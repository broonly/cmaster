#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void srand_(){
	struct timeval tv;
 
	gettimeofday(&tv , NULL);
	srand(tv.tv_sec ^ tv.tv_usec);
}
 
int rand_(int n){
	return (rand() * 76543LL + rand()) % n;
}
 
int compare(void const *a, void const *b){
 
	int ia = *(int *) a;
	int ib = *(int *) b;
 
	return ia - ib;
}
 
void sort(int *aa , int n){
 
	for(int i = 0;i < n; i++){
		int j = rand_(i + 1) , tmp;
		tmp = aa[i] , aa[i] = aa[j] , aa[j] = tmp;
	}
 
	qsort(aa , n , sizeof *aa , compare);
}

int main(){
	
	srand_();

	int a[10];
	int i;
	
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}

	sort(a, 10);

	for(i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}

}