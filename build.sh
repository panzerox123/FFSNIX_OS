#!/bin/sh
bool_nasm=0
function check_nasm
{
    if [[ -f `which nasm` ]]; then
        echo "Building Kernel"
        ((bool_nasm=1))
    else 
        echo "Please install nasm to build."
    fi
    return
}

function run_build
{
    check_nasm
    if [[ $bool_nasm == 1 ]]; then
        cd src/boot
        mkdir -p ../out/boot 2> /dev/null
        nasm -f bin -o ../out/boot/boot.bin boot.asm
        nasm -f elf64 -o ../out/boot/boot_ext.o boot_ext.asm
        nasm -f elf64 -o ../out/boot/bin.o bin.asm
        cd ../
        mkdir -p out/kernel 2> /dev/null
        echo "Using gcc toolchain"
        ../toolchain/build-tools/bin/x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c kernel/kernel.cpp -o out/kernel/kernel.o
        # ../toolchain/build-tools/bin/x86_64-elf-ld -o out/kernel/kernel.bin -Ttext 0x9000 out/boot/boot_ext.o out/kernel/kernel.o --oformat binary
        ../toolchain/build-tools/bin/x86_64-elf-ld -T"linker.ld"
        # objcopy -O binary out/kernel/kernel.tmp out/kernel/kernel.bin
        cat out/boot/boot.bin out/kernel/kernel.bin > out/os.bin
        cat out/boot/boot.bin out/kernel/kernel.bin > out/os.flp
        cd ../
    else 
        echo "nasm not found... exiting"
    fi
    return
}

function clean_build
{
    cd src
    rm -rf out
    cd ../
}

case "$1" in
    build) run_build ;;
    clean) clean_build ;;
    *) 
    echo "Usage: ./build_bootloader.sh [ build | clean ]"
    ;;
esac
