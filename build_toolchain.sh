#!/bin/sh
echo "WARNING: This script can take anywhere from a couple minutes to a couple hours to run depending on your PC. If your PC is not powerful enough, please use a prebuilt toolchain available in the repo."
echo "Would you like to continue? [y/n]"
read choice
if [ $choice == 'y' ]; then
echo "Running script to build toolchain..."
echo "Making Directories"
mkdir toolchain 2>/dev/null
cd toolchain
mkdir build-bintools 2>/dev/null
mkdir build-gcc 2>/dev/null
mkdir build-tools 2>/dev/null
echo "Downloading binutils and gcc source code"
curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.xz > /dev/null
curl -O https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.xz > /dev/null
export PREFIX="$(pwd)/build-tools"
export TARGET=x86_64-elf
"Extracting files"
tar xf toolchain/binutils-2.35.tar.xz
tar xf toolchain/gcc-10.2.0.tar.xz
echo "Building binutils..."
cd build-bintools
../binutils-2.35/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror > /dev/null
make -j4 > /dev/null
make install > /dev/null
cd ../build-gcc
echo "Building gcc..."
../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers > /dev/null
make all-gcc -j4 > /dev/null
make all-target-libgcc -j4 > /dev/null
make install-gcc > /dev/null
make install-target-libgcc > /dev/null
echo "Toolchain ready."
fi