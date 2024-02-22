/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│ vi: set et ft=c ts=2 sts=2 sw=2 fenc=utf-8                               :vi │
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2024 Justine Alexandra Roberts Tunney                              │
│                                                                              │
│ Permission to use, copy, modify, and/or distribute this software for         │
│ any purpose with or without fee is hereby granted, provided that the         │
│ above copyright notice and this permission notice appear in all copies.      │
│                                                                              │
│ THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL                │
│ WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED                │
│ WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE             │
│ AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL         │
│ DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR        │
│ PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER               │
│ TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR             │
│ PERFORMANCE OF THIS SOFTWARE.                                                │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/calls/calls.h"
#include "libc/calls/struct/cpuset.h"
#include "libc/calls/syscall_support-nt.internal.h"
#include "libc/dce.h"
#include "libc/errno.h"
#include "libc/nexgen32e/rdtscp.h"
#include "libc/nexgen32e/x86feature.h"
#include "libc/nt/struct/processornumber.h"
#include "libc/nt/synchronization.h"
#include "libc/runtime/syslib.internal.h"
#include "libc/sysv/errfuns.h"

int sys_getcpu(unsigned *opt_cpu, unsigned *opt_node, void *tcache);

int getcpu(unsigned *out_opt_cpu, unsigned *out_opt_node) {
  unsigned cpu;
  unsigned node;
  if (X86_HAVE(RDTSCP)) {
    unsigned tsc_aux;
    rdtscp(&tsc_aux);
    cpu = TSC_AUX_CORE(tsc_aux);
    node = TSC_AUX_NODE(tsc_aux);
  } else if (IsWindows()) {
    struct NtProcessorNumber pn;
    GetCurrentProcessorNumberEx(&pn);
    cpu = 64 * pn.Group + pn.Number;
    unsigned short node16;
    if (GetNumaProcessorNodeEx(&pn, &node16)) {
      node = node16;
    } else {
      return __winerr();
    }
  } else if (IsXnuSilicon()) {
    if (__syslib->__version >= 9) {
      size_t cpu64;
      errno_t err = __syslib->__pthread_cpu_number_np(&cpu64);
      if (!err) {
        cpu = cpu64;
        node = 0;
      } else {
        errno = err;
        return -1;
      }
    } else {
      return enosys();
    }
  } else {
    int rc = sys_getcpu(&cpu, &node, 0);
    if (rc == -1) return -1;
  }
  if (out_opt_cpu) {
    *out_opt_cpu = cpu;
  }
  if (out_opt_node) {
    *out_opt_node = node;
  }
  return 0;
}
