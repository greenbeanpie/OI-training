#include<bits/stdc++.h>
using namespace std;
char smin[3005][3005];
char smax[3005][3005];
bool ans[3005];
int n,m;
struct xy {
	int son[26];
};
bool cmp1(char a,char b) {
	return a>b;
}
xy tr[9000005];
int cnt;
void insert(char *s) {
	int i=0,pos=0;
	while(i<m) {
		int c=s[i]-'a';
		if(tr[pos].son[c]) {
			pos=tr[pos].son[c];
		} else {
			tr[pos].son[c]=++cnt;
			pos=cnt;
		}
		++i;
	}
}
bool check(char *s) {
	int i=0,pos=0;
	while(i<m) {
		int c=s[i]-'a';
		for(int k=0; k<c; ++k) {
			if(tr[pos].son[k]) {
//				cout<<"!";
				return false;
			}
		}
		if(tr[pos].son[c]) {
			pos=tr[pos].son[c];
		} else return true;
		++i;
	}
	return true;
}
int main() {

	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		scanf("%s",smin[i]);
		for(int j=0; j<m; ++j)smax[i][j]=smin[i][j];
		sort(smin[i],smin[i]+m);
		sort(smax[i],smax[i]+m,cmp1);
		insert(smax[i]);
	}
	for(int i=1; i<=n; ++i) {
		if(check(smin[i])) cout<<"1";
		else cout<<"0";
	}

	return 0;
}
