#include <iostream>
using namespace std;
const int MAX_SIZE = 20;


void displayBinary(int T[],int n){
    for(int i = 0; i<n;i++){
        if(T[i] == -1) 
        {
            continue;
        }
        else{

            int left = 2*i+1;
            int right = 2*i+2;

            if(left < n && T[left] != -1){
                cout<<"Left of "<<T[i]<<" : "<<T[left]<<endl;
            }
            else{
                cout<<"Left of "<<T[i]<<" : NULL"<<endl;
            }

            if(right <n && T[right] != -1){
                cout<<"Right of "<<T[i]<<" : "<<T[right]<<endl;
            }
            else{
                cout<<"Right of "<<T[i]<<" : NULL"<<endl;
            }
        }

    }
}
int main(){
    int T[MAX_SIZE];
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    cout<<"Enter the tree nodes level-wise(-1 for NULL): ";
    for(int i = 0; i<n;i++){
        cin>>T[i];
    }

    displayBinary(T,n);

    return 0;
}