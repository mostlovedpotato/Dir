#include<iostream>
#include<vector>

using namespace std;

int bellman_ford(vector<vector<int>> graph, int v, int e, in src) {
	vector<int> dist(v,INT_MAX);
	dist[src] = 0;

	for (int i = 0; i < v - 1; i++) {
		for (int j = 0; j < e; j++) {
			if (dist[graph[j][0]] != INT_MAX && dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]]) {
				dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
			}
		}
	}

	for (int i = 0; i < e; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];

		if (dist[x] != INT_MAX && dist[x] + weight < dist[y]) {
			cout << " negative cycle" << endl;
		}
	}
	cout << "distances  : ";
 	for (auto x : dist) {
		cout << x << " ";
	}
	cout << endl;

}