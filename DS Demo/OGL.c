
// standard Header Files
#include<windows.h>
#include<stdio.h> 
#include<stdlib.h> // for exit() 
#include <mmsystem.h>	// for PlaySound() api

//OpenGl Header file
#include<gl/GL.h>
#include<gl/GLU.h>

#include"OGL.h"

#define STB_IMAGE_IMPLEMENTATION 

#include"stb_image.h"


// Micros
#define WIN_WIDTH 800                  
#define WIN_HEIGHT 600

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

GLfloat angle = 0.0;
GLfloat tx, ty, tz,sx,sy,sz;


GLUquadric* quadric = NULL;

//Texture Object

GLuint texture_sky= 0;
GLuint texture_grass = 0;
GLuint texture_tree = 0;
GLuint texture_mother = 0;
GLuint texture_Ground = 0;
GLuint texture_Well;
GLuint tree_root;
GLuint texture_Cort = 0;
GLuint texture_blackSky = 0;
GLuint texture_honey = 0;
GLuint texture_Swing = 0;
GLuint texture_tractor = 0;
GLuint texture_Sunset = 0;
GLuint texture_Football = 0;
GLuint texture_River = 0;
GLuint texture_Soil = 0;
GLuint texture_Tyre = 0;
GLuint texture_Varul = 0;
GLuint texture_Ant = 0;
GLuint texture_Airplane = 0;
GLuint texture_terrain = 0;
GLuint texture_astromedicomp = 0;
GLuint texture_groupname = 0;
GLuint texture_naal = 0;
GLuint texture_Outro = 0;

GLfloat s1Rotate = 0.0f;
BOOL bFlag = TRUE;

int sceneCount = 0;
float timeCount = 0.0;

//user defined header file
#include"Humanoid.h"
#include"Scene1.h"
#include"House.h"
#include"Scene2.h"
#include"Scene3.h"
#include"Intro.h"
#include"Outro.h"


//int SceneCounter = 0;
//GLfloat sceneTranslate = 0.0f;

//GLfloat sc1_tx = 0; 
//GLfloat sc1_ty = 1.0;
//GLfloat sc1_tz = 12.0;

