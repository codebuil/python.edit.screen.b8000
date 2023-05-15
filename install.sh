printf "\033c\033[44;30m\n"
mkdir $HOME/src
cd $HOME/src
mkdir $HOME/src/cross
cd $HOME/src
pacman -S  make
pacman -S  bison
pacman -S  flex
pacman -S  gmp
pacman -S  mpc
pacman -S  mpfr
pacman -S  texinfo
pacman -S  isl
