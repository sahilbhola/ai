#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;
int BLANK=0;
int board[10];
void initboard()
{
    for(int i=1;i<10;i++)
    {
        board[i]=0;
    }
}
bool isblank(int board[10],int pos)
{
    if(board[pos]==0 )
        return true;
    else
        return false;
}
bool go(int board[10],char piece,int n)
{
    if(isblank(board,n)==false)
        return false;
    else
    {
        if(piece=='x')
                board[n]=3;
        else if(piece=='o')
                board[n]=5;

        return true;
    }
}
void displayboard(int board[10])
{
    cout<<"\n";
    for(int i=1;i<10;i++)
    {
        if(board[i]==3)
            cout<<"\t"<<"x"<<"\t";
        else if(board[i]==5)
            cout<<"\t"<<"o"<<"\t";
        else if(board[i]==0)
            cout<<"\t"<<"-"<<"\t";
//cout<<"\t"<<board[i]<<"\t";
        if(i%3==0)
            cout<<"\n------------------------------------------\n";
    }

}
char checkwin(int board[10],char piece)
{

    if(piece=='x')
    {
        for(int i=0;i<3;i++)
        {
            if(board[i+1]==3&&board[i+4]==3&&board[i+7]==3)
                return piece;
            if(board[i*3+1]==3&&board[i*3+2]==3&&board[i*3+3]==3)
                return piece;
        }
        if(board[1]==3&&board[5]==3&&board[9]==3)
            return piece;
        if(board[3]==3&&board[5]==3&&board[7]==3)
            return piece;

    }
    else if(piece=='o')
    {
        for(int i=0;i<3;i++)
        {
            if(board[i+1]==5&&board[i+4]==5&&board[i+7]==5)
                return piece;
            if(board[i*3+1]==5&&board[i*3+2]==5&&board[i*3+3]==5)
                return piece;
        }
        if(board[1]==5&&board[5]==5&&board[9]==5)
            return piece;
        if(board[3]==5&&board[5]==5&&board[7]==5)
            return piece;
    }
    int flag=0;
    for(int i=1;i<10;i++)
    {
        if(board[i]==0)
            flag++;
    }
    if(flag==0)
        return('t');
    else
        return('c');
}
 int utility(int board[10], char piece1, char piece2) {
   char winner = checkwin(board, piece1);
   //displayboard(board);
     //   cout<<"\nwinner=\t"<<winner<<"\t"<<checkwin(board,piece2)<<"\n";
    if (winner == piece1)

        return 1;
    else if (checkwin(board,piece2) == piece2)

        return -1;
    else if (winner == 't')

        return 0;
    else

        return 2;
 }
int max(int board[10], char piece1, char piece2, int alpha, int beta);
int min(int board[10], char piece1, char piece2, int alpha, int beta) {
    int score;
int
util = utility(board, piece1, piece2);
   //cout<<util;
   if (util != 2) // leaf node
     {
        //cout<<"\nutil="<<util<<"\n";
        return util;
    }
       //return util;
   for (int i = 1; i < 10; i++)
   {
          if (board[i] == BLANK) {
             if(piece1=='x')
                    board[i]=5;
                else
                    board[i]=3;// try out a square
              score = max(board, piece1, piece2, alpha, beta);
            if (score < beta)  // a new minimum
                beta = score;
            board[i] = BLANK; // return square to its original state
             if (beta <= alpha)
                return beta;
         }
   }
   return beta;
 }
 int max(int board[10], char piece1, char piece2, int alpha, int beta) {
 int util = utility(board, piece1, piece2);
    if (util != 2) // leaf node
    {
        //cout<<"\nutil="<<util<<"\n";
        return util;
    }

    int i,score;
    for (i = 1; i < 10; i++)
    {
          if (board[i] == BLANK) {
              if(piece1=='x')
                    board[i]=3;
                else
                    board[i]=5;// try out a square
             score = min(board, piece1, piece2, alpha, beta);
            if (score > alpha) // a new maximum
                alpha = score;
             board[i] = BLANK; // return square to its original state
             if (alpha >= beta)
               return alpha;
            }
    }

//#    return alpha;
    return alpha;
 }
