#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') f=(ch=='-')?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=3005;
int a[N][28],pre[N],ne[N];
char ch[N];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n=read(),m=read();
	if(n==1) return puts("1"),0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch);
//		if(i==1525) cerr<<ch<<endl;
		for(int j=0;j<m;j++) a[i][ch[j]-'a']++;
		for(int j=0;j<=25;j++)
			if(a[i][j])
			{
				pre[i]=j;
				break;
			}
		for(int j=25;j>=0;j--)
			if(a[i][j])
			{
				ne[i]=j;
				break;
			}
//		cerr<<pre[i].fi<<' '<<pre[i].se<<' '<<ne[i].fi<<' '<<ne[i].se<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=true;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(pre[i]<ne[j]) continue;
//			if(pre[i].fi==ne[j].fi&&pre[i].se<ne[j].se) continue;
			flag=false;
			break;
		}
		if(flag) printf("1");
		else printf("0");
	}
	return 0;
}