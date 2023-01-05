#include<iostream>
#include<vector>
using namespace std;
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
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            cout<<"Element'"<<x<<"'found at index :"<<i;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Element Not Found"<<endl;
    }
    return 0;
}