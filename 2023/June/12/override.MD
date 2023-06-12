virtual function overriding is what makes possibe to invoke
a derived class function through base class interface: 

```
class Base{
	public:
	virtual void doWork();
	...
};

class Derived: public Base{
	public:
	virtual void doWork(); // overrides doWork virtual is optional here
	...
};

std::unique_ptr<Base> upb = std::make_unique<Derived>();
// base class pointer to dervied class object;

upb->doWork(); // call doWork through base class ptr,dervied class 
// function is invoked.

```

Overriding conditions - 
	1. The base class must be virtual.
	2. Function names should be identical in base and derived.
	3. Parameter types must be same
	4. constantness of both should be same
	5. return type and exception specifications of functions.
	6. - > new property a functions reference qualifiers must be identical.


```
class Base{
	public:
	virtual void f1() const;
	virtual void f2(int x);
	virtual void f3() &;
	void f4() const;
};

class Derived: public Base{
	public:
	virtual void f1();
	virtual void f2(unsigned x);
	virtual void f3() &&;
	void f4( ) const;
};
```
Some compilers won't even give warnings for compiling above code.


Here is an example to understand the part of using override and virtual keyword

```
#include <iostream>

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area(int a)  {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shape1 = new Rectangle(4.0, 5.0);
    Shape* shape2 = new Circle(3.0);

    std::cout << "Area of shape1 (Rectangle): " << shape1->area() << std::endl;
    std::cout << "Area of shape2 (Circle): " << shape2->area() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
```
This results - 
Area of shape1 (Rectangle): 0
Area of shape2 (Circle): 28.2743

Here rectangle is not working as the signature doesn't match up.
so, whenever defining overriding functions, provide override keyword.

And if we add override for the two functions now 
we get the error as below 
```
main.cpp:18:12: error: ‘double Rectangle::area(int)’ marked ‘override’, but does not override
   18 |     double area(int a) override {
      |            ^~~~
```
So, this is quite important sometimes you might mistakenly declare wrong 
declaratons and normally compiler won't give you warning.
So, better code here is: 

```
#include <iostream>

class Shape {
public:
    virtual double area() const {
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Shape* shape1 = new Rectangle(4.0, 5.0);
    Shape* shape2 = new Circle(3.0);

    std::cout << "Area of shape1 (Rectangle): " << shape1->area() << std::endl;
    std::cout << "Area of shape2 (Circle): " << shape2->area() << std::endl;

    delete shape1;
    delete shape2;

    return 0;
}
```
giving us the proper output areas.

