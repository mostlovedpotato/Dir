Choosing between different templates based on weather template argument
is prime number or not.

```
template<typename SZ, bool = isPrime(SZ) >
struct Helper;

template<typename SZ > 
struct Helper <SZ, false > 
{

};

template<typename SZ > 
struct Helper <SZ, true > 
{

};
```

Instead we can also have one of them as default and other partial specialization.

```
template<typename SZ, bool = isPrime(SZ) >
struct Helper 
{

};
template<typename SZ > 
struct Helper <SZ, true > 
{

};
```

