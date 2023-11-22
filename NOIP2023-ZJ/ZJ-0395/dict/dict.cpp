#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=3e3+10;
int max_(int x,int y) {
	return x>y?x:y;
}
int min_(int x,int y) {
	return x<y?x:y;
}
int n,m;
int a[N][2];
signed main() {

	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);

	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		string s;
		cin>>s;
		int maxx=-inf,minn=inf,ls=s.size();
		for(int j=0; j<ls; j++) {
			int k=s[j]-'a';
			maxx=max_(maxx,k);
			minn=min_(minn,k);
		}
		a[i][0]=maxx;
		a[i][1]=minn;
	}

	for(int i=1; i<=n; i++) {
		bool flag=1;
		for(int j=1; j<=n; j++)
			if(i!=j)
				if(a[i][1]>=a[j][0]) {
					flag=0;
					break;
				}

		if(flag)	cout<<"1";
		else		cout<<"0";

	}


	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn

*/
