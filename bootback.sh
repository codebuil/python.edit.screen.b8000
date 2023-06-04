printf "\033c\033[44;37m\n"
backs=back/boot/
roots="/boot"
mkdir -p  "$backs"
temps="tmp"
ls "$roots"> tmp


while read a;do
printf "$roots/$a\n"
sudo cp -r "$roots/$a" "$backs/"
chmod 777 "$backs/$a"
done <$temps
chmod 777

