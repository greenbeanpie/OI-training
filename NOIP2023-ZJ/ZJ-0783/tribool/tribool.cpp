#include<bits/stdc++.h>
using namespace std;
int lst[15];
int rc[15];
int a[100010];
bool ck[100010];
//int p1[100010],p2[100010];
struct M{
	int Kd;
	int x;
	int y;
}D[20];
int qpow(int x,int n){
	if(n==0){
		return 1;
	}
	if(n%2==1){
		return qpow(x*x,n/2)*x;
	}
	return qpow(x*x,n/2);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(c==1||c==2){
		while(t--){
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char v;
				cin>>v;
				if(v=='T'){
					D[i].Kd=1;
					int xx;
					cin>>xx;
					D[i].x=xx;
				}
				if(v=='F'){
					D[i].Kd=2;
					int xx;
					cin>>xx;
					D[i].x=xx;
				}
				if(v=='U'){
					D[i].Kd=3;
					int xx;
					cin>>xx;
					D[i].x=xx;
				}
				if(v=='+'){
					D[i].Kd=4;
					int xx,yy;
					cin>>xx>>yy;
					D[i].x=xx;D[i].y=yy;
				}
				if(v=='-'){
					D[i].Kd=5;
					int xx,yy;
					cin>>xx>>yy;
					D[i].x=xx;D[i].y=yy;
				}
			}
			int Min=1e9+7;
			for(int i=0;i<qpow(3,n);i++){
				int Ans=0;
				for(int j=1;j<=n;j++){
					lst[j]=(i%qpow(3,j))/qpow(3,j-1)+1;
					if(lst[j]==3){
						Ans++;
					}
				}
				for(int i=1;i<=n;i++){
					rc[i]=lst[i];
				}
				for(int j=1;j<=m;j++){
					if(D[j].Kd==1||D[j].Kd==2||D[j].Kd==3){
						lst[D[j].x]=D[j].Kd;
					}
					if(D[j].Kd==4){
						lst[D[j].x]=lst[D[j].y];
					}
					if(D[j].Kd==5){
						if(lst[D[j].y]==1){
							lst[D[j].x]=2;
						}
						if(lst[D[j].y]==2){
							lst[D[j].x]=1;
						}
						if(lst[D[j].y]==3){
							lst[D[j].x]=3;
						}
					}
				}
				bool flag=1;
				for(int i=1;i<=n;i++){
					if(rc[i]!=lst[i]){
						flag=0;
						break;
					}
				}
				if(flag){
					Min=min(Min,Ans);
				}
			}
			cout<<Min<<endl;
		}
		cout<<flush;
	}
	if(c==3||c==4){
		while(t--){
			int n,m;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				a[i]=0;
			}
			for(int i=1;i<=m;i++){
				char v;
				int x;
				cin>>v>>x;
				if(v=='T'){
					a[x]=1;
				}
				if(v=='F'){
					a[x]=2;
				}
				if(v=='U'){
					a[x]=3;
				}
			}
			int Ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==3){
					Ans++;
				}
			}
			cout<<Ans<<'\n';
		}
		cout<<flush;
	}
//	if(c==5||c==6){
//		while(t--){
//			int n,m;
//			cin>>n>>m;
//			for(int i=1;i<=n;i++){
//				p1[i]=p2[i]=ck[i]=0;
//			}
//			int h=0;
//			for(int i=1;i<=m;i++){
//				char v;
//				cin>>v;
//				if(v=='+'){
//					int xx,yy;
//					cin>>xx>>yy;
//					ck[xx]=ck[yy];
//					p1[++h]=xx;
//					p2[h]=yy;
//				}
//				if(v=='U'){
//					int xx;
//					cin>>xx;
//					ck[xx]=1;
//				}
//			}
//			int Ans=0;
//			for(int i=1;i<=n;i++){
//				if(ck[i]==1){
//					Ans++;
//				}
//			}
//			for(int i=1;i<=h;i++){
//				ck[p1[i]]=ck[p2[i]];
//			}
//			int Ans=0;
//			for(int i=1;i<=n;i++){
//				if(ck[i]==1){
//					Ans++;
//				}
//			}
//			cout<<Ans<<'\n';
//		}
//		cout<<flush;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
zhefang duibuqi
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1 
- 3 2
- 1 3
2 2
T 2
U 2
*/