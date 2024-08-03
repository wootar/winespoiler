void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
	void (*realFlush)(GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid *) = dlsym_real(RTLD_NEXT,"glVertexAttribPointe");
	//if(size != 0) {
		//memset(pointer,0,size);
	//}
	//getrandom(pointer,size,GRND_RANDOM);
	if(realFlush != NULL) realFlush(index,size,type,normalized,stride,pointer);
};