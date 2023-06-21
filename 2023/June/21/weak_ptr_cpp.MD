```
auto spw = std::make_shared<Widget>(); // Ref count is 1 now

std::weak_ptr<Widget> wpw(spw); // Ref count is unchanged

spw = nullptr; // Ref count is 0 and Widget is destroyed.
```

Weak pointers that dangle are said to be expired.
and we can test it directly.

```
if(wpw.expired())...
```

We can get shared pointer from the weak pointer.

```
#include <iostream>
#include <memory>

class Widget{
  int x;
  int y;
};

int main()
{
    auto spw = std::make_shared<Widget>();
    std::weak_ptr<Widget> wpw(spw);
    std::cout << spw.use_count();
    // cout<<"Hello World";
    spw = nullptr;
    std::cout << '\n' << spw.use_count(); 
    return 0;
}
```
Prints 1 in first line and 0 in second. as it shows there is no effect on 
ref count of weak_ptr.

```
#include <memory>
#include <iostream>
 
void fun(std::shared_ptr<int> & sp)
{
    std::cout << "in fun(): sp.use_count() == " << sp.use_count()
              << " (object @ " << sp << ")\n";
}
 
int main()
{
    auto sp1 = std::make_shared<int>(5);
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
 
    fun(sp1);
}

Output : 
in main(): sp1.use_count() == 1 (object @ 0x1f1ec30)
in fun(): sp.use_count() == 1 (object @ 0x1f1ec30)

```
passing the shared_ptr with reference.

```
#include <memory>
#include <iostream>
 
void fun(std::shared_ptr<int>  sp)
{
    std::cout << "in fun(): sp.use_count() == " << sp.use_count()
              << " (object @ " << sp << ")\n";
}
 
int main()
{
    auto sp1 = std::make_shared<int>(5);
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
 
    fun(sp1);
}
Output : 
in main(): sp1.use_count() == 1 (object @ 0x24edc30)
in fun(): sp.use_count() == 2 (object @ 0x24edc30)
```

There is another shared_ptr created which points to the same value.
But it is only upto when the fun() scope.

```
#include <memory>
#include <iostream>
 
void fun(std::shared_ptr<int>  sp)
{
    std::cout << "in fun(): sp.use_count() == " << sp.use_count()
              << " (object @ " << sp << ")\n";
}
 
int main()
{
    auto sp1 = std::make_shared<int>(5);
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
 
    fun(sp1);
    
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
    
}
Output : 
in main(): sp1.use_count() == 1 (object @ 0x655c30)
in fun(): sp.use_count() == 2 (object @ 0x655c30)
in main(): sp1.use_count() == 1 (object @ 0x655c30)
```
Here we see the change in count as we move out of scope of fun().

Next is usage of expired() function to check if there is some shared_ptr 
still pointing to the address or is it dead.

```
#include <memory>
#include <iostream>
 
void fun(std::shared_ptr<int>  sp)
{
    std::cout << "in fun(): sp.use_count() == " << sp.use_count()
              << " (object @ " << sp << ")\n";
}
 
int main()
{
    auto sp1 = std::make_shared<int>(5);
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
 
    fun(sp1);
    
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
    std::weak_ptr<int> wpw(sp1);
    std::cout << "sp1.use_count after weak_ptr " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
    if(!wpw.expired()){
        std::shared_ptr<int> sp2 = wpw.lock();
        std::cout << "sp1.use_count shared_ptr " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
    }
    // sp2 is not available in this scope it is auto deleted.
    sp1 = nullptr;
    if(wpw.expired()){
       std::cout << "Weak Pointer is expired\n"; 
    }
}
```

For somewhere if we want to cache the locations or shared pointers, and also 
delete them when they are in no longer usage.
but we can't know if they are dangling pointers so, it is better to store 
them as weak_pointers.