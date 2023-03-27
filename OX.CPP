#include<iostream>
#include<windows.h>
#include<cstdlib>
using namespace std;
int color=1;
HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
int finaldisplay(char c[9])
{
    SetConsoleTextAttribute(h,color);
    color++;
    cout<<endl<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[0]<<"  |  "<<c[1]<<"   |  "<<c[2]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                     "<<"-----|------|-----"<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[3]<<"  |  "<<c[4]<<"   |  "<<c[5]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                     "<<"-----|------|-----"<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[6]<<"  |  "<<c[7]<<"   |  "<<c[8]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<endl;
    return 0;
}
int display(char c[9])
{
    system("CLS");
    SetConsoleTextAttribute(h,color);
    color++;
    cout<<endl<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[0]<<"  |  "<<c[1]<<"   |  "<<c[2]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                     "<<"-----|------|-----"<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[3]<<"  |  "<<c[4]<<"   |  "<<c[5]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                     "<<"-----|------|-----"<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<"                                                       "<<c[6]<<"  |  "<<c[7]<<"   |  "<<c[8]<<endl;
    cout<<"                                                     "<<"     |      |   "<<endl;
    cout<<endl;
    return 0;
}
int checkwin(char c[9])
{
    if((c[0]=='O' && c[1]=='O' && c[2]=='O')||(c[3]=='O' && c[4]=='O' && c[5]=='O')||(c[6]=='O' && c[7]=='O' && c[8]=='O')
    ||(c[0]=='O' && c[3]=='O' && c[6]=='O') ||(c[1]=='O' && c[4]=='O' && c[7]=='O')||(c[2]=='O' && c[5]=='O' && c[8]=='O')
    ||(c[0]=='O' && c[4]=='O' && c[8]=='O')||(c[2]=='O' && c[4]=='O' && c[6]=='O'))
    {
        return 1;
    }
    if((c[0]=='X' && c[1]=='X' && c[2]=='X')||(c[3]=='X' && c[4]=='X' && c[5]=='X')||(c[6]=='X' && c[7]=='X' && c[8]=='X')
    ||(c[0]=='X' && c[3]=='X' && c[6]=='X') ||(c[1]=='X' && c[4]=='X' && c[7]=='X')||(c[2]=='X' && c[5]=='X' && c[8]=='X')
    ||(c[0]=='X' && c[4]=='X' && c[8]=='X')||(c[2]=='X' && c[4]=='X' && c[6]=='X'))
    {
        return 2;
    }
    else
    {
        return 0;
    }

}
int dici(char c[9]) 
{
    int i=0;
    char temp;
    //check com win
    for(i=0;i<9;i++)
    {
        if(c[i]!='X' && c[i]!='O')
        {
            temp=c[i];
            c[i]='X';
            if(checkwin(c)==2)
            {
                c[i]=temp;
                return i;
            }
            else
            {
                c[i]=temp;
            }
        }
    }


    //chech person win
    for(i=0;i<9;i++)
    {
        if(c[i]!='X' && c[i]!='O')
        {
            temp=c[i];
            c[i]='O';
            if(checkwin(c)==1)
            {
                c[i]=temp;
                return i;
            }
            else
            {
                c[i]=temp;
            }
        }
    }   

    //random move 
    int move;
    do
    {
        move=rand()%9;
        if(c[move]!='O' && c[move]!='X')
        {
            return move;
        }
    }
    while(1);
}


