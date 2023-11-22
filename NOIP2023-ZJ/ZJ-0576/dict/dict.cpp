#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[5000][5000],s[5000];
string ans;
bool f;
bool cmp(char x,char y) {
	return x<y;
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		getchar();
		scanf("%s",&a[i]);
	}
	ans="";
	for (int i=1; i<=n; i++) {
		for (int j=0; j<m; j++) {
			s[j]=a[i][j];
		}
		sort(s,s+m,cmp);
		f=1;
		for (int j=1; j<=n; j++) {
			if (j!=i) {
				for (int k=0; k<=m; k++) {
					if (s[k]>a[j][k]) {
						f=0;
						break;
					}
					if (s[k]<a[j][k]) {
						break;
					}
				}
				if (!f) {
					break;
				}
			}
		}
		if (f) {
			ans+='1';
		} else {
			ans+='0';
		}
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
