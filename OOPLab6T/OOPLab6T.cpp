#include<iostream>
#include<map>
using namespace std;

class Employee{
protected:
double rate;
string name;
public:
Employee(string name, double rate){
    this->rate=rate;
    this->name=name;
}
virtual double Calculate()=0;
};
class HourlyEmp:public Employee{
private:
int hours;
public:
HourlyEmp(string name,double rate, int hours):Employee(name,rate){
    this->hours=hours;
}
double Calculate(){
    return rate*hours;
}
};
class SalariedEmp:public Employee{
private:
double salary;
public: 
SalariedEmp(string name , double rate,double salary):Employee(name,rate){
    this->salary=salary;
}   
double Calculate(){
    return salary;
}
};
class PercentageEmp:public Employee{
    private:
    double sales;
    double percent;
    public:
    PercentageEmp(string name, double rate ,double sales , double percent):Employee(name,rate){
        this->sales=sales;
        this->percent=percent;
    }
    double Calculate() {
        return rate + (sales * percent);
    }
};
void Ex2(){
    Employee* employes[3];
    employes[0]=new HourlyEmp("Vasya Pupkin",1337,24);
    employes[1]=new SalariedEmp("Evkakiy Apanasiov",322,1991);
    employes[2]=new PercentageEmp("Motivator Petro", 14.5 , 131415,0.20);
    for(int i=0;i<3;i++){
        cout<<"Person "<<i<<" : ";
        cout<<employes[i]->Calculate()<<endl;
        delete employes[i];
    }
}
int main(){
    int a;
    cout<<"Exercise :"<<endl;
    cin>>a;
    if(a==1){

    }
    if(a==2){
        Ex2();
    }
    if(a==3){
        
    }
    return 0;
}
