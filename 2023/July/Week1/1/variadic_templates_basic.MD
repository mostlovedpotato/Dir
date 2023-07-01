Template parameters can be defined to accept an unbound number of template
arguments. These are called variadic templates.

```
#include <iostream>

void print(){

}

template<typename T,typename... Types>
void print( T firstArg, Types... args) {
	std::cout << firstArg << '\n';
	print(args...);
}
```
Also we have new type of operator sizeof... , It expands number of elements
the parameter pack contains.
```
template<typename T, typename... Types>
void print (T firstArg, Types... args) {
	std::cout << sizeof...(Types) << '\n'; 
	std::cout << sizeof...(args);
}
```

