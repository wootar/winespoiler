# vintager.cpp generator
import os
import sys

hookcpp_start = '''#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define __USE_GNU
#include <dlfcn.h>
#include <GL/gl.h>
#include <cstdlib>
#include "luxuries.hpp"
static void * (*dlsym_real)(void *, const char *) = 0x0;
extern char *__progname;'''

# This is meant to be in the end for c++ compilers to pick these up
# REPLACEMECPP should be replaced with a bunch of
# 	if(strcmp(symbol,"glRotatef") == 0) {
#		return reinterpret_cast<void *>(&glRotatef);
#	}

hookcpp_end = '''void *dlsym(void *handle, const char *symbol) {
    printf(\"Request: %s\\n\",symbol);
REPLACEMECPP

	if( dlsym_real == 0x0 ) {
		dlsym_real = dlvsym(RTLD_DEFAULT,"dlsym","GLIBC_2.34");	
	}
	void *out = dlsym_real(handle, symbol);
	return out;
}'''

generated = "// This is an generated file, edits will be overwritten\n"+hookcpp_start+"\n"

ifs = ""

def appendFile(file):
    with open(file) as opened:
        return opened.read()+"\n"

for i in os.walk("hooks"):
    for file in i[2]:
        funcname = file[0:len(file)-4]
        sys.stderr.write(f"Importing {funcname}\n")
        generated += appendFile(f"{i[0]}/"+file)
        # TODO: replace "void *" here due to functions varying
        ifs += f"   if(strcmp(symbol,\"{funcname}\") == 0) {'{'}return reinterpret_cast<void *>(&{funcname});{'}'};\n"

sys.stdout.write(generated+"\n"+hookcpp_end.replace("REPLACEMECPP",ifs))
