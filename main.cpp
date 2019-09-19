#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#include<iostream>

int turn_no=1;
int arrow_points=0;


int dartX = 150, dartY = 30;
int width = 20, height = 100;

int dartX1 = 130, dartY1 = 50;
int width1 = 20, height1 = 60;
float ttr=0;
int flag=0,count1=0,count2=0;

int dartX2 = 120, dartY2 = 70;
int width2 = 10, height2 = 20;

float tx=0,countar=0,ty=0,spin=0.0,spin1=0.0;
float ts=0,tt=0,tz=0,ta=0,tb=0,RX=0,RY=0;;
float factor1=0;
float RH=0.0,RHY=0.0;
float mat[3];
float * point;
int val=0;
  int dum=0;
int pointer=1,ready=0;

void showname()
{
    char s[256];
    sprintf( s, "2D Archery" );

    glRasterPos2f(-45, 245);
   // float x = .5;
   // glRasterPos2f(x - (float) width / 2, 0);
   // glColor3f(0, 1, 1);
    for (int i = 0; i < 10; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);

    }

    glColor3f(1, 0, 0);

}
void board()
{
    glColor3f(0.36,0.18,0.18);
    glBegin(GL_QUADS);
    glVertex2d(-150,220);
    glVertex2d(150,220);
    glVertex2d(150,280);
    glVertex2d(-150,280);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-150,220);
    glVertex2d(150,220);
    glVertex2d(150,280);
    glVertex2d(-150,280);
    glEnd();
    glColor3f(0.36,0.18,0.18);
    glBegin(GL_QUADS);
    glVertex2d(150,220);
    glVertex2d(160,215);
    glVertex2d(160,275);
    glVertex2d(150,280);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(150,220);
    glVertex2d(160,215);
    glVertex2d(160,275);
    glVertex2d(150,280);
    glEnd();

    glColor3f(0.36,0.18,0.18);
    glBegin(GL_QUADS);
    glVertex2d(160,215);
    glVertex2d(150,220);

    glVertex2d(-150,220);
    glVertex2d(-140,215);
    glEnd();

    glColor3f(1,1,1);
    showname();


}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300.0, 300.0, -260.0, 300.0);
}

void target()
{




    glBegin(GL_POLYGON);


    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(dartX2, dartY2);
    glVertex2f(dartX2 + width2, dartY2);
    glVertex2f(dartX2 + width2, dartY2 + height2);
    glVertex2f(dartX2, dartY2 + height2);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(dartX1, dartY1);
    glVertex2f(dartX1 + width1, dartY1);
    glVertex2f(dartX1 + width1, dartY1 + height1);
    glVertex2f(dartX1, dartY1 + height1);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(dartX, dartY);
    glVertex2f(dartX + width, dartY);
    glVertex2f(dartX + width, dartY + height);
    glVertex2f(dartX, dartY + height);
    glEnd();
}

void righthand()
{
    glBegin(GL_LINE_STRIP);

    glVertex2f(-170+RH,70+RHY);
    glVertex2f(-120+RH,84+RHY);
    glVertex2f(-115+RH,81+RHY);
    glVertex2f(-105+RH,84+RHY);
    glVertex2f(-108+RH,87+RHY);
    glVertex2f(-111+RH,92+RHY);
    glVertex2f(-115+RH,92+RHY);
    glVertex2f(-160+RH,85+RHY);
    glVertex2f(-165+RH,83+RHY);
    glVertex2f(-166+RH,81+RHY);
    glVertex2f(-167+RH,80+RHY);
    glVertex2f(-168+RH,77+RHY);
    glVertex2f(-169+RH,72+RHY);
    glVertex2f(-170+RH,70+RHY);

    glEnd();
}

void arm()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(-91+RX,55+RY);
    glVertex2f(-70+RX,65+RY);
    glVertex2f(-70+RX,75+RY);
    glVertex2f(-91+RX,79+RY);
    glVertex2f(-111+RX,92+RY);
    glEnd();
}

