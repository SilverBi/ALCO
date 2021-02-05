#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

map<int, vector<int>> computer;
vector<bool> visited;
queue<int> q;

int ans = 0;

void getInfected(int cur) {
	if (!q.empty()) q.pop();
	for (int next : computer[cur]) {
		if (visited[next]);
		else {
			q.push(next);
			visited[next] = true;
			ans++;
		}
	}
	if (q.empty()) return;
	getInfected(q.front());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int V; cin >> V;  // 노드 수 = 컴퓨터 수
	int E; cin >> E;  // 간선 수
	visited.assign(V+1, false);

	for (int i = 0; i < E; i++) {
		int cur, next; cin >> cur >> next;
		computer[cur].push_back(next); 
		computer[next].push_back(cur); // 무방향 그래프이므로
	}
	visited[1] = true;
	getInfected(1);
	cout << ans;
}
