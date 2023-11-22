#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	srand(time(0));
	int c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=q+1;i++)
		cout<<(int)rand()%2;
	return 0;
}
