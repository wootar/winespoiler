void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	void (*realFlush)(GLfloat,GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glVertex3f");
	if(realFlush != NULL) realFlush(x,z,y,w);
};
