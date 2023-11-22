#include<bits/stdc++.h>
using namespace std;
int n,m,Ans,cnt;
struct Node
{
	char ch;
	int p,q,x;
}b[100050];
void f(int a[],int t)
{
	if(t>n+1) return;
	if(a[t]>2) return;
	int d[50];
	for(int i=1;i<=n;i++) d[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		if(b[i].ch=='+')
			d[b[i].p]=d[b[i].q];
		else
			if(b[i].ch=='-')
			{
				if(d[b[i].q]==2) d[b[i].p]=d[b[i].q];
				else d[b[i].p]=1-d[b[i].q];
			}
			else
			{
				int xx;
				if(b[i].ch=='T') xx=1;
				if(b[i].ch=='F') xx=0;
				if(b[i].ch=='U') xx=2;
				d[b[i].x]=xx;
			}
	}
	int sum=0,pp=1;
	
	for(int i=1;i<=n;i++)
	{
		if(d[i]!=a[i])
		{ 	
			pp=0;
			break;
		}
		if(d[i]==2) sum++;
	}
	if(sum<Ans&&pp) 
	{
		Ans=sum;
	}
	f(a,t+1);
	a[t]++; f(a,t+1); a[t]--;
	a[t]+=2; f(a,t+1); a[t]-=2;
	return;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int a[100050];
	int c,t; cin>>c>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cnt=0;
		cin>>n>>m;
		Ans=n;
		for(int i=1;i<=m;i++)
		{
			cin>>b[i].ch;
			if(b[i].ch=='+'||b[i].ch=='-')
				cin>>b[i].p>>b[i].q;
			else
				cin>>b[i].x;
		}
		f(a,1);
		cout<<Ans<<'\n';
	}
	fclose(stdin); fclose(stdout);
	return 0;
}