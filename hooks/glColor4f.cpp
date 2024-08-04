void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glColor4f");
	if(realFlush != NULL) realFlush(r,g,b,a);
};
