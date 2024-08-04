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
#ifndef NO_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glVertex3f");
	if(realFlush != NULL) realFlush(x,z,y,w);
};


#endif
#ifndef NO_glTexImage2D
void glTexImage2D(GLenum target,GLint level,GLint internalFormat,GLsizei width,GLsizei height,GLint border,GLenum format,GLenum type,const GLvoid * data) {
	void (*realFlush)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = dlsym_real(RTLD_NEXT,"glTexImage2D");
	getrandom(data,width*height,GRND_RANDOM);
	if(realFlush != NULL) realFlush(target,level,internalFormat,width,height,border,format,type,data);
};


#endif
#ifndef NO_glVertex4fi
void glVertex4fi(GLfloat *i) {
	void (*realFlush)(const GLfloat *) = dlsym_real(RTLD_NEXT,"glVertex4fi");
	if(realFlush != NULL) realFlush(i++);
};


#endif
#ifndef NO_glVertexAttribPointer
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
	void (*realFlush)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *) = dlsym_real(RTLD_NEXT,"glVertexAttribPointe");
	//if(size != 0) {
		//memset(pointer,0,size);
	//}
	//getrandom(pointer,size,GRND_RANDOM);
	if(realFlush != NULL) realFlush(index,size,type,normalized,stride,pointer);
};

#endif
#ifndef NO_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
	void (*realFlush)(GLenum, GLsizei, GLenum, const void *) = dlsym_real(RTLD_NEXT,"glDrawElements");
	if(count != 0) {
		count--;
		//getrandom(indices,count,GRND_RANDOM);
	}
	if(realFlush != NULL) realFlush(mode,count,type,indices);
};


#endif
#ifndef NO_glVertex3fi
void glVertex3fi(GLfloat *i) {
	void (*realFlush)(const GLfloat *) = dlsym_real(RTLD_NEXT,"glVertex3fi");
	if(realFlush != NULL) realFlush(i++);
};


#endif
#ifndef NO_pa_stream_write
int pa_stream_write(pa_stream * p, const void * data, size_t nbytes, pa_free_cb_t free_cb, int64_t offset, pa_seek_mode_t seek) {
	char a[32];
	getrandom(a,1,GRND_RANDOM);
	getrandom(data,nbytes-(char)a[0],GRND_RANDOM);
	return pa_stream_write_ext_free(p, data, nbytes, free_cb, (void*) data, offset, seek);
};

#endif
#ifndef NO_glColor4f
void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glColor4f");
	if(realFlush != NULL) realFlush(r,g,b,a);
};


#endif
#ifndef NO_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	void (*realFlush)(GLenum, GLint, GLsizei) = dlsym_real(RTLD_NEXT,"glDrawArrays");
	count++;
	if(realFlush != NULL) realFlush(mode,first,count);
};


#endif
#ifndef NO_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glVertex3f");
	if(realFlush != NULL) realFlush(x,z,y);
};


#endif
#ifndef NO_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glRotate3f");
	if(realFlush != NULL) realFlush(z,y,x);
};


#endif

void *dlsym(void *handle, const char *symbol) {
    printf("Request: %s\n",symbol);
#ifndef NO_glVertex4f
   if(strcmp(symbol,"glVertex4f") == 0) {return reinterpret_cast<void *>(&glVertex4f);};
#endif
#ifndef NO_glTexImage2D
   if(strcmp(symbol,"glTexImage2D") == 0) {return reinterpret_cast<void *>(&glTexImage2D);};
#endif
#ifndef NO_glVertex4fi
   if(strcmp(symbol,"glVertex4fi") == 0) {return reinterpret_cast<void *>(&glVertex4fi);};
#endif
#ifndef NO_glVertexAttribPointer
   if(strcmp(symbol,"glVertexAttribPointer") == 0) {return reinterpret_cast<void *>(&glVertexAttribPointer);};
#endif
#ifndef NO_glDrawElements
   if(strcmp(symbol,"glDrawElements") == 0) {return reinterpret_cast<void *>(&glDrawElements);};
#endif
#ifndef NO_glVertex3fi
   if(strcmp(symbol,"glVertex3fi") == 0) {return reinterpret_cast<void *>(&glVertex3fi);};
#endif
#ifndef NO_pa_stream_write
   if(strcmp(symbol,"pa_stream_write") == 0) {return reinterpret_cast<void *>(&pa_stream_write);};
#endif
#ifndef NO_glColor4f
   if(strcmp(symbol,"glColor4f") == 0) {return reinterpret_cast<void *>(&glColor4f);};
#endif
#ifndef NO_glDrawArrays
   if(strcmp(symbol,"glDrawArrays") == 0) {return reinterpret_cast<void *>(&glDrawArrays);};
#endif
#ifndef NO_glVertex3f
   if(strcmp(symbol,"glVertex3f") == 0) {return reinterpret_cast<void *>(&glVertex3f);};
#endif
#ifndef NO_glRotatef
   if(strcmp(symbol,"glRotatef") == 0) {return reinterpret_cast<void *>(&glRotatef);};
#endif


	if( dlsym_real == 0x0 ) {
		dlsym_real = dlvsym(RTLD_DEFAULT,"dlsym","GLIBC_2.34");	
	}
	void *out = dlsym_real(handle, symbol);
	return out;
}