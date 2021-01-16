#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N;
	int M;
	string key;
	string value;
	string temp;
	unordered_map<string, string> sign;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> key >> value;
		sign.insert(make_pair(key, value));
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		cout << sign[temp] << "\n";
	}
}