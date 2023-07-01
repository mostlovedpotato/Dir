For printing out the args. We can use fold expressions as below..

```
template<typename... Types>
void print (Types const&... args) {
	(std::cout << ... << args) << '\n';
}
```
But what about printing out the spaces between the arguments if we want to 
include them... 
we can use something like

```
(std::cout << ... << someFunction(args)) << '\n';
```
here someFunction will provide us with the functionality to get the 
whitespace in between the arguments.

```
template<typename T>
class AddSpace {
	private:
		T const& ref;
	public:
		AddSpace (T const& ref) : ref(r) {
		}
		friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) {
			os << s.ref << ' ';
			return os;
		}
};

template<typename... Args>
void print (Args... args) {
	(std::cout << ... << AddSpace(args)) << '\n';
}
```

Here is the implementation ... with usage of printDouble

```
#include <iostream>
#include <string>

using namespace std;
 

// template<typename ...Args> 
// auto sum2(Args ...args) 
// { 
//     return (args + ...);
// }

template<typename T>
class AddSpace {
	private:
		T const& ref;
	public:
		AddSpace (T const& r) : ref(r) {
		}
		friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) {
			os << s.ref << ' ';
			return os;
		}
};

// template<typename... Args>
// void print (Args&&... args) {
// 	(std::cout << ... << forward<Args>(AddSpace(args))) << '\n'; // this doesn't work
// }

template<typename ...Args>
void print(Args&&... args) {
    (cout  <<  ... <<  AddSpace(forward<Args>(args))) << '\n' ;
}


template<typename... T>
void printDoubled (T const&... args)
{
    print(args + args...);
}

int main()
{
    // FoldPrint("hello", ", ", 10, ", ", 90.0);
    printDoubled(1.2, 44 , 44);
}
```

Adding one to every argument 

```
template<typename... T>
void addOne (T const&... args)
{
	print (args + 1...);
		// ERROR: 1... is a literal with too many decimal points
	print (args + 1 ...);
		// OK
	print ((args + 1)...);
		// OK
}
```

