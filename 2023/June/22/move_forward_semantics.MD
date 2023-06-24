If you are in function that return by value.
but you are returning an object bound to rvalue or
universeal reference. you would want to use std::move
or std::forward when returning reference.

```
template<typename T>
Fraction reduceAndReturn(T&& frac){
	frac.reduce();
	return std::forward<T>(frac);
}
```
you can only do this in above conditions stated. Otherwise
if you try to do this even in normal cases. Then you will
make it inefficient by not letting RVO take place.

