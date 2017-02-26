//Name : Leeladhar Munnangi
//ID   : 109510225
//Class: CSCI 272 Computer Graphics
//ProjectName : Project1

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
/* GLUT callback Handlers */
int n=200000;
  int width,height;

void resize(int width, int height)
{
    if(width<=height)
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
        glViewport((GLsizei) (width-height)/2 ,0 ,(GLsizei) height,(GLsizei) height);
}

void init()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0); // adjusted for suitable viewport

}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);        // clear display screen
glColor3f(1,0,1); //Color to the output RGB bits.
  int i,num=0;
  float px=0.0,py=0.0; //represent the origin
  float tempx=0.5,tempy=0.5;
  for (i=0;i<n;i++)
  {
      num=rand()%100;
      if(num<85) // 85% of times choose coordinate transformation with f2.
      {

          px=0.85*tempx +0.04*tempy; //where (a= 0.85, c = 0.04)
          py=-0.04*tempx+0.85*tempy+1.6; //where (b = -0.04, d =0.85, e =0, f=1.6 )
      }
      else if(num<92) // 7% of times choose coordinate transformation with f3.
        {
        px=0.2*tempx-0.26*tempy; //where (a= 0.2, c =-0.26 )
        py=0.23*tempx+0.22*tempy+1.6; //where ( b =0.23,, d =0.22, e =0, f=1.6 )


      }
      else if(num<99) // 7% of times choose coordinate transformation with f4.
        {
        px=-0.15*tempx+0.28*tempy; //where (a= -0.15, c =0.28)
        py=0.26*tempx+0.24*tempy+0.44; //where ( b =0.26,d =0.24, e =0, f=0.44 )

      }
    else // 1% of times choose coordinate transformation with f1.
        {

            px=0*tempx; //where (a=0, c=0)
            py=0.16*tempy; //where (b =0, d =0.16, e =0, f=0 )

    }
    tempx=px;
    tempy=py;
glBegin(GL_POINTS);
glVertex3f(px,py,0);
glEnd();

  }




  glFlush();                           // clear buffer
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :                       // esc key to exit
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250);                //window screen
   glutInitWindowPosition (100, 100);            //window position
   glutCreateWindow ("Program1");                //program title
   init();
   glutDisplayFunc(display);                     //callback function for display
   glutReshapeFunc(resize);                      //callback for reshape
   glutKeyboardFunc(key);                        //callback function for keyboard
   glutMainLoop();                               //loop

    return EXIT_SUCCESS;
}
