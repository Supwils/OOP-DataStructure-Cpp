/////////////////////////////////////////////////////////////////////
// circleAndMore.cpp
//
// Draw a 6 sided circle (aka hexagon) and a rectangle per Exercise

//
// Interaction:
//
//
// Baruch and you
/////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265358979324

using namespace std;

// Globals.
bool x11WorkAround = true;  //***X11Fix
int windowHeight=400;   //***X11Fix
int windowWidth=400;   //***X11Fix
static float R = 40.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 5; // Number of vertices on circle.

// Drawing routine.
void drawScene(void)
{
    // *********  x11Fix begin chunk
    if(x11WorkAround)
    {
        glutReshapeWindow(windowWidth-1,windowHeight-1);// Has to be different dimensions than in glutInitWindowSize();
        x11WorkAround = false;
    }
    //*********** x11Fix end chunk
   float t = 0; // Angle parameter.
   int i;

   //Set viewing box
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, 20.0,0.0, 20.0, -1.0,20.0);  //*********needs values************
   
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();

  

   //Display the background
   glClear(GL_COLOR_BUFFER_BIT);


   //Draw a green rectangle
   glColor3f(0,1,0);  //*********needs values************
  

   glBegin(GL_POLYGON);
       glVertex3f(10,5,0);  //*********needs values************
       glVertex3f(18,5,0);  //*********needs values************
       glVertex3f(18,7,0);  //*********needs values************
       glVertex3f(10,7,0);  //*********needs values************
   glEnd();



   // Draw a light blue hexagon
   glLineWidth(5);
   glColor3f(0,0,1);  //*********needs values************
   glBegin(GL_LINE_LOOP);
      for(i = 0; i < numVertices ; ++i)  //*********needs a value************
      {
          
         glVertex3f( 15 +  5 * cos(t), 10 + 5  * sin(t), 0 );  //*********needs values************
         t += 2 * PI / numVertices;  //*********needs a value************
      }
   glEnd();

   glFlush();
}

// Initialization routine.
void setup(void)
{    //light yellow background
   glClearColor(1.0, 1.0, 0.0, 0.0); //*********needs values************
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   //glOrtho moved to drawScene
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch(key)
   {
      case 27:
         exit(0);
         break;
     
      default:
         break;
   }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
   cout << "Interaction:" << endl;
   cout << "Press escape to quit" << endl;
}

// Main routine.
int main(int argc, char **argv)
{
   printInteraction();
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("circleAndMore.cpp");
   setup();
   glutDisplayFunc(drawScene);
   glutReshapeFunc(resize);
   glutKeyboardFunc(keyInput);
   glutMainLoop();

   return 0;
}
