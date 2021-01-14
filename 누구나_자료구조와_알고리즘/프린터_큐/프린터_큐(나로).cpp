#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> printer;
    int N; cin >> N; //테스트 케이스 수
    int M, pos; //문서의 수와 찾으려는 문서의 위치
    int count = 0;  //출력된 문서의 수


    for (int i = 0; i < N; i++) {
        int priority;
        count = 0;
        cin >> M >> pos;
        if (M == 1) {
            cin >> priority;
            cout << "1\n";
            continue;
        }
        for (int j = 0; j < M; j++) {
            cin >> priority;
            printer.push_back(priority);
        }
        for ( ; ; ) {
            bool isBiggest = true;
            for (int j = 1; j < printer.size() && printer.size() > 1 ; j++) {
                if (printer.front() < printer[j]) {
                    isBiggest = false;
                    if (pos == 0) pos = printer.size();
                    printer.push_back(printer.front());
                    printer.pop_front();
                    break;
                }
            }
            if (isBiggest) {
                printer.pop_front();  //문서 출력
                count++;
                if (pos == 0) break;
            }
            pos--;
        }
        cout << count << "\n";
        printer.clear();
    }
}
