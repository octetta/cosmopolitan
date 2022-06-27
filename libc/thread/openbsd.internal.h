#ifndef COSMOPOLITAN_LIBC_THREAD_OPENBSD_INTERNAL_H_
#define COSMOPOLITAN_LIBC_THREAD_OPENBSD_INTERNAL_H_
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

struct __tfork {
  void *tf_tcb;
  int32_t *tf_tid;
  void *tf_stack;
};

int __tfork_thread(struct __tfork *, size_t, void (*)(void *), void *);

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_THREAD_OPENBSD_INTERNAL_H_ */