void body()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(-170,70);
    glVertex2f(-140,35);
    glVertex2f(-145,15);
    /*for(float i=0;i<=10;i=i+1)
    {
      glVertex2f(-145+i-0.5,15-i);
    }*/
    glVertex2f(-140,0);
    glVertex2f(-100,0);
    glVertex2f(-90,13);
    glVertex2f(-94,28);
    glVertex2f(-91,55);






    glEnd();


    /* */




}

void face()
{

    //FaceShape
    glBegin(GL_LINE_STRIP);

    /* glVertex2f(-140,89);
     glVertex2f(-144,92);
     glVertex2f(-144,96);
     glVertex2f(-144,98);
     glVertex2f(-144,101);
     glVertex2f(-144,102.5);*/
    glVertex2f(-143+RH,89+RHY);
    glVertex2f(-143+RH,92+RHY);
    glVertex2f(-142+RH,105.5+RHY);
    glVertex2f(-141+RH,106+RHY);
    glVertex2f(-140+RH,107+RHY);
    glVertex2f(-139+RH,109+RHY);
    glVertex2f(-138+RH,110.2+RHY);
    glVertex2f(-137+RH,111+RHY);
    glVertex2f(-136+RH,112.4+RHY);
    glVertex2f(-135+RH,113+RHY);
    glVertex2f(-134+RH,114+RHY);
    glVertex2f(-133+RH,114.7+RHY);
    glVertex2f(-132+RH,115+RHY);
    glVertex2f(-131+RH,115.5+RHY);
    glVertex2f(-130+RH,116+RHY);
    glVertex2f(-125+RH,117+RHY);
    glVertex2f(-120+RH,117+RHY);
    glVertex2f(-115+RH,105.5+RHY);
    glVertex2f(-118+RH,92+RHY);


    // glVertex2f(-115,92);
    // glVertex2f(-115,92);
    // glVertex2f(-115,92);
    // glVertex2f(-115,92);
    glEnd();
    //LeftEye
    glBegin(GL_LINE_STRIP);
    glVertex2f(-137+RH,100+RHY);
    glVertex2f(-134+RH,103+RHY);
    glEnd();
    //RightEye
    glBegin(GL_LINE_STRIP);
    glVertex2f(-125+RH,106+RHY);
    glVertex2f(-122+RH,109+RHY);
    glEnd();
    //Nose
    glBegin(GL_LINE_STRIP);
    glVertex2f(-129.5+RH,105+RHY);
    glVertex2f(-128.5+RH,100+RHY);

    glEnd();
    //Emo
    glBegin(GL_LINE_STRIP);
    glVertex2f(-130+RH,95+RHY);
    glVertex2f(-125+RH,99+RHY);
    glEnd();
}

void lefthand()
{
    //LeftHand
    glBegin(GL_LINE_STRIP);
    glVertex2f(-70+RX,66+RY);
    glVertex2f(-27+RX,65+RY);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-70+RX,74+RY);
    glVertex2f(-25+RX,75+RY);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-25+RX,75+RY);
    glVertex2f(-25.5+RX,76+RY);
    glVertex2f(-26+RX,71+RY);
    glVertex2f(-26.5+RX,70+RY);
    glVertex2f(-27+RX,69+RY);
    glVertex2f(-27+RX,65+RY);
    glEnd();

}

void bow()
{
    //Arrow
    glBegin(GL_LINE_STRIP);
    glVertex2f(-60+RH,-15+RHY);
    glVertex2f(-60+RH,-5+RHY);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-60+RH,145+RHY);
    glVertex2f(-60+RH,155+RHY);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(-60+RH,155+RHY);
    glVertex2f(-105+RH,84+RHY);
    glVertex2f(-60+RH,-15+RHY);
    glEnd();
    float x,y,s1,s2,s3,s4;
    glBegin(GL_LINE_STRIP);
    for(float angle=-75.0f; angle>=-90; angle-=1)
    {
        float rad  = 3.1416*angle/180;
        x  = -60+75*cos(rad);
        y  = 70+75*sin(rad);
        glVertex2f(x+RH,y+RHY);
        if(angle==-75.0)
        {
            s3=x;
            s4=y;
        }

    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for(float angle=75.0f; angle<=90; angle+=1)
    {
        float rad  = 3.1416*angle/180;
        x  = -60+75*cos(rad);
        y  = 70+75*sin(rad);
        glVertex2f(x+RH,y+RHY);
        if(angle==75.0)
        {
            s1=x;
            s2=y;
        }

    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2f(s1+RH,s2+RHY);

    glVertex2f(-25+RH,75+RHY);
    glVertex2f(s3+RH,s4+RHY);


    glEnd();

}

void arrow()
{

    glBegin(GL_LINE_STRIP);
    glVertex2f(-105+RH,84+RHY);
    glVertex2f(-25+RH,75+RHY);
    glVertex2f(-22+RH,75+RHY);
    glVertex2f(-20+RH,75+RHY);
    glVertex2f(-18+RH,74+RHY);
    glVertex2f(-16+RH,74+RHY);
    glVertex2f(-15+RH,74+RHY);
    glVertex2f(-12+RH,74+RHY);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-12+RH,74+RHY);
    glVertex2f(-15+RH,79+RHY);
    glVertex2f(-15+RH,69+RHY);
    glEnd();
}

