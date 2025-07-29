#pragma once

void Astromedicomp(void)
{
	glEnable(GL_BLEND);
	

	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_astromedicomp);

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

void Groupname(void)
{
	glEnable(GL_BLEND);


	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_groupname);

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

void Naal(void)
{
	glEnable(GL_BLEND);


	glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D, texture_naal);

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


void Intro(void)
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -8.0f);
	glScalef(2.0, 2.0, 1.0);
	Astromedicomp();
	glPopMatrix();
}

void group(void)
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -8.0f);
	glScalef(2.0, 2.0, 1.0);
	Groupname();
	glPopMatrix();
}

void demoname(void)
{
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -8.0f);
	glScalef(2.0, 2.0, 1.0);
	Naal();
	glPopMatrix();
}
