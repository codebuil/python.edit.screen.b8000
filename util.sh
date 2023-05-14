printf "\033c\033[44;30m\n"
mkdir $HOME/src
cd $HOME/src
PREFIX="$HOME/opt/cross"
TARGET="i386-elf"
PATH="$PREFIX/bin:$PATH" 
mkdir build-binutils
cd build-binutils
curl https://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.xz >./binutils-2.40.tar.xz
tar -xvf binutils-2.40.tar.xz
cd binutils-2.40
./configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install