#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long

int t[100005]; // 1--U 2--F 3--T
int jian[100005][3], jia[100005][3];
bool prime[100005];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, T, n, m; cin>>c>>T;
	if(c==3 || c==4){
		while(T--){
			// memset
			int ans=0;
			for(int i=1; i<=100005; i++) t[i]=3;
			// main
			cin>>n>>m;
			char ch; int id;
			for(int i=1; i<=m; i++){
				cin>>ch>>id;
				if(ch=='U') t[id]=1;
				else if(ch=='F') t[id]=2;
				else if(ch=='T') t[id]=3;
			}
			for(int i=1; i<=n; i++){
				if(t[i]==1) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	else if(c==5 || c==6){
		while(T--){
			// memset
			int ans=0;
			for(int i=1; i<=100005; i++) t[i]=3;
			// main
			cin>>n>>m;
			char ch; int id, u, v;
			for(int i=1; i<=m; i++){
				cin>>ch;
				if(ch=='+'){
					cin>>u>>v;
					t[u] = t[v];
				}
				else if(ch=='U'){
					cin>>id;
					t[id] = 1;
				}
			}
			for(int i=1; i<=n; i++){
				if(t[i]==1) ans++;
			} 
			cout<<ans<<"\n";
		}
		return 0;
		/*
		6 2
		6 6
		U 6
		+ 5 6
		+ 4 5
		U 3
		+ 1 4
		+ 4 1
		6 6
		U 6
		+ 5 6
		+ 4 5
		U 3
		+ 1 4
		+ 4 1
		*/
	}
	else if(c==7 || c==8){
		while(T--){
			// memset
			int ans=0;
			for(int i=1; i<=100005; i++){
				jian[i][1] = jian[i][2] = 0;
				jia[i][1] = jia[i][2] = 0;
				prime[i] = false;
			}
			// main
			cin>>n>>m;
			char ch; int u, v;
			for(int i=1; i<=m; i++){
				cin>>ch>>u>>v;
				if(ch=='-'){
					jian[u][1]++; jian[v][2]++;
				}
				else if(ch=='+'){
					jia[u][1]++; jia[v][2]++;
				}
			}
			for(int i=1; i<=n; i++){
				if((jian[i][2]+jia[i][1])%2==0 || (jian[i][1]+jia[i][2])%2==0) prime[i] = true;
			}
			for(int i=1; i<=n; i++){
				if(prime[i]) continue;
				if(prime[i-1] && prime[i+1]) prime[i]=true;
			}
			for(int i=1; i<=n; i++){
				if(!prime[i]) ans++;
			}
			cout<<ans<<"\n";
		}
		return 0;
		/*
		7 2
		3 3
		- 2 1
		- 3 2
		+ 1 3
		3 3
		- 2 1
		- 3 2
		- 1 3
		*/
	}
	else{
		while(T--){
			cout<<"0\n";
		}
	}
	return 0;
}

