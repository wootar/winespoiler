#!/bin/sh
echo "Compiling 32-bit winespoiler"
CFLAGS="-m32" ./build.sh
mv winespoiler.so winespoiler32.so
echo "Compiling 64-bit winespoiler"
CFLAGS="-m64" ./build.sh