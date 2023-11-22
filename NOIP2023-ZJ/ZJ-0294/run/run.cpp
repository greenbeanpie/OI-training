#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll c,t,n,m,k,d,ans;
struct node{
    ll x,y,v,l;
}a[N];
bool operator<(node r,node c){return r.x<c.x;}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m>>k>>d;
        for(int i=1;i<=m;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].v;
            a[i].l=a[i].x-a[i].y+1,a[i].v-=a[i].y*d;
        }
        if(c>=17&&c<=18)
        {
            for(int i=1;i<=m;i++) 
                if(a[i].y<=k)
                    ans+=max(0LL,a[i].v);
            cout<<ans<<'\n';
        }

    }
    return 0;
}