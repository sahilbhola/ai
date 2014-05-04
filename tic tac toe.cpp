#include<iostream>
int posswin(int);
int game(int);
void win(void);
using namespace std;
int tic[10];
int main()
{
    int flag;

    int f_turn,cube;
    do{
            for(int i=1;i<10;i++)
    {
        tic[i]=2;
    }
    cout<<"welcome to tic tac toe";
    cout<<"\n\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t";
    cout<<"\n---------------------------------------------------------------------";
    cout<<"\n\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t";
    cout<<"\n---------------------------------------------------------------------";
    cout<<"\n\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t\n\t\t\t|\t\t\t|\t\t\t";
    cout<<"Enter \n1.To play first\n2.To play second\n3.Exit";
    cin>>f_turn;

    game(f_turn);
    win();
    cout<<"\n\ndo u want to play again then press 1";
    cin>>flag;

    }while(flag==1);

}
void win()
{

    {
        if(tic[1]*tic[2]*tic[3]==27)
        {
            cout<<"\n\nfirst person win";
        }
        else if(tic[4]*tic[5]*tic[6]==27)
        {
            cout<<"\n\nfirst person win";
                    }
        else if(tic[7]*tic[8]*tic[9]==27)
        {
            cout<<"\n\nfirst person win";
        }
        else if(tic[1]*tic[4]*tic[7]==27)
        {
            cout<<"\n\nfirst person win";

        }
        else if(tic[2]*tic[5]*tic[8]==27)
        {
            cout<<"\n\nfirst person win";
        }
        else if(tic[3]*tic[6]*tic[9]==27)
        {
            cout<<"\n\nfirst person win";
        }
        else if(tic[1]*tic[5]*tic[9]==27)
        {
            cout<<"\n\nfirst person win";
        }
        else if(tic[5]*tic[7]*tic[3]==27)
        {
            cout<<"\n\nfirst person win";
        }
        //return(x);




        else if(tic[1]*tic[2]*tic[3]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[4]*tic[5]*tic[6]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[7]*tic[8]*tic[9]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[1]*tic[4]*tic[7]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[2]*tic[5]*tic[8]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[3]*tic[6]*tic[9]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[1]*tic[5]*tic[9]==125)
        {
            cout<<"\n\nsecond person win";
        }
        else if(tic[5]*tic[7]*tic[3]==125)
        {
            cout<<"\n\nsecond person win";
        }
        //return(x);
        else
            cout<<"\n\ndraw";

}
}
int game(int turn)
{
    int cube;
    int f_turn=turn;
        if(f_turn==2)
    {
        tic[5]=3;           //first turn
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==5);
        tic[cube]=5;
        cout<<"\n\n";
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";
        if(tic[9]==2)       //3rd move
            tic[9]=3;
        else
            tic[3]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==5);
        tic[cube]=5;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n" ;       //5th move
        if(posswin(3)==0)
        {
            if(posswin(5)==0)
            {
                if(tic[7]==2)
                    tic[7]=3;
                else
                    tic[3]=3;
            }
            else
                tic[posswin(5)]=3;
        }
        else
        {
            tic[posswin(3)]=3;
            for(int i=1;i<10;i++)
            {
                if(i==1||i==4||i==7)
                cout<<"\n";
                if(tic[i]==2)
                {
                    cout<<"-\t";
                }
                if(tic[i]==3)
                    cout<<"X\t";
                if(tic[i]==5)
                    cout<<"0\t";
            }
            return(0);
        }
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==5);
        tic[cube]=5;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";       //7th move
        if(posswin(3)==0)
        {
            if(posswin(5)==0)
            {
                for(int i=1;i<10;i++)
                {
                    if(tic[i]==2)
                    {
                        tic[i]=3;
                        break;
                    }
                }
            }
            else
                tic[posswin(5)]=3;
                for(int i=1;i<10;i++)
            {
                if(i==1||i==4||i==7)
                cout<<"\n";
                if(tic[i]==2)
                {
                    cout<<"-\t";
                }
                if(tic[i]==3)
                    cout<<"X\t";
                if(tic[i]==5)
                    cout<<"0\t";
            }
        }
        else
        {
            tic[posswin(3)]=3;
            for(int i=1;i<10;i++)
            {
                if(i==1||i==4||i==7)
                cout<<"\n";
                if(tic[i]==2)
                {
                    cout<<"-\t";
                }
                if(tic[i]==3)
                    cout<<"X\t";
                if(tic[i]==5)
                    cout<<"0\t";
            }
            return(0);
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==5);
        tic[cube]=5;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";       //9th move
        if(posswin(3)==0)
        {
            if(posswin(5)==0)
            {
                for(int i=1;i<10;i++)
                {
                    if(tic[i]==2)
                    {
                        tic[i]=3;
                        break;
                    }
                }
            }
            else
                tic[posswin(5)]=3;
                for(int i=1;i<10;i++)
            {
                if(i==1||i==4||i==7)
                cout<<"\n";
                if(tic[i]==2)
                {
                    cout<<"-\t";
                }
                if(tic[i]==3)
                    cout<<"X\t";
                if(tic[i]==5)
                    cout<<"0\t";
            }
        }
        else
        {
            tic[posswin(3)]=3;
            for(int i=1;i<10;i++)
            {
                if(i==1||i==4||i==7)
                cout<<"\n";
                if(tic[i]==2)
                {
                    cout<<"-\t";
                }
                if(tic[i]==3)
                    cout<<"X\t";
                if(tic[i]==5)
                    cout<<"0\t";
            }
            return (0);
        }
    }
    else if(f_turn==1)
    {
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==3);
        cout<<"\n\n";
        tic[cube]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";
        if(tic[5]==2)       //2nd move
            tic[5]=5;
        else
            tic[1]=5;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==3);
        tic[cube]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";
        if(posswin(3)==0)       //4th move
        {
            if(posswin(5)==0)
            {
                if(tic[2]==3&&tic[4]==3)
                    tic[1]=5;
                else if(tic[2]==3&&tic[6]==3)
                    tic[3]=5;
                 else   if(tic[8]==3&&tic[4]==3)
                    tic[7]=5;
                  else  if(tic[8]==3&&tic[6]==3)
                    tic[9]=5;
               else if(tic[8]==2)
                    tic[8]=5;
                else if(tic[4]==2)
                    tic[4]=5;
                else if(tic[6]==2)
                    tic[6]=5;
                else if(tic[8]==2)
                    tic[2]=5;


            }

        }
        else
        {
            tic[posswin(3)]=5;
        }
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }
        while(tic[cube]==3);
        tic[cube]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";
        if(posswin(5)==0)       //6th move
        {
            if(posswin(3)==0)
            {
                if(tic[2]==2)
                    tic[2]=5;
                else if(tic[4]==2)
                    tic[4]=5;
                else if(tic[6]==2)
                    tic[6]=5;
                else if(tic[8]==2)
                    tic[8]=5;
                    else if(tic[1]==2)
                        tic[1]=5;
            }
            else
                tic[posswin(3)]=5;
                for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        }
        else
        {
            tic[posswin(5)]=5;
            for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        return(0);
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==3);
        tic[cube]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        cout<<"\n\n";
        if(posswin(5)==0)       //8th move
        {
            if(posswin(3)==0)
            {
                for(int i=1;i<10;i++)
                {
                    if(tic[i]==2)
                    {
                        tic[i]=5;
                        break;
                    }
                }
            }
            else
                tic[posswin(3)]=5;
                for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        }
        else
        {
            tic[posswin(5)]=5;
            for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }
        return(0);
        }
        do
        {


        cout<<"\nenter the cube no to make the next move";
        cin>>cube;
        }while(tic[cube]==3);
        tic[cube]=3;
        for(int i=1;i<10;i++)
        {
            if(i==1||i==4||i==7)
                cout<<"\n";
            if(tic[i]==2)
            {
                cout<<"-\t";
            }
            if(tic[i]==3)
                cout<<"X\t";
            if(tic[i]==5)
                cout<<"0\t";
        }


    }
    }

