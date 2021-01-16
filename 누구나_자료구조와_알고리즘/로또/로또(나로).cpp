#include <iostream>
#include <deque>
using namespace std;


int k;
deque<int> set;
deque<int> selected;

void selectNum(int n) { // n번째 숫자 선택
	if (n == 7) {
		for (int i = 0; i < 6; i++) {
			cout << selected[i] <<" ";
		}
		cout << "\n";
		return;
	}
	int prev = selected.empty() ? 0 : selected.back();
	for (int i = 0; i < k; i++) {
		if (set[i] > prev) {
			selected.push_back(set[i]);
			selectNum(n + 1);
			selected.pop_back();
		}
	}
}

int main(){
	for (; ;) {
		/* 초기화 */
		set.clear();
		selected.clear();
		cin >> k;
		if (k == 0) break; // 0 입력 시 종료
		/* set 입력 */
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			set.push_back(num);
		}
		selectNum(1);
		cout << "\n";
	}
}
