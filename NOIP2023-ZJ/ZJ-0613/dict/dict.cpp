#include <bits/stdc++.h>
using namespace std;
int n,m;
int st[3001][27]={};
int read()
{
	char s=getchar();
	int ans=0;
	while('0'<=s && '9'>=s)
	{
		ans=ans*10+(s-'0');
		s=getchar();
	}
	return ans;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	char t;
	n=read();
	m=read();
	if(n==1){cout<<1;return 0;}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t=getchar();
			st[i][t-'a'+1]+=1;
		}
		t=getchar();
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(j==i) continue;
			int flag=0,l=1,r=26;
			while(st[i][l]==0 && l<=26) l++;
			while(st[j][r]==0 && r>=1) r--;
			if(l<r) {flag=1;}
			else if(l>r){flag=0;break;}
			else if(l==r)
			{
				if(st[i][l]<=st[j][r]) {flag=0;break;}
				if(st[i][l]>st[j][r]) {flag=1;}
			}
			if(flag==0) break;
			if(flag==1) cnt++;
		}
		if(cnt==n-1) cout<<1;
		else cout<<0;
	}
}