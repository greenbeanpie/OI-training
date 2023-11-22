#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	char ch=getchar();int s=0,w=1;
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
	return s*w;
}
void write(int x){
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

int main(){
	//freopen("expand.in","r",stdin);
	//freopen("expand.out","w",stdout);

	return 0;
}