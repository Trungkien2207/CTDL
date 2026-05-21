#include <bits/stdc++.h>
using namespace std;
#define maxlen 300
typedef int ET;
typedef int Position;
typedef struct{
	ET Element[maxlen];
	Position Last;
}List;
Position firstlist(List pL){
	return 1;
}
Position endlist(List pL){
	return pL.Last+1;
}
void insertlist(ET x,Position p, List *pL){
	if(pL->Last==maxlen){
		printf("Danh sach day");
	}
	else{
		if(p<1 || p>pL->Last+1){
			printf("Vi tri ko hop le");
		}
		else{
			for(Position R=pL->Last;R>p-1;R--){
				pL->Element[R]=pL->Element[R-1];
			}
			pL->Element[p-1]=x;
			pL->Last++;
		}
	}
}
void deletelist(Position p, List *pL){
	if(p>pL->Last || p<1){
		printf("Vi tri ko hop le");
	}
	else{
		for(Position Q=p-1;Q<pL->Last;Q++){
			pL->Element[Q]=pL->Element[Q+1];
		}
		pL->Last--;
	}
}
Position Locatelist(ET x,List *pL){
	for(Position L=1;L<=pL->Last;L++){
		if(pL->Element[L-1]==x) return L;
	}
	return endlist(*pL);
}
ET retrievelist(Position p,List pL){
	if(p<1 || p>pL.Last) return -1000;
	return pL.Element[p-1];
}
Position nextlist(Position p,List L){
	if (p < 1 || p >= L.Last){
        return endlist(L);
    }
	return p+1;
}
Position Previous(Position p, List L){
	if(p<2 || p>L.Last){
		return endlist(L);
	}
	return --p;
}
void makenulllist(List *pL){
	pL->Last=0;
}
bool emptylist(List pL){
	return (pL.Last==0);
}
int main (){


  return 0;
}

