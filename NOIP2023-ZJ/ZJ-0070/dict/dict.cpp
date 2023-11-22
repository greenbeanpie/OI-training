#include<bits/stdc++.h>
using namespace std;
int n,m,c[128],cRmin=0;
string w[3005],r[3005],R[3005],Rmin="{";
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		memset(c,0,sizeof c);
		for(int j=0;j<m;j++)
			c[w[i][j]]++;
		for(char j='a';j<='z';j++)
			for(int k=0;k<c[j];k++)
				r[i]+=j;
		R[i]=r[i];
		reverse(R[i].begin(),R[i].end());
		if(R[i]<Rmin)
		{
			Rmin=R[i];
			cRmin=1;
		}
		else if(R[i]==Rmin)
			cRmin++;
	}
	for(int i=1;i<=n;i++)
		//if(r[i]<wmin or r[i]==wmin && cwmin==1)
		if(r[i]<Rmin or r[i]==Rmin && cRmin==1)
			putchar('1');
		else putchar('0');
	return 0;
}