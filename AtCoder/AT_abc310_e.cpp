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

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
    cin>>n;
    vector<char> s(n+1);
	for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    vector<vector<int>> f(n+1, vector<int>(2));
    if(s[1]=='1') f[1][1]=1;
    else f[1][0]=1;
    for(int i=2; i<=n; i++)
    {
        if(s[i]=='1')
        {
            f[i][0]=f[i-1][1];
            f[i][1]=f[i-1][0]+1;//"i==i"
        }
        else
        {
            f[i][0]=1;//"i==i"
            f[i][1]=f[i-1][0]+f[i-1][1];
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++) ans+=f[i][1];
    cout<<ans<<endl;
    return 0;
}
