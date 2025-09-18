#include <iostream>
using namespace std;

class Square {
private:
    int L; 

public:
    void setLength(int L) {
        this->L = L;  
    }

    int calculateArea() {
        return L * L;
    }
};

int main() {
    int inputLength;
    cin >> inputLength;

    Square s;
    s.setLength(inputLength);    
    cout << s.calculateArea();  

    return 0;
}
