if [ -z "$EXPERIMENTS" ]; then
	CFLAGS="$CFLGAS -DNO_pa_stream_write"
else
	echo "WARNING: Experiments are enabled"
	LIBS="$LIBS $(pkg-config --libs libpulse)"
fi

failure() {
	echo "Build failed: $1"
	exit 1
}

echo "Invoking generator"
python3 generator.py > vintager.cpp || failure "generator"
gcc -shared -o winespoiler.so -fPIC -fpermissive -lstdc++ $CFLAGS vintager.cpp $LIBS || failure "vintager.cpp"

if [ -n "$multilib" ]; then
	gcc -shared -o winespoiler32.so -m32 -fPIC -fpermissive -lstdc++ $CFLAGS vintager.cpp $LIBS || failure "32bit vintager.cpp"
fi

echo "Build successful."