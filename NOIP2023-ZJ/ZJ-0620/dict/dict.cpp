//#include<bits/stdc++.h>
//using namespace std;
//inline int read(){
//	int f=1,x=0;char ch=getchar();
//	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
//	while(ch<='9'&&ch>='0'){ x=x*10+ch-48;ch=getchar();}
//	return x*f;
//}
//int n,m;
//string s;
//int a[4005][4005],b[4005][4005],ha[4005][45];
//long long hash1[4005],hash2[4005];
//bool cmp(int a,int b){
//	return a>b;
//}
//int main(){
//	freopen("dict.in","r",stdin);
//	freopen("dict.out","w",stdout);
//	
////	freopen("D:\\dict4.in","r",stdin);
////	freopen("D:\\dic.out","w",stdout);
//	n=read(),m=read();
//	for(int i=1;i<=n;i++){
//		cin>>s;
//		for(int j=1;j<=m;j++){
//			b[i][j]=a[i][j]=int(s[j-1])-96;
//			ha[i][b[i][j]]++;
//		}
//	}
//	if(n==1&&m==1){
//		printf("1");
//		return 0;
//	}
//	if(m==1){
//		int Min=100000000;
//		for(int i=1;i<=n;i++){
//			if(a[i][0]<Min){
//				Min=a[i][0];
//			}
//		}
//		for(int i=1;i<=n;i++){
//			if(a[i][0]==Min){
//				printf("1");
//				continue;
//			}
//			printf("0");
//		}
//		return 0;
//	}
//	
////	for(int i=1;i<=n;i++){
////		for(int j=m;j>=1;j--){
////			hash1[i]+=a[i][j]*(m-j+1);
////		}
////	}
////	
//	int we=1;
//	for(int i=1;i<=n;i++){
//		we=1;
//		for(int j=26;j>=1;j--){
//			for(int k=1;k<=ha[i][j];k++){
//				hash1[i]+=j*we*1ll;we++;
//			}			
//		} 
//	}
//	we=1;
//	for(int i=1;i<=n;i++){
//		we=1;
//		for(int j=1;j<=26;j++){
//			for(int k=1;k<=ha[i][j];k++){
//				hash2[i]+=j*we*1ll;we++;
//			}			
//		} 
//	}      
////	for(int i=1;i<=n;i++){
////		cout<<hash1[i]<<" "<<hash2[i]<<endl;
////	}    
//	bool tr=true;
//	for(int i=1;i<=n;i++){
//		tr=true;
//		for(int j=1;j<=n;j++){
//			if(i==j) continue;
//			//cout<<i<<" "<<j<<" "<<hash1[i]<<" "<<hash2[j]<<endl;
//			if(hash1[i]>=hash2[j]){
//				printf("0");
//				tr=false;
//				break;
//			}
//		}
//		if(tr){
//			printf("1");
//		}
//	}
//
//	return 0;
//}
//
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){ x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
string s;
int ha[4005][45];
long long hash1[4005][405],hash2[4005][405];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=m;j++){
			ha[i][int(s[j-1])-97]++;
		}
	}
	if(n==1&&m==1){
		printf("1");
		return 0;
	}
	long long we=1,id=1,op=1;
	for(int i=1;i<=n;i++){
		we=1;id=1;op=1;
		for(int j=25;j>=0;j--){
			if(op==10){
				id++;we=1;op=1;
			}				
			for(int k=1;k<=ha[i][j];k++){
				hash1[i][id]+=j*we*1ll;we*=26;op++;
				if(op==10){
					id++;we=1;op=1;
				}
			}			
		} 
	}
	for(int i=1;i<=n;i++){
		we=1;id=1;op=1;
		for(int j=0;j<=25;j++){
			if(op==10){
				id++;we=1;op=1;
			}	
			for(int k=1;k<=ha[i][j];k++){
				hash2[i][id]+=j*we*1ll;we*=26;op++;
				if(op==10){
					id++;we=1;op=1;
				}					
			}			
		} 
	}

	bool tr=true;
	for(int i=1;i<=n;i++){
		tr=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			for(int k=id;k>=1;k--){
				if(hash1[i][k]>hash2[j][k]){
					printf("0");tr=false;break;
				}
			}
			if(!tr) break;
		}
		if(tr){
			printf("1");
		}
	}

	return 0;
}














