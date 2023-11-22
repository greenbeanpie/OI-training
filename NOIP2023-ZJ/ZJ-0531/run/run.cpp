#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,m,k,d;
inline void f17_18(){
	while(T--){
		long long ans=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;++i){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			if(y<=k&&v>y*d)ans+=v-y*d;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c<=18&&c>=17)f17_18();
	fclose(stdin);
	fclose(stdout);
	return 0;
}