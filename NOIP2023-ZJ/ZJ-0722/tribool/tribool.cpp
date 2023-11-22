#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,l,r,ll,ans;
string s;
char v;
char pp(char a){
	if(a=='T') a='F';
	else if(a=='F') a='T';
	return a;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==3||c==4){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%c",&v);
				if(v=='T'||v=='F'||v=='U'){
					scanf("%d",&l);
					ll=max(ll,l);
					s[l]=v;
				}
				for(int i=1;i<=ll;i++){
					if(s[i]=='U') ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else if(c==5||c==6){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%c",&v);
				if(v=='U'){
					scanf("%d",&l);
					ll=max(ll,l);
					s[l]=v;
				}else if(v=='+'){
					scanf("%d%d",&l,&r);
					ll=max(ll,max(l,r));
					s[l]=s[r];
				}
				for(int i=1;i<=ll;i++){
					if(s[i]=='U') ans++;
				}
			}
			cout<<ans<<endl;
		}
	}else if(c==1||c==2){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%c",&v);
				if(v=='T'||v=='F'||v=='U'){
					scanf("%d",&l);
					ll=max(ll,l);
					s[l]=v;
				}else if(v=='+'){
					scanf("%d%d",&l,&r);
					ll=max(ll,max(l,r));
					s[l]=s[r];
				}else if(v=='-'){
					scanf("%d%d",&l,&r);
					ll=max(ll,max(l,r));
					s[l]=pp(s[r]);
				}
				for(int i=1;i<=ll;i++){
					if(s[i]=='U') ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}