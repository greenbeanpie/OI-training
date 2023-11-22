#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define il inline
#define re register
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
//#define int ll
#define pii pair<int,int>
#define mp make_pair
#define F(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DF(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define G(i,u) for(int (i)=head[(u)];(i);(i)=nxt[(i)])
il ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}return x*f;}
const int N=3010;
int n,m,firmin,secmin;
char a[N][N];
int t[30];
int ans[N];
char minn[N][N],maxx[N][N];
il void init(int id)
{
	F(i,1,26) t[i]=0;
	int now=1;
	F(i,1,m) t[a[id][i]-'a'+1]++;
	F(i,1,26)
	{
		F(j,1,t[i])
		{
			minn[id][now++]='a'+i-1;
		}
	}
	now=1;
	DF(i,26,1)
	{
		F(j,1,t[i])
		{
			maxx[id][now++]='a'+i-1;
		}
	}
}
il bool cmp(int i,int j) 
{
	F(k,1,m)
	{
		if(maxx[i][k]!=maxx[j][k])
		{
			return maxx[i][k]>maxx[j][k];
		}
	}
	return 0;
}
il void findmax()
{
	int flag=cmp(1,2);
	if(flag==0)
	{
		F(i,1,m) maxx[n+1][i]=maxx[1][i];
		F(i,1,m) maxx[n+2][i]=maxx[2][i];
		firmin=1;
		secmin=2;
	}
	else if(flag==1)
	{
		F(i,1,m) maxx[n+1][i]=maxx[2][i];
		F(i,1,m) maxx[n+2][i]=maxx[1][i];
		firmin=2;
		secmin=1;
	}
	F(i,3,n)
	{
		if(cmp(n+1,i))
		{
			F(j,1,m) maxx[n+2][j]=maxx[n+1][j];
			F(j,1,m) maxx[n+1][j]=maxx[i][j];
			secmin=firmin;
			firmin=i;
		}
		else if(cmp(n+2,i))
		{
			F(j,1,m) maxx[n+2][j]=maxx[i][j];
			secmin=i;
		}
	}
}
il bool check(int id)
{
	if(firmin!=id)
	{
		int flag=0;
		F(i,1,m)
		{
			if(minn[id][i]>maxx[n+1][i])
			{
				return 0;
			}
			else if(minn[id][i]<maxx[n+1][i])
			{
				flag=1;
				break;
			}
		}
		return flag;
	}
	if(secmin!=id)
	{
		int flag=0;
		F(i,1,m)
		{
			if(minn[id][i]>maxx[n+2][i])
			{
				return 0;
			}
			else if(minn[id][i]<maxx[n+2][i])
			{
				flag=1;
				break;
			}
		}
		return flag;
	}
	return 1;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	F(i,1,n) scanf("%s",a[i]+1);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	F(i,1,n) init(i);
	findmax();
	F(i,1,n)
	{
		if(check(i))
		{
			ans[i]=1;
		}
		else
		{
			ans[i]=0;
		}
	}
	F(i,1,n)
	{
		printf("%d",ans[i]);
	}
	return 0;
}
