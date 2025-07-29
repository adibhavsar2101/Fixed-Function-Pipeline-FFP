#pragma once

float tactortranslatex = -5.0f;
float tyretranslatex = 10.0f;

float Arotate = 0.0;

void Tractor(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_tractor);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);			//Right Bottom
	glVertex3f(1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);			//Left Bottom
	glVertex3f(-1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);			//Left top
	glVertex3f(-1.5f, -1.2f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);			//Right top face
	glVertex3f(1.5f, -1.2f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

void Tyre(void)
{

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_Tyre);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);			//Right Bottom
	glVertex3f(1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);			//Left Bottom
	glVertex3f(-1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);			//Left top
	glVertex3f(-1.5f, -1.2f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);			//Right top face
	glVertex3f(1.5f, -1.2f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

void Varul(void)
{
	glBindTexture(GL_TEXTURE_2D, texture_Varul);

	glBegin(GL_TRIANGLES);

	//front fase
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);//left
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);//right


	//right fase
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);//left
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);//right

	//back fase
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);//left
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);//right

	//left fase
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);//left
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);//right

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Ant(void)
{

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_Ant);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);			//Right Bottom
	glVertex3f(1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);			//Left Bottom
	glVertex3f(-1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);			//Left top
	glVertex3f(-1.5f, -1.2f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);			//Right top face
	glVertex3f(1.5f, -1.2f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

void Airoplane(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_Airplane);

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f);			//Right Bottom
	glVertex3f(1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);			//Left Bottom
	glVertex3f(-1.5f, 1.2f, 0.0f);
	glTexCoord2f(0.0f, 1.0f);			//Left top
	glVertex3f(-1.5f, -1.2f, 0.0f);
	glTexCoord2f(1.0f, 1.0f);			//Right top face
	glVertex3f(1.5f, -1.2f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}


void scene3(void)
{
	//fog code
	//Fog state enable
	GLfloat fogColor[4] = { 0.5, 0.5, 0.5, 1.0 };
	glEnable(GL_FOG);

	glFogi(GL_FOG_MODE, GL_EXP);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.005f);
	glHint(GL_FOG_HINT, GL_NICEST);
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 10.0f);
	
	//code
	glPushMatrix();
	//glRotatef(90, 1, 0, 0);
	//glRotatef(90, 1.0, 0.0, 0.0);
	gluQuadricTexture(quadric, GL_TRUE);

	//bind texture
	glBindTexture(GL_TEXTURE_2D, texture_terrain);

	//glTranslatef(0.0f, 0.0f, -8.0f);
	//glRotatef(-(-1167), 1.0, 0.0, 0.0);
	//glRotatef(173.0, 1.0, 0.0, 0.0);
	glRotatef(60, 1.0, 0.0, 0.0);
	//glRotatef(0, 0.0, 1.0, 0.0);
	//glRotatef(-465, 0.0, 0.0, 1.0);


	glColor3f(1.0, 1.0, 1.0);
	//glColor3f(0.5f,0.5f,0.5f);
	gluSphere(quadric, 70.0f, 50,50);//glusphere call internally creates all normals for you

	//unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();


	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture_Soil);
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

	glPushMatrix();

		//1
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.5,5.0,1.0);
		glTranslatef(10.0f,0.8f,-20.0f);
		Tree_unit();
		glPopMatrix();

		//2
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 5.0, 1.0);
		glTranslatef(-9.0, 0.8f,-13.0);
		Tree_unit();
		glPopMatrix();

		//3
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 5.0, 1.0);
		glTranslatef(-5.0f, 0.8f, -30.0f);
		Tree_unit();
		glPopMatrix();

		//4
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 5.0, 1.0);
		//glTranslatef(sx, sy, sz);
		glTranslatef(9.0f, 0.8f, -58.0f);
		Tree_unit();
		glPopMatrix();

		//5
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 5.0, 1.0);
		glTranslatef(-2.0f, 0.8f, -57.0f);
		Tree_unit();
		glPopMatrix();

		//6
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glScalef(4.0, 5.0, 1.0);
		//glTranslatef(sx, sy, sz);
		glTranslatef(15.0f, 0.8f, -30.0f);
		Tree_unit();
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(tactortranslatex,0.0,-30.0);
	//glTranslatef(0.0,0.0,-20.0f);
		glPushMatrix();
		glScalef(4.0,4.0,1.0);
		glTranslatef(0.0,0.8,0.0);
		glColor3f(1.0, 1.0, 1.0);
		Tractor();
		glPushMatrix();
			//glTranslatef(-1.4, 6.15, -4.0);
			glTranslatef(-0.5,1.0,-1.5);
			glScalef(0.5, 0.5, 1.0);
			glRotatef(-90, 0.0, 1.0, 0.0);
			boy1();
		glPopMatrix();
		glPopMatrix();

	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(tyretranslatex,0.0f,-12.0f);
	//glTranslatef(10.0,0.0,-12.0);
		glPushMatrix();
		glTranslatef(0.0,0.0,-4.0);
		glScalef(0.8,0.8,1.0);
		Tyre();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.9,1.9,-4.0);
		glRotatef(90,0.0,1.0,0.0);
		glScalef(1.0,1.0,1.0);
		boy1_standing(1.0, 1.0f, 0.0f);
		glPopMatrix();
	glPopMatrix();


	glPushMatrix();
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0,-0.4,-2.0);
		glScalef(2.0,3.0,1.0);
		Varul();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0.0, 1.0, -1.0);
		glScalef(0.8,0.6,1.0);
		Ant();
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	//glTranslatef(sx,sy,sz);
	glTranslatef(0.0,15.0,0.0);
	glRotatef(Arotate, 0.0, 1.0, 0.0);
	glTranslatef(0.0f, 7.0f, 21.0f);
	Airoplane();
	glPopMatrix();


	//Airoplane animation
	if (Arotate <= 360.0f)
	{
		Arotate = Arotate + 0.5;
	}
	else
	{
		Arotate = Arotate - 360.0f;
	}

}
