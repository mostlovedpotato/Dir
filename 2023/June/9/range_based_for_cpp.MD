For simply observing the elements in the structure.
```
// capture by constant reference
for(const auto& i : container){
	...
}
```

If values are easy to copy like int, double etc.
use 
```
for(auto i : container){
	...
}
```

For modifying the elements in place 
```
// capture by non-constant reference
for(auto& i : container){
	...
}
```

And in this only if container use proxy iterators like vector<bool>
then use 
```
for(auto&& i : container){
	...
}
```

In observing mode it's always safe to use 
```
for(const auto& i : container){
	...
}
```
In modifying mode if we want it work also in case of proxy-iterations,
best option is 
```
for(auto&& i : container){
	...
}
```
This will also work fine for container not using proxy-iteration too.

