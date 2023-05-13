(defconst cosmo-cpp-constants-c11
 '("__STDC_IEC_559__"
   "__FILE__"
   "__LINE__"
   "__DATE__"))

(defconst cosmo-cpp-constants-chibicc
  '("__cosmo__"
    "__chibicc__"))

(defconst cosmo-cpp-constants-gcc-412
  '("__BASE_FILE__"
    "__CHAR_BIT__"
    "__FUNCTION__"
    "__GNUC_MINOR__"
    "__GNUC_PATCHLEVEL__"
    "__GNUC__"
    "__APPLE__"
    "__HAIKU__"
    "__CYGWIN__"
    "__EMSCRIPTEN__"
    "__ANDROID__"
    "__FreeBSD__"
    "__NetBSD__"
    "__NetBSD_Version__"
    "__OpenBSD__"
    "__COSMOPOLITAN__"
    "__GLIBC__"
    "__linux"
    "__MACH__"
    "__GNUG__"
    "__INCLUDE_LEVEL__"
    "__INTMAX_MAX__"
    "__INT_MAX__"
    "__LONG_LONG_MAX__"
    "__LONG_MAX__"
    "__SCHAR_MAX__"
    "__SHRT_MAX__"
    "__DBL_MIN__"
    "__DBL_MAX__"
    "__LDBL_MIN__"
    "__LDBL_MAX__"
    "__FLT_MIN__"
    "__FLT_MAX__"
    "__WCHAR_MAX__"
    "__WCHAR_UNSIGNED__"
    "__AES__"
    "__AVX__"
    "__AVX2__"
    "__AVX512F__"
    "__AVXVNNI__"
    "__ABM__"
    "__BMI__"
    "__BMI2__"
    "__FMA__"
    "__FMA4__"
    "__F16C__"
    "__CLZERO__"
    "__MWAITX__"
    "__SGX__"
    "__VAES__"
    "__VSX__"
    "__ADX__"
    "__PCLMUL__"
    "__POPCNT__"
    "__RDRND__"
    "__RDSEED__"
    "__SHA__"
    "__SSE__"
    "__SSE2__"
    "__SSE3__"
    "__SSSE3__"
    "__SSE4_1__"
    "__SSE4_2__"
    "__XSAVE__"
    "__CLFLUSHOPT__"
    "__RDPID__"
    "FLT_ROUNDS"))