//#
int stat(int board[10],char piece)
{
    int tot, val=0;
    if(piece=='x')
        tot=3;
    else
        tot=5;
        //cout<<piece;
        //displayboard(board);
    for(int i=1;i<10;i++)
    {
        if(board[i]==tot && i==5)
            val+=5;
        if(board[i]==tot && (i==2 || i==4 || i==6 || i==8))
            val+=3;
        if(board[i]==tot && (i==1 || i==3 || i==7 || i==9))
            val+=1;

    }
//    if(checkwin(board,piece)==piece)
//        val=100;
//cout<<"val="<<val<<"\n";
    return val;

}

 void computer_move(int board[10], char piece1, char piece2) {
    int i, j,score;
    int bestValue = - (INT_MAX);
    int level=0;
    int bestMoves[10]={0}, bestLen = 1; // randomizes equal-valued moves
    for (i = 1; i < 10; i++)
    {
          if (board[i] == BLANK) {
                if(piece1=='x')
                    board[i]=3;
                else
                    board[i]=5;
              // try out a square
              score = min(board, piece1, piece2, -(INT_MAX), INT_MAX);
              //cout<<"\n"<<score<<"\n";
             if (score > bestValue) { // new maximum
                bestValue = score;
                bestLen = 1;
                bestMoves[1] = i; // store move # bestMoves[0][1] = j; // store move
             }
             else if (score == bestValue) { // move tie
//                bestMoves[bestLen] = i; // store move
//                bestLen++;

                    int z=stat(board,piece1);
                    //cout<<"\n inside \n"<<z;
                    if(stat(board,piece1)>level)
                    {
                       // cout<<"\n\n"<<level<<"\n\n";
                       level=stat(board,piece1);
                        bestMoves[1]=i;
                    }
             }
             board[i] = BLANK; // return square to its original state
          }
 }
int k;
//cout<<"\n";
//for(int k=1;k<=bestLen;k++)
//    cout<<"\t"<<bestMoves[k];
//cout<<"\n";
//if(bestLen>1)
//    {bestLen = (rand() % bestLen);
//    k = bestMoves[bestLen];}
//    else
        k=bestMoves[1];
//    j = bestMoves[bestLen][1];
//cout<<i;
    if(piece1=='x')
        board[k]=3;
    else
        board[k]=5;
//    board[bestMoves[bestLen]] = piece1;



//#    return 1; //this means the computer made a move (computer always has to make a move, no need to change this line)
 }
void human_move(int board[10],char piece)
{
    int no;
    cout<<"enter the block no";
    cin>>no;
    if(go(board,piece,no)==false)
        human_move(board,piece);
}

int main()
{
    //cout<<INT_MAX;
    //cout<<INT_MIN;

    char try_again='y';
    while(try_again=='y')
    {
         char player1='x';
        char player2='o';
        char winner='c';
        initboard();
        int choice;
        displayboard(board);
        cout<<"\npress the following\n1.play first\n2.play second";
        cin>>choice;
        if(choice==1)
        {
            while(winner=='c')
            {
                human_move(board,player1);
                displayboard(board);
                winner=checkwin(board,player1);
                //cout<<winner;
                if(winner!=player1 && winner!='t')
                {
                    computer_move(board,player2,player1);
                    winner=checkwin(board,player2);
                    displayboard(board);
                }
            }
        }
        else
        {
            while(winner=='c')
            {
                computer_move(board,player1,player2);
                winner=checkwin(board,player1);
                displayboard(board);
                //cout<<winner;
                if(winner!=player1 && winner!='t')
                {
                    human_move(board,player2);
                    displayboard(board);
                    winner=checkwin(board,player2);
                }
            }
        }
        if(winner!='t')
            cout<<"\nwinter is \t"<<winner;
        else if(winner=='t')
            cout<<"its a tie";
        cout<<"\nto play again enter y\n";
        cin>>try_again;
    }
}
