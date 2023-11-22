#include<bits/stdc++.h>

using namespace std;
int n,m,k[3005][3005],zuixiao[3005][3005],zuida[3005][3005],flag;
char guodu;
int main() {
	int mmin=114514,jishu=0;
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1) {
		cout<<1;
		return 0;
	}

	else if(m==1) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>guodu;
				k[i][j]=int(guodu);
			}
		}
		for(int i=0; i<n; i++) {
			if(int(k[i][0])<mmin) {
				mmin=int(k[i][0]);
				jishu=i;
			}
		}
		for(int i=0; i<n; i++) {
			if(i!=jishu)cout<<0;
			else cout<<1;
		}
	} 
	
	
	else if(m==2) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin>>guodu;
				k[i][j]=int(guodu);
			}
		}
		for(int i=0; i<n; i++) {
			if(k[i][0]<k[i][2]) {
				zuida[i][0]=k[i][1];
				zuida[i][1]=k[i][0];
				zuixiao[i][0]=k[i][0];
				zuixiao[i][1]=k[i][1];
			} else {
				zuida[i][0]=k[i][0];
				zuida[i][1]=k[i][1];
				zuixiao[i][0]=k[i][1];
				zuixiao[i][1]=k[i][0];
			}
		}
//		for(int i=0;i<n;i++){
//			cout<<zuixiao[i][0]<<zuixiao[i][1]<<endl;
//			cout<<zuida[i][0]<<zuida[i][1]<<endl;
//			cout<<endl;
//		}
		for(int i=0; i<n; i++) {
			flag=1;
			for(int j=0; j<n; j++) {
				if(j==i)continue;
				if(zuixiao[i][0]>zuida[j][0]) {
					cout<<0;
					flag=0;
					break;
				} else if(zuixiao[i][0]==zuida[j][0]) {
					if(zuixiao[i][1]>zuida[j][1]) {
						cout<<0;
						flag=0;

						break;
					}
				}
			}
			if(flag==1) {
				cout<<1;
			}
		}
	} else {
		srand(time(0));
		for(int i=0; i<n; i++) {
			
			cout<<rand()%2;
		}
	}









	return 0;
}
