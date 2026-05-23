#include <bits/stdc++.h>
using namespace std;
#define MAX 120
typedef char* C;
typedef int len;
typedef struct{
C Name;
C MSSV;	
}SV;
typedef struct{
SV A[MAX];
len last;	
}ListSV;
int endlist(ListSV pL){
	return pL.last+1;
}
void makenulllist(ListSV *pL){
	pL->last=0;
}
bool emptylist(ListSV L){
	if(L.last==0) return 1;
	return 0;
}
void insertlist(SV x,int p,ListSV *pL){
	if(pL->last==MAX){
		printf("DS full");
	}
	else{
		if(p<1 || p>pL->last+1){
			printf("Vi tri ko hop le");
		}
		else{
			for(int R=pL->last;R>p-1;R--){
				pL->A[R]=pL->A[R-1];
			}
			pL->A[p-1]=x;
			pL->last++;
		}
	}
}
void deletelist(int p,ListSV *pL){
	if(p>pL->last || p<1){
		printf("Vi tri ko hop le");
	}
	else{
		free(pL->A[p - 1].Name);
        free(pL->A[p - 1].MSSV);
		for(int L=p-1;L<pL->last-1;L++){
			pL->A[L]=pL->A[L+1];
		}
		pL->last--;
	}
}
int locatelist(C mssv,ListSV *pL){
	for(int L=1;L<=pL->last;L++){
		if(strcmp(pL->A[L-1].MSSV,mssv)==0) return L;
	}
	return pL->last+1;
}
C retrievelist(int p,ListSV pL){
	if(p<1 || p>pL.last) return NULL;
	return pL.A[p-1].MSSV;
}
int nextlist(int p,ListSV L){
	if (p < 1 || p > L.last){
        return endlist(L);
}
	return ++p;
}
int previouslist(int p,ListSV L){
	if(p<2 || p>L.last){
		return endlist(L);
	}
	return --p;
}
int firstlist(ListSV L){
	if(L.last==0) return endlist(L);
	return 1;
}
ListSV nhapDSSV(){
	ListSV L;
	makenulllist(&L);
	printf("Nhap so luong sinh vien: ");
	int n;scanf("%d",&n);
    while(getchar() != '\n');
	while(n>0){
		SV svdonle;
		printf("\nNhap ten sinh vien: ");
		char ten[500];
		fgets(ten,500,stdin);
		ten[strcspn(ten, "\n")] = '\0';
		svdonle.Name=(char*)strdup(ten);
		printf("Nhap MSSV: ");
		char mssv[500];
		fgets(mssv,500,stdin);
		mssv[strcspn(mssv, "\n")] = '\0';
		svdonle.MSSV=(char*)strdup(mssv);
		n-=1;
		insertlist(svdonle,L.last+1,&L);
	}
	return L;
}
void printlist(ListSV L){
	for(int i=1;i<=L.last;i++){
		printf("Ho va ten : %s\n",L.A[i-1].Name);
		printf("MSSV : %s\n",L.A[i-1].MSSV);
	}
}
int main (){
ListSV MyList = nhapDSSV();
    printlist(MyList);
    
    if (!emptylist(MyList)) {
        char mssv_can_tim[50];
        printf("\nNhap MSSV sinh vien can xoa: \n");
        scanf("%49s", mssv_can_tim);
        
        int vitri = locatelist(mssv_can_tim, &MyList);
        
        if (vitri != endlist(MyList)) {
            printf("-> Tim thay sinh vien tai vi tri: %d. Dang tien hanh xoa...\n", vitri);
            deletelist(vitri, &MyList);
            printlist(MyList);
        } else {
            printf("-> Khong tim thay sinh vien co MSSV %s trong danh sach!\n", mssv_can_tim);
        }
    }

    for (int i = 0; i < MyList.last; i++) {
        free(MyList.A[i].Name);
        free(MyList.A[i].MSSV);
    }
  return 0;
}

