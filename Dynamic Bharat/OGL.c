
// standard Header Files
#include<windows.h>
#include<stdio.h> 
#include<stdlib.h> // for exit() 

#include"plane.h"

//OpenGl Header file
#include<gl/GL.h>
#include<gl/GLU.h>
#include<mmsystem.h>
#include"OGL.h"

#define M_PI 3.14

// Micros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define SPEED 0.001f
#define SPEED_CURVE 0.02f
#define LETTER_SPEED 0.001f
#define WORD_DEPTH -3.0f

//Link With OpenGl Libraray 
#pragma comment(lib,"OpenGl32.lib")
#pragma comment(lib,"glu32.lib")


// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable declarations
HWND ghwnd = NULL;
DWORD dwStyle = 0;

WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbfullscreen = FALSE;

FILE* gpFile = NULL;
BOOL gbActive = FALSE;

//OpenGl related global variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

//letter translation variable
float btranslatex = -3.5f;
float htranslatex = -3.5f;
float a1translatex = -4.5f;
float a1translatey = -4.5f;
float rtranslatex = 3.5f;
float rtranslatey = 3.5f;
float a2translatex = 4.5f;
float a2translatey = -4.5f;
float ttranslatex = 3.5f;

float cPlanetranslatex = -3.0f;

int Bflag = 1;
int Hflag = 0;
int A1flag = 0;
int Rflag = 0;
int A2flag = 0;
int Tflag = 0;

int planeflag = 0;

float a1, b1, a2, b2, p1, q1, p2, q2;
float angle = 180.0f;
float angle1 = 180.0f;
float radian = 0.0f;
float pAngle1 = 270.0f;
float pAngle3 = 90.0f;
double radius = 2.25f;
int rotateFlagPlane1 = 0;
int rotateFlagPlane3 = 0;
float xPlane1 = 0.0f, xPlane3 = 0.0f;
float yPlane1 = 0.0f, yPlane3 = 0.0f;
int cpCount = 0;

// Entry point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Function Declarations 
	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	// local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("AMBWindow");
	int iResult = 0;  // for base code
	BOOL bDone = FALSE;

	
	int SW = 0;   // Screen width
	int SH = 0;   // Screen Height

	int x = 0;
	int y = 0;

	// Code
	gpFile = fopen("log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File cannot be opend..."), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}

	fprintf(gpFile, "Program Started Successfully... \n\n");

	// WNDCLASSEX initialization  
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	// Register WNDCLASSEX 
	RegisterClassEx(&wndclass);

	// Centering of window code
	SW = GetSystemMetrics(SM_CXSCREEN);
	SH = GetSystemMetrics(SM_CYSCREEN);

	x = (SW / 2) - (WIN_WIDTH / 2);
	y = (SH / 2) - (WIN_HEIGHT / 2);


	// Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("Aditya Madhukar Bhavsar : DynamicBharat "),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		x,
		y,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);
 
	ghwnd = hwnd;

	//initialization
	iResult = initialize();

	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize() Failed..."), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
		exit(0);
	}

	// Show the Window
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// Game Loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				bDone = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE) 
			{
				// Render

				display();

				// Update

				update();

			}
		}
	}

	// uninitialization
	uninitialize();

	return((int)msg.wParam);
}

// CALLBACK function
LRESULT CALLBACK WndProc(HWND   hwnd, UINT   iMsg, WPARAM wParam, LPARAM lParam)
{
	// Function declarations
	void ToggleFullscreen(void);
	void resize(int, int);


	// Code

	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_ERASEBKGND:
		return(0);

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		}
		break;

	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
		case 'f':
			if (gbfullscreen == FALSE)
			{
				ToggleFullscreen();
				gbfullscreen = TRUE;
			}
			else
			{
				ToggleFullscreen();
				gbfullscreen = FALSE;
			}
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullscreen(void)
{
	// Local Variable Declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	// Code
	if (gbfullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);                             
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	void resize(int, int);

	// Function Declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	//initialization pixel format discriptor
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	//Get the dc
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile,"GetDC() failed\n");
		return -1;
	}

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile,"choose pixel format() failed\n");
		return -2;
	}

	//set octel pixel format
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() failed\n");
		return -3;
	}

	//Create OpenGl context from device context
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() failed\n");
		return -4;
	}

	//make rendering context current
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglmakeCurrent() failed\n");
		return -5;
	}

	//Enable in Depth
	glShadeModel(GL_SMOOTH);//Beautification 

	//compulsory
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);//Beautification


	//Set the clear color of window 
	//clear OpenGl() starts
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//code
	resize(WIN_WIDTH, WIN_HEIGHT);

	//PlaySound("DynamicBharatSong.wav", NULL, SND_ASYNC);
	PlaySound("song.wav", NULL,SND_ASYNC);
	
	
	return(0);
}

