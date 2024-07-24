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
	if(realFlush != NULL) realFlush(target,level,internalFormat,width,height,border,format,type,data);
};


#endif
#ifndef NO_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
	void (*realFlush)(GLenum, GLsizei, GLenum, const void *) = dlsym_real(RTLD_NEXT,"glDrawElements");
	count -= count/2;
	if(realFlush != NULL) realFlush(mode,count,type,indices);
};


#endif
#ifndef NO_pa_stream_write
int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	return pa_stream_write_ext_free(p, data-2000, nbytes, free_cb, (void*) data, offset, seek);
};

#endif
#ifndef NO_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	void (*realFlush)(GLenum, GLint, GLsizei) = dlsym_real(RTLD_NEXT,"glDrawArrays");
	count -= count/2;
	if(realFlush != NULL) realFlush(mode,first,count);
};


#endif

void *dlsym(void *handle, const char *symbol) {
    printf("Request: %s\n",symbol);
#ifndef NO_glTexImage2D
   if(strcmp(symbol,"glTexImage2D") == 0) {return reinterpret_cast<void *>(&glTexImage2D);};
#endif
#ifndef NO_glDrawElements
   if(strcmp(symbol,"glDrawElements") == 0) {return reinterpret_cast<void *>(&glDrawElements);};
#endif
#ifndef NO_pa_stream_write
   if(strcmp(symbol,"pa_stream_write") == 0) {return reinterpret_cast<void *>(&pa_stream_write);};
#endif
#ifndef NO_glDrawArrays
   if(strcmp(symbol,"glDrawArrays") == 0) {return reinterpret_cast<void *>(&glDrawArrays);};
#endif


	if( dlsym_real == 0x0 ) {
		dlsym_real = dlvsym(RTLD_DEFAULT,"dlsym","GLIBC_2.34");	
	}
	void *out = dlsym_real(handle, symbol);
	return out;
}