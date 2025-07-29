#pragma once

#include"Scene1.h"

GLuint texture_bricks;
GLuint texture_Roof;
GLuint texture_Door;
GLuint texture_Window;

extern GLfloat angle;

//void drawBorder(float, float, float, float, float, float, float, float);
//
////void House(void)
////{
////	//function declaration
////	void Terrace_house(void);
////
////	glPushMatrix();
////
////	glTranslatef(0.0f, 4.5f, 0.0f);
////	glScalef(3.0f, 1.5f, 2.5f);
////	glColor3f(1.0f, 1.0f, 0.0f);
////	Terrace_house();
////
////	glPopMatrix();
////
////	glPushMatrix();
////	
////	glColor3f(1.0, 0.0, 0.0);
////	glScalef(2.5f, 0.3f, 2.5f);
////	Cube();//base level
////	//glPopMatrix();
////
////	//glPushMatrix();
////	glTranslatef(0.0f,6.0f,0.0f);
////	glScalef(0.95,5.0,0.95);
////	glColor3f(0.0f, 0.0f, 1.0f);
////	Cube();//room 
////
////
////	glPopMatrix();
////
////	
////
////
////}
////
////void Terrace_house(void)
////{
////
////	glBegin(GL_QUADS);
////
////	//front fase
////	glVertex3f(0.1f, 1.0f, 1.0f);//right top
////	glVertex3f(-0.1f, 1.0f, 1.0f);//left top
////	glVertex3f(-1.0f, -1.0f, 1.0f);//left bottom
////	glVertex3f(1.0f, -1.0f, 1.0f);//right bottom
////
////	//right fase
////	glVertex3f(0.1f, 1.0f, -1.0f);
////	glVertex3f(0.1f, 1.0f, 1.0f);
////	glVertex3f(1.0f, -1.0f, 1.0f);
////	glVertex3f(1.0f, -1.0f, -1.0f);
////
////	//back face 
////	glVertex3f(-0.1f, 1.0f, -1.0f);
////	glVertex3f(0.1f, 1.0f, -1.0f);
////	glVertex3f(1.0f, -1.0f, -1.0f);
////	glVertex3f(-1.0f, -1.0f, -1.0f);
////
////	//left fase
////	glVertex3f(-0.1f, 1.0f, 1.0f);
////	glVertex3f(-0.1f, 1.0f, -1.0f);
////	glVertex3f(-1.0f, -1.0f, -1.0f);
////	glVertex3f(-1.0f, -1.0f, 1.0f);
////
////	//top fase
////	glVertex3f(0.1f, 1.0f, -1.0f);
////	glVertex3f(-0.1f, 1.0f, -1.0f);
////	glVertex3f(-0.1f, 1.0f, 1.0f);
////	glVertex3f(0.1f, 1.0f, 1.0f);
////
////	////bottom fase
////	//glVertex3f(1.0f, -1.0f, -1.0f);
////	//glVertex3f(-1.0f, -1.0f, -1.0f);
////	//glVertex3f(-1.0f, -1.0f, 1.0f);
////	//glVertex3f(1.0f, -1.0f, 1.0f);
////
////	glEnd();
////}
//
//void house()
//{
//	//glTranslatef(0.5f, -0.2f, 0.0f);
//	//glScalef(0.8f, 0.8f, 0.0f);
//
//
//	//Big tower of house
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.5f, 0.15f);
//	glVertex2f(0.5f, -0.8f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.9f, -0.8f);
//	glVertex2f(0.9f, 0.15f);
//	glEnd();
//	drawBorder(0.5f, 0.15f, 0.5f, -0.8f, 0.9f, -0.8f, 0.9f, 0.15f);
//
//
//	//Tower upper triangle
//	glBegin(GL_TRIANGLES);
//	glColor3f(0.9, 0.9, 0.4);	//Brown dark
//	glVertex2f(0.5f, 0.15f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.9f, 0.15f);
//	glColor3f(0.9, 0.9, 0.5);
//	glVertex2f(0.7f, 0.35f);
//	glEnd();
//
//	//Tower Ceiling Left
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.45f, 0.15f);
//	glVertex2f(0.5f, 0.15);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.7f, 0.35f);
//	glVertex2f(0.7f, 0.4f);
//	glEnd();
//
//	//Tower Ceiling Right
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.7f, 0.4);
//	glVertex2f(0.7f, 0.35);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.9f, 0.15f);
//	glVertex2f(0.95f, 0.15f);
//	glEnd();
//
//	//Upper Window (inner)
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.59f, 0.11f);
//	glVertex2f(0.59f, -0.11f);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.81f, -0.11f);
//	glVertex2f(0.81f, 0.11f);
//	glEnd();
//
//	//Upper Window (outer)
//	glBegin(GL_QUADS);
//
//	glColor3f(0.71, 0.83, 0.80);
//	glVertex2f(0.6f, 0.1f);
//	glVertex2f(0.6f, -0.1f);
//	glColor3f(0.85, 0.88, 0.87);
//	glVertex2f(0.8f, -0.1f);
//	glVertex2f(0.8f, 0.1f);
//	glEnd();
//
//	// Window + sign
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.7f, 0.1f);
//	glVertex2f(0.7f, -0.1f);
//	glEnd();
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.6f, 0.0f);
//	glVertex2f(0.8, 0.0f);
//	glEnd();
//
//
//	//Lower Window (inner)
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.59f, -0.34f);
//	glVertex2f(0.59f, -0.56f);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.81f, -0.56f);
//	glVertex2f(0.81f, -0.34f);
//	glEnd();
//
//	//Lower Window (outer)
//	glBegin(GL_QUADS);
//	glColor3f(0.71, 0.83, 0.80);
//	glVertex2f(0.6f, -0.35f);
//	glVertex2f(0.6f, -0.55f);
//	glColor3f(0.85, 0.88, 0.87);
//	glVertex2f(0.8f, -0.55f);
//	glVertex2f(0.8f, -0.35f);
//	glEnd();
//
//	// Window + sign
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.7f, -0.35f);
//	glVertex2f(0.7f, -0.55f);
//	glEnd();
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.6f, -0.45f);
//	glVertex2f(0.8f, -0.45f);
//	glEnd();
//
//
//	//--------------
//	//  Main House 
//	//---------------
//
//	//Main Square          ghar ka background main window
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.2f, 0.15f);
//	glVertex2f(-0.2f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.5f, -0.7f);
//	glVertex2f(0.5f, 0.15f);
//	glEnd();
//	drawBorder(-0.2f, 0.15f, -0.2f, -0.7f, 0.5f, -0.7f, 0.5f, 0.15f);
//
//
//	//Balcony		ground floor ka
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.35f, -0.7f);
//	glVertex2f(-0.35f, -0.8f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.5f, -0.8f);
//	glVertex2f(0.5f, -0.7f);
//	glEnd();
//	drawBorder(-0.35f, -0.7f, -0.35f, -0.8f, 0.5f, -0.8f, 0.5f, -0.7f);
//
//
//	// BAlcony Piller 1
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.16f, -0.62f);
//	glVertex2f(-0.16f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.14f, -0.7f);
//	glVertex2f(-0.14f, -0.62f);
//	glEnd();
//	drawBorder(-0.16f, -0.62f, -0.16f, -0.7f, -0.14f, -0.7f, -0.14f, -0.62f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.06f, -0.62f);
//	glVertex2f(-0.06f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.04f, -0.7f);
//	glVertex2f(-0.04f, -0.62f);
//	glEnd();
//	drawBorder(-0.06f, -0.62f, -0.06f, -0.7f, -0.04f, -0.7f, -0.04f, -0.62f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.04f, -0.62f);
//	glVertex2f(0.04f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.06f, -0.7f);
//	glVertex2f(0.06f, -0.62f);
//	glEnd();
//	drawBorder(0.04f, -0.62f, 0.04f, -0.7f, 0.06f, -0.7f, 0.06f, -0.62f);
//
//	//Balcony blocks
//	//3
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.5f, -0.6f);
//	glVertex2f(0.5f, -0.8f);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.6f, -0.8f);
//	glVertex2f(0.6f, -0.6f);
//	glEnd();
//	drawBorder(0.5f, -0.6f, 0.5f, -0.8f, 0.6f, -0.8f, 0.6f, -0.6f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.49f, -0.6f);
//	glVertex2f(0.49f, -0.62f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.61f, -0.62f);
//	glVertex2f(0.61f, -0.6f);
//	glEnd();
//	drawBorder(0.49f, -0.6f, 0.49f, -0.62f, 0.61f, -0.62f, 0.61f, -0.60f);
//
//	// block Piller 2
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.1f, -0.6f);
//	glVertex2f(0.1f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.2f, -0.7f);
//	glVertex2f(0.2f, -0.6f);
//	glEnd();
//	drawBorder(0.1f, -0.6f, 0.1f, -0.7f, 0.2f, -0.7f, 0.2f, -0.6f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.09f, -0.6f);
//	glVertex2f(0.09f, -0.62f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.21f, -0.62f);
//	glVertex2f(0.21f, -0.60f);
//	glEnd();
//	drawBorder(0.09f, -0.6f, 0.09f, -0.62f, 0.21f, -0.62f, 0.21f, -0.6f);
//
//	// Block Pillar 1
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.3f, -0.6f);
//	glVertex2f(-0.3f, -0.7f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.2f, -0.7f);
//	glVertex2f(-0.2f, -0.6f);
//	glEnd();
//	drawBorder(-0.3f, -0.6f, -0.3f, -0.7f, -0.2f, -0.7f, -0.2f, -0.6f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.31f, -0.6f);
//	glVertex2f(-0.31f, -0.62f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.19f, -0.62f);
//	glVertex2f(-0.19f, -0.6f);
//	glEnd();
//	drawBorder(-0.31f, -0.6f, -0.31f, -0.62f, -0.19f, -0.62f, -0.19f, -0.6f);
//
//	//Compund wall
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.19f, -0.6f);
//	glVertex2f(-0.19f, -0.62f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.09f, -0.62f);
//	glVertex2f(0.09f, -0.6f);
//	glEnd();
//	drawBorder(-0.19f, -0.6f, -0.19f, -0.62f, 0.09f, -0.62f, 0.09f, -0.6f);
//
//	//Ceiling of ground floor
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(-0.2f, -0.15f);
//	glVertex2f(-0.35f, -0.3f);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.65f, -0.3f);
//	glVertex2f(0.5f, -0.15f);
//	glEnd();
//
//	// Ceiling of 1st floor
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(-0.1f, 0.4f);
//	glVertex2f(-0.35f, 0.15f);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.45f, 0.15f);
//	glVertex2f(0.7f, 0.4f);
//	glEnd();
//
//	// Stairs
//
////1
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.2f, -0.7f);
//	glVertex2f(0.2f, -0.73f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.5f, -0.73f);
//	glVertex2f(0.5f, -0.7f);
//	glEnd();
//	drawBorder(0.2f, -0.7f, 0.2f, -0.73f, 0.5f, -0.73f, 0.5f, -0.7f);
//
//	//2
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.17f, -0.73f);
//	glVertex2f(0.17f, -0.76f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.53f, -0.76f);
//	glVertex2f(0.53f, -0.73f);
//	glEnd();
//	drawBorder(0.17f, -0.73f, 0.17f, -0.76f, 0.53f, -0.76f, 0.53f, -0.73f);
//
//	//3
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.14f, -0.76f);
//	glVertex2f(0.14f, -0.79f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.56f, -0.79f);
//	glVertex2f(0.56f, -0.76f);
//	glEnd();
//	drawBorder(0.14f, -0.76f, 0.14f, -0.79f, 0.56f, -0.79f, 0.56f, -0.76f);
//
//	//4
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.11f, -0.79f);
//	glVertex2f(0.11f, -0.82f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.59f, -0.82f);
//	glVertex2f(0.59f, -0.79f);
//	glEnd();
//	drawBorder(0.11f, -0.79f, 0.11f, -0.82f, 0.59f, -0.82f, 0.59f, -0.79f);
//
//	//Ceiling support Pillers
//	//Piller 1
//	glBegin(GL_QUADS);
//	glColor3f(0.30, 0.05, 0.01);
//	glVertex2f(-0.27f, -0.3f);
//	glVertex2f(-0.27f, -0.6f);
//	glColor3f(0.50, 0.20, 0.14);
//	glVertex2f(-0.23f, -0.6f);
//	glVertex2f(-0.23f, -0.3f);
//	glEnd();
//	drawBorder(-0.27f, -0.3f, -0.27f, -0.6f, -0.23f, -0.6f, -0.23f, -0.3f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.28f, -0.3f);
//	glVertex2f(-0.28f, -0.31f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.22f, -0.31f);
//	glVertex2f(-0.22f, -0.30f);
//	glEnd();
//	drawBorder(-0.28f, -0.3f, -0.28f, -0.31f, -0.22f, -0.31f, -0.22f, -0.30f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(-0.28f, -0.59f);
//	glVertex2f(-0.28f, -0.60f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(-0.22f, -0.60f);
//	glVertex2f(-0.22f, -0.59f);
//	glEnd();
//	drawBorder(-0.28f, -0.59f, -0.28f, -0.60f, -0.22f, -0.60f, -0.22f, -0.59f);
//
//	//Piller 2
//	glBegin(GL_QUADS);
//	glColor3f(0.30, 0.05, 0.01);
//	glVertex2f(0.13f, -0.31f);
//	glVertex2f(0.13f, -0.59f);
//	glColor3f(0.50, 0.20, 0.14);
//	glVertex2f(0.17f, -0.59f);
//	glVertex2f(0.17f, -0.31f);
//	glEnd();
//	drawBorder(0.13f, -0.31f, 0.13f, -0.59f, 0.17f, -0.59f, 0.17f, -0.31f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.12f, -0.30f);
//	glVertex2f(0.12f, -0.31f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.18f, -0.31f);
//	glVertex2f(0.18f, -0.3f);
//	glEnd();
//	drawBorder(0.12f, -0.30f, 0.12f, -0.31f, 0.18f, -0.31f, 0.18f, -0.3f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.12f, -0.59f);
//	glVertex2f(0.12f, -0.60f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.18f, -0.60f);
//	glVertex2f(0.18f, -0.59f);
//	glEnd();
//	drawBorder(0.12f, -0.59f, 0.12f, -0.60f, 0.18f, -0.60f, 0.18f, -0.59f);
//
//	//Piller 3
//	glBegin(GL_QUADS);
//	glColor3f(0.30, 0.05, 0.01);
//	glVertex2f(0.53f, -0.31f);
//	glVertex2f(0.53f, -0.59f);
//	glColor3f(0.50, 0.20, 0.14);
//	glVertex2f(0.57f, -0.59f);
//	glVertex2f(0.57f, -0.31f);
//	glEnd();
//	drawBorder(0.53f, -0.3f, 0.53f, -0.6f, 0.57f, -0.6f, 0.57f, -0.3f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.52f, -0.30f);
//	glVertex2f(0.52f, -0.31f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.58f, -0.31f);
//	glVertex2f(0.58f, -0.30f);
//	glEnd();
//	drawBorder(0.52f, -0.30f, 0.52f, -0.31f, 0.58f, -0.31f, 0.58f, -0.30f);
//
//	glBegin(GL_QUADS);
//	glColor3f(0.9, 0.9, 0.4);
//	glVertex2f(0.52f, -0.59f);
//	glVertex2f(0.52f, -0.6f);
//	glColor3f(0.9, 0.9, 0.6);
//	glVertex2f(0.58f, -0.60f);
//	glVertex2f(0.58f, -0.59f);
//	glEnd();
//	drawBorder(0.52f, -0.59f, 0.52f, -0.6f, 0.58f, -0.60f, 0.58f, -0.59f);
//
//	// First Floor window
//
//	glBegin(GL_QUADS);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(-0.01f, 0.11f);
//	glVertex2f(-0.01f, -0.11f);
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.31f, -0.11f);
//	glVertex2f(0.31f, 0.11f);
//	glEnd();
//
//	glBegin(GL_QUADS);
//	glColor3f(0.71, 0.83, 0.80);
//	glVertex2f(0.0f, 0.1f);
//	glVertex2f(0.0f, -0.1f);
//	glColor3f(0.85, 0.88, 0.87);
//	glVertex2f(0.3f, -0.1f);
//	glVertex2f(0.3f, 0.1f);
//	glEnd();
//
//	//+ in window
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.15f, 0.1f);
//	glVertex2f(0.15f, -0.1f);
//	glEnd();
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.0f, 0.0f);
//	glVertex2f(0.3, 0.0f);
//	glEnd();
//
//	// Door
//
//	glPushMatrix();
//	/*if (walk_trans >= 5.0f)
//		glRotatef(0.0f, 0.0f, 1.0f, 0.0f);*/
//
//	glBegin(GL_QUADS);//left door
//	glColor3f(0.30, 0.05, 0.01);
//	glVertex2f(0.24f, -0.34f);
//	glVertex2f(0.24f, -0.7f);
//	glVertex2f(0.46f, -0.7f);
//	glVertex2f(0.46f, -0.34f);
//	glEnd();
//
//	glBegin(GL_QUADS);//right ddor
//	glColor3f(0.62, 0.25, 0.02);
//	glVertex2f(0.25f, -0.35f);
//	glVertex2f(0.25f, -0.7f);
//	glColor3f(0.78, 0.37, 0.12);
//	glVertex2f(0.45f, -0.7f);
//	glVertex2f(0.45f, -0.35f);
//	glEnd();
//
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex2f(0.35f, -0.36f);
//	glVertex2f(0.35, -0.7f);
//	glEnd();
//
//	//Door latch
//	glBegin(GL_TRIANGLE_FAN);
//	glColor3f(0.05f, 0.05f, 0.05f);
//
//	// Right Latch
//	float x_new = 0.0f;
//	float y_new = 0.0f;
//	float pi = 2.0 * (22.0 / 7.0);
//	float radius = 0.01f;
//	glVertex2f(0.37f, -0.52);  // Centre
//
//	glColor3f(0.05f, 0.05f, 0.05f);		// Circumference color
//	for (float i = 0.0f; i < 360.0; i = i + 0.01f)
//	{
//		x_new = 0.37f + (0.01f * cos(i * (pi / 180.0)));
//		y_new = -0.52 + (0.01f * sin(i * (pi / 180.0)));
//		glVertex2f(x_new, y_new);
//	}
//	glEnd();
//
//	// Left  Latch
//	glBegin(GL_TRIANGLE_FAN);
//	glColor3f(0.05f, 0.05f, 0.05f);
//
//	// Right Latch
//	x_new = 0.0f;
//	y_new = 0.0f;
//	glVertex2f(0.33f, -0.52);  // Centre
//
//	glColor3f(0.05f, 0.05f, 0.05f);	// Circumference color
//	for (float i = 0.0f; i < 360.0; i = i + 0.01f)
//	{
//		x_new = 0.33f + (0.01f * cos(i * (pi / 180.0)));
//		y_new = -0.52 + (0.01f * sin(i * (pi / 180.0)));
//		glVertex2f(x_new, y_new);
//	}
//	glEnd();
//	glPopMatrix();
//
//
//
//	////Path way
//
//	//glPushMatrix();
//	//glTranslatef(-0.2, 0.0f, 0.0f);
//	//glScalef(1.5, 1.0f, 1.0f);
//	//glBegin(GL_QUADS);
//	//glColor3f(0.58, 0.6, 0.58);
//	//glVertex2f(0.22f, -0.81f);
//	//glColor3f(0.68, 0.69, 0.68);
//	//glVertex2f(0.5f, -0.81f);
//	//glColor3f(0.41, 0.41, 0.41);
//	//glVertex2f(0.68f, -4.0f);
//	//glColor3f(0.36, 0.38, 0.36);
//	//glVertex2f(0.02f, -4.0);
//	//glEnd();
//	//glPopMatrix();
//	// ------------ Texture --------------
//
//	// ----------------------------------------------------------
//	//glTranslatef(0.0, 0.0, 0.01);
//	////glRotatef(90, 0.0, 1.0, 0.0);
//	//glBindTexture(GL_TEXTURE_2D, tex_ashram);
//	//glBegin(GL_QUADS);
//	//glColor3f(0.98, 0.65, 0.3);
//
//	//glTexCoord2f(1.0, 1.0);
//	//glVertex3f(0.43f, 0.35f, 0.0f);
//
//	//glTexCoord2f(0.0, 1.0);
//	//glVertex3f(-0.08f, 0.35f, 0.0f);
//
//	//glTexCoord2f(0.0, 0.0);
//	//glVertex3f(-0.08f, 0.21f, 0.0f);
//
//	//glTexCoord2f(1.0, 0.0);
//	//glVertex3f(0.43f, 0.21f, 0.0f);
//
//	//glEnd();
//	//glBindTexture(GL_TEXTURE_2D, 0);
//	//// ----------------------------------------------------------
//}
//
//void drawBorder(float pt1_x, float pt1_y, float pt2_x, float pt2_y, float pt3_x, float pt3_y, float pt4_x, float pt4_y)
//{
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0, 0.0, 0.0);
//	glVertex2f(pt1_x, pt1_y);
//	glVertex2f(pt2_x, pt2_y);
//	glVertex2f(pt3_x, pt3_y);
//	glVertex2f(pt4_x, pt4_y);
//	glEnd();
//}