BOOL flagTyre = FALSE;
BOOL flagTactor = FALSE;


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
		TEXT("Aditya Madhukar Bhavsar"),
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
LRESULT CALLBACK WndProc(HWND   hwnd, UINT  iMsg, WPARAM wParam, LPARAM lParam)
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

		case 'x':
			tx = tx + 1.0f;
			break;

		case 'X':
			tx = tx - 1.0f;
			break;

		case 'y':
			ty = ty + 1.0f;
			break;

		case 'Y':
			ty = ty - 1.0f;
			break;

		case 'z':
			tz = tz + 1.0f;
			break;

		case 'Z':
			tz = tz - 1.0f;
			break;

		case 'a':
			sx = sx - 1.0f;
			break;

		case 'A':
			sx = sx + 1.0f;
			break;

		case 'b':
			sy = sy - 1.0f;
			break;

		case 'B':
			sy = sy + 1.0f;
			break;

		case 'c':
			sz = sz - 1.0f;
			break;

		case 'C':
			sz = sz + 1.0f;
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
	//BOOL LoadGlTexture(GLuint*, TCHAR[]);
	BOOL LoadGlTexture_Sky(GLuint*, char*);

	// Function Declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	BOOL bResult;

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


	//initialize quadric
	quadric = gluNewQuadric();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//Create Texture
	bResult = LoadGlTexture_Sky(&texture_sky, "Sky.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Texture failed\n");
		return -6;
	}

	bResult = LoadGlTexture_Sky(&texture_grass, "Grass.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of grass Texture failed\n");
		return -7;
	}

	bResult = LoadGlTexture_Sky(&texture_Well, "Well3.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of well Texture failed\n");
		return -8;
	}

	bResult = LoadGlTexture_Sky(&tree_root, "tree_root.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of treeroot Texture failed\n");
		return -9;
	}

	bResult = LoadGlTexture_Sky(&texture_bricks, "bricks.jpeg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of bricks texture failed\n");
		return -10;
	}

	bResult = LoadGlTexture_Sky(&texture_Roof,"roof.jpeg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of roof Texture failed\n");
		return -11;
	}

	bResult = LoadGlTexture_Sky(&texture_Door, "door.jpeg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Door texture failed\n");
		return -12;
	}

	bResult = LoadGlTexture_Sky(&texture_Window, "window.jpeg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Window texture failed\n");
		return -13;
	}

	bResult = LoadGlTexture_Sky(&texture_mother,"mother.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of mother texture failed\n");
		return -14;
	}

	bResult = LoadGlTexture_Sky(&texture_Ground, "gd.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of ground texture failed\n");
		return -15;
	}

	bResult = LoadGlTexture_Sky(&texture_Cort, "FootballCort.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of football texture failed\n");
		return -16;
	}

	bResult = LoadGlTexture_Sky(&texture_blackSky, "Sky1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of blacksky texture failed\n");
		return -17;
	}

	bResult = LoadGlTexture_Sky(&texture_honey, "Honey.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of honey texture failed\n");
		return -18;
	}

	bResult = LoadGlTexture_Sky(&texture_Swing, "swing1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of swing texture failed\n");
		return -19;
	}

	bResult = LoadGlTexture_Sky(&texture_tractor, "Tractor.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of tractor texture failed\n");
		return -20;
	}

	bResult = LoadGlTexture_Sky(&texture_Sunset, "Sunset.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of sky_Sunset texture failed\n");
		return -21;
	}

	bResult = LoadGlTexture_Sky(&texture_Football, "Football.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of football texture failed\n");
		return -22;
	}

	bResult = LoadGlTexture_Sky(&texture_River, "River.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of river texture failed\n");
		return -23;
	}

	bResult = LoadGlTexture_Sky(&texture_Soil, "grass1.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of soil texture failed\n");
		return -24;
	}

	bResult = LoadGlTexture_Sky(&texture_Tyre, "Tyre.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of tyre texture failed\n");
		return -25;
	}

	bResult = LoadGlTexture_Sky(&texture_Varul, "AntHill.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of varul texture failed\n");
		return -26;
	}

	bResult = LoadGlTexture_Sky(&texture_Ant, "AntOnStick.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of ant texture failed\n");
		return -27;
	}

	bResult = LoadGlTexture_Sky(&texture_Airplane, "Airplane.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of airplane texture failed\n");
		return -28;
	}

	bResult = LoadGlTexture_Sky(&texture_terrain, "Terrain.jpg");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of terrain texture failed\n");
		return -29;
	}

	bResult = LoadGlTexture_Sky(&texture_astromedicomp, "Astromedicomp.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Astromedicomp texture failed\n");
		return -30;
	}

	bResult = LoadGlTexture_Sky(&texture_groupname, "group.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of groupname texture failed\n");
		return -31;
	}

	bResult = LoadGlTexture_Sky(&texture_naal, "naal.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of naal texture failed\n");
		return -32;
	}


	bResult = LoadGlTexture_Sky(&texture_Outro, "Credits1.png");
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Outro texture failed\n");
		return -32;
	}


	//Failed OpenGl to Enable statement
	glEnable(GL_TEXTURE_2D);

	//code
	resize(WIN_WIDTH, WIN_HEIGHT);

	PlaySound("Naal_Song2.wav", NULL, SND_ASYNC);

	return(0);
}

BOOL LoadGlTexture_Sky(GLuint* texture, char* filename)
{
	//variable declaration
	int width;
	int height;
	int components;
	BOOL bresult = FALSE;

	unsigned char* imagedata = stbi_load(filename, &width, &height, &components, 0);

	if (imagedata == NULL)
	{
		fprintf(gpFile, "failed to load texture %s\n", filename);
		return(bresult);
	}
	else
	{
		bresult = TRUE;
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

		glGenTextures(1, texture);

		glBindTexture(GL_TEXTURE_2D, *texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		if (components == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imagedata);
		}
		else if (components == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagedata);
		}

		//glGenerateMipMap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		stbi_image_free(imagedata);
	}
	return(bresult);
}

void resize(int width, int height)
{
	// Code

	if (height <= 0)
		height = 1;


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 10000.0f);

}

