mkdir -p CD_root/isolinux
mkdir -p CD_root/images
mkdir -p CD_root/kernel
cp isolinux.bin CD_root/isolinux/isolinux.bin
cp isolinux.cfg CD_root/kernel/isolinux.cfg
cp isolinux.cfg CD_root/isolinux/isolinux.cfg
cp isolinux.cfg CD_root/isolinux.cfg
cp isolinux.cfg CD_root/images/isolinux.cfg
cp ldlinux.c32 CD_root/isolinux/ldlinux.c32
cp kernel.bin CD_root/kernel/kernel.bin
cp kernel.bin CD_root/image/kernel.bin
cp memdisk CD_root/kernel/memdisk
mkisofs -o myos.iso -input-charset utf-8 -b isolinux/isolinux.bin -no-emul-boot -boot-load-size 4  -boot-info-table ./CD_root 

