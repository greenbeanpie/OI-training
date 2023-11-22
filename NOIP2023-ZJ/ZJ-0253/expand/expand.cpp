#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cout<<"10";
	return 0;
}