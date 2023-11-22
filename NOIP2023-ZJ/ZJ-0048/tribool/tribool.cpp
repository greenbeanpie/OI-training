#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
constexpr int N=100010;

int C,T,n,m,b[N],mn,sum,c[N],f[N],num[N],fa[N];
bool bo[N],flag;
int ok[N];
vector <pair<int,int> > v[N];
char ch[10];

struct node{
	int id,x,y;
}a[N];

inline bool check()
{
	for (int i=1;i<=n;i++)
	{
		c[i]=b[i];
	}
	for (int i=1;i<=m;i++)
	{
		if (a[i].id<=3)
		{
			c[a[i].x]=a[i].id;
		}
		else if (a[i].id==4)
		{
			c[a[i].x]=c[a[i].y];
		}
		else
		{
			if (c[a[i].y]==3) c[a[i].x]=3;
			else c[a[i].x]=3-c[a[i].y];
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (c[i]!=b[i]) return 0;
	}
	return 1;
}

void dfs(int t)
{
	if (t>n)
	{
		sum=0;
		for (int i=1;i<=n;i++)
		{
			if (b[i]==3)
			{
				sum++;
			}
		}
		if (sum<mn)
		{
			if (check()) mn=sum;
		}
		return;
	}
	for (int i=1;i<=3;i++)
	{
		b[t]=i;
		dfs(t+1);
	}
}

void dfs2(int t,int s,int id)
{
//	cout<<t<<" "<<s<<endl;
	ok[t]=id;
	num[t]=s;
	for (pair<int,int> pa:v[t])
	{
		if (!ok[pa.fi])
		{
//			cout<<"!!!"<<" "<<pa.fi<<" "<<pa.se<<endl;
			fa[pa.fi]=t;
			dfs2(pa.fi,s^pa.se,id);
		}
		else if (ok[pa.fi]==id)
		{
//			cout<<"@@@"<<endl;
			if (flag) continue;
			flag=1;
//			cout<<"&&&"<<endl;
			if ((s^pa.se)!=num[pa.fi])
			{
				int p=t;
//				int oo=0;
//				cout<<t<<" "<<pa.fi<<endl;
				while (p!=pa.fi)
				{
//					oo++;
//					if (oo>10) break;
//					cout<<p<<endl;
					b[p]=3;
					p=fa[p];
				}
				b[p]=3;
			}
		}
	}
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1,x,y;i<=m;i++)
		{
			scanf("%s%d",ch,&x);
			if (ch[0]=='T')
			{
				a[i].id=1;
				a[i].x=x;
			}
			else if (ch[0]=='F')
			{
				a[i].id=2;
				a[i].x=x;
			}
			else if (ch[0]=='U')
			{
				a[i].id=3;
				a[i].x=x;
			}
			else if (ch[0]=='+')
			{
				a[i].id=4;
				a[i].x=x;
				scanf("%d",&y);
				a[i].y=y;
			}
			else
			{
				a[i].id=5;
				a[i].x=x;
				scanf("%d",&y);
				a[i].y=y;
			}
		}
		if (C<=2)
		{
			mn=20;
			dfs(1);
			printf("%d\n",mn);
		}
		else if (C<=4)
		{
			for (int i=1;i<=n;i++)
			{
				b[i]=0;
			}
			for (int i=1;i<=m;i++)
			{
				b[a[i].x]=a[i].id;
			}
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (b[i]==3) cnt++;
			}
			printf("%d\n",cnt);
		}
		else if (C<=6)
		{
			for (int i=1;i<=n;i++) b[i]=1;
			for (int i=1;i<=m;i++)
			{
				if (a[i].id==3) b[a[i].x]=3;
				else b[a[i].x]=b[a[i].y];
			}
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (b[i]==3) cnt++;
			}
			while (1)
			{
				int pp=cnt;
				for (int i=1;i<=m;i++)
				{
					if (a[i].id==3) b[a[i].x]=3;
					else b[a[i].x]=b[a[i].y];
				}
				cnt=0;
				for (int i=1;i<=n;i++)
				{
					if (b[i]==3) cnt++;
				}
				if (pp==cnt) break;
			}
			printf("%d\n",cnt);
		}
		else if (C<=8)
		{
			for (int i=1;i<=n;i++)
			{
				f[i]=i;
				bo[i]=1;
				v[i].clear();
			}
			for (int i=1;i<=m;i++)
			{
				if (a[i].id==4)
				{
					f[a[i].x]=f[a[i].y];
					bo[a[i].x]=bo[a[i].y];
				}
				else
				{
					f[a[i].x]=f[a[i].y];
					bo[a[i].x]=bo[a[i].y]^1;
				}
			}
			for (int i=1;i<=n;i++)
			{
				ok[i]=0,b[i]=0;
				fa[i]=0;
//				cout<<i<<" "<<f[i]<<endl;
				v[f[i]].push_back({i,bo[i]^1});
			}
//			cout<<"PPP"<<endl;
			for (int i=1;i<=n;i++)
			{
				if (!ok[i])
				{
					flag=0;
					dfs2(i,0,i);
				}
			}
			for (int i=1;i<=m;i++)
			{
				b[a[i].x]=b[a[i].y];
			}
			int cnt=0;
			for (int i=1;i<=n;i++)
			{
				if (b[i]==3) cnt++;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}