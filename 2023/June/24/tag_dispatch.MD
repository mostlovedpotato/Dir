To avoid overloading on the universal references where we want to give exceptions. 
It's not that hard to produce, though it will need some concept development.

Generally calls to overloaded functions are resolved using the function arguments 
being called and also the parameter types defined. We might introduce a new parameter
and argument to be called for not letting it overload the functions.

Let's understand with an example ->

```
std::multiset<std::string> carnames;

template<typename T>
void logInfo(T&& carname){
	log(carname,"$NASCAR");
	carnames.emplace(std::forward<T>(carname));
}
```
Suppose we want to provide different implementation for int types. If we provide it using

```
void logInfo(int carid){
	log(carid.getByID().to_string(),"$NASCAR");
	carnames.emplace(std::forward<T>(carid.getById().to_string()));
}
```
This overload will definitely work for the proper int type.
But what about if we pass in (short) or int&  or something else, It will then go to 
templatated function with universal reference. But this is not what we want.

We would want this function to take all the possible int related types or convertibles.

So, we could do slight modification.
```
template<typename T>
void logInfo(T&& carname){
	logInfoDef(std::forward<T>(carname),std::is_integer<T>());
}
```
This function forwards the parameters to logInfoDef.. and also passing another 
arguemnt denoting weather it is of integer type or not.
But also another thing is std::is_integer doesn't distinguish between int and int&
so, we might need to remove any references from it.

and we have std::remove_reference, that does what it is named.

```
template<typename T>
void logInfor(T&& carname){
	logInforDef(std::forward<T>(carname),std::is_integer<typename std::remove_reference<T>::type>());
}
```
There are now two overloads one for integral and other for non-integral type.
```
template<typename T>
void logInfoDef(T&& carname, std::false_type){
	log(carname,"$NASCAR");
	carname.emplace(std::forward<T>(carname));
}
```
And the second overload, for int type where we have std::true_type, like instead of passing
boolean here compiler will directly understand the types. Look into cppreference.

From int id, we can either pass the carname to logInfoDef with string in an argument
and second argument being std::false_type, or else we can call upon the original function
which is logInfo.

```
void logInfoDef(int carid, std::true_type){
	
	logInfo(carid.getById().to_string());
}
```

