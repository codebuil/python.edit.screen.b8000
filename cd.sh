mkdir -p CD_root/isolinux
mkdir -p CD_root/images
mkdir -p CD_root/kernel
cp isolinux.bin CD_root/isolinux/isolinux.bin
cp syslinux.cnf CD_root/syslinux.cnf
cp ldlinux.c32 CD_root/isolinux/ldlinux.c32
cp kernel.bin CD_root/kernel/kernel.bin
cp ldlinux.elf CD_root/kernel/ldlinux.elf
mkisofs -o myos.iso -input-charset utf-8 -b isolinux/isolinux.bin -no-emul-boot -boot-load-size 4  -boot-info-table ./CD_root 

