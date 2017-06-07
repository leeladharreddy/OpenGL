//Name: Leeladhar Munnangi
//ID  : 109510225
//Class : CSCI 272
//Project Name : Bezier Curve

#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <iostream>
using std::cerr;
using std::endl;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;
/* GLUT callback Handlers */




const int numcontrolpts = 4;  // Number of control points

bool curve1=false;  /*Creating Boolean values*/
bool curve2=false;
bool curve3=false;
bool curve4=false;
bool curve5=false;



int numdrawsegs = 30;  /* number of segments that has to be drawn */

const int startwinsize = 600;  /*Window size*/

GLfloat point1[numcontrolpts][3] = {    /*Creating Control point1 as an array with 4 Quadrants and 3 coordinate axis*/
   {-0.7, -0.7,  0.0},
   {-0.4,  0.4,  0.0},
   { 0.5,  0.5,  0.0},
   { 0.9, -0.9,  0.0}
};
GLfloat point2[numcontrolpts][3] = {    /*Creating Control point2 as an array with 4 Quadrants and 3 coordinate axis*/
   {-0.2, -0.2,  0.0},
   {-0.5,  0.5,  0.0},
   { 0.7,  0.6,  0.0},
   { 0.2, -0.2,  0.0}
};
GLfloat point3[numcontrolpts][3] = {     /*Creating Control point3 as an array with 4 Quadrants and 3 coordinate axis*/
   { 0.2, -0.2,  0.0},
   {-0.5,  0.5,  0.0},
   { 0.7,  0.6,  0.0},
   {-0.2, -0.2,  0.0}
};
GLfloat point4[numcontrolpts][3] = {     /*Creating Control point4 as an array with 4 Quadrants and 3 coordinate axis*/
   {-0.7, -0.5,  0.0},
   {-0.3,  0.4,  0.0},
   { 0.5, -0.8,  0.0},
   { 0.8,  0.3,  0.0}
};
GLfloat point5[5][3] = {                 /*Creating Control point5 as an array with 5 Quadrants and 3 coordinate axis*/
   {-0.85, -0.5,  0.0},
   {-0.3,  0.4,  0.0},
   { 0.5, -0.8,  0.0},
   { 0.9,  0.4,  0.0},
   { 0.2,  0.2,  0.0}

};

void init()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0);           // adjusted for suitable viewport
  glClearColor(1.0, 1.0, 1.0, 0.0);              // set background color
glFlush();                                       //clear buffer

}

