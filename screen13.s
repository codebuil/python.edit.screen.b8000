
#./screen13:     formato de ficheiro elf32-i386
00001189 <main>:
    1189:	55                   	push   %ebp
    118a:	89 e5                	mov    %esp,%ebp
    118c:	e8 12 00 00 00       	call   11a3 <__x86.get_pc_thunk.ax>
    1191:	05 6f 2e 00 00       	add    $0x2e6f,%eax
    1196:	66 b8 13 00          	mov    $0x13,%ax
    119a:	cd 10                	int    $0x10
    119c:	b8 00 00 00 00       	mov    $0x0,%eax
    11a1:	5d                   	pop    %ebp
    11a2:	c3                   	ret    
