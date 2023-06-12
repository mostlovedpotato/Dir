const at the end of member function declaration tell us that
object on which member function is invoked is const.

And similary for using & and && we need lvalue and rvalue objects.

```
class Widget{
	public:
		using DataType = std::vector<double>;
		...
		DataType& data() & {
			return values;
		}
		DataType& data() &&{
			return std::move(values);
		}
		...
	private:
		DataType values;
};
```
Here calling 
auto value1 = w.data(); // provies lvalue 
auto value2 = w.makeWidget().data(); // rvalue object would be destroyed soon
// so instead of using normal copy method to get new object we can use move
