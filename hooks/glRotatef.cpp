void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glRotate3f");
	if(realFlush != NULL) realFlush(z,y,x);
};
