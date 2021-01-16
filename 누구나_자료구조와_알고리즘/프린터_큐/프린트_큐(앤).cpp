#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int testCase = 0;
	int count = 0;
	int N, M, important;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		count = 0;
		cin >> N >> M;

		queue<pair<int, int>> queue;
		priority_queue<int> priorityQueue;

		for (int j = 0; j < N; j++) {
			cin >> important;
			queue.push({ j, important });
			priorityQueue.push(important);
		}

		while (!queue.empty()) {
			int k = queue.front().first;
			int v = queue.front().second;

			queue.pop();

			if (priorityQueue.top() == v) {
				priorityQueue.pop();
				count++;
				if (k == M) {
					cout << count << endl;
					break;
				}
			}
			else {
				// 아니면 다시 queue 뒤로 넣기
				queue.push({ k, v });
			}
		}
	}
}