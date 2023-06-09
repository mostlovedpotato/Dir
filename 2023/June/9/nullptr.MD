$nullpointer$ doesn't have integral type. It doesn't have pointer
type either. But we can think of it as a pointer of all types.
nullptr's actual type is $std::nullptr_t$ 
```
void f(int );
void f(bool);
void f(void*);

//f(0) usually calls f(int) 
//f(NULL) usually calls f(int) i.e. if not faced with some error
```

Calling the function f with nullptr calls the void* overload (i.e. the 
pointer overload), because nullptr can't be viewed as anything integral.

nullptr gives us the confirmity that something is pointer if not then 
we can be sure it is not the pointer.
for example in checks below - 

```
// case 1 
auto res = findSomething(...);
if(res == 0){
	...
}

// case 2
auto res2 = findSomething(...);
if(res2 == nullptr){
	...
}

```
In second case there is no ambiguity as in first case it might be pointer
or int. But when used nullptr we can be sure as result must be of pointer type.

```
int f1(std::shared_ptr<Widget> spw);
double f2(std::unique_ptr<Widget> upw);
bool f3(Widget * pw);

std::mutex f1m,f2m,f3m;

using MaxGuard = std::lock_guard<std::mutex>;
...
{
	MaxGuard g(f1m);
	auto result = f1(0);
}
{
	MaxGuard g(f2m);
	auto result = f2(NULL);
}
...
{
	MaxGuard g(f3m);
	auto result = f3(nullptr);
}

```

The code is repeating itself so we can use templates to overcome this

```
template<typename FuncType,
		typename MuxType,
		typename PtrType>
auto lockAndCall(FuncType func, MuxType& mutex, PtrType ptr)->decltype(func(ptr)){
	MuxGuard g(mutex);
	return func(ptr);
}

// or we can also use
template<typename FuncType,
		typename MuxType,
		typename PtrType>
decltype(auto) lockAndCall(...){...}
```
But here we get error in case of 0 and NUll as argument to our lockAndCall function
Here the problem will be as type deduction kicks in as we call
```
auto result1 = lockAndCall(f1,f1m,0);
```
Here it will deduce the type of third argument 0 as int. and then try to pass
it as int to the f1. But f1 is expecting the std::shared_ptr. So this call will
be invalid.