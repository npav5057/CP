#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
typedef int64_t ll;
typedef uint64_t ull; 
typedef unsigned uint;
typedef long double lld;

#define inf     (int) 2e9
#define INF     (ll) 2e18
#define cnl     putchar('\n')
#define nl      '\n'
#define yes     cout << "YES\n"
#define no      cout << "NO\n"
#define eb      emplace_back    
#define PB      push_back
#define umap    unordered_map
#define uset    unordered_set
#define F       first
#define S       second
#define fast            ios_base::sync_with_stdio(0),cin.tie(0);
#define ITR1(it,c)      for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ITR(it,ct)      for(auto it:ct)
#define PR(ct)          ITR(it,ct)_print(it);
#define allr(c)         (c).rbegin(),(c).rend()
#define all(c)          (c).begin(),(c).end()
#define dsort(v)        sort(all(v), greater<int>())
#define asort(v)        sort(all(v))
#define ptc(c)          putchar(c)
void _print(int t){cerr<<t<<" ";}void _print(string t){cerr<<t<<" ";}
void _print(char t){cerr<<t<<" ";}void _print(lld t) {cerr<<t<<" ";}
void _print(double t){cerr<<t<<" ";}void _print(ull t) {cerr<<t<<" ";}
void _print(ll t){cerr<<t<<" ";}void _print(bool t) {cerr<<t<<" ";}
template <class T, class V> void _print(pair<T, V> p){cerr << "{ "; _print(p.F);cerr <<',';_print(p.S);cerr << '}';}
template <class T> void _print(vector<T> v){cerr << "[ ";PR(v);cerr << "]";}
template <class T> void _print(set<T> v) {cerr << "[ ";PR(v);cerr << "]";}
template <class T> void _print(multiset<T> v){cerr << "[ ";PR(v);cerr << "]";}
template <class T, class V> void _print(map<T, V> v){cerr << "[ ";PR(v);cerr << "]";}
template <class T> T ceil(T nm, T dn) {return (nm+dn-1)/dn;}
template <class T> T gcd(T a, T b){if(b==0)return a;return gcd(b,a%b);}
#define flogll(n)        63-__builtin_clzll(n)
#define flog(n)          31-__builtin_clz(n)
#define mset(m, v)       memset(m, v, sizeof(m))
#define debug(a)         cerr << #a << ": " << a << ' ';
#define ask(x,y)         cout<<"? "<<x<<" "<<y<<endl; 
#define ii      int,int
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef pair<ii>    pii;
typedef vector<pii> vpii;
typedef vector<vi>  vvi;
typedef map<ii>     mpii;
// typedef tree< pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#define maxa(cont,val)  if(cont<val)cont=val
#define mina(cont,val)  if(cont>val)cont=val
#define rep(i,n)        for(__typeof(n) i=0;  i<n; ++i )
#define rep1(i,n)       for(__typeof(n) i=1;  i<=n;++i)
#define rrep(i,n)       for(__typeof(n) i=n-1;i>=0;--i)
#define rrep1(i,n)      for(__typeof(n) i=n;  i>=1;--i)
#define myrrep(i,b,a)   for(__typeof(a) i=b;  i>=a;--i)
#define myrep(i,a,b)    for(__typeof(a) i=a;  i<b;i++)
#define readar(a, n)    rep(i,n)a[i]=in();
#define printar(a, n)   rep1(i,n){cout<<a[i]<<" ";}cout<<nl;
#define chekif(m,x)     (m).find(x)!=(m).end()
#define ctz(x) __builtin_ctz(x)
#define TOYES(x)        printf(x?"YES\n":"NO\n")
#define nl              '\n'
#define MOD 1000000007
#define MAX (int)2e5+1
int a[MAX][30],k,e,n,m;
int test()
{
    int sum=0;
    const int d=m-e;
    rep(i,30)sum+=((int)(d+a[e][i]==a[m][i]))<<i;
    return sum>=k;
}
void solve()
{
    int q;
    mset(a[0],0);
    cin>>n;
    rep1(i,n)
    {
        cin>>q;
        rep(j,30)a[i][j]=a[i-1][j]+(q&1),q>>=1;
    }
    cin>>q;
    while(q--)
    {
        cin>>e>>k;
        int l=e--,r=n,ans=-1;
        while(l<=r)
        {
            m=(l+r)>>1;
            if(test())
            {
                ans=m,l=m+1;
            }else r=m-1;
        }
        cout<<ans<<' ';
    }
    cout<<nl;
}
int main()
{
    fast;
   
    int t =1;
    cin>>t;
    while (t--) solve();
    return 0;
}


