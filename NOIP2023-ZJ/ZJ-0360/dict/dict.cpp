#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+10;
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')sgn*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
char ch[N][N];
ll n,m,num[N][30],t1[30],t2[30];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
			num[i][ch[i][j]-'a']++;
		}
		
	}
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=1;j<=n;j++){
			if(i!=j&&f==0){
				int p=30,q=0,si=0,sj=0;
				for(int k=0;k<=25;k++){
					t1[k]=num[i][k],t2[k]=num[j][k];
					if(t1[k])p=min(p,k);
					if(t2[k])q=max(q,k);
				}
				//cout<<i<<" "<<j<<" "<<p<<" "<<q<<endl;
				while(p<=25&&q>=0&&si<m&&sj<m){
					if(p>q){
						f=1;break;
					}else if(p==q){
						t1[p]-=min(t1[p],t2[q]);t2[q]-=min(t1[p],t2[q]);
						si+=min(t1[p],t2[q]);sj+=min(t1[p],t2[q]);
						if(!t1[p])p++;
						if(!t2[q])q--;
					}else{
						break;
					}
				}
			}
		}
		if(!f)cout<<"1";
		else cout<<"0";
	}
	return 0;
}
//T#YMS@4
