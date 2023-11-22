#include<bits/stdc++.h>
using namespace std;
int n,m;
string w[3005];
string zuixiao[3005],zuida[3005];
string zx(string st){ //jiaohuan st zhongde liangge zifu,suoneng dedao de zuixiao zidianxu
	//ruoyouduoge fuhetiaojian, zhao yuande nage
	char suffixmin[3005];
	for(int i = m-1;i >= 0;i--){
		if(i==m-1) suffixmin[i] = st[i];
		else suffixmin[i] = min(suffixmin[i+1],st[i]);
	}
	for(int i = 0;i <= m-1;i++){
		if(st[i]>suffixmin[i+1]){
			for(int j = m-1;j >= i+1;j--){
				if(st[j]==suffixmin[i+1]){
					swap(st[j],st[i]);
					break;
				}
			}
			break;
		}
	}
	
	return st;
}
string zd(string st){ 
	char suffixmax[3005];
	for(int i = m-1;i >= 0;i--){
		if(i==m-1) suffixmax[i] = st[i];
		else suffixmax[i] = max(suffixmax[i+1],st[i]);
	}
	for(int i = 0;i <= m-1;i++){
		if(st[i]<suffixmax[i+1]){
			for(int j = m-1;j >= i+1;j--){
				if(st[j]==suffixmax[i+1]){
					swap(st[j],st[i]);
					break;
				}
			}
			break;
		}
	}
	return st;
}
int main(){
	#ifndef LOCAL
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> w[i];
		zuixiao[i] = zx(w[i]);
		zuida[i] = zd(w[i]);
	}
	if(n==1){
		cout << 1;
		return 0;
	}
	if(m==1){
		string s = "";
		for(int i = 1;i <= n;i++){
			if(s==""||w[i]<s) s = w[i];
		}
		for(int i = 1;i <= n;i++){
			if(w[i]==s) cout << 1;
			else cout << 0;
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		bool flag = true;
		for(int j = 1;j <= n;j++){
			if(i==j) continue;
			if(zuixiao[i]>=zuida[j]) flag = false;
		}
		if(flag) cout << 1;
		else cout << 0;
	}
	return 0;
}