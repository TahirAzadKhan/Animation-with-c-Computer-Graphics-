#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
using namespace std;
float _move = 0.0f;
float _angle = 0.0f;
float _move1 = 0.0f;
float _angle1 = 0.0f;
float _move2 = 0.0f;
float _move3 = 0.0f;
float _move4 = 0.2f;
float _move5 = 0.0f;
float _angle5 = 0.0f;
float _move6 = 0.0f;

GLfloat pos1 = 0.0f;
GLfloat pos2 = 0.0f;
GLfloat s1 = 0.01f;
GLfloat s2 = 0.01f;

bool fly = false;
bool ron = false;

float _angle3 = 0.0f;

GLfloat position = 0.0f;
GLfloat speed = 0.1f;

float _angle2 = 0.0f;
float pos = 1.5f;
bool trainRun = false;

bool run = false;
bool start = false;
bool night = false;
float _nt = 0.0;
bool fall = false;

bool mill = false;
bool frd = false;

void but(int value)
{
    if (ron)
    {
        _angle3+=7.0f;
        if(_angle3 > 360.0)
        {
            _angle3-=360;
        }
        _move3 -= .02;
        if(_move3 < -1.2)
        {
            _move3 = 1.2;
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, but, 0); //Notify GLUT to call update again in 25 milliseconds
}

void but2(int value)
{
    if (ron)
    {
        _angle3+=7.0f;
        if(_angle3 > 360.0)
        {
            _angle3-=360;
        }
        _move4 -= .02;
        if(_move4 < -1.2)
        {
            _move4 = 1.2;
        }
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, but2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void planeforward (int value)
{
    if(frd)
    {
        pos -= 0.01f;
        if (pos < -1.5)
        {
            pos = 2.0;
            frd= false;
        }
        glutPostRedisplay();
        glutTimerFunc(25, planeforward, 0);
    }
}
void Night(int value)
{
    if(night)
    {
        glClearColor(0.098,0.098,0.439,0.0);
        glutPostRedisplay();
        glutTimerFunc(1, Night, 0);
        glFlush();
    }
}

void update(int value)
{
    if (run)
    {
        _angle+=2.0f;
        if(_angle > 5.0)
        {
            _angle-=5;
        }
        _move += .02;
        if(_move > 5)
        {
            _move = 0;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(200, update, 0);
}

void update1(int value)
{
    if (start)
    {
        _angle1-=5.0f;
        if(_angle1 > 360.0)
        {
            _angle1-=360;
        }
        _move1 += .02;
        if(_move1 > 5)
        {
            _move1 = -1.0;
        }
    }
    glutPostRedisplay();
	glutTimerFunc(60, update1, 0);
}

void update2(int value)
{
    if(trainRun)
    {
        _move2 += .03;
        if(_move2 > 100)
        {
            _move2 = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(200, update2, 0);
}

void update3(int value)
{
    if(fall)
    {
        if(position <-1.0)
        {
             position = 1.0f;
        }
    else if(position > 1)
    {
        position = - 1.0f ;
    }

    position -= speed;

    }

	glutPostRedisplay();
	glutTimerFunc(500, update3, 0);
}

void update4(int value) {
    if(mill){

 _angle2+=7.0f;
if(_angle2 > 360.0)
{
_angle2-=360;
}
    }
glutPostRedisplay();
 glutTimerFunc(20, update4, 0);
}

void update5(int value) {
    if(fly)
{

    _angle5+= 1.5f;
    if(_angle5 > 360.0)
    {
        _angle5-=360;
    }


	_move5 -= .02;
    if(_move5 < -1.5)
    {
        _move5 = +1.5;
    }
}
    glutPostRedisplay();
    glutTimerFunc(100, update5, 0);

}

void up1(int value) {
    if(pos1 <0.15)
        pos1 = 0.15f;
    pos1 += s1;
	glutPostRedisplay();
	glutTimerFunc(90, up1, 0);
}

void Boat()  
{
    glPushMatrix();
    glTranslatef(pos2,0.0f, 0.0f);
    glScalef(0.95,0.65,0.0);
    glPushMatrix();

	glBegin(GL_QUADS);
	glColor3ub(0.0f, 0.0f, 0.0f);
	glVertex2f(.12f, -.54f);
	glVertex2f(.1f, -.6f);
	glVertex2f(.5f, -.6f);
	glVertex2f(.55f, -.54f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.17f, -.48f);
	glVertex2f(.17f, -.54f);
	glVertex2f(.3f, -.54f);
	glVertex2f(.27f, -.48f);
	glEnd();

	glBegin(GL_QUADS);                 //window
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.175f, -.485f);
	glVertex2f(.175f, -.51f);
	glVertex2f(.20f, -.51f);
	glVertex2f(.20f, -.485f);
	glEnd();


    glBegin(GL_QUADS);                 //window
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.205f, -.485f);
	glVertex2f(.205f, -.51f);
	glVertex2f(.23f, -.51f);
	glVertex2f(.23f, -.485f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.235f, -.485f);
	glVertex2f(.235f, -.51f);
	glVertex2f(.28f, -.51f);
	glVertex2f(.265f, -.485f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(139.0f, 0.0f, 0.0f);
	glVertex2f(.2f, -.54f);
	glVertex2f(.2f, -.6f);
	glVertex2f(.42f, -.6f);
	glVertex2f(.43f, -.57f);
	glVertex2f(.42f, -.54f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.18f, -.44f);
	glVertex2f(.27f, -.435f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.18f, -.44f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.27f, -.435f);
    glVertex2f(.35f, -.48f);
    glVertex2f(.35f, -.165f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.25f, -.435f);
    glVertex2f(.30f, -.44f);
    glVertex2f(.35f, -.165f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.352f, -.28f);
	glVertex2f(.365f, -.35f);
	glVertex2f(.50f, -.53f);
	glVertex2f(.352f, -.28f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.365f, -.35f);
	glVertex2f(.365f, -.41f);
    glVertex2f(.50f, -.53f);
    glVertex2f(.365f, -.35f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.365f, -.41f);
	glVertex2f(.352f, -.48f);
    glVertex2f(.50f, -.53f);
    glVertex2f(.365f, -.41f);
	glEnd();

    glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(.495f, -.53f);
	glVertex2f(.495f, -.541f);

	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.35f, -.17f);
	glVertex2f(.35f, -.54f);

	glEnd();

    glLineWidth(3.0);
	glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.18f, -.44f);
	glVertex2f(.35f, -.48f);

	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(.35f, -.17f);
	glVertex2f(.545f, -.54f);

	glEnd();
    glPopMatrix();
    glPopMatrix();

}

void Boat2()  
{
    glPushMatrix();
    glTranslatef(pos1,0.0f, 0.0f);
    glScalef(0.65,0.35,0.0);
    glPushMatrix();

	glBegin(GL_QUADS);
	glColor3ub(0.0f, 0.0f, 0.0f);
	glVertex2f(.12f, -.54f);
	glVertex2f(.1f, -.6f);
	glVertex2f(.5f, -.6f);
	glVertex2f(.55f, -.54f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.17f, -.48f);
	glVertex2f(.17f, -.54f);
	glVertex2f(.3f, -.54f);
	glVertex2f(.27f, -.48f);
	glEnd();

	glBegin(GL_QUADS);                 //window
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.175f, -.485f);
	glVertex2f(.175f, -.51f);
	glVertex2f(.20f, -.51f);
	glVertex2f(.20f, -.485f);
	glEnd();


    glBegin(GL_QUADS);                 //window
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.205f, -.485f);
	glVertex2f(.205f, -.51f);
	glVertex2f(.23f, -.51f);
	glVertex2f(.23f, -.485f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(169.0f, 169.0f, 269.0f);
	glVertex2f(.235f, -.485f);
	glVertex2f(.235f, -.51f);
	glVertex2f(.28f, -.51f);
	glVertex2f(.265f, -.485f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(139.0f, 0.0f, 0.0f);
	glVertex2f(.2f, -.54f);
	glVertex2f(.2f, -.6f);
	glVertex2f(.42f, -.6f);
	glVertex2f(.43f, -.57f);
	glVertex2f(.42f, -.54f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.18f, -.44f);
	glVertex2f(.27f, -.435f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.18f, -.44f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.27f, -.435f);
    glVertex2f(.35f, -.48f);
    glVertex2f(.35f, -.165f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.35f, -.165f);
	glVertex2f(.25f, -.435f);
    glVertex2f(.30f, -.44f);
    glVertex2f(.35f, -.165f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.352f, -.28f);
	glVertex2f(.365f, -.35f);
	glVertex2f(.50f, -.53f);
	glVertex2f(.352f, -.28f);
	glEnd();


    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.365f, -.35f);
	glVertex2f(.365f, -.41f);
    glVertex2f(.50f, -.53f);
    glVertex2f(.365f, -.35f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(178.0f, 34.0f, 34.0f);
	glVertex2f(.365f, -.41f);
	glVertex2f(.352f, -.48f);
    glVertex2f(.50f, -.53f);
    glVertex2f(.365f, -.41f);
	glEnd();

    glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(.495f, -.53f);
	glVertex2f(.495f, -.541f);

	glEnd();

	glLineWidth(3.0);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.35f, -.17f);
	glVertex2f(.35f, -.54f);

	glEnd();

    glLineWidth(3.0);
	glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(.18f, -.44f);
	glVertex2f(.35f, -.48f);

	glEnd();

	glLineWidth(1.0);
	glBegin(GL_LINES);
	glColor3f(255.0f, 0.0f, 0.0f);
	glVertex2f(.35f, -.17f);
	glVertex2f(.545f, -.54f);

	glEnd();
    glPopMatrix();
    glPopMatrix();

}

void River()  
    {

      glBegin(GL_POLYGON);

      glColor3ub(65, 175, 255);
      glVertex2f(1.0f, -0.1f);
      glVertex2f(0.15f, -0.1f);
      glVertex2f(0.0f, -0.2f);
      glVertex2f(0.1f, -0.35f);
      glVertex2f(-0.10f, -0.48f);
      glVertex2f(1.0f, -0.48f);
      glVertex2f(1.0f, 0.0f);
    glEnd();
    }

void butterfly()   
{


    glPushMatrix();




glTranslatef(_move3, 0.1f, 0.0f);
 glRotatef(_angle3, 1.0f, 0.0f,0.0f);
 glScalef(0.1f, 0.1f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.4f, 0.9f);

glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.3f);
glVertex2f(0.3f, -0.3f);


glEnd();



glBegin(GL_POLYGON);
glColor3f(0.0f, 0.4f, 0.9f);

glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, 0.3f);
glVertex2f(0.3f, 0.3f);


 glEnd();


glPopMatrix();


glFlush();

}

void butterfly2()  
{


    glPushMatrix();




glTranslatef(_move3, 0.2f, 0.0f);
 glRotatef(_angle3, 1.0f, 0.0f,0.0f);
 glScalef(0.1f, 0.1f, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.4f, 0.9f);

glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.3f);
glVertex2f(0.3f, -0.3f);


glEnd();



glBegin(GL_POLYGON);
glColor3f(0.0f, 0.4f, 0.9f);

glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, 0.3f);
glVertex2f(0.3f, 0.3f);


 glEnd();


