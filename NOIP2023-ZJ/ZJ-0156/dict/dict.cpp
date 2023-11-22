#include<bits/stdc++.h>
int cnt[3005][27];
std::string mn[3005];
struct DATA{
	std::string mx;
	int id;
}MX[3005];
bool cmp(DATA x,DATA y)
{
	return x.mx<y.mx;
}
int read()
{
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch&15),ch=getchar();
	return x;
}
int n,m;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			char ch=getchar();
			while(ch<'a'||ch>'z')
				ch=getchar();
			++cnt[i][ch&31];
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=26;++j)
		{
			char tmp1=j^96;
			char tmp2=(26-j+1)^96;
			for(int k=1;k<=cnt[i][j];++k)
				mn[i]+=tmp1;
			for(int k=1;k<=cnt[i][26-j+1];++k)
				MX[i].mx+=tmp2;
		}
		MX[i].id=i;
//		std::cout<<mn[i]<<" "<<mx[i]<<"\n";
	}
	std::sort(MX+1,MX+1+n,cmp);
//	std::cout<<mx[1]<<"\n";
	for(int i=1;i<=n;++i)
	{
//		std::cout<<mn[i]<<"\n";
		if(mn[i]<MX[1].mx||(mn[i]==MX[1].mx&&i==MX[1].id&&(n==1||mn[i]<MX[2].mx)))
			printf("1");
		else
			printf("0");
	}
	return 0;
}
