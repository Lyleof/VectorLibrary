;Assembly Vector Library
.686
.XMM
.MODEL FLAT, C
.STACK 4096

ExitProcess PROTO stdcall, dwExitCode:DWORD

.CODE
_normalize PROC
push ebp
mov ebp, esp
push ebx

mulps xmm0, xmm0
haddps xmm0, xmm0
haddps xmm0, xmm0
sqrtps xmm0, xmm0
divps xmm1, xmm0
movaps xmm0, xmm1

pop ebx
pop ebp
ret
_normalize ENDP

_magnitude PROC
push ebp
mov ebp, esp
push ebx

mulps xmm0, xmm0
haddps xmm0, xmm0
haddps xmm0, xmm0
sqrtps xmm0, xmm0

pop ebx
pop ebp
ret
_magnitude ENDP

_scalar PROC
push ebp
mov ebp, esp
push ebx

mulps xmm0, xmm1

pop ebx
pop ebp
ret
_scalar ENDP

_vectorAdd PROC
push ebp
mov ebp, esp
push ebx

haddps xmm0 ,xmm1

pop ebx
pop ebp
ret
_vectorAdd ENDP

_dotProduct PROC
push ebp
mov ebp, esp
push ebx

haddps xmm0, xmm1
haddps xmm0, xmm0

pop ebx
pop ebp
ret
_dotProduct ENDP
END