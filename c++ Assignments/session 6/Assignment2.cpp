#include<iostream>
#include <string>
#include <vector>
using namespace std;




class Shape
{
protected:
string Color;

public:
Shape():Color("null"){};
Shape(const string& color) : Color(color) {}
virtual double getArea(void)const {
  return 0.0;
}

};

class Rectangle:public Shape
{
  double width;
  double height;

  public:
  Rectangle(string color , double heightVar , double widthVar):Shape(color),height(heightVar),width(widthVar){};
  double getWidth(void) {return width ;}
  double getHeight(void) {return height ;}

  double getArea(void) const{
    return width*height;
   }
};

class Circle:public Shape
{
  double radius;
  public:
  Circle(string color ,double radiusVar):Shape(color),radius(radiusVar){};
  double getArea(void) const
  {
    return radius*radius;
  }
};


class Triangle:public Shape
{
  double base;
  double height;
  public:
  Triangle(string color, double baseVar , double heightVar):Shape(color),base(baseVar),height(heightVar){};
  double getArea(void) const
  {
    return 0.5*base*height;
  }
};


int main (void)
{

double Area;
Triangle obj ("red" ,8.1 , 9);
Area = obj.getArea();
cout<<"Area is " << Area;
  return 0;
}