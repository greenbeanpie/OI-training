#include<bits/stdc++.h>
using namespace std;
char s[3010][3010];
int tong[3010][30];
int Ans[3010][2];
struct node{
	int id;
	int kd;
}D[6010];
bool Check(int xx,int xd,int yy,int yd){
	if(xd==1&&yd==1){
//		cout<<114<<"  "<<D[xx].id<<"  "<<D[yy].id;
		for(int i=0;i<=25;i++){
			if(tong[xx][i]==tong[yy][i]){
				continue;
			}
			if(tong[xx][i]<tong[yy][i]){
//				cout<<i<<"  114";
				return 0;
			}
			if(tong[xx][i]>tong[yy][i]){
//				cout<<i<<"  514";
//				cout<<tong[4][2]<<"   ";
				return 1;
			}
		}
		return 1;
	}
	if(xd==1&&yd==2){
//		cout<<114<<"  ";
		int Ad1,Ad2;
		for(int i=0;i<=25;i++){
			if(tong[xx][i]){
				Ad1=i;
				break;
			}
		}
		for(int i=25;i>=0;i--){
			if(tong[yy][i]){
				Ad2=i;
				break;
			}
		}
//		cout<<char(Ad1+'a')<<"   "<<char(Ad2+'a')<<"    ";
		if(Ad1<Ad2){
//			cout<<514<<"  ";
			return 1;
		}
		else{
			return 0;
		}
	}
	if(xd==2&&yd==1){
		int Ad1,Ad2;
		for(int i=25;i>=0;i--){
			if(tong[xx][i]){
				Ad1=i;
				break;
			}
		}
		for(int i=0;i<=25;i++){
			if(tong[yy][i]){
				Ad2=i;
				break;
			}
		}
		if(Ad1<=Ad2){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(xd==2&&yd==2){
		for(int i=25;i>=0;i--){
			if(tong[xx][i]==tong[yy][i]){
				continue;
			}
			if(tong[xx][i]>tong[yy][i]){
				return 0;
			}
			if(tong[xx][i]<tong[yy][i]){
				return 1;
			}
		}
		return 1;
	}
}
bool cmp(node xx,node yy){
	return Check(xx.id,xx.kd,yy.id,yy.kd);
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
			tong[i][s[i][j]-'a']++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<=25;j++){
//			cout<<tong[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		D[i].kd=1;D[i].id=i;
	}
	for(int i=n+1;i<=2*n;i++){
		D[i].kd=2;D[i].id=i-n;
	}
//	cout<<Check(4,1,1,2)<<"  ";
	sort(D+1,D+2*n+1,cmp);
//	for(int i=1;i<=2*n;i++){
//		cout<<D[i].id<<" "<<D[i].kd<<" "<<endl;
//	}
//	for(int i=1;i<=2*n;i++){
//		for(int j=i+1;j<=2*n;j++){
//			cout<<Check(D[i].id,D[i].kd,D[j].id,D[j].kd);
//		}
//	}
	for(int i=1;i<=2*n;i++){
		if(D[i].kd==1){
			Ans[D[i].id][0]=i;
		}
		if(D[i].kd==2){
			Ans[D[i].id][1]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int Min=1e9+7;
		for(int j=1;j<=n;j++){
			if(j!=i){
				Min=min(Min,Ans[j][1]);
			}
		}
		if(Ans[i][0]<Min){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	cout<<'\n';
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/
/*
2023
zhefang duibuqi.
*/