// The GLUT display function
void display(void)
{
    int i;
   glClear(GL_COLOR_BUFFER_BIT);             // Clear screen

   if(curve1)                                /*if curve1=true enter the loop*/
   {
      glColor3d(1.0, 0.0, 0.0);              /*coloring coordinate point in the display*/
      glPointSize(10.0);                     /*size of the coordinate point in the display*/
      glBegin(GL_POINTS);                    /*display the points*/
         for (i=0; i<numcontrolpts; ++i)
            glVertex3fv(point1[i]);          /*This function is calculates the point on the curve*/
      glEnd();
   glColor3d(0.0, 0.0, 1.0);                 /*Color of the curve*/
   glLineWidth(3.0);                         /*Line width*/
   glEvalMesh1(GL_LINE, 0, numdrawsegs);     /*defines the type, starting point and ending point*/
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0,3,numcontrolpts,&point1[0][0]); /* This has parameters target, min, max, stride, order
                                                                         point_array*/
   glEnable(GL_MAP1_VERTEX_3);               /*this function allows to draw a curve to the target*/
   glMapGrid1d(numdrawsegs, 0.0, 1.0);       /* Number of drawing segments, min, max values*/
   }

   if(curve2)                                /*if curve2=true enter the loop*/
   {
      glColor3d(1.0, 0.0, 0.0);              /*coloring coordinate point in the display*/
      glPointSize(10.0);                     /*size of the coordinate point in the display*/
      glBegin(GL_POINTS);                    /*display the points*/
         for (i=0; i<numcontrolpts; ++i)
            glVertex3fv(point2[i]);          /*This function is calculates the point on the curve*/
      glEnd();
   glColor3d(0.0, 0.0, 1.0);                 /*Color of the curve*/
   glLineWidth(3.0);                         /*Line width*/
   glEvalMesh1(GL_LINE, 0, numdrawsegs);     /*defines the type, starting point and ending point*/
   glMap1f(GL_MAP1_VERTEX_3,0.0, 1.0,3,numcontrolpts,&point2[0][0]); /* This has parameters target, min, max, stride, order
                                                                         point_array*/
   glEnable(GL_MAP1_VERTEX_3);               /*this function allows to draw a curve to the target*/
   glMapGrid1d(numdrawsegs, 0.0, 1.0);       /* Number of drawing segments, min, max values*/

   }

   if(curve3)                                        /*if curve2=true enter the loop*/
   {
      glColor3d(1.0, 0.0, 0.0);                      /*coloring coordinate point in the display*/
      glPointSize(10.0);                             /*size of the coordinate point in the display*/
      glBegin(GL_POINTS);                            /*display the points*/
         for (i=0; i<numcontrolpts; ++i)
            glVertex3fv(point3[i]);                  /*This function is calculates the point on the curve*/
      glEnd();
   glColor3d(0.0, 0.0, 1.0);                         /*Color of the curve*/
   glLineWidth(3.0);                                 /*Line width*/
   glEvalMesh1(GL_LINE, 0, numdrawsegs);             /*defines the type, starting point and ending point*/
   glMap1f(GL_MAP1_VERTEX_3,0.0, 1.0,3,numcontrolpts,&point3[0][0]);   /* This has parameters target, min, max, stride, order
                                                                         point_array*/
   glEnable(GL_MAP1_VERTEX_3);                     /*this function allows to draw a curve to the target*/
   glMapGrid1d(numdrawsegs, 0.0, 1.0);             /* Number of drawing segments, min, max values*/
   }

