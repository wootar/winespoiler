#!/bin/sh
# Le fancy wrapper for Winespoiler

export LD_PRELOAD="$PWD/winespoiler32.so:$PWD/winespoiler.so"

sh -c "$*"