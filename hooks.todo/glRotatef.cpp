void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
	GLfloat *az = &angle;
	angle = az[87];
	GLfloat *zz = &z;
	z = zz[87];
	void (*realFlush)(GLfloat,GLfloat,GLfloat) = dlsym_real(RTLD_NEXT,"glRotate3f");
	if(realFlush != NULL) realFlush(x,y,z);
};
