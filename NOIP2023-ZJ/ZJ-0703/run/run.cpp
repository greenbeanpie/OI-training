#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read()
{
	int x,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){if(c=="-"){f=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0',c=getchar();}
	return x;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>n>>m>>k>>d;
	cout<<m-n*d;
	return 0;
}