#include<bits/stdc++.h>
using namespace std;

constexpr int maxn=3010;

int mn[maxn],mx[maxn];
char s[maxn];

int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        mn[i]=mx[i]=s[0]-'a';
        for(j=1;j<m;j++)
        {
            mn[i]=min(mn[i],s[j]-'a');
            mx[i]=max(mx[i],s[j]-'a');
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==i) continue;
            if(mx[j]<=mn[i]) break;
        }
        cout<<(j==n+1);
    }
    cout<<'\n';
    return 0;
}
