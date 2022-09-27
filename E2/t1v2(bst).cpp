#include<stdio.h>
#include<stdlib.h>

struct node{
	int dat;
	struct node *chl;
	struct node *chr;
	struct node *par;
};

struct node *root = NULL;
int cnt = 0;

struct node *create(int dat){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->dat = dat;
	newNode->chl = newNode->chr = newNode->par = NULL;
	return newNode;
}

void insert(int dat){
	struct node *p = create(dat);
	if(root == NULL){
		root = p;
	}else{
		struct node *pt = root;
		while(pt != NULL){
			if(dat < pt->dat){
				if(pt->chl == NULL){
					pt->chl = p;
					pt->chl->par = pt;
					return;
				}else{
					pt = pt->chl;
				}
			}else if(dat >= pt->dat){
				if(pt->chr == NULL){
					pt->chr = p;
					pt->chr->par = pt;
					return;
				}else{
					pt = pt->chr;
				}
			}
		}
	}
	cnt++;
}

struct node *findMin(struct node *p){
	while(p->chl != NULL){
		p = p->chl;
	}
	return p;
}

void delMin(struct node *p){
	while(p->chl != NULL){
		p = p->chl;
	}
	
}

struct node *find(int dat){
	struct node *p = root;
	while(p!=NULL){
		if(dat < p->dat){
			p = p->chl;
		}else if(dat > p->dat){
			p = p->chr;
		}else{
			return p;
		}
	}
	return NULL;
}

void del(int dat){
	struct node *p = find(dat);
	if(p==NULL){
		return;
	}
	if(p->chl!=NULL && p->chr!=NULL){
		struct node *pmin = findMin(p);
		p->dat = pmin->dat;
		p = pmin;
	}
	struct node *pch;
	if(p->chl != NULL){
		pch = p->chl;
	}else{
		pch = p->chr;
	}
	if(pch != NULL){
		pch->par = p->par;
	}
	if(p->par == NULL){
		root = pch;
	}else if(p == p->par->chl){
		p->par->chl = pch;
	}else{
		p->par->chr = pch;
	}
	cnt--;
}

void dfs(struct node *p){
	if(p==NULL){
		return;
	}
	dfs(p->chl);
	printf("%d ", p->dat);
	dfs(p->chr);
}

int main(){
	int op, x, n;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &op);
		switch (op) {
			case 1:
				scanf("%d", &x);
				insert(x);
				break;
			case 2:
				del(findMin(root)->dat);
				break;
			case 3:
				printf("%d\n", findMin(root)->dat);
				break;
			case 4:
				scanf("%d", &x);
				del(x);
			default:
				break;
		}
	}
	dfs(root);
	return 0;
} 
