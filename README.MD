#  Far From *NIX OS (FFSNIX OS)
An operating system based on the x86_64 architecture. Will hopefully emulate a UNIX OS in the future.
Written in C++ *for now*. Rust planned for later.

**Built by Kunal Bhat**

### Build instructions
1) Download required dependencies.

**Debian/Ubuntu**
```
sudo apt-get update
sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo nasm
```
**Arch/Manjaro** 
```
sudo pacman -Sy
sudo pacman -S base-devel gcc nasm
```

2) Run script to build toolchain.
```
sh build_toolchain.sh
```
**This can take anywhere from 10 minutes to a couple hours depending on how fast your system is. You can use an x86_64-elf prebuilt toolchain**

3) Run script to build the kernel.
```
sh build.sh build
```

### Running the OS
```
qemu-system-x86_64 src/out/os.bin
```

### Cleaning build directory
**This will delete all built files**
```
sh build.sh clean
```

### Current Status
**Bootloader**
- [x] Detected by BIOS
- [x] Ability to read from disk
- [x] Ability to enter 32 bit Protected mode
- [x] 64 bit protected mode supported
- [ ] UEFI Support

**Kernel**
- [x] Can load C/C++ code
