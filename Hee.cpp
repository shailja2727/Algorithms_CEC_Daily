#include<iostream>
using namespace std;
int f(int n){
    if(n<=0){
        return 0;
    }
    cout<<n<<" ";
    n--;
    f(n);
}
int main(){
    int n;
    cout<<"Enter the number :"<<endl;
    cin>>n;
    f(n);
    return 0;
}