glPopMatrix();


glFlush();

}


void plane()  
{
        glPushMatrix();
glTranslatef(pos,0.79f, 0.0f);
glScalef(0.2f, 0.2f, 0.0f);

    glBegin(GL_POLYGON);

glColor3f(0, 255, 255);

glVertex2f(-0.7f, 0.3f);
glVertex2f(-0.9f, 0.4f);
glVertex2f(-0.6f, 0.6f);
glVertex2f(0.6f,0.6f);
glVertex2f(1.0f, 0.5f);
glVertex2f(0.7f, 0.3f);
glVertex2f(-0.7f,0.3f);

 glEnd();

 glBegin(GL_POLYGON);

glColor3f(0, 0, 255);


glVertex2f(0.6f,0.6f);
glVertex2f(0.65f, 0.7f);
glVertex2f(0.8f, 1.0f);
glVertex2f(0.9f,1.0f);
glVertex2f(0.9f,0.52f);
 glEnd();


glBegin(GL_POLYGON);

glColor3f(0, 0, 255);


glVertex2f(-0.2f,0.4f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.8f, 0.0f);

glVertex2f(0.8f,-0.05f);
glVertex2f(-0.2f, 0.4f);

 glEnd();





glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.73f,0.5f);
glVertex2f(-0.6f, 0.5f);
glVertex2f(-0.6f, 0.45f);

glVertex2f(-0.82f,0.45f);


 glEnd();

 glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.73f,0.5f);
glVertex2f(-0.6f, 0.5f);
glVertex2f(-0.6f, 0.45f);

glVertex2f(-0.82f,0.45f);


 glEnd();

glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.5f,0.5f);
glVertex2f(-0.45f, 0.5f);
glVertex2f(-0.45f, 0.45f);
glVertex2f(-0.5f,0.45f);


 glEnd();
 glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.4f,0.5f);
glVertex2f(-0.35f, 0.5f);
glVertex2f(-0.35f, 0.45f);
glVertex2f(-0.4f,0.45f);


 glEnd();

 glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.3f,0.5f);
glVertex2f(-0.25f, 0.5f);
glVertex2f(-0.25f, 0.45f);
glVertex2f(-0.3f,0.45f);


 glEnd();
  glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(-0.2f,0.5f);
glVertex2f(-0.15f, 0.5f);
glVertex2f(-0.15f, 0.45f);
glVertex2f(-0.2f,0.45f);


 glEnd();

 glBegin(GL_POLYGON);

glColor3f(255, 255, 255); //


