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
}
#include<iostream>
using namespace std;
class Base{
    protected:
    int dat;
    public:
    Base():dat(1){}
    Base(int d):dat(d){}
};
class R1:protected Base{
    protected:
    int d1;
    public:
    R1():d1(1){}
    R1(int d):d1(d){}
    R1(int a , int b):Base(a),d1(b){}
};
class R2:protected Base{
    protected:
    int d2;
    public:
    R2():d2(1){}
    R2(int d):d2(d){}
    R2(int a , int b):Base(a),d2(b){}
};
class R3:protected R1{
    protected:
    int d3;
    public:
    R3():d3(1){}
    R3(int d):d3(d){}
    R3(int a, int b, int d):R1(a,b),d3(d){}
};
class R4:protected R3{
    protected:
    int d4;
    public:
    R4():d4(1){}
    R4(int d):d4(d){}
    R4(int a,int b ,int c, int v,int g,int u):R3(c,v,g),d4(u){}
};
class R5:protected R2,protected R3{
    protected:
    int d5;
    public:
    R5():d5(1){}
    R5(int d):d5(d){}
    R5(int a,int b , int c ,int v ,int g, int u,int m):R2(b,c),R3(v,g,u),d5(m){}
};
class R1V:virtual protected Base{
    int d1;
    public:
    R1V():d1(1){}
    R1V(int d):d1(d){}
    R1V(int a , int b):Base(a),d1(b){}
};
class R2V:virtual protected Base{
    protected:
    int d2;
    public:
    R2V():d2(1){}
    R2V(int d):d2(d){}
    R2V(int a , int b):Base(a),d2(b){}
};
class R3V:virtual protected R1V{
    protected:
    int d3;
    public:
    R3V():d3(1){}
    R3V(int d):d3(d){}
    R3V(int a, int b, int d):R1V(a,b),d3(d){}
};
class R4V:virtual protected R1V, protected R3V{
    protected:
    int d4;
    public:
    R4V():d4(1){}
    R4V(int d):d4(d){}
    R4V(int a,int b ,int c, int v,int g,int u):R1V(a,b),R3V(c,v,g),d4(u){}
};
class R5V:virtual protected Base,protected R2V,protected R3V{
    protected:
    int d5;
    public:
    R5V():d5(1){}
    R5V(int d):d5(d){}
    R5V(int a,int b , int c ,int v ,int g, int u,int m):Base(a),R2V(b,c),R3V(v,g,u),d5(m){}
};
void Ex1(){
    Base b;
    R1 r1;
    R2 r2;
    R3 r3;
    R4 r4;
    R5 r5;
    R1V r1v;
    R2V r2v;
    R3V r3v;
    R4V r4v;
    R5V r5v;

    cout<<"Size of Base: "<<sizeof(b)<<endl;
    cout<<"Size of R1: "<<sizeof(r1)<<endl;
    cout<<"Size of R2: "<<sizeof(r2)<<endl;
    cout<<"Size of R3: "<<sizeof(r3)<<endl;
    cout<<"Size of R4: "<<sizeof(r4)<<endl;
    cout<<"Size of R5: "<<sizeof(r5)<<endl;
    cout<<"Size of R1V: "<<sizeof(r1v)<<endl;
    cout<<"Size of R2V: "<<sizeof(r2v)<<endl;
    cout<<"Size of R3V: "<<sizeof(r3v)<<endl;
    cout<<"Size of R4V: "<<sizeof(r4v)<<endl;
    cout<<"Size of R5V: "<<sizeof(r5v)<<endl;
}
int main(){
    int a;
    cout<<"Exercise :"<<endl;
    cin>>a;
    if(a==1){
        Ex1();
    }
    if(a==2){
        Ex2();
    }
    if(a==3){
        Ex3();
    }
    return 0;
}
