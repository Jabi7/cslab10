//Using C++ to set and move points using classes and objects on the XY plane
#include <iostream>        //library header

using namespace std;       //namespace

// ********************************************************************
//  Declaration of class Point
// ********************************************************************

// class Point represents a two-dimensional point
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 

  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);

  // member function for moving a point by dx, dy:
  void Move(int dx, int dy);

  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;

  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);

//Lab 7 exercise 4.1. Add declaration of member function Print here:

  void print();

// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  


// ********************************************************************
//  Methods for class Point
// ********************************************************************

// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}

// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}

// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}

// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}

// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}

// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 

// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
    

//Lab 7 exercise 4.1. Add definition of member function print:

void Point::print()            //definition of member function print
{
        cout<<"("<<X<<","<<Y<<")"<<endl;
}


// ********************************************************************
//  Declaration of class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 

class Rectangle: public Point                      //class Point gets inherited publicly to class Rectangle
{
	//point objects declared
	Point p1, p2, p3, p4;
	public:
		Rectangle(Point,Point);           //parameterized constructor
		Rectangle();                      //default constructor that builds a rectangle with coordinates (0,0), (0,1), (1,0), (1,1)
	
	private:
		int side1();                      //member functions to calculate length of sides
		int side2();
	
	public:
		int area();                       //member function to calculate the area of the rectangle
		int l1,l2;                        //variables to store length of sides
		
	int my_side1();                       //function to access returned data from private member functions side1 
	
	int my_side2();	                      //function to access returned data from private member functions side2
	
		
};


// ********************************************************************
//  Methods for class Rectangle
// ********************************************************************

//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE:

Rectangle::Rectangle()
{
	//assigns default values to points p1,p2,p3,p4
	p1.Set_X(0);
	p1.Set_Y(0);

	p2.Set_X(0);
	p2.Set_Y(1);

	p3.Set_X(1);
	p3.Set_Y(1);

	p4.Set_X(1);
	p4.Set_Y(0);
	
	//displays these points
	cout<<"The coordinates are:\n";
	cout<<"First point:"<<endl;
	p1.print();
	cout<<endl<<"Second point:"<<endl;
	p2.print();
	cout<<endl<<"Third point:"<<endl;
	p3.print();
	cout<<endl<<"Fourth point:"<<endl;
	p4.print();
	cout<<endl;
} 

Rectangle::Rectangle(Point a, Point b)
{
	p1 = a;
	p3 = b;
	//assigns coordinate values for remaining points on the rectangle
	p2.Set_X(p1.Get_X());
	p2.Set_Y(p3.Get_Y());

	p4.Set_X(p3.Get_X());
	p4.Set_Y(p1.Get_Y());
	
	//displays the coordinates of the rectangle 
	cout<<"Coordinates of first point: "<<endl;
    p1.print();
    cout<<endl;
    cout<<"Coordinates of second point: "<<endl;
	p2.print();
    cout<<endl;
    cout<<"Coordinates of third point: "<<endl;
    p3.print();
    cout<<endl;
	cout<<"Coordinates of fourth point: "<<endl;
	p4.print();
	cout<<endl;
}

int Rectangle::side1()                       //function definition of private member function side1()
{
	l1 = p2.Get_Y() - p1.Get_Y();
	
}

int Rectangle::side2()                       //function definition of private member function side2()
{
	l2 = p4.Get_X() - p1.Get_X();

}

int Rectangle::area()						 //function definition of public member function area()
{
	return l1*l2;
}

int Rectangle::my_side1()
{
	side1();
	return l1;	
}

int Rectangle::my_side2()
{
	side2();
	return l2;	
}



// ********************************************************************
//  main() function for testing classes Point and Rectangle
// ********************************************************************



// Testing classes Point and Rectangle
int main()
{
// Declaring a point using default class constructor (x = y = 0):
  Point po1;
  cout<< "The coordinates of po1 are: ";
  po1.print();
  cout<<endl;

// Declaring a point with coordinates X = 2, Y = 3:
  Point po2(2, 3);
  cout<< "The coordinates of po2 are: ";
  po2.print();

// Moving point po2 by (1, -1):
  po2.Move(1, -1);
  cout<< "After the move:" << endl;
  cout<< "The x value for po2 is " << po2.Get_X() << endl;
  cout<< "The y value for po2 is " << po2.Get_Y() << endl;

//Lab 7 exercise 4.1. Test member function print on points po1, po2:
  cout<< "The coordinates are ";
  po2.print();
  cout<<endl<<endl;
  
  
//asks user the coordinates for 2 points using which a rectangle is to be made
  int xval,yval;                                                    //variables for assigning coordinates to points p1 and p3
  cout<<"Enter coordinates of 1st point"<<endl;
  cout<<"Enter x coordinate: "<<endl;
  cin>>xval;
  cout<<endl;
  cout<<"Enter y coordinate: "<<endl;
  cin>>yval;
  Point p1(xval,yval);
  cout<<endl;
  cout<<"Enter coordinates of 2nd point"<<endl;
  cout<<"Enter x coordinate: "<<endl;
  cin>>xval;
  cout<<endl;
  cout<<"Enter y coordinate: "<<endl;
  cin>>yval;
  cout<<endl;
  Point p3(xval,yval);
    

//Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here: 
    
  //Displays coordinates of rectangle ob1
  cout<<"Rectangle ob1:"<<endl;
  Rectangle ob1;
  
  
  //Displays coordinates of rectangle ob2
  cout<<"Rectangle ob2:"<<endl;
  Rectangle ob2(p1,p3);
  
  
  //displays the sides of the rectangle
  cout<<"The sides of the rectangle are: \n";
  cout<<ob2.my_side1()<<" & "<<ob2.my_side2()<<endl;
  
  //displays the area of the rectangle
  cout<<"The area of the rectangle: "<<ob2.area();
  
  //return statement
  return 0;
}

//---------------------- point.cpp ------------------------------------//