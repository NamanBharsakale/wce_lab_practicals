#include <iostream>
using namespace std;

class BankAccount{
    private:
    double balance;
    public:
    void deposite(double amount){
        if(amount >= 0){
            balance += amount;
            cout<<"Amount is deposited.."<<endl;
        }
    }

    void withdrawn(double amount){
        if(balance >= amount){
            balance -= amount;
            cout<<"Amount is withdrawn.."<<endl;
        }
    }

    void showBalance(){

        cout<<"Available balance is "<<balance<<endl;
    }


};

int main(){
    BankAccount bk;
    bk.deposite(2200);
    bk.showBalance();
    bk.withdrawn(1100);
    bk.showBalance();



    return 0;

}