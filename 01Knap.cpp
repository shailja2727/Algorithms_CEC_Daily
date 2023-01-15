#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int wt[],int val[],int W)
{
    int sol[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 ||j==0)
            {
                sol[i][j]=0;
            }
            else if(wt[i-1]>j)
            {
                sol[i][j]=sol[i-1][j];
            }
            else
            {
                sol[i][j]=max(sol[i-1][j],val[i-1]+sol[i-1][j-wt[i-1]]);
            }
        }
    }
    return sol[n][W];
}
int main()
{
    int n;
    cin>>n;
    int wt[n+1],val[n+1];
    int W;
    cin>>W;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int value=knapsack(n,wt,val,W);
    cout<<"Profit maximized:"<<value;

}