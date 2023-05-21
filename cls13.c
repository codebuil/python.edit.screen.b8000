#include <conio.h>
#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <varargs.h>
#include <stdlib.h>

int screenptr;
int screen13();
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);
void cls13(cls1);
int getptr();

void refresh();


void main(){
int hlinex;
int hliney;
int hlinex1;
int hliney1;
int hlinecolor;
	char a;	
	int c;
	int d;
	int tt;
	long l;
	long ll;
	char b=15;
	
	int t=screen13();
screenptr=getptr();
	
cls13(1);
hlinex=320/2+1;
hlinex1=320/2-1;
hlinecolor=1;
for (c=0;c<200;c++)
{
	hliney=c;
	hliney1=c;
	if (c<100){
		hlinex=hlinex-1;
		hlinex1=hlinex1+1;
		}else{
			hlinex=hlinex+1;
		hlinex1=hlinex1-1;
			}
			hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);
	}

a=(char)getccc();
screen3();
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
	movedata(__get_ds(),&ir,__get_cs(),0xf080,2);
	ir=xxx;
	movedata(__get_ds(),&ir,__get_cs(),0xf082,2);
	ir=xxa;
	movedata(__get_ds(),&ir,__get_cs(),0xf084,2);
	movedata(__get_ds(),&hlinecolor,__get_cs(),0xf086,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov di,[0xf082]";
	asm "mov dx,[0xf086]";
	
	asm "mov cx,[0xf084]";
	asm "mov ax,[0xf080]";
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

void refresh()
{
}