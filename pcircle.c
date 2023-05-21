#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>


int screenptr;
int screen13();
void cls13(cls1);
int getptr();
void refresh();
void circle(circlex,circley,circler,circlecolor);

void main(){
	char aa;
	int c;
	int d;
	long l;
	long ll;
	char b=1;
int a;	
	int t=screen13();
screenptr=getptr();

	cls13(1);

for (a=5;a<100;a=a+10){ 
circle(160,100,a,7);
} 

aa=getccc();
t=screen3();

}


int screen13()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x13;
	int86(0x10,&r,&r1);
	return r1.x.ax;
	}
int screen3()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x3;
	int86(0x10,&r,&r1);
	return r1.x.ax;
	}
int getccc()
{
	
		return (int)getchar();
	
	return 0;
	}
int inp(i){			
asm "label1000:";
asm "mov dx,0x60";
asm "in al,dx";
asm "and al,128";
asm "cmp al,0";
asm "jnz label1000";
		
}

void cls13(cls1)
{
	int i;
	i=screenptr;
	movedata(__get_ds(),&i,__get_cs(),0xf080,2);
	i=320*200+1;
	movedata(__get_ds(),&i,__get_cs(),0xf082,2);
	movedata(__get_ds(),&cls1,__get_cs(),0xf084,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov cx,[0xf082]";
	asm "mov dx,[0xf084]";
	asm "mov ax,[0xf080]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";
	asm "mov di,dx";	
asm "label1:";
asm "cld";
asm "rep";
asm "stosb";
	
	asm "pop ds";
	
	}





	int getptr(){
		
		return 0xa000;
		
		}

void refresh()
{
	}


void circle(circlex,circley,circler,circlecolor){

	int ir;
	int ny;
	int nx;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
int n1;
int n2;
int n3;
int n4;
	
	int xxa;
	xx=circlex;
	yy=circley;
	xx1=circler;
	yy1=circlecolor;

	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0xf080,2);
	ir=xx;
	movedata(__get_ds(),&ir,__get_cs(),0xf082,2);
	ir=yy;
	movedata(__get_ds(),&ir,__get_cs(),0xf084,2);
	ir=xx1;
	movedata(__get_ds(),&ir,__get_cs(),0xf086,2);
	ir=yy1;
	movedata(__get_ds(),&ir,__get_cs(),0xf088,2);
	ir=-1;
	movedata(__get_ds(),&ir,__get_cs(),0xf08a,2);
	ir=0;
	movedata(__get_ds(),&ir,__get_cs(),0xf08c,2);
	ir=199;
	movedata(__get_ds(),&ir,__get_cs(),0xf08e,2);
	ir=200;
	movedata(__get_ds(),&ir,__get_cs(),0xf090,2);
	ir=319;
	movedata(__get_ds(),&ir,__get_cs(),0xf092,2);
	ir=320;
	movedata(__get_ds(),&ir,__get_cs(),0xf094,2);
	ir=24;
	movedata(__get_ds(),&ir,__get_cs(),0xf096,2);
	ir=50;
	movedata(__get_ds(),&ir,__get_cs(),0xf098,2);



	asm "push bp";
	asm "push es";
	asm "push ds";
	asm "push cs";
	asm "pop ds";
/* get stask point */
	asm "mov si,sp";
	asm "mov bp,sp";

/* load data to stack */
	asm "mov ax,[0xf080]";
	asm "push ax";
	asm "mov ax,[0xf082]";
	asm "push ax";
	asm "mov ax,[0xf084]";
	asm "push ax";
	asm "mov ax,[0xf086]";
	asm "push ax";
	asm "mov ax,[0xf088]";
	asm "push ax";
	asm "mov ax,[0xf08a]";
	asm "push ax";
	asm "mov ax,[0xf08c]";
	asm "push ax";
	asm "mov ax,[0xf08e]";
	asm "push ax";
	asm "mov ax,[0xf090]";
	asm "push ax";
	asm "mov ax,[0xf092]";
	asm "push ax";
	asm "mov ax,[0xf094]";
	asm "push ax";
	asm "mov ax,[0xf096]";
	asm "push ax";
	asm "mov ax,[0xf098]";
	asm "push ax";
	asm "clc";
	asm "sub bp,ax";
	asm "mov sp,bp";

	asm "mov ax,[bp+0x30]";
	asm "mov ds,ax";
	asm "mov es,ax";

	asm "mov bx,[bp+0x24]";
	asm "mov [bp+0x8],bx";
	asm "mov ax,[bp+0x2a]";
	asm "mov [bp+0xa],ax";
	asm "inc bx";
	asm "clc";
	asm "sub bx,ax";
	asm "mov [bp+0x6],bx";
	asm "label71:";

/* 0 +x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*1 +y +x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";
	asm "jmp label79";
	asm "label90:";
	asm "jmp label71";
	asm "label79:";

/*2 +x -y */


	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*3 +y -x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*4 +x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";
	asm "jmp label92";
	asm "label94:";
	asm "jmp label90";
	asm "label92:";

/*5 -x +y */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*6 -y +x */
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";

/*7 -y -x */

	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x0],ax";
	asm "mov ax,[bp+0x2c]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0x2],ax";
	asm "call label80";


	asm "mov bx,[bp+0x8]";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x8],bx";

	asm "mov bx,[bp+0x6]";
	asm "mov dx,[bp+0x24]";
	asm "cmp bx,dx";
	asm "jl label75";
	asm "jmp label72";
	asm "label76:";
	asm "jmp label94";
	asm "label75:";
	asm "mov bx,[bp+0x8]";
	asm "mov ax,bx";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,[bp+0x6]";
	asm "clc";
	asm "add bx,ax";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x6],bx";

	asm "jmp label73";
	asm "label72:";
	asm "mov bx,[bp+0x24]";
	asm "inc bx";
	asm "mov ax,[bp+0xa]";
	asm "clc";
	asm "sub ax,bx";
	asm "mov [bp+0xa],ax";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "sub bx,ax";
	asm "mov ax,bx";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,[bp+0x6]";
	asm "clc";
	asm "add bx,ax";
	asm "mov ax,[bp+0x24]";
	asm "inc ax";
	asm "clc";
	asm "add bx,ax";
	asm "mov [bp+0x6],bx";

	asm "label73:";
	asm "mov bx,[bp+0x24]";
	asm "inc bx";
	asm "mov ax,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov bx,ax";
	asm "mov ax,[bp+0x8]";
	asm "cmp ax,bx";
	asm "jl label76";
	asm "jmp label81";

	asm "label80:";
	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x24]";
	asm "cmp ax,bx";
	asm "jl label82";
	asm "mov ax,[bp+0x2]";
	asm "cmp ax,bx";
	asm "jl label82";
	asm "mov bx,[bp+0x22]";
	asm "cmp ax,bx";
	asm "ja label82";
	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x1e]";
	asm "ja label82";
	asm "mov ax,[bp+0x2]";
	asm "mov bx,[bp+0x1c]";
	asm "xor dx,dx";
	asm "xor cx,cx";
	asm "clc";
	asm "mul bx";
	asm "mov bx,[bp+0x0]";
	asm "clc";
	asm "add bx,ax";
	asm "mov al,[bp+0x28]";
	asm "mov [bx],al";
	asm "label82:";
	asm "ret";

	asm "label81:";
	asm "mov sp,si"; /*restore sp */

	asm "pop ds"; /* restore var from return */
	asm "pop es";
	asm "pop bp";			



	}







