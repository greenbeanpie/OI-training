#include<bits/stdc++.h>
#define maxm 30010
#define base 27
#define ull  long long
#define p (ull)1e14
using namespace std;
ull n,m;
struct sss{
	string st;
	ull id;
	bool operator < (const sss &x) const
	{
		return x.st<st;
	}
};
priority_queue<sss>Q;
struct node{
	ull num;
	ull id;
	bool operator < (const node &x) const
	{
		return x.num<num;
	}
};
priority_queue<node>q;
ull a[maxm][30];
bool vis[maxm];
void solve2()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=26;j++)
			if(a[i][j])
			{
				q.push((node) { j ,i} );
			}
	int t=(q.top()).id;
	for(int i=1;i<=n;i++)
	{
		if(i!=t)cout<<"0";
		else cout<<"1";
	}
	return ;
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		ull t=0;
		for(int j=1;j<=26;j++)
			for(int k=1;k<=a[i][j];k++)
			{
				t=(t*base%p+j)%p;
			}
		q.push((node){t,i});
	}
	while(!q.empty())
	{
		ull id=(q.top()).id,num=(q.top()).num;		
		q.pop();
		
		
		
		while(vis[(q.top()).id]&&(q.top()).num==num&&(!q.empty()))q.pop();
		

		
		if(vis[id]&&num<(q.top()).num)break;
		if(!vis[id])
		{
			vis[id]=1;
			ull t=0;
			for(int j=26;j>=1;j--)
				for(int k=1;k<=a[id][j];k++)
				{
					t=(t*base%p+j)%p;
				}

			q.push((node){t,id});	
		}
		
	}
	for(int i=1;i<=n;i++)
		cout<<vis[i];
	return ;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char ch;cin>>ch;
			a[i][ch-'a'+1]++;
		}	
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(n!=1&&m==1)
	{
		solve2();
		return 0;
	}
	if(m<=2)
	{
		solve3();
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		string s="";
		for(int j=1;j<=26;j++)
			for(int k=1;k<=a[i][j];k++)
			{
				s+=char(j+'a'-1);
			}
		Q.push((sss){s,i});
	}

//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=26;j++)
//			cout<<a[i][j]<<" ";cout<<endl;
//	}
//	while(!q.empty())
//	{
//		cout<<(q.top()).num<<endl;
//		q.pop();
//	}
	
	while(!Q.empty())
	{
		ull id=(Q.top()).id;
		string st=(Q.top()).st;		
		Q.pop();
		

		
		while(vis[(Q.top()).id]&&(Q.top()).st==st&&(!Q.empty()))Q.pop();

		if(vis[id]&&st<(Q.top()).st)break;
		if(!vis[id])
		{
			vis[id]=1;
			string s="";
			for(int j=26;j>=1;j--)
				for(int k=1;k<=a[id][j];k++)
				{
					s+=char(j+'a'-1);
				}
			Q.push((sss){s,id});	
		}
		
	}
	for(int i=1;i<=n;i++)
		cout<<vis[i];
	return 0;
}
