#include <bits/stdc++.h>
using namespace std;
#define re register
const int maxn=3003;

int n,m;
vector<string> vc(maxn);
vector<int> ans(maxn);
vector<string> asct(maxn);
vector<string> ascf(maxn);

inline void zj(int k)
{
    string s=vc[k];
    asct[k]=s;
    ascf[k]=s;
    char arr[m];
    for(re int i=0;i<m;i++)
    {
        arr[i]=s[i];
    }
    sort(arr,arr+m);
    for(re int i=0;i<m;i++)
    {
        asct[k][i]=arr[i];
        ascf[k][m-1-i]=arr[i];
    }
}

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(re int i=1;i<=n;i++)
        cin>>vc[i];

    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            ans[i]=1;
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                if(vc[i]>=vc[j])
                {
                    ans[i]=0;
                    break;
                }
            }
        }
    }
    else
    {
        for(re int i=1;i<=n;i++)
        {
            zj(i);
        }
        for(re int i=1;i<=n;i++)
        {
            ans[i]=1;
            for(re int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                if(asct[i]>=ascf[j])
                {
                    ans[i]=0;
                    break;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i];
    }

    return 0;
}
