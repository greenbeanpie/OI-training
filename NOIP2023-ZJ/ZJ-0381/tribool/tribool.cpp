#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int num[N];
bool isu[N];
int c,t;
int main() {

	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4) {
		while(t--) {
			int n,m;
			cin>>n>>m;
			int sum=0;
			for(int i=1; i<=m; ++i) {
				char opt;
				int k;
				cin>>opt>>k;
				if(opt=='U') num[k]=1;
				else num[k]=0;
			}
			for(int i=1; i<=n; ++i) {
				if(num[i]) ++sum;
				num[i]=0;
			}
			cout<<sum<<"\n";
		}
		exit(0);
	} else if(c==5||c==6) {
		while(t--) {
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;++i){
				num[i]=i;
				isu[i]=0;
			}
			for(int i=1; i<=m; ++i) {
				char opt;
				int x,y;
				cin>>opt;
				if(opt=='+'){
					cin>>x>>y;
					num[x]=num[y];
				}
				else{
					cin>>x;
					isu[x]=1;
				}
			}
			int sum=0;
			for(int i=1;i<=n;++i){
				if(isu[num[i]]) ++sum;
			}
			cout<<sum<<"\n";
		}
		exit(0);
	}

	return 0;
}
