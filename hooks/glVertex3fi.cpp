void glVertex3fi(GLfloat *i) {
	void (*realFlush)(const GLfloat *) = dlsym_real(RTLD_NEXT,"glVertex3fi");
	if(realFlush != NULL) realFlush(i++);
};
