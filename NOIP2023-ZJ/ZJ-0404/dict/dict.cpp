#include<bits/stdc++.h>//solved.
using namespace std;
typedef long long ll;
template<typename T>
void read(T &x)
{
	x=0;
	bool sgn=0;
	char c=getchar();
	while(!isdigit(c))
		sgn|=c=='-',c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x=sgn?-x:x;
}
int n,m;
const int maxn=3005;
char s[maxn][maxn];
string ss;
string rev(string s)
{
	string ss="";
	for(int i=s.size()-1;~i;--i)
		ss+=s[i];
	return ss;
}
//priority_queue<string,vector<string>,greater<string> >qb;
string big1,big2;
int id1,id2;
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	read(n),read(m);
	for(int i=0;i<m;++i)
		big1+='z',big2+='z';
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		sort(s[i],s[i]+m);
		ss=s[i];
		ss=rev(ss);
		//qb.emplace(rev(ss));
		if(ss<big1)
		{
			big2=big1,id2=id1;
			big1=ss,id1=i;
		}
		else if(ss<big2)
		{
			big2=ss,id2=i;
		}
		//printf("%s",s[i]);
	}
	for(int i=1;i<=n;++i)
	{
		ss=s[i];
		//if(ss<qb.top())
		if(i==id1)
		{
			if(ss<big2)
				putchar('1');
			else
				putchar('0');
			continue;
		}
		if(ss<big1)
			putchar('1');
		else
			putchar('0');
	}
	puts("");
	return 0;
}

