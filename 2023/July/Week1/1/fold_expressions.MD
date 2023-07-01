Feature to compute the result of using the binary operator over all the
arguments of the parameter pack.
```
template<typename... T>
auto foldSum (T... s) {
	return (...+s);
}
```
Fold expression rules : 
```
(... op pack)  -> (((pack1 op pack2 ) op pack3)... op packN);
(pack op ...)  -> (pack1 op (pack2 op (... (pack_(N-1) op pack_N));

(pack op ... op init) -> (pack1 op (pack2 op (... (pack_N op init));
(init op ... op pack) -> (((init op pack1 ) op pack2)... op packN);

```

Let's see the difference of the packing with example of non-associative op.
```
#include <iostream>
#include <type_traits>
#include <array>

template<typename... Args>
auto buildArray(Args&&... args)->std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>(args)... };
}
template<typename... Values>
auto f(Values const&... values)
{
    return (values - ...);
}
template<typename... Values>
auto f2(Values const&... values){
    return (... - values);
}

int main() {
	auto data = buildArray(1.0, 0u, 'a', 3.3f, false);
	for (auto i : data) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
	std::cout << f(1,2,2) << '\n';
	std::cout << f2(1,2,2) << '\n';
}
```
folding over comma operator.

```
template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);
}
```