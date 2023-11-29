#-*-mode:makefile-gmake;indent-tabs-mode:t;tab-width:8;coding:utf-8-*-┐
#───vi: set et ft=make ts=8 tw=8 fenc=utf-8 :vi───────────────────────┘

PKGS += LIBC

LIBC_ISYSTEM = \
libc/isystem/algorithm \
libc/isystem/alloca.h \
libc/isystem/ammintrin.h \
libc/isystem/any \
libc/isystem/ar.h \
libc/isystem/arm_acle.h \
libc/isystem/arm_bf16.h \
libc/isystem/arm_fp16.h \
libc/isystem/arm_neon.h \
libc/isystem/arpa/inet.h \
libc/isystem/array \
libc/isystem/assert.h \
libc/isystem/atomic \
libc/isystem/bit \
libc/isystem/bitset \
libc/isystem/byteswap.h \
libc/isystem/cassert \
libc/isystem/ccomplex \
libc/isystem/cctype \
libc/isystem/cerrno \
libc/isystem/cfenv \
libc/isystem/cfloat \
libc/isystem/charconv \
libc/isystem/chrono \
libc/isystem/cinttypes \
libc/isystem/ciso646 \
libc/isystem/climits \
libc/isystem/clocale \
libc/isystem/clzerointrin.h \
libc/isystem/cmath \
libc/isystem/codecvt \
libc/isystem/compare \
libc/isystem/complex \
libc/isystem/complex.h \
libc/isystem/condition_variable \
libc/isystem/cosmo.h \
libc/isystem/cpio.h \
libc/isystem/cpuid.h \
libc/isystem/crypt.h \
libc/isystem/csetjmp \
libc/isystem/csignal \
libc/isystem/cstdarg \
libc/isystem/cstdbool \
libc/isystem/cstddef \
libc/isystem/cstdint \
libc/isystem/cstdio \
libc/isystem/cstdlib \
libc/isystem/cstring \
libc/isystem/ctgmath \
libc/isystem/ctime \
libc/isystem/ctype.h \
libc/isystem/cwchar \
libc/isystem/cwctype \
libc/isystem/cxxabi.h \
libc/isystem/deque \
libc/isystem/dirent.h \
libc/isystem/dlfcn.h \
libc/isystem/elf.h \
libc/isystem/emmintrin.h \
libc/isystem/endian.h \
libc/isystem/err.h \
libc/isystem/errno.h \
libc/isystem/exception \
libc/isystem/execution \
libc/isystem/fcntl.h \
libc/isystem/features.h \
libc/isystem/fenv.h \
libc/isystem/filesystem \
libc/isystem/float.h \
libc/isystem/fnmatch.h \
libc/isystem/forward_list \
libc/isystem/fstream \
libc/isystem/ftw.h \
libc/isystem/functional \
libc/isystem/future \
libc/isystem/getopt.h \
libc/isystem/glob.h \
libc/isystem/grp.h \
libc/isystem/iconv.h \
libc/isystem/ifaddrs.h \
libc/isystem/immintrin.h \
libc/isystem/initializer_list \
libc/isystem/inttypes.h \
libc/isystem/iomanip \
libc/isystem/ios \
libc/isystem/iosfwd \
libc/isystem/iostream \
libc/isystem/iso646.h \
libc/isystem/istream \
libc/isystem/iterator \
libc/isystem/langinfo.h \
libc/isystem/libgen.h \
libc/isystem/limits \
libc/isystem/limits.h \
libc/isystem/linux/futex.h \
libc/isystem/linux/limits.h \
libc/isystem/linux/param.h \
libc/isystem/linux/types.h \
libc/isystem/list \
libc/isystem/locale \
libc/isystem/locale.h \
libc/isystem/malloc.h \
libc/isystem/map \
libc/isystem/math.h \
libc/isystem/memory \
libc/isystem/memory.h \
libc/isystem/mm3dnow.h \
libc/isystem/mm_malloc.h \
libc/isystem/mmintrin.h \
libc/isystem/mntent.h \
libc/isystem/monetary.h \
libc/isystem/mutex \
libc/isystem/mwaitxintrin.h \
libc/isystem/net/ethernet.h \
libc/isystem/net/if.h \
libc/isystem/net/if_arp.h \
libc/isystem/netdb.h \
libc/isystem/netinet/in.h \
libc/isystem/netinet/ip.h \
libc/isystem/netinet/tcp.h \
libc/isystem/netinet/udp.h \
libc/isystem/new \
libc/isystem/nl_types.h \
libc/isystem/nmmintrin.h \
libc/isystem/nsync.h \
libc/isystem/nsync_atomic.h \
libc/isystem/nsync_counter.h \
libc/isystem/nsync_cv.h \
libc/isystem/nsync_debug.h \
libc/isystem/nsync_mu.h \
libc/isystem/nsync_mu_wait.h \
libc/isystem/nsync_note.h \
libc/isystem/nsync_once.h \
libc/isystem/nsync_time.h \
libc/isystem/nsync_waiter.h \
libc/isystem/numeric \
libc/isystem/optional \
libc/isystem/ostream \
libc/isystem/paths.h \
libc/isystem/pmmintrin.h \
libc/isystem/poll.h \
libc/isystem/popcntintrin.h \
libc/isystem/pthread.h \
libc/isystem/pty.h \
libc/isystem/pwd.h \
libc/isystem/queue \
libc/isystem/random \
libc/isystem/ratio \
libc/isystem/regex \
libc/isystem/regex.h \
libc/isystem/sched.h \
libc/isystem/scoped_allocator \
libc/isystem/search.h \
libc/isystem/semaphore.h \
libc/isystem/set \
libc/isystem/setjmp.h \
libc/isystem/sgxintrin.h \
libc/isystem/shared_mutex \
libc/isystem/signal.h \
libc/isystem/smmintrin.h \
libc/isystem/span \
libc/isystem/spawn.h \
libc/isystem/sstream \
libc/isystem/stack \
libc/isystem/stdalign.h \
libc/isystem/stdarg.h \
libc/isystem/stdatomic.h \
libc/isystem/stdbool.h \
libc/isystem/stdc-predef.h \
libc/isystem/stdckdint.h \
libc/isystem/stddef.h \
libc/isystem/stdexcept \
libc/isystem/stdint.h \
libc/isystem/stdio.h \
libc/isystem/stdio_ext.h \
libc/isystem/stdlib.h \
libc/isystem/stdnoreturn.h \
libc/isystem/streambuf \
libc/isystem/string \
libc/isystem/string.h \
libc/isystem/string_view \
libc/isystem/strings.h \
libc/isystem/strstream \
libc/isystem/sys/auxv.h \
libc/isystem/sys/cdefs.h \
libc/isystem/sys/dir.h \
libc/isystem/sys/errno.h \
libc/isystem/sys/event.h \
libc/isystem/sys/fcntl.h \
libc/isystem/sys/file.h \
libc/isystem/sys/ioctl.h \
libc/isystem/sys/ipc.h \
libc/isystem/sys/mman.h \
libc/isystem/sys/mount.h \
libc/isystem/sys/msg.h \
libc/isystem/sys/param.h \
libc/isystem/sys/poll.h \
libc/isystem/sys/prctl.h \
libc/isystem/sys/procfs.h \
libc/isystem/sys/ptrace.h \
libc/isystem/sys/random.h \
libc/isystem/sys/reboot.h \
libc/isystem/sys/resource.h \
libc/isystem/sys/select.h \
libc/isystem/sys/sendfile.h \
libc/isystem/sys/signal.h \
libc/isystem/sys/socket.h \
libc/isystem/sys/stat.h \
libc/isystem/sys/statfs.h \
libc/isystem/sys/statvfs.h \
libc/isystem/sys/syscall.h \
libc/isystem/sys/sysinfo.h \
libc/isystem/sys/sysmacros.h \
libc/isystem/sys/termios.h \
libc/isystem/sys/time.h \
libc/isystem/sys/times.h \
libc/isystem/sys/ttydefaults.h \
libc/isystem/sys/types.h \
libc/isystem/sys/ucontext.h \
libc/isystem/sys/uio.h \
libc/isystem/sys/un.h \
libc/isystem/sys/user.h \
libc/isystem/sys/utsname.h \
libc/isystem/sys/vfs.h \
libc/isystem/sys/wait.h \
libc/isystem/sysexits.h \
libc/isystem/syslog.h \
libc/isystem/system_error \
libc/isystem/termios.h \
libc/isystem/tgmath.h \
libc/isystem/thread \
libc/isystem/time.h \
libc/isystem/tmmintrin.h \
libc/isystem/tuple \
libc/isystem/type_traits \
libc/isystem/typeindex \
libc/isystem/typeinfo \
libc/isystem/uchar.h \
libc/isystem/ucontext.h \
libc/isystem/uio.h \
libc/isystem/unistd.h \
libc/isystem/unordered_map \
libc/isystem/unordered_set \
libc/isystem/utility \
libc/isystem/utime.h \
libc/isystem/utmp.h \
libc/isystem/utmpx.h \
libc/isystem/valarray \
libc/isystem/variant \
libc/isystem/vector \
libc/isystem/version \
libc/isystem/wait.h \
libc/isystem/wchar.h \
libc/isystem/wctype.h \
libc/isystem/winternl.h \
libc/isystem/wmmintrin.h \
libc/isystem/x86intrin.h \
libc/isystem/xmmintrin.h

