.include "o/libc/nt/codegen.inc"
.imp	ws2_32,__imp_WSAAsyncGetProtoByNumber,WSAAsyncGetProtoByNumber,104

	.text.windows
WSAAsyncGetProtoByNumber:
	push	%rbp
	mov	%rsp,%rbp
	.profilable
	mov	__imp_WSAAsyncGetProtoByNumber(%rip),%rax
	jmp	__sysv2nt6
	.endfn	WSAAsyncGetProtoByNumber,globl
	.previous
