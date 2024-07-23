echo "Invoking generator"
python3 generator.py > vintager.cpp || exit 1

gcc -shared -o winespoiler.so -fPIC -fpermissive -lstdc++ $CFLAGS vintager.cpp
