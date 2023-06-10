For writing into some file, we can use std::ofstream

```
#include<fstream>
int main(){
	std::ofstream os {"squares.txt"};
	if(os.good()){
		for(int i = 1; i < 10; i++){
			os << i << " " << i * i << "\n";
		}
	}
}
```
This creates new file squares.txt, and if file already exist.
It will overwrite the file.

```
#include<fstream>
int main(){
	std::ifstream is {"squares.txt"};
	if(is.good()){
		int x, y;
		while(is >> x >> y){
			cout << x << y << "\n";
		}
	}
}
```
Here it will read the file squares.txt and then 
as long as 2 variables x, y are readable it will 
read and print the values.
