extern "C" void _start(){
    int *video_ptr = (int*)0xb8000;
    *video_ptr = 0x50505050;
    return;
}