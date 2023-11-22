#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
char s[3010][3010];
ull hsh[3010][3010];
int n,m;
void init(int x)
{
	for(int i=1;i<=m;i++)
		hsh[x][i]=hsh[x][i-1]*893+s[x][i];
}
int cmp(int x,int y)
{
	int l=1,r=m,res=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(hsh[x][mid]==hsh[y][mid])
			l=mid+1,res=mid;
		else
			r=mid-1;
	}
	if(res==m)
		return 0;
	return s[x][res+1]<s[y][res+1];
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1),sort(s[i]+1,s[i]+m+1,greater<char>()),init(i);
	for(int i=1;i<=n;i++)
	{
		sort(s[i]+1,s[i]+m+1);init(i);
		if(i-1)
			sort(s[i-1]+1,s[i-1]+m+1,greater<char>()),init(i-1);
		bool ok=1;
		for(int j=1;j<=n;j++)
			if(cmp(j,i))
			{
				ok=0;
				break;
			}
		putchar(ok+'0');
	}
	puts("");
}
