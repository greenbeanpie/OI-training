#include<bits/stdc++.h>
using namespace std;
int n,m;
char w[3005][3005],wh[3][3005];
int s[30],whh;
int a[3005];
bool c(char a[3005],char b[3005])
{
	for(int i=0;i<m;i++)
	{
		if(a[i]>b[i])
		return 0;
		if(a[i]<b[i])
		return 1;
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		for(int j=0;j<m;j++)
		{
			s[w[i][j]-'a'+0]++;
		}
		int tmp=0;
		char wtmp[3005];
		for(int j=0;j<26;j++)
		{
			while(s[j]>0)
			{
				w[i][tmp]=char('a'+j);
				wtmp[m-1-tmp]=char('a'+j);
				tmp++;
				s[j]--;
			}
		}
//		cout<<w[i]<<endl;
		if(i==1)
		{
			swap(wh[1],wtmp);
			whh=i;
		}
		else if(i==2)
		{
			if(c(wh[1],wtmp))
			{
				swap(wh[2],wh[1]);
				swap(wh[1],wtmp);
				whh=i;
			}
			else
			{
				swap(wh[2],wtmp);
			}
		}
		else if(c(wtmp,wh[1]))
		{
			swap(wh[2],wh[1]);
			swap(wh[1],wtmp);
			whh=i;
		}
		else if(c(wtmp,wh[2]))
		{
			swap(wh[2],wtmp);
		}
	}
//	cout<<wh[1]<<endl;
//	cout<<wh[2]<<endl;
//	cout<<whh<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i==whh)
		{
			if(c(w[i],wh[2]))
			cout<<"1";
			else
			cout<<"0";
		}
		else
		{
			if(c(w[i],wh[1]))
			cout<<"1";
			else
			cout<<"0";
		}
	}
	cout<<endl;
	return 0;
}
