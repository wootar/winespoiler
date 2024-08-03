void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices) {
	void (*realFlush)(GLenum, GLsizei, GLenum, const void *) = dlsym_real(RTLD_NEXT,"glDrawElements");
	if(count != 0) {
		count--;
		//getrandom(indices,count,GRND_RANDOM);
	}
	if(realFlush != NULL) realFlush(mode,count,type,indices);
};
