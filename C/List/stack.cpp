#include <bits/stdc++.h>
using namespace std;
typedef struct{
int elements[10];
int top;
}Stack;
void makenullstack(Stack *A){
	A->top=-1;
}
int fullstack(Stack A){
	if(A.top==10-1) return 1;
	return 0;
}
int emptystack(Stack A){
	if(A.top==-1) return 1;
	return 0;
}
void pushstack(int x,Stack *A){
if(!fullstack(*A)){
	A->top++;
	A->elements[A->top]=x;
    }
else{
	printf("ERROR");
    }
}
void popstack(Stack *A){
	if(!emptystack(*A)){
		A->top--;
	}
	else{
		printf("ERROR");
	}
}
int topstack(Stack A){
	if(!emptystack(A)){
		return A.elements[A.top];
	}
	else{
		printf("ERROR");
	}
}

int main (){
Stack S;
makenullstack(&S);
int n;scanf("%d",&n);
if(n==0) printf("%d",0);
while(n>0){
pushstack(n%2,&S);
n=n/2;
}
while(S.top>=0){
	printf("%d",S.elements[S.top]);
	popstack(&S);
}

  return 0;
}

