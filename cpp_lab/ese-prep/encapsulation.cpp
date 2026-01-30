#include <iostream>
#include <string>
using namespace std;

//Private member -> Controlled Access
class Bank{
    private:
    int Ac_no;
    string Ac_holder;

    public:
    static int bct;
    void setDetails(int ac_no, string ac_holder){
        Ac_no = ac_no;
        Ac_holder = ac_holder;
        cout<<"New Account created.."<<endl;
        bct++;
    }

    void getDetails(){
        cout<<"Accout id: "<<Ac_no<<endl;
        cout<<"Account Name: "<<Ac_holder<<endl;
    }

    friend void getCount(Bank b);
};

int Bank::bct = 0;
void getCount(Bank b){
    cout<<"Total Accounts in Bank: "<<Bank::bct<<endl;
    cout<<"Your Account Id: "<<b.Ac_no;
    cout<<"Your Name: "<<b.Ac_holder;
}
int main(){
    Bank b1;
    b1.setDetails(12,"Ram");
    b1.getDetails();

    Bank b2;
    b2.setDetails(14,"Sham");
    b2.getDetails();

    Bank b3;
    b3.setDetails(16,"Naman");
    b3.getDetails();

    Bank b4;
    b4.setDetails(18,"Raman");
    b4.getDetails();

    getCount(b3);
}