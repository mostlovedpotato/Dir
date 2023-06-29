We will try to implement stack template.

```
#include<vector>
#include<cassert>
#include <ostream>


template<typename T>
class stack{
    private:
        std::vector<T>  elems;
    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems.empty();
        }
};

template<typename T>
void stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template<typename T>
void stack<T>::pop (){
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T>
T const& stack<T>::top () const {
    assert(!elems.empty());
    return elems.back();
}
```

This would be basic implementation for stack with push, pop, peek operations. 

We would also like to have a output operator which will print all the elements of 
the stack .

``` 
void printOn( std::ostream& strm) const {
            for (T const& elem : elems){
                strm << elem << ' ';
            }
        }
```
So, we can have above function to do that. 

In the main.cpp file.
```
#include "stack1.hpp"
#include <iostream>
#include <string>
#include <fstream>


int main()
{
    stack<int> intStack;
    stack<std::string> stringStack;
    
    intStack.push(7);
    std::cout << intStack.top() << '\n';
    
    stringStack.push("Newherehuh?");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();
    // stringStack.pop();  // Will give an assert for the second pop as it is empty stack
    std::string filename = "Test.txt";
    std::ofstream ofstrm(filename, std::ios::binary );
    // ofstrm << "Hello Inside from the File, Hehe!\n"; // This would write in Test.txt
    
    stack<std::string> ps;
    ps.push("Prash");
    ps.push("Timus");
    // ps.printOn(std::cout);
    ps.printOn(ofstrm); // Will make a file Test.txt and have text Prash Timus

    return 0;
}
```
and our stack1.hpp

```
#include<vector>
#include<cassert>
#include <ostream>


template<typename T>
class stack{
    private:
        std::vector<T>  elems;
    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems.empty();
        }
        void printOn( std::ostream& strm) const {
            for (T const& elem : elems){
                strm << elem << ' ';
            }
        }
};

template<typename T>
void stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template<typename T>
void stack<T>::pop (){
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T>
T const& stack<T>::top () const {
    assert(!elems.empty());
    return elems.back();
}
```
We can introduce an operator + which will add value to each element on the stack.

```
void operator+ (int value){
            for(auto& elem : elems){
                elem += value;
            }
        }
```

And for operator << also to print out the elements istead of using the function 
we can use the opeartor << overloading as,
```
friend std::ostream& operator<< (std::ostream& strm, stack<T> const& s ){
            s.printOn(strm);
            return strm;
        }
```
We overloaded the operator << 
now, let's see it in action.

Out stack1.hpp file,

```
#include<vector>
#include<cassert>
#include <ostream>
#include <iostream>


template<typename T>
class stack{
    private:
        std::vector<T>  elems;
    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems.empty();
        }
        void printOn( std::ostream& strm) const {
            for (T const& elem : elems){
                strm << elem << ' ';
            }
        }
        void operator+ (int value){
            for(auto& elem : elems){
                elem += value;
                // std::cout << elem << '\n';
            }
        }
        // for + operator we did it knowing we have this reference to current object
        // calling the operator.
        friend std::ostream& operator<< (std::ostream& strm, stack<T> const& s ){
            s.printOn(strm);
            return strm;
        }
};

template<typename T>
void stack<T>::push (T const& elem){
    elems.push_back(elem);
}

template<typename T>
void stack<T>::pop (){
    assert(!elems.empty());
    elems.pop_back();
}

template<typename T>
T const& stack<T>::top () const {
    assert(!elems.empty());
    return elems.back();
}
```
and our main.cpp

```
#include "stack1.hpp"
#include <iostream>
#include <string>
#include <fstream>


int main()
{
    stack<int> intStack;
    stack<std::string> stringStack;
    
    intStack.push(7);
    std::cout << intStack.top() << '\n';
    
    stringStack.push("Newherehuh?");
    std::cout << stringStack.top() << '\n';
    stringStack.pop();
    // stringStack.pop();
    std::string filename = "Test.txt";
    std::ofstream ofstrm(filename, std::ios::binary );
    // ofstrm << "Hello Inside from the File, Hehe!\n";
    
    stack<std::string> ps;
    ps.push("Prash");
    ps.push("Timus");
    // ps.printOn(std::cout);
    ps.printOn(ofstrm);
    intStack+5;
    intStack.printOn(std::cout);
    intStack.push(31);
    std::cout << intStack << '\n';
    
    return 0;
}
```
Giving us output
```
7
Newherehuh?
12 12 31
```
