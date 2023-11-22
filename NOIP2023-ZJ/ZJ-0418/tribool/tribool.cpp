#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int T=1;
const int F=-1;
const int U=0;
const int NOT_INITIALIZED=-2;
int c,t;
int n,m;
char op[maxn];
int val[maxn][3];
int original_value[maxn]={};
int var[maxn]={};
int track[maxn]={};
vector <int> retrack[maxn]; // 反向追溯 
bool vis[maxn]={};
bool check(){
	for(int i=1;i<=n;i++){
		var[i]=original_value[i];
	}
	for(int i=1;i<=m;i++){
		if(op[i]=='T'){
			var[val[i][1]]=T;
		}else if(op[i]=='F'){
			var[val[i][1]]=F;
		}else if(op[i]=='U'){
			var[val[i][1]]=U;
		}else if(op[i]=='+'){
			var[val[i][1]]=var[val[i][2]];
		}else if(op[i]=='-'){
			var[val[i][1]]=-var[val[i][2]];
		}
	}
	for(int i=1;i<=n;i++){
		if(var[i]!=original_value[i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("tribool.in","r",stdin); // !!!!!!!!!!!!!!!!!!!!!!
	freopen("tribool.out","w",stdout);
	cin>>c>>t; // 测试点编号&数据组数
	while(t--){
		cin>>n>>m; // 变量个数&语句条数
		for(int i=1;i<=m;i++){
			cin>>op[i];
			if(op[i]=='+'||op[i]=='-'){
				cin>>val[i][1]>>val[i][2];
			}else{
				cin>>val[i][1];
			}
		}
		if(c==1||c==2){
			int ans=INT_MAX;
			for(int i=1;i<=n;i++){
				original_value[i]=-1;
			}
			while(1){
				original_value[1]++;
				int ind=1;
				while(original_value[ind]>1){
					original_value[ind]=-1;
					original_value[++ind]+=1; 
				}
				if(ind>n){
					break;
				}
				if(check()){
					int cnt=0;
					for(int i=1;i<=n;i++){
						if(original_value[i]==U){
							cnt++;
						}
					}
					ans=min(ans,cnt);
				}
			}
			cout<<ans<<endl;
		}else if(c==3||c==4){
			for(int i=1;i<=n;i++){
				original_value[i]=NOT_INITIALIZED;
			}
			for(int i=1;i<=m;i++){
				if(op[i]=='T'){
					original_value[i]=T;
				}else if(op[i]=='F'){
					original_value[i]=F;
				}else if(op[i]=='U'){
					original_value[i]=U;
				}
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(original_value[i]==U){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}else if(c==5||c==6){
			for(int i=1;i<=n;i++){
				track[i]=i;
			} 
			for(int i=1;i<=m;i++){
				if(op[i]=='U'){
					track[val[i][1]]=-1;
				}else if(op[i]=='+'){
					track[val[i][1]]=track[val[i][2]];
				}
			}
			for(int i=1;i<=n;i++){
				if(track[i]!=-1){
					retrack[track[i]].push_back(i);
				}
			}
			int cnt=0;
			set <int> myset;
			queue <int> q;
			for(int i=1;i<=n;i++){
				if(track[i]==-1){
					q.push(i);
					vis[i]=1;
					cnt++;
				}
			}
			while(!q.empty()){
				int fnt=q.front();
				myset.insert(fnt);
				q.pop();
				for(auto vi:retrack[fnt]){
					myset.insert(vi);
					if(!vis[vi]){
						vis[vi]=1;
						q.push(vi);
					}
				}
			}
			cout<<myset.size()<<endl;
		}
	} 
	return 0;
} 
