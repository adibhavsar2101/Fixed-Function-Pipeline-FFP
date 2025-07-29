// Windows common header files
#pragma once
#include <windows.h>
#include <stdio.h>	// For File IO
#include <stdlib.h>	// For exit()
#include <math.h>
#include "OGL.h"  // For Icon

// OpenGL Header files
#include<gl/GL.h>
#include<gl/glu.h>


// Hand movement variables
GLfloat leftHandMove = 0.0f;
GLfloat rightHandMove = 0.0f;

// Legs movement variables
GLfloat leftLegMove = 0.0f;
GLfloat rightLegMove = 0.0f;

// Movement flag
GLuint forwardMovement = TRUE;
GLuint backwardMovement = FALSE;



//MACROS

//#define PI 3.142156855

//Link with OpenGL library
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

extern GLUquadric* quadric;


void boy_Head(void)
{
	void quad3D(void);
	//Draw the Head
	
	glPushMatrix();
		// Main head
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glColor3f(0.97f, 0.85f, 0.54f);
		glScalef(1.1f, 1.1f, 1.0f);
		gluSphere(quadric, 0.25f, 30, 30);

		glPushMatrix();
		glTranslatef(0.1f, -0.02f, -0.22f);
		glScalef(0.5f, 0.2f, 0.2f);
		glColor3f(1.0f, 1.0f, 1.0f);
		gluSphere(quadric, 0.1f, 20.0f, 20.f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.1f, -0.02f, -0.23f);
		glScalef(0.2f, 0.2f, 0.2f);
		glColor3f(0.0f, 0.0f, 0.0f);
		gluSphere(quadric, 0.1f, 20.0f, 20.f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.1f, -0.02f, -0.22f);
		glScalef(0.5f, 0.2f, 0.2f);
		glColor3f(1.0f, 1.0f, 1.0f);
		gluSphere(quadric, 0.1f, 20.0f, 20.f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.12f, -0.02f, -0.23f);
		glScalef(0.2f, 0.2f, 0.2f);
		glColor3f(0.0f, 0.0f, 0.0f);
		gluSphere(quadric, 0.1f, 20.0f, 20.f);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -0.04f, -0.21f);
		glScalef(0.028f, 0.028f, 0.028f);
		//glScalef(0.07, 0.09, 0.07);

		glBegin(GL_TRIANGLES);

		//front face
		glColor3f(0.97f, 0.90f, 0.54f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glEnd();

		//Right Face
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glEnd();

		//Back Face
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glEnd();

		//left face
		glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glEnd();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0f, -0.13f, -0.21f);
		glScalef(0.5f, 0.2f, 0.2f);
		glColor3f(1.0f, 1.0f, 1.0f);
		gluSphere(quadric, 0.1f, 20.0f, 20.f);
		glPopMatrix();
		
		// Hairs
		glPushMatrix();
		glTranslatef(0.0f, 0.017f, 0.04f);
		glColor3f(0.09f, 0.08f, 0.09f);
		gluSphere(quadric, 0.25f, 30, 30);

		glTranslatef(-0.0f, 0.02f, -0.03f);
		gluSphere(quadric, 0.25f, 10, 10);

		
		glPopMatrix();

		// Neck
		glColor3f(0.97f, 0.85f, 0.54f);
		glTranslatef(0.0f, -0.2f, 0.0f);
		glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
		gluCylinder(quadric, 0.1f, 0.1f, 0.1f, 8, 6);

	glPopMatrix();

}

void quad3D(void)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);	// Red
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	//Right Face
	//glColor3f(0.0f, 1.0f, 0.0f);	// Green
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	//Back Face
	//glColor3f(0.0f, 0.0f, 1.0f);	// Blue
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	//Left Side 
	//glColor3f(0.0f, 1.0f, 1.0f);	// Cyan
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	//Top Side
	//glColor3f(1.0f, 0.0f, 1.0f);	// Magenta
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//Bottom Side
	//glColor3f(1.0f, 1.0f, 0.0f);	// Yello
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
	glPopMatrix();
}

void boy_cheast(float r, float g, float b)
{
	// Cheast quad
	glPushMatrix();
	//glColor3f(0.3, 0.01, 0.01);
	glColor3f(r,g,b);
	glTranslatef(0.0f, -0.76f, 0.0f);
	glScalef(0.30f, 0.41f, 0.16f);

	quad3D();
	
	glPopMatrix();

}

void right_Hand_bend(float r, float g, float b)
{
	glPushMatrix();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r, g, b);
	glScalef(1.0f, 1.2f, 1.0f);
	glTranslatef(-0.35f, -0.45f, 0.0f);
	gluSphere(quadric, 0.17f, 30, 30);

	// Arm
	//glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(-0.05f, 0.0f, 0.0f);
	glRotatef(-10.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.12f, 0.1f, 0.5f, 8, 6);

	// fore Arm
	glRotatef(85.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.40f, 0.10f);
	gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 8, 6);

	// Hand 
	glTranslatef(0.0f, 0.0f, 0.48f);
	glColor3f(0.97f, 0.85f, 0.54f);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();
}


