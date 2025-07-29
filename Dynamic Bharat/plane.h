#pragma once

#include<windows.h>
#include<math.h>
#include<gl/GL.h>

void PlaneCenter(void)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(-0.05f,-0.1f);
	glVertex2f(0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.36f,0.54f,0.66f);
	glVertex2f(0.05f,-0.1f);
	glVertex2f(-0.05f,-0.1f);
	glVertex2f(-0.1f,-0.2f);
	glVertex2f(0.1f,-0.2f);

	glEnd();

	//upper body
	glBegin(GL_QUADS);

	glVertex2f(0.1f,-0.2f);
	glVertex2f(-0.1f,-0.2f);
	glVertex2f(-0.1f,-0.5f);
	glVertex2f(0.1f,-0.5f);

	glEnd();

	//lower body
	glBegin(GL_QUADS);
	glVertex2f(0.07f,-0.5f);
	glVertex2f(-0.07f,-0.5f);
	glVertex2f(-0.07f,-0.7f);
	glVertex2f(0.07f,-0.7f);

	glEnd();

	//left big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.1f,-0.3f);
	glVertex2f(-0.3f,-0.4f);
	glVertex2f(-0.3f,-0.55);
	glVertex2f(-0.1f,-0.5f);

	glEnd();

	//right big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(0.3f,-0.4f);
	glVertex2f(0.1f,-0.3f);
	glVertex2f(0.1f,-0.5f);
	glVertex2f(0.3f,-0.55f);

	glEnd();

	//left bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-0.3f,-0.35f);
	glVertex2f(-0.32f,-0.35f);
	glVertex2f(-0.32f,-0.55f);
	glVertex2f(-0.3f,-0.55f);

	glEnd();

	//right bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.32f, -0.35f);
	glVertex2f(0.3f, -0.35f);
	glVertex2f(0.3f, -0.55f);
	glVertex2f(0.32f, -0.55f);

	glEnd();

	//left small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(-0.07f,-0.55f);
	glVertex2f(-0.2f,-0.65f);
	glVertex2f(-0.1f,-0.65f);
	glVertex2f(-0.07f,-0.63f);

	glEnd();

	//right small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.2f,-0.65f);
	glVertex2f(0.07f,-0.55f);
	glVertex2f(0.07f,-0.63f);
	glVertex2f(0.1f,-0.65f);

	glEnd();

	//lower body line
	glBegin(GL_QUADS);

	glColor3f(1.0f,1.0f,1.0f);
	glVertex2f(0.01f,-0.5f);
	glVertex2f(-0.01f,-0.5f);
	glVertex2f(-0.01f,-0.68f);
	glVertex2f(0.01f,-0.68f);

	glEnd();

	//end body line
	glBegin(GL_QUADS);

	glVertex2f(0.03f,-0.68f);
	glVertex2f(-0.03f,-0.68f);
	glVertex2f(-0.03f,-0.9f);
	glVertex2f(0.03f,-0.9f);

	glEnd();

	//upper body line
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.01f,-0.15f);
	glVertex2f(-0.01f,-0.15f);
	glVertex2f(-0.01f,-0.2f);
	glVertex2f(0.01f,-0.2f);

	glEnd();
}

