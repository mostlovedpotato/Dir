A unique pointer takes ownership of the pointer. 
deleter is invoked when out of scope.

unique_ptr's can't bee copied. Below are some operations that can be
preformed on unique_ptr

```
#include <memory>

typedef struct {
	int a;
	int b;
}IntPair;

int main(){
	unique_ptr<int> x(new int(5));
	int *ptr = x.get(); // pointer
	int val = *x;   // value for pointed-to object
	unique_ptr<IntPair> ip(new IntPair);
	ip->a = 100;
	x.reset(new int(1));
	ptr = x.release(); // released from responsibility of freeing mem
	deleter ptr;
}

```
unique pointers can be stored in STL. Though they dont't support copy operation
while STL extensively uses copy and assignment operations. 
But there comes move semantics to the rescue.

So, we can move one unique_ptr to another. 
And this is like having combination of release-and-reset. 

```
unique_ptr<int> x(new int(5));
unique_ptr<int> y = std::move(x);
```

unique_ptr with stl
```
#include<iostream>
#include<memory>

int main(){
	std::vector<std::unique_ptr<int> > vec;
	vec.push_back(std::unique_ptr<int> (new int(5)));
	vec.push_back(std::unique_ptr<int> (new int(6)));
	vec.push_back(std::unique_ptr<int> (new int(9)));
	int z = *vec[1];
	std::cout << "value of z : " << z << '\n';
	std::unique_ptr<int> copied = vec[1];
	std::unique_ptr<int> moved  = std::move(vec[1]);
	std::cout << "value of moved : " << *moved << '\n';
	std::cout << "value of vec[1].get() : " << vec[1].get() << '\n';
}
```
This program will give an error telling us that copy operation is deleted. 

and if we comment out the copied = vec[1] part  we will not get any errors.