void resize(int width, int height)
{
	// Code

	if (height <= 0)
		height = 1;


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

}

void display(void)
{
	//function declarations
	void Bharat(void);


	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -3.0f);

	glPushMatrix();
	//glTranslatef(0.0f,0.0f,-3.0f);
	glScalef(3.8, 3.8, 3.8);
	Bharat();
	glPopMatrix();

	
	glPushMatrix();
	//glTranslatef(0.0f,0.5f,0.0f);
	glTranslatef(cPlanetranslatex,0.0f,0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(-90,0.0f,0.0f,1.0f);
	PlaneCenter();
	glPopMatrix();

	glPushMatrix();
	if (rotateFlagPlane1 == 0 && planeflag==1)
	{
		glTranslatef(a1, b1, -5.0f);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);
		xPlane1 = a1;
		yPlane1 = b1;
		PlaneUpper();
	}
	else if (rotateFlagPlane1 == 1)
	{
		glTranslatef(xPlane1, yPlane1, -5.0f);
		glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
		PlaneUpper();
	}
	else if (rotateFlagPlane1 == 2)
	{
		glTranslatef(p1, q1, -5.0f);
		glRotatef(pAngle1, 0.0f, 0.0f, 1.0f);
		PlaneUpper();
	}
	glPopMatrix();

	glPushMatrix();
	if (rotateFlagPlane3 == 0 && planeflag == 1)
	{
		glTranslatef(a2, b2, -5.0f);
		glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(angle1, 0.0f, 0.0f, 1.0f);
		xPlane3 = a2;
		yPlane3 = b2;
		PlaneLower();
	}
	else if (rotateFlagPlane3 == 1)
	{
		glTranslatef(xPlane3, yPlane3, -5.0f);
		glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
		PlaneLower();
	}
	else if (rotateFlagPlane3 == 2)
	{
		glTranslatef(p2, q2, -5.0f);
		glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(pAngle3, 0.0f, 0.0f, 1.0f);
		PlaneLower();
	}
	glPopMatrix();

	
	SwapBuffers(ghdc);


}

