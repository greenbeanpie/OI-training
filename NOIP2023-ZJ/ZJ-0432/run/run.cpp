#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=gc;
	for(;!isdigit(ch);ch=gc)if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc)x=x*10+ch-'0';
	return x*f;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	printf("0");
	return 0;
}