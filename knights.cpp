#include<iostream>
using namespace std;
int board[10][10]={0};

int static tot_count=0;
int no_act;
//bool check(int board_size)
//{
//    bool flag=true;
//    for(int i=0;i<board_size;i++)
//    {
//        for(int j=0;j<board_size;j++)
//        {
//            if(board[i][j]==0)
//                flag=false;
//        }
//    }
//    return flag;
//}
//bool goal(int board_size,int no)
//{
//    int flag=0;
//    for(int i=0;i<board_size;i++)
//    {
//        for(int j=0;j<board_size;j++)
//        {
//            if(board[i][j]==1)
//                flag++;
//
//        }
//    }
//    if(flag==no)
//        return true;
//    else
//        return false;
//}
//void place(int i,int j)
//{
//
////    int i,j,flag=0;
////    for(i=0;i<board_size;i++)
////    {
////        for(j=0;j<board_size;j++)
////        {
////            if(board[i][j]==0)
////            {
////                board[i][j]=1;
////                flag=1;
////                break;
////            }
////        }
////        if(flag==1)
////            break;
////    }
//    if(board[i][j]==0)
//    {
//        board[i][j]=1;
//        board[i-2][j-1]=9;
//        board[i-2][j+1]=9;
//        board[i-1][j-2]=9;
//        board[i-1][j+2]=9;
//        board[i+1][j-2]=9;
//        board[i+1][j+2]=9;
//        board[i+2][j-1]=9;
//        board[i+2][j+1]=9;
//    }


//}
bool full(int board[10][10],int board_size)
{
    int flag=0;
    for(int i=0;i<board_size;i++)
    {
        for(int k=0;k<board_size;k++)
        {if(board[i][k]==0)
                flag++;
        }
    }
    if(flag==0)
        return true;
    else
        return false;
}

void knights(int board[10][10],int i,int j,int no,int board_size)
{
    //cout<<"inside knight\n";
    if(no==0)
    {
        int tell=0;
//        for(int q=0;q<board_size;q++)
//                    {
//                        for(int w=0;w<board_size;w++)
//                        {
//                            cout<<board[q][w]<<"\t";
//
//                            //new_board[q][w]=board[q][w];
//                        }
//                        cout<<"\n";
//                    }
//                    cout<<"\n\n";
        tot_count++;

        return;
    }
    else
    {
        //cout<<"inside else of knight\n";
        int x,y,flag=0;
        for( x=i;x<board_size;x++)
        {
            //cout<<"inside first loop\n";
            for( y=j;y<board_size;y++)
            {
                //cout<<"inside second loop\n";
//                for(int q=0;q<board_size;q++)
//                    {
//                        for(int w=0;w<board_size;w++)
//                        {
//                            cout<<board[q][w]<<"\t";
//                           // new_board[q][w]=board[q][w];
//                        }
//                        cout<<"\n";
//                    }
                if(board[x][y]==0)
                {
                    int new_board[10][10]={0};
                    for(int q=0;q<board_size;q++)
                    {
                        for(int w=0;w<board_size;w++)
                        {
                            //cout<<board[q][w]<<"\t";
                            new_board[q][w]=board[q][w];
                        }
                        //cout<<"\n";
                    }

                    //cout<<"inside if\n";
                    new_board[x][y]=1;
                    if(x-2>=0&&y-1>=0)
                    new_board[x-2][y-1]=9;
                    if(x-2>=0)
                    new_board[x-2][y+1]=9;
                    if(x-1>=0&&y-2>=0)
                    new_board[x-1][y-2]=9;
                    if(x-1>=0)
                    new_board[x-1][y+2]=9;
                    if(y-2>=0)
                    new_board[x+1][y-2]=9;
                    new_board[x+1][y+2]=9;
                    if(y-1>=0)
                    new_board[x+2][y-1]=9;
                    new_board[x+2][y+1]=9;
                    //cout<<"inside if\n";

                    //cout<<"inside if\n";

                    //cout<<"\n-\n";
                    knights(new_board,x,y,no-1,board_size);
                    //y=0;

                    if(full(new_board,board_size)==true)
                    {
                        flag=1;
                        break;
                    }

                }

            }
            j=0;
            if(flag==1)
                break;

        }
    }

//    if(check(board_size)==true)
//        return 0;
//    else if(goal(board_size,no_act)==true)
//    {
//        tot_count++;
//        //return 0;
//    }
//    else
//    {
//        place(board_size);
//        knights(board_size,no--);
//    }

}
int main()
{
    int board_size;
    cout<<"enter board size";
    cin>>board_size;
    cout<<"enter the no of knights";
    cin>>no_act;
//    int** board = 0;
//      board = new int*[no_act];
//
//      for (int h = 0; h < no_act; h++)
//      {
//            board[h] = new int[no_act];
//
//            for (int w = 0; w < no_act; w++)
//            {
//                 board[h][w] = 0;
//            }
//      }
    knights(board,0,0,no_act,board_size);

cout<<tot_count;
return 0;
}
