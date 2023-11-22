#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m;
string s[N];
char mx[N],mn[N];
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        mx[i]=*max_element(s[i].begin(),s[i].end());
        mn[i]=*min_element(s[i].begin(),s[i].end());
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=true;
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                if(mx[j]<=mn[i])
                {
                    flag=false;
                    break;
                }
            }
        if(flag)
            cout<<1;
        else cout<<0;
    }
    cout<<'\n';
    // cerr<<clock()<<'\n';
    return 0;
}