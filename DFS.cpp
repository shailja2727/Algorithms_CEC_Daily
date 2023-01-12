#include<iostream>
#include<vector>
using namespace std;
void dfs(int i,vector<int> &ans,vector<int>&vis,vector<vector<int>>adj){
    vis[i]=1;
    ans.push_back(i);
    for(auto it:adj[i]){
        if(!vis[it]){
            dfs(it,ans,vis,adj);
        }
    }

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
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    vector<int>ans;

    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,ans,vis,adj);
        }
    }
    cout<<"DFS Traversal of Graph:"<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

   return 0;
}