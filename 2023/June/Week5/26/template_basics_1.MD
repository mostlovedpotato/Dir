Using templates in cpp.

Before C++17, type T had to be copyable to pass in arguments.
But since, C++17 you can pass in rvalues and temporaries.

```
#include "maxx.hpp"
#include <iostream>
#include <string> 

int main()
{
	int i = 42;
	std::cout << "max(7,i):" << ::max(7,i) << ’\n’;
	double f1 = 3.4;
	double f2 = -6.7;
	std::cout << "max(f1,f2): " << ::max(f1,f2) << ’\n’;
	std::string s1 = "mathematics";
	std::string s2 = "math";
	std::cout << "max(s1,s2): " << ::max(s1,s2) << ’\n’;
}
```

:: used before max, to ensure it is found in global namespace.
