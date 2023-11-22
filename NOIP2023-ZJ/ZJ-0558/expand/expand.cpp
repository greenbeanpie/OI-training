#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define int long long
int c,n,m,q;
int a[MAXN],b[MAXN],kx,ky,ka[MAXN],kb[MAXN],xa,va,amn,amx,bmn,bmx;
inline void check(){
	amn=amx=ka[0];
	for(int i=1;i<n;i++) amn=min(amn,ka[i]),amx=max(amx,ka[i]);
	bmn=bmx=kb[0];
	for(int i=1;i<m;i++) bmn=min(bmn,kb[i]),bmx=max(bmx,kb[i]); 
	if(ka[0]>kb[0]){
		if(amn<=bmn) printf("0");
		else if(bmx>=amx) printf("0");
		else printf("1");
	}
	else if(ka[0]<kb[0]){
		if(bmn<=amn) printf("0");
		else if(amx>=bmx) printf("0");
		else printf("1");
	}
	else printf("0");
	return;
}
signed main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%lld%lld%lld%lld",&c,&n,&m,&q);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<m;i++) scanf("%lld",&b[i]);
	memcpy(ka,a,sizeof(ka));
	memcpy(kb,b,sizeof(kb));
	check();
	while(q--){
		memcpy(ka,a,sizeof(ka));
		memcpy(kb,b,sizeof(kb));
		scanf("%lld%lld",&kx,&ky);
		for(int i=0;i<kx;i++){
			scanf("%lld%lld",&xa,&va);
			ka[xa-1]=va;
		}
		for(int i=0;i<ky;i++){
			scanf("%lld%lld",&xa,&va);
			kb[xa-1]=va;
		}
		check();
	}
	return 0;
}
//期望得分100+40+0+44=184
//    ------ ------ ------
//    --     --     --
//    --     --     ------
//    --     --     --
//    ------ ------ --
//    
//
//
//    --  -- ------ --     ------  --  -- ------ 
//    --  -- --     --     --  --  - -- - --    
//    ------ ------ --     ------  - -- - ------
//    --  -- --     --     --      - -- - --    
//    --  -- ------ ------ --      - -- - ------ 