void update(void)
{
	// Code

	//Bharat name animation

	btranslatex = btranslatex + LETTER_SPEED;
	if (btranslatex >= 0.0f)
	{
		btranslatex = 0.0f;
		Hflag = 1;
	}


	if (Hflag)
	{
		htranslatex = htranslatex + LETTER_SPEED;
		if (htranslatex >= 0.0f)
		{
			htranslatex = 0.0f;
			A1flag = 1;
		}
	}
	
	
	if (A1flag)
	{
		a1translatex = a1translatex + LETTER_SPEED;
		if (a1translatex >= 0.0f)
		{
			a1translatex = 0.0f;
			
		}

		a1translatey = a1translatey + LETTER_SPEED;
		if (a1translatey >= 0.0f)
		{
			a1translatey = 0.0f;
			Rflag = 1;
		}
	}
	

	if (Rflag)
	{
		rtranslatex = rtranslatex - LETTER_SPEED;
		if (rtranslatex <= 0.0f)
		{
			rtranslatex = 0.0f;
		}

		rtranslatey = rtranslatey - LETTER_SPEED;
		if (rtranslatey <= 0.0f)
		{
			rtranslatey = 0.0f;
			A2flag = 1;
		}

	}
	
	if (A2flag)
	{
		a2translatex = a2translatex - LETTER_SPEED;
		if (a2translatex <= 0.0f)
		{
			a2translatex = 0.0f;
		}

		a2translatey = a2translatey + LETTER_SPEED;
		if (a2translatey >= 0.0f)
		{
			a2translatey = 0.0f;
			Tflag = 1;
		}

	}
	
	if (Tflag)
	{
		ttranslatex = ttranslatex - LETTER_SPEED;
		if (ttranslatex <= 0.0f)
		{
			ttranslatex = 0.0f;
			planeflag = 1;
		}

	}

	//plane animation
	if (planeflag)
	{
		cpCount++;
		if (cpCount >= 500)
		{
			cPlanetranslatex = cPlanetranslatex + 0.0004f;
			if (cPlanetranslatex >= 4.0f)
			{
				cPlanetranslatex = 4.0f;
			}
		}

		//upper plane animation
		if (rotateFlagPlane1 == 0)
		{
			angle = angle + SPEED_CURVE;
			if (angle >= 270.0f)
			{
				angle = 270.0f;
				rotateFlagPlane1 = 1;
			}
		}

		radian = (M_PI / 180) * angle;
		a1 = cos(radian) * radius - 3.7f;
		b1 = sin(radian) * radius + 2.25f;

		if (rotateFlagPlane1 == 1)
		{
			xPlane1 = xPlane1 + SPEED;
			if (xPlane1 >= 3.7f)
				rotateFlagPlane1 = 2;
		}

		if (rotateFlagPlane1 == 2)
		{
			pAngle1 = pAngle1 + SPEED_CURVE;
			if (pAngle1 >= 360.0f)
			{
				pAngle1 = 360.0f;
				rotateFlagPlane1 = -1;
			}
		}

		radian = (M_PI / 180) * pAngle1;
		p1 = cos(radian) * radius + xPlane1;
		q1 = sin(radian) * radius + 2.25f;

		//lower plane animation
		if (rotateFlagPlane3 == 0 && planeflag == 1)
		{
			angle1 = angle1 - SPEED_CURVE;
			if (angle1 <= 90.0f)
			{
				angle1 = 90.0f;
				rotateFlagPlane3 = 1;
			}
		}

		radian = (M_PI / 180) * angle1;
		a2 = cos(radian) * radius - 3.7f;
		b2 = sin(radian) * radius - 2.25f;

		if (rotateFlagPlane3 == 1)
		{
			xPlane3 = xPlane3 + SPEED;
			if (xPlane3 >= 3.7f)
			{
				xPlane3 = 3.7f;
				rotateFlagPlane3 = 2;
			}
		}

		if (rotateFlagPlane3 == 2)
		{
			pAngle3 = pAngle3 - SPEED_CURVE;
			if (pAngle3 <= 0.0f)
			{
				pAngle3 = 0.0f;
				rotateFlagPlane3 = -1;
			}
		}

		radian = (M_PI / 180) * pAngle3;
		p2 = cos(radian) * radius + 3.7f;
		q2 = sin(radian) * radius - 2.25f;
	}
}

void uninitialize(void)
{
	// Function Declarations
	void ToggleFullscreen(void);

	// Code

	// if application is exiting in fullDcreen
	if (gbfullscreen == TRUE)
	{
		ToggleFullscreen();
		gbfullscreen = FALSE;
	}

	//make the hdc at current dc
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//Delete Rendering Context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//relese the hdc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// Close the log file 
	if (gpFile)
	{
		fprintf(gpFile, "Program Ended Successfully...\n");
		fclose(gpFile);
		gpFile = NULL;
	}

}

void Bharat(void)
{
	void B(void);
	void H(void);
	void A1(void);
	void R(void);
	void A2(void);
	void T(void);

	glPushMatrix();
	glTranslatef(btranslatex,0.0f, WORD_DEPTH);
	B();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(htranslatex, -htranslatex, WORD_DEPTH);
	H();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(a1translatex, a1translatey, WORD_DEPTH);
	glScalef(0.85f, 1.0f, 1.0f);
	A1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(rtranslatex, rtranslatey, WORD_DEPTH);
	R();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6f, 0.0f, 0.0f);
	glTranslatef(a2translatex, a2translatey, WORD_DEPTH);
	glScalef(0.85f, 1.0f, 1.0f);
	A2();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(ttranslatex, 0.0f, WORD_DEPTH);
	T();
	glPopMatrix();

}

