#include<bits/stdc++.h>
using namespace std;
const int maxn=3100;
int n,m;
int w[maxn][2];
int main() {
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int Min,Max;
	for(int i=1; i<=n; ++i) {
		Min=1000;
		Max=1;
		for(int j=1; j<=m; ++j) {
			char x;
			cin>>x;
			int p=int(x);
			Min=min(Min,p);
			Max=max(Max,p);
		}
		w[i][1]=Min;
		w[i][2]=Max;
	}
//	for(int i=1; i<=n; ++i) {
//		cout<<w[i][1]<<" "<<w[i][2]<<endl;
//	}
	bool flag;
//	if(n==1) cout<<1;
//	else {
		for(int i=1; i<=n; ++i) {
			flag=true;
			int j=1;
			while(flag==true&&j<=n) {
				if(w[i][1]<w[j][2]) flag=true;
				else flag=false;
				if(i==j) flag=true;
				j+=1;
//			cout<<flag;
			}
			cout<<flag;

		}
//	}
	return 0;
}

