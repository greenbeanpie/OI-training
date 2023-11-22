 #include<bits/stdc++.h>
 using namespace std;
 int n,m;
 char s[3010][3010];
 int id1,id2;
 bool compdd(char *s1,char * s2){
 	for(int i=m-1;i>=0;i--){
 		if(s1[i]<s2[i])return 1;
	}
	return 0;
 }
 bool compsd(char* s1,char* s2){
 	for(int i=0;i<m;i++){
 		if(s1[i]<s2[m-1-i])return 1;
	 }
	 return 0;
 }
 int main(){
 	freopen("dict.in","r",stdin);
 	freopen("dict.out","w",stdout);
 	scanf("%d%d",&n,&m);
 	if(n==1){
 		printf("1");
 		return 0;
	 }
 	for(int i=1;i<=n;i++){
 		scanf("%s",s[i]);
 		sort(s[i],s[i]+m);
 		if(id1==0||compdd(s[i],s[id1])){
 			id2=id1;id1=i;
		}
		else if(id2==0||compdd(s[i],s[id2])){
			id2=i;
		}
	 }
 	for(int i=1;i<=n;i++){
 		bool t=0;
 		if(i!=id1){
 			t=compsd(s[i],s[id1]);
		 }
		 else{
		 	t=compsd(s[i],s[id2]);
		 }
		 if(t)putchar('1');
		 else putchar('0');
	 }
 	return 0;
 }