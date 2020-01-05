#include <stdio.h>
#include <GL/glut.h>
#include<stdlib.h>
#define ROT_INC		0.1

//*********flags*********
static int window;
int lightingflag = 0;
int coloringflag = 0;
int bgcoloringflag = 0;
int lightingflag1 = 0;

/*********Coordinates for the cube********/
GLfloat vertices[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},  {1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat normals[][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},  {1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
GLfloat colors[][3]={{0.0,0.0,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};

/*********Declaration of the variables and functions*********/
static GLfloat g_rotate = 0;
static GLfloat g_rotInc = ROT_INC;
static int window, returnmenu, returnsubmenu, returnsubmenushapes, value = 0 ;
void key1(unsigned char,int ,int);

/*********DrawText*********/
void drawstring(char *s,float x,float y)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}
void drawstring2(char *s,float x,float y)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}
void drawstring3(char *s,float x,float y)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
}
/*********Cube Code*********/
void polygon(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(colors[a]);
     		glNormal3fv(normals[a]);
     		glVertex3fv(vertices[a]);
     		glColor3fv(colors[b]);
     		glNormal3fv(normals[b]);
     		glVertex3fv(vertices[b]);
     		glColor3fv(colors[c]);
     		glNormal3fv(normals[c]);
     		glVertex3fv(vertices[c]);
     		glColor3fv(colors[d]);
     		glNormal3fv(normals[d]);
     		glVertex3fv(vertices[d]);
    	glEnd();
}
void colorcube()
{
  	polygon(0,3,2,1);
  	polygon(2,3,7,6);
  	polygon(0,4,7,3);
  	polygon(1,2,6,5);
  	polygon(4,5,6,7);
  	polygon(0,1,5,4);     
}

/*********Menu Begins*********/
void menu(int n)
{
	if (n == 0)
	{
		glutDestroyWindow(window);
		exit(0);
	}
	else
	{
		value = n;
		glutPostRedisplay();
	}
}
void createMenu(void)
{
	returnsubmenushapes = glutCreateMenu(menu);
	glutAddMenuEntry("SolidSphere", 1);
	glutAddMenuEntry("WiredSphere",2);
	glutAddMenuEntry("SolidCube", 3);
	glutAddMenuEntry("WiredCube", 4);
	glutAddMenuEntry("ColorCube",5);
	glutAddMenuEntry("SolidTorus", 6);
	glutAddMenuEntry("WiredTorus", 7);
	glutAddMenuEntry("SolidCone", 8);
	glutAddMenuEntry("WiredCone", 9);
	glutAddMenuEntry("Icos", 10);
	glutAddMenuEntry("SolidTeapot",11);
	glutAddMenuEntry("WiredTeapot", 12);
	//function to call menu function and return value
	returnmenu = glutCreateMenu(menu);	
	glutAddMenuEntry("Clear",'c');
	glutAddSubMenu("Shapes", returnsubmenushapes);
	glutAddMenuEntry("Quit", 0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

/*********Front Screen*********/
void frontscreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0f,1.0f,0.0f,1.0f);
	glColor3f(0.0,0.0,0.0);
	drawstring("BANGALORE INSTITUTE OF TECHNOLOGY ",-0.75,0.8);
	glColor3f(0.0,0.0,1.0);
	drawstring2("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",-0.8,0.7);
	glColor3f(0.0,0.0,0.0);
	drawstring2("COMPUTER GRAPHICS PACKAGE ON",-0.52,0.4);
	glColor3f(1.0,0.0,0.0);
	drawstring("3D GEOMETRIC SHAPES",-0.46,0.1);
	glColor3f(1.0,0.0,0.0);
	drawstring3("BY:",-0.8,-0.75);
	glColor3f(0.0,0.0,0.0);
	drawstring3("VIVEK HEGADE M S",-0.8,-0.85);
	drawstring3("1BI14CS183",-0.8,-0.9);
	glColor3f(1.0,0.0,0.0);
	drawstring3("GUIDED BY:",0.6,-0.75);
	glColor3f(0.0,0.0,0.0);
	drawstring3("Prof. SHOBHA Y",0.6,-0.85);
	drawstring3("Associate Proffessor",0.6,-0.9);
	glColor3f(1.0,0.0,0.0);
	drawstring2("PRESS ENTER TO START",-0.36,-0.1);
	glutKeyboardFunc(key1);
	//glFlush();
	glColor3f(0,0,0);
	glutSwapBuffers();
}

