#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> height;
vector<vector<bool>> visited;
int N, rain, area;  // 지역 크기, 비의 양, 안전 구역의 넓이

void initVisited() {
	vector<bool> tmp(N, false);
	visited.assign(N, tmp);
}

void get_safe_zone(int x, int y) {
	if (x < 0 || x >= N) return;
	if (y < 0 || y >= N) return;
	if (visited[x][y]) return;
	if (height[x][y] <= rain) return;
	
	visited[x][y] = true; area++;
	get_safe_zone(x + 1, y);
	get_safe_zone(x - 1, y);
	get_safe_zone(x, y + 1);
	get_safe_zone(x, y - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	height.assign(N, {});

	int max_h = 0, min_h = 100;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int h; cin >> h;
			height[i].push_back(h);
			max_h = max(max_h, h);
			min_h = min(min_h, h);
		}
	}

	int ans = 1;
	for (rain = min_h; rain < max_h; rain++) {
		int count = 0;
		initVisited();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				area = 0;
				get_safe_zone(i, j);
				if (area > 0) count++;
			}
		}
		ans = max(ans, count);
	}
	cout << ans;
}
