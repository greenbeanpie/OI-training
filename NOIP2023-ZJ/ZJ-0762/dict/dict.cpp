#include<bits/stdc++.h>
using namespace std;
//#define int long long
void file(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
}
bool cmp(char a,char b){
	return a>b;
}// I think the data of CCF 
//Water 
//please give me 100 pts + 60pts + 10pts +8pts=178pts
//Genshin Impact
//freopen
//dict1.in 
int a[27];
string kcm[3010],op[3010],b[3010];
//char op[3010][3010],b[3010][3010];
int minn=0x3f3f3f3f;
signed main(){
    file();
    int n,m;
    cin>>n>>m;
    if(n==1){
        cout<<1;
		return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
        	char ch;
            cin>>ch;
            a[i]=ch-'a'+1;
            minn=min((int)(ch-'a'+1),minn);
        }
        for(int i=1;i<=n;i++){
        	if(a[i]==minn){
        		cout<<1;
			}
			else{
				cout<<0;
			}
		}
        return 0;
    }
    else{
    	for(int i=1;i<=n;i++){
    		cin>>kcm[i];
    		op[i]=b[i]=kcm[i];
			sort(op[i].begin(),op[i].end(),cmp);
		}
		sort(op+1,op+1+n);
//        for(int i=1;i<=n;i++){
//            cout<<op[i]<<endl;
//        }
//        cout<<endl;
		for(int i=1;i<=n;i++){
			sort(b[i].begin(),b[i].end());
//			cout<<b[i]<<'\n'<<op[i]<<endl;
//			cout<<endl;
			if(b[i]>op[1])
			{
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
	}
}
