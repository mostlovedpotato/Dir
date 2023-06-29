Let us look at the complete specialization of a class Stack 
for string. 

stack2.hpp
```
#include "stack1.hpp"
#include <iostream>
#include <deque>
#include <string>
#include <cassert>

template<>
class stack<std::string> {
	private : 
		std::deque<std::string> elems;
	public: 
		void push(std::string const& );
		void pop();
		std::string const& top() const ;
		bool empty() const{
			return elems.empty();
		}
};

void stack<std::string>::push(std::string const& elem){
	elems.push_back(elem);
}
void stack<std::string>::pop() {
	assert(!elems.empty());
	elems.pop_back();
}
std::string const& stack<std::string>::top () const{
	assert(!elems.empty());
	return elems.back();
}
```
Here the implementation for the string stack is specialized.
