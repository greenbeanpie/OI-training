#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int x[maxn],y[maxn],x_[maxn],y_[maxn],n,m;
bool ok[maxn][maxn];
inline int check()
{
    int i,j;
    ok[1][1]=(x[1]!=y[1]);
    for(i=1;i<=n;i++)
        for(j=(i==1)?2:1;j<=m;j++)
            ok[i][j]=((x[1]<y[1] && x[i]<y[j]) || (x[1]>y[1] && x[i]>y[j]))
                && ((i>1 && ok[i-1][j]) || (j>1 && ok[i][j-1]));
    return ok[n][m];
}
int main()
{
    int q,i,j,s,t;
    freopen("expand.in","r",stdin),freopen("expand.ans","w",stdout);
    scanf("%*d%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++) scanf("%d",&x_[i]);
    for(i=1;i<=m;i++) scanf("%d",&y_[i]);
    for(i=1;i<=n;i++) x[i]=x_[i];
    for(i=1;i<=m;i++) y[i]=y_[i];
    printf("%d",check());
    while(q--)
    {
        for(i=1;i<=n;i++) x[i]=x_[i];
        for(i=1;i<=m;i++) y[i]=y_[i];
        scanf("%d%d",&s,&t);
        while(s--) scanf("%d",&i),scanf("%d",&x[i]);
        while(t--) scanf("%d",&i),scanf("%d",&y[i]);
        printf("%d",check());
    }
    printf("\n");
    fclose(stdin),fclose(stdout);
    return 0;
}