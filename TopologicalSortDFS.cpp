//for DAG(Directed Acyclic Graph)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topoSort(int i,stack<int> &ans,vector<int>&vis,vector<vector<int>>adj){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            topoSort(it,ans,vis,adj);
        }
    }
    ans.push(i);
}
int main(){
    int n;
    cout<<"Enter the number of vertices:"<<endl;
    cin>>n;
    vector<vector<int>>adj(n+1);
    int e;
    cout<<"Enter the number of edges:"<<endl;
    cin>>e;
    int u,v;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>vis(n+1,0);
    stack<int>ans;

    for(int i=0;i<n;i++){
        if(vis[i]==0){
            topoSort(i,ans,vis,adj);
        }
    }
    cout<<"Topological Sorting of Graph:"<<endl;
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }

   return 0;
}