#include <bits/stdc++.h>
using namespace std;
int a[3010][2],ans[3010];
int main()
{
	freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	int n,m;char tmp;scanf("%d%d",&n,&m);for(int i=1;i<=n;i++) ans[i]=1,a[i][1]=27;
	for(int i=1;i<=n;i++){tmp=getchar();for(int j=1;j<=m;j++) tmp=getchar(),a[i][0]=max(a[i][0],tmp-'a'),a[i][1]=min(a[i][1],tmp-'a');}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		if(a[i][0]<=a[j][1]) ans[j]=0;
		if(a[i][1]>=a[j][0]) ans[i]=0;
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);return 0;
}