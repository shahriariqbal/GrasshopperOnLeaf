#include <windows.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include<iostream>
#include <time.h>
#define PI 3.1416


using namespace std;
GLint i;
GLfloat cx=0,str=500.0,mn=500.0;
double spin=0.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
float padx = 27.5, pady = 18.0;
static float	tx	=  0.0;
static float	ty	=  0.0;
bool ghurtese = false;


void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for( i = 0; i <=50; i++, theta += delTheta )
        {
            glVertex2f(rad * cos(theta),rad * sin(theta));
        }
    }
    glEnd();
}




void cloudB()

{
    //left

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    //top left

    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    //middle

    glPushMatrix();

    //glColor3f (1, 1 ,1);
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}

void a()                                        //mini Cloud

{
    //left

    glPushMatrix();
    glTranslatef(4,5.5,0);
    circle(4);
    glPopMatrix();

    //right

    glPushMatrix();
    glTranslatef(-8,5.5,0);
    circle(3.5);
    glPopMatrix();

    //top left

    glPushMatrix();
    glTranslatef(-3.5,9,0);
    circle(3.5);
    glPopMatrix();

    //top right

    glPushMatrix();
    glTranslatef(1,9,0);
    circle(3);
    glPopMatrix();

    //middle

    glPushMatrix();
    glTranslatef(-1.5,5.5,0);
    circle(4);
    glPopMatrix();

}


void c()                                        //One Single Cloud
{
    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(35,10,0);
    a();
    glPopMatrix();


    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(28,16,0);
    a();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(20,10,0);
    a();
    glPopMatrix();
}

void cloud()                                     // Three Cloud
{
    glPushMatrix();
    glTranslatef(-15.0,30.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-60.0,25.0,0.0);
    glScalef(0.7,0.7,0.0);
    c();
    glPopMatrix();
}


void rect()
{
    glRectf(-16.0, -16.0, 16.0, 16.0);
}
GLfloat ss=0.0;
void day()
{
    glBegin(GL_POLYGON);                        // blue sky
    glColor3f(sr,sg,sb);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);
    glEnd();

    glPushMatrix();                             //sun
    glTranslatef(ss,0.0,0.0);
    glTranslatef(-20.0,40.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,0.0);
    circle(3);
    glPopMatrix();
}
void ground()
{

    glColor3f(0.8,0.498039,0.196078);
    glPushMatrix();
    glTranslatef(-70,-42,0);
    glBegin(GL_POLYGON);

    glVertex3f (-10, 0, 0.0);
    glVertex3f (-10,10, 0.0);
    glVertex3f (600,10, 0.0);
    glVertex3f (600,0, 0.0);

    glEnd();
}
void night ()                                    //black sky
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-50,-3,0.0);
    glVertex3f(-50,50,0.0);
    glVertex3f(80,50,0.0);
    glVertex3f(80,-3,0.0);

    glEnd();
}
void moon()                                     //moon
{
    glPushMatrix();

    glTranslatef(mn,0.0,0.0);
    glTranslatef(20.0,35.0,0.0);
    glScalef(1.0,1.5,0.0);
    glColor3f(1.0,1.0,1.0);
    circle(3.5);


    glPopMatrix();

    glutPostRedisplay();
}
void triangle(void)
{
    glColor3f (0.137255,0.556863,0.137255);
    glBegin(GL_POLYGON);

    glVertex3f (0, 0, 0.0);
    glVertex3f (9, 13, 0.0);
    glVertex3f (18, 0, 0.0);

    glEnd();
}

void grass()
{

    glPushMatrix();
    glColor3f (0.8,0.196078,0.6);
    glTranslatef(38,16,0);
    glScalef(.1,.1,0);
    cloud();
    glPopMatrix();

}

void tree()                             //green leaves
{
    glPushMatrix();
    glTranslatef(35,10,0);
    a();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(28,16,0);
    a();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(20,10,0);
    a();
    glPopMatrix();
}

