#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	int N, K; cin >> N >> K;
	list<int> nums;
	list<int>::iterator n_iter;
	list<int>::iterator tmp;

	for (int i = 0; i < N; i++) {
		nums.push_back(i + 1);
	}
	cout << "<";
	for (n_iter=nums.begin();!nums.empty(); ) {
		if (n_iter == nums.end()) n_iter = nums.begin();
		for (int i = 0; i < K-1; i++) {
			n_iter++;
			if (n_iter == nums.end()) n_iter = nums.begin();
		}
		cout << *n_iter;
		if (nums.size() != 1) cout << ", ";
		tmp = n_iter;
		tmp++;
		nums.erase(n_iter);
		n_iter = tmp;
	}
	cout << ">";
}
