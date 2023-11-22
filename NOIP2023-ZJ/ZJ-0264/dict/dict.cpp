#include <bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,mi[N],ma[N];
char ch;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		while (!('a'<=ch&&ch<='z')) ch=getchar();
		mi[i]=25;ma[i]=0;
		for (int j=0;j<m;++j)
		mi[i]=min(mi[i],ch-'a'),
		ma[i]=max(ma[i],ch-'a'),
		ch=getchar();
	}
	for (int i=1;i<=n;++i){
		bool flag=1;
		for (int j=1;j<=n;++j)
		if (j!=i) if (mi[i]>=ma[j]){
			flag=0;
			break;
		}
		if (flag) putchar('1');
		else putchar('0');
	}
	return 0;
}