glVertex2f(-0.1f,0.5f);
glVertex2f(-0.05f, 0.5f);
glVertex2f(-0.05f, 0.45f);
glVertex2f(-0.1f,0.45f);


 glEnd();
  glBegin(GL_POLYGON);

glColor3f(255, 255, 255); //


glVertex2f(0.0f,0.5f);
glVertex2f(0.05f, 0.5f);
glVertex2f(0.05f, 0.45f);
glVertex2f(0.0f,0.45f);


 glEnd();


  glBegin(GL_POLYGON);

glColor3f(255, 255, 255); //


glVertex2f(0.1f,0.5f);
glVertex2f(0.15f, 0.5f);
glVertex2f(0.15f, 0.45f);
glVertex2f(0.1f,0.45f);


 glEnd();

  glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(0.2f,0.5f);
glVertex2f(0.25f, 0.5f);
glVertex2f(0.25f, 0.45f);
glVertex2f(0.2f,0.45f);


 glEnd();


  glBegin(GL_POLYGON);

glColor3f(255, 255, 255);


glVertex2f(0.3f,0.5f);
glVertex2f(0.35f, 0.5f);
glVertex2f(0.35f, 0.45f);
glVertex2f(0.3f,0.45f);


 glEnd();




  glBegin(GL_POLYGON);

glColor3f(255, 255, 255); //


glVertex2f(0.4f,0.5f);
glVertex2f(0.45f, 0.5f);
glVertex2f(0.45f, 0.45f);
glVertex2f(0.4f,0.45f);


 glEnd();

  glBegin(GL_POLYGON);

glColor3f(255, 255, 255); //


glVertex2f(0.5f,0.5f);
glVertex2f(0.55f, 0.5f);
glVertex2f(0.55f, 0.45f);
glVertex2f(0.5f,0.45f);


 glEnd();

glPopMatrix();


}

void trafficLight()    
    {


    glLineWidth(7.5);

glPushMatrix();
glScalef(-0.45f, 0.5f, 0.0f);
glTranslatef(0.0, -0.5f, 0.0f);

	glPushMatrix();
	glTranslatef(0.618, 0.030f, 0.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.15f,0.0f);
	glVertex2f(0.15f,0.35f);
	glVertex2f(0.0f,0.35f);


	glEnd();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(0.7, 0.3, 0.8f);
    glLineWidth(7.5);

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.8f);

	glEnd();
    glPopMatrix();
    glPushMatrix();
	glTranslatef(0.7, 0.3, 0.8f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.000, 0.000, 0.000);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();

	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.7, 0.2, 0.8f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(1.000, 1.000, 0.000);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
    glPopMatrix();


    glPushMatrix();
	glTranslatef(0.7, 0.1, 0.8f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.000, 0.502, 0.000);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.04;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
    glPopMatrix();
        glPopMatrix();

}

void road()  
{


//road
    glBegin(GL_POLYGON);
	glColor3f(0.133, 0.545, 0.133);
	glVertex2f(-1.0f,-0.1f);
	glVertex2f(-1.0f,-0.8f);
	glVertex2f(1.0f,-0.8f);
	glVertex2f(1.0f,-0.1f);
	glEnd();





	glBegin(GL_POLYGON);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(-1.0f,-0.5f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,-0.5f);
	glEnd();
    glPushMatrix();
	glTranslatef(-1.0f, -.8f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.3f,0.0f);
	glVertex2f(0.3f,0.1f);
	glVertex2f(0.0f,0.1f);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(-0.4f, -.8f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.3f,0.0f);
	glVertex2f(0.3f,0.1f);
	glVertex2f(0.0f,0.1f);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(0.2f, -.8f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.3f,0.0f);
	glVertex2f(0.3f,0.1f);
	glVertex2f(0.0f,0.1f);
	glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(.8f, -.8f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.3f,0.0f);
	glVertex2f(0.3f,0.1f);
	glVertex2f(0.0f,0.1f);
	glEnd();
    glPopMatrix();


}



void human()  
{
glPushMatrix();
glTranslatef(-0.7,-0.25,1.0);



	glPushMatrix();
	glScalef(.5f,0.5f,1.0f);

	glPushMatrix();
//Thang
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f,-1.0f);
	glTranslatef(-0.05, -0.5, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.0f);
	glVertex2f(0.07f,0.25f);
	glVertex2f(0.0f,0.25f);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glRotatef(_angle, 0.0f, 0.0f,1.0f);
	glTranslatef(-0.02, -0.5, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.0f);
	glVertex2f(0.07f,0.25f);
	glVertex2f(0.0f,0.25f);
	glEnd();
    glPopMatrix();
    //matha
    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.941, 0.902, 0.549);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	  glPopMatrix();







    glPushMatrix();

//body

	glTranslatef(-0.07, -0.25, 0.0);
	glTranslatef(_move, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.000, 0.271, 0.000);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.14f,0.0f);
	glVertex2f(0.14f,0.20f);
	glVertex2f(0.0f,0.20f);
    glEnd();
//shamner hat
    glRotatef(_angle-30, 0.0f, 0.0f,1.0f);
	glTranslatef(-0.05, 0.13, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.20f,0.0f);
	glVertex2f(0.20f,0.05f);
	glVertex2f(0.0f,0.05f);
	glEnd();


  glPopMatrix();
glPopMatrix();



glPushMatrix();
   glTranslatef(-0.4f, -0.0f, 0.0f);
//Thang
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
	glRotatef(_angle, 0.0f, 0.0f,-1.0f);
	glTranslatef(-0.05, -0.5, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.0f);
	glVertex2f(0.07f,0.25f);
	glVertex2f(0.0f,0.25f);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glRotatef(_angle, 0.0f, 0.0f,1.0f);
	glTranslatef(-0.02, -0.5, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.07f,0.0f);
	glVertex2f(0.07f,0.25f);
	glVertex2f(0.0f,0.25f);
	glEnd();
    glPopMatrix();
    //matha
    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
   glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.941, 0.902, 0.549);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.05;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }

	glEnd();
	  glPopMatrix();


    glPushMatrix();


//body

	glTranslatef(-0.07, -0.25, 0.0);
	glTranslatef(_move, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.502, 0.000, 0.000);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.14f,0.0f);
	glVertex2f(0.14f,0.20f);
	glVertex2f(0.0f,0.20f);
    glEnd();
//shamner hat
    glRotatef(_angle-30, 0.0f, 0.0f,1.0f);
	glTranslatef(-0.05, 0.13, 0.0);
    glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.20f,0.0f);
	glVertex2f(0.20f,0.05f);
	glVertex2f(0.0f,0.05f);
	glEnd();


  glPopMatrix();

glPopMatrix();


glPopMatrix();
glPopMatrix();


}
void car()     
{
glPushMatrix();
glTranslatef(-0.9,-0.3,1.0);



	glPushMatrix();
    glTranslatef(_move1, 0.0f, 0.0f);
glPushMatrix();
glTranslatef(0.0f, -0.6f, 0.0f);
glScalef(0.5f, 0.5f, 0.0f);
	glPushMatrix();
	glScalef(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.000, 0.271, 0.000);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.9f, 0.0f);
