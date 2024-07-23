// This is an generated file, edits will be overwritten
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define __USE_GNU
#include <dlfcn.h>
#include <GL/gl.h>
#include <cstdlib>
#include "luxuries.hpp"
static void * (*dlsym_real)(void *, const char *) = 0x0;
extern char *__progname;
void glTexImage2D(GLenum target,GLint level,GLint internalFormat,GLsizei width,GLsizei height,GLint border,GLenum format,GLenum type,const GLvoid * data) {
	void (*realFlush)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = dlsym_real(RTLD_NEXT,"glTexImage2D");
	width--;
	height--;
	// 4 bytes of luck
	const void *garbage = malloc(width*height*4);
	if(realFlush != NULL) realFlush(target,level,internalFormat,width,height,border,format,type,garbage);
	free(garbage);
};


void *dlsym(void *handle, const char *symbol) {
    printf("Request: %s\n",symbol);
   if(strcmp(symbol,"glTexImage2D") == 0) {return reinterpret_cast<void *>(&glTexImage2D);};


	if( dlsym_real == 0x0 ) {
		dlsym_real = dlvsym(RTLD_DEFAULT,"dlsym","GLIBC_2.34");	
	}
	void *out = dlsym_real(handle, symbol);
	return out;
}