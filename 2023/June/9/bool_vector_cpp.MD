
```
std::vector<T>
```
generally dereference to T&, which you can bind to your own auto&

```
std::vector<bool>
```
however this one doesn't unpack as T&, and it return prvalue.
So, three ways to dereference an vector<bool> is 

```

// Read only 
for(auto i: boolVector){
	cout << i ; 
}

// Read-only, possibly inefficient
for(auto const& i:boolVector){
	cout << i;
}

// Read - Write
for(auto&& i: boolVector){
	cout << i;
}

```

```
std::vector<bool>::reference 
```
is an example of a proxy class.
The class that exists for the purpose of emulating and augmenting 
the behaviour of some other type. 

Some proxy classes are designed to be apparent to clients. 
Like in case of std::shared_ptr, std::unique_ptr.
But other classes are designed to act less invisibly.
std::vector<bool>::reference is example of such invisible class.

As a general rule invisible proxy classes doesn't play well with auto.
Objects of such classes are not designed to live more than a single
statement.

#### Explicitly typed initializer idiom's
we can cast the type using auto in the left when we are not sure
if auto will take upon the correct type, mostly in case of usage 
of invisible proxy types.

```
auto highPriority = static_cast<bool>(features(w)[5]);

auto sum = static_cast<Matrix>(m1+m2+m3+m4);
```
Also this shows that we are deliberately chaging the types
or declaring the types when needed for ex.
```
int index = c * d.size();

auto index = static_cast<int>(d*c.size());
```
The second statement is more intuitive. 
