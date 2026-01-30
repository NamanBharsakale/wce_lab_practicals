#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"How many elements want to store: ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements: ";
    
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    //Shell Sort

    for(int gap = n / 2; gap > 0; gap = gap / 2){
        for(int j = gap; j < n; j++){
            for(int i = j-gap; i >= 0; i= i - gap){
                if(a[gap + i] >= a[i]){
                    break;
                }
                else{
                    int t = a[gap+i];
                    a[gap+i] = a[i];
                    a[i] = t;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}