#include<bits/stdc++.h>
#define poly vector<int>
#define pa pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ll long long
using namespace std;
const int N=3005;
int n,m,mx[N],mn[N];
void BellaKira()
{
    cin>>n>>m;
    multiset<int>all;
    for (int i=1;i<=n;i++)
    {
        string st;
        cin>>st;
        mn[i]=26,mx[i]=0;
        for (auto u:st)
        {
            mx[i]=max(mx[i],(int)(u-'a'));
            mn[i]=min(mn[i],(int)(u-'a'));
        }
        all.insert(mx[i]);
    }
    all.insert(26);
    for (int i=1;i<=n;i++)
    {
        all.erase(all.find(mx[i]));

        if ((*all.begin())>mn[i]) cout<<1;
        else cout<<0;

        all.insert(mx[i]);
    }
    cout<<'\n';
}
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    while (T--)
    {
        BellaKira();
    }
}