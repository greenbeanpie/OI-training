#include<bits/stdc++.h>
using namespace std;
#define ll int
const int N=3e3+10;
string s[N];
int a[N][500];
ll min1,max1;
ll n,m,k,ans;
ll read() {
	ll uu=0;
	char c;
	c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c)) {
		uu=(uu<<3)+(uu<<1)+(c^48);
		c=getchar();
	}
	return uu;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	for(int i=1; i<=n; i++)
		cin>>s[i];
	for(int i=1; i<=n; i++)
		for(int j=0; j<m; j++)
			a[i][s[i][j]]++;


	for(int i=1; i<=n; i++) {
		bool flag=1,tag=1;
		for(int j=1; j<=n; j++) {
       
			if(j==i) continue;
			for(int k1='a'; k1<='z'; k1++)
				if(a[i][k1]>0) {
					min1=k1;
					break;
				}
			for(int k2='z'; k2>='a'; k2--)

				if(a[j][k2]>0) {
					max1=k2;
					break;
				}
			if(max1<=min1) {
				printf("0");
				tag=0;
				break;
			}
		}
		if(tag) printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
