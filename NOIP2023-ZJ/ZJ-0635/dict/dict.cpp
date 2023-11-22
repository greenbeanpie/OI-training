#include <bits/stdc++.h>//90
using namespace std;
const int N=3e3+5;
int n,m;
char c[N][N];
char c1[N][N];
char ans[N];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch<='9'&&ch>='0') { x=(x<<3)+(x<<1)+ch-48; ch=getchar(); }
	return x*f;
}
bool cmp1(char X,char Y) { return X<Y; }
void init() { for(int i=1;i<=n;i++) ans[i]='7'; }
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	init();
	if(n==1)
	{
		scanf("%s",c);
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]);
		sort(c[i],c[i]+m,cmp1);
		for(int j=0;j<m;j++) c1[i][j]=c[i][m-j-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool flag=true;
			if(j!=i)
			{
				for(int k=0;k<m;k++)
				{
					if(c[i][k]>c1[j][k])
					{
						ans[i]='0';
						flag=false;
						break;
					}
					if(c[i][k]<c1[j][k]) break;
				}
			}
			if(!flag) break;
		}
		if(ans[i]!='0') ans[i]='1';
	}
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
	return 0;
}
