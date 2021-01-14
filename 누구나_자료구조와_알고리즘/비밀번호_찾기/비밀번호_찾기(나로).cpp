#include <iostream>
#include <map>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	string domain, password;
	map<string, string> store;

	for (int i = 0; i < N; i++) {
		cin >> domain >> password;
		store[domain] = password;
	}
	for (int i = 0; i < M; i++) {
		cin >> domain;
		password = store[domain];
		cout << password << "\n";
	}
}
