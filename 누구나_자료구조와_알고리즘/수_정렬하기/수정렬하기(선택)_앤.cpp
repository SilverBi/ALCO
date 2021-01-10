#include <iostream>

using namespace std;

int main() {
	int array[1000] = { 0, };
	int num = 0;
	int temp = 0;
	int indexMin = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> array[i];
	}

	for (int i = 0; i < num - 1; i++) {
		indexMin = i;
		for (int j = i + 1; j < num; j++) {
			if (array[j] < array[indexMin]) {
				indexMin = j;
			}
		}
		temp = array[indexMin];
		array[indexMin] = array[i];
		array[i] = temp;
	}

	for (int i = 0; i < num; i++) {
		cout << array[i] << endl;
	}

	return 0;
}