void display(void)
{
	//local variable
	char str[255];

	sprintf(str, "tx=%f,ty=%f,tz=%f,sx=%f,sy=%f,sz=%f", tx, ty, tz,sx,sy,sz);

	SetWindowText(ghwnd, str);

	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//camera
	//glTranslatef(0.0f, 0.0f, -8.0f);

	if (sceneCount == 0)
	{
		if (timeCount <= 1.0)
		{
			Intro();
			timeCount = timeCount + 0.005;
		}
		else if (timeCount <= 2.0)
		{
			group();
			timeCount = timeCount + 0.005;
		}
		else if (timeCount <= 3.0)
		{
			demoname();
			timeCount = timeCount + 0.005;
		}
		else
		{
			sceneCount = 1;
		}
	}

	//*************************************************************
	
	//x=0,y=0,z=9.0
	//x=0.0,y=0.0,z=2.0
	if (sceneCount == 1)
	{
		static GLfloat camX = 0.0f;
		static GLfloat camY = 0.0f;
		static GLfloat camZ = 9.0f;

		static int sc1Flag = 1;
		static GLfloat s1Stop = 0.0f;


		if (sc1Flag == 1)
		{
			if (camZ > 2.0)
			{
				camZ = camZ - 0.01;
			}
			else if (camZ <= 2.0f)
			{
				sc1Flag = 2;
			}
		}
		else if (sc1Flag == 2)
		{
			if (s1Stop < 1.0)
			{
				s1Stop = s1Stop + 0.01;
			}
			else if (camZ > 0.8)
			{
				camZ = camZ - 0.01;
			}
			else
			{
				sc1Flag = 3;
			}
		}
		else if (sc1Flag == 3)
		{
			if (s1Rotate <= 180)
			{
				s1Rotate = s1Rotate + 0.7;
			}
			else if (camZ >= -4.0)
			{
				bFlag = FALSE;
				camZ = camZ - 0.01;
			}
			else
			{
				sceneCount = 2;
			}
		}

		gluLookAt(camX, camY, camZ, 0.0, 0.0, -200, 0.0, 1.0, 0.0);
		glPushMatrix();

		glRotatef(s1Rotate, 0.0, 1.0, 0.0);

		tx = camX;
		ty = camY;
		tz = camZ;

		//gluLookAt(tx + 0.0f, 0.0f + ty, 0.0f + tz, 0.0f, 0.0f, -200.0f, 0.0f, 1.0f, 0.0f);
		scene1();
		glDisable(GL_FOG);
		glPopMatrix();
	}

	else if (sceneCount == 2)
	{
		static GLfloat camX = 0.0f;
		static GLfloat camY = 13.0f;
		static GLfloat camZ = 47.0f;

		static int sc2Flag = 1;
		static GLfloat s2Stop = 0.0f;

		//**********************************************************************
		//x=0.0,y=13.0,z=47.0;
		// x=0.0,y=2.0,z=4.9;
		
		if (sc2Flag == 1)
		{
			if (camZ > 4.9)
			{
				camZ = camZ - 0.08;
			}
			if (camY > 2.0)
			{
				camY = camY - 0.025;
			}
			else if (camZ <= 4.9f)
			{
				sc2Flag = 2;
			}
		}
		/*else if (sc2Flag == 2)
		{
			if (s2Stop < 1.0)
			{
				s2Stop = s2Stop + 0.01;
			}
			else
			{
				sc2Flag = 3;
			}
		}*/

		//x=-20.0, y=8.0, z=-15.0;
		else if (sc2Flag == 2)
		{
			if (camX >= -20.0f)
			{
				camX = camX - 0.05f;
			}
			if (camY <= 8.0)
			{
				camY = camY + 0.05;
			}
			if (camZ >= -15.0f)
			{
				camZ = camZ - 0.04;
			}
			else
			{
				sc2Flag = 3;
			}
		}

		//x=26.0, y=6.0, z=-2.0;
		else if (sc2Flag == 3)
		{
			if (camX <= 26.0f)
			{
				camX = camX + 0.05f;
			}
			else
			{
				sceneCount = 3;
			}

			if (camY >= 6.0)
			{
				camY = camY - 0.05;
			}

			if (camZ <= -2.0f)
			{
				camZ = camZ + 0.04;
			}

		}

		//**********************************************************************

		
		glPushMatrix();
		//gluLookAt(tx + 0.0f, 0.0f + ty, 0.0f + tz, 0.0f, 0.0f, -200.0f, 0.0f, 1.0f, 0.0f);
		gluLookAt(camX, camY, camZ, 0.0, 0.0, -200, 0.0, 1.0, 0.0);
		scene2();
		glPopMatrix();
	}

	else if (sceneCount == 3)
	{
		static GLfloat camX = 0.0f;
		static GLfloat camY = 6.0f;
		static GLfloat camZ = 28.0f;

		static int sc3Flag = 1;
		static GLfloat s3Stop = 0.0f;

		//**********************************************************
		//x=0.0, y=6.0, z=28.0;
		//x=0.0, y=2.0, z=5.0;
		
		if (sc3Flag == 1)
		{
			if (camY > 2.0)
			{
				camY = camY - 0.08;
			}
			if (camZ > 5.0)
			{
				camZ = camZ - 0.025;
			}
			else
			{
				sc3Flag = 2;
			}
		}

		//x=9.0, y=2.0, z=-4.0;

		if (sc3Flag == 2)
		{
			if (camZ > -4.0)
			{
				camZ = camZ - 0.008;
			}
			if (camX < 9.0)
			{
				camX = camX + 0.025;
			}
			else
			{
				flagTyre = TRUE;
				sc3Flag = 3;
			}
		}
		
		//x=-11, y=4, z=-1.0;

		if (sc3Flag == 3)
		{
			if (camZ < -1.0)
			{
				camZ = camZ + 0.008;
			}

			if (camY < 4.0)
			{
				camY = camY + 0.008;
			}

			if (camX > -11.0)
			{
				camX = camX - 0.025;
			}
			else
			{
				flagTyre = FALSE;
				sc3Flag = 4;
			}
		}
		 
		//x=-4.0, y=6.0, z=-11.0;

		if (sc3Flag == 4)
		{
			if (camZ > -11.0)
			{
				camZ = camZ - 0.08;
			}
			else
			{
				flagTactor = TRUE;
				sc3Flag = 5;
			}

			if (camY < 6.0)
			{
				camY = camY + 0.08;
			}

			if (camX < -4.0)
			{
				camX = camX + 0.025;
			}
			
		}

		//x=5, y=4, z=-15

		if (sc3Flag == 5)
		{
			if (camZ > -15.0)
			{
				camZ = camZ - 0.08;
			}
			
			if (camX < 5.0)
			{
				camX = camX + 0.025;
			}
			else
			{
				flagTactor = FALSE;
				sc3Flag = 6;
			}

		}

		//x=0, y=37, z=49

		if (sc3Flag == 6)
		{
			if (camZ < 49.0)
			{
				camZ = camZ + 0.08;
			}
			else
			{
				sceneCount = 4;
			}

			if (camX > 0.0)
			{
				camX = camX - 0.025;
			}

			if (camY < 37.0)
			{
				camY = camY + 0.08;
			}
		}

		//*************************************************************

		glPushMatrix();
		//gluLookAt(tx + 0.0f, 0.0f + ty, 0.0f + tz, 0.0f, 0.0f, -200.0f, 0.0f, 1.0f, 0.0f);
		gluLookAt(camX, camY, camZ, 0.0, 0.0, -200, 0.0, 1.0, 0.0);
		scene3();
		glPopMatrix();
	}
	else if (sceneCount == 4)
	{
		glPushMatrix();
		Outro();
		glPopMatrix();
	}
	
	
	SwapBuffers(ghdc);
}

