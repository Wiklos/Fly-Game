#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

#include <cstdlib>
#include <ctime>

#include <windows.h>


float rBomba = 0.0;
float smiercAnim = 0.0;
bool smierc = false;

float klocekR = 0.0;

float pasekAnim = 0.1;
float pasekAnim2 = 0.1;

bool poziom2 = false;

float licznik2Bool = false;

int hpMax = 3; //bylo 3
int currentHp = hpMax;

float wartMaxSpeed2 = 1;
float wartMaxSpeed = 1;
//float wartSpeed = 0.9;
float wartSpeed2 = -1.5;
float wartSpeed = -1.5;
float licznik2start = 1;
float licznik2end = 2;


float r = 0;
float x = 0;
float y = 0;
float M_PI = 3.14;

float px;
float py;
float px2; //bomba
float py2;

float speed = 0.0003;
//float speed = 0.0001; - przed zmiana exe speeda

bool start = false;
void czaszka()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.1,0.4,-5.0);
    glVertex3f(0.3,0.4,-5.0);
    glVertex3f(0.3,0.5,-5.0);
    glVertex3f(0.1,0.5,-5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-0.1,0.0,-5.0);
    glVertex3f(0.5,0.0,-5.0);
    glVertex3f(0.5,0.4,-5.0);
    glVertex3f(-0.1,0.4,-5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(0.0,0.4,-5.0);
    glVertex3f(0.4,0.4,-5.0);
    glVertex3f(0.4,-0.3,-5.0);
    glVertex3f(0.0,-0.3,-5.0);
    glEnd();

    glBegin(GL_QUADS);// oczy
    glColor3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.1,-4.99);
    glVertex3f(0.1,0.1,-4.99);
    glVertex3f(0.1,0.3,-4.99);
    glVertex3f(0.0,0.3,-4.99);
    glEnd();

    glBegin(GL_QUADS);// oczy prawe
    glColor3f(0.0,0.0,0.0);
    glVertex3f(0.3,0.1,-4.99);
    glVertex3f(0.4,0.1,-4.99);
    glVertex3f(0.4,0.3,-4.99);
    glVertex3f(0.3,0.3,-4.99);
    glEnd();

    glBegin(GL_QUADS);// zeby
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.35,0.0,-4.99);
    glVertex3f(0.4,0.0,-4.99);
    glVertex3f(0.4,-0.2,-4.99);
    glVertex3f(0.35,-0.2,-4.99);
    glEnd();

    glBegin(GL_QUADS);// zeby 2 od prawej
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.26,-0.1,-4.99);
    glVertex3f(0.3,-0.1,-4.99);
    glVertex3f(0.3,-0.3,-4.99);
    glVertex3f(0.26,-0.3,-4.99);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.16,0.0,-4.99);
    glVertex3f(0.21,0.0,-4.99);
    glVertex3f(0.21,-0.2,-4.99);
    glVertex3f(0.16,-0.2,-4.99);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.07,-0.1,-4.99);
    glVertex3f(0.11,-0.1,-4.99);
    glVertex3f(0.11,-0.3,-4.99);
    glVertex3f(0.07,-0.3,-4.99);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,0.0,-4.99);
    glVertex3f(0.05,0.0,-4.99);
    glVertex3f(0.05,-0.2,-4.99);
    glVertex3f(0.0,-0.2,-4.99);
    glEnd();

}
void licznik2(float wart, float wartmax)
{
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,-1.5,-5.0);
    glVertex3f(0.1,-1.5,-5.0);
    glVertex3f(0.1,1.5,-5.0);
    glVertex3f(0.0,1.5,-5.0);
    glEnd();

    glTranslatef(0.0,0.0,0.01);

    glBegin(GL_QUADS);
    if(wart<0)
    {
        glColor3f(0.0,1.0,0.0);
    }
    else if(wart<1)
    {
        glColor3f(0.0,0.0,1.0);
    }
    else
    {
        glColor3f(1.0,0.0,0.0);
    }
    if((wart/wartmax)>1.5)
    {
        glVertex3f(0.0,-1.5,-5.0);
        glVertex3f(0.1,-1.5,-5.0);
        glVertex3f(0.1,1.5,-5.0);
        glVertex3f(0.0,1.5,-5.0);
        glEnd();
    }
    else
    {
        glVertex3f(0.0,-1.5,-5.0);
        glVertex3f(0.1,-1.5,-5.0);
        glVertex3f(0.1,wart/wartmax,-5.0);
        glVertex3f(0.0,wart/wartmax,-5.0);
        glEnd();
    }



}
void licznik(float wart, float wartmax)
{
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,-1.5,-5.0);
    glVertex3f(0.1,-1.5,-5.0);
    glVertex3f(0.1,1.5,-5.0);
    glVertex3f(0.0,1.5,-5.0);
    glEnd();

    glTranslatef(0.0,0.0,0.01);

    glBegin(GL_QUADS);
    if(wartSpeed<0)
    {
        glColor3f(0.0,1.0,0.0);
    }
    else if(wartSpeed<1)
    {
        glColor3f(0.0,0.0,1.0);
    }
    else
    {
        glColor3f(1.0,0.0,0.0);
    }
    if((wartSpeed/wartMaxSpeed)>1.5)
    {
        if(pasekAnim>0)
        {
            pasekAnim = -0.01;
        }
        else
        {
            pasekAnim = 0.01;
        }
        glVertex3f(0.0+pasekAnim,-1.5,-5.0);
        glVertex3f(0.1+pasekAnim,-1.5,-5.0);
        glVertex3f(0.1+pasekAnim,1.5,-5.0);
        glVertex3f(0.0+pasekAnim,1.5,-5.0);
        glEnd();

        licznik2Bool = true;
    }
    else
    {
        glVertex3f(0.0,-1.5,-5.0);
        glVertex3f(0.1,-1.5,-5.0);
        glVertex3f(0.1,wartSpeed/wartMaxSpeed,-5.0);
        glVertex3f(0.0,wartSpeed/wartMaxSpeed,-5.0);
        glEnd();
    }
