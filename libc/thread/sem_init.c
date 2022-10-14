/*-*- mode:c;indent-tabs-mode:nil;c-basic-offset:2;tab-width:8;coding:utf-8 -*-│
│vi: set net ft=c ts=2 sts=2 sw=2 fenc=utf-8                                :vi│
╞══════════════════════════════════════════════════════════════════════════════╡
│ Copyright 2022 Justine Alexandra Roberts Tunney                              │
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
#include "libc/intrin/atomic.h"
#include "libc/limits.h"
#include "libc/sysv/errfuns.h"
#include "libc/thread/semaphore.h"
#include "third_party/nsync/mu_semaphore.h"

/**
 * Initializes unnamed semaphore.
 *
 * @param sem should make its way to sem_destroy() if this succeeds
 * @param pshared if semaphore may be shared between processes
 * @param value is initial count of semaphore
 * @return 0 on success, or -1 w/ errno
 * @raise EINVAL if `value` exceeds `SEM_VALUE_MAX`
 */
int sem_init(sem_t *sem, int pshared, unsigned value) {
  if (value > SEM_VALUE_MAX) return einval();
  atomic_store_explicit(&sem->sem_value, value, memory_order_relaxed);
  sem->sem_pshared = pshared;
  return 0;
}