if(curve4)                                           /*if curve4=true enter the loop*/
   {
      glColor3d(1.0, 0.0, 0.0);                      /*coloring coordinate point in the display*/
      glPointSize(10.0);                             /*size of the coordinate point in the display*/
      glBegin(GL_POINTS);                            /*display the points*/
         for (i=0; i<numcontrolpts; ++i)
            glVertex3fv(point4[i]);                  /*This function is calculates the point on the curve*/
      glEnd();
   glColor3d(0.0, 0.0, 1.0);                         /*Color of the curve*/
   glLineWidth(3.0);                                 /*Line width*/
   glEvalMesh1(GL_LINE, 0, numdrawsegs);             /*defines the type, starting point and ending point*/
   glMap1f(GL_MAP1_VERTEX_3,0.0, 1.0,3,numcontrolpts,&point4[0][0]);   /* This has parameters target, min, max, stride, order
                                                                         point_array*/
   glEnable(GL_MAP1_VERTEX_3);                  /*this function allows to draw a curve to the target*/
   glMapGrid1d(numdrawsegs, 0.0, 1.0);          /* Number of drawing segments, min, max values*/
   }

   if(curve5)                                   /*if curve5=true enter the loop*/
   {
      glColor3d(1.0, 0.0, 0.0);                 /*coloring coordinate point in the display*/
      glPointSize(10.0);                        /*size of the coordinate point in the display*/
      glBegin(GL_POINTS);                       /*display the points*/
         for (i=0; i<5; ++i)
            glVertex3fv(point5[i]);             /*This function is calculates the point on the curve*/
      glEnd();
   glColor3d(0.0, 0.0, 1.0);                    /*Color of the curve*/
   glLineWidth(3.0);                            /*Line width*/
   glEvalMesh1(GL_LINE, 0, numdrawsegs);        /*defines the type, starting point and ending point*/
   glMap1f(GL_MAP1_VERTEX_3,0.0, 1.0,3,5,&point5[0][0]);    /* This has parameters target, min, max, stride, order
                                                                         point_array*/
   glEnable(GL_MAP1_VERTEX_3);                   /*this function allows to draw a curve to the target*/
   glMapGrid1d(numdrawsegs, 0.0, 1.0);           /* Number of drawing segments, min, max values*/
   }

   ostringstream out;     // Write instructions in drawing window
   string msg = out.str();
   glColor3d(0.0, 0.0, 0.0);
   glRasterPos2d(-0.95, 1.05);
   string::iterator ii;
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);

   msg = string("Curve 1 [")  // string message
       + (curve1 ? "X" : " ")
       + "]";
   glColor3d(0.9, 0.1, 0.1);       //color of the message
   glRasterPos2d(-0.95, 0.95);     //position of the message in the display
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);

   msg = string("Curve 2 [")    // string message
       + (curve2 ? "X" : " ")
       + "]";
   glColor3d(0.1, 0.7, 0.1);     //color of the message
   glRasterPos2d(-0.95, 0.85);    //position of the message in the display
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);

   msg = string("Curve 3 [")    // string message
       + (curve3 ? "X" : " ")
       + "]";
   glColor3d(0.9, 0.1, 0.9);     //color of the message
   glRasterPos2d(-0.95, 0.75);     //position of the message in the display
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);

   msg = string("Curve 4 [")    // string message
       + (curve4 ? "X" : " ")
       + "]";
   glColor3d(0.1, 0.1, 0.9);      //color of the message
   glRasterPos2d(-0.95, 0.65);    //position of the message in the display
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);

      msg = string("Curve 5 [")    // string message
       + (curve5 ? "X" : " ")
       + "]";
   glColor3d(0.8, 0.6, 0.2);     //color of the message
   glRasterPos2d(-0.95, 0.55);   //position of the message in the display
   for (ii=msg.begin(); ii!=msg.end(); ++ii)
      glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);


   glutSwapBuffers();

}



// The GLUT reshape function
void reshape(int w, int h)
{
   glViewport(0, 0, w, h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w > h)
   {
      gluOrtho2D(-double(w)/h, double(w)/h, -1., 1.);
   }
   else
   {
      gluOrtho2D( -1., 1., -double(h)/w, double(h)/w);
   }

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


// The GLUT keyboard function
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 27:
      exit(0);
      break;
    case '1':
      curve1=true;              /*In case 1 only Curve is true rest all are false */
      curve2=false;
      curve3=false;
      curve4=false;
      curve5=false;
      glutPostRedisplay();
      break;
   case '2':
      curve1=false;
      curve2=true;               /*In case 2 only Curve 2 is true rest all are false */
      curve3=false;
      curve4=false;
      curve5=false;
      glutPostRedisplay();
      break;
       case '3':
      curve1=false;
      curve2=false;
      curve3=true;                /*In case 3 only Curve 3 is true rest all are false */
      curve4=false;
      curve5=false;
      glutPostRedisplay();
      break;
       case '4':
      curve1=false;
      curve2=false;
      curve3=false;
      curve4=true;                 /*In case 4 only Curve 4 is true rest all are false */
      curve5=false;
      glutPostRedisplay();
      break;
      case '5':
      curve1=false;
      curve2=false;
      curve3=false;
      curve4=false;
      curve5=true;                 /*In case 5  only Curve 5 is true rest all are false */
      glutPostRedisplay();
      break;

   }
}

int main(int argc, char ** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);                        //window screen
   glutInitWindowPosition(100, 100);                    //window position
   glutCreateWindow("Bezier Curve");                    //program title
   init();
   glutDisplayFunc(display);                            //callback function for display
   glutReshapeFunc(reshape);                            //callback for reshape
   glutKeyboardFunc(keyboard);                          //callback for keyboard
   glutMainLoop();                                      //loop

   return EXIT_SUCCESS;
}
