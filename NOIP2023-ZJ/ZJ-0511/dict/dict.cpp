#include<bits/stdc++.h>
using namespace std;//WY AK IOI!!!
inline long long read()
{
	long long s=0,k=1;
	char r=getchar();
	while(!isdigit(r)) k=(r=='-')?-1:1,r=getchar();
	while(isdigit(r)) s=s*10+r-'0',r=getchar();
	return s*k;
}
#define d read()
#define ll long long
#define Maxn 10010
#define Size 3010
#define pb push_back
#define mp make_pair
#define fi first
#define se second
string s[Size],t[Size];
ll cnt[50];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ll n=d,m=d;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		for(int j=0;j<m;j++)
			cnt[s[i][j]-'a']++;
		t[i]="";
		for(int j=0;j<26;j++)
			while(cnt[j]) t[i]+=(char)('a'+j),cnt[j]--;
		s[i]=t[i];
		reverse(s[i].begin(),s[i].end());
	}
	ll id=1,las=2;
	if(s[las]<s[id]) swap(las,id);
	for(int i=2;i<=n;i++)
		if(s[i]<s[id])
			las=id,id=i;
		else if(s[i]<s[las])
			las=i;
	for(int i=1;i<=n;i++)
	{
		bool flag;
		if(i==id) flag=(t[i]<s[las]);
		else flag=(t[i]<s[id]);
		putchar('0'+(int)flag);
	}
}