//    glColor3f(0.5,0.5,0.5);
//    glPushMatrix();
//    glBegin(GL_QUADS);
//    glVertex3f(0.0,-0.1,0.0);
//    glVertex3f(1.0,-0.1,0.0);
//    glVertex3f(1.0,0.1,0.0);
//    glVertex3f(0.0,0.1,0.0);
//    glEnd();
//
//    //glTranslatef(0.0,0.0,0.01);
//
//    glColor3f(r,g,b);
//    glBegin(GL_QUADS);
//    glVertex3f(0.0,-0.1,0.0);
//    glVertex3f(wart/wartmax,-0.1,0.0);
//    glVertex3f(wart/wartmax,0.1,0.0);
//    glVertex3f(0.0,0.1,0.0);
//    glEnd();
//    glPopMatrix();
}
void losuj()
{
    int wylosowana_liczba =( std::rand() % 19 ) -19;
    px = wylosowana_liczba/10;
    wylosowana_liczba =( std::rand() % 16 ) -19;
    py = wylosowana_liczba/10;

    if(px==px2 && py==py2)
    {
        losuj();
    }
}
void losujBombe()
{
    Sleep(100);
    int wylosowana_liczba2 =( std::rand() % 19 ) -19;
    px2 = wylosowana_liczba2/10;
    wylosowana_liczba2 =( std::rand() % 16 ) -19;
    py2 = wylosowana_liczba2/10;
}
void serce()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0.0,0.0,-5.0);
    glVertex3f(0.1,0.0,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glVertex3f(0.0,0.1,-5.0);
    glEnd();
}
void klocek()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(0.0,0.0,-5.0);
    glVertex3f(0.1,0.0,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glVertex3f(0.0,0.1,-5.0);
    glEnd();
}

