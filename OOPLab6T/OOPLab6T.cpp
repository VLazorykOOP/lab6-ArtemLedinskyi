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
class GeomFig{
    protected:
    double area;
    public:
    virtual ~GeomFig(){
    }
    virtual void print()=0;
    virtual void read()=0;
friend ostream& operator<<(ostream& os , GeomFig& Fig){
    Fig.print();
    return os;
}
friend istream& operator>>(istream& is , GeomFig& Fig){
    Fig.read();
    return is;
}
};
class Circle:public GeomFig{
    protected:
    double radius;
    public:
    Circle(double radius){
        this->radius=radius;
        area=3.14*radius*radius;
    }
    virtual ~Circle(){
    }
    void print()override{
        cout<<"Circle : Radius is "<<radius<<endl;
    }
    void read()override{
        cout<<"Enter circle radius ";
        cin>>radius;
        area=3.14*radius*radius;
    }
friend ostream& operator<<(ostream& os , Circle circ){
    circ.print();
    return os;
}
friend istream& operator>>(istream& is , Circle& circ){
    circ.read();
    return is;
}
};
class Square:public GeomFig{
protected:
double side;
public:
Square(double side){
    this->side=side;
    area=side*side;
}
virtual ~Square(){

}
void print()override{
    cout<<"Square : Side is "<<side<<endl;
    cout<<"Square : Area is "<<area<<endl;
}
void read()override{
    cout<<"Enter square side : ";
    cin>>side;
    area=side*side;
}
friend ostream& operator<<(ostream& os , Square& sq){
   sq.print();
    return os;
}
friend istream& operator>>(istream& is , Square& sq){
    sq.read();
    return is;
}
};
class SqinsideCircle: public Circle , public Square{
public:
SqinsideCircle(double S=0):Circle(S/2),Square(S){
    Circle::area=3.14*(S/2)*(S/2);
}
void print()override{
    cout<<"Square inside Circle : side is "<<side<<endl;
    cout<<"Radius is "<<radius<<endl;
    cout<<"Area is "<<Circle::area<<endl;
}
void read()override{
    cout<<"Enter square side ";
    cin>>side;
    radius=side/2;
    Circle::area=3.14*radius*radius;
}
friend ostream& operator<<(ostream& os ,SqinsideCircle SIC ){
    SIC.print();
    return os;
}
friend istream& operator>>(istream& is ,SqinsideCircle SIC ){
    SIC.read();
    return is;
}
};

void Ex3(){
    Circle C(5);
    cout<<C<<endl;
    Circle C1(0);
    cin>>C1;
    cout<<C1<<endl;
    Square S(2);
    cout<<S<<endl;
    Square S1(0);
    cin>>S1;
    cout<<S1<<endl;
    SqinsideCircle SIC(6);
    cout<<SIC<<endl;
    SqinsideCircle SIC1(2);
    cin>>SIC1;
    cout<<SIC1;
    return 0;
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
        Ex3();
    }
    return 0;
}
