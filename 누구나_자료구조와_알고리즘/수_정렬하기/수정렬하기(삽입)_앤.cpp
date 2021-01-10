#include <iostream>

using namespace std;

int main() {
	int array[1000] = {0,};
	int num = 0;
	int temp = 0;
	int j = 0;

	cin >> num;

	for(int i = 0; i < num; i++) {
		cin >> array[i];
	}

	for (int i = 1; i < num; i++) {
		temp = array[i];
		for (j = i-1; j >=0; j--) {
			if (array[j] > temp) {
				array[j + 1] = array[j];
			} else {
				break;
			}
		}
		array[j + 1] = temp;
	}

	for (int i = 0; i < num; i++) {
		cout << array[i] << endl;
	}
	
	return 0;
}