#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<int>v;
	int f;//father
	int z;//ziji
	int dan;
	
}e[100005];
int nw[100005];
int vis[100005];
map<int,map<int,int> > pro;
int add(int i){
	if(vis[i]){
		return 0;
	}
	vis[i]=1;
	int ans=1;
	for(int j=0;j<e[i].v.size();j++){
		int to=e[i].v[j];
		if(!pro[i][to])ans+=add(to);
	}
	return ans;
}
map<char,int>mp;

int main(){
 	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	mp['U']=-1;
	mp['T']=1;
	mp['F']=0;
	scanf("%d%d",&c,&t);
//	cout<<c;
	while(t--){
		
	//	cout<<1;
		for(int i=0;i<100004;i++){
			nw[i]=-2;
			e[i].dan=0;
			e[i].f=0;
			e[i].z=0;
			e[i].v.clear();
			vis[i]=0;			
		}
		if(c==3||c==4){
			int ans=0;
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=0;i<m;i++){
				int x=0;
				char s[3];
				scanf("%s",s);
				scanf("%d",&x);
				nw[x]=mp[s[0]];
			}
			for(int i=1;i<=n;i++){
				if(nw[i]==-1){
					ans++;
				}
			}
			printf("%d\n",ans);
		}else if(c==7||c==8){
			int ans=0;
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=0;i<m;i++){
				char s[3];
				int x1,x2;
				scanf("%s",s);
				scanf("%d%d",&x1,&x2);
				//cout<<x1<<x2;
				if(!e[x2].f){
					e[x2].z=1;
				}
				if(!e[x1].f&&e[x1].z){
					//cout<<x1<<e[x1].z<<endl;
					if(s[0]=='+'){
						if(!(e[x2].z==e[x1].z)){
							e[x1].dan=1;
						}
					}else{
						if((e[x2].z==e[x1].z)){
							e[x1].dan=1;
						}
					}
				}else{
				
					e[x2].v.push_back(x1);
				//	cout<<x1;
					if(e[x1].f){
						pro[e[x1].f][x1]=1;
					}
					e[x1].f=x2;
					if(s[0]=='+'){
						e[x1].z=e[x2].z;
					}else{
						
						e[x1].z=-e[x2].z;
					
					}
				}	
			}
			
			for(int i=1;i<=n;i++){
			//	cout<<e[i].f<<" "<<e[i].z<<" "<<e[i].dan<<endl;
				if(e[i].dan){
				//	cout<<i<<endl;
					ans+=add(i);
				}
			}
			printf("%d\n",ans);
		}else if(c==5||c==6){
			int ans=0;
			int n,m;
			scanf("%d%d",&n,&m);
			for(int i=0;i<m;i++){
				char s[3];
				int x1,x2;
				scanf("%s",s);
				if(s[0]=='+'||s[0]=='-'){
					scanf("%d%d",&x1,&x2);
					
				}if(s[0]=='U'){
					scanf("%d",&x1);
				}
					
			}
			
			for(int i=1;i<=n;i++){
			//	cout<<e[i].f<<" "<<e[i].z<<" "<<e[i].dan<<endl;
				if(e[i].z==-2){
					ans+=add(i);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