void hat()
{

    glBegin(GL_LINE_STRIP);


    glVertex2f(-143+RH,89+RHY);
    glVertex2f(-145+RH,92+RHY);
    glVertex2f(-147+RH,94+RHY);
    glVertex2f(-148+RH,96+RHY);
    glVertex2f(-149+RH,97+RHY);
    glVertex2f(-150+RH,100+RHY);
    glVertex2f(-151+RH,102+RHY);
    glVertex2f(-152+RH,103+RHY);
    glVertex2f(-150+RH,111+RHY);
    glVertex2f(-149+RH,115+RHY);
    glVertex2f(-146+RH,121+RHY);
    //glVertex2f(-145,110);
    glVertex2f(-132+RH,122+RHY);
    glVertex2f(-120+RH,117+RHY);


    ////

    /* glVertex2f(-125,117);

      glVertex2f(-130,116);


      glVertex2f(-131,115.5);

      glVertex2f(-132,115);

      glVertex2f(-133,114.7);

      glVertex2f(-134,114);

      glVertex2f(-135,113);


      glVertex2f(-136,112.4);

      glVertex2f(-137,111);


      glVertex2f(-138,110.2);

      glVertex2f(-139,109);


      glVertex2f(-140,107);


      glVertex2f(-141,106);


      glVertex2f(-142,105.5);


      glVertex2f(-143,92);
      glVertex2f(-143,89);*/

    glEnd();

}

void leg()
{
    glBegin(GL_LINE_STRIP);
    glVertex2f(-145,15);
    glVertex2f(-150,-15);
    glVertex2f(-152,-95);

    int x1=-152;
    int y1=-95;
    int x2=-142;
    int y2=-99;
    int x3=-132;
    int y3=-95;
    float a,b;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );
    }
    glVertex2f(-132,-45);
    x1=-132;
    y1=-45;
    x2=-122;
    y2=-29;
    x3=-115;
    y3=-10;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        if(i==0.8)
        {
            a=x;
            b=y;
        }
        glVertex2d( x, y );
        //printf("%f %f \n",x,y);
    }


    glEnd();

    glBegin(GL_LINE_STRIP);
    // glVertex2f(a,b);
    //glVertex2f(a,b);
    x1=-117.466705;
    y1=-16.373318;
    x2=-105;
    y2=-30;
    x3=-99;
    y3=-40;

    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );
    }
    glVertex2f(-97,-95);
    x1=-97;
    y1=-95;
    x2=-87;
    y2=-99;
    x3=-77;
    y3=-95;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );
    }
    glVertex2f(-77,-15);
    glVertex2f(-90,13);

    glEnd();
}

