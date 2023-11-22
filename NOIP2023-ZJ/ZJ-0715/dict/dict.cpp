#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mkp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
void rd(int &x) {
	x = 0; int tp = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') tp = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	if(tp) x = -x;
}
const int N = 3005;
char s[N][N], mns[N][N], mxs[N][N];
int sum[N << 1], pos[N];
struct node {
	char ch[N];
	int pz, yid;
}qwq[N << 1];
bool cmp(node x, node y) {
	if(strcmp(x.ch, y.ch) == 0) 
		return x.pz < y.pz; //´¦Àíme 
	return strcmp(x.ch, y.ch) < 0;
}
int main() {
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	int n, m;
	rd(n); rd(m);
	int cnt = 0;
//	cout<<n<<" "<<m<<endl;
	for(int i = 1; i <= n; i++) {
		scanf("%s", mns[i]);
	//	cout<<mns[i]<<" "<<mxs[i]<<endl;
		sort(mns[i], mns[i] + m);
		for(int j = 0; j < m; j++)
			mxs[i][m - 1 - j] = mns[i][j];
			
		++cnt;
		for(int j = 0; j < m; j++)
			qwq[cnt].ch[j] = mns[i][j];
		qwq[cnt].pz = 0;
		qwq[cnt].yid = i;
		
		++cnt;
		for(int j = 0; j < m; j++)
			qwq[cnt].ch[j] = mxs[i][j];
		qwq[cnt].pz = 1;
		qwq[cnt].yid = 0;
		//cout<<mns[i]<<" "<<mxs[i]<<endl;
	}
	sort(qwq + 1, qwq + cnt + 1, cmp);
	for(int i = 1; i <= cnt; i++)
		pos[qwq[i].yid] = i;
	for(int i = cnt; i >= 1; i--) 
		sum[i] = sum[i + 1] + qwq[i].pz;
	for(int i = 1; i <= n; i++) {
			if(sum[pos[i]] == n) printf("1");
			else printf("0");
		}
	puts("");
	return 0;
}
