#include<bits/stdc++.h>
using namespace std;
int a[3008][3008];
int t[3008][30];
int ss[3008][10];
int n,m;
int flag;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j,k,sta,sto,ll,rr;
	cin>>n>>m;
	string st;
	for(i=1;i<=n;i++)
	{
		sta=27;
		sto=0;
		cin>>st;
		for(j=0;j<=m-1;j++)
		{
			a[i][j+1]=st[j]-'a'+1;
			sta=min(sta,a[i][j+1]);
			sto=max(sto,a[i][j+1]);
			t[i][a[i][j+1]]++;
		}
		ss[i][1]=sta;
		ss[i][2]=sto;
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	int dl,dr;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			ll=ss[i][1];
			rr=ss[j][2];
			flag=0;
			dl=0,dr=0;
			while(ll<=26&&rr>=1)
			{
				if(rr>ll)
				{
					flag=1;
					break;
				}
				else if(rr<ll)
				{
					flag=-1;
					break;
				}
				else if(rr==ll)
				{
					dl=min(t[i][ll],t[j][rr]);
					dr=dl;
					while(t[i][ll]-dl<=0&&ll<27)
					{
						dl=0;
						ll++;
					}
					while(t[j][rr]-dr<=0&&rr>0)
					{
						dr=0;
						rr--;
					}
					
					if(ll>rr)
					{
						flag=-1;
						break;
					}
				}
				if(flag!=0)
				break;
			}
			if(flag==-1) 
			{
				cout<<0;
				break;
			}
		}
		if(flag!=-1) cout<<1;
	}
	return 0;
}
