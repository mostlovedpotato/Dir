
```
template<typename It> 
void dwim(It b, It e){
	while(b!=e){
		typename std::iterator_traits<It>::value_type currValue = *b;
		// here we are declaring the type of It we are also not sure of
		// here instead using auto will be more useful and conscise 
	}
}

auto derefUPLess = [](const std::unique_ptr<Widget>& p1,const std::unique_ptr<widget>& p2){
	return *p1<*p2;
};
```
we are giving type for derefUPLess here. 
we can further make it smaller
```
auto derefLess = [](const auto& p1,const auto& p2){return *p1 < *p2;};
```
with using function pointer we would write it as 
first signature for the functino would be
```
bool(const std::unique_ptr<widget>&,const std::unique_ptr<Widget>&)
```
now using function pointer as 
```
std::function<bool(const std::unique_ptr<widget>&,const std::unique_ptr<widget>&)> func;
```
in overall we would deeclare the same function 'derefUPLess' as below

```
std::function<bool(const std::unique_ptr<widget>&,const std::unique_ptr<widget>&)>
derefUPLess = [](const std::unique_ptr<widget>& p1,const std::unique_ptr<widget>& p2){
	return *p1 < *p2;
}
```

Also another problem with defining custom types instead of using
auto declarations is - as example below

```
std::vector<int> v;
unsigned sz = v.size();
```
Here the official return type of v.size() is std::vector<int>::size_type but it's type is unsigned integral type.
so a lot of programmers write above code but we have to know that
on 32-bit windows, both unsigned and std::vector<int>::size_type have same size,
but on 64-bit windows, unsigned is still 32 bit but 
std::vector<int>::size_type is 64 bit. 
So, we have to be careful when porting our application.

```
std::unordered_map<std::string, int> m;
…
for (const std::pair<std::string, int>& p : m)
{
… // do something with p
}```

Now we see the above code,at first glace nothing seems wrong with this.
But the problem is we know the key part of the std::unordered_map<key,value> is 
constant so that it couldn't be modified so, it's original type is
std::pair<const std::string, int> and not the std::pair<std::string, int>
As a result of this prolem compilers will try to find a way to convert 
std::pair<const std::string, int> to std::pair<std::string,int> 

Here it will succeed by creating a temporary object and copying each object into it
binding reference to that temporary object. At the end of each loop iteration, 
the temporary object will be destroyed.

So, here using 
```
for(const auto& p: m ){
	...
}
```
This is more efficient and easier to type. Also one more interesting thing here is
If you take p's address you'd certainly get a pointer to an element within m. 
But in the code not using the auto, we'd get the pointer to the temporary object
and that object would be destroyed at the end of loop iteration.

There are serveral reason above being two of them for using auto instead of explicit
type declaration. But auto itself is not perfect.

One of the problems with auto being - 
when $C++11$ introduced curly braces initialization. 
as 
```
int x1 = 12;
int x2(12); 
// The above two were already present in C++98
int x3 = {12};
int x3{12};
```
Four syntaxes but same result int with value 12
But if we use auto with the same statements first two will give the int,
but other two won't give the type int. Rather it will be std::initializer_list<int>
containing single element with value 12.

std::initlializer_list<T> if it can't deduce a single type in the list it will 
reject the initialization. 
for example - 

```
auto x4 = {1,23,1.0}; // error as it can't deduce type T
```

Another problem with the auto declaration - 
suppose, 
```
std::vector<bool> features(const widget& w);
// bit 5 indicates wheather widget has high priority
widget w;
bool highPriority = features(w)[5];
processWidget(w,highPriority);
```
here if we use 
```
auto highPriority = features(w)[5];
```
then, the behaviour is no longer predictable.
In the above code the type of highPriority is no longer bool.
Though features(w) return type conceptually holds bools, 
The operator [] for std::vector<bool> doesn't return a reference
to an element of the container.(always works for all the other data types)
bool here is an exception. 
Instead it returns an object of type std::vector<bool>::reference
(this is a class nested inside the vector<bool>) 

This weird class exists because std::vector<bool> is specified to 
represent it's bools in a packed form, as one bit per bool.
std::vector<bool> is not a array of bools instead it holds bits.
so, we do not get bool& from it's dereferencing operator.




