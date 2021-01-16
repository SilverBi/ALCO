#include <iostream>
#include <deque>
using namespace std;


deque<pair<int, int>> coord;

void swap(int left, int right) {
	pair<int, int> tmp;
	tmp = coord[right];
	coord[right] = coord[left];
	coord[left] = tmp;
}

void quick(int start, int end) {
	if (end - start <= 0) return;
	pair<int, int> tmp;
	int pivot_idx = end;
	int left_idx = start;
	int right_idx = end - 1;

	for ( ; ; ) {
		bool shouldEnd = false;
		for (; left_idx <= right_idx; left_idx++) {
			if (coord[left_idx].first > coord[pivot_idx].first) break;
			if (coord[left_idx].first == coord[pivot_idx].first) {
				if (coord[left_idx].second > coord[pivot_idx].second) break;
			}
		}
		for (; ; right_idx--) {
			if (right_idx <= left_idx) {
				shouldEnd = true;
				break;
			}
			if (coord[right_idx].first < coord[pivot_idx].first) break;
			if (coord[right_idx].first == coord[pivot_idx].first) {
				if (coord[right_idx].second < coord[pivot_idx].second) break;
			}
		}
		if (shouldEnd) break;
		swap(left_idx, right_idx);
	}

	swap(left_idx, pivot_idx);
	quick(start, left_idx - 1);
	quick(left_idx + 1, end);
}

int main() {
	int N; // 좌표의 개수
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}
	quick(0, coord.size() - 1);
	for (int i = 0; i < coord.size(); i++) {
		cout << coord[i].first << " " << coord[i].second << "\n";
	}
}
