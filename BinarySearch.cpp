#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int> arr,int x,int n){
    int low=0;
    int high=n-1;
    int mid;
    while(high>=low){
        mid=low+(high-low)/2;
        if(arr[mid]==x)
            return mid;
    
        else if(arr[mid]>x)
            high=mid-1;
        
        else
            low=mid+1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x;
    cout<<"Enter the number to be searched:"<<endl;
    cin>>x;
    int ans=binary_search(arr,x,n);
    if(ans==-1)
    cout<<"Element Not Found"<<endl;
    else
    cout<<"Element '"<<x<<"' found at index:"<<ans<<endl;
    return 0;
    
}