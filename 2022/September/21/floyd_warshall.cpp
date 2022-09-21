#include<iostream>
#include<vector>
#define V 5

using namespace std;


vector<vector<int>> ffloyd(vector<vector<int>> graph) {
	vector<vector<int>> dist(V, vector<int>(V));
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			dist[i][j] = graph[i][j];
		}
	}
	// update for every possible intermediate vertex
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	return dist;
}