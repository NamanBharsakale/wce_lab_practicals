#include <iostream>
#include <string>
using namespace std;


class Employee{
    int emp_id;
    string emp_name;

    public:
    static int ect;


    void setData(int eid, string ename){
        emp_id = eid;
        emp_name = ename;
        ect++;
    }

    void getData(){
        cout<<"Emp Id: "<<emp_id<<endl;
        cout<<"Emp Name: "<<emp_name<<endl;
    }

    static void showCount(){
        cout<<"Toatl number of employees are: "<<ect;
    }
};

int Employee::ect = 0;
int main(){

    int n;
    cout<<"ENter the number of employees: ";
    cin>>n;

    Employee e[n];

    int id;
    string name;
    for(int i = 0; i < n ; i++){
        cout<<"Enter the id and name for "<<i+1<<" employee: ";
        cin>>id>>name;
        e[i].setData(id,name);
        e[i].getData();
    }

    Employee::showCount();

    

}