void glVertex4fi(GLfloat *i) {
	void (*realFlush)(const GLfloat *) = dlsym_real(RTLD_NEXT,"glVertex4fi");
	if(realFlush != NULL) realFlush(i++);
};
