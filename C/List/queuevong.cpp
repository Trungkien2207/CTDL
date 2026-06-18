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
		return q.front==-1;
	}
	int fullqueue(Q q){
		if((q.rear+1-q.front)%10==0) return 1;
		return 0;
	}
	void dequeue(Q *q){
		if(!emptyqueue(*q)){
			if(q->front==q->rear) makenullqueue(q);
			else q->front=(q->front+1)%10;
		}
		else{
			printf("ERROR");
		}
	}
	void enqueue(int x,Q *q){
		if(!fullqueue(*q)){
			if(emptyqueue(*q)) q->front=0;
			q->rear=(q->rear+1)%10;
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

