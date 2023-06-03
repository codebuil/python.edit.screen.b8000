printf "\ec\e[44;30m\n"
roots="CD_dir/"
list="dev home lost mnt proc run srv tmp usr/bin boot etc lib media opt root sbin sys tools var"
for a in $list
do
	mkdir -p "$roots$a"
done



