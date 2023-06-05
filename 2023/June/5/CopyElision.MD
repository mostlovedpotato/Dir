**Copy elision is a rule that permits a C++ compiler to ignore the creation of the temporary and its subsequent copy/destruction. That is, the compiler can take the initializing expression for the temporary and initialize the function's return value from it directly. This obviously saves performance.**

**However, it does have two visible effects on the user:**

    The type must have the copy/move constructor that would have been called. Even if the compiler elides the copy/move, the type must still be able to have been copied/moved.

    Side-effects of copy/move constructors are not guaranteed in circumstances where elision can happen. Consider the following:

$C++11$

```
    struct my_type
    {
      my_type() = default;
      my_type(const my_type &) {std::cout <<"Copying\n";}
      my_type(my_type &&) {std::cout <<"Moving\n";}
    };

    my_type func()
    {
      return my_type();
    }
```

**Without the copy elision rule, this would be required to always print "Moving". But because the copy elision rule exists, the move constructor may or may not be called; it is implementation-dependent.**

$$-fno-elide-constructors$$ Flag is used when we don't want to have RVO enabled.