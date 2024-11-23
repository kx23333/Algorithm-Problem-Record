//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,j) (i)=min((i),(j))
#define cmax(i,j) (i)=max((i),(j))
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define all(x) x.begin(), x.end()
#define each(i,x) for(auto &i:(x))
#define fi first
#define se second
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert

using ll=long long;
using ull=unsigned long long;
using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

inline namespace FileIO{
void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }
void setIO(string s="")
{	
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	#ifndef LOCAL
        if(s.size()) setIn(s+".in"), setOut(s+".out");
	#else
        setIn("inkorange.in"), setOut("inkorange.out");
    #endif
}
}

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;

signed main()
{
	setIO();
	int n, d; cin>>n>>d;
    vector<int> v(n), w(n+1);
    vector<ll> dist(n+1), c(n+1);
    for(int i=1; i<n; i++) cin>>v[i], dist[i+1]=v[i]+dist[i];
    for(int i=1; i<=n; i++) cin>>w[i], c[i]=(dist[i]+d-1)/d;
    // for(int i=1; i<=n; i++) debug(dist[i]);
    int lst=1;
    ll ans=w[lst]*c[n];
    for(int i=2; i<=n; i++) if(w[i]<w[lst])
        ans-=(c[n]-c[i])*(w[lst]-w[i]), lst=i;
    cout<<ans<<endl;
	return 0;
}
// greedy, implementation