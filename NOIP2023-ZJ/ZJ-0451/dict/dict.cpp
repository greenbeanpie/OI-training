#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct newchar
{
    char ch[3010];
    int idx;
    bool operator < (const newchar &o) const
    {
        for (int i=1;i<=m;++i)
            if (ch[i] != o.ch[i])
                return ch[i] < o.ch[i];
        return false;
    }
};
newchar csmall[3010],clarge[3010];
bool cmp1(newchar a,newchar b)
{
    for (int i=1;i<=m;++i)
        if (a.ch[i] != b.ch[i])
            return a.ch[i] < b.ch[i];
    return true;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%s",csmall[i].ch+1);
    for (int i=1;i<=n;++i)
        sort(csmall[i].ch+1,csmall[i].ch+m+1);
    for (int i=1;i<=n;++i)
        clarge[i].idx = i;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            clarge[i].ch[j] = csmall[i].ch[m-j+1];
    sort(clarge+1,clarge+n+1,cmp1);
    for (int i=1;i<=n;++i)
        {
            if (clarge[1].idx != i)
                {
                    if (csmall[i] < clarge[1])
                        printf("1");
                    else
                        printf("0");
                }
            else
                {
                    if (csmall[i] < clarge[2])
                        printf("1");
                    else
                        printf("0");
                }
        }
    return 0;
}