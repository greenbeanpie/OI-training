#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int a[N][N],b[N][N];
inline bool cmp(register int x,register int y)
{
	return x>y;
}
signed main(void){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	register int n,m;
	scanf("%d%d",&n,&m);
	string cur;
	int minn=1;
	for(register int i=1;i<=n;i++)
	{
		cin>>cur;
		for(register int j=0;j<m;j++)
		{
			a[i][j+1]=(int)(cur[j]-'a');
			b[i][j+1]=a[i][j+1];
		}
		sort(a[i]+1,a[i]+1+m);
		sort(b[i]+1,b[i]+1+m,cmp);
		for(register int j=1;j<=m;j++)
		{
			if(b[i][j]>b[minn][j]) break;
			if(b[i][j]<b[minn][j])
			{
				minn=i;
				break;
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(i==minn)
		{
			printf("1");
			continue;
		}
		register int j;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]<b[minn][j])
			{
				printf("1");
				break;
			}
			if(b[minn][j]<a[i][j])
			{
				printf("0");
				break;
			}
		}
		if(j>m) printf("0");
	}
	return 0;
}