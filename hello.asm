org 101000h
[bits 32]
head:
mov eax,0x21cd4cff
push es
mov ax,0
mov es,ax

mov ebx,0b8000h
mov al,17h
mov ecx,4000
forss:
es
mov [ebx],al
inc ebx
dec ecx
cmp ecx,0
jnz forss
mov ax,0
int 21h
ret
ret
checkin:
hello db 27,"c",27,"[44;37m",13,10,"hello world.....",13,10,13,10,"$$$$",0

