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
#ifndef NO_glTexImage2D
void glTexImage2D(GLenum target,GLint level,GLint internalFormat,GLsizei width,GLsizei height,GLint border,GLenum format,GLenum type,const GLvoid * data) {
	void (*realFlush)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = dlsym_real(RTLD_NEXT,"glTexImage2D");
	width--;
	height--;
	// 4 bytes of luck
	const void *garbage = malloc(width*height*4);
	if(realFlush != NULL) realFlush(target,level,internalFormat,width,height,border,format,type,garbage);
	free(garbage);
};


#endif
#ifndef NO_pa_stream_write
int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	int (*realFlush)(pa_stream *, const void *, size_t, pa_free_cb_t, int64_t, pa_seek_mode_t) = dlsym_real(RTLD_NEXT,"pa_stream_write");
	//getrandom(data,nbytes,0);
	if(realFlush != NULL) return realFlush(p,data,nbytes,free_cb,offset,seek);
	else printf("Whoops, no pa_stream_write :(")
	// We're an little liar
	return 0;
};

#endif

void *dlsym(void *handle, const char *symbol) {
    printf("Request: %s\n",symbol);
#ifndef NO_glTexImage2D
   if(strcmp(symbol,"glTexImage2D") == 0) {return reinterpret_cast<void *>(&glTexImage2D);};
#endif
#ifndef NO_pa_stream_write
   if(strcmp(symbol,"pa_stream_write") == 0) {return reinterpret_cast<void *>(&pa_stream_write);};
#endif


	if( dlsym_real == 0x0 ) {
		dlsym_real = dlvsym(RTLD_DEFAULT,"dlsym","GLIBC_2.34");	
	}
	void *out = dlsym_real(handle, symbol);
	return out;
}