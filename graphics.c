#include <bios.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <varargs.h>



int screenptr;
int screen13();
int hlines(hlinex,hliney,hlinex1,hliney1,hlinecolor);
void cls13(cls1);
int getptr();
void refresh();


void main(){
	char a;
	int c;
	int d;
	long l;
	long ll;
	char b=1;
	
	int t=screen13();
screenptr=getptr();
cls13(1);


d=1;
l=0;
for(c=0;c<200;c++){
hlines(0,c,d,c,1);
l=l+2100;
ll=l/1000;
d=ll;
l=l-500;

}
refresh();
a=getccc();
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
	union REGS r1;
	union REGS r;
	r.h.ah=0;
	r.h.al=0x0;
	int86(0x16,&r,&r1);
	return r1.x.ax;
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
	asm "mov bx,[0x82]";
	asm "mov dx,[0x86]";
	
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "mov al,dl";
	asm "xor dx,dx";
asm "label2:";
asm "mov [bx],al";
asm "inc bx";
asm "dec cx";
asm "cmp cx,dx";
	asm "jnz label2";
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
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=320*200;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	movedata(__get_ds(),&cls1,__get_cs(),0x84,1);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x82]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "xor dx,dx";
	asm "mov al,cl";
	
asm "label1:";
asm "mov [bx],al";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label1";
	asm "pop ds";
	
	}






	int getptr(){
		
		
		return 0xa000;
		
		}

void refresh()
{

	
	}
