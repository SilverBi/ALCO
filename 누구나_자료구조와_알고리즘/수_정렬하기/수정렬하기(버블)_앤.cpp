#include <iostream>

using namespace std;

int main() {
	int array[1000] = {0,};
	int num = 0;
	int temp = 0;

	cin >> num;

	for(int i = 0; i < num; i++) {
		cin >> array[i];
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (array[i] <= array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++) {
		cout << array[i] << endl;
	}
	
	return 0;
}