#include<iostream>
using namespace std;
void heapify(int *arr,int n,int i){
    int left=2*i+1;//left child
    int right=2*i+2;//right child
    int maxii=i;
    if(left<n && arr[left]>arr[maxii]){
        maxii=left;
    }
    if(right<n && arr[right]>arr[maxii]){
        maxii=right;
    }
    if(maxii!=i){
        swap(arr[maxii],arr[i]);
        heapify(arr,n,maxii);//called for tree below it
    }
}
void buildheap(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);//rightmost internal node
    }
    //Heapify for rest of the elements other than maximum (Heap Sort)
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    buildheap(arr,n);
    cout<<"Array after applying HeapSort:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}