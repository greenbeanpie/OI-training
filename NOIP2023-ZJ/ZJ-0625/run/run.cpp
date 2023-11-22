#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000010;
const int maxm = 100010;
int read() {
	char c = getchar();
	int sum = 0;
	while(c > '9' || c < '0') c = getchar();
	while(c <= '9' && c >= '0') sum = sum * 10 + c - '0',c = getchar();
	return sum;
}
bool run[maxn];
struct chal {
	int x,y,v;
}lol[maxm];
int n,m,k,d,c,t,ans;
pair<int,int> r;
void calc(int x) {
	int sta = lol[x].x - lol[x].y + 1,tmp,day;
//	printf("now x:%d r.first:%d r.second:%d\n",x,r.first,r.second);
	if(r.second >= sta) {
		day = lol[x].x - r.second,tmp = ans - day * d + lol[x].v;
//		printf("mode 1 day %d\n",day);
		if(tmp > ans && lol[r.first].y + lol[x].x - r.second <= k) r.first = x,ans = tmp,r.second += day;
	}else if(lol[r.first].x != lol[x].x - lol[x].y) {
		tmp = ans - lol[x].y * d + lol[x].v;
//		printf("mode 2 day %d\n",lol[x].y);
		if(tmp > ans) r.first = x,ans = tmp,r.second = lol[x].x;
	}else {
//		printf("mode 3 day %d\n",lol[x].y);
		if(lol[r.first].x + lol[x].y <= k) {
			tmp = ans - lol[x].y * d + lol[x].v;
			if(tmp > ans) r.first = x,ans = tmp,r.second += lol[x].y;
		}
	}
}
bool cmp(chal a,chal b) {
	return a.x < b.x;
}
int main() {
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c = read(),t = read();
	while(t--) {
		ans = 0;
		n = read(),m = read(),k = read(),d = read();
		r.first = r.second = 0;
		for(int i=1;i<=m;i++) lol[i].x = read(),lol[i].y = read(),lol[i].v = read();
		sort(lol + 1,lol + 1 + m,cmp);
		for(int i=1;i<=m;i++) {
			if(lol[i].y <= k && lol[i].x - lol[i].y + 1 > 0) calc(i);
		}
		printf("%d\n",ans);
	}
}