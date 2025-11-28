#include <iostream>
using namespace std;


void heapiFy(int a[],int n,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[largest] < a[left])
    {
        largest = left;
    }

    if(right < n && a[largest] < a[right]){
        largest = right;
    }


    if(largest != i){
        int t = a[largest];
        a[largest] = a[i];
        a[i] = t;
        heapiFy(a,n,largest);
    }
}

buildMaxheap(int a[],int n,int i){
    for(int i = n / 2 - 1 ; i >= 0; i--){
        heapiFy(a,n,i);
    }
}

void displayRelations(int a[],int n,int i,int parentValue = -1){
    if(n <= i){
        return;
    }

    if(i == 0){
        cout<<"root -> "<<a[i]<<endl;
    }

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n){
            cout<<"Left of "<<a[i]<<" -> "<<a[left]<<endl;
    }

    if(right < n){
        cout<<"Right of "<<a[i]<<" -> "<<a[right]<<endl;
    }

    displayRelations(a,n,left,a[i]);
    displayRelations(a,n,right,a[i]);
    
}
int main(){
    int n;
    cout<<"Enter the number of nodeS: ";
    cin>>n;

    int a[n];
    cout<<"Enter "<<n<<" nodes(preorder): ";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    buildMaxheap(a,n,0);

    cout<<"Maxheap: ";
    displayRelations(a,n,0);

    return 0;


}