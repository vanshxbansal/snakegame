#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
using namespace std;
bool gameover;
int x,y,fruitx,fruity,score,length=0;
int tailx[100],taily[100];
enum edirection{ STOP,LEFT,RIGHT,UP,DOWN};
edirection dir;
void setup()
{
    gameover=false;
    dir=STOP;
    x=10;
    y=10;
    fruitx=rand()%20;
    fruity=rand()%20;
    score=0;
}
void Draw()
{
    system("cls");
    for(int i=0;i<20+1;i++)
    {   
        cout<<"#";
    }
    cout<<"\n";
    for(int i=1;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(j==0)
            {
                cout<<"#";
            }
            if(j==x&&i==y)
            {
                cout<<"O";
            }
            else if(i==fruity&&j==fruitx)
            {
                cout<<"F";
            }
            else if(j==19)
            {
                cout<<"#";
                cout<<"\n";
            }
            else
            {
                 bool print=false;
                    for(int k=0;k<length;k++)
                    {
                       
                    if(j==tailx[k]&&i==taily[k])
                    {
                        cout<<"o";
                         print=true;
                    }
                    }
                    if(!print)
                    {
                        cout<<" ";
                    }
                   
            }
        }
    }
    for(int i=0;i<20+1;i++)
    {   
        cout<<"#";
    }
    cout<<"\nscore:"<<score;
}
void input()
{
    
    if(_kbhit())
    {
       
            switch(_getch())
        {
            case 'a':
            dir=LEFT;
            break;
            case 'w':
            dir=UP;
            break;
            case 'd':
            dir=RIGHT;
            break;
            case 's':
            dir=DOWN;
            break;
        }
    }
}
void logic()
{
    int prevx,prevy;
    prevx=tailx[0];
    prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<length;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir)
    {
        case LEFT:
            x--;
            break;
        case UP:
            y--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
   
    if(x>19)
    {
        x=0;
    }
    if(x<0)
    {
        x=20;
    }
    if(y<0)
    {
        y=20;
    }
    if(y>20)
    {
        y=0;
    }
    for(int i=0;i<length;i++)
    {
        if(tailx[i]==x&&taily[i]==y)
        {
            gameover=true;
        }
    }
    if (x==fruitx&&y==fruity)
    { 
        srand(time(NULL));
        length++;
       start2: fruitx=rand()%20;
        fruity=rand()%20;
        if(fruitx <= 0||fruity <= 0||fruitx == x||fruity == y||fruitx>=19||fruity>=19){
            goto start2;
        }
        score=score+10;

    }
    
}
int main()
{
    setup();
    while(!gameover)
    {
        srand(time(NULL));
        Draw();
        input();
        logic();
        usleep(300000);
    }
    return 0;
}