void left_Hand_bend(float r, float g, float b)
{
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(r,g,b);
	glScalef(1.0f, 1.2f, 1.0f);
	glTranslatef(0.35f, -0.45f, 0.0f);
	gluSphere(quadric, 0.17f, 30, 30);
	//Arm
	//glColor3f(0.18, 0.34, 0.69);
	glTranslatef(0.05f, 0.0f, 0.0f);
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.12f, 0.1f, 0.5f, 8, 6);

	// fore Arm
	glRotatef(85.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.40f, 0.10f);
	gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 8, 6);

	// Hand 
	glTranslatef(0.0f, 0.0f, 0.48f);
	glColor3f(0.97f, 0.85f, 0.54f);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();

}

void boy_base(float r, float g, float b)
{
	glPushMatrix();
	glColor3f(0.01, 0.07, 0.13);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glTranslatef(-0.05f, -1.32f, -0.30f);
		glScalef(1.0f, 1.3f,1.0f);
		gluCylinder(quadric, 0.155f, 0.155f, 0.60f, 12, 6);

	glPopMatrix();
}

void boy_LeftLeg(float r, float g, float b)
{

	//First leg
	glPushMatrix();

	glColor3f(r,g,b);
	glTranslatef(0.19f, -1.33f, -0.28f);
	glScalef(0.13f, 0.13f, 0.42f);
	quad3D();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.131f, 0.4f, 0.131f);
	glTranslatef(1.4f,-4.3f, -4.3f);
	//glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	quad3D();
	glPopMatrix();

	// Shoes
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.09, 0.09, 0.09);
	glTranslatef(-0.18f, -2.1f, -0.67f);
	glScalef(1.0f, 1.0f, 1.7f);
	gluSphere(quadric, 0.15f, 30, 30);

	glTranslatef(0.37f,0.0f, 0.0f);
	gluSphere(quadric, 0.15f, 30, 30);
	glPopMatrix();

	

	// Other Leg
	glPushMatrix();
	glTranslatef(-0.35f, 0.0f, 0.0f);
	glColor3f(r, g, b);
	glPushMatrix();

	glTranslatef(0.19f, -1.33f, -0.28f);
	glScalef(0.13f, 0.13f, 0.42f);
	quad3D();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.131f, 0.4f, 0.131f);
	glTranslatef(1.4f, -4.3f, -4.3f);
	//glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	quad3D();
	glPopMatrix();

	glPopMatrix();
}



void boy1(void)
{
	// Head
	boy_Head();

	//Cheast
	boy_cheast(0.04, 0.42, 0.15);


	// Right hand
	right_Hand_bend(0.18, 0.34, 0.69);

	//Left hand
	left_Hand_bend(0.18, 0.34, 0.69);

	//Basement
	boy_base(0.82, 0.80, 0.38);

	//Left Leg
	boy_LeftLeg(0.82, 0.80, 0.38);

}


void standing_Right_hands(float r, float g, float b)
{
	glPushMatrix();
	//Shoulder
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glColor3f(0.3, 0.01, 0.01);
	glColor3f(r,g,b);
	glScalef(1.0f, 1.2f, 1.0f);
	glTranslatef(-0.35f, -0.45f, 0.0f);
	gluSphere(quadric, 0.17f, 30, 30);

	// Arm Biceps
	glTranslatef(-0.05f, 0.0f, 0.0f);
	glRotatef(-10.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.12f, 0.1f, 0.4f, 8, 6);

	// fore Arm
	glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.065f, 0.30f);
	gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 8, 6);

	// Hand 
	glTranslatef(0.0f, 0.0f, 0.48f);
	glColor3f(0.97f, 0.85f, 0.54f);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();
}

