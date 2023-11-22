#include<bits/stdc++.h>
using namespace std;
int op,t,n,m,vis[100010],cnt,ba[100010];
struct p{
	int q=1;
	int v;
	int col;
	int tst;
}a[100100],b[100100];
void f(int x,int col){
	if(x>n) return;
	if(vis[x]==1) a[x].col=col;
	if(vis[x]>1){
		ba[col]=1;
		return ;
	}
	vis[x]++;
	b[x].col=col;
	if(a[x].v==x) return;
	else{
		f(a[x].v,col);
		a[x].v=a[a[x].v].v;
		b[x].col=b[a[x].v].col;
		if(a[x].q==-1){
			a[x].q=-a[a[x].v].q;
		} 
		else{
			a[x].q=a[a[x].v].q;
		}
		return;
	}
}
/*
1 1 

10 10
- 9 8
- 8 6
- 6 5
- 5 4
- 4 3
+ 3 9
- 1 2
+ 2 7
+ 7 10
- 10 1
*/
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>op>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i].v=i;
			a[i].q=1;
			ba[i]=0;
			vis[i]=0;
			a[i].col=0;
			a[i].tst=0;
		}
		a[100001].v=100001;
		a[100002].v=100002;
		a[100003].v=100003;
		for(int p=1;p<=m;p++){
			char v;
			int x,y;
			cin>>v>>x;
			if(v=='T') a[x].v=100001;
			else if(v=='F') a[x].v=100002;
			else if(v=='U') a[x].v=100003;
			else{
				cin>>y;
				if(v=='+'){
					a[x].v=a[y].v;
					a[x].q=a[y].q;
				}
				else {
					a[x].v=a[y].v;
					a[x].q=-a[y].q;
				}
			}
		}
		if(op==4||op==3){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i].v==100003) sum++;
			}
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].v==i&&a[i].q==-1) a[i].v=100003;
			if(a[i].v>n){
				if(a[i].q==-1){
					a[i].q=1;
					if(a[i].v==100001) a[i].v=100002;
					if(a[i].v==100002) a[i].v=100001;
				}
			}
		}
		
		//cout<<"==========="<<endl;
		for(int i=1;i<=n;i++) {	
			b[i].q=a[i].q;
			b[i].v=a[i].v;
		}
		for(int i=1;i<=n;i++){
			if(a[i].v!=i&&a[i].v<=n&&!vis[i]) f(i,++cnt);
		}
		for(int i=1;i<=n;i++){
			if(a[i].v>n){
				if(a[i].q==-1){
					a[i].q=1;
					if(a[i].v==100001) a[i].v=100002;
					if(a[i].v==100002) a[i].v=100001;
				}
			}
		}
		//for(int i=1;i<=cnt;i++){
	//		if(!vis2[i]) 
		//}
		for(int i=1;i<=cnt;i++){
			int sum=0,ff=0,fff=0;
			for(int j=1;j<=n;j++){
				if(a[j].col==i){
					if(a[j].q==-1) sum++;
				}
			}
			if(sum%2||ff){
				for(int j=1;j<=n;j++){
					if(b[j].col==i){
						ans++;
						a[i].tst=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!a[i].tst){
				if(a[i].v==100003) ans++;
			}
		}
		//cout<<"______"<<endl;
		//for(int i=1;i<=n;i++) cout<<" "<<a[i].q<<" "<<a[i].v<<" "<<a[i].col<<endl;
		//for(int i=1;i<=n;i++) cout<<" "<<b[i].q<<" "<<b[i].v<<" "<<b[i].col<<endl;
		//for(int i=1;i<=cnt;i++) cout<<ba[i]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}//meow~ meow~ meow~