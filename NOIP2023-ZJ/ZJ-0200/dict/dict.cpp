#include<bits/stdc++.h>
using namespace std;
int n,m;
char w[3005][3005];
int a[3005][30],u[30],v[30];

bool chk(int x,int y)
{
//	cerr<<w[x]<<" "<<w[y]<<":";
//	bool fl=false;
//	if(w[y][0]=='z')
//		fl=true;
	for(int i=0;i<26;i++)
		u[i]=a[x][i],v[i]=a[y][i];
	int l=0,r=25;
	while((l<26)&&(u[l]==0))
		l++;
	while((r>=0)&&(v[r]==0))
		r--;
//	if(fl)
//		cerr<<l<<" "<<r<<endl;
	while((l<26)&&(r>=0))
	{
		if(l<r)
		{
//			cerr<<1<<endl;
			return true;
		}
		if(l>r)
		{
//			cerr<<0<<endl;
			return false;
		}
		int t=min(u[l],v[r]);
		u[l]-=t;
		v[r]-=t;
		while((l<26)&&(u[l]==0))
			l++;
		while((r>=0)&&(v[r]==0))
			r--;
//		if(fl)
//			cerr<<l<<" "<<r<<endl;
	}
//	cerr<<0<<endl;
	return false;
}

void f(int x)
{
	for(int i=1;i<=n;i++)
		if(i!=x)
			if(!chk(x,i))
			{
				cout<<0;
//				cerr<<endl;
				return;
			}
	cout<<1;
//	cerr<<endl;
	return;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		for(int j=1;j<=m;j++)
			a[i][w[i][j-1]-'a']++;
	}
	for(int i=1;i<=n;i++)
		f(i);
	return 0;
}