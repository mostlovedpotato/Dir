#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>

using namespace std;

// given two pots a and b litres volume capacity
// you can fill(i) , drop(i) , pour(i,j)
// from one to another , you have to find
// shortest possible sequence to make C litres 
// of water in one of the containers.

struct Node {
	int a, b;

}node, now;

struct Path {
	int x, y, action;
}path[110][110];

string INFO[7] = { "","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)" };

void PrintPath(Path p) {
	stack<int> st;
	st.push(p.action);
	int sum = 1;
	while (!(p.x == 0 && p.y == 0)) {
		p = path[p.x][p.y];
		st.push(p.action);
		sum++;
	}
	cout << sum << endl;
	while (!st.empty()) {
		cout << INFO[st.top()] << endl;
		st.pop();
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	queue<Node> que;
	que.push((Node{ 0,0 });
	while (que.size()) {
		node = que.front();
		que.pop();
		if (node.a == c || node.b == c) {
			PrintPath(path[node.a][node.b]);
		}
		for (int i = 1; i <= 6; i++) {
			if (i == 1) now = (Node){ a,node.b };
			if (i == 2) now = (Node){ node.a,b };
			if (i == 3) now = (Node){ 0,node.b };
			if (i == 4) now = (Node){ node.a,0 };
			if (n == 5) now = (Node){ max(0,node.a - b + node.b),min(b,node.a + node.b) };
			if (n == 6) now = (Node){ min(a,node.a + node.b),max(0,node.a + node.b - a) };

			if (path[now.a][now.b].action == 0) {
				que.push(now);
				path[now.a][now.b] = (Path){ node.a,node.b,i };
			}
		}
	}
	cout << "impossible" << endl;
	return 0;
}




