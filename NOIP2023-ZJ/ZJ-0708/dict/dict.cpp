#include<bits/stdc++.h>
using namespace std;
	string s[3005],sxtmp[3005],jxtmp[3005];
	int n,m;
	int tmp[3005];
bool cmp1(const char &a,const char &b)//½µĞòÅÅĞò±È½Ï 
{
	return (a>b);
}
bool cmp2(const char &a,const char &b)//ÉıĞòÅÅĞò±È½Ï 
{
	return (a<b);
}
void sort1(string &x)//½µĞòÅÅĞò 
{
	int len=x.length();
	for(int i=0;i<=x.length()-1;i++) tmp[i]=x[i]-'a';
	sort(tmp,tmp+len,cmp1);
	string ans1="";
	for(int i=0;i<=x.length()-1;i++) ans1+=char(tmp[i]+'a');
	x=ans1;
	memset(tmp,0,sizeof(tmp));
}
void sort2(string &x)//ÉıĞòÅÅĞò 
{
	int len=x.length();
	for(int i=0;i<=x.length()-1;i++) tmp[i]=x[i]-'a';
	sort(tmp,tmp+len,cmp2);
	string ans1="";
	for(int i=0;i<=x.length()-1;i++) ans1+=char(tmp[i]+'a');
	x=ans1;
	memset(tmp,0,sizeof(tmp));
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1) cout<<1;
	else
	{
		for(int i=1;i<=n;i++) cin>>s[i];
		for(int i=1;i<=n;i++)
		{
			sxtmp[i]=s[i];
			jxtmp[i]=s[i];
		}
		for(int i=1;i<=n;i++)
		{
			sort1(jxtmp[i]);
			sort2(sxtmp[i]);
		}
		for(int i=1;i<=n;i++)
		{
			bool flag=true;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				else if(jxtmp[j]<sxtmp[i])
				{
					flag=false;
					break;
				}
			} 
			if(flag) cout<<1;
			else if(!flag) cout<<0;
		}
	}
	return 0;
}
