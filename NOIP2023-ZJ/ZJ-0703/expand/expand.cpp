#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cc,m,n,q;
int ka,kb,pa[114514],pb[114514],v;
int a[114514],b[114514],c[114514],d[114514];
string ans;
bool check0()
{
	if((a[1]-b[1])*(a[n]-b[m])<=0)
	{
		return 0;
	}
	return 1;
}
bool check3()
{
	int maa=a[1],mab=b[1],mia=a[1],mib=b[1];
	for(int i=1;i<=n;i++)maa=max(maa,a[i]),mia=min(mia,a[i]);
	for(int i=1;i<=m;i++)mab=max(mab,b[i]),mib=min(mib,b[i]);;
	if(a[1]>b[1])
	{
		if(mia<=mib||maa<=mab){
			return 0;
		}
	}else{
		if(mib>=mia||maa>=mab)
		{
			return 0;
		}
	}
	return 1;
}
bool check1(int x)
{
	int maa=a[1],mab=b[1],mia=a[1],mib=b[1];
	for(int i=1;i<=1+x;i++)maa=max(maa,a[i]),mia=min(mia,a[i]);
	for(int i=1;i<=1+x;i++)mab=max(mab,b[i]),mib=min(mib,b[i]);;
	if(a[1]>b[1])
	{
		if(a[x+1]<=mib&&b[x+1]>=maa){return 0;}
	}else{
		if(b[x+1]<=mia&&a[x+1]>=mab){return 0;}
	}
	maa=a[n],mab=b[m],mia=a[n],mib=b[m];
	for(int i=n-x;i<=n;i++)maa=max(maa,a[i]),mia=min(mia,a[i]);
	for(int i=m-x;i<=m;i++)mab=max(mab,b[i]),mib=min(mib,b[i]);;
	if(a[1]>b[1])
	{
		if(a[n-x]<=mib&&b[m-x]>=maa){return 0;}
	}else{
		if(b[m-x]<=mia&&a[n-x]>=mab){return 0;}
	}
	return 1;
}
bool check2()
{
	int mn=max(m,n)>>1;
	for(int j=1;j<=mn;j++)
	{
		if(!check1(j))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>cc>>n>>m>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[i]=a[i];
	for(int i=1;i<=m;i++)scanf("%d",&b[i]),d[i]=b[i];
	if(check0()&&check2()&&check3())
	{
		ans+="1";
	}else{
		ans+="0";
	}
	while(q--)
	{
		scanf("%d%d",&ka,&kb);
		for(int i=1;i<=ka;i++)scanf("%d%d",&pa[i],&v),a[pa[i]]=v;
		for(int i=1;i<=kb;i++)scanf("%d%d",&pb[i],&v),b[pb[i]]=v;
		if(check0()&&check2()&&check3())
		{
			ans+="1";
		}else{
			ans+="0";
		}
		for(int i=1;i<=ka;i++)a[pa[i]]=c[pa[i]];
		for(int i=1;i<=kb;i++)b[pb[i]]=d[pb[i]];
	}
	cout<<ans;
	return 0;
}