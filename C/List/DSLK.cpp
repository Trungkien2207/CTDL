#include <bits/stdc++.h>
using namespace std;
typedef struct Node {
	int E;
	Node *N;
};
typedef Node *Position;
typedef Node *List;
void makenull(List *pL){
	(*pL)=(Node*)malloc(sizeof(Node));
	(*pL)->N=NULL;
}
bool empty(List L){
	return L->N==NULL;
}
int retrieve(Position P,List L){
	if(P->N!=NULL){
		return P->N->E;
	}
}
void insert(int X,Position P, List *pL){
Node *T=(Node*)malloc(sizeof(Node));
T->E=X;
T->N=P->N;
P->N=T;
}
void deletee(Position P, List *pL){
	if(P->N!=NULL){
		Node *Tamp=P->N;
		P->N=Tamp->N;
		free(Tamp);
	}
}
Position first(List L){
	return L;
} 
Position end(List L){
	Position P=first(L);
	while(P->N!=NULL){
		P=P->N;
	}
	return P;
}
Position next(Position P, List L){
return P->N;
}
Position locate(int X,List L){
	Position P=first(L);
	while(P->N!=NULL){
		if(retrieve(P,L)==X) return P;
		else P=next(P,L);
	}
	return P;
}
Position mylocate(int X, int i, List L){
	Position P=first(L);
	while(P->N!=NULL && i>0){
		if(retrieve(P,L)==X) i--;
		if(i>0) P=next(P,L);
	}
	return P;
}
Position previous(Position P, List L){
Position Q;
Q = first(L);
while (next(Q,L)!= NULL){
if (next(Q,L) == P)
    return Q;
else
    Q = next(Q,L);
}
return NULL;
}
void print(List L){
Position P;
P = first(L);
while (P != end(L)){
printf("%d ", retrieve(P,L));
P = next(P, L);
}
printf("\n");
}
List nhap(){
    List L;
    makenull(&L); 
    int value;
    printf("Nhap cac so nguyen cho danh sach (Nhap 0 de KET THUC):\n");
    while (1) {
        printf("Nhap gia tri: ");
        scanf("%d", &value);
        if (value == 0) {
            break; 
        }
        insert(value, end(L), &L);
    }
    return L;
}

int main (){


  return 0;
}

