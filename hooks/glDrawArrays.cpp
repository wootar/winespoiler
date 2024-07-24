void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	void (*realFlush)(GLenum, GLint, GLsizei) = dlsym_real(RTLD_NEXT,"glDrawArrays");
	count++;
	if(realFlush != NULL) realFlush(mode,first,count);
};
