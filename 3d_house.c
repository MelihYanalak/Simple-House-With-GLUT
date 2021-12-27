




#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

float camera = -0.0f;
int isDebug = 0;
float angle = 180.0f;
float angle2 = 0.0f;
float angle3 = 0.0f;
float camera2=-1.5f;
float zoom=110.0;

void handleResize(int w, int h);
void drawToScreen();
void keyboardHandler(unsigned char key, int x, int y);
int main(int argc, char * * argv) {
    int flags = GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH;
    glutInit( & argc, argv);
    glutInitDisplayMode(flags);
    glutInitWindowSize(900, 800);
    glutCreateWindow("GTU 3D House");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawToScreen);
    glutKeyboardFunc(keyboardHandler);
    glutReshapeFunc(handleResize);
    glutMainLoop();
    return 0;
}







void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(zoom, (double) w / (double) h, 1.0, 200.0);
}


void drawToScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glClearColor( 0.196078 , 0.4 , 0.8, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-camera, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, camera2, -2.0f);

    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glRotatef(angle2, 0.1f, 0.0f, 0.0f);
    glRotatef(angle3, 0.0f, 0.0f, 1.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    glLineWidth(10);







    // main shape
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.858824 , 0.576471 , 0.439216);
    glBegin(GL_POLYGON);
    glVertex3f (-0.6, 0.0, 0.0);
    glVertex3f (0.6, 0.0, 0.0);
    glVertex3f (0.6, 1.0, 0.0);
    glVertex3f (-0.6, 1.0, 0.0);
    glEnd();


    glColor3f (0.858824 , 0.576471 , 0.439216);
    glBegin(GL_POLYGON);
    glVertex3f (-0.6,0.0, 0.7);
    glVertex3f (0.6,0.0, 0.7);
    glVertex3f (0.6,1.0, 0.7);
    glVertex3f (-0.6,1.0, 0.7);
    glEnd();


    glColor3f (0.858824 , 0.576471 , 0.439216);
    glBegin(GL_POLYGON);
    glVertex3f (-0.6, 0.0, 0.7);
    glVertex3f (-0.6, 0.0, 0.0);
    glVertex3f (-0.6, 1.0, 0.0);
    glVertex3f (-0.6, 1.0, 0.7);
    glEnd();


    glColor3f (0.858824 , 0.576471 , 0.439216);
    glBegin(GL_POLYGON);
    glVertex3f (0.6, 0.0, 0.7);
    glVertex3f (0.6, 0.0, 0.0);
    glVertex3f (0.6, 1.0, 0.0);
    glVertex3f (0.6,1.0, 0.7);
    glEnd();

    // roof

    glColor3f (0.6, 0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.6, 1.0, 0);
    glVertex3f (0.6, 1.0, 0.7);
    glVertex3f (0.6, 1.4, 0.35);
glEnd();

    glColor3f (0.6, 0,0);
    glBegin(GL_TRIANGLES);
    glVertex3f (-0.6, 1, 0);
    glVertex3f (-0.6, 1, 0.70);
    glVertex3f (-0.6, 1.4, 0.35);
    glEnd();


    glColor3f (0.6, 0,0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.6, 1, 0);
    glVertex3f (0.6, 1, 0);
    glVertex3f (0.6, 1.4, 0.35);
    glVertex3f (-0.6, 1.4, 0.35);
    glEnd();


    glColor3f (0.6, 0,0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.6, 1,0.7);
    glVertex3f (0.6, 1, 0.7);
    glVertex3f (0.6, 1.4, 0.35);
    glVertex3f (-0.6, 1., 0.35);
    glEnd();

    // door
    glColor3f (0.35, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f (-0.15, 0, -0.01);
    glVertex3f (0.15, 0, -0.01);
    glVertex3f (0.15, 0.40, -0.01);
    glVertex3f (-0.15, 0.40, -0.01);
    glEnd();

    // windows
    glColor3f ( 0.40 , 0.60 , 0.847059);
    glBegin(GL_POLYGON);
    glVertex3f (-0.4, 0.6, -0.01);
    glVertex3f (-0.15, 0.6, -0.01);
    glVertex3f (-0.15, 0.8, -0.01);
    glVertex3f (-0.4, 0.8, -0.01);
    glEnd();


    glColor3f ( 0.40 , 0.60 , 0.847059);
    glBegin(GL_POLYGON);
    glVertex3f (0.15, 0.6, -0.01);
    glVertex3f (0.4, 0.6, -0.01);
    glVertex3f (0.4, 0.8, -0.01);
    glVertex3f (0.15, 0.8, -0.01);
    glEnd();


glEnd();

// the ground


glColor3f (0, 0.6, 0);
    glBegin(GL_POLYGON);
    glVertex3f (-5, 0, -5);
    glVertex3f (5, 0, -5);
    glVertex3f (5, 0,5);
    glVertex3f (-5, 0, 5);
    glEnd();


    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
}


void keyboardHandler(unsigned char key, int x, int y) {
    switch (key) {

    case 's':
	    if (camera2 < -2.0) {
	      camera2+=0.2;
	    }


	      glutPostRedisplay();


	      break;

    case 'w':

	      camera2-=0.2;

	      glutPostRedisplay();


	      break;
    case 'a':

	       angle += 10.0f;
	      if (angle > 360) {
		  angle -= 360;
	      }
	      glutPostRedisplay();


	      break;

    case 'd':

	       angle -= 10.0f;
	      if (angle > 360) {
		  angle -= 360;
	      }
	      glutPostRedisplay();


	      break;



     case 'k':

       angle2 -= 10.0f;
      if (angle > 360) {
          angle -= 360;
      }
      glutPostRedisplay();


      break;
     case 'm':

       angle2 += 10.0f;
      if (angle > 360) {
          angle -= 360;
      }
      glutPostRedisplay();


      break;

    


    default:
      break;



    }


}