void B(void)
{
	//top quad
	glColor3f(0.75,0.75,0.75);//orange
	glBegin(GL_QUADS);

	glVertex2f(-0.55f,0.2f);
	glVertex2f(-0.7f, 0.2f);
	//glColor3f(1.0,1.0f,1.0);//white
	glVertex2f(-0.7f,0.0f);
	glVertex2f(-0.55f, 0.0f);

	glEnd();

	//bottom quad
	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glBegin(GL_QUADS);

	glVertex2f(-0.55f, 0.0f);
	glVertex2f(-0.7f, 0.0f);
	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(-0.7f, -0.2f);
	glVertex2f(-0.55f,-0.2f);
	

	glEnd();

	//top hole
	glBegin(GL_QUADS);

	glColor3f(0.0f,0.0f,0.0f);//black

	glVertex2f(-0.55f,0.05);
	glVertex2f(-0.55f,0.15f);
	glVertex2f(-0.65f,0.15f);
	glVertex2f(-0.65f,0.05);

	glEnd();

	//bottom hole
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);//black

	glVertex2f(-0.55f,-0.15f);
	glVertex2f(-0.55f,-0.05f);
	glVertex2f(-0.65f,-0.05f);
	glVertex2f(-0.65f,-0.15f);

	glEnd();


	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);//gray
	glVertex2f(-0.5f, 0.15f);
	glVertex2f(-0.55f, 0.2f);
	glColor3f(0.75,0.75,0.75);//gray
	glVertex2f(-0.55f,0.0f);
	glVertex2f(-0.5f,0.05f);
	

	glEnd();

	glBegin(GL_QUADS);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(-0.5f, -0.05);
	glVertex2f(-0.55f, 0.0f);
	//glColor3f(0.02, 0.50, 0.03);//Green
	glVertex2f(-0.55f,-0.2f);
	glVertex2f(-0.5f,-0.15f);
	
	glEnd();

	//band
	if (cPlanetranslatex >= -0.25f)
	{
		glBegin(GL_QUADS);

		glColor3f(1, 0.4, 0.12);//orange

		glVertex2f(-0.50f,0.05f);
		glVertex2f(-0.70f,0.05);
		glVertex2f(-0.70f, 0.017f);
		glVertex2f(-0.53f,0.017f);
		

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1.0, 1.0, 1.0);//white

		glVertex2f(-0.53f, 0.017f);
		glVertex2f(-0.55f, 0.0f);
		glVertex2f(-0.70f, 0.0f);
		glVertex2f(-0.70f, 0.017);
		
		glEnd();

		glBegin(GL_QUADS);
		
		glColor3f(1.0,1.0,1.0);//white

		glVertex2f(-0.55f, 0.0f);
		glVertex2f(-0.53f, -0.0163f);
		glVertex2f(-0.70f, -0.0163f);
		glVertex2f(-0.70f, 0.0f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(0.02,0.42,0.22);//green

		glVertex2f(-0.50f, -0.05f);
		glVertex2f(-0.53f, -0.0163f);
		glVertex2f(-0.70f, -0.0163f);
		glVertex2f(-0.70f, -0.05f);
		

		glEnd();
	}


}

void H(void)
{
	//left quad upper
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);//orange
	glVertex2f(-0.35f, 0.2f);
	glVertex2f(-0.4f, 0.2f);

	//glColor3f(1.0,1.0f,1.0f);//white
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.35f,0.0f);

	glEnd();

	//left quad lower
	glBegin(GL_QUADS);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(-0.35f, 0.0f);
	glVertex2f(-0.4f, 0.0f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(-0.4f, -0.2f);
	glVertex2f(-0.35f, -0.2f);

	glEnd();

	//right quad upper
	glBegin(GL_QUADS);

	//glColor3f(0.98, 0.51, 0.10);//Orange
	glVertex2f(-0.2f, 0.2f);
	glVertex2f(-0.25f, 0.2f);
	
	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(-0.25f,0.0f);
	glVertex2f(-0.2f, 0.0f);

	glEnd();

	//right quad lower
	glBegin(GL_QUADS);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.25f, 0.0f);
	
	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(-0.25f, -0.2f);
	glVertex2f(-0.2f, -0.2f);
	
	glEnd();

	//advi line
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);

	glVertex2f(-0.25f, -0.05f);
	glVertex2f(-0.25f, 0.05f);
	glVertex2f(-0.35f, 0.05f);
	glVertex2f(-0.35f, -0.05f);

	glEnd();

	if (cPlanetranslatex >= -0.10)
	{

		glBegin(GL_QUADS);

		glColor3f(1, 0.4, 0.12);//orange

		glVertex2f(-0.2f, 0.017f);
		glVertex2f(-0.2f, 0.05f);
		glVertex2f(-0.4f, 0.05f);
		glVertex2f(-0.4f, 0.017f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1.0,1.0,1.0);

		glVertex2f(-0.2f, -0.0163f);
		glVertex2f(-0.2f, 0.017f);
		glVertex2f(-0.4f, 0.017f);
		glVertex2f(-0.4f, -0.0163f);

		glEnd();

		
		glBegin(GL_QUADS);

		glColor3f(0.02,0.42,0.22);//green

		glVertex2f(-0.2f, -0.05f);
		glVertex2f(-0.2f, -0.0163f);
		glVertex2f(-0.4f, -0.0163f);
		glVertex2f(-0.4f, -0.05f);

		glEnd();

	}
}

