#include<stdlib.h>
#include<stdio.h>
typedef struct node{
	int key;
	struct node *left;
	struct node *right;
};
typedef struct node* tree;
tree makenulltree(int x){
	tree T=(tree)malloc(sizeof(struct node));
	T->key=x;
	T->left=NULL;
	T->right=NULL;
	return T;
}
int emptytree(tree n){
	return n==NULL;
}
int leaf(tree n){
	if(n!=NULL){
		if(n->left==NULL && n->right==NULL) return 1; 
	}
	return 0;
}
void preorder(tree n){
	if(n!=NULL){
		printf("%d ",n->key);
	}
	else{
		return; 
	}
	if(n->left!=NULL){
		preorder(n->left);
	}
	if(n->right!=NULL){
		preorder(n->right);
	}
}
void inorder(tree n) {
    if (n == NULL) return;
    inorder(n->left);
    printf("%d ", n->key);
    inorder(n->right);
}
int sonuttree(tree n){
	if(n==NULL) return 0;
	else{
		return 1 + sonuttree(n->left) + sonuttree(n->right);
	}
}
tree createtree(int x,tree l,tree r){
	tree T=makenulltree(x);
	T->left=l;
	T->right=r;
	return T;
}
void inserttree(int x, tree *n){
	if((*n==NULL)){
		*n=makenulltree(x);
		return;
	}
	if((*n)->key==x){
		return;
	}
	else{
		if(x>(*n)->key){
			inserttree(x,&(*n)->right);
		}
		if(x<(*n)->key){
			inserttree(x,&(*n)->left);
		}
	}
}
int deletemax(tree *n){
	if((*n)==NULL) return -1;
	if((*n)->right!=NULL){
		deletemax(&((*n)->right));
	}
	else{
		tree t=*n;
		int k=(*n)->key;
		(*n)=(*n)->left;
		free(t);
		return k;
	}
}
void deletex(int x,tree *n){
	if((*n)!=NULL){
		if(x>(*n)->key) deletex(x,&((*n)->right));
		if(x<(*n)->key) deletex(x,&((*n)->left));
		if(x==(*n)->key){
			if(leaf(*n)){
				struct node *temp=*n;
				(*n)=NULL;
				free(temp);
			}
			else if((*n)->left==NULL){
				struct node *temp=*n;
				(*n)=(*n)->right;
				free(temp);
			}
			else if((*n)->right==NULL){
				struct node *temp=*n;
				(*n)=(*n)->left;
				free(temp);
			}
			else if(!(leaf(*n))){
				(*n)->key=deletemax(&((*n)->left));
			}
		}
	}
}


int main (){
tree root = NULL;
    inserttree(45, &root);
    inserttree(25, &root);
    inserttree(65, &root);
    inserttree(15, &root);
    inserttree(35, &root);
    inserttree(55, &root);
    inserttree(75, &root);
    printf("--- KHOI TAO CAY BST ---\n");
    printf("Duyet tien tu (Preorder): ");
    preorder(root);
    printf("\nDuyet trung tu (Inorder): ");
    inorder(root);
    printf("\nTong so nut tren cay: %d\n", sonuttree(root));
    printf("\n--- XOA NUT LA 15 ---\n");
    deletex(15, &root);
    printf("Inorder sau khi xoa 15: ");
    inorder(root);
    printf("\n");
    printf("\n--- XOA NUT CO 2 CON (GOC 45) ---\n");
    deletex(45, &root);
    printf("Inorder sau khi xoa goc 45: ");
    inorder(root);
    printf("\nNut goc hien tai bay gio la: %d\n", root->key);

  return 0;
}

