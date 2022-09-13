/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2021 Justine Alexandra Roberts Tunney                              │
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
#include "libc/intrin/strace.internal.h"
#include "libc/intrin/weaken.h"
#include "libc/runtime/internal.h"
#include "libc/runtime/runtime.h"

/**
 * Exits process with grace.
 *
 * This calls functions registered by atexit() before terminating
 * the current process, and any associated threads. It also calls
 * all the legacy linker registered destructors in reeverse order
 *
 * @param exitcode is masked with 255
 * @see _Exit()
 * @noreturn
 */
wontreturn void exit(int exitcode) {
  const uintptr_t *p;
  STRACE("exit(%d)", exitcode);
  if (_weaken(__cxa_finalize)) {
    _weaken(__cxa_finalize)(NULL);
  }
  for (p = __fini_array_end; p > __fini_array_start;) {
    ((void (*)(void))(*--p))();
  }
  _Exitr(exitcode);
}
