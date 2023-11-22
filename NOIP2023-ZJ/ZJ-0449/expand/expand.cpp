#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxsize = 500010;
int n, m;
int c, q;
int backupX[maxsize], backupY[maxsize];
int seqX[maxsize], seqY[maxsize];
vector<char> anss;
bool inrule(int idX, int idY, bool cmprule){
	if (seqX[idX]==seqY[idY]) return false;
	return ((seqX[idX]<seqY[idY])==cmprule);
}
bool answer;
bool vis[20020][20020];
void dfs(int xi, int yi, bool crule){
	if (xi>n or yi>m) return;
	if (xi==n and yi==m) {
		answer = true; return;
	}
	if (xi<20000 and yi<20000){
		if (vis[xi][yi]) return;
		vis[xi][yi]=true;
	}
	if (inrule(xi, yi+1, crule) && (!answer)) dfs(xi, yi+1, crule);
	if (inrule(xi+1, yi, crule) && (!answer)) dfs(xi+1, yi, crule);
}
int main(){
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	cin>>c>>n>>m>>q;
	for (int i=1;i<=n;i++) cin>>seqX[i];
	for (int i=1;i<=n;i++) backupX[i]=seqX[i];
	for (int i=1;i<=m;i++) cin>>seqY[i];
	for (int i=1;i<=m;i++) backupY[i]=seqY[i];
	answer = false;
	if (seqX[1]!=seqY[1] and (seqX[1]<seqY[1])==(seqX[n]<seqY[m])) dfs(1, 1, (seqX[1]<seqY[1]));
	if (answer) anss.push_back('1');
	else anss.push_back('0');
	
	for (int j=0;j<=min(n, 20010);j++){
		for (int k=0;k<=min(m,20010);k++){
			vis[j][k]=false;
		}
	}
	
	for (int i=1, kx, ky;i<=q;i++) {
		cin>>kx>>ky;
		for (int j=0, px, vx;j<kx;j++){
			cin>>px>>vx;
			seqX[px]=vx;
		}
		for (int j=0, py, vy;j<ky;j++){
			cin>>py>>vy;
			seqY[py]=vy;
		}
		answer = false;
		if (seqX[1]!=seqY[1] and seqX[n]!=seqY[m]) {
			if ((seqX[1]<seqY[1]) == (seqX[n]<seqY[m]))
				dfs(1, 1, (seqX[1]<seqY[1]));
		}
		if (answer) anss.push_back('1');
		else anss.push_back('0');
		if (i!=q) {
			for (int j=1;j<=n;j++) seqX[j]=backupX[j];
			for (int j=1;j<=m;j++) seqY[j]=backupY[j];
			for (int j=0;j<=min(n, 20010);j++){
				for (int k=0;k<=min(m,20010);k++){
					vis[j][k]=false;
				}
			}
		}
	}
	for (char cc:anss) cout<<cc;
	cout<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}