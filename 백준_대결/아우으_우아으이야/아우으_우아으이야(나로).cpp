#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	int x, y; cin >> x >> y;

	int sum = 0;
	int start = x;
	int end = y;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		if (end >= x) end = (end > y) ? end : y;
		else {
			sum += end - start;
			start = x; end = y;
		}
	}
	sum += end - start;
	cout << sum;
}
