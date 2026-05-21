#include <bits/stdc++.h>
using namespace std;


int main (){
int n;
scanf("%d",&n);
float tb=0;
int tmp=n;
do{
	float x;
	scanf("%f",&x);
	tb=tb+x;
	n--;
}
while(n>0);
printf("%f",tb/tmp);

  return 0;
}

