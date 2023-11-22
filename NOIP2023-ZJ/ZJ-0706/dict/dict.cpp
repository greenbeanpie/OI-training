//8:41 kai map ji lu mei ge zi fu chu xian de ci shu
//bi jiao zui xiao zi dian xu he zui da zi dian xu ji ke
//9:40 tu ran fa xian freopen hao xiang gua diao le yi zhi dao bi sai jie shu 
//dou bu zhi dao zen me hui shi
//tiao le hao jiu mei tiao chu lai bu zhi dao hui bu hui gua
//10:00 fang qi le ba T3 te shu xing zhi xie le
//10:20 kai shi xie T2 de te shu xing zhi he bao sou
//dui yu ce shi dian 1 he 3 ke yi ba lu jing ji lu xia lai
//11:30 T2 bao sou da chu lai le, dan wei shen me zui hou yi ge dian gua le?
//12:00 tu ran fa xian freopen hao xiang gua diao le 
#include<bits/stdc++.h>
using namespace std;
const int N=3005;
string str[N];
int n,m;
int cnt[N][N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>str[i];
		for(int j=0;j<m;j++){
			cnt[i][str[i][j]-'a'+1]++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=26;j++){
//			printf("%d ",cnt[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int p=1,q=26,firp=-1,firq=-1;
			while(p<=26 && q>=1){
				if(!cnt[i][p]) p++;
				if(!cnt[j][q]) q--;
				if(cnt[i][p]) firp=p;
				if(cnt[j][q]) firq=q;
				if(firp!=-1 && firq!=-1) break;
				//printf("%d %d\n",p,q);
			}
			//printf("%d %d\n",firp,firq);
			if(firq<=firp){
				flag=false;
				break;
			}
			
		}
		cout<<flag;
	}
	return 0;
}
//4 7
//abandon
//bananaa
//baannaa
//notnotn