LIBC_HDRS = $(filter %.h,$(LIBC_FILES)) $(LIBC_ISYSTEM)
LIBC_HDRS_H = $(filter %.h,$(LIBC_HDRS))
LIBC_INCS = $(filter %.inc,$(LIBC_FILES))
LIBC_CHECKS = $(LIBC_HDRS_H:%=o/$(MODE)/%.ok)

ifneq ($(MODE), llvm)
LIBC_FILES := $(wildcard libc/*)
else
LIBC_FILES := $(wildcard libc/*)
endif

.PHONY:		o/$(MODE)/libc
o/$(MODE)/libc:	o/$(MODE)/libc/calls		\
		o/$(MODE)/libc/crt		\
		o/$(MODE)/libc/dlopen		\
		o/$(MODE)/libc/dns		\
		o/$(MODE)/libc/elf		\
		o/$(MODE)/libc/fmt		\
		o/$(MODE)/libc/intrin		\
		o/$(MODE)/libc/irq		\
		o/$(MODE)/libc/log		\
		o/$(MODE)/libc/mem		\
		o/$(MODE)/libc/nexgen32e	\
		o/$(MODE)/libc/nt		\
		o/$(MODE)/libc/proc		\
		o/$(MODE)/libc/runtime		\
		o/$(MODE)/libc/sock		\
		o/$(MODE)/libc/stdio		\
		o/$(MODE)/libc/str		\
		o/$(MODE)/libc/sysv		\
		o/$(MODE)/libc/testlib		\
		o/$(MODE)/libc/thread		\
		o/$(MODE)/libc/time		\
		o/$(MODE)/libc/tinymath		\
		o/$(MODE)/libc/vga		\
		o/$(MODE)/libc/x		\
		$(LIBC_CHECKS)