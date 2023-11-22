#include <bits/stdc++.h>
#define re register
using namespace std;
string s[3010],smax[3010],smin[3010];
int n,m,pos,F;
bool f[3010][3010];
string T;
bool check(string t1,string t2)
{
	for(re int i=0;i<m;i++)
	if (t1[i]>t2[i]) return false;
	else if (t1[i]<t2[i]) return true;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for (re int i=1;i<=n;i++) cin>>s[i],smax[i]=s[i],smin[i]=s[i];
	if (n==1) cout<<1<<endl;
	else{
		for (re int i=1;i<=n;i++)
		{
			for (re int j=0;j<s[i].length();j++)
			{
				int Max=s[i][j];pos=j;
				for (re int k=j+1;k<s[i].length();k++)
				{
					if (int(s[i][k])==Max) pos=k;
					if (int(s[i][k])>Max) Max=int(s[i][k]),pos=k;
				}
				if (Max!=s[i][j]) 
				{
					smax[i][pos]=s[i][j];
					smax[i][j]=char(Max);
					break;
				}
			}
		}//找最大字符串的可能的串 
		
		for (re int i=1;i<=n;i++)
		{
			for (re int j=0;j<s[i].length();j++)
			{
				int Min=int(s[i][j]);pos=j;
				for (re int k=j+1;k<s[i].length();k++)
				{
					if (int(s[i][k])==Min) pos=k;
					if (int(s[i][k])<Min) Min=int(s[i][k]),pos=k;
				}
				if (Min!=s[i][j]) 
				{
					smin[i][pos]=s[i][j];
					smin[i][j]=char(Min);
					break;
				}
			}
		}//min
	}
	for (re int i=1;i<=n;i++)
		for (re int j=1;j<=n;j++)
		if (j!=i) if (check(smin[i],smax[j])==true) f[i][j]=1;//i最小，j最大 
	
	for (re int i=1;i<=n;i++)
	{
		F=1;
		for (re int j=1;j<=n;j++)
			if (j!=i) if (f[i][j]==0) {F=0;break;}
		T+=char(F+48);
	}
	
//	cout<<check("defrsja","asdasda")<<endl;
	cout<<T<<endl;
	
//	for (re int i=1;i<=n;i++) cout<<smax[i]<<" "<<smin[i]<<endl;

//	for (re int i=1;i<=n;i++,cout<<endl)
//		for (re int j=1;j<=n;j++) cout<<f[i][j]<<" ";
	return 0;
}
