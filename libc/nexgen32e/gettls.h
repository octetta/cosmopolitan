#ifndef COSMOPOLITAN_LIBC_NEXGEN32E_GETTLS_H_
#define COSMOPOLITAN_LIBC_NEXGEN32E_GETTLS_H_
#include "libc/dce.h"
#include "libc/nexgen32e/threaded.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

char *__get_tls(void) libcesque nosideeffect;

#if defined(__GNUC__) && defined(__x86_64__) && !defined(__STRICT_ANSI__)
static noasan inline char *__get_tls_inline(void) {
  char *tib, *lin = (char *)0x30;
  if (IsLinux() || IsFreebsd() || IsNetbsd() || IsOpenbsd()) {
    asm("mov\t%%fs:(%1),%0" : "=a"(tib) : "r"(lin) : "memory");
  } else {
    asm("mov\t%%gs:(%1),%0" : "=a"(tib) : "r"(lin) : "memory");
    if (IsWindows()) {
      tib = *(char **)(tib + 0x1480 + __tls_index * 8);
    }
  }
  return tib;
}
#endif /* GNU x86-64 */

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_NEXGEN32E_GETTLS_H_ */
