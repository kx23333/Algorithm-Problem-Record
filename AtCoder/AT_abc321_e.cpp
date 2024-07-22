//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#define sz(x) int((x).size())
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
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

ll calc(ll x, ll k, ll n)
{
    if(k<0) return 0; 
    ll l=x, r=x;
    for(int i=0; i<k; i++)
    {
        l=l<<1, r=r<<1|1;
        if(l>n) return 0;
    }
    return min(r, n)-l+1;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int T;
    cin>>T;
    while(T--)
    {
        ll n, x, k;
        cin>>n>>x>>k;
        ll ans=calc(x, k, n);
        while(x>>1)
        {
            k--;
            //find fa[x]
            ans+=calc(x>>1, k, n)-calc(x, k-1, n);
            x>>=1;
        }
        cout<<ans<<endl;
    }
	return 0;
}
