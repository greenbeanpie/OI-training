#include<bits/stdc++.h>
using namespace std;
const int N = 3010;
inline int read()
{
	int x = 0,f = 1;char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9'){x = x*10+ch-48;ch = getchar();}
	return x*f;
}
string s[N],ma[N],mi[N];
int ton[30];int n,m;
void sol(string res,int id)
{
	memset(ton,0,sizeof(ton));
	res = " "+res;
	for(int i = 1;i<=m;i++)
	{
		ton[res[i]-'a'+1]++;
	}
	string res1 = "",res2 = "";
	for(int i = 1;i<=26;i++)
	{
		for(int j = 1;j<=ton[i];j++)
		{
			res1+=char('a'+i-1);
		}
	}
	for(int i = 26;i>=1;i--)
	{
		for(int j = 1;j<=ton[i];j++)
		{
			res2+=char('a'+i-1);
		}
	}
	ma[id] = res2,mi[id] = res1;
	return;
}
signed main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>s[i];
	for(int i = 1;i<=n;i++)sol(s[i],i);
//	for(int i = 1;i<=n;i++)
//	{
//		cout<<ma[i]<<endl;
//		cout<<mi[i]<<endl;
//		cout<<endl;
//	}
	string Min = "",ciMin = "";
	int Mid = 0,ciMid = 0;
	for(int i = 1;i<=n;i++)
	{
		if(Min=="")
		{
			Min = ma[i];Mid = i;
		}
		else if(ma[i]<Min)
		{
			ciMin = Min;Min = ma[i];
			ciMid = Mid;Mid = i;
		}
		else if(ma[i]<ciMin)
		{
			ciMin = ma[i];ciMid = i;
		}
	}
	string ans = "";
	for(int i = 1;i<=n;i++)
	{
		if(i==Mid)
		{
			if(mi[i]<ciMin)ans+='1';
			else ans+='0';
		}
		else
		{
			if(mi[i]<Min)ans+='1';
			else ans+='0';
		}
	}
	cout<<ans;
	return 0;
}
