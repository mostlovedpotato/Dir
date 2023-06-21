make_shared is part of C++11 but make_unique came in C++14.
basic implementation of make_unique is quite simple.

```
template<typename T, typename... Ts>
std::unique_ptr<T> make_unique(Ts&&... params){
	return std::unique_ptr<T>(new T(std::forward<Ts>(params)...));
}
```
make_unique just perfect forwards it's parameters to the constructor of the
object being created. This form doesn't support arrays or custom deleters.

There are three make functions - make_shared, make_unique and std::allocate_shared
It just acts like make_shared except its first argument is allocator object 
to be used for dynamic memory allocation.

We can't pass custom deleter when using constructor with normal new. but 
we can't pass them along in make functions.

```
auto widgetDeleter = [](Widget * pw){ ... };

std::unique_ptr<Widget, decltype(widgetDeleter)> upw(new Widget, widgetDeleeter);
std::shared_ptr<Widget> spw(new Widget, widgetDeleter);
```
There is no such thing possible using the make function.

suppose we have functions

```
void processWidget(std::shared_ptr<Widget> spw, int priority);
void custDel(Widget *w);

// below is the exception-unsafe call
processWidget(std::shared_ptr<Widget>(new Widget, custDel), computePriority());
```
But there is possibility that we get exception between calling out 
new Widget and then it starts to computePriority() and later try to make
shared_ptr here... but if computePriority() throws exception. There is memory 
leak for new Widget allocated.

So, better code is 
```
std::shared_ptr<Widget> spw(new Widget, custDel);
processWidget(spw, computePriority());

// but we can improve it further.
// as here spw is lvalue but but it will need copy before passing in 
// difference can be significant also ref count is incremented.
// so best would be using std::move
std::shared_ptr<Widget> spw(new Widget, custDel);
processWidget(std::move(spw), computePriority());
```

