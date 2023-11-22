//NOIP2023加油！rp++
//jmyzq & yzt
//哪怕全世界都背叛你，我也不会
//为你战死是我至高无上的荣耀
//T组数据不要忘记初始化
//freopen记得检查
//数组不要开太大，MLE本地看不出来
//最大值不要赋值太小
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
int n,m;
char op[M];
int a[M],c[M];
int x[M],y[M];
bool ktfu,k,ku;
int cnt;
int ans;
void clear()
{
	ans=INT_MAX;
	ktfu=0;
	ku=0;
	for(int i=0;i<=n;++i)
	{
		a[i]=-1;
	}
	return ;
}
void copy()
{
	for(int i=1;i<=n;++i)
	{
		c[i]=a[i];
	}
	return ;
}
void work()
{
	copy();
	k=1;cnt=0;
	for(int i=1;i<=m;++i)
	{
		if(op[i]=='+') a[x[i]]=a[y[i]];
		else if(op[i]=='-') a[x[i]]=a[y[i]]^1;
		else
		{
			if(op[i]=='T') a[x[i]]=1;
			else if(op[i]=='F') a[x[i]]=0;
			else a[x[i]]=2;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==c[i] || (a[i]==2 && c[i]==3) || (a[i]==3 && c[i]==2)) k=1;
		else
		{
			k=0;
			break;
		}
		if(c[i]==2 || c[i]==3)
		{
			cnt++;
		}
	}
	if(k) ans=min(ans,cnt);
	k=1;cnt=0;
}
int cnttfu;
void worktfu()
{
	cnttfu=0;
	for(int i=1;i<=m;++i)
	{
		if(op[i]=='T') a[x[i]]=1;
		else if(op[i]=='F') a[x[i]]=0;
		else a[x[i]]=2;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]==2 || a[i]==3) cnttfu++;
	}
	ans=cnttfu;
	return ;
}
int cntu;
void worku()
{
	cntu=0;
	for(int i=1;i<=m;++i)
	{
		if(op[i]=='+')
		{
			if(x[i]==y[i]) continue;
			if((a[y[i]]==2 || a[y[i]]==3) && (a[x[i]]!=2 || a[x[i]]!=3))
			{
				cntu++;
				a[x[i]]=a[y[i]];
			}
			else if((a[y[i]]!=2 || a[y[i]]!=3) && (a[x[i]]==2 || a[x[i]]==3))
			{
				cntu--;
				a[x[i]]=a[y[i]];
			}
		}
		else if(op[i]=='U')
		{
			if(a[x[i]]!=2 || a[x[i]]!=3)
			{
				cntu++;
			}
			a[x[i]]=2;
		}
	}
	ans=cntu;
	return ;
}
void baol()
{		
	for(int i1=0;i1<=2;++i1)
		for(int i2=0;i2<=2;++i2)
			for(int i3=0;i3<=2;++i3)
				for(int i4=0;i4<=2;++i4)
					for(int i5=0;i5<=2;++i5)
						for(int i6=0;i6<=2;++i6)
							for(int i7=0;i7<=2;++i7)
								for(int i8=0;i8<=2;++i8)
									for(int i9=0;i9<=2;++i9)
										for(int i10=0;i10<=2;++i10)
										{
											a[1]=i1;a[2]=i2;a[3]=i3;
											a[4]=i4;a[5]=i5;a[6]=i6;
											a[7]=i7;a[8]=i8;a[9]=i9;
											a[10]=i10;
											work();
										}
	return ;
}
void solve()
{
	scanf("%d%d",&n,&m);
	clear();
	for(int i=1;i<=m;++i)
	{
		cin>>op[i];
		if(op[i]=='+')
		{
			scanf("%d%d",&x[i],&y[i]);
			ktfu=1;
		}
		else if(op[i]=='-')
		{
			scanf("%d%d",&x[i],&y[i]);
			ktfu=1;ku=1;
		}
		else
		{
			scanf("%d",&x[i]);
			if(op[i]!='U') ku=1;
		}
	}
	if(n<=11)
	{
		baol();
		printf("%d\n",ans);
		return ;
	}
	if(!ktfu)
	{
		worktfu();
		printf("%d\n",ans);
		return ;
	}
	if(!ku)
	{
		worku();
		printf("%d\n",ans);
		return ;
	}
	printf("0\n");
	return ;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);//不要忘初始化
	while(T--)
	{
		solve();
	}
	return 0;
}
