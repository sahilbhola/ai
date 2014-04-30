#include<iostream>
#include<cstdlib>
#include<stack>
int *flag,nodes;
 int max_dept=1,dept=0;
using namespace std;
bool stop()
{
    int tap=0;
    for(int j=1;j<=nodes;j++)
            {
                if(flag[j]==1)
                    tap++;

            }
    if(tap==nodes)
        return true;
    else
    {
        for(int j=1;j<=nodes;j++)
            {
                flag[j]=0;
            }
            return false;
    }

}
int main()
{
    int no,left,right,edges,**graph,node;
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
    stack<int> breath;
    cout<<"enter the start node";
    cin>>node;

    flag=new int[nodes];
    for(int j=1;j<=nodes;j++)
            {
                flag[j]=0;
            }

            int element;
            int maxdepth=1;
            cout<<node<<"\n";
    while(stop()!=true)
    {
        int destination=1;
        breath.push(node);
        int depth=0;
        cout<<node<<"\t";
        while(!breath.empty())
        {
            element=breath.top();
            flag[element]=1;
            while(destination<=nodes)
            {
                if(depth<maxdepth)
                {
                    if(graph[element][destination]==1&&flag[destination]==0)
                    {
                        int x;
                        breath.push(destination);
                        flag[destination]=1;
                        cout<<destination<<"\t";
                        depth++;
                        element=destination;
                        destination=1;
                        continue;
                    }
                }
                else
                    break;
                destination++;

            }

            destination=breath.top();
            breath.pop();
            destination++;
            depth--;
        }
        cout<<"\n";
        maxdepth++;
    }


}
