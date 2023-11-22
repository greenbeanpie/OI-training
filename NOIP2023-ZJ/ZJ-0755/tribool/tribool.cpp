#include<bits/stdc++.h>
using namespace std;

const int N=150000;

int c,T;
int n,m,ans;

char op[100050];
int xi[100050],xj[100050];
int x[100050];

int yuan[100050];

bool pd(){
	for(int i=1;i<=n;i++)yuan[i]=x[i];
	for(int i=1;i<=m;i++){
		if (op[i]=='-') {
			if(x[xj[i]] == 1) yuan[xi[i]] = 0;
			else if(x[xj[i]] == 0) yuan[xi[i]] = 1;
			else if(x[xj[i]] == 2) yuan[xi[i]] = 2;
		}
		else if (op[i]=='+') {
			yuan[xi[i]] = yuan[xj[i]];
		}
		else if (op[i] == 'T') yuan[xi[i]] = 1;
		else if (op[i] == 'F') yuan[xi[i]] = 0;
		else if (op[i] == 'U') yuan[xi[i]] = 2;
	}
	for(int i=1;i<=n;i++){
		if(yuan[i]!=x[i])
			return false;
	}
	return true;
}

void dfs(int now,int cnt){
	if(ans==0) return ;
	if(cnt>ans) return ;
	
	if(now>n){
		if(pd()){
			ans=min(ans,cnt);
		}
		return ;
	}
	for(int j=0;j<=2;j++){
		x[now]=j;
		if(j==2) dfs(now+1, cnt+1);
		else dfs(now+1,cnt);
	}
	x[now]=-1;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	cin>>c>>T;
	
	if(c==3 || c==4){
		while(T--){
			cin>>n>>m;
			ans=0;

			for(int i=1;i<=m;i++){
				cin>>op[i];
				cin>>xi[i];
				if (op[i] == 'T') x[xi[i]] = 1;
				else if (op[i] == 'F') x[xi[i]] = 0;
				else if (op[i] == 'U') x[xi[i]] = 2;
			}
			for(int i=1;i<=n;i++){
				if(x[i]==2)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else if(c==5 || c==6){
		while(T--){
			cin>>n>>m;
			
			memset(x,1,sizeof(x));	
			ans=0;
			for(int i=1;i<=m;i++){
				cin>>op[i];
				if(op[i] == '+'){
					cin>>xi[i]>>xj[i]; 
					x[xi[i]] = x[xj[i]];
				}
				else {
					cin>>xi[i];
					x[xi[i]]=2;
				}
			}
			for(int i=1;i<=n;i++){
				if(x[i]==2)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else{
		while(T--){
			cin>>n>>m;
			
			memset(x,-1,sizeof(x));	
			ans=n;
			
			for(int i=1;i<=m;i++){
				cin>>op[i];
				if(op[i]=='-') cin>>xi[i]>>xj[i]; 
				else if(op[i] == '+') cin>>xi[i]>>xj[i]; 
				else cin>>xi[i];
			}
			dfs(1,0);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
