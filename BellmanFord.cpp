#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
int main()
{
    cout<<"Enter the number of vertices and edges:"<<endl;
    int n,m;
    cin>>n>>m;
    vector<node>adj;
    vector<int>dist(n,1e9);
    cout<<"Enter the source,destination and weight for edge formation:"<<endl;
    for(int i = 0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back(node(u,v,wt));
    }
    cout<<"Enter the source:"<<endl;
    int src;
    cin>>src;
    dist[src] = 0;
    for(int i = 1;i<=n-1;i++)
    {
        for(auto it : adj)
        {
            if(dist[it.u]+it.wt < dist[it.v])
                dist[it.v] = dist[it.u]+it.wt;
        }
    }
    int fl = 0;
    for(auto it : adj)
    {
        if(dist[it.u]+it.wt < dist[it.v])
        {
            cout<<"The negative cycle exist";
            fl = 1;
            break;
        }

    }
    if(fl == 0)
    {
        for(int i = 0;i<n;i++)
        {
            cout<<"the distance of "<<i<<" is "<<dist[i]<<endl;
        }
    }
    return 0;
}