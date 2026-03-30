/* Definitions for LoongArch running NetBSD systems using ELF */

#undef DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS ""

#define TARGET_OS_CPP_BUILTINS()			\
  do {							\
    NETBSD_OS_CPP_BUILTINS_ELF();			\
    builtin_define ("__loongarch__");			\
    if (c_dialect_cxx ())				\
      builtin_define ("_GNU_SOURCE");			\
  } while (0)

#undef CPP_SPEC
#define CPP_SPEC NETBSD_CPP_SPEC

#undef LIB_SPEC
#define LIB_SPEC NETBSD_LIB_SPEC

#define EXTRA_SPECS NETBSD_SUBTARGET_EXTRA_SPECS

#undef STARTFILE_PREFIX_SPEC

#undef LINK_SPEC
#define LINK_SPEC \
  "-melf64loongarch %(netbsd_link_spec)"

#undef NETBSD_ENTRY_POINT
#define NETBSD_ENTRY_POINT "_start"

#undef UINTPTR_TYPE
#define UINTPTR_TYPE "long unsigned int"

#undef INTPTR_TYPE
#define INTPTR_TYPE "long int"
