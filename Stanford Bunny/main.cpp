#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include <math.h>
using namespace std;
bool WireFrame= false;
/*v ,vn,f z being used to store the variables*/
double v[11146][3]={0},vn[11148][3]={0},f[30338][9]={0},zoom = -10,mo=0,rot=0;
int i;

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
    glTranslatef(0,0,zoom);
    glRotated(mo,1,0,0);
    glRotated(rot,0,1,0);
    glScalef(1.0,1.0,1.0);


//    glCallList(statue);
for(int i=0;i<30338;i++){
    glBegin(GL_TRIANGLES);
       // glNormal3f(vn[(int)f[i][2]][0],vn[(int)f[i][2]][1],vn[(int)f[i][2]][2]);
        glVertex3f(v[(int)f[i][0]][0],v[(int)f[i][0]][1],v[(int)f[i][0]][2]);

        //glNormal3f(vn[(int)f[i][5]][0],vn[(int)f[i][5]][1],vn[(int)f[i][5]][2]);
        glVertex3f(v[(int)f[i][3]][0],v[(int)f[i][3]][1],v[(int)f[i][3]][2]);

       // glNormal3f(vn[(int)f[i][8]][0],vn[(int)f[i][8]][1],vn[(int)f[i][8]][2]);
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
        case 27 : /*escape key */
            exit(0);
            break;
        case 'q': /*quit*/
            exit(0);
            break;
        case 'w':
            WireFrame =! WireFrame;
            break;
    }
}

void Specialkeys(int key, int x, int y)
{
    switch(key)
    {
case GLUT_KEY_LEFT: /*This is used to turn left when pressed left arrow*/
        mo=mo+1;
    break;

    case GLUT_KEY_RIGHT: /*This is used to turn right when pressed right arrow*/
        mo=mo-1;
    break;

    case GLUT_KEY_END: /*Zoom in when pressed end button*/
        zoom=zoom+1;
    break;

    case GLUT_KEY_HOME: /*Zoom out when pressed home button*/
        zoom=zoom-1;
    break;
        case GLUT_KEY_UP: /*Rotate when pressed up arrow button*/
        rot=rot+1;
    break;

    case GLUT_KEY_DOWN: /*Rotate when pressed down arrow button*/
        rot=rot-1;
    break;

   }
  glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void load(void){ /*load function is used to load the values from the file*/
     string text,left;
     int len,pos,prev,p=0,j=0,q=0,r=0,k=0,factor = 40;
  ifstream file ("bunny.obj");
  if (file.is_open()) /*checking weather the file can be read or not*/
   {
    while ( getline (file,text) )
    {
        if(text[0]=='v'&&text[1]==' '){ /*checking if the line has the vertexes values or not*/
                   len=text.length();
            prev=3;
            j=0;
        for(i=4;i<len;i++){
            if(text[i]==' '){
                pos=i;
                left=text.substr(prev,pos);
                stringstream geek(left);
                geek >> v[p][j]; /*storing values into matrices*/
                v[p][j] = v[p][j]/ factor;

                prev=pos+1;
        j++;
               }
                if(j==2){
                    left=text.substr(prev);
                    stringstream geek(left);
                    geek >> v[p][j]; /*storing values into matrices*/
                    v[p][j] = v[p][j]/ factor;
                    break;
                }
        }

        p++;
        }else if(text[0]=='v'&&text[1]=='t'){ /*checking if the line has the vertex normals values or not*/
           len=text.length();
            prev=3;
            j=0;
        for(i=4;i<len;i++){
            if(text[i]==' '){
                pos=i;
                left=text.substr(prev,pos);
                stringstream geek(left);
                geek >> vn[q][j];/*storing values into matrices*/
                prev=pos+1;
        j++;
               }
                if(j==1){
                    left=text.substr(prev);
                    stringstream geek(left);
                    geek >>vn[q][j] ;/*storing values into matrices*/

                    break;
                }
        }
        q++;
        }else if(text[1]=='f'){ /*checking if the line has the faces values or not*/

           len=text.length();
            prev=2;
            j=0;
        for(i=2;i<len;i++){
            if(text[i]==' '){
                pos=i;

                for(k=prev;k<pos;k++){
                        if(text[k]==47||(j%3)==2){
                left=text.substr(prev,k);
                stringstream geek(left);
                geek >> f[r][j];/*storing values into matrices*/
                f[r][j]--;
                j++;
                prev=k+1;
                        }

                }
                prev=pos+1;
               }
                if(j==6){
                for(k=prev;k<len;k++){
                if(text[k]==47||(j%3)==2){
                left=text.substr(prev,k);
                stringstream geek(left);
                geek >> f[r][j];/*storing values into matrices*/
                f[r][j]--;
                j++;
                prev=k+1;
                        }

                }
                    break;
                }
        }

        r++;
        }

    }
    file.close();

  }

  else cout << "Unable to open file";
}

static void init(void)
{
    load();
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
