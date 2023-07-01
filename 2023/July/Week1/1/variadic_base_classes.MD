If we want to have multiple implementations for a derived class function
from multiple base classes in C++, we can do the below ..

```
#include <string>
#include <unordered_set>

class Customer {
	private:
		std::string name;
	public:
		Customer (std::string const& n ) : name(n) {}
		std::string getName () const { return name; }
};

struct CustomerEq {
	bool operator() (Customer const& c1, Customer const& c2 ) const {
		return c1.getName() == c2.getName();
	}
};

template<typename... Bases>
struct Overloader : Bases... 
{
	using Bases::operator()... ;
};

int main() {
	using CustomerOp = Overloader<CustomerHash, CustomerEq>;
	std::unordered_set<Customer, CustomerHash, CustomerEq> US1;
	std::unordered_set<Customer, CustomerOp, CustomerOp> US2;
}
```