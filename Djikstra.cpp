#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a,b,wt;
    vector<pair<int,int>>adj[n+1];
    cout<<"Enter the edges:"<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    int src;
    cout<<"Enter source"<<endl;
    cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(n+1,INT_MAX);
    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dist=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for(auto it:adj[prev]){
            int next=it.first;
            int nextDis=it.second;
            if(dis[prev]+nextDis<dis[next]){
                dis[next]=dis[prev]+nextDis;
                pq.push({dis[next],next});
            }
        }
    }
    cout<<"Distances from source are:"<<endl;
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    return 0;
}