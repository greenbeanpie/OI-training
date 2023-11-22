#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
const int maxm=3005;
const int sz=26;
int n,m,cnt[maxn][sz],fi,se;
char s[maxm],ans[maxn];
#define cmp asfdaldf
#define check asfhasdfjh
inline bool cmp(int x,int y)
{
    int i;
    for(i=sz-1;i>=0;i--)
        if(cnt[x][i]!=cnt[y][i])
            return cnt[x][i]>cnt[y][i];
    return 0;
}
inline bool check(int x,int y)
{
    if(y==-1) return true;
    int i,j;
    for(i=0;i<sz;i++)
        if(cnt[x][i])
            break;
    for(j=sz-1;j>=0;j--)
        if(cnt[y][j])
            break;
    return i<j;
}
int main()
{
    int i,j;
    freopen("dict.in","r",stdin),freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=0;j<sz;j++)
            cnt[i][j]=0;
        for(j=0;j<m;j++)
            ++cnt[i][(int)(s[j]-'a')];
    }
    for(fi=se=-1,i=0;i<n;i++)
        if(fi==-1 || cmp(fi,i))
            se=fi,fi=i;
        else if(se==-1 || cmp(se,i))
            se=i;
    for(ans[n]='\0',i=0;i<n;i++)
        ans[i]=check(i,(fi==i)?se:fi)?'1':'0';
    printf("%s\n",ans);
    fclose(stdin),fclose(stdout);
    return 0;
}