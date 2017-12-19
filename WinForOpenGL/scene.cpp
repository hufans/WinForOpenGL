#include "scene.h"
void init() {
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void DrawModel(int V)
{
	if (V == 3) 
	{
		glBegin(GL_TRIANGLES);
		glColor4ub(129, 34, 255, 255);
		glVertex3f(0.0f, -0.2f, -1.5f);
		glVertex3f(-0.2f, 0.2f, -1.5f);
		glVertex3f(0.2f, 0.2f, -1.5f);
	}
	if (V == 4 )
	{
		glBegin(GL_QUADS);
		glColor4ub(255, 255, 255, 255);
		glVertex3f(-0.5f, -0.2f, -0.5f);
		glVertex3f(0.5f, -0.2f, -0.5f);
		glVertex3f(0.5f, -0.2f, -1.0f);
		glVertex3f(-0.5f, -0.2f, -1.0f);
	}
	//test
	glEnd();
}


void Draw()
{
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float lightPos[] = { 0.0f,1.0f,0.0f,0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	DrawModel(3);
	DrawModel(4);
	
}