/*********FrontPage*********/
void key1(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 13:
				startscreen();
				break;
	}
}

/*********Display Function*********/
void display(void)
{
	glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	GLfloat mat_ambient1[]={0.7,0.7,0.7,1.0};
 	GLfloat mat_diffuse1[]={0.5,0.5,0.5,1.0};
  	GLfloat mat_specular1[]={1.0,1.0,1.0,1.0};

	GLfloat mat_ambient2[]={0.329412,0.223529,0.027452,1.0};
 	GLfloat mat_diffuse2[]={0.780392,0.568627,0.113725,1.0};
  	GLfloat mat_specular2[]={0.992157,0.941176,0.807843,1.0};

	GLfloat mat_ambient3[]={0.1,0.1,0.1,1.0};
 	GLfloat mat_diffuse3[]={0.5,0.5,0.5,1.0};
  	GLfloat mat_specular3[]={1.0,1.0,1.0,1.0};

	GLfloat mat_ambient4[]={0.2,0.3,0.2,1.0};
 	GLfloat mat_diffuse4[]={0.3,0.6,0.8,1.0};
  	GLfloat mat_specular4[]={1.0,1.0,1.0,1.0};

	GLfloat mat_ambient5[]={0.1,0.3,0.2,1.0};
 	GLfloat mat_diffuse5[]={0.1,0.1,0.1,1.0};
  	GLfloat mat_specular5[]={1.0,1.0,1.0,1.0};

	GLfloat mat_shininess[]={30.0};
  	GLfloat lightintensity[]={0.7,0.7,0.7,1.0};
  	GLfloat lightposition[]={2.0,6.0,3.0,0.0};
  	
  	glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
  	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);
	glLightfv(GL_LIGHT1,GL_POSITION,lightposition);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,lightintensity);
	glRotatef(g_rotate,1.0,1.0,1.0);
	//Different background colors for geometric shapes
	switch(bgcoloringflag)
	{
		case 1:
			glClearColor(1.0f,0.0f,0.0f,1.0f);
			break;
		case 2:
			glClearColor(0.0f,1.0f,0.0f,1.0f);
			break;
		case 3:
			glClearColor(0.0f,0.0f,1.0f,1.0f);
			break;
		case 4:
			glClearColor(1.0f,1.0f,0.0f,1.0f);
			break;
		case 5:
			glClearColor(0.0f,1.0f,1.0f,1.0f);
			break;
		default:
			glClearColor(0.0f,0.0f,0.0f,1.0f);
	}
	//Different color for lighting
	switch(lightingflag1)
	{
		case 1:
			glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient2);
  			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse2);  
  			glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular2);
  			glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
			break;
		case 2:
			glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient3);
  			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse3);  
  			glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular3);
  			glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
			break;
		case 3:
			glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient4);
  			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse4);  
  			glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular4);
  			glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
			break;
		case 4:
			glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient5);
  			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse5);  
  			glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular5);
  			glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
			break;
		default:
			glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient1);
  			glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse1);  
  			glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular1);
  			glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	}
	//Different colors for geometric shapes
	switch(coloringflag)
	{	
		case 1:
			glColor3f(1.0,0.0,0.0);
			break;
		case 2:
			glColor3f(0.0,1.0,0.0);
			break;
		case 3:
			glColor3f(0.0,0.0,1.0);
			break;
		case 4:
			glColor3f(1.0,1.0,0.0);
			break;
		case 5:
			glColor3f(0.0,1.0,1.0);
			break;
		default: glColor3f(1.0,1.0,1.0);
			break;
	}
	//Goemetric Shapes drawing
	switch(value)
	{
		case 1: 
			
			glutSolidSphere(5.0,20,20);
			break;
		case 2: 
			glutWireSphere(5.0,20,20);
			break;
		case 3: 
			glutSolidCube(6.0);
			break;
		case 4: 
			glutWireCube(6.0);
			break;
		case 5:
			colorcube();
			break;
		case 6:
			glutSolidTorus(1.0,6.0,10,20);
			break;
		case 7:
			glutWireTorus(1.0,6.0,10,20);
			break;
		case 8:
			glutSolidCone(6.0,8.0,10,20);
			break;
		case 9:
			glutWireCone(6.0,8.0,10,20);
			break;
		case 10: 
			glPushMatrix();
			glScalef(6.0,6.0,6.0);
			glutWireIcosahedron();
			glPopMatrix();
			break;
		case 11: 
			glutSolidTeapot(6.0);
			break;
		case 12:
			glutWireTeapot(6.0);
			break;
	}
	//Lighting enabling or disabling
	if(lightingflag==1)
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}
	glFlush();
	glPopMatrix();
 	glutSwapBuffers();

}

