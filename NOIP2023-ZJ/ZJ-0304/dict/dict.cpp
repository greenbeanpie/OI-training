#include <bits/stdc++.h>
using namespace std;

string a[10000];
int bucket[1000];
bool ans[10000];

int n,m;
int minthins=1;
int dmin(string x,string y){
	for(int i=0;i<m;i++){
		if(x[i]==y[i]){
			continue;
		}
		if(x[i]<y[i]){
			return 1;
		}else if(x[i]>y[i]){
			return -1;
		}
	}
	return 0;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	string x;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i==1){
			x=a[i];
		}
		if(i>=2){
			if(dmin(a[i],x)==1){
				x=a[i];
				minthins=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==minthins){
			cout << 1;
			continue;
		}
		for(int j=0;j<m;j++){
			bucket[a[i][j]-'a']++;
		}
		int cnt=0;
		for(int p=0;p<26;p++){
			while(bucket[p]!=0){
				a[i][cnt]=p+'a';
				cnt++;
				bucket[p]--;
			}
		}
		if(dmin(a[i],x)==1){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	return 0;
}