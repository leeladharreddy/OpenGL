//Name : Leeladhar Munnangi
//Class : CSCI 272
//ID : 109510225
//Project Name: Shapes and Modeling


#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>



bool WireFrame= false;
float  s_zaxis=-1.0, c_zaxis=-3.0,  t_zaxis=2.0;
double s_angle=0.0,  c_angle = 0.0, t_angle =0.0;
bool   s = false,    c = false,     t = false, a=false;
using namespace std;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

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

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,5,10,0.0,0.0,0.0,0.0,1.0,0.0);

    if(WireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//Draw Our Mesh In Wireframe Mesh
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		//Toggle WIRE FRAME

glPushMatrix(); //set where to start the cube object

    glColor3f( 0.5, 0.5, 1.0);          //Applying color to the cube
    glTranslated(4.0,0.0,c_zaxis);      //Placing Cube on the plane
    glRotated(c_angle,0,1,0);           //Rotating cube along the Y-axis
    glScalef (1,1,1);                   //Scaling the cube.
    glutSolidCube(2);                   //Cube

glPopMatrix(); //end the Cube object transormations

glPushMatrix(); //set where to start the Teapot object

    glColor3f( 0.0, 1.0, 1.0);           //Applying color to the Teapot
    glTranslatef(0.0,0.0,t_zaxis);       //Placing Teapot on the plane
    glRotated(t_angle,0,1,0);            //Rotating Teapot along the Y-axis
    glScalef (1,1,1);                    //Scaling the Teapot.
    glutSolidTeapot(1);                  //Teapot

glPopMatrix(); //end the Teapot object transormations

glPushMatrix(); //set where to start the sphere object

    glColor3f( 1.0, 0.0, 1.0);          //Applying color to the sphere
    glTranslatef(-3.5,0.0,s_zaxis);     //Placing sphere on the plane
    glRotated(s_angle,0,1,0);           //Rotating sphere along the Y-axis
    glScalef (1,1,1);                   //Scaling the sphere
    glutSolidSphere(1,16,22);           //Sphere

glPopMatrix(); //end the sphere object transormations


glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
   switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;
        case 'C':
        case 'c':
            c = true;   //only cube is active
            s = false;
            t = false;
            break;
        case 'S':
        case 's':
            c = false;
            s = true;   //only Sphere is active
            t = false;
            break;
        case 'T':
        case 't':
            c = false;
            s = false;
            t = true;   //only Teapot is active
            break;
        case 'A':
        case 'a':            //In this case all the three objects are active
            c = true;
            s =true;
            t =true;
            break;
    }
}


void Specialkeys(int key, int x, int y)
{
   switch(key)
    {
    case GLUT_KEY_UP:
        if(c){
            c_zaxis =c_zaxis+1.0;  //Cube Zoom In: Up_Key (1.0 increment)
        }

        if(t){
            t_zaxis =t_zaxis+1.0;  //Teapot Zoom In: Up_Key (1.0 increment)
        }

        if(s){
            s_zaxis =s_zaxis+1.0;  //Sphere Zoom In: Up_Key (1.0 increment)
        }

    break;

        case GLUT_KEY_DOWN:
        if(c){
            c_zaxis =c_zaxis-1.0;  //Cube Zoom out: Down_Key (1.0 decrement)
        }

        if(t){
            t_zaxis =t_zaxis-1.0;  //Teapot Zoom out: Down_Key (1.0 decrement)
        }

        if(s){
            s_zaxis =s_zaxis-1.0;  //Sphere Zoom out: Down_Key (1.0 decrement)
        }

    break;

    case GLUT_KEY_LEFT:
        if(c){
            c_angle+=5.0; //Cube Rotate Left (around y-axis):by 5 degrees increment
        }

        if(t){
            t_angle+=5.0; //Teapot Rotate Left (around y-axis):by 5 degrees increment
        }

        if(s){
            s_angle+=5.0; //Sphere Rotate Left (around y-axis):by 5 degrees increment
        }
    break;
        case GLUT_KEY_RIGHT:
        if(c){
            c_angle-=5.0;  //Cube Rotate Left (around y-axis):by 5 degrees decrement
        }

        if(t){
            t_angle-=5.0;  //Teapot Rotate Left (around y-axis):by 5 degrees decrement
        }

        if(s){
            s_angle-=5.0; //Sphere Rotate Left (around y-axis):by 5 degrees decrement
        }
    break;
   }
  glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
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
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);
    glutIdleFunc(idle);
    glutMainLoop();

    return EXIT_SUCCESS;
}
