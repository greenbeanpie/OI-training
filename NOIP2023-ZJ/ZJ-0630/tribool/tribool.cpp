#include<bits/stdc++.h>
#define N 100005
using namespace std;
int C,T,n,m,i,j,fu[N],de[N],ex[N],ans=0,depth[N];
//fu1 ex2 ex:1T -1F 0U 
char v;
bool f[N],yes[N];
void dfs(int k,int dep){
	//cout<<k<<' '<<dep<<"  ";
	if(de[k]==2){
	    f[k]=true;
		yes[k]=true;
		return;
	}
	if(f[k]&&!yes[k]){
	//	cout<<k<<" "<<depth[k]<<' '<<dep<<endl;
		if(abs((depth[k]-dep)%2)==1){
			//cout<<k<<endl;
			de[k]=2;ex[k]=0;
		}
		yes[k]=true;
		return;
	}f[k]=true;
	depth[k]=dep;
	if(de[k]==1){
		int c=abs(fu[k]);
		if(c==k){
			if(fu[k]<0){
				de[k]=2;
				ex[k]=0;
			}
			yes[k]=true;
			return;
		}
		if(fu[k]<0){
			dep=depth[k]+1;
		}else{
			dep=depth[k];
		}
		dfs(c,dep);
		if(de[c]==2){
			de[k]=2;
			ex[k]=ex[c]*(fu[k]>0? 1:-1);
		}
		else{
			fu[k]=fu[c]*(fu[k]>0? 1:-1);
		}yes[k]=true;return;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>C>>T;
	while(T--){
		//cout<<endl;
		memset(f,false,sizeof(f));
		memset(yes,false,sizeof(yes));
		memset(depth,0,sizeof(depth));
		cin>>n>>m;ans=0;
		for(int k=1;k<=n;k++){
			de[k]=1;
			fu[k]=k;ex[k]=-2;
		}
		for(int k=1;k<=m;k++){
			cin>>v;
			if(v=='+'||v=='-'){
				cin>>i>>j;
				if(de[j]==1){
					de[i]=1;
					fu[i]=fu[j]*(v=='+'? 1:-1);
				}
				else if(de[j]==2){
					de[i]=2;
					ex[i]=ex[j]*(v=='+'? 1:-1);
				}
			}else{
				cin>>i;
				de[i]=2;
				if(v=='T')ex[i]=1;
				if(v=='F')ex[i]=-1;
				if(v=='U')ex[i]=0;
			}
		}//cout<<endl;
		/*for(int k=1;k<=n;k++){
			cout<<k<<' ';
			if(de[k]==1){
				cout<<fu[k];
			}
			if(de[k]==2){
				if(ex[k]==1)cout<<'T';
				if(ex[k]==-1)cout<<'F';
				if(ex[k]==0)cout<<'U';
			}cout<<endl;
		}cout<<endl;*/
		for(int k=1;k<=n;k++){
			//cout<<k<<":\n";
			dfs(k,2);//cout<<endl;
		}//cout<<endl;
		/*for(int qq=0;qq<100;qq++){
			for(int k=1;k<=n;k++){
	    		if(de[k]==1&&fu[k]==-k){
    				de[k]=2,ex[k]=0;
    			}
    			if(de[k]==1&&de[abs(fu[k])]==2&&ex[abs(fu[k])]==0){
    				de[k]=2,ex[k]=0;
				}
    		}
		}*/
		for(int k=1;k<=n;k++){
			if(de[k]==2&&ex[k]==0){
				//cout<<k<<endl;
				ans++;
			}
		}cout<<ans<<endl;
	}
}