void juta()
{

//Left Juta
    glBegin(GL_LINE_STRIP);
    glVertex2f(-150,-96);
    glVertex2f(-150,-110);
    int x1=-150;
    int y1=-110;
    int x2=-145;
    int y2=-114;
    int x3=-120;
    int y3=-110;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );
    }
    x1=-120;
    y1=-110;
    x2=-125;
    y2=-112;
    x3=-134;
    y3=-105;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );

    }
    glVertex2d( -134, -96 );
    glEnd();

    ///Right Juta
    glBegin(GL_LINE_STRIP);
    glVertex2f(-95,-96);
    glVertex2f(-95,-110);
    x1=-95;
    y1=-110;
    x2=-85;
    y2=-114;
    x3=-65;
    y3=-110;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );
    }
    x1=-65;
    y1=-110;
    x2=-68;
    y2=-112;
    x3=-79;
    y3=-105;
    for( float i = 0 ; i < 1 ; i += 0.01 )
    {

        float x=(1-i)*(1-i)*x1+2*(1-i)*i*x2+i*i*x3;
        float y=(1-i)*(1-i)*y1+2*(1-i)*i*y2+i*i*y3;
        glVertex2d( x, y );

    }
    glVertex2d( -79, -96 );
    glEnd();

}


void showText()
{
    char s[256];
    sprintf( s, "Turn   %d   ", turn_no );

    glRasterPos2f(0, -180);
    float x = .5;
   // glRasterPos2f(x - (float) width / 2, 0);

   // glPointSize(10);

    for (int i = 0; i < 9; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);

    }
}

void showPoint()
{
    char s[256];
    sprintf( s, "Points %d   ", arrow_points );

    glRasterPos2f(0, -200);
   // float x = .5;
   // glRasterPos2f(x - (float) width / 2, 0);
    glColor3f(0, 1, 1);
    for (int i = 0; i < 9; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);

    }
    glColor3f(1, 0, 0);
}



void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    board();


    glPushMatrix();

    glTranslatef(0,ttr,0);
    target();

    glPopMatrix();

    glColor3f(1, 0, 0);
    showText();
    showPoint();

    glColor3d(1,1,1);



    body();


    glPushMatrix();

    glTranslatef(ta,tb,0.0);
    glRotatef(spin1,0.0,0.0,1.0);
    arm();
    lefthand();
    glPopMatrix();
    // lefthand();
    // righthand();






    leg();
    juta();


    //glPointSize(100);

    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    glTranslatef(ts,tt,0.0);
    glRotatef(spin,0.0,0.0,1.0);
    glTranslatef(tx,ty,0.0);
    glGetFloatv(GL_MODELVIEW_MATRIX, mat);
    arrow();


    glPopMatrix();





    glPushMatrix();
    glTranslatef(ts,tt,0.0);
    glRotatef(spin,0.0,0.0,1.0);
    righthand();
    face();
    hat();
    bow();

    glPopMatrix();





    pointer++;
    glFlush();
     if(pointer==2)
    {
        PlaySound("ready.wav", NULL, SND_FILENAME|SND_LOOP);
       // pointer=1;
    }
}

float* getpoint(float p[])
{
    p[0]=p[0]+RH;
    p[1]=p[1]+RHY;

   //  printf("%f %f\n",p[0],p[1]);


    float deg=spin/57.29;
    float x=p[0]*cos(deg)-p[1]*sin(deg);
    float y=p[0]*sin(deg)+p[1]*cos(deg);

    // printf("%f %f\n",x,y);
    p[0]=x-RH;
    p[1]=y-RHY;

    // printf("%f %f\n",p[0],p[1]);

    return p;

}