int posswin(int turn)
{
    int x=0;
    if(turn==3)
    {
        if(tic[1]*tic[2]*tic[3]==18)
        {
            if(tic[1]==2)
                x=1;
            if(tic[2]==2)
                x=2;
            if(tic[3]==2)
                x=3;
        }
        if(tic[4]*tic[5]*tic[6]==18)
        {
            if(tic[4]==2)
                x=4;
            if(tic[5]==2)
                x=5;
            if(tic[6]==2)
                x=6;
        }
        if(tic[7]*tic[8]*tic[9]==18)
        {
            if(tic[7]==2)
                x=7;
            if(tic[8]==2)
                x=8;
            if(tic[9]==2)
                x=9;
        }
        if(tic[1]*tic[4]*tic[7]==18)
        {
            if(tic[1]==2)
                x=1;
            if(tic[4]==2)
                x=4;
            if(tic[7]==2)
                x=7;
        }
        if(tic[2]*tic[5]*tic[8]==18)
        {
            if(tic[2]==2)
                x=2;
            if(tic[5]==2)
                x=5;
            if(tic[8]==2)
                x=8;
        }
        if(tic[3]*tic[6]*tic[9]==18)
        {
            if(tic[3]==2)
                x=3;
            if(tic[6]==2)
                x=6;
            if(tic[9]==2)
                x=9;
        }
        if(tic[1]*tic[5]*tic[9]==18)
        {
            if(tic[1]==2)
                x=1;
            if(tic[5]==2)
                x=5;
            if(tic[9]==2)
                x=9;
        }
        if(tic[5]*tic[7]*tic[3]==18)
        {
            if(tic[5]==2)
                x=5;
            if(tic[7]==2)
                x=7;
            if(tic[3]==2)
                x=3;
        }
        return(x);


    }
    else if(turn==5)
    {

        if(tic[1]*tic[2]*tic[3]==50)
        {
            if(tic[1]==2)
                x=1;
            if(tic[2]==2)
                x=2;
            if(tic[3]==2)
                x=3;
        }
        if(tic[4]*tic[5]*tic[6]==50)
        {
            if(tic[4]==2)
                x=4;
            if(tic[5]==2)
                x=5;
            if(tic[6]==2)
                x=6;
        }
        if(tic[7]*tic[8]*tic[9]==50)
        {
            if(tic[7]==2)
                x=7;
            if(tic[8]==2)
                x=8;
            if(tic[9]==2)
                x=9;
        }
        if(tic[1]*tic[4]*tic[7]==50)
        {
            if(tic[1]==2)
                x=1;
            if(tic[4]==2)
                x=4;
            if(tic[7]==2)
                x=7;
        }
        if(tic[2]*tic[5]*tic[8]==50)
        {
            if(tic[2]==2)
                x=2;
            if(tic[5]==2)
                x=5;
            if(tic[8]==2)
                x=8;
        }
        if(tic[3]*tic[6]*tic[9]==50)
        {
            if(tic[3]==2)
                x=3;
            if(tic[6]==2)
                x=6;
            if(tic[9]==2)
                x=9;
        }
        if(tic[1]*tic[5]*tic[9]==50)
        {
            if(tic[1]==2)
                x=1;
            if(tic[5]==2)
                x=5;
            if(tic[9]==2)
                x=9;
        }
        if(tic[5]*tic[7]*tic[3]==50)
        {
            if(tic[5]==2)
                x=5;
            if(tic[7]==2)
                x=7;
            if(tic[3]==2)
                x=3;
        }
        return(x);


    }
}
