if [ -z "$EXPERIMENTS" ]; then
	CFLAGS="$CFLGAS -DNO_pa_stream_write"
else
	echo "WARNING: Experiments are enabled"
fi

echo "Invoking generator"
python3 generator.py > vintager.cpp || exit 1

gcc -shared -o winespoiler.so -fPIC -fpermissive -lstdc++ $CFLAGS vintager.cpp
