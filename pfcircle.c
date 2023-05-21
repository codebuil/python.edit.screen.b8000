#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>


int screenptr;
int screen13();
void cls13(cls1);
void refresh();
void fillcircle(fillcirclex,fillcircley,fillcircler,fillcirclecolor);


void main(){
char aa;
	int c;
	int d;
	long l;
	long ll;
	char b=1;
int a;
int e;	
	int t=screen13();
screenptr=0xa000;

	cls13(1);
e=4;
for (a=0;a<95;a=a+10){
if (e==1){
 e=7;
}
else
{
e=1;
}
fillcircle(160,100,95-a,e);
}
aa=getccc();
t=screen3();
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


int screen13()
{
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x13;
	int86(0x10,&r,&r1);
	return r1.x.ax;
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

void refresh(){
	
	}


void fillcircle(fillcirclex,fillcircley,fillcircler,fillcirclecolor){

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
	xx=fillcirclex;
	yy=fillcircley;
	xx1=fillcircler;
	yy1=fillcirclecolor;

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

/* 0 -x +y +x*/
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
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0xc],ax";
	asm "call label101";


/* 1 -y +x +y */
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
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0xc],ax";
	asm "call label101";
	asm "jmp label200";
	asm "label201:";
	asm "jmp label71";
	asm "label200:";
/* 2 -x -y +x*/
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
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0x8]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0xc],ax";
	asm "call label101";

/* 3 -y -x +y*/
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
	asm "mov ax,[bp+0x2e]";
	asm "mov bx,[bp+0xa]";
	asm "clc";
	asm "add ax,bx";
	asm "mov [bp+0xc],ax";
	asm "call label101";



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
	asm "jmp label201";
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
	asm "jmp label130";

	asm "label101:";
	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x26]";
	asm "cmp ax,bx";
	asm "jg label122";
	asm "inc bx";
	asm "mov [bp+0x0],bx";
	asm "label122:";

	asm "mov ax,[bp+0x2]";
	asm "mov bx,[bp+0x26]";
	asm "cmp ax,bx";
	asm "jg label123";
	asm "inc bx";
	asm "mov [bp+0x2],bx";
	asm "label123:";

	asm "mov ax,[bp+0xc]";
	asm "mov bx,[bp+0x26]";
	asm "cmp ax,bx";
	asm "jg label124";
	asm "inc bx";
	asm "mov [bp+0xc],bx";
	asm "label124:";

	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0x1c]";
	asm "cmp ax,bx";
	asm "jl label125";
	asm "inc bx";
	asm "mov [bp+0x0],bx";
	asm "label125:";

	asm "mov ax,[bp+0x2]";
	asm "mov bx,[bp+0x1c]";
	asm "cmp ax,bx";
	asm "jl label126";
	asm "inc bx";
	asm "mov [bp+0x2],bx";
	asm "label126:";



	asm "mov ax,[bp+0x2]";
	asm "mov bx,[bp+0x20]";
	asm "cmp ax,bx";
	asm "jl label128";
	asm "inc bx";
	asm "mov [bp+0x2],bx";
	asm "label128:";

	asm "mov ax,[bp+0x0c]";
	asm "mov bx,[bp+0x1c]";
	asm "cmp ax,bx";
	asm "jl label127";
	asm "inc bx";
	asm "mov [bp+0xc],bx";
	asm "jmp label127";
	asm "label130:";
	asm "jmp label81";
	asm "label127:";

	asm "mov ax,[bp+0x0]";
	asm "mov bx,[bp+0xc]";
	asm "clc";
	asm "sub bx,ax";
	asm "inc bx";
	asm "mov [bp+0x10],bx";

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
	asm "mov di,bx";
	asm "mov cx,[bp+0x10]";
	asm "label82:";
	asm "cld";
	asm "rep";
	asm "stosb";
	asm "ret";

	asm "label81:";
	asm "mov sp,si"; /*restore sp */

	asm "pop ds"; /* restore var from return */
	asm "pop es";
	asm "pop bp";			



	}







