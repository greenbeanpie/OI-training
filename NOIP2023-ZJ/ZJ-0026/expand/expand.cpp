#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define ll long long
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}

int n,m,q;
const int N=5e5+5;
int a[N],b[N],c[N],d[N];
int top,st[N];

bool solve(int *a,int *b,int n,int m,int &u)
{
    top=0;
    rep(i,1,n)
    {
        if (top==0||a[i]>=a[st[top]]) st[++top]=i;
    }
    u=1;
    rep(i,1,top-1)
    {
        int mn=a[st[i]],mx=-1;
        rep(j,st[i],st[i+1]-1) chkmin(mn,a[j]);
        while (u<=m&&b[u]>=mn) chkmax(mx,b[u]),u++;
        if (u>m) return 0;
        if (mx>=a[st[i]]) return 0;
    }
    return 1;
}

bool work(int n,int m)
{
    // rep(i,1,n) cerr << a[i] << " ";
    // cerr << endl;
    // rep(i,1,m) cerr << b[i] << " ";
    // cerr << endl;
    if (a[1]==b[1]||a[n]==b[m]) return 0;
    if (a[1]<b[1]) swap(a,b),swap(n,m);
    if (a[n]<b[m]) return 0;
    int u;
    if (solve(a,b,n,m,u)==0) return 0;
    int v=st[top],w;
    rep(i,1,m) if (b[i]>=a[v]) return 0;
    reverse(a+1,a+n+1),reverse(b+1,b+m+1);
    if (solve(a,b,n-v+1,m-u+1,w)==0) return 0;
    return 1;
}
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int id;
    cin >> id >> n >> m >> q;
    rep(i,1,n) cin >> c[i];
    rep(i,1,m) cin >> d[i];
    rep(j,1,n) a[j]=c[j];
    rep(j,1,m) b[j]=d[j];
    cout << work(n,m);
    rep(i,1,q)
    {
        rep(j,1,n) a[j]=c[j];
        rep(j,1,m) b[j]=d[j];
        int kx,ky;
        cin >> kx >> ky;
        rep(j,1,kx)
        {
            int x,y;
            cin >> x >> y;
            a[x]=y;
        }
        rep(j,1,ky)
        {
            int x,y;
            cin >> x >> y;
            b[x]=y;
        }
        cout << work(n,m);
    }
    cout << "\n";
    return 0;
}