#include<bits/stdc++.h>
using namespace std;
const int N=3005,M=30;
struct node{
	int len,n,add,x[M],num[M];
}a[N<<1];
int n,m,c[N][M],b[N<<1],ans[N<<1];
bool cmp(node x,node y)
{
	int z=1;
	while(z<=x.len&&z<=y.len&&x.x[z]==y.x[z]&&x.num[z]==y.num[z])z++;
	if(z>x.len||z>y.len)return 0;
	if(x.x[z]<y.x[z])return 1;
	if(x.x[z]==y.x[z]&&x.num[z]<y.num[z]&&x.x[z+1]<y.x[z])return 1;
	if(x.x[z]==y.x[z]&&x.num[z]>y.num[z]&&x.x[z]<y.x[z+1])return 1;
	return 0;
}
bool sm(node x,node y)
{
	int z=1;
	while(z<=x.len&&z<=y.len&&x.x[z]==y.x[z]&&x.num[z]==y.num[z])z++;
	if(z==x.len+1&&z==y.len+1)return 1;
	return 0;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	char ch=getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{	
			while(ch<'a'||ch>'z')ch=getchar();
			c[i][ch-'a'+1]++;
			ch=getchar();
		}
		a[i].n=i;a[i].add=0;a[i].len=0;
		for(int j=1;j<=26;j++)
			if(c[i][j]!=0)
				a[i].x[++a[i].len]=j,
				a[i].num[a[i].len]=c[i][j];
		a[n+i].n=i;a[n+i].add=1;a[n+i].len=0;
		for(int j=26;j>0;j--)
			if(c[i][j]!=0)
				a[n+i].x[++a[n+i].len]=j,
				a[n+i].num[a[n+i].len]=c[i][j];
	}
	sort(a+1,a+n+n+1,cmp);
//	for(int i=1;i<=n+n;i++)
//	{
//		for(int j=1;j<=a[i].len;j++)
//			cout<<a[i].x[j]<<' '<<a[i].num[j]<<' ';
//		cout<<endl;
//	}
	for(int i=1;i<=n+n;i++)
		b[i]=b[i-1]+(a[i].add);
	for(int i=1;i<=n+n;i++)
	{
		if(a[i].add==1)continue;
		int l=i,r=n+n,h=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sm(a[i],a[mid]))
				h=mid,l=mid+1;
			else
				r=mid-1;
		}
		if((a[i].len>1&&b[n+n]-b[h]==n)||(a[i].len==1&&b[n+n]-b[h]==n-1))
			ans[a[i].n]=1;
		else
			ans[a[i].n]=0;
	}
	for(int i=1;i<=n;i++)
		if(ans[i]==1)
			putchar('1');
		else
			putchar('0');
	return 0;
}