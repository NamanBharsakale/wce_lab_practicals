#include <iostream>
using namespace std;

void getFibonacci(int n, int &fibm, int &fibm1, int &fibm2){
    fibm1 = 0;
    fibm2 = 1;
    fibm = fibm1 + fibm2;

    while (n > fibm)
    {
        fibm2 = fibm1;
        fibm1 = fibm;
        fibm = fibm1 + fibm2;
    }
    
}
int fibonacciSearch(int arr[],int n,int x){
    int fibm,fibm1,fibm2;

    getFibonacci(n,fibm,fibm1,fibm2);

    int offset = -1;

    while (fibm > 1)
    {
        int i = (offset + fibm2) > (n-1) ? (n-1) : (offset + fibm2);

        if(arr[i] > x){
            fibm = fibm2;
            fibm1 = fibm1 - fibm2;
            fibm2 = fibm - fibm1;
        }
        else if(arr[i] < x){
            fibm = fibm1;
            fibm1 = fibm2;
            fibm2 = fibm - fibm2;
            offset = i;

        }
        else{
            return i;
        }


    }

    if(fibm1 && offset + 1 < n && arr[offset + 1] == x){
        return offset + 1;
    }

    return -1;
    


}
int main(){
    int n;
    cout<<"How many numbers you want to store: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }

    int x;
    cout<<"Enter element to search: ";
    cin>>x;

    int res = fibonacciSearch(arr,n,x);
    if(res != -1){
        cout<<x<<" found at "<<res;
    }
    else{
        cout<<"Not found";
    }

    return 0;
}