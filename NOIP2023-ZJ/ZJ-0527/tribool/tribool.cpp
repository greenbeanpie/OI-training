#include<bits/stdc++.h>
using namespace std;
void fireio(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
}
const int maxn = 1e5+10;
int groupc,t,n,m,x,y,used[maxn];
char opt;
void preee(){
	for(int i = 1;i<=n;i++)	used[i] = 0;
}
void f56(){
	while(t--){
		cin>>n>>m;
		for(int i = 1;i<=n;i++)used[i] = -1;
		for(int i = 1;i<=m;i++){
			cin>>opt;
			if(opt=='U'){
				cin>>x;
				used[x] = 1;
//				cout<<x<<endl;
			}else{
				cin>>x>>y;
				used[x] = used[y];
			}
		}
		int ans56 = 0;
		for(int i = 1;i<=n;i++){
			if(used[i]){
				ans56++;
			}
		}
		cout<<ans56<<endl;
	}
}
void f34(){
	while(t--){
		cin>>n>>m;
		for(int i = 1 ;i<=n;i++)used[i] = -3;
		for(int i = 1;i<=m;i++){
			cin>>opt;
			if(opt=='U'){
				cin>>x;
				used[x] = -1;
//				cout<<x<<endl;
			}else if(opt=='T'){
				cin>>x;
				used[x] = 1;
			}else if(opt=='F'){
				cin>>x;
				used[x] = 0;
			}
		}
		int ans34 = 0;
		for(int i = 1;i<=n;i++){
			if(used[i]==-1){
				ans34++;
			}
		}
		cout<<ans34<<endl;
	}
}
int main(){
	fireio();
//	testio(); 
//	ios::sync_with_stdio(0);
	cin>>groupc>>t;
	if(groupc==5 || groupc==6){
		f56();
	}
	if(groupc==3 || groupc==4){
		f34();
	}
	f56();
	return 0;
}
