void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glVertex3f");
	if(realFlush != NULL) realFlush(x,z,y);
};