standing_Left_hands(float r, float g, float b)
{
	glPushMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//glColor3f(0.3, 0.01, 0.01);
	glColor3f(r,g,b);
	glScalef(1.0f, 1.2f, 1.0f);
	glTranslatef(0.35f, -0.45f, 0.0f);
	gluSphere(quadric, 0.17f, 30, 30);

	//Arm
	glTranslatef(0.05f, 0.0f, 0.0f);
	glRotatef(10.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(80.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.12f, 0.1f, 0.4f, 8, 6);

	// fore Arm
	glRotatef(10.0f, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.07f, 0.35f);
	gluCylinder(quadric, 0.1f, 0.1f, 0.4f, 8, 6);

	// Hand 
	glTranslatef(0.0f, 0.0f, 0.48f);
	glColor3f(0.97f, 0.85f, 0.54f);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();
}

void rightLeg(void)
{

	glColor3f(0.01, 0.07, 0.13);
	glPushMatrix();
	gluCylinder(quadric, 0.18f, 0.10f, 1.3f, 8, 6);
	
	
	//RIght Shoe
	glTranslatef(0.0f, -0.08f, 1.35f);
	glColor3f(0.5f, 0.5f, 0.54f);
	glScalef(1.0, 1.8, 1.0);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();


}


void leftLeg(void)
{
	glColor3f(0.01, 0.07, 0.13);

	glPushMatrix();
	gluCylinder(quadric, 0.18f, 0.1f, 1.3f, 8, 6);


	//Left Shoe
	glColor3f(0.5f, 0.5f, 0.54f);
	glTranslatef(0.31f, 0.0f, 0.0f);
	glTranslatef(-0.32f, -0.08f, 1.35f);
	glScalef(1.0, 1.8, 1.0);
	gluSphere(quadric, 0.11f, 30, 30);

	glPopMatrix();

}


void Standing_Legs(void)
{

	
	glPushMatrix();
	
	glTranslatef(0.15f, -1.2f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

	

		//Right Leg
		glPushMatrix();
		glRotatef(rightLegMove, 1.0f, 0.0f, 0.0f);
		rightLeg();
		glPopMatrix();

		//Left Leg
		glTranslatef(-0.3f, 0.0f, 0.0f);

		glPushMatrix();
		glRotatef(leftLegMove, 1.0f, 0.0f, 0.0f);
		leftLeg();
		glPopMatrix();
		

	glPopMatrix();
}

void update_human(void)
{
	
	// Left Hand
	if (forwardMovement == TRUE)
	{
		leftHandMove = leftHandMove + 0.1f;
		if (leftHandMove >= 8.0f)
		{
			forwardMovement = FALSE;
			backwardMovement = TRUE;
		}
	}

	if (backwardMovement == TRUE)
	{
		leftHandMove = leftHandMove - 0.1f;
		if (leftHandMove <= -10.0f)
		{
			forwardMovement = TRUE;
			backwardMovement = FALSE;
		}
	}
	

	// Right Hand
	if (forwardMovement == TRUE)
	{
		rightHandMove = rightHandMove - 0.1f;
		if (rightHandMove <= -10.0f)
		{
			forwardMovement = FALSE;
			backwardMovement = TRUE;
		}
	}

	if (backwardMovement == TRUE)
	{
		rightHandMove = rightHandMove + 0.1f;
		if (rightHandMove >= 8.0f)
		{
			forwardMovement = TRUE;
			backwardMovement = FALSE;
		}
	}



	// Left Leg Movement

	if (forwardMovement == TRUE)
	{
		leftLegMove = leftLegMove + 0.2f;
		if (leftLegMove >= 50.0f)
		{
			forwardMovement = FALSE;
			backwardMovement = TRUE;
		}
	}

	if (backwardMovement == TRUE)
	{
		leftLegMove = leftLegMove - 0.2f;
		if (leftLegMove <= -50.0f)
		{
			forwardMovement = TRUE;
			backwardMovement = FALSE;
		}
	}

	/*leftLegMove = leftLegMove + 0.01f;
	if (leftLegMove >= 10.0f)
	{
		leftLegMove = -4.0f;
	}*/


	// Right Leg
	if (forwardMovement == TRUE)
	{
		rightLegMove = rightLegMove - 0.2f;
		if (rightLegMove <= -50.0f)
		{
			forwardMovement = FALSE;
			backwardMovement = TRUE;
		}
	}

	if (backwardMovement == TRUE)
	{
		rightLegMove = rightLegMove + 0.2f;
		if (rightLegMove >= 50.0f)
		{
			forwardMovement = TRUE;
			backwardMovement = FALSE;
		}
	}


	/*rightLegMove = rightLegMove - 0.01f;
	if (rightLegMove <= -10.0f)
	{
		rightLegMove = 4.0f;
	}*/

}

void boy1_standing(float r, float g, float b)
{
	glPushMatrix();

	// Head
	boy_Head();

	//Cheast
	//boy_cheast(0.04, 0.16, 0.42);
	boy_cheast(r,g,b);

	// Right hand
	glPushMatrix();
	glRotated(rightHandMove, 1.0f, 0.0f, 0.0f);
	//standing_Right_hands(0.18, 0.34, 0.69);
	standing_Right_hands(r, g, b);
	glPopMatrix();

	//Left hand
	glPushMatrix();
	glRotated(leftHandMove, 1.0f, 0.0f, 0.0f);
	//standing_Left_hands(0.18, 0.34, 0.69);
	standing_Left_hands(r,g,b);
	glPopMatrix();


	//Basement
	boy_base(0.82, 0.80, 0.38);

	// Legs
	Standing_Legs();

	glPopMatrix();

	update_human();
}