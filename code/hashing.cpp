#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    int hash[13]= {0};//if constraint is there of 10^3 then hash[1000] = {0}
    for(int i = 0; i <n;i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin>>q;
    while(q--){
        int numbers;
        cin>>numbers;
        cout<<hash[numbers]<<endl;
    }
}