void update(void)
{
	// Code
	angle = angle + 0.05f;
	if (angle >= 360.0f)
	{
		angle = angle - 360.0f;
	}

	
	if (bFlag==TRUE && translateboyZ >= 1.0f)
	{
		translateboyZ = translateboyZ - 0.009;	
	}
	else if (bFlag == FALSE && translateboyZ <= 5.0f)
	{
		translateboyZ = translateboyZ + 0.009;
	}

	//tactor animation
	
	if (flagTactor && tactortranslatex <= 20.0f)
	{
		tactortranslatex = tactortranslatex + 0.03;
		//tactortranslatex = 10.0f;
	}

	//tyre animation
	
	if (flagTyre && tyretranslatex >= -20.0f)
	{
		tyretranslatex = tyretranslatex - 0.03;
		//tyretranslatex = -5.0f;
	}

	////scene 1 camera
	//if (sc1_ty >= 0.0f)
	//{
	//	sc1_ty = sc1_ty - 0.01;
	//}

	//if (sc1_tz >= 4.5f)
	//{
	//	sc1_tz = sc1_tz - 0.05;
	//}
	//
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

	if (texture_sky)
	{
		glDeleteTextures(1, &texture_sky);
		texture_sky = 0;
	}

	if (texture_grass)
	{
		glDeleteTextures(1, &texture_grass);
		texture_grass = 0;
	}

	if (texture_Well)
	{
		glDeleteTextures(1, &texture_Well);
		texture_Well = 0;
	}

	if (texture_mother)
	{
		glDeleteTextures(1, &texture_mother);
		texture_mother = 0;
	}

	if (texture_bricks)
	{
		glDeleteTextures(1, &texture_bricks);
		texture_bricks = 0;
	}

	if (texture_Door)
	{
		glDeleteTextures(1, &texture_Door);
		texture_Door = 0;
	}

	if (texture_Roof)
	{
		glDeleteTextures(1, &texture_Roof);
		texture_Roof = 0;
	}

	if (texture_Window)
	{
		glDeleteTextures(1, &texture_Window);
		texture_Window = 0;
	}

	if (texture_tree)
	{
		glDeleteTextures(1, &texture_tree);
		texture_tree = 0;
	}

	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

}

