#include<bits/stdc++.h>
using namespace std;
string s[3005],s1;
int n,m,f[3005][35],now,r1,sum;
bool cmp (string x,string y) {return x<y;}
int main () {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) cin>>s[i];
	for (int i=1;i<=n;i++) {
		for (int j=0;j<s[i].length();j++) f[i][int(s[i][j])-96]++;
	}
	now=1;
	for (int i=2;i<=n;i++) {
		for (int j=26;j>=1;j--) {
			if (f[now][j]>f[i][j]) {
				now=i;
				break;
			}
			if (f[now][j]<f[i][j]) break;
		}
	}
	for (int i=26;i>=1;i--) {
		if (f[now][i]!=0) {
			r1=i;
			break;
		}
	}
	for (int i=1;i<=n;i++) {
		sum=0;
		for (int j=1;j<r1;j++) {
			if (f[i][j]!=0) {
				sum=1;
				break;
			}
		}
		if (sum==1||f[i][r1]==m) printf("1");
		else printf("0");
	}
	return 0;
}
