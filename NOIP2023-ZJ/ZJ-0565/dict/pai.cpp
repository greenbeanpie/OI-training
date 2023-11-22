#include<bits/stdc++.h>
int n, m;
int main() {
	for(; ;) {
		system("./data");
		system("./baoli");
		system("./dict");
		if(system("diff baoli.out dict.out")) return puts("WA"), 0;
		puts("AC");
	}
    
    return 0;
}
