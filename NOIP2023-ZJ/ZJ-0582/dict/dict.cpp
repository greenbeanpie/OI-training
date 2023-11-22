#include<bits/stdc++.h>
using namespace std;
int n,m;
priority_queue<int>q[1005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==1){
		if(n==1){
			char op;
			cin>>op;
			cout<<1<<endl;
			return 0;
		}
		else{
			char w[30];
			char t='z';
			for(int i=1;i<=n;i++){
				cin>>w[i];
				if(t>w[i])t=w[i];
			}
			for(int i=1;i<=n;i++){
				if(w[i]==t)cout<<1;
				else cout<<0;
			}
			return 0;
		}
	}
	else if(m==2){
		char st[20][3];
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++)cin>>st[i][j];
		int a[20][4];
		int b[20][4];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=1;j++){
				a[i][j]=st[i][j]-'a'+1;
			}
			if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
		}
		int flag;
		for(int i=1;i<=n;i++){
			flag=1;
			int t=0;
			//cout<<" "<<a[i][0]<<" "<<a[i][1]<<endl;
			for(int j=1;j<=n;j++){
				if(a[i][0]>a[j][1]){
					flag=0;
					break;
				}
			}
			if(flag==1)cout<<1;
			else cout<<0;
		}
		return 0;
	}
	else {
		char st[304][304];
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				cin>>st[i][j];
				q[i].push(int(st[i][j]-'a'+1));
			}
		}
		int a[305][305],b[305][305];
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++){
			//cout<<q[i].top()<<endl;
			a[i][j]=b[i][m-j-1]=q[i].top();
			q[i].pop();
		}
		//cout<<a[1][0]<<" "<<a[1][1]<<endl;
		int flag;
		for(int i=1;i<=n;i++){
			flag=1;	
			for(int j=1;j<=n;j++){
				for(int k=0;k<m;k++){
					if(b[i][k]>a[j][k]){
						flag=0;
						break;
					}
					else if(b[i][k]<a[j][k]){
						flag=1;
						break;
					}
				}
				if(flag==0)break;
			}
			if(flag==1)cout<<1;
			else cout<<0;
		}
		return 0;
	}
}
