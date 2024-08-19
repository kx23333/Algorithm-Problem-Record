#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fre(s) Fi(s".in"),Fo(s".out")
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl '\n'
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using pli=pair<ll, int>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int mod=1e9+7;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    Fre("alice");
    ll l, r, ans=0;
    cin>>l>>r;
    set<ll> tr;
    tr.emplace(-llinf);
    tr.emplace(llinf);
    for(ll i=sqrt(l); i<=sqrt(r)+1; i++)
        tr.emplace(i*i);
    for(ll x=l; x<=r; x++)
    {
        auto ptr=tr.lower_bound(x);
        ll rx=*ptr, lx=*prev(ptr);
        // if(x-lx==rx-x) return cout<<"Game Over"<<endl, 0;
        ll res=sqrt(x-lx<rx-x ? lx : rx);
        ans=(ans+(res&1 ? x : -x)+mod)%mod;
    }
    cout<<ans<<endl;
	return 0;
}
