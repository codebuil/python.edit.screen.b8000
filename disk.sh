printf "\ec\e[44;37m\n"
imgs="../out.img"
printf $imgs
rm *.img
rm *.iso
rm $imgs
sudo mkdir /mnt/new
#build image null
dd if=/dev/zero of=$imgs  bs=1M count=5
chmod 777 $imgs
sudo losetup --find --show $imgs /dev/loop0 
#create a empty disk image
sudo mkfs -t vfat /dev/loop0
sudo mount /dev/loop0 /mnt/new
roots="/mnt/new"
pppp=$(pwd)
cd $roots
#populate
list="dev home lost mnt proc run srv tmp usr/bin boot etc lib media opt root sbin sys tools var"
for a in $list
do
	sudo mkdir -p "$a"
done
cd boot
backs=./
roots="$pppp"
mkdir -p  "$backs"
temps="/tmp/tmp"
ls "$roots"> $temps
while read a;do
printf "$roots/$a\n"
sudo cp -r "$roots/$a" "$backs/"
sudo chmod 777 "$backs/$a"
done <$temps


cd $pppp
sudo umount /dev/loop0
sudo losetup --detach /dev/loop0
dd conv=notrunc if=mbr.bin of=$imgs bs=1 seek=72


