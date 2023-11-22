#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[110];
char s[3010][3010],temp[3010];
char now[3010][3010];
int realpos[3010],pos[3010];
vector<int> nowt[110];
int pos1,pos2;
int cmp(int x)
{
    for(int i=1;i<=m;i++)
    {
        if(temp[i]<now[x][i]) return 1;
        if(temp[i]>now[x][i]) return 0;
    }
    return 0;
}
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int tot=0;
        for(int j=1;j<=m;j++)
        {
            s[i][j]=getchar();
            while(s[i][j]<'a'||s[i][j]>'z') s[i][j]=getchar();
            t[s[i][j]-'a']++;
        }
        // for(int j=0;j<=25;j++) printf("%d ",t[j]);
        // printf("\n");
        for(int j=25;j>=0;j--) while(t[j]) now[i][++tot]=(j+'a'),t[j]--;
        realpos[i]=i;
        // for(int j=1;j<=m;j++) printf("%c",now[i][j]);
        // printf("\n");
    }
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    for(int i=m;i>=1;i--)
    {
        int tot=0;
        for(int j=1;j<=n;j++) pos[realpos[j]]=j;
        for(int j=1;j<=n;j++) nowt[now[pos[j]][i]-'a'].push_back(pos[j]);
        for(int j=0;j<=25;j++) for(int k=0;k<nowt[j].size();k++) realpos[nowt[j][k]]=++tot;
        for(int j=0;j<=25;j++) nowt[j].clear();
    }
    for(int i=1;i<=n;i++)
    {
        if(realpos[i]==1) pos1=i;
        if(realpos[i]==2) pos2=i;
    }
    for(int i=1;i<=n;i++)
    {
        int tot=0;
        for(int j=1;j<=m;j++) t[s[i][j]-'a']++;
        for(int j=0;j<=25;j++) while(t[j]) temp[++tot]=j+'a',t[j]--;
        if(pos1==i) printf("%d",cmp(pos2));
        else printf("%d",cmp(pos1));
    }
    printf("\n");
    return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