glVertex2f(0.9f, 0.2f);
glVertex2f(0.7f, 0.2f);
glVertex2f(0.6f, 0.35f);
glVertex2f(0.4f, 0.35f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.0f, 0.2f);
	glEnd();
	 glTranslatef(0.55,0.27,1.0);
 glScalef(0.25,0.25,0.3);
 glBegin(GL_QUADS);

      glColor3f(1.000, 1.000, 0.000);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f( 0.2f, -0.2f);
      glVertex2f( 0.2f,  0.2f);
      glVertex2f(-0.2f,  0.2f);
    glEnd();
    glTranslatef(-0.45,-0.0,1.0);
 glBegin(GL_QUADS);

      glColor3f(1.000, 1.000, 0.000);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f( 0.2f, -0.2f);
      glVertex2f( 0.2f,  0.2f);
      glVertex2f(-0.2f,  0.2f);
    glEnd();
	glPopMatrix();





    glPushMatrix();
    glTranslatef(0.2, 0.0f, 0.0f);
    glScalef(0.2f, 0.2f, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.000, 0.000, 0.000);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.663, 0.663, 0.663);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.412, 0.412, 0.412);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.184, 0.310, 0.310);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.3f, 0.0f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.3f, 0.0f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.3f);

	glEnd();
    glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.3f);

	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.412, 0.412, 0.412);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glFlush();
    glPopMatrix();
    //second wheel


    glPushMatrix();
    glTranslatef(0.7, 0.0f, 0.0f);
    glScalef(0.2f, 0.2f, 0.0f);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.000, 0.000, 0.000);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.663, 0.663, 0.663);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.4;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.412, 0.412, 0.412);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.184, 0.310, 0.310);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.2;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.3f, 0.0f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.3f, 0.0f);

	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.3f);

	glEnd();
    glBegin(GL_LINES);
	glColor3f(0.502, 0.502, 0.502);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.3f);

	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(0.412, 0.412, 0.412);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.1;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }


	glEnd();
	glFlush();
    glPopMatrix();



 glPopMatrix();

glPopMatrix();
glPopMatrix();
}


void Hills()                       
  //Hills.................................
      {
          glPushMatrix();
          glScalef(0.01,0.01,0.0);
    glPushMatrix();
    glBegin(GL_TRIANGLES);                // Left side's first Hill
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(-80.0f, 40.0f);
	glVertex2f(-100.0f, -10.0f);
	glVertex2f(-60.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);                //Left side's second hill
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(-40.0f, 70.0f);
	glVertex2f(-85.0f, -10.0f);
	glVertex2f(0.0f, -10.0f);
	glEnd();

    glBegin(GL_TRIANGLES);                //Left side's third hill
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(0.0f, 80.0f);
	glVertex2f(-63.0f, -10.0f);
	glVertex2f(75.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);                //Right side's hill
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(75.0f, 70.0f);
	glVertex2f(30.0f, -10.0f);
	glVertex2f(100.0f, -10.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(176.0f, 196.0f, 222.0f);       //LightSteelBlue

	glVertex2f(-47.0f, 58.0f);
	glVertex2f(-80.0f, -10.0f);
	glVertex2f(-70.0f, -10.0f);
	glVertex2f(-47.0f, 58.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);        //LightSteelBlue

	glVertex2f(-40.0f, 70.0f);
	glVertex2f(-40.0f, -10.0f);
	glVertex2f(-30.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);       //LightSteelBlue

	glVertex2f(0.0f, 80.0f);
	glVertex2f(-10.0f, -10.0f);
	glVertex2f(0.0f, -10.0f);
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);       //LightSteelBlue

	glVertex2f(0.0f, 80.0f);
	glVertex2f(30.0f, -10.0f);
	glVertex2f(40.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);       //LightSteelBlue

	glVertex2f(75.0f, 70.0f);
	glVertex2f(50.0f, -10.0f);
	glVertex2f(55.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);        //LightSteelBlue

	glVertex2f(58.0f, 40.0f);
	glVertex2f(45.0f, -10.0f);
	glVertex2f(55.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);        //LightSteelBlue

	glVertex2f(-10.0f, 65.0f);
	glVertex2f(-35.0f, 15.0f);
	glVertex2f(-30.0f, 15.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);         //LightSteelBlue

    glVertex2f(75.0f, 70.0f);
    glVertex2f(85.0f, 15.0f);
	glVertex2f(90.0f, 15.0f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);        //LightSteelBlue

	glVertex2f(-80.0f, 40.0f);
	glVertex2f(-70.0f, -10.0f);
	glVertex2f(-60.0f, -10.0f);
	glEnd();
    glPopMatrix();
    glPopMatrix();
     }

