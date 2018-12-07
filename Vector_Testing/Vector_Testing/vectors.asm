;Assembly Vector Library
.686
.XMM
.MODEL FLAT, stdcall
.STACK 4096

.DATA


.CODE

_normalize PROC C
push ebp
mov ebp, esp

movapd xmm1, xmm0
mulpd xmm0, xmm0
haddpd xmm0, xmm0
sqrtpd xmm0, xmm0
divpd xmm1, xmm0
movapd xmm0, xmm1

pop ebp
ret
_normalize ENDP

_magnitude PROC C
push ebp
mov ebp, esp

mulpd xmm0, xmm0
haddpd xmm0, xmm0
sqrtpd xmm0, xmm0

pop ebp
ret
_magnitude ENDP

_scalar PROC C
push ebp
mov ebp, esp

shufpd xmm1, xmm1, 0h
mulpd xmm0, xmm1

pop ebp
ret
_scalar ENDP

_vectorAdd PROC C
push ebp
mov ebp, esp

addpd xmm0 ,xmm1

pop ebp
ret
_vectorAdd ENDP

_dotProduct PROC C
push ebp
mov ebp, esp

mulpd xmm0, xmm1
haddpd xmm0, xmm0

pop ebp
ret
_dotProduct ENDP
END