printf "\033c\033[44;30m\n"
mkdir $HOME/src
cd $HOME/src
PREFIX="$HOME/opt/cross"
TARGET="i386-elf"
PATH="$PREFIX/bin:$PATH" 
mkdir gdb
cd gdb
curl https://ftp.gnu.org/gnu/gdb/gdb-10.1.tar.gz >./gdb-10.1.tar.gz
tar -xvf gdb-10.1.tar.gz
cd gdb-10.1
./configure --target=$TARGET --prefix="$PREFIX" --disable-werror
make all-gdb
make install-gdb