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
void pixelset(pixelsetx,pixelsety,pixelsetcolor);

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
refresh();
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
int xxx;	
int yyy;
int p;
int a;

xxx=0;
yyy=circler;


p=1-(yyy);
do{
pixelset(circlex+xxx,circley+yyy,circlecolor);	
pixelset(circlex+yyy,circley+xxx,circlecolor);	
pixelset(circlex+xxx,circley-yyy,circlecolor);	
pixelset(circlex+yyy,circley-xxx,circlecolor);	
pixelset(circlex-xxx,circley-yyy,circlecolor);	
pixelset(circlex-xxx,circley+yyy,circlecolor);	
pixelset(circlex-yyy,circley+xxx,circlecolor);	
pixelset(circlex-yyy,circley-xxx,circlecolor);	

if (p<0){
xxx=xxx+1;
yyy=yyy;
p=p+(2*xxx)+2;
}else

{
xxx=xxx+1;
yyy=yyy-1;
p=p+(2*(xxx-yyy))+1;
}



}while(xxx<yyy+1);




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



