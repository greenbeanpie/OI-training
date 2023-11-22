#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define ll long long
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}
const int N=2e5+51;
int n,m;
int fa[N];
int find(int x)
{
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    x=find(x),y=find(y);
    if (x==y) return;
    fa[x]=y;
}
bool w[N];
void make(int x,int y,int z)
{
    if (z==0)
    {
        if (find(x)==find(y+n)) 
        {
            w[x]=1;
            return;
        }
        merge(x,y),merge(x+n,y+n);
        return;
    }
    else
    {
        if (find(x)==find(y))
        {
            w[x]=1;
            return;
        }
        merge(x+n,y),merge(x,y+n);
        return;
    }
}
void init()
{
    rep(i,1,n*2) fa[i]=i;
}
int a[N];
inline int rev(int x)
{
    if (x>n) return x-n;
    if (x>0) return x+n;
    if (x==-3) return x;
    return -3-x;
}
void work()
{
    cin >> n >> m;
    n+=2;
    init();
    make(n-1,n,1);
    rep(i,1,n) a[i]=i;
    rep(i,1,n*2) w[i]=0;
    rep(i,1,m)
    {
        char c;
        cin >> c;
        if (c=='T'||c=='F'||c=='U')
        {
            int x;
            cin >> x;
            if (c=='T') a[x]=-1;
            else if (c=='F') a[x]=-2;
            else a[x]=-3;
        } 
        else if (c=='+')
        {
            int x,y;
            cin >> x >> y;
            a[x]=a[y];
        }
        else
        {
            int x,y;
            cin >> x >> y;
            a[x]=rev(a[y]);
        }
    }
    // rep(i,1,n-2) cerr << a[i] << " ";
    // cerr << endl;
    rep(i,1,n-2)
    {
        if (a[i]==-3) w[i]=1;
        else if (a[i]==-2) make(i,n,0);
        else if (a[i]==-1) make(i,n-1,0);
        else if (a[i]<=n) make(i,a[i],0);
        else make(i,a[i]-n,1);
    }
    // rep(i,1,n-2) cerr << w[i] << " ";
    // cerr << endl;
    rep(i,1,n-2) if (w[i]==1) w[find(i)]=1,w[find(i+n)]=1;
    int ans=0;
    rep(i,1,n-2) if (w[find(i)]==1) ans++;
    cout << ans << "\n";
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int id,T;
    cin >> id >> T;
    while (T--) work();
    return 0;
}