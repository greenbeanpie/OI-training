#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
	return x*f;
}
void write(int x){
	if (x<0) x=-x,putchar('-');
	if (x<10) putchar(x+48);
	if (x==0) return;
	write(x/10);
}
signed main(){
//	freopen("run.in","r",stdin);
//	freopen("run.out","w",stdout);

	return 0;
}

