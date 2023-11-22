#include<bits/stdc++.h>
using namespace std;
int n,m,a[3005][3005],bel[2];
string s[3005],ans="",tmax[3005],tmin[3005],mins[2];

bool cmp1(int a,int b){
	return a<b;
}
bool cmp2(int a,int b){
	return a>b;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin >> n >> m;
	if(n==1){
		cout << "1";
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		for(int j = 0; j < m; j++)a[i][j+1]=s[i][j];
		sort(a[i]+1,a[i]+1+m,cmp2);
		tmax[i]=tmin[i]="";
		for(int j = 1; j <= m; j++){
			tmax[i]+=char(a[i][j]);
		}
		if(!bel[0]||tmax[i] < mins[0]){
			mins[1]=mins[0];
			bel[1]=bel[0];
			bel[0]=i;
			mins[0]=tmax[i];
		}else if(!bel[1]||tmax[i] < mins[1]){
			bel[1]=i;
			mins[1]=tmax[i];
		}
		sort(a[i]+1,a[i]+1+m,cmp1);
		for(int j = 1; j <= m; j++){
			tmin[i]+=char(a[i][j]);
		}
	}
	for(int cur = 1; cur <= n; cur++){
		bool flag = 1;
		if(cur!=bel[0]){
			if(tmin[cur]>mins[0])flag = 0;
		}else{
			if(tmin[cur]>mins[1])flag = 0;
		}
		if(flag)ans+="1";
		else ans+="0";
	}
	cout << ans;
	return 0;
}