int main()
{
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                   __________________________________"<<endl;
    cout<<"                                                  ||                                ||"<<endl;
    cout<<"                                                  ||  ENTER MENU :                  ||"<<endl;
    cout<<"                                                  ||  1] PLAYING WITH COMPUTER      ||"<<endl;
    cout<<"                                                  ||  2] PLAYING WITH YOUR FRIEND   ||"<<endl;
    cout<<"                                                  ||________________________________||"<<endl;
    cout<<endl;
    cout<<"                                                      ENTER NUM : ";
    int menu;
    cin>>menu;
    int t,i,k;
    char c[9]={'1','2','3','4','5','6','7','8','9'};
    display(c);
    if(menu==1)
    {
        for(i=0;i<9;i++)
        {
            if(i%2==0)
            {
                display(c);
                cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                cin>>t;
                if(t>9)
                {
                    while(t>9)
                    {
                        cout<<"                                      player 1 ::your place is invalid"<<endl;
                        cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                        cin>>t;
                    }
                }
                while(c[t-1]=='X' || c[t-1]=='O')
                {
                    cout<<"                                      player 1 ::your place is already occupied"<<endl;
                    display(c);
                    cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                    cin>>t;
                    if(c[t-1]!='O' && c[t-1]!='X')
                    {
                        c[t-1]='O';
                        break;
                    }
                }
                c[t-1]='O';
        
                k=checkwin(c);
                if(k==1)
                {
                    display(c);
                    cout<<"                                      winner: 1"<<endl;
                    break;
                }
                else if(k==2)
                {
                    display(c);
                    cout<<"                                      computer is winner"<<endl;
                    break;
                }
            }
            else
            {
                display(c);
                t=dici(c);
                while(c[t]=='X' || c[t]=='O')
                {
                    t=dici(c);
                    if(c[t]!='O' && c[t]!='X')
                    {
                        c[t]='X';
                        break;
                    }
                }
                c[t]='X';
                k=checkwin(c);
                if(k==1)
                {
                    cout<<endl<<"                                      winner: 1"<<endl;
                    break;
                }
                else if(k==2)
                {
                    cout<<endl<<"                                      computer is winner"<<endl;
                    break;
                }
            }
        }
        finaldisplay(c);
        if(k==0)
        {
            cout<<"                                      game over no one is winner!!"<<endl;
        }
    }
    if(menu==2)
    {
        for(i=0;i<9;i++)
        {
            if(i%2==0)
            {
                display(c);
                cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                cin>>t;
                if(t>9)
                {
                    while(t>9)
                    {
                        cout<<"                                      player 1 ::your place is invalid"<<endl;
                        cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                        cin>>t;
                    }
                }
                while(c[t-1]=='X' || c[t-1]=='O')
                {
                    cout<<"                                      player 1 ::your place is already occupied"<<endl;
                    cout<<"                                      player 1 ::ENTER NO FROM 0 TO 9 : ";
                    cin>>t;
                    if(c[t-1]!='O' && c[t-1]!='X')
                    {
                        c[t-1]='O';
                        break;
                    }
                }
                c[t-1]='O';
        
                k=checkwin(c);
                if(k==1)
                {
                    display(c);
                    cout<<"                                      win 1"<<endl;
                    break;
                }
                else if(k==2)
                {
                    display(c);
                    cout<<"                                      win 2"<<endl;
                    break;
                }
            }
            else
            {
                display(c);
                cout<<"                                      player 2 ::ENTER NO FROM 0 TO 9 : ";
                cin>>t;
                if(t>9)
                {
                    while(t>9)
                    {
                        cout<<"                                      player 2 ::your place is invalid"<<endl;
                        cout<<"                                      player 2 ::ENTER NO FROM 0 TO 9 : ";
                        cin>>t;
                    }
                }
                while(c[t-1]=='X' || c[t-1]=='O')
                {
                    cout<<"                                      player 2 ::your place is already occupied"<<endl;
                    display(c);
                    cin>>t;
                    if(c[t-1]!='O' && c[t-1]!='X')
                    {
                        c[t-1]='X';
                        break;
                    }
                }
                c[t-1]='X';
                k=checkwin(c);
                if(k==1)
                {
                    display(c);
                    cout<<"                                      winner: 1"<<endl;
                    break;
                }
                else if(k==2)
                {
                    display(c);
                    cout<<"                                      winner: 2"<<endl;
                    break;
                }
            }
        }
        finaldisplay(c);
        if(k==0)
        {
            cout<<"                                      game over no one is winner!!"<<endl;
        }
    }

    return 0;
}