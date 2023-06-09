The uncopyable objects std::atmoics may be initialized through
braces and parantheses but not with '=' 

```
std::atmoic<int> ai1(10);
std::atomic<int> ai2{10};
std::atomic<int> ai3 = 10; // error
```

braced initlialization is called complete and can be used everywhere
it prohibits implicit narrowing conversions among built-in types.
If the value of expression in braces isn't guaranteed to be expressible
by the type of object being initilized, the code won't compile.

```
double x, y, z;
int sum1{x + y + z}; // error! sum of doubles might not be int
```
Initialization with () and = won't check for narrowing conversions,
because that could break too much of legacy code.
```
int sum2(x + y + z);// fine
int sum3 = x + y + z;// fine
```

**Braced initialization is immune to C++'s most vexing parse.**

A rule that anything that can be parsed as a declaration must be
interpreted as one.

The problem is as below - 

```
Widget w1(10);
```
call widget constructor with argument 10 

```
Widget w2();
```
But this declares a function instead of object.
But it is not the same when we use parantheses.

```
Widget w3{};
```

