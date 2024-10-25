#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],ans;
vector<int>v[100005];
signed main(){
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(j>i&&a[j]>a[i]&&b[j]>b[i]){
//				vv[j][i]=true;
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		v[i].push_back(i);
		for(int j=1;j<i;j++){
			for(auto y:v[j])if(a[y]>a[i]||b[y]>b[i])goto A;
			v[j].push_back(i);
			A:;
		}
	}int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,(int)v[i].size());
	}
	cout<<ans;
}
