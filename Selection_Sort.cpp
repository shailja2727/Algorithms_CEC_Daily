#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int min_index;
    for(int i=0;i<n-1;i++){
        min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_index]>arr[j]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(arr[min_index],arr[i]);
        }
    }
    printf("Elements After Sorting :");
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}