(defconst cosmo-cpp-constants-gcc-92
  '("__x86_64__"
    "__arm__"
    "__aarch64__"
    "__AARCH64EB__"
    "__ARM_NEON"
    "__powerpc__"
    "__powerpc64__"
    "__POWER9_VECTOR__"
    "__wasm_simd128__"
    "_ARCH_PWR5X"
    "__mips__"
    "__s390__"
    "__s390x__"
    "__mips64"
    "__m68k__"
    "__riscv"
    "__riscv_flen"
    "__riscv_xlen"
    "__MICROBLAZE__"
    "__amd64__"
    "__WINT_MAX__"
    "__BIGGEST_ALIGNMENT__"
    "__SIZE_MAX__"
    "__PTRDIFF_MAX__"
    "__UINTMAX_MAX__"
    "__SIG_ATOMIC_MAX__"
    "__INT8_MAX__"
    "__INT16_MAX__"
    "__INT32_MAX__"
    "__INT64_MAX__"
    "__UINT8_MAX__"
    "__UINT16_MAX__"
    "__UINT32_MAX__"
    "__UINT64_MAX__"
    "__INT_LEAST8_MAX__"
    "__INT_LEAST16_MAX__"
    "__INT_LEAST32_MAX__"
    "__INT_LEAST64_MAX__"
    "__UINT_LEAST8_MAX__"
    "__UINT_LEAST16_MAX__"
    "__UINT_LEAST32_MAX__"
    "__UINT_LEAST64_MAX__"
    "__INT_FAST8_MAX__"
    "__INT_FAST16_MAX__"
    "__INT_FAST32_MAX__"
    "__INT_FAST64_MAX__"
    "__UINT_FAST8_MAX__"
    "__UINT_FAST16_MAX__"
    "__UINT_FAST32_MAX__"
    "__UINT_FAST64_MAX__"
    "__INTPTR_MAX__"
    "__UINTPTR_MAX__"
    "__WCHAR_MIN__"
    "__WINT_MIN__"
    "__SIG_ATOMIC_MIN__"
    "__SCHAR_WIDTH__"
    "__SHRT_WIDTH__"
    "__INT_WIDTH__"
    "__LONG_WIDTH__"
    "__LONG_LONG_WIDTH__"
    "__PTRDIFF_WIDTH__"
    "__SIG_ATOMIC_WIDTH__"
    "__SIZE_WIDTH__"
    "__WCHAR_WIDTH__"
    "__WINT_WIDTH__"
    "__INT_LEAST8_WIDTH__"
    "__INT_LEAST16_WIDTH__"
    "__INT_LEAST32_WIDTH__"
    "__INT_LEAST64_WIDTH__"
    "__INT_FAST8_WIDTH__"
    "__INT_FAST16_WIDTH__"
    "__INT_FAST32_WIDTH__"
    "__INT_FAST64_WIDTH__"
    "__INTPTR_WIDTH__"
    "__INTMAX_WIDTH__"
    "__SIZEOF_INT__"
    "__SIZEOF_INTMAX__"
    "__SIZEOF_UINTMAX__"
    "__SIZEOF_LONG__"
    "__SIZEOF_LONG_LONG__"
    "__SIZEOF_SHORT__"
    "__SIZEOF_POINTER__"
    "__SIZEOF_FLOAT__"
    "__SIZEOF_DOUBLE__"
    "__SIZEOF_LONG_DOUBLE__"
    "__SIZEOF_SIZE_T__"
    "__SIZEOF_WCHAR_T__"
    "__SIZEOF_WINT_T__"
    "__SIZEOF_PTRDIFF_T__"
    "__TIMESTAMP__"
    "_GNU_SOURCE"
    "_BSD_SOURCE"
    "_XOPEN_SOURCE"))

(defconst cosmo-cpp-constants-cosmopolitan
 '("__SAUCE__"
   "PAGESIZE"
   "GUARDSIZE"
   "FRAMESIZE"
   "BIGPAGESIZE"
   "STACKSIZE"
   "ARG_MAX"
   "PATH_MAX"
   "BUFSIZ"
   "CACHELINE"
   "CHAR_BIT"
   "NAME_MAX"
   "NSIG"
   "CHILD_MAX"
   "OPEN_MAX"
   "ATEXIT_MAX"
   "LONG_BIT"
   "IM_FEELING_NAUGHTY"
   "__REAL_MODE__"
   "__ia16__"
   "__x86__"
   "__i386__"
   "__i486__"
   "__i586__"
   "__i686__"
   "__W__"
   "__PG__"
   "__MFENTRY__"
   "__MNO_VZEROUPPER__"
   "__MNO_RED_ZONE__"
   "__MNOP_MCOUNT__"
   "__MRECORD_MCOUNT__"
   "__FNO_OMIT_FRAME_POINTER__"))

(defconst cosmo-cpp-constants-clang
  '("__llvm__"
    "__clang__"
    "_MSC_VER"
    "_WIN32"
    "__MINGW32__"
    "__INTEL_COMPILER"))

(defconst cosmo-cpp-constants
  (append cosmo-cpp-constants-c11
          cosmo-cpp-constants-clang
          cosmo-cpp-constants-gcc-92
          cosmo-cpp-constants-gcc-412
          cosmo-cpp-constants-chibicc
          cosmo-cpp-constants-cosmopolitan))

(defconst cosmo-cpp-constants-regex
  (concat "\\_<" (regexp-opt cosmo-cpp-constants) "\\_>"))

(provide 'cosmo-cpp-constants)
