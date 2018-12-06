;Assembly Vector Library
.686
.XMM
.MODEL FLAT, stdcall
.STACK 4096

_normalize PROTO C
_magnitude PROTO C
_scalar PROTO C
_vectorAdd PROTO C
_dotProduct PROTO C

.DATA


.CODE
_normalize PROC C
push ebp
mov ebp, esp

mulpd xmm0, xmm0
haddpd xmm0, xmm0
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
haddpd xmm0, xmm0
sqrtpd xmm0, xmm0

pop ebp
ret
_magnitude ENDP

_scalar PROC C
push ebp
mov ebp, esp

mulpd xmm0, xmm1

pop ebp
ret
_scalar ENDP

_vectorAdd PROC C
push ebp
mov ebp, esp

shufpd xmm1, xmm1, 0h
haddpd xmm0 ,xmm1

pop ebp
ret
_vectorAdd ENDP

_dotProduct PROC C
push ebp
mov ebp, esp

haddpd xmm0, xmm1
haddpd xmm0, xmm0

pop ebp
ret
_dotProduct ENDP
END