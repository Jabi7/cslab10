#include<iostream>

using namespace std;

class rectangle
{
	
public:
	double l,b;
	void inp(void){
		cout<<"\nenter leangth : ";
		cin>>l;
		cout<<"enter breadth : ";
		cin>>b;
	}

	

	
	double area(double x,  double y){
		return x*y;
	}
	

	double perimeter(double x,  double y){
		return 2*(x+y);
	}
	

	void outp(void){
		cout<<"\narea : ";
		cout<<area(l,b);
		cout<<"\nperimeter : ";
		cout<<perimeter(l,b)<<"\n";
	}
	
	
};

int main()
{
	rectangle r1,r2;
	cout<<"rectangle 1\n";
	r1.inp();
	cout<<"\nrectangle 2\n";
	r2.inp();
	cout<<"\nrectangle 1\n";
	r1.outp();
	cout<<"\nrectangle 2\n";
	r2.outp();
	;
	if(r1.area(r1.l,r1.b)==r2.area(r2.l,r2.b))cout<<"\nthey have same area"; else cout<<"\nthey dont have same area";
	if(r1.perimeter(r1.l,r1.b)==r2.perimeter(r2.l,r2.b))cout<<"\nthey have same perimeter"; else cout<<"\nthey dont have same perimeter";
	cout<<endl;
	return 0;
}