void PlaneUpper(void)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(-0.05f, -0.1f);
	glVertex2f(0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(-0.05f, -0.1f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);

	glEnd();

	//upper body
	glBegin(GL_QUADS);

	glVertex2f(0.1f, -0.2f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(0.1f, -0.5f);

	glEnd();

	//lower body
	glBegin(GL_QUADS);
	glVertex2f(0.07f, -0.5f);
	glVertex2f(-0.07f, -0.5f);
	glVertex2f(-0.07f, -0.7f);
	glVertex2f(0.07f, -0.7f);

	glEnd();

	//left big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.1f, -0.3f);
	glVertex2f(-0.3f, -0.4f);
	glVertex2f(-0.3f, -0.55);
	glVertex2f(-0.1f, -0.5f);

	glEnd();

	//right big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.3f, -0.4f);
	glVertex2f(0.1f, -0.3f);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.3f, -0.55f);

	glEnd();

	//left bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -0.35f);
	glVertex2f(-0.32f, -0.35f);
	glVertex2f(-0.32f, -0.55f);
	glVertex2f(-0.3f, -0.55f);

	glEnd();

	//right bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.32f, -0.35f);
	glVertex2f(0.3f, -0.35f);
	glVertex2f(0.3f, -0.55f);
	glVertex2f(0.32f, -0.55f);

	glEnd();

	//left small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.07f, -0.55f);
	glVertex2f(-0.2f, -0.65f);
	glVertex2f(-0.1f, -0.65f);
	glVertex2f(-0.07f, -0.63f);

	glEnd();

	//right small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.2f, -0.65f);
	glVertex2f(0.07f, -0.55f);
	glVertex2f(0.07f, -0.63f);
	glVertex2f(0.1f, -0.65f);

	glEnd();

	//lower body line
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.01f, -0.5f);
	glVertex2f(-0.01f, -0.5f);
	glVertex2f(-0.01f, -0.68f);
	glVertex2f(0.01f, -0.68f);

	glEnd();

	//end body line
	glBegin(GL_QUADS);

	glColor3f(1, 0.4, 0.12);
	glVertex2f(0.03f, -0.68f);
	glVertex2f(-0.03f, -0.68f);
	glVertex2f(-0.03f, -0.9f);
	glVertex2f(0.03f, -0.9f);

	glEnd();

	//upper body line
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.01f, -0.15f);
	glVertex2f(-0.01f, -0.15f);
	glVertex2f(-0.01f, -0.2f);
	glVertex2f(0.01f, -0.2f);

	glEnd();
}

void PlaneLower(void)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(-0.05f, -0.1f);
	glVertex2f(0.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.36f, 0.54f, 0.66f);
	glVertex2f(0.05f, -0.1f);
	glVertex2f(-0.05f, -0.1f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.1f, -0.2f);

	glEnd();

	//upper body
	glBegin(GL_QUADS);

	glVertex2f(0.1f, -0.2f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(-0.1f, -0.5f);
	glVertex2f(0.1f, -0.5f);

	glEnd();

	//lower body
	glBegin(GL_QUADS);
	glVertex2f(0.07f, -0.5f);
	glVertex2f(-0.07f, -0.5f);
	glVertex2f(-0.07f, -0.7f);
	glVertex2f(0.07f, -0.7f);

	glEnd();

	//left big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.1f, -0.3f);
	glVertex2f(-0.3f, -0.4f);
	glVertex2f(-0.3f, -0.55);
	glVertex2f(-0.1f, -0.5f);

	glEnd();

	//right big wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.3f, -0.4f);
	glVertex2f(0.1f, -0.3f);
	glVertex2f(0.1f, -0.5f);
	glVertex2f(0.3f, -0.55f);

	glEnd();

	//left bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -0.35f);
	glVertex2f(-0.32f, -0.35f);
	glVertex2f(-0.32f, -0.55f);
	glVertex2f(-0.3f, -0.55f);

	glEnd();

	//right bar 
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.32f, -0.35f);
	glVertex2f(0.3f, -0.35f);
	glVertex2f(0.3f, -0.55f);
	glVertex2f(0.32f, -0.55f);

	glEnd();

	//left small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.07f, -0.55f);
	glVertex2f(-0.2f, -0.65f);
	glVertex2f(-0.1f, -0.65f);
	glVertex2f(-0.07f, -0.63f);

	glEnd();

	//right small wing
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.2f, -0.65f);
	glVertex2f(0.07f, -0.55f);
	glVertex2f(0.07f, -0.63f);
	glVertex2f(0.1f, -0.65f);

	glEnd();

	//lower body line
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.01f, -0.5f);
	glVertex2f(-0.01f, -0.5f);
	glVertex2f(-0.01f, -0.68f);
	glVertex2f(0.01f, -0.68f);

	glEnd();

	//end body line
	glBegin(GL_QUADS);

	glColor3f(0.02, 0.42, 0.22);
	glVertex2f(0.03f, -0.68f);
	glVertex2f(-0.03f, -0.68f);
	glVertex2f(-0.03f, -0.9f);
	glVertex2f(0.03f, -0.9f);

	glEnd();

	//upper body line
	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.01f, -0.15f);
	glVertex2f(-0.01f, -0.15f);
	glVertex2f(-0.01f, -0.2f);
	glVertex2f(0.01f, -0.2f);

	glEnd();
}