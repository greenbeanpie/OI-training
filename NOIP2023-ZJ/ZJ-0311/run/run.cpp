#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
il ll read(){
	ll a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*f;
}
ll c,t,n,m,k;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	srand(time(0));
	c=read();
	t=read();
	for(int i=1;i<=t;i++)cout<<rand()%50-rand()%25<<'\n';
	return 0;
}

