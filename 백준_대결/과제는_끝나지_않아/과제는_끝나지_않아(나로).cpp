#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N; cin >> N;
	int flag, A, T;
	int score = 0;
	deque<pair<int, int>> assignment;

	for (int i = 0; i < N; i++) {
		cin >> flag;
		if (flag == 1) {
			cin >> A >> T;
			assignment.push_back(make_pair(A, T - 1));
		}
		else if (flag == 0) {
			if (!assignment.empty()) {
				assignment.back().second--;
			}
		}
		if (!assignment.empty() && assignment.back().second == 0) {
			score += assignment.back().first;
			assignment.pop_back();
		}
	}
	cout << score;
}
