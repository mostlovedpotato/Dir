#include<iostream>
#include<algorithm>


using namespace std;


// we can either move to x+y,y 
// or to x,y+x
// in one steps 

// we want to know min steps to reach m,n from 1,1
int gloabl_min = 1e6;
void solve(int x, int y, int count) {
	if (x < 1 or y < 1) {
		global_min = -1;
		return;
	}
	if (x == 1 && y == 1) {
		if (count < global_min) {
			global_min = count;
		}
		return;
	}
	if (x == y or x < 1 or y < 1) {
		return;
	}
	if (x > y) {
		return solve(x - y, y, ++count);
	}
	else {
		return solve(x, y - x, ++count);
	}
}