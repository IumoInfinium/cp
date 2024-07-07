#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define pdi pair<double,int>
#define mp make_pair
#define ordered_set tree<pdi,null_type,less<pdi>,rb_tree_tag,tree_order_statistics_node_update>

const double eps=1e-3;

int n,l,r;
ll k;
double d[100005],d1[100005];

bool isOk(double A){
    for(int i=1;i<=n;i++){
        d1[i]=d[i]-A;
        d1[i]+=d1[i-1];
    }
    ll total=0;
    ordered_set S;
    for(int i=0;i+l<=n;i++){
        S.insert(mp(d1[i],i));
        total+=S.size()-S.order_of_key(mp(d1[i+l],n));
        if(i+l-r>=0) S.erase(mp(d1[i+l-r],i+l-r));
    }
    return total>=k;
}
void solve(){
    cin >> n >> l >> r >> k;
    for(int i=1;i<=n;i++)
        cin >> d[i];
    double low=0,high=double(1e6);
    while(high-low>eps){
        double mid=(low+high)/2;
        if(isOk(mid))
            high=mid;
        else low=mid; 
    }
    cout << fixed << setprecision(3) << high;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	T=1;
	while(T--)
		solve();
}