Generally when we call methods on const objects.
The constantness is propogated all along.
But if we called them with the pointer objects
then this constantness is not propogated.

```
#include <iostream>
#include <memory>
struct X{
    void foo() {std::cout << "X::foo()\n";}
    void foo() const{std::cout << "X::foo()const\n";}
};
class Y{
    private:
        std::unique_ptr<X> xPtr_;
    public:
        Y():xPtr_{std::make_unique<X>()}
        {     /*empty ctor body */   }        void bar(){
            std::cout << "Y::bar()\n";
            xPtr_->foo();
        }       void bar() const{
           std::cout << "Y::bar() const\n";
           xPtr_->foo();
       }
};
int main(){    Y y;
    y.bar();    const Y cy;
    cy.bar();
    
    return 0;
}
/*
output
------Y::bar()
X::foo()Y::bar() const
X::foo()     <-- NOTE THIS!!
*/
```

But we can use experimental::propogate_const for the above problem.

```
#include <iostream>
#include <memory>
#include <experimental/propagate_const> //<-- NOTE THIS
struct X{
    void foo(){std::cout << "X::foo()\n";}
    void foo() const {std::cout << "X::foo() const\n";}
};
struct Y{
    std::experimental::propagate_const<std::unique_ptr<X>> xPtr_;
    Y():xPtr_{std::make_unique<X>()}
    {/*empty ctor body */ }    void bar(){
        std::cout << "Y::bar()\n";
        xPtr_->foo();
    }
   
    void bar() const{
        std::cout << "Y::bar() const\n";
        xPtr_->foo();
    }
};
int main(){
    Y y;
    y.bar();    const Y cy;
    cy.bar();    return 0;
}
/*
output
------
Y::bar()
X::foo()Y::bar() const
X::foo() const
*/
```