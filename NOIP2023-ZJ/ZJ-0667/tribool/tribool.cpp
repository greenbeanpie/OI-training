#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n=N,m,a[N],b[N];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4){
		while(t){
			t--;
			for(int i=1;i<=N;i++){
				a[i]=1;
				b[i]=0;
			}
			cin>>n>>m;
			char ch;
			while(m){
				m--;
				cin>>ch;
				int x,y;
				if(ch=='T'){
					cin>>x;
					a[x]=1;
				}else if(ch=='F'){
					cin>>x;
					a[x]=-1;
				}else if(ch=='U'){
					cin>>x;
					a[x]=0;
				}else if(ch=='+'){
					cin>>x>>y;
					a[x]=a[y];
				}else if(ch=='-'){
					cin>>x>>y;
					a[x]=(-1)*a[y];
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			cout<<ans<<endl;
		}
	}
	else if(c==5||c==6){
		while(t){
			t--;
			for(int i=1;i<=n;i++){
				a[i]=1;
				b[i]=0;
			}
			cin>>n>>m;
			char ch;
			while(m){
				m--;
				cin>>ch;
				int x,y;
				if(ch=='U'){
					cin>>x;
					a[x]=0;
				}else if(ch=='+'){
					cin>>x>>y;
					//a[x]=a[y];
					b[x]=y;
				}
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(b[i]!=0) 
					a[i]=a[b[i]];
			}
//			for(int i=1;i<=n;i++){
//				cout<<a[i]<<" ";
//			}
//			cout<<endl;
			for(int i=1;i<=n;i++){
				if(b[i]!=0) a[i]=a[b[i]];
				if(a[i]==0){
					//cout<<i<<" ";
					ans++;
				} 
			}
			cout<<ans<<endl;
		}
	}		
	return 0;
}
/*
1 1
2 2
T 2
U 2

5 1

5 1
10 6
+ 2 9
U 9
+ 1 9
+ 7 1
+ 6 3
+ 10 9 
*/
