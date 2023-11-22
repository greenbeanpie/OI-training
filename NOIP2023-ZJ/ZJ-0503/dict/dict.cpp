#include<bits/stdc++.h>
using namespace std;
int a,b,c[26];
string mxi,mi[4000],s;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		string mx="";
		cin>>s;
		for(int n=0;n<b;n++)c[int(s[n]-'a')]++;
		for(int n=25;n>=0;n--)
		{
			int k=c[n];
			while(k>0)
			{
				mx=mx+char(97+n);
				k--;
			}
		}
		if(mxi=="")mxi=mx;
		else mxi=min(mxi,mx);
		for(int n=0;n<=25;n++)
		{
			while(c[n]>0)
			{
				mi[i]=mi[i]+char(97+n);
				c[n]--;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(mi[i]<=mxi)printf("%d",1);
		else printf("%d",0);
	}
	return 0;
}