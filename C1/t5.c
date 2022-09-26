#include<stdio.h>
#include<string.h>
int tireNum;

struct tireTree{
	int next[26];
	int a[3];
}tire[500005];

void insert(char s[], int num){
	int p = 0, lens = strlen(s);
	for(int i=0;i<lens;i++){
		if(tire[p].next[s[i]-'a'] == 0){
			tire[p].next[s[i]-'a'] = ++tireNum;
		}
		p = tire[p].next[s[i]-'a'];
	}
	tire[p].a[num] = 1;
}

void clean(){
	for(int i=0;i<=tireNum;i++){
		for(int j=0;j<26;j++){
			tire[i].next[j] = 0;
		}
		for(int j=0;j<3;j++){
			tire[i].a[j] = 0;
		}
	}
	tireNum = 0;
}

int getScore(int sum){
	if(sum == 1){
		return 3;
	}else if(sum == 2){
		return 1;
	}
	return 0;
}

int main(){
	int t;
	char s[10];
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		int n, score[3] = {0, 0, 0};
		scanf("%d", &n);
		for(int j=0;j<3;j++){
			for(int k=0;k<n;k++){
				scanf("%s", s);
				insert(s, j);
			}
		}
		for(int k=0;k<=tireNum;k++){
			int sum = 0;
			for(int j=0;j<3;j++){
				sum += tire[k].a[j];
			}
			for(int j=0;j<3;j++){
				if(tire[k].a[j] == 1){
					score[j] += getScore(sum);
				}
			}
		}
		for(int j=0;j<3;j++){
			printf("%d ", score[j]);
		}
		printf("\n");
		clean();
	}
	return 0;
}
