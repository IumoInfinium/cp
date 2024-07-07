#include <bits/stdc++.h>
using namespace std;
#define int long long 
void solve(int* arr, int n, int p) {
    int ans = -1, freq = 0;
    set<int> s;
    for(int i = 0, sum = 0; i < n; i++) {
        sum += arr[i];
        sum %= p;
        auto it = s.upper_bound(sum);
        if(it == s.end()) ans = max(ans, sum);
        else ans = max(ans, p - (*it - sum));
        s.insert(sum);
    }
    map<int, int> mp{{0,1}};
    for(int i = 0, sum = 0; i < n; i++) {
        sum += arr[i];
        sum %= p;
        if(sum - ans >= 0) freq += mp[sum - ans];
		freq += mp[sum + p - ans];
        mp[sum]++;
    }
    cout<<ans<<' '<<freq<<'\n';
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, p;
        cin >> n >> p;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] %= p;
        }
        solve(arr, n, p);
    }
}
