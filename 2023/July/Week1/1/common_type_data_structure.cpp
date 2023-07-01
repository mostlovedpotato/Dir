#include <iostream>
#include <type_traits>
#include <array>

template<typename... Args>
auto buildArray(Args&&... args)->std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
	using commonType = typename std::common_type<Args...>::type;
	return { std::forward<commonType>(args)... };
}

int main() {
	auto data = buildArray(1.0, 0u, 'a', 3.3f, false);
	for (auto i : data) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}