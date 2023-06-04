printf "\ec\e[44;30m\n"
dd if=/dev/zero of=out.img  bs=143k count=100
sudo mkfs.vfat -n '_' -S 512 -f 2 -F 12 out.img
sudo mkdir /mnt/new
chmod 777 out.img
sudo mount -t vfat -o loop out.img /mnt/new
roots="/mnt/new"
pppp=$(pwd)
cd $roots
list="dev home lost mnt proc run srv tmp usr/bin boot etc lib media opt root sbin sys tools var"
for a in $list
do
	sudo mkdir -p "$a"
done
cd $pppp
sudo umount $roots
