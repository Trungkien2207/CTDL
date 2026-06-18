#include <bits/stdc++.h>
using namespace std;
typedef struct{
int elements[10];
int front,rear;
}Q;
void makenullqueue(Q *q){
	q->front=-1;
	q->rear=-1;
}
int emptyqueue(Q q){
	if(q.front==-1) return 1;
	return 0;
}
int fullqueue(Q q){
	if(q.rear-q.front==10-1) return 1;
	return 0;
}
void dequeue(Q *q){
if(!emptyqueue(*q)){
	q->front++;
	if(q->front>q->rear) makenullqueue(q);
}
else{
	printf("ERROR");
}
}
void enqueue(int x,Q *q){
if(!fullqueue(*q)){
   if(emptyqueue(*q)) q->front=0;
   if(q->rear==10-1){
   	for(int i=q->front;i<=q->rear;i++){
   		q->elements[i-q->front]=q->elements[i];
	   }
		q->rear=9-q->front;
	q->front=0;
   }
   q->rear++;
   q->elements[q->rear]=x;
}
else{
	printf("ERROR");
}
}
int main (){
Q A;
makenullqueue(&A);
int n;scanf("%d",&n);
while(n>0){
int x;scanf("%d",&x);	
enqueue(x,&A);	
	n--;
}
while(!emptyqueue(A)){
	printf("%d ",A.elements[A.front]);
	dequeue(&A);
}


  return 0;
}

