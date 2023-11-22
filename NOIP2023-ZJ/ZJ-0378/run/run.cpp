#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define il inline
#define ll long long
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	srand(time(0));
	ll ans=1ll*rand()*rand()*rand()%2145890;
	return 0;
}

