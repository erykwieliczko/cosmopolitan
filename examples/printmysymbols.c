#if 0
/*─────────────────────────────────────────────────────────────────╗
│ To the extent possible under law, Justine Tunney has waived      │
│ all copyright and related or neighboring rights to this file,    │
│ as it is written in the following disclaimers:                   │
│   • http://unlicense.org/                                        │
│   • http://creativecommons.org/publicdomain/zero/1.0/            │
╚─────────────────────────────────────────────────────────────────*/
#endif
#include "libc/calls/calls.h"
#include "libc/elf/elf.h"
#include "libc/log/backtrace.h"
#include "libc/log/log.h"
#include "libc/runtime/symbols.h"
#include "libc/stdio/stdio.h"
#include "libc/sysv/consts/fileno.h"

int main(int argc, char *argv[]) {
  int rc = 0;
  char *filename;
  struct SymbolTable *tab = NULL;
  if ((filename = FindDebugBinary()) != NULL &&
      (tab = OpenSymbolTable(filename))) {
    for (unsigned i = 0; i < tab->count; ++i) {
      printf("%p %s\n", tab->addr_base + tab->symbols[i].addr_rva,
             GetElfString(tab->elf, tab->elfsize, tab->name_base,
                          tab->symbols[i].name_rva));
    }
  } else {
    perror("printmysymbols");
    ShowBacktrace(STDERR_FILENO, NULL);
    rc = 1;
  }
  CloseSymbolTable(&tab);
  return rc;
}
