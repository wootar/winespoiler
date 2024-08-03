void glTexImage2D(GLenum target,GLint level,GLint internalFormat,GLsizei width,GLsizei height,GLint border,GLenum format,GLenum type,const GLvoid * data) {
	void (*realFlush)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *) = dlsym_real(RTLD_NEXT,"glTexImage2D");
	getrandom(data,width*height,GRND_RANDOM);
	if(realFlush != NULL) realFlush(target,level,internalFormat,width,height,border,format,type,data);
};
