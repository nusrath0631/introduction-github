#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);

        if (n >= k * k && n % 2 == k % 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a)
         cin >> x;

        sort(a.begin(), a.end());
        vector<long long>
             pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];

        long long ans = 0;
        for (int x = 0; x <= k; x++) {
            int rmMin = 2 * x, rmMax = k - x;
            ans = max(ans, pref[n - rmMax] - pref[rmMin]);
        }
        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
}*/
