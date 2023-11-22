#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005][3005],tmp[3005],app[3005],Min[3005][3005],Max[3005],Maxx[3005];
vector<int> Maxi;
string s;
bool cmp(int x,int y){
	return x>y;
}
inline int dy(int x[],int y[]){
	for(int i=1;i<=m;i++){
		if(x[i]>y[i]) return 1;
		if(x[i]<y[i]) return -1;
	}
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][j+1]=s[j]-'a';
		}
	}
	if(n==1){
		cout<<'1'<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		Max[i]=Maxx[i]=1000000000;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			tmp[j]=a[i][j];
			app[a[i][j]]=j;
		}
		sort(tmp+1,tmp+1+m);
		for(int j=1;j<=m;j++){
			Min[i][j]=a[i][j];
		}
		int l=0,r=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]>tmp[j]){
				l=j,r=app[tmp[j]];

				break;
			}
		}
		swap(a[i][l],a[i][r]);
		for(int j=1;j<=m;j++){
			Min[i][j]=a[i][j];
		}
		swap(a[i][l],a[i][r]);		
		
		
		l=0,r=0;
		sort(tmp+1,tmp+1+m,cmp);
		for(int j=1;j<=n;j++){
			if(a[i][j]<tmp[j]){
				l=j,r=app[tmp[j]];
				break;
			}
		}
		swap(a[i][l],a[i][r]);
		int flag=dy(a[i],Max);
		if(flag==-1){
			Maxi.clear();
			Maxi.push_back(i);
			for(int j=1;j<=m;j++){
				Maxx[j]=Max[j];
				Max[j]=a[i][j];
			}
		}else if(flag==0){
			Maxi.push_back(i);
		}else{
			flag=dy(a[i],Maxx);
			if(flag==-1){
				for(int j=1;j<=m;j++){
					Maxx[j]=a[i][j];
				}
			}
		}
		swap(a[i][l],a[i][r]);		
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<Min[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	cout<<"Maxi="<<Maxi[0]<<endl;
//	for(int i=1;i<=m;i++){
//		cout<<Max[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=1;i<=m;i++){
//		cout<<Maxx[i]<<' ';
//	}
	for(int i=1;i<=n;i++){
		if(Maxi.size()==1&&Maxi[0]==i){
			if(dy(Min[i],Maxx)==-1){
				cout<<'1';
			}else{
				cout<<'0';
			}
		}else if(dy(Min[i],Max)==-1){
			cout<<'1';
		}else{
			cout<<'0';
		}	
	}
	cout<<endl;
	return 0;
}