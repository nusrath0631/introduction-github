#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, num = 1;
    cin >> n;

    while (n != 0)
    {
        vector<int> stack(n);
        int totalBricks = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> stack[i];
            totalBricks += stack[i];
        }

        int average = totalBricks / n;
        int m = 0;

        for (int i = 0; i < n; i++)
        {
            if (stack[i] > average)
            {
                m += stack[i] - average;
            }
        }

        cout << "Set #" << num << endl;
        cout << "The minimum number of moves is " << m << "." << endl;
        cout << endl;

        num++;
        cin >> n;
    }

    return 0;
}
/*#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int num = 1; num <= T; num++) {
        string a;
        int b;
        cin >> a >> b;

        long long rem = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '-') continue;
            rem = (rem * 10 + (a[i] - '0')) % abs(b);
        }

        cout << "Case " << num << ": ";
        if (rem == 0)
            cout << "divisible" << endl;
        else
            cout << "not divisible" << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        int you, lift;
        cin >> you >> lift;

        int moveToYou = abs(you - lift) * 4;
        int openDoor = 3;
        int closeDoor = 3;
        int enter = 5;
        int exit = 5;
        int moveToGround = you * 4;

        int totalTime = moveToYou + openDoor + enter + closeDoor + moveToGround + openDoor + exit;

        cout << "Case " << num << ": " << totalTime << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int num = 1; num <= T; ++num) {
        long long r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        if ((r1 + c1) % 2 != (r2 + c2) % 2) {
            cout << "Case " << num << ": impossible" << endl;
        }
        else if (abs(r1 - r2) == abs(c1 - c2)) {
            cout << "Case " << num << ": 1" << endl;
        }

        else {
            cout << "Case " << num << ": 2" << endl;
        }
    }

    return 0;
}
*/


