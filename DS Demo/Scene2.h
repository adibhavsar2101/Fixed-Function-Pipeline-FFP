#pragma once

#include <gl/GL.h> 

#include<gl/GLU.h>


#include"Humanoid.h"

//extern GLuint texture_sky;
//extern GLuint texture_grass;
//extern GLuint texture_tree;
//extern GLuint texture_Ground;
//extern GLuint texture_Cort;
//GLuint texture_bricks;
//GLuint texture_Roof;
//GLuint texture_Door;
//GLuint texture_Window;
//GLuint texture_ball;

//extern GLfloat angle;

void Ball(void)
{
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture_Football);
	gluQuadricTexture(quadric, GL_TRUE);
	gluSphere(quadric, 0.5f, 70, 70);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

void FootballCort(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_Cort);

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

void Honey(void)
{
	glPushMatrix();
	glRotatef(90, 1.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture_honey);
	gluQuadricTexture(quadric, GL_TRUE);
	gluSphere(quadric, 0.5f, 70, 70);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

}

void Swing(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_Swing);

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


void scene2(void)
{
	//code
	glPushMatrix();
	//glRotatef(90, 1, 0, 0);
	//glRotatef(90, 1.0, 0.0, 0.0);
	gluQuadricTexture(quadric, GL_TRUE);

	//bind texture
	glBindTexture(GL_TEXTURE_2D, texture_blackSky);

	//glTranslatef(0.0f, 0.0f, -8.0f);
	//glRotatef(-(-1167), 1.0, 0.0, 0.0);
	glRotatef(-98.0, 1.0, 0.0, 0.0);
	//glRotatef(0, 0.0, 1.0, 0.0);
	glRotatef(-465, 0.0, 0.0, 1.0);

	


	glColor3f(0.5f, 0.5f, 0.5f);
	gluSphere(quadric, 50.0f, 100, 100);//glusphere call internally creates all normals for you

	//unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

	glPushMatrix();
	/*glRotatef(90, 1.0, 1.0, 0.0);
	Tree_unit();*/
	glPopMatrix();



	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture_Ground);
	glBegin(GL_QUADS);

	glColor3f(1.0, 1.0, 1.0);

	//bottom fase
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(100.0f, -1.0f, -100.0f);

	glTexCoord2f(15.0f, 0.0f);
	glVertex3f(-100.0f, -1.0f, -100.0f);

	glTexCoord2f(15.0f, 15.0f);
	glVertex3f(-100.0f, -1.0f, 100.0f);

	glTexCoord2f(0.0f, 15.0f);
	glVertex3f(100.0f, -1.0f, 100.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

	
	//********************************************************************************************************************

	//boy1
	glPushMatrix();
	glTranslatef(-4.0f,2.0f,14.0f);
	boy1_standing(1.0,1.0f,0.0f);
	glPopMatrix();

	//boy 2
	glPushMatrix();
	glTranslatef(4.0f, 2.0f, 14.0f);
	boy1_standing(1.0f,1.0f,0.0f);
	glPopMatrix();

	//boy3
	glPushMatrix();
	glTranslatef(-4.0f, 2.0f, -14.0f);
	glRotatef(180, 0.0, 1.0, 0.0);
	boy1_standing(0.0, 1.0f, 1.0f);
	glPopMatrix();

	//boy 4
	glPushMatrix();
	glTranslatef(4.0f, 2.0f, -14.0f);
	glRotatef(180, 0.0, 1.0, 0.0);
	boy1_standing(0.0f, 1.0f, 1.0f);
	glPopMatrix();

	//boy 5
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, -5.0f);
	glRotatef(180, 0.0, 1.0, 0.0);
	boy1_standing(0.0f, 1.0f, 1.0f);
	glPopMatrix();

	//golkipper 1
	glPushMatrix();
	glTranslatef(0.0, 2.0, 18.0);
	boy1_standing(1.0f,1.0f,1.0f);
	glPopMatrix();

	//golkipper 2
	glPushMatrix();
	glTranslatef(0.0f, 2.0f, -18.0f);
	glRotatef(180, 0.0, 1.0, 0.0);
	boy1_standing(1.0f, 0.0f, 1.0f);
	glPopMatrix();


	//*********************************************************************************************************************
	
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0, 1.0, 20.0);
	glScalef(3.0, 3.0, 1.0);
	FootballCort();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(0.0, 1.0, -20.0);
	glScalef(3.0, 3.0, 1.0);
	//glRotatef(180, 0.0, 1.0, 0.0);
	FootballCort();
	glPopMatrix();

	//tree
	glPushMatrix();
	glTranslatef(-9.0f, 3.6f, -25.0f);
	glScalef(4.0, 5.0, 1.0);
	Tree_unit();
	//honey tree
		glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glScalef(0.2, 0.35, 2.0);
			glTranslatef(-14.0,1.8,0.2);
			Honey();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	Ball();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.0,3.0,-25.0);
	glScalef(8.0,8.0,0.0);
	Swing();
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(sx,sy,sz);
	glTranslatef(20.0f,1.0f,-25.0f);
	glRotatef(180, 0.0, 1.0, 0.0);
	boy1();
	glPopMatrix();

	//1
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	//glTranslatef(sx,sy,sz);
	glTranslatef(-4.0f, 3.6f, -41.0f);
	glScalef(4.0, 5.0, 1.0);
	Tree_unit();
	glPopMatrix();

	//2
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	//glTranslatef(sx,sy,sz);
	glTranslatef(-14.0f,3.6f,-7.0f);
	glScalef(4.0, 5.0, 1.0);
	Tree_unit();
	glPopMatrix();

	//3
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	//glTranslatef(sx,sy,sz);
	glTranslatef(40.0f,3.6f,0.0f);
	glScalef(4.0, 5.0, 1.0);
	Tree_unit();
	glPopMatrix();

}