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
#include "libc/dce.h"
#include "libc/mem/gc.h"
#include "libc/mem/mem.h"
#include "libc/runtime/runtime.h"
#include "libc/stdio/temp.h"
#include "libc/sysv/consts/clock.h"
#include "libc/sysv/consts/o.h"
#include "libc/testlib/testlib.h"
#include "libc/thread/semaphore.h"
#include "libc/thread/thread.h"

pthread_barrier_t barrier;
char testlib_enable_tmp_setup_teardown;

void *Worker(void *arg) {
  sem_t *s[2];
  struct timespec ts;
  ASSERT_NE(SEM_FAILED, (s[0] = sem_open("fooz", O_CREAT, 0644)));
  ASSERT_NE(SEM_FAILED, (s[1] = sem_open("barz", O_CREAT, 0644)));
  if (pthread_barrier_wait(&barrier) == PTHREAD_BARRIER_SERIAL_THREAD) {
    if (!IsWindows()) {  // :'(
      ASSERT_SYS(0, 0, sem_unlink("fooz"));
      ASSERT_SYS(0, 0, sem_unlink("barz"));
    }
  }
  ASSERT_SYS(0, 0, clock_gettime(CLOCK_REALTIME, &ts));
  ts.tv_sec += 1;
  ASSERT_SYS(0, 0, sem_post(s[0]));
  ASSERT_SYS(0, 0, sem_timedwait(s[1], &ts));
  ASSERT_SYS(0, 0, sem_close(s[1]));
  ASSERT_SYS(0, 0, sem_close(s[0]));
  return 0;
}

TEST(sem_open, test) {
  if (IsWindows()) return;  // TODO(jart): fix me
  sem_t *s[2];
  int i, r, n = 4;
  pthread_t *t = _gc(malloc(sizeof(pthread_t) * n));
  ASSERT_EQ(0, pthread_barrier_init(&barrier, 0, n));
  ASSERT_NE(SEM_FAILED, (s[0] = sem_open("fooz", O_CREAT, 0644)));
  ASSERT_NE(SEM_FAILED, (s[1] = sem_open("barz", O_CREAT, 0644)));
  for (i = 0; i < n; ++i) ASSERT_EQ(0, pthread_create(t + i, 0, Worker, 0));
  for (i = 0; i < n; ++i) ASSERT_SYS(0, 0, sem_wait(s[0]));
  ASSERT_SYS(0, 0, sem_getvalue(s[0], &r));
  ASSERT_EQ(0, r);
  for (i = 0; i < n; ++i) ASSERT_SYS(0, 0, sem_post(s[1]));
  for (i = 0; i < n; ++i) ASSERT_EQ(0, pthread_join(t[i], 0));
  ASSERT_SYS(0, 0, sem_getvalue(s[1], &r));
  ASSERT_EQ(0, r);
  ASSERT_SYS(0, 0, sem_close(s[1]));
  ASSERT_SYS(0, 0, sem_close(s[0]));
  ASSERT_EQ(0, pthread_barrier_destroy(&barrier));
}