#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+10;
int n,m;
string s[maxn];
string mins[maxn]; // ͨ��һ�β������ܴﵽ����С�ַ��� 
string maxs[maxn];
bool cmp(char x,char y){
	return x>y;
} 
int main(){
	freopen("dict.in","r",stdin); // !!!!!!!!!!!
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	// ==============����mins============== 
	for(int i=1;i<=n;i++){
//		string sorted=s[i];
//		sort(sorted.begin(),sorted.end());
//		if(sorted!=s[i]){ 
//			int j=0;
//			for(;j<m;j++){
//				if(s[i][j]!=sorted[j]){
//					break;
//				}
//			}
//			for(int k=m-1;k>j;k--){
//				if(s[i][k]==sorted[j]){
//					string scopy=s[i];
//					swap(scopy[k],scopy[j]);
//					mins[i]=scopy;
//					break;
//				}
//			} 
//		}else{
//			mins[i]=s[i];
//		}
		int cnt[30]={};
		for(int j=0;j<m;j++){
			cnt[s[i][j]-'a']++;
		}
		int minc;
		for(int i=0;i<='z'-'a';i++){
			if(cnt[i]){
				minc=i;
				break;
			}
		}
		bool flag=1;
		for(int j=0;j<m;j++){
//			cout<<"j="<<j<<" minc="<<minc<<endl;
			if(s[i][j]-'a'==minc){
				cnt[minc]--;
				if(cnt[minc]==0){
					// Ѱ����һ����С�ַ�
					for(;minc<='z'-'a';minc++){
						if(cnt[minc]){
							break;
						}
					} 
				} 
			}else{
//				cout<<"[DEBUG]\n";
				// �����бȵ�ǰλ�ø�С���ַ���
				for(int k=m-1;k>j;k--){
					if(s[i][k]-'a'==minc){
						flag=0;
						string scopy=s[i];
						swap(scopy[k],scopy[j]);
						mins[i]=scopy;
						break;
					}
				} 
				if(!flag){
					break;
				}
			}
		}
		if(flag){
			mins[i]=s[i];
		}
//		cout<<mins[i]<<endl;
	}
	// =================����maxs================= 
	for(int i=1;i<=n;i++){
		int cnt[30]={};
		for(int j=0;j<m;j++){
			cnt[s[i][j]-'a']++;
		}
		int minc;
		for(int i='z'-'a';i>=0;i--){
			if(cnt[i]){
				minc=i;
				break;
			}
		}
		bool flag=1;
		for(int j=0;j<m;j++){
			if(s[i][j]-'a'==minc){
				cnt[minc]--;
				if(cnt[minc]==0){
					for(;minc>=0;minc--){
						if(cnt[minc]){
							break;
						}
					} 
				} 
			}else{
				for(int k=m-1;k>j;k--){
					if(s[i][k]-'a'==minc){
						flag=0;
						string scopy=s[i];
						swap(scopy[k],scopy[j]);
						maxs[i]=scopy;
						break;
					}
				} 
				if(!flag){
					break;
				}
			}
		}
		if(flag){
			maxs[i]=s[i];
		}
	}
	// ��ȡ��һС�ĺ͵ڶ�С��
	string min_str=min(maxs[1],maxs[2]),min2_str=max(maxs[1],maxs[2]);
	for(int i=3;i<=n;i++){
		if(maxs[i]<min_str){
			min2_str=min_str;
			min_str=maxs[i];
		}else if(maxs[i]<min2_str){
			min2_str=maxs[i];
		}
	}
//	cout<<min_str<<endl;
	// �����
	string ans_str="";
	for(int i=1;i<=n;i++){
		if(maxs[i]==min_str){
			ans_str+="1";
//			if(mins[i]<min2_str){
//				cout<<"1";
//			}else{
//				cout<<"0";
//			}
		}else{
			if(mins[i]<min_str){
//				cout<<"1";
				ans_str+="1";
			}else{
//				cout<<"0";
				ans_str+="0";
			}
		}
	} 
	cout<<ans_str;
	return 0;
}