void A1(void)
{
	//left quad
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);
	glVertex2f(-0.1f,-0.05f);
	glVertex2f(-0.15f,-0.05f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(-0.15f,-0.2f);
	glVertex2f(-0.1f,-0.2f);
	
	glEnd();

	//Right quad
	glBegin(GL_QUADS);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(0.15f,0.05);
	glVertex2f(0.1f,0.05f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(0.1f,-0.2f);
	glVertex2f(0.15f,-0.2f);
	
	glEnd();

	//advi line
	glBegin(GL_QUADS);

	glColor3f(0.75, 0.75, 0.75);

	glVertex2f(0.15f,0.05f);
	glVertex2f(-0.15f,0.05f);
	glVertex2f(-0.15f,-0.05f);
	glVertex2f(0.15f,-0.05f);

	glEnd();

	if (cPlanetranslatex >= 0.10)
	{
		glBegin(GL_QUADS);

		glColor3f(1, 0.4, 0.12);//orange

		glVertex2f(0.15f, 0.05f);
		glVertex2f(-0.15f, 0.05f);
		glVertex2f(-0.15f, 0.017f);
		glVertex2f(0.15f, 0.017f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(0.15f, 0.017f);
		glVertex2f(-0.15f, 0.017f);
		glVertex2f(-0.15f, -0.0163f);
		glVertex2f(0.15f, -0.0163f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(0.02, 0.42, 0.22);//green

		glVertex2f(0.15f, -0.0163f);
		glVertex2f(-0.15f, -0.0163f);
		glVertex2f(-0.15f, -0.05f);
		glVertex2f(0.15f, -0.05f);

		glEnd();
	}

	//top left line
	glBegin(GL_QUADS);

	glColor3f(0.75, 0.75, 0.75);//gray
	glVertex2f(0.025f,0.2f);
	glVertex2f(-0.025,0.2f);
	
	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(-0.15f,0.05f);
	glVertex2f(-0.1f,0.05f);

	glEnd();

	//right top line
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);//gray
	glVertex2f(0.025f,0.2f);
	glVertex2f(-0.025f,0.2f);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(0.1f,0.05f);
	glVertex2f(0.15f,0.05f);

	glEnd();
	
}

void R(void)
{
	//top quad
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);
	glVertex2f(0.35f,0.2f);
	glVertex2f(0.2f, 0.2f);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(0.2f,-0.05f);
	glVertex2f(0.35f, -0.05f);

	glEnd();

	//bottom quad
	glBegin(GL_QUADS);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(0.25f, -0.05f);
	glVertex2f(0.2f, -0.05f);
	

	//glColor3f(0.02f, 0.50f, 0.03f);//green
	glVertex2f(0.2f, -0.2f);
	glVertex2f(0.25f, -0.2f);

	glEnd();

	//top hole
	glBegin(GL_QUADS);

	glColor3f(0.0f, 0.0f, 0.0f);//black

	glVertex2f(0.35f,0.05f);
	glVertex2f(0.35f,0.15f);
	glVertex2f(0.25f,0.15f);
	glVertex2f(0.25f,0.05f);

	glEnd();

	//top right arrow
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);//gray
	glVertex2f(0.4f, 0.15f);
	glVertex2f(0.35f, 0.2f);

	//glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.35f,-0.05f);
	glVertex2f(0.4f,0.0f);
	
	

	glEnd();

	//bottom advi line
	glBegin(GL_QUADS);

	//glColor3f(1.0,1.0,1.0);//white
	glVertex2f(0.3f, -0.05f);
	glVertex2f(0.25f, -0.05f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(0.35f,-0.2f);
	glVertex2f(0.4f, -0.2f);
	glEnd();

	if (cPlanetranslatex >= 0.30)
	{
		glBegin(GL_QUADS);
		glColor3f(1, 0.4, 0.12);//orange

		glVertex2f(0.4f,0.05f);
		glVertex2f(0.4f,0.017f);
		glVertex2f(0.2f,0.017f);
		glVertex2f(0.2f,0.05f);

		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);//white

		glVertex2f(0.4f, 0.017f);
		glVertex2f(0.38f, -0.0163f);
		glVertex2f(0.2f, -0.0163f);
		glVertex2f(0.2f, 0.017f);

		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.02,0.42,0.22);//green

		glVertex2f(0.38f, -0.0163f);
		glVertex2f(0.35f, -0.05f);
		glVertex2f(0.2f, -0.05f);
		glVertex2f(0.2f, -0.0163f);

		glEnd();




	}


}

