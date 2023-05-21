#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>
#include <string.h>



int screenptr;


void refresh();
int screen13();
void cls13(cls1);
int getptr();
void pixelset(pixelsetx,pixelsety,pixelsetcolor);
void fillcircle(fillcirclex,fillcircley,fillcircler,fillcirclecolor);
void linedown(linedownx,linedowny,linedownx1,linedowny1,linedowncolor);
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);

void main(){
char aa;
	int c;
	int d;
	long l;
	long ll;
	char *b="";

int a;
int e;	
	int t=screen13();


screenptr=getptr();

	cls13(1);
e=4;
for (a=10;a<300;a=a+50){
fillcircle(a,100,2,7);
}

for (a=40;a<300;a=a+50){
fillcircle(a,180,2,7);
}

for (a=10;a<300;a=a+50){
linedown(0,0,a,100,7);
}

for (a=40;a<300;a=a+50){
linedown(0,0,a,180,7);
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



int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor)
{

	int ir;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=hlinex;
	yy=hliney;
	xx1=hlinex1;
	yy1=hliney1;
	if (xx>319) xx=319;
	if (xx1>319) xx1=319;
	if (yy>199) yy=199;
	if (yy1>199) yy1=199;
	if (xx<0) xx=0;
	if (xx1<0) xx1=0;
	if (yy<0) yy=0;
	if (yy1<0) yy1=0;
	if (xx<=xx1 && yy==yy1) {
		xxa=xx1-xx;
		if (xxa<1) xxa=1;
		yyy=yy1-yy;
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0x80,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0x82,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0x84,2);
	movedata(__get_ds(),&hlinecolor,__get_cs(),0x86,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0x82]";
	asm "mov dx,[0x86]";
	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop es";
	asm "mov al,dl";
	asm "xor dx,dx";

asm "label2:";
asm "cld";
asm "rep";
asm "stosb";
	asm "pop ds";
			
			
		r=-1;
		
		
		}else{
			r=0;
			}
		
		return r;
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








void pixelset(pixelsetx,pixelsety,pixelsetcolor){


	int ir;
	int xx ;
int yy;
int xx1;
int yy1;
int xxx;
int yyy;
int r;
	
	int xxa;
	xx=pixelsetx;
	yy=pixelsety;
	if (xx>319 && yy>199 && xx<0 && yy<0) goto pixelsetexit;
	
		
	
			
	xxx=yy*320+xx;
	ir=screenptr;
	movedata(__get_ds(),&ir,__get_cs(),0xf080,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0xf082,2);
	movedata(__get_ds(),&pixelsetcolor,__get_cs(),0xf084,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0xf082]";
	asm "mov dx,[0xf084]";
	asm "mov ax,[0xf080]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";


asm "mov [di],al";

	asm "pop ds";
pixelsetexit:			
;

		
		
		}
void lineup(lineupx,lineupy,lineupx1,lineupy1,lineupcolor){
int xxx1;
int yyy1;
int xxx;
int yyy;
int xx;
int yy;
int xx1;
int yy1;
int diferent;
int n;
int m;
long l1;
long l2;
long l3;
long l4;

xx=lineupx;
yy=lineupy;
xx1=lineupx1;
yy1=lineupy1;

xxx1=xx;
yyy1=yy;

xxx=xx1-xx;
yyy=yy-yy1;
diferent=xxx;
if (xxx<yyy) diferent=yyy;
l1=1000;
l2=1000;

if (xxx<yyy){
l1=xxx;
l1=l1*1000;
l3=yyy;
l1=l1/l3;
}
if (xxx>yyy){
l2=yyy;
l2=l2*1000;
l3=xxx;
l2=l2/l3;
}


l3=0;
l4=0;
if(xxx>-1 && yyy>-1){
pixelset(xxx1,yyy1,lineupcolor);
for (n=0;n<diferent;n++){
l3=l3+l1;
l4=l4+l2;
if (l3>1000){
l3=l3-1000;
xxx1++;
}
if (l4>1000){
l4=l4-1000;
yyy1--;
}

pixelset(xxx1,yyy1,lineupcolor);

}
}

}

void linedown(linedownx,linedowny,linedownx1,linedowny1,linedowncolor){
int xxx1;
int yyy1;
int xxx;
int yyy;
int xx;
int yy;
int xx1;
int yy1;
int diferent;
int n;
int m;
long l1;
long l2;
long l3;
long l4;

xx=linedownx;
yy=linedowny;
xx1=linedownx1;
yy1=linedowny1;

xxx1=xx;
yyy1=yy;

xxx=xx1-xx;
yyy=yy1-yy;
diferent=xxx;
if (xxx<yyy) diferent=yyy;
l1=1000;
l2=1000;

if (xxx<yyy){
l1=xxx;
l1=l1*1000;
l3=yyy;
l1=l1/l3;
}
if (xxx>yyy){
l2=yyy;
l2=l2*1000;
l3=xxx;
l2=l2/l3;
}


l3=0;
l4=0;
if(xxx>-1 && yyy>-1){

pixelset(xxx1,yyy1,linedowncolor);
for (n=0;n<diferent;n++){
l3=l3+l1;
l4=l4+l2;
if (l3>999){
l3=l3-1000;
xxx1++;
}
if (l4>999){
l4=l4-1000;
yyy1++;
}



if (xxx1>319 || yyy1>199) goto linedownexit;
pixelset(xxx1,yyy1,linedowncolor);

}
}
linedownexit:
;
}





