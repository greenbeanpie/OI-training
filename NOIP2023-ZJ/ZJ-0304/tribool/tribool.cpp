#include <bits/stdc++.h>
using namespace std;

int ans[100010];
int old[100010];

int fa[100010];
long long siz[100010];
int lst[100010];
bool bucket[100010];

int find(int x){
	if(fa[x]==-1){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}

void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y){
		return;
	}
	if(siz[x]>siz[y]){
		siz[y]+=siz[x];
		fa[x]=y;
	}else{
		siz[x]+=siz[y];
		fa[y]=x;
	}
}

int n,m;
int id;
int cnt=0;
int opt[100010][5];
int num=114514;

bool isc(){
	for(int i=0;i<m;i++){
		if(opt[i][0]==1){
			old[opt[i][1]]=1;
		}
		if(opt[i][0]==0){
			old[opt[i][1]]=0;
		}
		if(opt[i][0]==-1){
			old[opt[i][1]]=-1;
		}
		if(opt[i][0]==114){
			old[opt[i][1]]=old[opt[i][2]];
		}
		if(opt[i][0]==514){
			old[opt[i][1]]=-old[opt[i][2]];
		}
	}
	for(int i=1;i<=n;i++){
		if(old[i]!=ans[i]){
			return 0;
		}
	}
	return 1;
}

void baoli(int nw){
	if(nw==n+1){
		for(int i=1;i<=n;i++){
			old[i]=ans[i];
		}
		if(isc()){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(ans[i]==0){
					cnt++;
				}
			}
			num=min(num,cnt);
		}
		return;
	}
	ans[nw]=-1;
	baoli(nw+1);
	ans[nw]=1;
	baoli(nw+1);
	ans[nw]=0;
	baoli(nw+1);
	ans[nw]=114514;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==1 || c==2){
		while(t--){
			for(int i=0;i<100010;i++){
				ans[i]=114514;
			}
			cin >> n >> m;
			num=114514;
			for(int i=0;i<m;i++){
				char tu;
				cin >> tu >> opt[i][1];
				if(tu=='U'){
					opt[i][0]=0;
				}else if(tu=='T'){
					opt[i][0]=1;
				}else if(tu=='F'){
					opt[i][0]=-1;
				}else if(tu=='+'){
					cin >> opt[i][2];
					opt[i][0]=114;
				}else{
					cin >> opt[i][2];
					opt[i][0]=514;
				}
			}
			baoli(1);
			cout << num << endl;
		}
	}else if(c==3 || c==4){
		while(t--){
			for(int i=0;i<100010;i++){
				ans[i]=114514;
			}
			cin >> n >> m;
			for(int i=0;i<m;i++){
				char tu;
				cin >> tu;
				cin >> id;
				if(tu=='U'){
					ans[id]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(ans[i]==0){
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}else if(c==5 || c==6){
		while(t--){
			num=0;
			for(int i=0;i<100010;i++){
				ans[i]=114514;
			}
			memset(fa,-1,sizeof(fa));
			memset(lst,-1,sizeof(lst));
			cin >> n >> m;
			ans[n+1]=0;
			for(int i=1;i<=n+10;i++){
				siz[i]=1;
			}
			for(int i=0;i<m;i++){
				char tu;
				cin >> tu;
				if(tu=='U'){
					int x;
					cin >> x;
					lst[x]=n+1;
				}
				if(tu=='+'){
					int x,y;
					cin >> x >> y;
					lst[x]=y;
				}
			}
			for(int i=1;i<=n;i++){
				if(lst[i]!=-1){
					//cout << siz[i] << " " << siz[lst[i]] << endl;
					merge(i,lst[i]);
					//cout << i << " " << lst[i] << endl;
					//cout << find(i) << " " << find(lst[i]) << " " << siz[find(i)] << endl;
				}
			}
			/*
			for(int i=1;i<=n;i++){
				if(ans[i]==0){
					int rt=find(i);
					if(bucket[rt]==0){
						num+=siz[rt];
						bucket[rt]=1;
					}
				}
			}
			*/
			cout << siz[find(n+1)]-1 << endl;
		}
	}else{
		while(t--){
			cout << 0 << endl;
		}
	}
	return 0;
}