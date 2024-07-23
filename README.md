# WineSpoiler
### NOTE: This project is experimental.

Yet another game corrupter but for Linux, Also works with wine hence it's name.

# Requirements
> Note: glibc is mandatory, this may change later down the line by adding support to musl via an patch.
> Note: The requirements below may become optional later down the line, for now we assume that everything here is installed
* Mesa or any OpenGL library
* Pulseaudio

# Running
It's an simple ```LD_PRELOAD``` hook meaning all you have to do is include it in the LD_PRELOAD environment variable