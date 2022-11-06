#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
using namespace std;
#define MAXN 10000005

char s[MAXN], cnt[55];
int ans = 0;

struct node{
	node* left;
	node* right;
	int weight;
	
	friend bool operator <(const node xx, const node yy){
		return xx.weight<yy.weight;
	}
};

void dfs(node* root, int depth){
	if(root->left==NULL && root->right==NULL){
		ans += root->weight*depth;
		return;
	}
	if(root->left != NULL){
		dfs(root->left, depth+1);
	}
	if(root->right != NULL){
		dfs(root->right, depth+1);
	}
}

int main(){
	scanf("%s", s);
	int lens = strlen(s);
	for(int i=0;i<lens;i++){
		if(s[i]>='a'&&s[i]<='z'){
			cnt[s[i]-'a']++;
		}else{
			cnt[s[i]-'A'+26]++;
		}
	}
	priority_queue <node> q;
	for(int i=0;i<=51;i++){
		node *t = (node*)malloc(sizeof(node));
		t->left = NULL;
		t->right = NULL;
		t->weight = cnt[i];
		q.push(*t);
	}
	for(int i=0;i<51;i++){
		node *t = (node*)malloc(sizeof(node));
		*(t->left) = q.top();
		q.pop();
		*(t->right) = q.top();
		q.pop();
		t->weight = t->left->weight + t->right->weight;
		q.push(*t);
	}
	node *t;
	*t = q.top();
	dfs(t, 0);
	printf("%d", ans);
}
