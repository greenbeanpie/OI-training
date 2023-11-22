#include<bits/stdc++.h>
char s[3050][3050],sm[3050];
int n,m;
using namespace std;
int Min(char a[],char b[])
{
	for(int i=0;i<min(strlen(a),strlen(b));i++)
	{
		if(a[i]>b[i])
			return 0;
		if(a[i]<b[i])
			return 1;
	}
	return 2;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	sm[0]='z'+1;
	gets(s[0]);
	for(int i=1;i<=n;i++)
	{
		gets(s[i]);
		if(Min(s[i],sm)==1)
		{
			for(int j=0;j<m;j++)
				sm[j]=s[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(Min(s[i],sm)==2){cout<<1; continue;}
		else
		{
			sort(s[i],s[i]+m);
			if(Min(s[i],sm)==1) cout<<1;
			else cout<<0;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}