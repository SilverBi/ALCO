#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int input = 1;
	int prev, cur;
	vector<int> num;
	vector<char> log;

	cin >> n;
	for (int i = 0, prev = 0; i < n; i++) {
		cin >> cur;
		if (cur > prev) {
			if (cur < input) {
				cout << "NO";
				return 0;
			}
			for (; input <= cur; input++) {
				num.push_back(input);
				log.push_back('+');
			}
			num.pop_back();
			log.push_back('-');
		}
		else {
			for (; num.back() != cur; ) {
				num.pop_back();
				log.push_back('-');
			}
			num.pop_back();
			log.push_back('-');
		}
		prev = cur;
	}

	for (int i = 0; i < log.size(); i++) {
		cout << log[i] << "\n";
	}
}
