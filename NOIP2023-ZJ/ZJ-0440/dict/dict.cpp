#include  <bits/stdc++.h>
#define N 3005
using namespace std;
string s;
int n,m;
int t[N][30];
struct apple{
	int pos;
};
apple maxp[N],minp[N];

int main (){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int i,j,flag=1;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (i=1;i<=n;i++){
		cin>>s;
		for (j=0;j<m;j++){
			t[i][s[j]-'a']++;
		}
		for (j=0;j<=25;j++){
			if (t[i][j]){
				minp[i].pos=j;
				break;
			} 
		}
		for (j=25;j>=0;j--){
			//cout<<j<<endl;
			if (j<0) break;
			if (t[i][j]){
				maxp[i].pos=j;
				break;
			} 
		}
	}
	for (i=1;i<=n;i++){
		flag=1;
		for (j=1;j<=n;j++){
			if (i==j) continue;
			if (minp[i].pos>maxp[j].pos){
				flag=0;break;
			}
			if (minp[i].pos==maxp[j].pos){
				flag=0;break;
			} 
 		}
		cout<<flag;
	}
	return 0;
}
