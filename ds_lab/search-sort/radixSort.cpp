#include <iostream>
using namespace std;
#define MAX 15

class Q{
    public:
    int a[MAX];
    int front;
    int rear;
    public:
    Q(){
        front = -1;
        rear = -1;
    }

    void push(int val){
        if(rear == MAX -1 ){
            cout<<"Overflow , Queue is full";
            return;
        }

        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = rear + 1;
        }

        a[rear] = val;
    }

    int getfront(){
        if(front == -1){
            return -1;
        }
        return a[front];
    }

    void pop(){
        if(front == -1 && rear == -1){
            return;
        }

        if(front == rear || front == MAX - 1){
            front = -1;
            rear = -1;
        }
        else{
            front = front + 1;
        }
    }

    bool isEmpty(){
        return (front == -1);
    }
};

int getMax(int a[],int n){
    int max = a[0];
    for(int i =1; i<n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }

    return max;
}

void radixSort(int a[], int n){
    int maxVal = getMax(a,n);
    int maxDigit = 0;

    while(maxVal > 0){
        maxDigit++;
        maxVal /= 10;
    }

    int divisor = 1;
    for(int pass = 1 ; pass <= maxDigit; pass++){
        Q bucket[10];

        for(int i = 0; i<n; i++){
            int digit = (a[i]/divisor) % 10;
            bucket[digit].push(a[i]);
        }

        int index = 0;
        for(int i =0; i<n; i++){
            while(!bucket[i].isEmpty()){
                a[index++] = bucket[i].getfront();
                bucket[i].pop();
            }
        }
        divisor = divisor * 10;
    }
}

void displayArr(int a[],int n){
    for(int i = 0; i < n ; i++){
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
    