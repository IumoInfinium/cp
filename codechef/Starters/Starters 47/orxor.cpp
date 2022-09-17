#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll count_set_bit(ll n){
    // _builtin_popcountll(long long n) -> returns the number of set bits in given number
    return __builtin_popcountll(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout.precision(10);
    cout << fixed;
    ll t, n, x;
    cin >> t;
    while (t--){
        cin >> n >> x;
        vector<vector<ll>> ans;
        vector<ll> vec, pec;
        for (int i = 1; i <= n; i++){
            if (((x & i) == 0) && count_set_bit(i) == 1) vec.push_back(i);
            else pec.push_back(i);

        }
        ll d = 0;
        if (pec.size() != 0){
            d = pec[0];
            for (int i = 1; i < pec.size(); i++){
                ans.push_back({1, d, pec[i]});
                d |= pec[i];
            }
        }

        for (int i = 0; i < vec.size(); i++){
            ans.push_back({2, d, vec[i]});
            d ^= vec[i];
        }
        if (d == x){
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }

    return 0;
}