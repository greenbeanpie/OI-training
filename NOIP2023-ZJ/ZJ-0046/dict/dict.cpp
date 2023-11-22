#include<bits/stdc++.h>
using namespace std;
const int MAXN=3010;
int n,m,w[MAXN*2];
char tmp[MAXN],c[2][MAXN][MAXN],ans[MAXN];
int cnt,num[MAXN];
bool cmp(int x,int y)
{
	for(int i=1;i<=m;i++)
	{
		if(c[x&1][x/2+1][i]>c[y&1][y/2+1][i]) return 1;
		if(c[x&1][x/2+1][i]<c[y&1][y/2+1][i]) return 0;
	}
	if(!(x&1)&&(y&1)) return 1;
	else return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",tmp+1);
		sort(tmp+1,tmp+1+m);
		for(int j=1;j<=m;j++)
			c[0][i][j]=c[1][i][m-j+1]=tmp[j];
	}
	for(int i=0;i<2*n;i++) w[i]=i;
	sort(w,w+2*n,cmp);
	for(int i=0;i<2*n;i++)
	{
		if(!(w[i]&1))
		{
			if(cnt-num[w[i]/2+1]>=n-1) ans[w[i]/2+1]=1;
		}
		else
		{
			num[w[i]/2+1]++;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i]) printf("1");
			else printf("0");
	printf("\n");
	return 0;
}