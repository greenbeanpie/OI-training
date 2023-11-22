#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=3005;
inline void fre()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
}
int n,m;
int pos1,pos2,p1[N][N],p2[N][N];
string st[N],st1[N],st2[N];
signed main()
{
	fre();
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
		pos1=pos2=-1;
		for(int j=m;j>=1;j--)
		{
			if(pos1==-1||st[i][j-1]>st[i][pos1-1]) pos1=j;
			p1[i][j]=pos1;
			if(pos2==-1||st[i][j-1]<st[i][pos2-1]) pos2=j;
			p2[i][j]=pos2;
		}
		st1[i]=st2[i]=st[i];
		for(int j=1;j<=m;j++)
		{
			if(st[i][j-1]<st[i][p1[i][j]-1])
			{
				swap(st1[i][j-1],st1[i][p1[i][j]-1]);
				break;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(st[i][j-1]>st[i][p2[i][j]-1])
			{
				swap(st2[i][j-1],st2[i][p2[i][j]-1]);
				break;
			}
		}
//		cout<<st[i]<<' '<<st1[i]<<' '<<st2[i]<<'\n';
	}
	for(int i=1;i<=n;i++)
	{
		bool flag=1;
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			if(st2[i]>=st1[j])
			{
				flag=0;
				continue;
			}
		}
		cout<<flag;
	}
	return 0;
}