void B_Railing()                     
     {
           glPushMatrix();
         glScalef(0.01,0.01,0.0);
    glPushMatrix();
    glLineWidth(2.5);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-100.0f, 32.0f);
    glVertex2f(100.0f, 32.0f);
	glEnd();

	glLineWidth(2.5);                      //  L1
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-90.0f, 32.0f);
    glVertex2f(-90.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                     //L2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-70.0f, 32.0f);
    glVertex2f(-70.0f, 25.0f);
	glEnd();


 	glLineWidth(2.5);                        // L3
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-50.0f, 32.0f);
    glVertex2f(-50.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                        //L4
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-30.0f, 32.0f);
    glVertex2f(-30.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                        //  L5
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-10.0f, 32.0f);
    glVertex2f(-10.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                        //L6
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(10.0f, 32.0f);
    glVertex2f(10.0f, 25.0f);
	glEnd();


 	glLineWidth(2.5);                        // L7
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(30.0f, 32.0f);
    glVertex2f(30.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                          //L8
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(50.0f, 32.0f);
    glVertex2f(50.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                          //  L9
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(70.0f, 32.0f);
    glVertex2f(70.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);                          //L10
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(90.0f, 32.0f);
    glVertex2f(90.0f, 25.0f);
	glEnd();
    glPopMatrix();
     glPopMatrix();
     }

     void Bridge()  
{
    glPushMatrix();
    glScalef(0.01,0.01,0.0);
    glPushMatrix();
    glBegin(GL_POLYGON);
	glColor3ub(128.0f, 0.0f, 128.0f);

	glVertex2f(-100.0f, 25.0f);
	glVertex2f(-100.0f, -10.0f);
	glVertex2f(100.0f, -10.0f);
	glVertex2f(100.0f, 25.0f);
	glEnd();

	//Tunnel L1..................................................

	 glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
           glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-80.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(-90.0f, 10.0f);
	glVertex2f(-90.0f, -10.0f);
	glVertex2f(-70.0f, -10.0f);
	glVertex2f(-70.0f, 10.0f);

	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(-70.0f, 12.0f);
	glVertex2f(-80.0f, -10.0f);
	glVertex2f(-70.0f, -10.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

glVertex2f(-90.0f, 12.0f);
	glVertex2f(-90.0f, 10.0f);
	glVertex2f(-88.0f, -10.0f);
	glVertex2f(-85.0f, -10.0f);

	glEnd();

     //Tunnel L2.....................................

      glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-50.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(-60.0f, 10.0f);
	glVertex2f(-60.0f, -10.0f);
	glVertex2f(-40.0f, -10.0f);
	glVertex2f(-40.0f, 10.0f);

	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(-40.0f, 10.0f);
	glVertex2f(-50.0f, -10.0f);
	glVertex2f(-45.0f, -10.0f);
	glVertex2f(-40.0f, 1.0f);
	glEnd();

     //Tunnel L3.................................

     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-20.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(-30.0f, 10.0f);
	glVertex2f(-30.0f, -10.0f);
	glVertex2f(-10.0f, -10.0f);
	glVertex2f(-10.0f, 10.0f);

	glEnd();

     //Tunnel L4..............................

     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(10.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(0.0f, 10.0f);
	glVertex2f(0.0f, -10.0f);
	glVertex2f(20.0f, -10.0f);
	glVertex2f(20.0f, 10.0f);

	glEnd();

	//Tunnel L5...........................................

	 glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(40.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(30.0f, 10.0f);
	glVertex2f(30.0f, -10.0f);
	glVertex2f(50.0f, -10.0f);
	glVertex2f(50.0f, 10.0f);

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(30.0f, 12.0f);
	glVertex2f(30.0f, -10.0f);
	glVertex2f(40.0f, -10.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(50.0f, 12.0f);
	glVertex2f(45.0f, -10.0f);
	glVertex2f(50.0f, -10.0f);
	glEnd();

	//Tunnel L6............................

	 glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(70.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(60.0f, 10.0f);
	glVertex2f(60.0f, -10.0f);
	glVertex2f(80.0f, -10.0f);
	glVertex2f(80.0f, 10.0f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(80.0f, 8.0f);
	glVertex2f(65.0f, -10.0f);
	glVertex2f(70.0f, -10.0f);
	glVertex2f(80.0f, 5.0f);
	glEnd();

	//Tunnel L7....(half)...............

	 glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(230.0f, 230.0f, 250.0f);  //Levender
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(100.0+x, 10+y);
        }
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(230.0f, 230.0f, 250.0f);  //Levender

	glVertex2f(90.0f, 10.0f);
	glVertex2f(90.0f, -10.0f);
	glVertex2f(100.0f, -10.0f);
	glVertex2f(100.0f, 10.0f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(176.0f, 196.0f, 222.0f);  //LightSteelBlue

	glVertex2f(90.0f, 12.0f);
	glVertex2f(90.0f, 4.0f);
	glVertex2f(93.0f, -10.0f);
	glVertex2f(98.0f, -10.0f);
	glEnd();
    glPopMatrix();
    glPopMatrix();
}



void Train()  
{


    glPushMatrix();
    glTranslatef(_move2,0.0f, 0.0f);

    //first Wagon.......................................................

    glBegin(GL_POLYGON);
	glColor3ub(153.0f, 50.0f, 204.0f);    //DarkOrchid

	glVertex2f(-.4f, .4f);
	glVertex2f(-.4f, .26f);
	glVertex2f(-.02f, .26f);
	glVertex2f(-.08f, .4f);
	glEnd();

    glBegin(GL_QUADS);                    //Window L1
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.39f, .35f);
	glVertex2f(-.39f, .3f);
	glVertex2f(-.36f, .3f);
	glVertex2f(-.36f, .35f);

	glEnd();

	glBegin(GL_QUADS);                     //Window L2
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.35f, .35f);
	glVertex2f(-.35f, .3f);
	glVertex2f(-.32f, .3f);
	glVertex2f(-.32f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L3
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.31f, .35f);
	glVertex2f(-.31f, .3f);
	glVertex2f(-.28f, .30f);
	glVertex2f(-.28f, .35f);

	glEnd();

    glBegin(GL_QUADS);                     //Window L4
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.27f, .35f);
	glVertex2f(-.27f, .30f);
	glVertex2f(-.24f, .30f);
	glVertex2f(-.24f, .35f);

	glEnd();

	glBegin(GL_QUADS);                     //Window L5
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.23f, .35f);
	glVertex2f(-.23f, .30f);
	glVertex2f(-.20f, .30f);
	glVertex2f(-.20f, .35f);

	glEnd();

	glBegin(GL_QUADS);                    //Window L6
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.19f, .35f);
	glVertex2f(-.19f, .30f);
	glVertex2f(-.16f, .30f);
	glVertex2f(-.16f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L7
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.15f, .35f);
	glVertex2f(-.15f, .30f);
	glVertex2f(-.12f, .30f);
	glVertex2f(-.12f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L8
    glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki
	glVertex2f(-.11f, .35f);
	glVertex2f(-.11f, .30f);
	glVertex2f(-.05f, .30f);
	glVertex2f(-.07f, .35f);

	glEnd();

    glLineWidth(3.5);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-.41f, .33f);
	glVertex2f(-.40f, .33f);

	glEnd();

    //second Wagon......................................................

	glBegin(GL_POLYGON);
	glColor3ub(153.0f, 50.0f, 204.0f);    //DarkOrchid

	glVertex2f(-.70f, .40f);
	glVertex2f(-.70f, .26f);
	glVertex2f(-.41f, .26f);
	glVertex2f(-.41f, .40f);
	glEnd();

    glBegin(GL_QUADS);                    //Window L1
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.69f, .35f);
	glVertex2f(-.69f, .30f);
	glVertex2f(-.66f, .30f);
	glVertex2f(-.66f, .35f);

	glEnd();

	glBegin(GL_QUADS);                     //Window L2
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.65f, .35f);
	glVertex2f(-.65f, .30f);
	glVertex2f(-.62f, .30f);
	glVertex2f(-.62f, .35f);

	glEnd();

    glBegin(GL_QUADS);                     //Window L3
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.61f, .35f);
	glVertex2f(-.61f, .30f);
	glVertex2f(-.58f, .30f);
	glVertex2f(-.58f, .35f);

	glEnd();

	glBegin(GL_QUADS);                    //Window L4
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.57f, .35f);
	glVertex2f(-.57f, .30f);
	glVertex2f(-.54f, .30f);
	glVertex2f(-.54f, .35f);

	glEnd();

    glBegin(GL_QUADS);                     //Window L5
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.53f, .35f);
	glVertex2f(-.53f, .30f);
	glVertex2f(-.50f, .30f);
	glVertex2f(-.50f, .35f);

	glEnd();

	glBegin(GL_QUADS);                     //Window L6
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.49f, .35f);
	glVertex2f(-.49f, .30f);
	glVertex2f(-.46f, .30f);
	glVertex2f(-.46f, .35f);

	glEnd();

    glBegin(GL_QUADS);                     //Window L7
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.45f, .35f);
	glVertex2f(-.45f, .30f);
	glVertex2f(-.42f, .30f);
	glVertex2f(-.42f, .35f);

	glEnd();

    glLineWidth(3.5);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-.71f, .33f);
	glVertex2f(-.70f, .33f);

	glEnd();

    //third Wagon..................................................

	glBegin(GL_POLYGON);
	glColor3ub(153.0f, 50.0f, 204.0f);    //DarkOrchid

	glVertex2f(-1.0f, .40f);
	glVertex2f(-1.0f, .26f);
	glVertex2f(-.71f, .26f);
	glVertex2f(-.71f, .40f);
	glEnd();

	glBegin(GL_QUADS);                    //Window L1
    glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.99f, .35f);
	glVertex2f(-.99f, .30f);
	glVertex2f(-.96f, .30f);
	glVertex2f(-.96f, .35f);

	glEnd();

	glBegin(GL_QUADS);                    //Window L2
    glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.95f, .35f);
	glVertex2f(-.95f, .30f);
	glVertex2f(-.92f, .30f);
	glVertex2f(-.92f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L3
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.91f, .35f);
	glVertex2f(-.91f, .30f);
	glVertex2f(-.88f, .30f);
	glVertex2f(-.88f, .35f);

	glEnd();

	glBegin(GL_QUADS);                    //Window L4
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.87f, .35f);
	glVertex2f(-.87f, .30f);
	glVertex2f(-.84f, .30f);
	glVertex2f(-.84f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L5
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.83f, .35f);
	glVertex2f(-.83f, .30f);
	glVertex2f(-.80f, .30f);
	glVertex2f(-.80f, .35f);

	glEnd();

	glBegin(GL_QUADS);                    //Window L6
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.79f, .35f);
	glVertex2f(-.79f, .30f);
	glVertex2f(-.76f, .30f);
	glVertex2f(-.76f, .35f);

	glEnd();

    glBegin(GL_QUADS);                    //Window L7
	glColor3ub(240.0f, 230.0f, 140.0f);   //Khaki

	glVertex2f(-.75f, .35f);
	glVertex2f(-.75f, .30f);
	glVertex2f(-.72f, .30f);
	glVertex2f(-.72f, .35f);

	glEnd();

    //..........**Wheel**............


	glLineWidth(.025);
	glBegin(GL_POLYGON);        //Wheel_L1
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.95+x, .265+y);
        }
	glEnd();




	glLineWidth(.025);
	glBegin(GL_POLYGON);        //Wheel_L2
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.85+x, .265+y);
        }
	glEnd();


	glLineWidth(.025);
	glBegin(GL_POLYGON);          //Wheel_L3
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.75+x, .265+y);
        }
	glEnd();



	glLineWidth(.025);
	glBegin(GL_POLYGON);            //Wheel_L4
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.650+x, .265+y);
        }
	glEnd();



	glLineWidth(.025);
	glBegin(GL_POLYGON);            //Wheel_L5
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.550+x, .265+y);
        }
	glEnd();


	glLineWidth(.025);
	glBegin(GL_POLYGON);        //L6
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.450+x, .265+y);
        }
	glEnd();



	glLineWidth(.025);
	glBegin(GL_POLYGON);        //Wheel_L7
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);  //Black......
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.355+x, .265+y);
        }
	glEnd();

                //L7................


	glLineWidth(.025);
	glBegin(GL_POLYGON);          //Wheel_L8
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.260+x, .265+y);
        }
	glEnd();


	glLineWidth(.025);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.165+x, .265+y);
        }
	glEnd();


	glLineWidth(.025);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=.015;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(-.075+x, .265+y);
        }
	glEnd();



    glPopMatrix();

}




