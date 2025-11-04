#include <iostream>
#include <queue>
using namespace std;

int maxVal(int a[],int n){
    int max = a[0];

    for(int i = 1; i < n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

void radixSort(int a[],int n){
    int max = maxVal(a,n);
    int maxDigit = 0;

    while(max > 0){
        maxDigit++;
        max = max /10;
    }
    int divisor = 1;
    for(int pass = 1; pass <= maxDigit; pass++){
        queue<int> bucket[10];

        for(int i = 0 ; i < n ; i++){
                int digit = (a[i] / divisor) % 10;
                bucket[digit].push(a[i]);
            
        }

        int index = 0;
        for(int i = 0; i < n ; i++){
            while(!bucket[i].empty()){
                a[index++] = bucket[i].front();
                bucket[i].pop();
            }
        }
        divisor *= 10;
    }
}
void displayArr(int a[],int n){
    for(int i =0 ; i < n ; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"How many elements you want to store: ";
    cin>>n;

    int a[n];

    cout<<"Enter "<<n<<" elements: ";
    for(int i = 0; i <n;i++){
        cin>>a[i];
    }

    cout<<"Original Array: ";
    displayArr(a,n);

    radixSort(a,n);

    cout<<"Sorted Array : ";
    displayArr(a,n);

    return 0;
}
    