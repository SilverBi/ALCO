#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int max = 0;
	int result[15];
	vector<pair<int, int>> consulting;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time, pay;
		cin >> time;
		cin >> pay;
		consulting.push_back(make_pair(time, pay));
		result[i] = i + time <= n ? pay : 0;
	}
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++){
			if (j + consulting[j].first <= i) {
				if (max < result[j]) max = result[j];
			}
		}
		result[i] += max;
	}
	max = 0;
	for (int i = 0; i < n; i++) {
		if (max < result[i]) max = result[i];
	}
	cout << max;
}	
