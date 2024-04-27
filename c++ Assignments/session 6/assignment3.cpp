#include<iostream>
#include <string>
#include <vector>
using namespace std;




class Shape
{

   protected:
   string name;
   public:
   Shape(const string& NameVar):name(NameVar){};
   string getName(void)const {return name;}
   virtual double calculateArea()const {}
    double calculateVolume() const{}

};

class Rectangle : public Shape
{
   double Width;
   double Length;

   public:
   Rectangle(const string& name, double Width, double Length)
   :Shape(name), Width(Width), Length(Length) {};
   void setWidth(double width){Width = width;}
   void setLength(double length){Length = length;}
   double calculateArea()const {
    return Width*Length;
   }
   

};

class Circle : public Shape
{
  double radius;
  public:
  Circle(const string& name, double Radius)
  : Shape(name), radius(Radius){};
  void setRaduis(double rad){radius = rad;}
   double calculateArea()const {
    return radius*radius*3.14;
   }
  
};

class Triangle : public Shape
{
  double Height;
  double Base;
  public:
  void setBase(double base){Base=base;}
   void setHeight(double height){Height = height;}
   double calculateArea()const {
    return Height*Base*0.5;
   }
   

};


class ThreeDimensionalShape : public Shape
{  
 
   public:
    ThreeDimensionalShape(const string& name) : Shape(name) {}
   virtual double calculateVolume() const
   {
  
   }
};

class Sphere: public ThreeDimensionalShape
{
  double radius;
  public:
    Sphere(const string& name, double Radius)
        : ThreeDimensionalShape(name), radius(Radius) {}
   void setRaduis(double Raduis) {radius = Raduis;} 
   double calculateArea()const {
    return radius*radius*4*3.14;
   }
   
  double calculateVolume() const
   {
    return (4.0 / 3.0) * 3.14*radius*radius*radius;
   }

};



int main (void)
{
  Circle circle("Circle", 4);
  Sphere sphere("Sphere", 6);
 cout<<"name is "<<circle.getName()<<" area is "<<circle.calculateArea()
 <<" volume is "<<circle.calculateVolume()<<endl;

  cout<<"name is "<<sphere.getName()<<" area is "<<sphere.calculateArea()
 <<" volume is "<<sphere.calculateVolume()<<endl;
  return 0;
}
