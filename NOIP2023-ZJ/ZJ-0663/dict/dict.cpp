#include<bits/stdc++.h>
#define forr(i,l,r) for(int i=l;i<=r;i++)
#define ffor(i,l,r) for(int i=l;i>=r;i--)
using namespace std;
const int N=3010;
string s[N],ma[N],mi[N];
int b[30],a[30];
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	n--;
	m--;
	forr(i,0,n)
	{
		cin>>s[i];
//		s[i]=' '+s[i];
	}
	forr(i,0,n)
	{
//		if(m==1)
//		{
//			mi=s[i];
//			ma=s[i];
//			continue;
//		}
		int top=1,dep=26;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		forr(j,0,m)
		{
			a[s[i][j]-'a'+1]++;
			b[s[i][j]-'a'+1]++;
			top=top>s[i][j]-'a'+1?top:s[i][j]-'a'+1;
			dep=dep<s[i][j]-'a'+1?dep:s[i][j]-'a'+1;
		}
		int p=0,flagg=1;
		while(s[i][p]-'a'+1==top)
		{
			a[top]--;
			while(a[top]==0&&top>=1)
			{
				top-=1;
			}
			if(top==0)
			{
				ma[i]=s[i];
				flagg=0;
				break;
			}
			p++;
		}
		if(flagg)
		{
		char la='a';int cnt1=0;
		forr(j,p,m)
		{
			if(s[i][j]>=la)
			{
				la=s[i][j];
				cnt1=j;
			}
		}
		swap(s[i][p],s[i][cnt1]);
		ma[i]=s[i];
		swap(s[i][p],s[i][cnt1]);
		}
		p=0;
		flagg=1;
		while(s[i][p]-'a'+1==dep)
		{
			b[dep]--;
			while(b[dep]==0&&dep<=26)
			{
				dep++;
			}
			if(dep==27)
			{
				mi[i]=s[i];
				flagg=0;
				break;
			}
			p++;
		}
		if(flagg)
		{
		char la='z';int cnt1=0;
		forr(j,p,m)
		{
			if(s[i][j]<=la)
			{
				la=s[i][j];
				cnt1=j;
			}
		}
		swap(s[i][p],s[i][cnt1]);
		mi[i]=s[i];
		swap(s[i][p],s[i][cnt1]);
		}
	}
	bool ji=0;
	forr(i,0,n)
	{
		ji=0;
		forr(j,0,n)
		{
			if(j==i)
			{
				continue;
			}
			if(mi[i]>=ma[j])
			{
				cout<<0;
				ji=1;
				break;
			}
		}	
		if(!ji)
		{
			cout<<1;
		}
	}
	cout<<'\n';
	return 0;
}
