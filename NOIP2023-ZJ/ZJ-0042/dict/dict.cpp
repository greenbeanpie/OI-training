#include <bits/stdc++.h>
#define rep(i,l,r) for(auto i(l),i##_end(r);i<=i##_end;++i)
#define per(i,r,l) for(auto i(r),i##_end(l);i>=i##_end;--i)
#define fi first
#define se second

using namespace std;
using ll=long long;
using ull=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;
using vii=vector<pii>;

const int N=3005;
int n,m;
struct STR
{
    char a[N];
    char &operator[](int i){ return a[i]; }
} a[N];
bool operator<(STR a,STR b)
{
    rep(i,1,m)
    {
        if(a[i]<b[i]) return 1;
        if(b[i]<a[i]) return 0;
    }
    return 0;
}
pair<STR,int> b[N*2];
int tot;
int ans[N];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    rep(i,1,n)
    {
        scanf(" %s",a[i].a+1);
        tot++;
        b[tot]={a[i],i};
        sort(b[tot].fi.a+1,b[tot].fi.a+m+1);
        tot++;
        b[tot]={a[i],-i};
        sort(b[tot].fi.a+1,b[tot].fi.a+m+1,greater<>());

    }
    // rep(i,1,tot)
    // {
    //     rep(j,1,m) putchar(b[i].fi[j]);
    //     puts("");
    // }
    sort(b+1,b+tot+1);
    int only=0;
    rep(i,1,tot)
    {
        if(b[i].se<0)
        {
            if(only) break;
            only=-b[i].se;
            continue;
        }
        if(only&&only!=b[i].se) break;
        ans[b[i].se]=1;
    }
    rep(i,1,n) putchar(ans[i]+'0');
    return 0;
}