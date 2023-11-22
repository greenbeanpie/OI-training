#include<bits/stdc++.h>
using namespace std;
int id,T,ans;
struct value{
	char t;int v;//t:1T0F
}val[100010];
void spt_3_4(){
	while(T--){
		int N,M,cnt = 0;
		cin >> N >> M;
		while(M--){
			char v;int i;
			cin >> v >> i;
			if(v == 'U')++cnt;
		}
		cout << cnt << "\n";
	}
}
char opset[200];
bitset<100010>had,res;
void push(int now){
	if(had[now]) return;
	had[now] = 1;
	if(now == val[now].v) return;
	push(val[now].v);
	val[now].t = (val[now].t == 1?val[val[now].v].t:opset[val[val[now].v].t]);
	val[now].v = val[val[now].v].v;
}
bool check(int now){
	if(had[now]) return res[now];
	had[now] = 1;
	if(now == val[now].v){
		res[now] = (val[now].t == 'U'||val[now].t == 0);
		return res[now];
	}
	res[now] = check(val[now].v);
	return res[now];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	opset[1] = 0;opset[0] = 1;
	opset['U'] = 'U';opset['F'] = 'T';opset['T'] = 'F';
	cin >> id >> T;
	if(id == 3||id == 4){
		spt_3_4();
		return 0;
	}
	while(T--){
		int N,M;
		cin >> N >> M;
		ans = 0;had = 0;res = 0;
		for(int i = 1;i <= N;++i){
			val[i].t = 1;
			val[i].v = i;
		}
		while(M--){
			char op;
			cin >> op;
			if(op == 'T'||op == 'F'||op == 'U'){
				int i;
				cin >> i;
				val[i].t = op;
				val[i].v = i;
			}else{
				int i,j;
				cin >> i >> j;
				if(val[j].t == 0||val[j].t == 1){
					val[i].v = j;
					val[i].t = (op == '-'?0:1);
				}else{
					val[i].v = i;
					val[i].t = (op == '-'?opset[val[j].t]:val[j].t);
				}
			}
		}
		for(int i = 1;i <= N;++i){if(!had[i]) push(i);}
		had = 0;
		for(int i = 1;i <= N;++i){if(check(i)) ans++;}
		cout << ans << "\n";
	}
	return 0;
}
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
//rp+=inf;
