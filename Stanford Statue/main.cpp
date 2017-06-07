/*Name  : Leeladhar Munnangi
ID      : 109510225
Class   : CSCI 272
Project : Wavefront Object Loader */


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
#include<GL/gl.h>
#include<stdio.h>
#include <math.h>
using namespace std;

bool WireFrame= false;
int zoom=0,rotate=0, move=0;                                 //creating variables for moving the object
double v[15000][3]={0},vn[15000][3]={0},f[25000][9]={0};     //creating an array which stores values


const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 5.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* GLUT callback Handlers */

GLuint statue;
char ch, ch1 ='1';


void loadObj(char *fname)
{
    FILE *fp;
    int i,read,vi=1,vni=1,fi=1;                         //initializing
    GLfloat x, y, z,x1,y1,z1;
    char ch,ch1;
    statue=glGenLists(1);                               //creating lists
    fp=fopen(fname,"r");                                //opening file to read data
    if (!fp)
    {
        printf("can't open file %s\n", fname);          //if file is not open then display the message
        exit(1);
    }

    {
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);     //reading the values x,y,z from the file
            //cout<<ch<<" "<<x<<" "<<y<<" "<<z<<endl;
            if(read==4&&ch=='v')                            //reading the vertex values
            {
                v[vi][0]=x/300;                             //Dividing all values by 300 to reduce the coordinates
                v[vi][1]=y/300;
                v[vi][2]=z/300;
                    vi++;
                    //cout<<x<<" "<<y<<" "<<z<<endl;
        }
            if(read==4&&ch=='n')                            //reading normal values when n is encountered in the file
            {
                //glVertex3f(x,y,z);
                vn[vni][0]=x;
                vn[vni][1]=y;
                vn[vni][2]=z;
                    vni++;
               // cout<<x<<" "<<y<<" "<<z<<endl;

        }
        if(ch=='f'&&vi>100&&fi<=22250){                     //reading faces from the file when F is encountered in the file
            f[fi][0]=x;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][1]=x;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][2]=x;
            f[fi][3]=y;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][4]=x;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][5]=x;
            f[fi][6]=y;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][7]=x;
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            f[fi][8]=x;
            fi++;

        }
    }
    }

    fclose(fp);

}

static void resize(int width, int height)
{
     double Ratio;

   if(width<=height)
            glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);
    else
          glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective (50.0f,1,0.1f, 100.0f);
 }



static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,10,0.0,0.0,0.0,0.0,1.0,0.0);

    if(WireFrame)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//Draw Our Mesh In Wireframe Mesh
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		//Toggle WIRE FRAME

    glPushMatrix();
    glTranslatef(0,0,zoom);          /*Translate along Z-axis*/
    glRotated(move,1,0,0);           /*Rotating object around X-axis*/
    glRotated(rotate,0,1,0);         /* Rotating Object around Y-axis*/
    glScalef(0.30,0.30,0.30);


    glCallList(statue);
for(int i=1;i<=22250;i++){         /*For loop is used to run 22250 times to display all faces*/
    glBegin(GL_TRIANGLES);
        glNormal3f(vn[(int)f[i][2]][0],vn[(int)f[i][2]][1],vn[(int)f[i][2]][2]);
        glVertex3f(v[(int)f[i][0]][0],v[(int)f[i][0]][1],v[(int)f[i][0]][2]);

        glNormal3f(vn[(int)f[i][5]][0],vn[(int)f[i][5]][1],vn[(int)f[i][5]][2]);
        glVertex3f(v[(int)f[i][3]][0],v[(int)f[i][3]][1],v[(int)f[i][3]][2]);

        glNormal3f(vn[(int)f[i][8]][0],vn[(int)f[i][8]][1],vn[(int)f[i][8]][2]);
        glVertex3f(v[(int)f[i][6]][0],v[(int)f[i][6]][1],v[(int)f[i][6]][2]);
    glEnd();
     }
    glPopMatrix();
    glutSwapBuffers();
}
static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
      case 27 :
        case 'q':               /*Quit program when Q is pressed*/
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
    case GLUT_KEY_END:
        zoom=zoom+5;           // Zooming in when End key is pressed
    break;

    case GLUT_KEY_HOME:        // Zooming out when Home key is pressed
        zoom=zoom-5;
    break;

    case GLUT_KEY_UP:           // Rotating around X-axis up arrow is pressed
        move=move-5;
    break;

    case GLUT_KEY_DOWN:          // Rotating around X-axis down arrow is pressed
        move=move+5;
    break;

    case GLUT_KEY_LEFT:
        rotate=rotate-5;           // Rotating around Y-axis left arrow is pressed
    break;

    case GLUT_KEY_RIGHT:
        rotate=rotate+5;           // Rotating around Y-axis right arrow is pressed
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
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(20,20);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutCreateWindow("WaveFront Object Loader");
    init();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(Specialkeys);
    glutIdleFunc(idle);
    loadObj("ateneam.obj");              /*Calling Ateneam.obj file to read data */
    glutMainLoop();
    return EXIT_SUCCESS;
}
