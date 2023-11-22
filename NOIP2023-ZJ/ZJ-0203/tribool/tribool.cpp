#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C,T;
int a[100005];//正数表示对应下标变量的初始值
//负数表示非
//T:10000001;F:-10000001;U:0
int f[200005];
int used[100005];
int n,m;
unordered_map<char,int>ins;
int find(int x){
	if(x==f[x])return x;
	f[x]=find(f[x]);
	return f[x];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ins['T']=10000001,ins['F']=-10000001,ins['U']=0;
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<=n;i++){a[i]=i,f[i]=-2,used[i]=0;}
		for(int i=1;i<=m;i++){
			char op;
			cin>>op;
			if(op=='+'){
				int x,y;
				cin>>x>>y;
				a[x]=a[y];
			}else if(op=='-'){
				int x,y;
				cin>>x>>y;
				a[x]=-a[y];
			}else{//op=='T'|'F'|'U'
				int x;
				cin>>x;
				a[x]=ins[op];
			}
		}
//		for(int i=1;i<=n;i++){
//			//a[i]=abs(a[i]);
//			if(a[i]!=10000001&&a[i]!=-10000001){
//				int p=find(i);
//				int q=find(a[i]);
//				f[p]=q;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(a[i]==0||a[i]==-i){
//				used[i]=1;
//			}
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			if(abs(a[i])==10000001)continue;
//			if(used[abs(a[i])]==1||used[i]==1){
//				ans++;
//			}
//		}
//		cout<<ans<<"\n";
//		for(int i=1;i<=n;i++){
//			cout<<a[i]<<" ";
//		}
		for(int i=1;i<=n;i++){
			if(f[i]==-2){
				if(a[i]==0||a[i]==10000001||a[i]==-10000001){
					f[i]=a[i];
				}else{
					f[i]=1;
					int now=i,val=1,cnt=0;
					while(1){
						cnt++;
						//cout<<now<<" "<<a[now]<<"\n";
						if(used[now]>=1){
							if(f[now]==0||f[now]==10000001||f[now]==-10000001){
								f[i]=f[now];
							}else{
								if(val!=f[now]){
									f[i]=0;
								}else{
									f[i]=10000001;
								}
							}
							break;
						}
						used[now]++,f[now]=val;
						if(a[now]==now){
							f[i]=10000001;
							break;
						}else if(a[now]==-now){
							f[i]=0;
							break;
						}else if(a[now]==i){
							if(val==-1){
								f[i]=0;
							}
							break;
						}else if(a[now]==-i){
							if(val==1){
								f[i]=0;
							}
							break;
						}else if(a[now]==0){
							f[i]=0;
							break;
						}else if(abs(a[now])==10000001){
							f[i]=a[now];
							break;
						}else{
							if(a[now]<0)val=-val;
							now=abs(a[now]);
						}
					}
					now=i,val=f[i];
					while(1){
						//cout<<now<<"\n";
						if(used[now]>=2)break;
						used[now]++;
						f[now]=val;
						if(a[now]==0||abs(a[now])==10000001){
							break;
						}
						if(a[now]<0)val=-val;
						//val*=abs(a[now])/a[now];
						now=abs(a[now]);
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			//cout<<f[i]<<" ";
			if(f[i]==0)ans++;
		}
		//cout<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/