/*Reshape function to set the adjust the size of shapes*/
void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); 
    	glLoadIdentity(); 
	/* perspective parameters: field of view, aspect, near clip, far clip */
	gluPerspective( 60.0, (GLdouble)w/(GLdouble)h, 0.1, 40.0);
    	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 20.0, /* eye at (0,0,20) */
			  0.0, 0.0, 0.0, /* lookat point */
			  0.0, 1.0, 0.0); /* up is in +ive y */
}

/*Key Board Function to quit from the output window*/
void myKey(unsigned char k, int x, int y)
{
	switch(k)
	{
		case 'q' | 'Q':
			exit(0);
			break;
		case 'l' | 'L':
			if(lightingflag == 0)
				lightingflag = 1;
			else
				lightingflag = 0;
			break;
		case 'c' | 'C':
			switch(coloringflag)
			{
				case 0:
					coloringflag = 1;
					break;
				case 1:
					coloringflag = 2;
					break;		
				case 2:	
					coloringflag = 3;
					break;
				case 3:	
					coloringflag = 4;
					break;
				case 4:	
					coloringflag = 5;
					break;
				case 5:	
					coloringflag = 0;
					break;
				
				default:
					coloringflag = 0;
			}
			break;
		case 'b' | 'B':
			switch(bgcoloringflag)
			{
				case 0:
					bgcoloringflag=1;
					break;
				case 1:
					bgcoloringflag=2;
					break;
				case 2:
					bgcoloringflag=3;
					break;
				case 3:
					bgcoloringflag=4;
					break;
				case 4:
					bgcoloringflag=5;
					break;
				case 5:
					bgcoloringflag=0;
					break;
				default:
					bgcoloringflag=0;
			}
			break;
		case 'p' | 'P':
			switch(lightingflag1)
			{
				case 0:
					lightingflag1=1;
					break;
				case 1:
					lightingflag1=2;
					break;
				case 2:
					lightingflag1=3;
					break;
				case 3:
					lightingflag1=4;
					break;
				default:
					lightingflag1=0;
			}
			break;
		default:
			 printf("Unknown keyboard command \'%c\'.\n", k);
		break;
	}
}

/*Mouse Function to implement the mouse Interaction*/
void myMouse(int btn, int state, int x, int y)
{   

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) g_rotInc += ROT_INC;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) g_rotInc -= ROT_INC;
	glutPostRedisplay();
}   

/*myIdle Function for the rotation of the Shapes used*/
void myIdleFunc(void)
{
	g_rotate += g_rotInc;

	/* force glut to call the display function */
	glutPostRedisplay();
}

/*********StartScreen***********/
int startscreen()
{	
	glutDestroyWindow(window);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	window=glutCreateWindow("3d Shapes Test");
	//Callback Functions
	createMenu();	
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(myIdleFunc);
	glutKeyboardFunc(myKey);
	glutMouseFunc(myMouse);
	//Enabling and Disabling the required features
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	/* set clear colour */
	glClearColor(0.0, 0.0, 0.0, 1.0);
	/* set current colour to black */
	glColor3f(0.0, 0.0, 0.0);
	//Delay for the output
	glutMainLoop();
	return 0;
}

/*********Main Funciton*********/
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowPosition(700,400);
	glutInitWindowSize(700,700);
	window=glutCreateWindow("WELCOME");
	glutDisplayFunc(frontscreen);
	//glutIdleFunc(frontscreen);
	glutKeyboardFunc(key1);
	//glutReshapeFunc(reshape);
	glutMainLoop();
}
/*********End OF The Program*********/
