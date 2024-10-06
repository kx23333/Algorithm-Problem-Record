//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
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
#define endl "\n"
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

constexpr int inf=0x3f3f3f3f;
constexpr ll llinf=0x3f3f3f3f3f3f3f3fll;
constexpr int N=10000010;

int n, a[N];
int tr[N][2];
int s[N], top=0;

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
    cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++)
    {
        while(top && a[s[top]]>a[i]) tr[i][0]=s[top--];
        if(top) tr[s[top]][1]=i;
        s[++top]=i;
    }
    ll x=0, y=0;
    for(int i=1; i<=n; i++)
    {
        x^=(ll)(tr[i][0]+1)*i;
        y^=(ll)(tr[i][1]+1)*i;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}