void F_Railing()     
    {
         glPushMatrix();
         glScalef(0.01,0.01,0.0);
        glPushMatrix();
        glLineWidth(2.5);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-100.0f, 36.0f);
	glVertex2f(100.0f, 36.0f);

	glEnd();


	glLineWidth(2.5);      //  L1
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-95.0f, 36.0f);
    glVertex2f(-95.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);          //L2
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-75.0f, 36.0f);
    glVertex2f(-75.0f, 25.0f);
	glEnd();


 	glLineWidth(2.5);      // L3
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-55.0f, 36.0f);
    glVertex2f(-55.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);        //L4
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-35.0f, 36.0f);
    glVertex2f(-35.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);      //  L5
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-15.0f, 36.0f);
    glVertex2f(-15.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);          //L6
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(5.0f, 36.0f);
    glVertex2f(5.0f, 25.0f);
	glEnd();


 	glLineWidth(2.5);      // L7
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(25.0f, 36.0f);
    glVertex2f(25.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);        //L8
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(45.0f, 36.0f);
    glVertex2f(45.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);      //  L9
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(65.0f, 36.0f);
    glVertex2f(65.0f, 25.0f);
	glEnd();

	glLineWidth(2.5);          //L10
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(85.0f, 36.0f);
    glVertex2f(85.0f, 25.0f);
	glEnd();
	glPopMatrix();
	glPopMatrix();
    }



void Bird() 
{


    glPushMatrix();
    glTranslatef(_move5,0.0f, 0.0f);
glScalef(0.90,0.95,0.0);
     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .41+y);
        }
	glEnd();

	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .39+y);
        }
	glEnd();


	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.7+x, .4+y);
        }
	glEnd();



    glBegin(GL_TRIANGLES);
	glColor3ub(255.0f, 0.0f, 0.0f);

	glVertex2f(.67f, .41f);
	glVertex2f(.65f, .4f);
	glVertex2f(.67f, .39f);
	glEnd();

     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.68+x, .4+y);
        }
	glEnd();

	glLineWidth(0.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.005;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.675+x, .4+y);
        }
	glEnd();

	glBegin(GL_POLYGON);

    glColor3ub(255.0f, 255.0f, 255.0f);
	glVertex2f(.7f, .4f);
	glVertex2f(.705f, .385f);
	glVertex2f(.74f, .36f);
	glVertex2f(.735f, .365f);
	glVertex2f(.74f, .37f);
	glVertex2f(.735f, .375f);
	glVertex2f(.74f, .38f);
	glVertex2f(.735f, .385f);
	glVertex2f(.74f, .39f);
	glVertex2f(.7f, .4f);

	glEnd();


glPopMatrix();

}


void Bird2()   
{


    glPushMatrix();
    glTranslatef(_move5,0.0f, 0.0f);
glScalef(0.90,1.25,0.0);
 glPushMatrix();
     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .41+y);
        }
	glEnd();

	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .39+y);
        }
	glEnd();


	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.7+x, .4+y);
        }
	glEnd();



    glBegin(GL_TRIANGLES);
	glColor3ub(255.0f, 0.0f, 0.0f);

	glVertex2f(.67f, .41f);
	glVertex2f(.65f, .4f);
	glVertex2f(.67f, .39f);
	glEnd();

     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.68+x, .4+y);
        }
	glEnd();

	glLineWidth(0.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.005;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.675+x, .4+y);
        }
	glEnd();

	glBegin(GL_POLYGON);

    glColor3ub(255.0f, 255.0f, 255.0f);
	glVertex2f(.7f, .4f);
	glVertex2f(.705f, .385f);
	glVertex2f(.74f, .36f);
	glVertex2f(.735f, .365f);
	glVertex2f(.74f, .37f);
	glVertex2f(.735f, .375f);
	glVertex2f(.74f, .38f);
	glVertex2f(.735f, .385f);
	glVertex2f(.74f, .39f);
	glVertex2f(.7f, .4f);

	glEnd();

