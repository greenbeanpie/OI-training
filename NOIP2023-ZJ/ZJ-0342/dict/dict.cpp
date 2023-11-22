#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=3086;

template<typename T>
inline void read(T &x)
{
    T k=1;char ch=getchar();x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')k=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
    x*=k;
}

int n,m,mn[N],mx[N];
char s[N];

void solve()
{
    read(n),read(m);
    for(int i=1;i<=n;i++)
    {
        mx[i]=-1;
        mn[i]=58;
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
            mn[i]=min(mn[i],(int)(s[j]-'a')),mx[i]=max(mx[i],(int)(s[j]-'a'));
    }
    for(int i=1;i<=n;i++)
    {
        bool f=true;
        for(int j=1;j<=n;j++)
            if(i!=j&&mn[i]>=mx[j])
            {
                f=false;
                break;
            }
        if(f) putchar('1');
        else putchar('0');
    }
        
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    solve();
    return 0;
}