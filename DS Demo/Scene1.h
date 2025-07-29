#pragma once

#include <gl/GL.h> 

#include<gl/GLU.h>
#include<math.h>

#define _USE_MATH_DEFINES 1

#define PI 3.14

#include"House.h"
#include"Humanoid.h"

//extern GLuint texture_sky;
//extern GLuint texture_grass;
//extern GLuint texture_mother;
//extern GLfloat angle;
//GLuint texture_Well;
//GLuint tree_root;

float translateboyZ =6.0f;

void Cube(void)
{

	glBegin(GL_QUADS);

	//front fase
	glVertex3f(1.0f, 1.0f, 1.0f);//right top
	glVertex3f(-1.0f, 1.0f, 1.0f);//left top
	glVertex3f(-1.0f, -1.0f, 1.0f);//left bottom
	glVertex3f(1.0f, -1.0f, 1.0f);//right bottom

	//right fase
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//back face 
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	//left fase
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	//top fase
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//bottom fase
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
}

void Tree_unit(void)
{
	glPushMatrix();
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(-6.5f, -2.0f, 0.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	//glColor3f(0.71, 0.37, 0.02);

	// Stem
	glBindTexture(GL_TEXTURE_2D, tree_root);
	gluQuadricTexture(quadric, GL_TRUE);
	gluCylinder(quadric, 0.8f, 0.4f, 0.4f, 4, 4);
	gluCylinder(quadric, 0.4, 0.4, 3.5f, 4, 4);
	glBindTexture(GL_TEXTURE_2D, 0);

	glTranslatef(0.0f, 0.0f, 4.0f);
	glBindTexture(GL_TEXTURE_2D, tree_root);
	gluQuadricTexture(quadric, GL_TRUE);

	glPushMatrix();
	// Branches
	glColor3f(0.41, 0.97, 0.45);
	glTranslatef(0.0f, 0.8f, 0.0f);
	gluSphere(quadric, 1.2f, 5, 5);				// Sphere 1

	glColor3f(0.02, 0.99, 0.09);
	glTranslatef(0.8f, -0.8f, 0.0f);
	gluSphere(quadric, 1.2f, 5, 5);				// Sphere 2

	glColor3f(0.02, 0.54, 0.06);
	glTranslatef(-0.8f, -0.8f, 0.0f);
	gluSphere(quadric, 1.2f, 5, 5);				// Sphere 3
	glPopMatrix();

	glColor3f(0.11, 0.36, 0.13);
	glTranslatef(0.3f, 0.0f, 1.0f);
	gluSphere(quadric, 1.2f, 5, 5);

	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

void well(void)
{
	glPushMatrix();
	glRotatef(90,1.0,0.0,0.0);
	glBindTexture(GL_TEXTURE_2D, texture_Well);
	gluQuadricTexture(quadric, GL_TRUE);
	//gluCylinder(quadric, 0.8f, 0.8f, 1.2f, 15,15);
	gluCylinder(quadric, 0.9f, 0.9f, 1.2f, 25,25);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

void drawQuad_with_colors_Coconut_grass(float x_pt1, float y_pt1, float x_pt2, float y_pt2, float x_pt3, float y_pt3, float x_pt4, float y_pt4, float r_pt1, float g_pt1, float b_pt1, float r_pt3, float g_pt3, float b_pt3)
{
	glPushMatrix();
	//glTranslatef(x_grass_translate, y_grass_translate, 0.0);
	glBegin(GL_QUADS);
	glColor4f(r_pt1, g_pt1, b_pt1, 1.0);
	glVertex2f(x_pt1, y_pt1);
	glVertex2f(x_pt2, y_pt2);
	glColor4f(r_pt3, g_pt3, b_pt3, 1.0);
	glVertex2f(x_pt3, y_pt3);
	glVertex2f(x_pt4, y_pt4);
	glEnd();
	glPopMatrix();
}

void drawTriangle_CoconutWithColors_grass(float x_pt1, float y_pt1, float x_pt2, float y_pt2, float x_pt3, float y_pt3)
{

	glPushMatrix();
	//glTranslatef(x_grass_translate, y_grass_translate, 0.0);
	// Ground
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.03, 0.47, 0.02);

	glVertex3f(x_pt1, y_pt1, 0.0f);
	glVertex3f(x_pt2, y_pt2, 0.0f);
	glVertex3f(x_pt3, y_pt3, 0.0f);
	glEnd();
	glPopMatrix();
}

void Grass(void)
{
	
	//Base layer 1
	drawQuad_with_colors_Coconut_grass(0.0f, 0.0f, 0.07f, 0.0f, 0.15f, 0.05f, -0.1f, 0.05f, 0.01, 0.31, 0.01, 0.01, 0.31, 0.01);

	//Base layer 2
	drawQuad_with_colors_Coconut_grass(-0.1f, 0.05f, 0.15f, 0.05f, 0.2f, 0.1f, -0.15f, 0.1f, 0.01, 0.31, 0.01, 0.01, 0.31, 0.01);

	// Base layer square 3
	drawQuad_with_colors_Coconut_grass(-0.1f, 0.1f, 0.15f, 0.1f, 0.15f, 0.2f, -0.1f, 0.2f, 0.01, 0.31, 0.01, 0.01, 0.31, 0.01);

	//BAse layet layer 4 Trapazium
	drawQuad_with_colors_Coconut_grass(-0.1f, 0.2f, 0.15f, 0.2f, 0.10f, 0.25f, -0.05f, 0.25f, 0.01, 0.31, 0.01, 0.01, 0.31, 0.01);

	// Upper base layer 5
	drawQuad_with_colors_Coconut_grass(-0.05f, 0.25f, 0.1f, 0.25f, 0.05f, 0.35f, 0.0f, 0.35f, 0.01, 0.32, 0.01, 0.01, 0.31, 0.01);

	//Leaf one
	drawQuad_with_colors_Coconut_grass(-0.15, 0.1f, -0.1f, 0.1f, -0.2f, 0.2f, -0.2f, 0.15f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(-0.2, 0.15, -0.2f, 0.2, -0.3f, 0.1);

	//Leaf Two
	drawQuad_with_colors_Coconut_grass(-0.1, 0.1f, -0.1f, 0.2f, -0.2f, 0.3f, -0.2f, 0.25f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(-0.2, 0.25, -0.2f, 0.3f, -0.3f, 0.25);

	//Leaf Three
	drawQuad_with_colors_Coconut_grass(-0.1, 0.2f, -0.05f, 0.25f, -0.1f, 0.35f, -0.15f, 0.35f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(-0.1f, 0.35f, -0.15f, 0.35f, -0.25f, 0.4);


	//Leaf four
	drawQuad_with_colors_Coconut_grass(-0.05, 0.25f, 0.0f, 0.35f, -0.05f, 0.45f, -0.1f, 0.45f, 0.01, 0.32, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(-0.05f, 0.45f, -0.1f, 0.45f, -0.15f, 0.5f);

	// Centre Leaf Rectangle
	drawQuad_with_colors_Coconut_grass(0.0f, 0.35f, 0.05f, 0.35f, 0.05f, 0.45f, 0.0f, 0.45f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);

	// Top leaf Left side 
	drawTriangle_CoconutWithColors_grass(0.05f, 0.45f, 0.0f, 0.45f, -0.1f, 0.6f);

	//Top leaf right side 
	drawTriangle_CoconutWithColors_grass(0.05f, 0.45f, 0.0f, 0.45f, 0.05f, 0.6f);

	//Right top leaf
	drawQuad_with_colors_Coconut_grass(0.05, 0.35f, 0.1f, 0.25f, 0.15f, 0.45f, 0.1f, 0.45f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(0.15f, 0.45f, 0.1f, 0.45f, 0.20f, 0.5f);

	// Right side second top leaf
	drawQuad_with_colors_Coconut_grass(0.1f, 0.25f, 0.15f, 0.20f, 0.2f, 0.35f, 0.15f, 0.35f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(0.2f, 0.35f, 0.15f, 0.35f, 0.25f, 0.4f);

	// Right side third leaf
	drawQuad_with_colors_Coconut_grass(0.15f, 0.2f, 0.15f, 0.10f, 0.25f, 0.25f, 0.25f, 0.30f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(0.25f, 0.25f, 0.25f, 0.30f, 0.35f, 0.25f);

	// RIght side botton leaf
	drawQuad_with_colors_Coconut_grass(0.15f, 0.1f, 0.2f, 0.10f, 0.25f, 0.15f, 0.25f, 0.20f, 0.01, 0.31, 0.01, 0.01f, 0.46f, 0.01f);
	drawTriangle_CoconutWithColors_grass(0.25f, 0.15f, 0.25f, 0.20f, 0.35f, 0.10f);

}


void ground(void)
{
	void Grass(void);

	// Left side straight Grass
	glPushMatrix();
	glScalef(0.8f, 0.90f, 0.8f);
	glTranslatef(-2.2f, -1.2f, 2.8f);

	float i = 0.0f;
	glScalef(1.5f, 1.5f, 1.0f);
	for (i = 0.0f; i >= -1.17f; i = i - 0.04f)
	{
		glTranslatef(0.0f, 0.0f, i);

		Grass();
	}
	glPopMatrix();


	// Right side straight Grass
	glPushMatrix();
	glScalef(0.8f, 0.90f, 0.8f);
	glTranslatef(2.2f, -1.2f, 2.8f);

	glScalef(1.5f, 1.5f, 1.0f);
	for (i = 0.0f; i >= -1.17f; i = i - 0.04f)
	{
		glTranslatef(0.0f, 0.0f, i);
		Grass();
	}
	glPopMatrix();

	// Left side grass
	glPushMatrix();
	glScalef(1.0f, 1.0f, 0.8f);
	glTranslatef(-1.8f, -1.1f, -16.0f);

	for (i = 0.0f; i >= -1.15f; i = i - 0.005f)
	{
		glTranslatef(i, 0.0f, 0.0f);
		Grass();
	}
	glPopMatrix();


	// Right side grass
	glPushMatrix();
	glScalef(1.0f, 1.0f, 0.8f);
	glTranslatef(1.8f, -1.1f, -16.0f);

	for (i = 0.0f; i <= 1.15f; i = i + 0.005f)
	{
		glTranslatef(i, 0.0f, 0.0f);
		Grass();
	}
	glPopMatrix();

}

void AMBcircle2(float xrad, float yrad, float AMB_i, float angle, float xPos, float yPos, float Red, float Green, float Blue, float Alpha)
{
	// Small Circle

	float xAMBcircle2;
	float yAMBcircle2;

	float OVNtheta = (PI / 180.0f);


	glBegin(GL_TRIANGLE_FAN);

	for (AMB_i; AMB_i <= angle; AMB_i++)
	{
		xAMBcircle2 = xrad * cos(AMB_i * OVNtheta);
		yAMBcircle2 = yrad * sin(AMB_i * OVNtheta);

		if (Alpha <= 0.9f)
		{
			glColor4f(Red, Green, Blue, Alpha);
			glVertex3f(xAMBcircle2 + xPos, yAMBcircle2 + yPos, 0.0f);
		}
		else
		{
			glColor3f(Red, Green, Blue);
			glVertex3f(xAMBcircle2 + xPos, yAMBcircle2 + yPos, 0.0f);
		}
	}

	glEnd();

}

void mother(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_mother);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);			//Right Bottom
	glVertex3f(1.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);			//Left Bottom
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);			//Left top
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);			//Right top face
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

void scene1(void)
{
	//fog code
	//Fog state enable
	GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, GL_EXP);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.01f);
	glHint(GL_FOG_HINT, GL_NICEST);
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 10.0f);

	glPushMatrix();

		gluQuadricTexture(quadric, GL_TRUE);

		//bind texture
		glBindTexture(GL_TEXTURE_2D, texture_sky);
		glRotatef(-636, 1.0, 0.0, 0.0);
		glColor3f(0.5f, 0.5f, 0.5f);
		gluSphere(quadric, 50.0f, 50, 50);//glusphere call internally creates all normals for you
		
		//unbind the texture
		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

	glPushMatrix();
		glRotatef(-90, 1.0, 1.0, 0.0);
	

		//1
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(-2.0f, 0.0f, -3.0f);
			Tree_unit();
		glPopMatrix();

		//2
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(7.8f, 0.0f, -3.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			Tree_unit();
		glPopMatrix();

		//3
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(-11.5f, 0.0f, -15.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			Tree_unit();
		glPopMatrix();

		//4
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(17.5f, 0.0f, -18.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			Tree_unit();
		glPopMatrix();

		//5
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(-6.5f, 0.0f, -20.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			Tree_unit();
		glPopMatrix();

		//6
		glPushMatrix();
			glRotatef(90, 1.0, 1.0, 0.0);
			glTranslatef(24.0f, 0.0f, -22.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			Tree_unit();
		glPopMatrix();

		//7
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		glTranslatef(12.0f, 0.0f, 18.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPopMatrix();

		//8
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		glTranslatef(-10.0f, 0.0f, 20.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPopMatrix();

		//9
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		glTranslatef(20.0f, 0.0f, 18.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPopMatrix();


		//10
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		glTranslatef(-5.0f, 0.0f, 10.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPopMatrix();

		//11
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		glTranslatef(10.0f, 0.0f, 8.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPopMatrix();

		//12
		glPushMatrix();
		glRotatef(90, 1.0, 1.0, 0.0);
		//glTranslatef(sx,sy,sz);
		glTranslatef(10.0f, 0.0f, 8.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		Tree_unit();
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(-15.0,0.0,15.0);
		Tree_unit();
		glPopMatrix();
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(10.0,0.0,15.0);
		Tree_unit();
		glPopMatrix();
		glPopMatrix();

		

		glPopMatrix();
		



	glPushMatrix();
		glTranslatef(0.0, 2.5f, -3.0f);
		glScalef(2.0f,2.5f, 1.0f);
		//glRotatef(90,1.0,1.0,0.0);
		glColor3f(1.0, 1.0, 1.0);
		House();
	glPopMatrix();

	glPushMatrix();

		glBindTexture(GL_TEXTURE_2D, texture_grass);
		glBegin(GL_QUADS);

		glColor3f(1.0, 1.0, 1.0);

		//bottom fase
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(50.0f, -1.0f, -50.0f);

		glTexCoord2f(15.0f, 0.0f);
		glVertex3f(-50.0f, -1.0f, -50.0f);

		glTexCoord2f(15.0f, 15.0f);
		glVertex3f(-50.0f, -1.0f, 50.0f);

		glTexCoord2f(0.0f, 15.0f);
		glVertex3f(50.0f, -1.0f, 50.0f);

		glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();


	//boy
	glPushMatrix();
		//glRotatef(angle, 0.0, 1.0, 0.0);
		//glTranslatef(0.0f, 0.29f, 2.0f);
		glTranslatef(0.0f, -0.2f, translateboyZ);
		glScalef(0.3, 0.3, 0.5);
		glRotatef(s1Rotate, 0.0, 1.0, 0.0);
		boy1_standing(1.0,0.0,0.0);
	glPopMatrix();

	////mother
	////veni
	//glPushMatrix();
	//glTranslatef(0.0, 1.0, 0.0);
	//glColor3f(1.0, 1.0, 1.0);
	//gluSphere(quadric, 0.4, 15, 15);
	//glTranslatef(0.0, -0.4, 0.0);
	//gluSphere(quadric, 0.3, 15, 15);
	//glTranslatef(0.0, -0.35, 0.0);
	//gluSphere(quadric, 0.25, 15, 15);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(0.0f, 1.0f, -5.0f);
	////glRotatef(90, 1.0f, 0.0f, 0.0f);
	////Cube();
	//glPopMatrix();

	

	//glPushMatrix();
	//glTranslated(0.0f,-1.0f,-5.0f);
	//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	////House();

	//glPopMatrix();

	glPushMatrix();
		glTranslated(4.5f, 0.0f, 0.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		well();
	glPopMatrix();

	//glPushMatrix();
	//glColor3f(1.0f,1.0f,1.0f);
	////mother();
	//glPopMatrix();

	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslated(0.0, 0.0, 5.0);
		ground();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f, -0.2f, -1.0f);
		glColor3f(1.0f, 1.0f, 1.0f);
		mother();
	glPopMatrix();
	

}
