;Assembly Vector Library
.686
.XMM
.MODEL FLAT, C
.STACK 4096

ExitProcess PROTO stdcall, dwExitCode:DWORD

_normalize PROC
push ebp
mov ebp, esp
push ebx

movaps xmm0, [ebp + 20h]
movaps xmm1, [ebp + 20h]
mulps xmm0, xmm0
haddps xmm0, xmm0
haddps xmm0, xmm0
sqrtps xmm0, xmm0
divps xmm1, xmm0
movaps eax, xmm0

pop ebx
pop ebp
ret
_normalize ENDP