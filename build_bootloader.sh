#!/bin/sh
bool_nasm=0
function check_nasm
{
    if [[ -f `which nasm` ]]; then
        echo "Buidling Bootloader"
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
        nasm -f bin -o ../out/boot/boot_ext.bin boot_ext.asm
        cat ../out/boot/boot.bin ../out/boot/boot_ext.bin > ../out/boot/bootloader.bin
        cd ../..
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
