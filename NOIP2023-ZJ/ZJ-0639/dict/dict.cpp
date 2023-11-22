#include<bits/stdc++.h>
using namespace std;


bool cmp1(char a,char b){
	return a<b;
}
bool cmp2(char a,char b){
	return a>b;
}

int n,m;
char yang[3009];
char s[3009];
string stmp;
string smin[3009];
struct mmm{
	string s1;
	int yuanshen;
}smaxsort[4];

bool cmp3(mmm s11,mmm s22){
	return s11.s1<s22.s1;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		yang[i]='z';
	smaxsort[1].s1=smaxsort[2].s1=yang;
	
	for(int i=1;i<=n;i++){
		cin>>s;
		sort(s,s+m,cmp1);
		smin[i]=s;
		sort(s,s+m,cmp2);
		if(s<smaxsort[1].s1){
			smaxsort[1].s1=s;
			smaxsort[1].yuanshen=i;
		}else if(s<smaxsort[2].s1){
			smaxsort[2].s1=s;
			smaxsort[2].yuanshen=i;
		}
		
	}
	sort(smaxsort+1,smaxsort+3,cmp3);
	for(int i=1;i<=n;i++){
		if(smaxsort[1].yuanshen!=i){
			if(smin[i]<smaxsort[1].s1)
				printf("%c",'1');
			else 
				printf("%c",'0');
		}
		else{
			if(smin[i]<smaxsort[2].s1)
				printf("%c",'1');
			else
				printf("%c",'0');
		}
			
		
	}
	return 0;
}
/*

4 7
abandon
bananaa
baannaa
notnotn
*/
