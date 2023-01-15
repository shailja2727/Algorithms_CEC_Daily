#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct
{
    int weight,val;
    float d;
}Item;
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}
float Frac_knapsack(Item items[],int n,int W)
{
    int totalWeight=0;
    float profit=0;
    for(int i=0;i<n;i++)
    {
        items[i].d=(float)items[i].val/items[i].weight;

    }
    sort(items,items+n,compare);
    for(int i=0;i<n;i++)
    {
        if(totalWeight + items[i].weight<= W) {
         profit += items[i].val ;
         totalWeight += items[i].weight;
       } 
       else 
        {
         int wt = W-totalWeight;
         profit += (wt * items[i].d);
         totalWeight += wt;
         break;
        }
      
    }
    cout<<"Total weight:"<<totalWeight<<endl;
    return profit;
}
int main()
{

    int n;
    cin>>n;
    Item items[n];
    int W;
    cin>>W;
    for(int i=0;i<n;i++)
    {
        cin>>items[i].weight>>items[i].val;
    }
    float max_p=Frac_knapsack(items,n,W);
    cout<<"Profit maximized"<<max_p;


}