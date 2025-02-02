// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,inline")
#include <bits/stdc++.h>
using namespace std;

#define cmin(i,n) (i)=min((i),(n))
#define cmax(i,n) (i)=max((i),(n))
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
constexpr int N=3010, base=233;

ull hs[N], fac[N];
int f[N][N];
unordered_map<ull, int> lst;
int n, q;
string s;

signed main()
{
    setIO("substring");
    cin>>n>>q>>s; s="%"+s;
    fac[0]=1;
    for(int i=1; i<=n; i++) hs[i]=hs[i-1]*base+s[i], fac[i]=fac[i-1]*base;
    auto H=[&](int l, int r){ return hs[r]-hs[l-1]*fac[r-l+1]; };
    for(int len=1; len<=n; len++) 
    {
        lst.clear();
        for(int l=1; l+len-1<=n; l++)
        {
            int r=l+len-1;
            ull tmp=H(l, r);
            f[l][r]++;
            f[lst[tmp]][r]--;
            lst[tmp]=l;
        }
    }
    for(int len=1; len<=n; len++) 
        for(int l=1; l+len-1<=n; l++)
        {
            int r=l+len-1;
            debug(f[l][r]);
        }
    for(int l=n; l>=1; l--) for(int r=l; r<=n; r++)
        f[l][r]+=(f[l+1][r]+f[l][r-1]-f[l+1][r-1]);
    while(q--)
    {
        int l, r; cin>>l>>r;
        cout<<f[l][r]<<endl;
    }
    return 0;
}
// strings, hashing, math