void House(void)
{
    // Front side
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_bricks);
    glTranslatef(0, 0, -6);
    //glRotatef(angle, 0.0, 1.0, 0.0);
    
    glBegin(GL_QUADS);  // Wall
    glTexCoord3f(0.0, 2.0, 0.1);
    glVertex3f(-2, 0, 1);
    glTexCoord3f(4.0, 2.0, 0.1);
    glVertex3f(2, 0, 1);
    glTexCoord3f(4.0, 0.0, 0.1);
    glVertex3f(2, -1.5, 1);
    glTexCoord3f(0.0, 0.0, 0.1);
    glVertex3f(-2, -1.5, 1);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_Roof);
    glBegin(GL_QUADS);  // Roof

    glTexCoord3f(0.0, 2.0, 0);
    glVertex3f(-2.2, 0.5, 0);

    glTexCoord3f(4.0, 2.0, 0);
    glVertex3f(2.2, 0.5, 0);

    glTexCoord3f(4.0, 0.0, 1.25);
    glVertex3f(2.2, -0.1, 1.25);

    glTexCoord3f(0.0, 0.0, 1.25);
    glVertex3f(-2.2, -0.1, 1.25);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_Door);

    glBegin(GL_QUADS);  // Door

    glTexCoord3f(0.0, 1.0, 1.0001);
    glVertex3f(-0.3, -0.4, 1.0001);

    glTexCoord3f(1.0, 1.0, 1.0001);
    glVertex3f(0.3, -0.4, 1.0001);

    glTexCoord3f(1.0, 0.0, 1.0001);
    glVertex3f(0.3, -1.5, 1.0001);

    glTexCoord3f(0.0, 0.0, 1.0001);
    glVertex3f(-0.3, -1.5, 1.0001);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_Window);

    glBegin(GL_QUADS);  // Window Left

    glTexCoord3f(0.0, 1.0, 1.0001);
    glVertex3f(-1.5, -0.3, 1.0001);

    glTexCoord3f(1.0, 1.0, 1.0001);
    glVertex3f(-0.75, -0.3, 1.0001);

    glTexCoord3f(1.0, 0.0, 1.0001);
    glVertex3f(-0.75, -0.8, 1.0001);

    glTexCoord3f(0.0, 0.0, 1.0001);
    glVertex3f(-1.5, -0.8, 1.0001);

    glEnd();

    glBegin(GL_QUADS);  // Window Right

    glTexCoord3f(0.0, 1.0, 1.0001);
    glVertex3f(1.5, -0.3, 1.0001);

    glTexCoord3f(1.0, 1.0, 1.0001);
    glVertex3f(0.75, -0.3, 1.0001);

    glTexCoord3f(1.0, 0.0, 1.0001);
    glVertex3f(0.75, -0.8, 1.0001);

    glTexCoord3f(0.0, 0.0, 1.0001);
    glVertex3f(1.5, -0.8, 1.0001);

    glEnd();

    glPopMatrix();

    // Back side
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_bricks);

    glTranslatef(0, 0, -6);
    //glRotatef(angle, 0.0, 1.0, 0.0);
    
    glBegin(GL_QUADS);  // Wall

    glTexCoord3f(0.0, 2.0, -1);
    glVertex3f(-2, 0, -1);

    glTexCoord3f(4.0, 2.0, -1);
    glVertex3f(2, 0, -1);

    glTexCoord3f(4.0, 0.0, -1);
    glVertex3f(2, -1.5, -1);

    glTexCoord3f(0.0, 0.0, -1);
    glVertex3f(-2, -1.5, -1);

    glEnd();


    glBindTexture(GL_TEXTURE_2D, texture_Roof);
    glBegin(GL_QUADS);  // Roof

    glTexCoord3f(0.0, 2.0, 0);
    glVertex3f(-2.2, 0.5, 0);

    glTexCoord3f(4.0, 2.0, 0);
    glVertex3f(2.2, 0.5, 0);

    glTexCoord3f(4.0, 0.0, -1.25);
    glVertex3f(2.2, -0.1, -1.25);

    glTexCoord3f(0.0, 0.0, -1.25);
    glVertex3f(-2.2, -0.1, -1.25);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, texture_Window);

    glBegin(GL_QUADS);  // Window Left

    glTexCoord3f(0.0, 1.0, -1.0001);
    glVertex3f(-1.5, -0.3, -1.0001);

    glTexCoord3f(1.0, 1.0, -1.0001);
    glVertex3f(-0.75, -0.3, -1.0001);

    glTexCoord3f(1.0, 0.0, -1.0001);
    glVertex3f(-0.75, -0.8, -1.0001);

    glTexCoord3f(0.0, 0.0, -1.0001);
    glVertex3f(-1.5, -0.8, -1.0001);

    glEnd();

    glBegin(GL_QUADS);  // Window Right

    glTexCoord3f(0.0, 1.0, 1.0001);
    glVertex3f(1.5, -0.3, -1.0001);

    glTexCoord3f(1.0, 1.0, 1.0001);
    glVertex3f(0.75, -0.3, -1.0001);

    glTexCoord3f(1.0, 0.0, 1.0001);
    glVertex3f(0.75, -0.8, -1.0001);

    glTexCoord3f(0.0, 0.0, 1.0001);
    glVertex3f(1.5, -0.8, -1.0001);

    glEnd();

    glPopMatrix();

    // Right side
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_bricks);

    glTranslatef(0, 0, -6);
    //glRotatef(angle, 0.0, 1.0, 0.0);
    
    glBegin(GL_QUADS);  // Wall

    glTexCoord3f(0.0, 2.0, 1);
    glVertex3f(2, 0, 1);

    glTexCoord3f(2.0, 2.0, -1);
    glVertex3f(2, 0, -1);

    glTexCoord3f(2.0, 0.0, -1);
    glVertex3f(2, -1.5, -1);

    glTexCoord3f(0.0, 0.0, 1);
    glVertex3f(2, -1.5, 1);

    glEnd();

    glBegin(GL_TRIANGLES);  // Wall Upper

    glTexCoord3f(0.0, 1.0, 0);
    glVertex3f(2, 0.5, 0);

    glTexCoord3f(1.0, 0.0, 1);
    glVertex3f(2, 0, 1);

    glTexCoord3f(-1.0, 0.0, -1);
    glVertex3f(2, 0, -1);

    glEnd();

    glPopMatrix();

    // Left side
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture_bricks);

    glTranslatef(0, 0, -6);
    //glRotatef(angle, 0.0, 1.0, 0.0);
    
    glBegin(GL_QUADS);  // Wall

    glTexCoord3f(0.0, 2.0, 1);
    glVertex3f(-2, 0, 1);

    glTexCoord3f(2.0, 2.0, -1);
    glVertex3f(-2, 0, -1);

    glTexCoord3f(2.0, 0.0, -1);
    glVertex3f(-2, -1.5, -1);

    glTexCoord3f(0.0, 0.0, 1);
    glVertex3f(-2, -1.5, 1);

    glEnd();

    glBegin(GL_TRIANGLES);  // Wall Upper

    glTexCoord3f(0.0, 1.0, 0);
    glVertex3f(-2, 0.5, 0);

    glTexCoord3f(1.0, 0.0, 1);
    glVertex3f(-2, 0, 1);

    glTexCoord3f(-1.0, 0.0, -1);
    glVertex3f(-2, 0, -1);

    glEnd();

    glPopMatrix();
}