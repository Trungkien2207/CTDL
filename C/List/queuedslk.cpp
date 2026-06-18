#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
int elements;
struct Node *Next;
}Node;
typedef struct Node *Position;
typedef struct{
Position front,rear;
}Q;
void makenull(Q *q){
	Position T=(Position)malloc(sizeof(struct Node));
	T->Next=NULL;
	q->front=T;
	q->rear=T;
}
int empty(Q q){
	return q.front==q.rear;
}
void enqueue(int x,Q *q){
Position P=(Position)malloc(sizeof(struct Node));
P->elements=x;
P->Next=NULL;
q->rear->Next=P;
q->rear=P;
	
}
void dequeue(Q *q){
	if(!empty(*q)){
		Position T=q->front;
		q->front=q->front->Next;
		free(T);
	}
}


int main (){
Q q;
    makenull(&q);
    enqueue(10, &q);
    enqueue(20, &q);
    enqueue(30, &q);
    while(!empty(q)){
        printf("%d ", q.front->Next->elements);
        dequeue(&q);
    }

  return 0;
}

