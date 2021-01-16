#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int temp = 0;
	int j = 0;
	stack <int> s;
	vector <char> v;
	vector <int> arr;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		s.push(i);
		v.push_back('+');

		while (!s.empty() && s.top() == arr[j]) {
			s.pop();
			v.push_back('-');
			j++;
		}
	}

	if (!s.empty()) {
		cout << "NO" << '\n';
	}

	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n';
		}
	}

	return 0;
}