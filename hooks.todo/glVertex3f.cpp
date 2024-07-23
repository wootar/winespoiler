void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat *xz = &x;
	x = xz[87];
	GLfloat *yz = &y;
	y = yz[87];
	GLfloat *zz = &z;
	z = zz[87];
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glVertex3f");
	if(realFlush != NULL) realFlush(x,y,z);
};
