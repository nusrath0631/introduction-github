#include <iostream>
#include <string>
using namespace std;
int main()
{
    string b; // b - binary
    cin>>b;
    string res = "";
    bool removed = false ;
    for(int i=0; i< b.length(); i++){
        if(!removed && b[i] == '0')
        {
            removed = true ;

            continue;
        }
        res += b[i];
    }
    if(!removed)
    {
        res = b.substr(1);
    }
    cout<<res<<endl;

    return 0;

}
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> count(5, 0);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        count[s]++;
    }

    int taxis = 0;

    taxis += count[4];

    int pair_3_1 = min(count[3], count[1]);
    taxis += pair_3_1;
    count[3] -= pair_3_1;
    count[1] -= pair_3_1;

    taxis += count[3];

    taxis += count[2] / 2;
    count[2] %= 2;

    if (count[2] == 1) {
        taxis += 1;
        count[1] -= min(2, count[1]);
    }

    if (count[1] > 0) {
        taxis += (count[1] + 3) / 4;
    }

    cout << taxis << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    int neg[100], pos[100], zero[100];
    int negCount = 0, posCount = 0, zeroCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            neg[negCount++] = arr[i];
        } else if (arr[i] > 0) {
            pos[posCount++] = arr[i];
        } else {
            zero[zeroCount++] = arr[i];
        }
    }
    int set1[100], set2[100], set3[100];
    int c1 = 0, c2 = 0, c3 = 0;

    set1[c1++] = neg[--negCount];

    if (posCount > 0) {
        for (int i = 0; i < posCount; i++)
            set2[c2++] = pos[i];
    } else {
        set2[c2++] = neg[--negCount];
        set2[c2++] = neg[--negCount];
    }

    for (int i = 0; i < negCount; i++)
        set3[c3++] = neg[i];
    for (int i = 0; i < zeroCount; i++)
        set3[c3++] = zero[i];

    cout << c1;
    for (int i = 0; i < c1; i++) cout << " " << set1[i];
    cout << endl;

    cout << c2;
    for (int i = 0; i < c2; i++) cout << " " << set2[i];
    cout << endl;

    cout << c3;
    for (int i = 0; i < c3; i++) cout << " " << set3[i];
    cout << endl;

    return 0;
}
*/
