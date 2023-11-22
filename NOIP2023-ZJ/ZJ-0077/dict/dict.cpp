#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=3e3+5;
int n,m,Min[INF],Max[INF];
string s1[INF];
signed main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>s1[i];
    // if (n==1) {
    //     cout<<"1\n";
    //     return 0;
    // }
    for (int i=1;i<=n;i++) {
        Max[i]=Min[i]=s1[i][0];
        for (char c:s1[i]) {
            Max[i]=max(Max[i],(int)(c));
            Min[i]=min(Min[i],(int)(c));
        }
    }
    for (int x=1;x<=n;x++) {
        int fl=1;
        for (int i=1;i<=n;i++)
            if (i!=x) {
                if (Max[i]>Min[x]) ;
                else fl=0;
            }
        cout<<fl;
    }
    cout<<"\n";
    return 0;
}