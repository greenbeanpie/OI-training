#include <bits/stdc++.h>
using namespace std;
int w[10000];
int g,v;
int p[1000][1000];
int cnt;
int pathj[1000],pathz[1000];
int ans;
int mn=10000000;
void dfs(int u){
	
	if(cnt>mn) return;
	if(ans==v){
		
		if(cnt<mn){
			mn=cnt;
			for(int i=1;i<=cnt;i++){
				pathz[i]=pathj[i];
			}
//			cout << "mn: " << mn << endl;
		}
		cnt--;
		return;
	}
	for(int i=u;i<=g;i++){
		pathj[++cnt]=i;
//		cout << i << endl;
		for(int j=1;j<=v;j++){
			
			w[j]-=p[i][j];
			if(w[j]+p[i][j]>0 && w[j]<=0){
				ans++;
			}
	//		cout << ans << endl;
		}
//		cout << "cnt:" << cnt << endl;
		dfs(i+1);
		for(int j=1;j<=v;j++){
			w[j]+=p[i][j];
			if(w[j]-p[i][j]<=0 && w[j]>0){
				ans--;
			}
			
		}
	}
	cnt--;
	return;
}
int main(){
	#ifdef CODESPACE
		freopen("P1460.in","r",stdin);
		freopen("P1460_xhw.out","w",stdout);
	#endif
	cin >> v;
	for(int i=1;i<=v;i++){
		cin >> w[i];
	}
	cin >> g;
	for(int i=1;i<=g;i++){
		for(int j=1;j<=v;j++){
			cin >> p[i][j];
		}
	}
	for(int i=1;i<=g;i++){
		cnt=0;
		dfs(i);
	}
	cout << mn;
	for(int i=1;i<=mn;i++){
		cout << " " << pathz[i];
	}
	cout << " ";
	return 0;
}