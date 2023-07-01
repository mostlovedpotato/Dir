We can use the variadic list of indices to access the elements corresponding to
passed first type.

```
template<typename T, typename... Idx>
void printElem (T const& Container, Idx... index) {
	print(Container[index]...);
}
```

We can also declare nontype template parameters to be parameter packs.

```
template<std::size_t... Idx, typename T>
void printElem (T const& Container) {
	print(Container[index]...);
}
```