glPopMatrix();
glPopMatrix();

}

void Bird3()    
{


    glPushMatrix();
    glTranslatef(_move5,0.0f, 0.0f);
glScalef(0.70,1.10,0.0);
 glPushMatrix();
     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .41+y);
        }
	glEnd();

	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.73+x, .39+y);
        }
	glEnd();


	glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.7+x, .4+y);
        }
	glEnd();



    glBegin(GL_TRIANGLES);
	glColor3ub(255.0f, 0.0f, 0.0f);

	glVertex2f(.67f, .41f);
	glVertex2f(.65f, .4f);
	glVertex2f(.67f, .39f);
	glEnd();

     glLineWidth(2.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(255.0f, 255.0f, 255.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.68+x, .4+y);
        }
	glEnd();

	glLineWidth(0.5);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3ub(0.0f, 0.0f, 0.0f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.005;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(.675+x, .4+y);
        }
	glEnd();

	glBegin(GL_POLYGON);

    glColor3ub(255.0f, 255.0f, 255.0f);
	glVertex2f(.7f, .4f);
	glVertex2f(.705f, .385f);
	glVertex2f(.74f, .36f);
	glVertex2f(.735f, .365f);
	glVertex2f(.74f, .37f);
	glVertex2f(.735f, .375f);
	glVertex2f(.74f, .38f);
	glVertex2f(.735f, .385f);
	glVertex2f(.74f, .39f);
	glVertex2f(.7f, .4f);

	glEnd();

glPopMatrix();
glPopMatrix();

}

void Tree()  
{
   //tree1 (Small Tree)............................
    glPushMatrix();
    glScalef(0.01,0.01,0.0);
    glPushMatrix();
   glBegin(GL_POLYGON);
	glColor3ub(222.0f, 184.0f, 135.0f);

	glVertex2f(-80.2f, 0.0f);
	glVertex2f(-80.2f, -10.0f);
	glVertex2f(-79.8f, -10.0f);
	glVertex2f(-79.8f, 0.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0.0f, 100.0f, 0.0f);

	glVertex2f(-80.0f, -2.0f);
	glVertex2f(-83.0f, -8.0f);
	glVertex2f(-80.0f, -7.0f);
	glVertex2f(-77.0f, -8.0f);
	glVertex2f(-80.0f, -2.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

	glVertex2f(-80.0f, 1.0f);
	glVertex2f(-82.8f, -5.0f);
	glVertex2f(-80.0f, -4.0f);
	glVertex2f(-77.2f, -5.0f);
	glVertex2f(-80.0f, 1.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34.0f, 139.0f, 34.0f);

	glVertex2f(-80.0f, 4.0f);
	glVertex2f(-82.6f, -2.0f);
	glVertex2f(-80.0f, -1.0f);
	glVertex2f(-77.4f, -2.0f);
	glVertex2f(-80.0f, 4.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

	glVertex2f(-80.0f, 7.0f);
	glVertex2f(-82.4f, 1.0f);
	glVertex2f(-80.0f, 2.0f);
	glVertex2f(-77.6f, 1.0f);
	glVertex2f(-80.0f, 7.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34.0f, 139.0f, 34.0f);

	glVertex2f(-80.0f, 10.0f);
	glVertex2f(-82.2f, 4.0f);
	glVertex2f(-80.0f, 5.0f);
	glVertex2f(-77.8f, 4.0f);
	glVertex2f(-80.0f, 10.0f);
	glEnd();


	//tree2(Big Tree)............................

    glBegin(GL_POLYGON);
	glColor3ub(222.0f, 184.0f, 135.0f);

	glVertex2f(-35.5f, 5.0f);
	glVertex2f(-35.5f, -11.0f);
	glVertex2f(-34.5f, -11.0f);
	glVertex2f(-34.5f, 5.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0f, 100.0f, 0.0f);

	glVertex2f(-35.0f, 3.0f);
	glVertex2f(-41.0f, -7.0f);
	glVertex2f(-35.0f, -5.0f);
	glVertex2f(-29.0f, -7.0f);
	glVertex2f(-35.0f, 3.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

    glVertex2f(-35.0f, 7.0f);
	glVertex2f(-40.0f, -3.0f);
	glVertex2f(-35.0f, -1.0f);
	glVertex2f(-30.0f, -3.0f);
	glVertex2f(-35.0f, 7.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34.0f, 139.0f, 34.0f);

    glVertex2f(-35.0f, 12.0f);
	glVertex2f(-40.0f, 1.0f);
	glVertex2f(-35.0f, 4.0f);
	glVertex2f(-30.0f, 1.0f);
	glVertex2f(-35.0f, 12.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

    glVertex2f(-35.0f, 17.0f);
	glVertex2f(-39.5f, 5.0f);
	glVertex2f(-35.0f, 9.0f);
	glVertex2f(-30.5f, 5.0f);
	glVertex2f(-35.0f, 17.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34.0f, 139.0f, 34.0f);

    glVertex2f(-35.0f, 22.0f);
	glVertex2f(-39.5f, 9.0f);
	glVertex2f(-35.0f, 13.0f);
	glVertex2f(-30.5f, 9.0f);
	glVertex2f(-35.0f, 22.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

    glVertex2f(-35.0f, 27.0f);
	glVertex2f(-39.0f, 13.0f);
	glVertex2f(-35.0f, 17.0f);
	glVertex2f(-31.0f, 13.0f);
	glVertex2f(-35.0f, 27.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(34.0f, 139.0f, 34.0f);

    glVertex2f(-35.0f, 32.0f);
	glVertex2f(-38.5f, 18.0f);
	glVertex2f(-35.0f, 21.0f);
	glVertex2f(-31.5f, 18.0f);
	glVertex2f(-35.0f, 32.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0.0f, 128.0f, 0.0f);

	glVertex2f(-35.0f, 33.0f);
	glVertex2f(-38.5f, 22.0f);
	glVertex2f(-35.0f, 25.0f);
	glVertex2f(-31.5f, 22.0f);
	glVertex2f(-35.0f, 33.0f);
	glEnd();
    glPopMatrix();
    glPopMatrix();


}



void snow(){  

    glPushMatrix();

         glTranslatef(-0.10,0.99,0.0f);

    glPushMatrix();
     glTranslatef(0.0f,position ,0.0f);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
  glEnd();




     glTranslatef(0.5f,position ,0.0f);

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

            glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();



      glTranslatef(-0.9f,position ,0.0f);
  glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

            glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();



 glTranslatef(-0.35f,position ,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

            glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();


 glTranslatef(0.55f,position ,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

            glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();


 glTranslatef(0.95f,position ,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

           glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();



 glTranslatef(0.75f,position ,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

           glColor3f(0.0f, 0.4f, 0.9f);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();




 glTranslatef(0.85f,position ,0.0f);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {

           glColor3f(0.118, 0.565, 1.00);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );

 }
 glEnd();
 glPopMatrix();
 glPopMatrix();

 }




 void windmill() {  

glPushMatrix();
         glScalef(0.20,0.20,0.0);
          glTranslatef(-0.95,0.10,0.0f);
 glPushMatrix();

 glBegin(GL_TRIANGLES);
glColor3f(0.545, 0.271, 0.075);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.7f);
glVertex2f(0.3f, -0.7f);

 glEnd();
glColor3f(0.2f, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.1f, -0.7f);
glVertex2f(0.1f, -0.6f);
glVertex2f(0.16f, -0.6f);
glVertex2f(0.16f, -0.7);
glEnd();

 glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(0.2f, 0.0f, 0.0f);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.05;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y );
}

glEnd();

 glRotatef(_angle2, 0.0f, 0.0f,1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.2f);
glVertex2f(-0.2f, -0.3f);

 glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(0.3f, -0.2f);
glVertex2f(0.2f, -0.3f);

 glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.2f, 0.3f);
glEnd();

 glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glVertex2f(-0.2f, 0.3f);

 glEnd();
glPopMatrix();
glPopMatrix();

}

void wind2() {     

glPushMatrix();

          glTranslatef(-0.5,0.08,1.0);
          glScalef(0.30,0.40,0.0);
 glPushMatrix();

 glBegin(GL_TRIANGLES);
glColor3f(0.545, 0.271, 0.075);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.7f);
glVertex2f(0.3f, -0.7f);

 glEnd();
glColor3f(0.2f, 0.0f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(0.1f, -0.7f);
glVertex2f(0.1f, -0.6f);
glVertex2f(0.16f, -0.6f);
glVertex2f(0.16f, -0.7);
glEnd();

 glLineWidth(7.5);
glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(0.2f, 0.0f, 0.0f);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.05;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(x,y );
}

glEnd();

 glRotatef(_angle2, 0.0f, 0.0f,1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, -0.2f);
glVertex2f(-0.2f, -0.3f);

 glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(0.3f, -0.2f);
glVertex2f(0.2f, -0.3f);

 glEnd();
glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(0.3f, 0.2f);
glVertex2f(0.2f, 0.3f);
glEnd();

 glBegin(GL_TRIANGLES);
glColor3f(0.412, 0.412, 0.412);

 glVertex2f(0.0f, 0.0f);
glVertex2f(-0.3f, 0.2f);
glVertex2f(-0.2f, 0.3f);

 glEnd();
glPopMatrix();
glPopMatrix();

glutSwapBuffers();

}

void moon()    
    {
         glPushMatrix();
glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.07;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.2+x,0.9+y);
}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.6+x,0.9+y);

}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.7+x,0.8+y);

}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.55+x,0.8+y);

}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.7+x,0.9+y);
}
glEnd();
glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.6+x,0.85+y);
}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(0.5+x,0.8+y);
}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.15+x,0.8+y);
}
glEnd();

