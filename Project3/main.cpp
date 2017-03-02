//Name : Leeladhar Reddy Munnangi
//ID: 109510225
//Class: Computer Graphics CSCI 272
//Project Name: Solar System

#include <string.h>
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
//#include <GL/freeglut.h>
static void init(void);
using namespace std;
#define PI 3.14159
GLfloat matrixX[16];
GLfloat matrixY[16];
GLfloat matrixZ[16];
GLfloat x, y, z, w;
int flag =0,i=0,j=0;
static int year = 0, day = 0;
static GLint RotateY=0; /* model rotation Y index*/
static GLint RotateX=0; /* model rotation X index*/
static GLint RotateZ=0; /* model rotation Z index*/
bool WireFrame= false;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };


const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


/* GLUT callback Handlers */

static void resize(int width, int height)
{
     double Ratio;

   if(width<=height)
     {
         glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
         Ratio =  height/width;
      }
    else
      {
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
        Ratio = width /height;
      }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (50.0f,Ratio,0.1f, 100.0f);
 }

void CreateFromAxisAngle(GLfloat X, GLfloat Y, GLfloat Z, GLfloat degree)
{
 /* First we want to convert the degrees to radians since the angle is assumed to be in radians*/
GLfloat angle = (GLfloat)((degree / 180.0f) * PI);
 /* Here we calculate the sin( theta / 2) once for optimization */
GLfloat result = (GLfloat)sin( angle / 2.0f );
 /* Calcualte the w value by cos( theta / 2 ) */
w = (GLfloat)cos( angle / 2.0f );
 /* Calculate the x, y and z of the quaternion */
x = (GLfloat)(X * result);
y = (GLfloat)(Y * result);
z = (GLfloat)(Z * result);
}


void CreateMatrix(GLfloat *pMatrix)
{
// First row
pMatrix[ 0] = 1.0f - 2.0f * ( y * y + z * z );
pMatrix[ 1] = 2.0f * (x * y + z * w);
pMatrix[ 2] = 2.0f * (x * z - y * w);
pMatrix[ 3] = 0.0f;
// Second row
pMatrix[ 4] = 2.0f * ( x * y - z * w );
pMatrix[ 5] = 1.0f - 2.0f * ( x * x + z * z );
pMatrix[ 6] = 2.0f * (z * y + x * w );
pMatrix[ 7] = 0.0f;
//third row
pMatrix[ 8] = 2.0f * ( x * z + y * w );
pMatrix[ 9] = 2.0f * (y * z - x * w);
pMatrix[ 10] = 1.0f - 2.0f * ( x * x + y * y );
pMatrix[ 11] = 0.0f;
//fourth row
pMatrix[ 12]=0.0f;
pMatrix[ 13]=0.0f;
pMatrix[ 14]=0.0f;
pMatrix[ 15]=1.0f;
}
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
   glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();

    glRotated(30,0,0,1);                                //This function tilts entire solar system by 30 degrees on X axis
    gluLookAt(0,5,10,0.0,0.0,0.0,0.0,1.0,0.0);           /*Specifies the position of the eye point.

                                                           Specifies the position of the reference point.

                                                            Specifies the direction of the up vector */



    if(WireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//Draw Our Mesh In Wireframe Mesh
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		//Toggle WIRE FRAME

		if(flag == 1)                                   //Check flag bit with if condition enter the loop
        {
            day = (day -2)%360;                         //rotate sun by 2 degrees

        for(i=0;i<1000000;i++)                         /* To decrease the speed of rotation */
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
       for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        }

 CreateMatrix(matrixX); /* initial quatonion */
 CreateFromAxisAngle(0, 1, 0,day); /* quaternion for rotation around Y axis*/
 glMultMatrixf(matrixX);  /* multiply original matrix*/
          init();
    glPushMatrix();                             //set where to start the sun object
    glColor3f( 1.0, 0.0, 0.0);                  //Applying color to the sun
    glTranslatef(0.0,0.0,0.0);                  //Placing sun on the plane
    glutSolidSphere(1.0,20,15);                 //Sun
    glPopMatrix();                              //end the sun object transformations

    		if(flag == 1)                       //Check flag bit with if condition enter the loop
        {
           day = (day -10)%360;                 //rotate PlanetB by 5 degrees

        for(i=0;i<1000000;i++)                  /* To decrease the speed of rotation */
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;


        }
    CreateMatrix(matrixX); /* initial quaternion */
 CreateFromAxisAngle(0, 1, 0,day); /* quaternion for rotation around Y axis*/
 glMultMatrixf(matrixX);  /* multiply original matrix*/

     glPushMatrix();                            //set where to start the planetB object
    glColor3f( 0.0, 0.7, 1.0);                  //Applying color to the planetB
    glTranslatef(2.3,0.0,0.0);                  //Placing planetB on the plane next to sun
    glutSolidSphere(0.6,20,15);                 //planetB
    glPopMatrix();                              //end the PlanetB object transformations

    		if(flag == 1)                       //Check flag bit with if condition enter the loop
        {
            day = (day -5)%360;                 //rotate Earth by 5 degrees
             for(i=0;i<1000000;i++)             /* To decrease the speed of rotation */
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
 for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;
        for(i=0;i<1000000;i++)
       {
           j++;
       }i=j=0;

        }


    CreateMatrix(matrixX); /* initial quatonion */
 CreateFromAxisAngle(0, 1, 0,day); /* quaternion for rotation around Y axis*/
 glMultMatrixf(matrixX); /* multiply original matrix*/

    glPushMatrix();
    glColor3f( 0.0, 0.7, 0.0);                   //Applying color to the earth
    glTranslatef(4.0,0.0,0.0);                   //Placing  earth on the plane next to planet B
    glutSolidSphere(0.70,20,15);                 //earth
   // glPopMatrix();


   CreateMatrix(matrixX); /* initial quatonion */
 CreateFromAxisAngle(0, 1, 0,day); /* quatonion for day rotation */
 glMultMatrixf(matrixX);  /* multiply original matrix*/

    //glPushMatrix();
    glColor3f( 0.5, 0.0, 0.5);                   //Applying color to the moon
    glTranslatef(1.0,0.25,0.0);                  //Placing moon on the plane
    glutSolidSphere(0.25,20,15);                 //moon
    glPopMatrix();                                  //end the Earth and moon object transformations



    glutSwapBuffers();

   glutPostRedisplay();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'w':
            WireFrame =! WireFrame;
    }
}

void Specialkeys(int key, int x, int y)
{

switch(key)
    {

 case GLUT_KEY_UP:
  flag =1;  // set flag bit equal to 1.

}
}

static void idle(void)
{

    glutPostRedisplay();

}
static void Timer(int iUnused)
{

    glutTimerFunc(600,Timer,0);
}

static void init(void)
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Solar System");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);
    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}