void arrowstraight(void)
{



    if(countar==1)
    {
        tx=tx+0.5;
        float arr[2]= {-12+tx,74};

        point=getpoint(arr);

        // printf("%f %f\n",point[0],point[1]);

        if(point[0]>=120&&point[0]<=120.5)
        {
            if(point[1]>=dartY2+ttr&&point[1]<=dartY2+height2+ttr)

            {
                printf("reached");

                arrow_points+=10;
                val=10;
                showPoint();
                glutIdleFunc(NULL);
                 PlaySound("arrow.wav", NULL, SND_FILENAME|SND_LOOP);
                // tx=0;
            }
            //
        }
        else if(point[0]>=130&&point[0]<=130.5)
        {
            if(point[1]>=dartY1+ttr&&point[1]<=dartY1+height1+ttr)
            {

            printf("reached");
               arrow_points+=5;
                val=5;
                showPoint();
                glutIdleFunc(NULL);
                PlaySound("arrow.wav", NULL, SND_FILENAME|SND_LOOP);
                // tx=0;
            }
            // tx=0;
        }
        else if(point[0]>=150&&point[0]<=150.5)
        {
            if(point[1]>=dartY+ttr&&point[1]<=dartY+height+ttr)
            {
                printf("reached");

               arrow_points+=1;
                val=1;
                showPoint();

                glutIdleFunc(NULL);
                PlaySound("arrow.wav", NULL, SND_FILENAME|SND_LOOP);
                // tx=0;
            }
            else
            {
                //
                dum=1;
                // PlaySound("arrow.wav", NULL, SND_FILENAME|SND_LOOP);
            }
            // tx=0;
        }

        //  printf("%f %f %f\n",mat[0],mat[1],mat[2]);
        glutPostRedisplay();

        countar=0;
    }
    countar++;


}
void turntop(void)
{
    spin=spin+5;
    //spin1=spin1-1.5;
   // spin1=spin1+2;
    // factor1=spin/5;
    RH=170;
    RHY=-70;
    RX=91;
    RY=-55;
    ts=-RH;
    tt=-RHY;
    ta=-RX;
    tb=-RY;

    if(spin==15)
        spin1=-7;
        else if(spin==10)
            spin1=-3.0;
        else if(spin==5)
            spin1=-1.5;
            else if(spin==0)
            spin1=0;
        else if(spin==-15)
            spin1=-5;
            else if(spin==-5)
                spin1=6;
                else if(spin==-10)
                    spin1=0;

    if(spin>=15)
        spin=15;
    //  printf("%f %f %f\n",mat[0],mat[1],mat[2]);
    glutPostRedisplay();


}
void turnbottom(void)
{
    spin=spin-5;
    //spin1=spin1+1.5;
    if(spin==15)
        spin1=-7;
        else if(spin==10)
            spin1=-3.0;
        else if(spin==5)
            spin1=-1.5;
            else if(spin==0)
            spin1=0;
        else if(spin==-15)
            spin1=-5;
            else if(spin==-5)
                spin1=6;
                else if(spin==-10)
                    spin1=0;
    RH=170;
    RHY=-70;
    ts=-RH;
    tt=-RHY;
    RX=91;
    RY=-55;
    ta=-RX;
    tb=-RY;



    if(spin<=-15)
        spin=-15;

    //  printf("%f %f %f\n",mat[0],mat[1],mat[2]);
    glutPostRedisplay();


}

void targetMove(void)
{

    if(ttr==40)
    {
        flag=1;
    }
    else if(ttr==-180)
    {
        flag=0;
    }
    if(flag==1)
    {
        if(count1==10)
        {
            ttr=ttr-0.5;
            count1=0;
        }
        count1++;
    }
    else
    {
        if(count2==10)
        {
            ttr=ttr+0.5;
            count2=0;
        }
        count2++;
    }
    glutPostRedisplay();
}

void my_reshape(int w, int h)
{
    glViewport (0,0,650, 600);//frame boro kora

}


void my_keyboard(unsigned char key, int x, int y)
{


    switch (key)
    {

    case 'w':
        turntop();
        break;

    case 'r':
         arrowstraight();



        break;

    case 's':
        turnbottom();
        break;
    case 'a':
        //dum=arrow_points;

        break;

    default:
        break;
    }
}

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
           {

           ready=1;
    //PlaySound("arrow.wav", NULL, SND_FILENAME|SND_LOOP);
        glutIdleFunc(arrowstraight);

           }
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			{

               turn_no+=1;
        //arrow_points+=val;
        tx=0;
        glutPostRedisplay();
       // arrow_points=dum;
        showPoint();
       // glutIdleFunc(NULL);
        glutIdleFunc(targetMove);
        glutPostRedisplay();

        ready=0;
        pointer=0;

			}
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:

         break;
   }
}

int main()
{

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(250, 100);
    glutCreateWindow("Demo Application");
    init();
    glutDisplayFunc(myDisplay);

    glutIdleFunc(targetMove);
    glutKeyboardFunc(my_keyboard);
   // glutReshapeFunc(my_reshape);
	glutMouseFunc(my_mouse);

    glutMainLoop();
    return 0;
}
