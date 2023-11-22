#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i=(j);i<=(k);i++)
#define per(i,j,k) for (int i=(j);i>=(k);i--)
#define ll long long
template<class T>void chkmin(T&x,T y){x=min(x,y);}
template<class T>void chkmax(T&x,T y){x=max(x,y);}
const int N=3005;
int n,m;
int mn[N],mx[N];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i,1,n)
    {
        mn[i]=30,mx[i]=-1;
        rep(j,1,m)
        {
            char x;
            cin >> x;
            int y=x-'a';
            chkmax(mx[i],y),chkmin(mn[i],y);
        }
    }
    rep(i,1,n)
    {
        bool ans=1;
        rep(j,1,n) if (j!=i&&mn[i]>=mx[j]) ans=0;
        cout << ans;
    }
    cout << "\n";
    return 0;
}