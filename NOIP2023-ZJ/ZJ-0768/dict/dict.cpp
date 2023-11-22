#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
int n,m;
char ss[N][N];
int s[N][N],smin[N][N],smax[N][N],to,prema,premi,k1,k2,fla1,fla2;

bool check(int x , int y)
{
//	cout << x << y << endl;
	for (int i=0;i<m;i++)
	{
		if (smin[x][i]<smax[y][i]) return 0;
	}
	return 1;
}

int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++) 	cin >> ss[i];
	for (int i=1;i<=n;i++) 
	for (int j=0;j<m;j++) s[i][j]=int (ss[i][j])-int ('a')+1,smin[i][j]=s[i][j],smax[i][j]=s[i][j];
	for (int i=1;i<=n;i++)
	{
		prema=s[i][0],premi=s[i][0];fla1=1;fla2=1;k1=k2=0;
//		mi1=99999;mi2=99999;
//		ma1=-1;ma2=-1;
		for (int j=1;j<m;j++)
		{
			if (s[i][j]<prema&&fla1) k1=j,fla1=0;
			prema=max(prema,s[i][j]);
			if (s[i][j]>premi&&fla2) k2=j,fla2=0;
			premi=min(premi,s[i][j]);
			
//			if (s[i][j]<mi1)
//			{
//				mi2=mi1;
//				mi1=int (s[i][j]);
//			}
//			else if (int s[i][j]<mi2) mi2=int (s[i][j]);
//			if (int (int (s[i][j])>ma1))
//			{
//				ma2=ma1;
//				ma1=int (s[i][j]);
//			}
//			else if (int (s[i][j])>mi2) mi2=int (s[i][j]);
		}
//		cout << k2 << endl;
//		cout << k1 << k2 << endl;
		int t,tt;
		to=99999;
		for (int k=k1;k<m;k++)
		if (s[i][k]<=to){to=s[i][k];t=k;}
//		cout << t << " ";
		for (int k=0;k<k1;k++)
		if (s[i][k]>to) {tt=k;break;}
		int op;
//		cout << tt << endl;
		op=smin[i][t],smin[i][t]=smin[i][tt],smin[i][tt]=op;
		
		to=-1;
		for (int k=k2;k<m;k++)
		if (s[i][k]>=to){to=s[i][k];t=k;}
//		cout << t << " ";
		for (int k=0;k<k2;k++)
		if (s[i][k]<to) {tt=k;break;}
//		cout << tt << endl;
		op=smax[i][t],smax[i][t]=smax[i][tt],smax[i][tt]=op;
	}
	
//	for (int i=1;i<=n;i++) 
//	for (int j=0;j<m;j++) cout << smax[i][j] << " ";
	int fla;
	for (int i=1;i<=n;i++)
	{
		fla=1;
		for (int j=1;j<=n;j++)
		if (i!=j&&check(i,j)) {fla=0;break;}
		if (fla) cout << 1;
		else cout << 0;
	}
	return 0;
}
//Good Bye.

