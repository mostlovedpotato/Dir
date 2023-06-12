We gnerally use std::endl without even thinking. 
It's become standard goto newline character. 
But you must realize and many people know that 
std::endl got something more than just a newline character.
ie. 
```
std::cout << "Hello" << std::endl;
// is same as 
std::cout << "Hello" << '\n' << std::flush;
```
Here it flush the output stream buffer. 
So, there is overhead of 
1. Time.
2. Memory usage.

consider the following code - 

```
#include<iostream>
#include<fstream>

void writeln(std::ostream &os, const std::string& str){
	os << str << '\n';
}
void writeln2(std::ostream& os, const std::string& str){
	os << str << std::endl;
}
int main(){
	std::ofstream outfile{"output.txt", std::ios_base::trunc};
	for(int i = 0; i < 1000000; i++){
		writeln(outfile, "Hello World");
	}
}
```

We can see the performance different between the above two functions.
One more thing is either include '\n' or "\n".
As we know single quote sounds better as it is a charcter to be added.
While string is different.