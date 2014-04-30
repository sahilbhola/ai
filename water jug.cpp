#include<iostream>
using namespace std;
int arr[15];
//int flag[43]=0;
static int rul_no,i=0;
bool sea(int no)
{
    for(int i=0;i<15;i++)
    {
        if(no==arr[i])
            return true;
    }
    return false;

}
int rule(int x,int no)
{
    int fir,sec,ans;
    fir=x/10;
    sec=x%10;
    //if(no==1)
    {
        if(fir<4)
        {
            ans=40+sec;
            if(sea(ans)==false)
            return(ans);
        }
        //else
            //return(x);
    }
    //if(no==2)
    {
        if(sec<3)
        {
            ans=(fir*10)+3;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==3)
    {
        if(fir>3)
        {
            ans=0+sec;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==4)
    {
        if(sec>0)
        {
            ans=(fir*10)+0;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==5)
    {
        if(fir+sec>=4 && sec>0)
        {
            ans=40+(sec-(4-fir));
            if(sea(ans)==false)
            return(ans);
        }
        //else
           // return(x);
    }
    //if(no==6)
    {
        if(fir+sec>=3 && fir>0)
        {
            ans=(fir-(3-sec))*10+3;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==7)
    {
        if(fir+sec<=4 && sec>0)
        {
            ans=(fir+sec)*10;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==8)
    {
        if(fir+sec<=3 && sec>0)
        {
            ans=fir+sec;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==9)
    {
        if(fir==0&&sec==2)
        {
            ans=20;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
    //if(no==10)
    {
        if(fir==2)
        {
            ans=sec;
            if(sea(ans)==false)
            return(ans);
        }
        //else
          //  return(x);
    }
}
int out;
void transaction(int value)
{
    rul_no=1;

    int next_value;
    if(value==out)
     {
         arr[++i]=out;
        return;
     }
    else
    {
        arr[++i]=value;
        int flag=1;

        do
        {
            next_value=rule(value,rul_no);
            arr[++i]=next_value;
            value=next_value;
            //rul_no++;
            if(value==out)
                flag=0;
        }while(flag==1);
        //cout<<"\n";
        transaction(next_value);
    }
}

int main()
{

    cout<<"enter the output";
    cin>>out;
    transaction(0);
    for(int x=1;x<i;x++)
    {
        cout<<arr[x]<<"\t";
    }
}