void treebody()                         //tree body
{
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(0,0,0);
    glVertex3f(2.5,2,0);
    glVertex3f(4.0,-2,0);
    glVertex3f(1,-4,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,2,0);
    glVertex3f(9,2,0);
    glVertex3f(8,-2,0);
    glVertex3f(4,-2,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1,-4,0);
    glVertex3f(4,-2,0);
    glVertex3f(8,-2,0);
    glVertex3f(7,-7,0);
    glVertex3f(1.5,-7,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-7,0);
    glVertex3f(7,-7,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(2,-10,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(2,-10,0);
    glVertex3f(6.5,-10,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(1.5,-13,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(1.5,-13,0);
    glVertex3f(6.8,-13,0);
    glVertex3f(7,-18,0);
    glVertex3f(.5,-18,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(7,-18,0);
    glVertex3f(3,-27,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(.5,-18,0);
    glVertex3f(2.5,-23,0);
    glVertex3f(-1,-25,0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f (0.502, 0.000, 0.000);
    glVertex3f(7,-18,0);
    glVertex3f(8,-28,0);
    glVertex3f(4,-22,0);
    glEnd();
}


//////////////////////
///***HOME Start***////
//////////////////////
void home1()
{
    //1st Home
    //1
    glColor3ub(102,51,0);
    glBegin(GL_POLYGON);
    glVertex2d(3,14);
    glVertex2d(3,11);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glEnd();
    //2
    glColor3ub(153,153,0);
    glBegin(GL_POLYGON);
    glVertex2d(10,8);
    glVertex2d(10,12);
    glVertex2d(20,12);
    glVertex2d(20,8);
    glEnd();
    //3
    glColor3ub(0,100,200);
    glBegin(GL_POLYGON);
    glVertex2d(10,12);
    glVertex2d(6,18);
    glVertex2d(17,18);
    glVertex2d(21,12);
    glEnd();
    //4
    glColor3ub(255,255,0);
    glBegin(GL_POLYGON);
    glVertex2d(5,11);
    glVertex2d(5,12);
    glVertex2d(8,11);
    glVertex2d(8,10);
    glEnd();
    //5

    glColor3ub(50,50,50);
    glBegin(GL_POLYGON);
    glVertex2d(14,8);
    glVertex2d(14,10);
    glVertex2d(17,10);
    glVertex2d(17,8);
    glEnd();


}
void house()
{
    glColor3ub(240,150,100);
    glBegin(GL_POLYGON);
    glVertex2d(33,23);
    glVertex2d(44,23);
    glVertex2d(44,30);
    glVertex2d(33,30);
    glEnd();

    glColor3ub(0,105,105);
    glBegin(GL_POLYGON);
    glVertex2d(31,30);
    glVertex2d(46,30);
    glVertex2d(38.5,38);
    glEnd();

}

//circle

void circle1(float radius_x, float radius_y)
{
    int i=0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f (cos(angle) * radius_x+27.5, 17.5+sin(angle) * radius_y);
    }

    glEnd();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);



glPushMatrix();
    day();
    glPopMatrix();

    ///ground///
    glPushMatrix();
    glTranslatef(0.0,-35.0,0.0);
    glScalef(3.5,3.0,0.0);
    glColor3f(0.0, 0.5, 0.0);
    rect();
    glPopMatrix();



    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(cx,17.0,0.0);
    cloudB();
    glPopMatrix();

    glPushMatrix();
    glColor3f (1,1,1);
    glTranslatef(cx,20.0,0.0);
    cloudB();
    glPopMatrix();




//tree1
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-49.0,9.5,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-40.4,15.4,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();
///*/

///
    glPushMatrix();
    moon();

    glPopMatrix();

///
    glPushMatrix();
    glTranslatef(cx,0.0,0.0);
    glScalef(.8,1,0);
    cloud();
    glPopMatrix();
    ///***///



//home 2///
    glPushMatrix();
    glTranslatef(-65.0,-20.0,0.0);
    house();
    glPopMatrix();
///***///
///home 1///
    glPushMatrix();
    glTranslatef(-45.0,-10.0,0.0);
    home1();
    glPopMatrix();

///***///
    ///tree2///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(-44.0,-1,0.0);
    glScalef(0.4,0.5,0.0);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-35.0,5.0,0.0);
    glScalef(0.4,0.5,0.0);
    treebody();
    glPopMatrix();
///***///

///********home 4********///
    glPushMatrix();
    glTranslatef(-10.0,-10.0,0.0);
    //home1();
    glPopMatrix();
    glPopMatrix();
///***///





    ///tree3///
    glPushMatrix();
    glColor3f(0.133, 0.545, 0.133);
    glTranslatef(22.0,-32.5,0.0);
    glScalef(0.4,0.5,0.0);
    //tree();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(30.5,-26.5,0.0);
    glScalef(0.4,0.5,0.0);
    //treebody();
    glPopMatrix();
    ///***///

 glPushMatrix();


    glTranslatef(27.5,18.0,0);
    glRotatef(spin,0,0,1);
    glColor3f(1.0f, 0.0f, 0.0f);


glPopMatrix();

    padx = 27.5, pady = 18.0;

   float nayeemx=(27.5) * cos(spin/57.29) - (18.0)*sin(spin/57.29);
    float nayeemy=(27.5) * sin(spin/57.29) + (18.0)*cos(spin/57.29);



    glPushMatrix();
    glTranslatef(nayeemx,nayeemy,0);


 glPopMatrix();


////////////////////////////pond

   glColor3f(0.058, 0.470, 0.780);
    glBegin(GL_POLYGON);


        glVertex2f(-50.0, -7.0);
        glVertex2f(50.0, -7.0);

         glVertex2f(50.0, -49.0);

        glVertex2f(-50.0, -50.0);
         glVertex2f(50.0,-50.0);


    glEnd();

    ////leaf/////
     glColor3f(0.011, 0.878, 0);
    glBegin(GL_POLYGON);
        glVertex2f(-10.0, -20.0);
      //  glVertex2f(-30.0, -33.0);

        glVertex2f(-45.0, -35.0);
        glVertex2f(-20.0,-42.0);

         glVertex2f(0.0, -44.0);
        glVertex2f(35.0, -40.0);
        glVertex2f(40.0, -30.0);
        glVertex2f(30.0,-20.0);

    glEnd();


//////////////leafmiddle

glColor3f(0.086, 0.270, 0.105);
    glBegin(GL_POLYGON);


        glVertex2f(-45.0, -35.0);
         glVertex2f(-45.0, -35.5);

        glVertex2f(40.0, -30.0);
        glVertex2f(43.0, -30.5);

  glEnd();


///leafshakha////////////////////////////////////
  glColor3f(0.086, 0.270, 0.105);
  glLineWidth(2.0);
  glBegin(GL_LINES);
    glVertex2f(-10.0, -20.0);
    glVertex2f(0.0, -32.5);

    glVertex2f(0.0, -32.5);
    glVertex2f(-20.0, -42);


    glVertex2f(5.5, -20.0);
    glVertex2f(12.0, -32.0);

       glVertex2f(0.0, -44.0);
    glVertex2f(12.0, -32.0);


      glVertex2f(20.0, -40.0);
    glVertex2f(30.0, -30.5);

          glVertex2f(20.0, -20.0);
    glVertex2f(30.0, -30.5);

   glEnd();
   /////////////////////////////////////////////////////////////////////////


   /////////////////////////Grasshopper//////////////////////


   ///head
glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
glVertex2f(-8.0, -17.0);
         glVertex2f(-4.5, -17.0);
         glVertex2f(-5.0, -20.0);
glVertex2f(-8.0, -22.0);
        glVertex2f(-6.0, -22.0);
glEnd();

///antena

glColor3f(1.0, 1.0, 0.0);
glLineWidth(2);
    glBegin(GL_LINES);
glVertex2f(-13.0, -8.0);
         glVertex2f(-7.0, -17.0);

         glVertex2f(-2.0, -8.0);
glVertex2f(-7.0, -17.0);
        glVertex2f(-6.0, -22.0);
glEnd();

///eye
glColor3f(0.0, 0.0, 0.0);
glPointSize(7.0);
glBegin(GL_POINTS);
glVertex2f(-7.0,-18.5);
glEnd();








   glFlush();

}
void init(void)
{
    glClearColor (0, 0.749, 1, 0);
    gluOrtho2D(-50,50,-50,50);
    //gluOrtho2D(0,100, 0, 100);
   // itime = time(NULL);
}

void spinDisplay()
{
    cx = cx + .01;
    if(cx>70)
        cx = -70;

        spin=spin+5;
        if(spin>=360)
            spin=0;

    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(spinDisplay);
            if(!ghurtese)
                ghurtese = true;
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            ghurtese = false;
            //glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}


void keyDisplayAnimationDay()
{
    str=500.0;
    sr=0.0;
    sg=0.749;
    sb=1.0;

    ss = 0.0;

    mn = 500.0;
    glutPostRedisplay();
}
void keyDisplayAnimationNight()
{
    str = 0.0;
    sr=0.0;
    sg=0.0;
    sb=0.0;

    ss = 500.0;

    mn = 0.0;
    glutPostRedisplay();
}




void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'd':
        keyDisplayAnimationDay();
        break;

    case 'n':
        //night();
        keyDisplayAnimationNight();
        break;
    case 'r':
        spinDisplay();
       break;

    default:
        break;
    }
}



int main()
{
    printf(">><< Press N for nightmood>><< Press D for day mood >><<\n\n");
    printf("Click Mouse Left/Right Button for cloud movement\n\n");
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (690, 690);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("shahriar ");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
