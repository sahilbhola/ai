#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    int no,left,right,nodes,edges,**graph;
    cout<<"enter the no of nodes and edges in the graph \n";
    cin>>nodes>>edges;
    graph=new int*[nodes];
    for(int i=1;i<=nodes;i++)
    {
        graph[i]=new int[nodes];
    }
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            graph[i][j]=0;
        }

    }


    while(edges)
    {
        cout<<"enter the two nodes that are connected\t";
        cin>>left>>right;
        graph[left][right]=1;
        graph[right][left]=1;
        edges--;
    }
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\nPress m to enter into the menu and q to exit\n";
    char ch;
    cin>>ch;
    if(ch=='m')
    {
        int while_ch=1;
        while(while_ch==1)
        {
            int option,node,*flag,f,flag1=0;
            flag=new int[nodes];
            for(int j=1;j<=nodes;j++)
            {
                flag[j]=0;
            }
            cout<<"\npress the following no \n1.breath search\n2.depth search\n3.exit\n";
            cin>>option;
            if(option==1)
            {
                queue<int> depth;
                cout<<"enter the start node\n";
                cin>>node;
                cout<<"\nenter the node to be searched";
                cin>>f;
                cout<<"\n";
                //flag[node]=1;
                depth.push (node);
                while(!depth.empty())
                {
                    int sch;
                    sch=depth.front();
                    depth.pop();
                    if(f==sch)
                    {
                        cout<<"\nthis is the no\n";
                        flag1++;
                    }
                    flag[sch]=1;
                    cout<<sch<<"\t";
                    for(int i=1;i<=nodes;i++)
                    {
                        if(graph[i][sch]==1&&flag[i]==0)
                        {   depth.push (i);
                            flag[i]=1;
                        }
                    }
                }
                if(flag1==0)
                    cout<<"\nno is not present\n";


            }
            else if(option==2)
            {
                stack<int> breath;
                cout<<"enter the start node";
                cin>>node;
                cout<<"\nenter the node to be searched";
                cin>>f;
                cout<<"\n";
                //flag[node]=1;
                breath.push (node);
                while(!breath.empty())
                {
                    int sch;
                    sch=breath.top();
                    flag[sch]=1;
                    if(f==sch)
                    {
                        cout<<"\nthis is the no\n";
                        flag1++;
                    }
                    breath.pop();
                    cout<<sch<<"\t";
                    for(int i=nodes;i>=1;i--)
                    {
                        if(graph[i][sch]==1&&flag[i]==0)
                        {   breath.push (i);
                            flag[i]=1;
                        }
                    }
                }
                if(flag1==0)
                    cout<<"\nno is not present\n";

            }
            else if(option==3)
            {
                while_ch=0;
            }
            else
            {
                cout<<"wrong choice pls enter again";
            }

        }
    }
//    else
//    {
//        exit();
//    }

    return 0;
}