void A2(void)
{
	//left quad
	glBegin(GL_QUADS);

	glColor3f(0.75, 0.75, 0.75);
	glVertex2f(-0.1f, -0.05f);
	glVertex2f(-0.15f, -0.05f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(-0.15f, -0.2f);
	glVertex2f(-0.1f, -0.2f);

	glEnd();

	//Right quad
	glBegin(GL_QUADS);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(0.15f, 0.05);
	glVertex2f(0.1f, 0.05f);

	//glColor3f(0.02, 0.50, 0.03);//green
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.15f, -0.2f);

	glEnd();

	//advi line
	glBegin(GL_QUADS);

	//glColor3f(1.0f, 1.0f, 1.0f);//white

	glVertex2f(0.15f, 0.05f);
	glVertex2f(-0.15f, 0.05f);
	glVertex2f(-0.15f, -0.05f);
	glVertex2f(0.15f, -0.05f);

	glEnd();

	if (cPlanetranslatex >= 0.57)
	{
		glBegin(GL_QUADS);

		glColor3f(1, 0.4, 0.12);//orange

		glVertex2f(0.15f, 0.05f);
		glVertex2f(-0.15f, 0.05f);
		glVertex2f(-0.15f, 0.017f);
		glVertex2f(0.15f, 0.017f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);

		glVertex2f(0.15f, 0.017f);
		glVertex2f(-0.15f, 0.017f);
		glVertex2f(-0.15f, -0.0163f);
		glVertex2f(0.15f, -0.0163f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(0.02, 0.42, 0.22);//green

		glVertex2f(0.15f, -0.0163f);
		glVertex2f(-0.15f, -0.0163f);
		glVertex2f(-0.15f, -0.05f);
		glVertex2f(0.15f, -0.05f);

		glEnd();
	}

	//top left line
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);//gray
	glVertex2f(0.025f, 0.2f);
	glVertex2f(-0.025, 0.2f);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(-0.15f, 0.05f);
	glVertex2f(-0.1f, 0.05f);

	glEnd();

	//right top line
	glBegin(GL_QUADS);

	glColor3f(0.75, 0.75, 0.75);//gray
	glVertex2f(0.025f, 0.2f);
	glVertex2f(-0.025f, 0.2f);

	//glColor3f(1.0f,1.0f,1.0f);//white
	glVertex2f(0.1f, 0.05f);
	glVertex2f(0.15f, 0.05f);

	glEnd();

}

void T(void)
{
	//top quad
	glBegin(GL_QUADS);

	glColor3f(0.75,0.75,0.75);
	glVertex2f(1.0f,0.15f);
	glVertex2f(1.0f,0.2f);
	glVertex2f(0.8f,0.2f);
	glVertex2f(0.8f,0.15f);

	glEnd();

	//bottom quad upper
	glBegin(GL_QUADS);

	//glColor3f(0.98, 0.51, 0.10);//orange
	glVertex2f(0.93f, 0.15f);
	glVertex2f(0.88f, 0.15f);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(0.88f, 0.0f);
	glVertex2f(0.93f,0.0f);

	glEnd();

	//bottom quad lower
	glBegin(GL_QUADS);

	//glColor3f(1.0f, 1.0f, 1.0f);//white
	glVertex2f(0.93f, 0.0f);
	glVertex2f(0.88f, 0.0f);
	

	//glColor3f(0.02, 0.50, 0.03);//green	
	glVertex2f(0.88f, -0.2f);
	glVertex2f(0.93f, -0.2f);
	
	glEnd();

	if (cPlanetranslatex >= 0.78)
	{
		glBegin(GL_QUADS);

		glColor3f(0.98, 0.51, 0.10);//orange

		glVertex2f(0.93f,0.05f);
		glVertex2f(0.93,0.017f);
		glVertex2f(0.88,0.017f);
		glVertex2f(0.88,0.05f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);//white

		glVertex2f(0.93f, 0.017f);
		glVertex2f(0.93f, -0.0163f);
		glVertex2f(0.88f, -0.0163f);
		glVertex2f(0.88, 0.017f);

		glEnd();

		glBegin(GL_QUADS);

		glColor3f(0.02, 0.50, 0.03);//green

		glVertex2f(0.93f, -0.0163f);
		glVertex2f(0.93, -0.05f);
		glVertex2f(0.88, -0.05f);
		glVertex2f(0.88, -0.0163f);

		glEnd();
	}
}