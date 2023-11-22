#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long int LL;
struct node{
	LL l,r,v;
}e[N];
inline LL read(){
	LL x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
	return x;
}
LL n,m,k,d;
LL C,T;
LL idx;
LL ans[N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	C = read(),T = read();
	for(int qwe = 1;qwe <= T;qwe++){
		memset(e,0,sizeof(e));
		n = read(),m = read(),k = read(),d = read();
	    for(int i = 1;i <= m;i++){
		    LL x = read();
		    LL y = read();
		    LL v = read();
		    e[i].l = x-y+1;
		    e[i].r = x;
		    e[i].v = v-y*d;
	    }
            LL anss = 0;
		    LL cnt = 0;
		    for(int i = 1;i <= n;i++){
		    	if(cnt+e[i].r-e[i].l+1 > k){
		    		cnt = 0;
		    		continue;
	    		}
		        if(e[i].l == i && e[i].v >= 0){
		        	cnt += e[i].r-e[i].l+1;
		        	anss += e[i].v;
		        	i += e[i].r-e[i].l+1;
		    	}
		    }
		ans[++idx] = anss;
	}
	for(int i = 1;i <= T;i++){
		cout << ans[i] << endl;
	}
	return 0;
}
