
```
typedef void (*FP)(int, const std::string&);

using FP = void (*)(int, const std::string&);
```
Second statement is more intuitive.

```
template<typename T>
using MyAllocList = std::list<T,MyAlloc<T>>;

// so when using this alias inside the template 
// we don't need to add typename before every usage

MyAllocList<Widget> lw;
```
Here we using custom Allocator MyAlloc to initialize list.
Here it is quite easy using the alias, while if we use 
typedef then,

```
template<typename T>
struct MyAllocList{
	typedef std::List<T,MyAlloc<T>> type;
};

MyAllocList<Widget>::type lw;
```

It is worst in case if we want to use the typedef inside the template
for the purpose of creating a linked list holding objects of type 
specified by template parameter.
Then you have precede the typedef name with typename.

```
template<typename T>
class Widget{
	private:
	typename MyAllocList<T>::type list;
}
```
Here, MyAllocLlist<T>::type referes to type that's dependent on a template
type parameter (T).
But if instead we define it using alias then this won't be a problem.

```
template<typename T>
using MyAllocList = std::list<T,MyAlloc<T>>;

template<typename T>
class Widget{
	private:
	MyAllocList<T> list;
	...
};
