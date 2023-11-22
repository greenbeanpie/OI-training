#include<bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int st[30];
char op[N];
char opma[N][N], opmi[N][N];
char opm[3][N];
int n, m;

bool cmp(char a[], char b[]){
    for(int i = 0; i < m; i++)
        if(int(a[i]) < int(b[i])) return true;
        else if(int(a[i]) > int(b[i])) return false;
    return true;
}

void qul(char a[], char b[]){
    for(int i = 0; i < m; i++)
        a[i] = b[i];
}

int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);

    
    scanf("%d%d", &n, &m);
  
    for(int i = 0; i < n; i++){
        scanf("%s", op);
        for(int j = 0; j < m; j++)
            st[op[j] - 'a']++;
        int len1 = 0, len2 = m - 1;
        for(int j = 0; j < 26; j++){
            
            while(st[j]){
			 	opmi[i][len1++] = char(j + 'a');
			 	opma[i][len2--] = char(j + 'a');
			 	st[j] --;
			}
        }
    }

    if(!cmp(opma[0], opma[1])){
        qul(opm[0], opma[1]);
        qul(opm[1], opma[0]);
    }else {
        qul(opm[0], opma[0]);
        qul(opm[1], opma[1]);
    }
    
    for(int i = 2; i < n; i++)
        if(cmp(opma[i], opm[0])){
            qul(opm[1], opm[0]);
            qul(opm[0], opma[i]);
        }else if(cmp(opma[i], opm[1])){
            qul(opm[1], opma[i]);
        }

    for(int i = 0; i < n; i++){
        if(cmp(opmi[i], opm[0]) && cmp(opmi[i], opm[1]))  
            printf("1");
        else 
            printf("0");
    }
    return 0;
}
