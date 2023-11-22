#include<bits/stdc++.h>
using namespace std;
int n,m;
string ans;
map<int,string> ma;
string solve2(string x) {
	int maxn=0;
	char a='a'-1;
	for(int i=0; i<m; i++) {
		if(x[i]>a) a=x[i],maxn=i;
	}
	swap(x[maxn],x[0]);
	return x;
}
string solve1(int x) {
	string f=ma[x];
	int minn=0;
	char b='z'+1;
	for(int i=0; i<m; i++) {
		if(f[i]<b) b=f[i],minn=i;
	}
	swap(f[0],f[minn]);
	return f;
}
bool cmp2(string x,string y) {
	for(int i=0; i<m; i++) {
		if(x[i]==y[i]) continue;
		if(x[i]!=y[i]) {
			if(x[i]<y[i]) return 1;
			else return 0;
		}
	}
}
bool cmp1(string x,string y) {

	for(int i=0; i<m; i++) {
		if(x[i]==y[i]) continue;
		if(x[i]!=y[i]) {
			if(x[i]<y[i]) return 1;
			else {
				y=solve2(y);
				if(cmp2(x,y)) return 1;
				else return 0;
			}
		}
	}
}
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);

	cin>>n>>m;
	if(n==1) {
		cout<<1;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>ma[i];
	}
	bool k=1;
	for(int i=1; i<=n; i++) {
		k=1;
		string f=solve1(i);
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			if(!cmp1(f,ma[j])) k=0;
		}
		if(k) ans+='1';
		else ans+='0';
	}
	cout<<ans;
	return 0;
}
