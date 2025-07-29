#pragma once

void Credits(void)
{
	glEnable(GL_BLEND);


	//glDepthMask(GL_FALSE);

	glBindTexture(GL_TEXTURE_2D,texture_Outro);

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

	/*glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);*/
}

void Outro(void)
{
	glPushMatrix();
	glTranslatef(0.0, 0.0, -8.0);
	glScalef(2.0, 2.0, 1.0);
	Credits();
	glPopMatrix();
}