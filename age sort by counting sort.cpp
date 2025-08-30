#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int count[101] = {0};

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            count[x]++;
        }

        bool firstNum = true;
        for (int i = 1; i <= 100; i++) {
            while (count[i] > 0) {
                if (!firstNum) {
                    cout << " ";
                }
                cout << i;
                firstNum = false;
                count[i]--;
            }
        }
        cout << "\n";
    }

    return 0;
}

