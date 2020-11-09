#  Far From *NIX OS (FFSNIX OS)
An operating system based on the x86_64 architecture. Will hopefully emulate a UNIX OS in the future.

**Built by Kunal Bhat**

### Bootloader build instructions
Depends on `nasm`:
```
sh ./build_bootloader.sh build
```

### Running the bootloader
```
qemu-system-x86_64 src/out/bootloader.bin
```

### Clean directory
```
sh ./build_bootloader.sh clean
```

### Current Status
**Bootloader**
- [x] Detected by BIOS
- [x] Ability to read from disk
- [x] Ability to enter 32 bit Protected mode
- [ ] 64 bit protected mode supported
- [ ] UEFI Support

