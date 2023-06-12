Enums in general are global defined and you can access
them anywhere.
```
#include<iostream>

enum day {monday, tuesday, wednesday, thursday, friday, saturday, sunday};
enum month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int main(){
	month m = jan;
	if(m == monday){
		std::cout << "Hello there \n";
	}
}
```
Logically this should not work but you know it works. 
Here we want them to be of different types.
So, instead of defining them directly we can use scoped enums.

```
#include<iostream>

enum class day {monday, tuesday, wednesday, thursday, friday, saturday, sunday};
enum class month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

int main(){
	month m = month::jan;
	if(m == day::monday){
		std::cout << "Hello there \n";
	}
}
```
Here now they are scoped enums now and we need to use, 
enum classname and then scope resolution op to get the 
particular enum value. Here it is sorted and even would 
say there is no match between types - month and day

Also similar problem is for - 
```
enum Color {black, red, white};
auto white = false; // error! white already declared
```
while when using scoped ones,
```
enum class Color {black, violet, red, white};
auto white = false; // works fine

Color c = white; // error! no enumerator white in this scope

Color d = Color::white; // works fine 
```
Scoped enums are also called enum classes.
Another reason to prefer scoped enums is as
Unscoped enums implicitly conver to integral types.
Therefore below code is valid.

```
enum Color {black, red, orange};

std::vector<std::size_t> primeFactorize(std::size_t x);

Color c = red;
...

if(c < 4.5){ // comparing color to double
	auto factors = primeFactorize(c); // computing prime factor of color
	...
}
```
But if instead we use scoped enums, then 
```
enum Color {black, red, orange};

std::vector<std::size_t> primeFactorize(std::size_t x);

Color c = red;
...

if(c < 4.5){ // error! can't compare color to double
	auto factors = primeFactorize(c); // error! can't pass color expecting size_t
	...
}
```

Then you might think if we want to compare color to integer deliberately then 
what to do.
Then we cast the types.

```
if(static_cast<double>(c) < 4.5){
	auto factors = primeFactorize(static_cast<std::size_t>(c));
	...
}
```

There is another advantage of using scoped enums and that is
forward declaration.

```
enum Color; // error!
enum class Color; // works fine!
```
We have to know that every enum in C++ has an integral underlying type.
for ex. 

```
enum Color {black, violet, red};
```
compilers might choose underlying char type. 
However some enums have large values 
ex. 
```
enum Status {good = 0, failed = 1, incomplete = 100, corrupt = 200, intermediate = 0xffffff};
```
So, compiler will choose the smallest type that fits the enum type.
So, C++98 help compilers to choose the type when we define it and that's why 
we can't forward declare them.

Now we discuss the problem with this.
The above status enum is the type of enum that we would like to use it 
throughout the system, and hence included in the header files on which
every part of the system is dependent on. 
Now if we introduce a new value into the enum Status
```
enum Status {
	good = 0,
	failed = 1,
	incomplete = 100,
	corrupt = 200,
	audited = 500,
	indeterminate = 0xffffff
};
```
Then now, we will have to recompile entire system. Even if only one 
subsystem is using the enum values from Status. This kind of thing is what
most people hate. 

but using forward declaration we avoid this.
we can have perfect header file.
```
enum class Status;
void anotherProcesses(Status S);
```
Now header containing this declarations don't need any recompiling and thus
we are spared of recompiling whole system.

But doesn't having scoped enums lead to inefficiency of not knowing the 
underlying type of enums in advance. As in C++98 we know as we define them.
So, here in C++11 we always know the type of enum for unscoped ones. 
And for scoped ones we can define the type to be used.

By default, the underlying type for scoped enums is int.

```
enum clas Status; // underlying type is int
// But we can override it.
enum class Status: std::unint32_t;
```
But there is a case where unscoped enums are quite useful

Suppose we want to have tuple feilds with username, email and password

```
using userInfo = std::tuple<std::string,   // name
							std::string,   // email
							std::string> ; // password
```
Though here comments tell us about the information but it is not very useful
when actually calling and using in.
```
userInfor uInfo;
...
auto val = std::get<1>(uInfo); // get value of feild 1
```
but here we can't know what is 1?? you have so many other things to 
keep track of. but using enums here might be useful

```
enum UserInfoField {uName, uEmail, uPass};

userInfo uInfo;
...
auto val = std::get<uEmail>(uInfo);
```
Here, uEmail will be implicitly converted to std::size_t type.
Which is what std::get requires.
The corresponding code for the scoped enums is quite complicated. 

```
enum class UserInfoField {uName, uEmail, uPass};

userInfo uInfo;
...
auto val = std::get<std::static_cast<std::size_t>(UserInfoField::uEmail)>(uInfo);
```
We can reduce the verbosity of the above code by defining a function for
returning compile-time constant by taking arbitrary enumerator.

```
template<typename E>
constexpr typename 