glLineWidth(7.5);

glBegin(GL_POLYGON);
for(int i=0;i<200;i++)
{
glColor3f(255,255,255);
float pi=3.1416;
float A=(i*2*pi)/200;
float r=0.01;
float x = r * cos(A);
float y = r * sin(A);
glVertex2f(-0.1+x,0.9+y);
}
    glEnd();
	glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3d(1,0,0);
	glLoadIdentity();
    moon();
    plane();
	Hills();
    B_Railing();
	Bridge();
	Train();
	F_Railing();

    Bird();
    Bird2();
    Bird3();

	Tree();
	road();
    car();
    butterfly2();
    butterfly();

    River();
    Boat2();
    Boat();

    human();
    trafficLight();

    snow();
    windmill();
    wind2();

   glFlush();


}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'h':
        run = true;
        break;

        case 'c':
        start = true;
        break;

        case 't':
        trainRun = true;
        break;

        case 'a':
        fly = true;
        break;

        case 's':
        fall=true;
        break;

        case 'f':// for plane move in forward direction
        frd = true;
        planeforward (pos);
        break;

        case 'w':
        mill=true;
        break;

        case 'j':
        ron = true;
        break;

        case 'n':   // for night
        night = true;
        Night(_nt);
        break;

        case 'd'://for day
        night = false;
        glClearColor(1.0,1.0,1.0,1.0);
        break;

        case 'R': //restart boats from initial position
        if(pos1>1||pos1<0)
        {
            pos1=0.0;
        }
        break;

        case 'r':
        if(pos1>1||pos1<0)
        {
            pos1=0.0;
        }
        break;

        case 'U': //increases speed
        s1 += 0.009;
        break;

        case 'u':
        s1 += 0.009;
        break;

        case 'L': //lowers speed
        while((pos1>=0))
        {
            s1 -=0.009;
        }
        break;

        case 'l':
        if((pos1>=0))
        {
            s1 -=0.009;
        }
        break;

        case 'P': //stops the boats
        s1=0.0;
        break;

        case 'p':
        s1=0.0;
        break;

default:
        break;
    }
}
void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT: //big boat moves left
            pos2-=0.01;
            if(pos2<0.0)
            {
                pos2 = 0.0;
            }
            break;
        case GLUT_KEY_RIGHT: //big boat moves right
            pos2+=0.01;
            if(pos2<0.0)
            {
                pos2 = 0.0;
            }
            break;
    }
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("project");
	glutDisplayFunc(drawScene);
	cout<<"Group 6\n";
	cout<<"Press d for day and n for night.\n";
	cout<<"Press f to see the plane move forward, consecutive press on f will increase plane speed.\n";
	cout<<"Press a to see the birds fly.\n";
	cout<<"Press t to start the train.\n";
	cout<<"Press j to see the butterflies movement.\n";
	cout<<"Press w to start the windmill.\n";
	cout<<"Press R/r to make the small boat reappear again.\n";
	cout<<"Press U/u to increase speed, L/l to lower the speed and P/p to stop the small boat.\n";
	cout<<"Using arrow keys the bigger boat can be moved from left to right and right to left.\n";
	cout<<"Press w to start the windmill.\n";
	cout<<"Press h to make the human walk.\n";
	cout<<"Press c to start the car.\n";
	glutSpecialFunc(SpecialInput);
	glutKeyboardFunc(handleKeypress);

	glutTimerFunc(20, update, 0);
	glutTimerFunc(20, update1, 0);
	glutTimerFunc(20, update2, 0);
	glutTimerFunc(500, update3, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(90, up1,0);
    glutTimerFunc(20, but, 0);
    glutTimerFunc(20, but2, 0);
	glutMainLoop();
	return 0;
}
