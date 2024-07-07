#include "bits/stdc++.h"
using namespace std;
#define fo(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>


void psi(int T)
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count = 1;
    char temp = s[0];
    fo(i, n)
    {
        if (s[i] != temp)
        {
            temp = s[i];
            count++;
        }
    }
    if (count == 1)
        cout << "SAHID\n";
    else if (count == 2)
        cout << "RAMADHIR\n";
    else
    {
        if (count % 3 == 0)
            cout << "SAHID\n";
        else if (count % 3 == 1)
            cout << "SAHID\n";
        else
            cout << "RAMADHIR\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        psi(T);
    }
    return 0;
}