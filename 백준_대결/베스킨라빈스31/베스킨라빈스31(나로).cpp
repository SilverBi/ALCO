#include <iostream>
using namespace std;

int main() {
	int A; cin >> A;
	for (int n = 1; n <= A; n++) {
		if (30 % (n + 1) == 0) cout << n << endl;
	}
}