void bomba()
{
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.6);
    glVertex3f(0.0,0.0,-5.0);
    glVertex3f(0.1,0.0,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glVertex3f(0.0,0.1,-5.0);
    glEnd();
}
void scianaPozioma()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(-1.7,0.1,-5.0);
    glVertex3f(2.0, 0.1,-5.0);
    glVertex3f(2.0,0.2,-5.0);
    glVertex3f(-1.7,0.2,-5.0);
    glEnd();

}
void scianaPionowa()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);

    glVertex3f(0.1,-1.8,-5.0);
    glVertex3f(0.2,-1.8,-5.0);
    glVertex3f(0.2,1.8,-5.0);
    glVertex3f(0.1,1.8,-5.0);
    glEnd();

}
void pole2()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,0.0);

    glVertex3f(0.1,-0.2,-5.0);
    glVertex3f(0.2,-0.2,-5.0);
    glVertex3f(0.2,0.2,-5.0);
    glVertex3f(0.1,0.2,-5.0);
    glEnd();

}
void pole()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-0.2,-0.2,-5.0);
    glVertex3f(0.1,-0.2,-5.0);
    glVertex3f(0.1,0.2,-5.0);
    glVertex3f(-0.2,0.2,-5.0);
    glEnd();
    pole2();
}
void mucha3()
{
    //skrzydla
    glBegin(GL_QUADS);
    glColor3f(1.0,0.7,1.0);

    glVertex3f(-0.1,-0.3,-5.0);
    glVertex3f(0.1,-0.1,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glVertex3f(-0.1,0.3,-5.0);
    glEnd();


}
void mucha2()
{
    glBegin(GL_QUADS);
    glColor3f(1.0,0.1,1.0);

    glVertex3f(0.1,-0.1,-5.0);
    glVertex3f(0.2,-0.1,-5.0);
    glVertex3f(0.2,0.1,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glEnd();
    mucha3();

}
void mucha()
{
    glBegin(GL_QUADS);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-0.2,-0.1,-5.0);
    glVertex3f(0.1,-0.1,-5.0);
    glVertex3f(0.1,0.1,-5.0);
    glVertex3f(-0.2,0.1,-5.0);
    glEnd();
    mucha2();
}
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,640.0/480.0,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(x,y,0.0);
    glRotatef(r,0.0,0.0,1.0);
    glScalef(0.5,0.5,1.0);
    //pole();
    mucha();
    glPopMatrix();

    if(start)
    {
        x += speed * cos((r*M_PI)/180);
        y += speed * sin((r*M_PI)/180);

    }
    glPushMatrix();
    glTranslatef(2.0,0.0,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    scianaPionowa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0,0.0,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    scianaPionowa();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,1.7,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    scianaPozioma();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-2.0,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    scianaPozioma();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(px,py,0.0);
    glRotatef(klocekR,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    klocek();
    glPopMatrix();

    if(poziom2)
    {
            glPushMatrix();
    glTranslatef(px2,py2,0.0);
    glRotatef(rBomba,0.0,0.0,0.1);
    //glScalef(0.5,0.5,1.0);
    bomba();
    glPopMatrix();

    rBomba +=0.05;
    }

    if(x>=2)
    {
        if(start)
        {
            currentHp-=1;
            if(currentHp == 0)
            {
                smierc = true;
            }
        }
        start = false;
    }
    if(x<=-1.7)
    {
        if(start)
        {
            currentHp-=1;
            if(currentHp == 0)
            {
                smierc = true;
            }
        }
        start = false;
    }
    if(y<=-1.8)
    {
        if(start)
        {
            currentHp-=1;
            if(currentHp == 0)
            {
                smierc = true;
            }
        }
        start = false;
    }
    if(y>=1.8)
    {
        if(start)
        {
            currentHp-=1;
            if(currentHp == 0)
            {
                smierc = true;
            }
        }
        start = false;
    }

    if(y>=(py-0.1) && y<=(py+0.1) )
    {
        if(x>=(px-0.1) && x<=(px+0.1))
        {
            //start = false;
            wartSpeed +=0.1;
            if(wartSpeed>=1.5)
            {
                poziom2 = true;
                wartSpeed2 +=0.1;
            }
            losuj();
            //speed = speed*1.1;
            speed+=0.00003;
        }
    }

    if(poziom2)
    {
    if(y>=(py2-0.1) && y<=(py2+0.1) )
    {
        if(x>=(px2-0.1) && x<=(px2+0.1))
        {
            if(start)
            {
            currentHp-=1;
            if(currentHp == 0)
            {
                smierc = true;
            }
            losujBombe();
            }
            start = false;
        }
    }
    }


//    if(y>=-1.1 && y<=-0.9 )
//    {
//        if(x>=0.9 && x<=1.1)
//        {
//            start = false;
//        }
//    }

    if(currentHp==1)
    {
        glPushMatrix();
        glTranslatef(-2.6,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();

    }


    if(currentHp==2)
    {
        glPushMatrix();
        glTranslatef(-2.6,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.4,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();

    }


    if(currentHp==3)
    {
        glPushMatrix();
        glTranslatef(-2.6,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2.4,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-2.2,1.5,0.0);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        serce();
        glPopMatrix();

    }

    glPushMatrix();
    glTranslatef(2.4,0.0,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    licznik(wartSpeed, wartMaxSpeed);
    glPopMatrix();

    if(licznik2Bool)
    {

           glPushMatrix();
    glTranslatef(2.6,0.0,0.0);
    //glRotatef(r,0.0,0.0,1.0);
    //glScalef(0.5,0.5,1.0);
    licznik2(wartSpeed2, wartMaxSpeed2);
    glPopMatrix();
    }



    if(smierc)
    {
        klocekR +=1.0;
        rBomba += 1.0;
        if(smiercAnim<2.0)
        {
            smiercAnim +=0.0002;
        }
        glPushMatrix();
        glTranslatef(0.0,0.0,smiercAnim);
        //glRotatef(r,0.0,0.0,1.0);
        //glScalef(0.5,0.5,1.0);
        czaszka();
        glPopMatrix();
    }


}

int main(int argc, char* args[])
{
    srand( time( NULL ) );
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);


    int loop=1;
//    Uint32 start;
    SDL_Event myevent;
    SDL_EnableKeyRepeat(10,10);

    init();
    while (loop==1)
    {
        while (SDL_PollEvent(&myevent))
        {
            switch(myevent.type)
            {
            case SDL_QUIT:
                loop=0;
                break;

            case SDL_KEYDOWN:
                if (myevent.key.keysym.sym==SDLK_SPACE)
                {
                    if(!start)
                    {

                        if(currentHp!=0)
                        {
                            losuj();
                            start = true;
                        }
                    }
                }
                if (myevent.key.keysym.sym==SDLK_LEFT)
                {
                    if(!smierc)
                    {
                        r=r+5;
                    }
                }

                if (myevent.key.keysym.sym==SDLK_RIGHT)
                {

                    if(!smierc)
                    {
                        r=r-5;
                    }
                }

                if (myevent.key.keysym.sym==SDLK_UP)
                {
                    //x=x+0.1;
                    //y=y+0.1;

                    //x += 0.05 * cos((r*M_PI)/180);
                    //y += 0.05 * sin((r*M_PI)/180);
                }
                if (myevent.key.keysym.sym==SDLK_ESCAPE)
                {
                    poziom2 = false;
                    licznik2Bool = false;
                    start = false;
                    currentHp = hpMax;
                    smierc = false;
                    wartSpeed = -1.5;
                    speed = 0.0001;

                    x = 0;
                    y = 0;
                    r = 0;
                }
            }
        }
        display();
        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}

