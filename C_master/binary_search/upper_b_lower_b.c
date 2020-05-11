#include <stdio.h>

int upper_bound(int *aa, int n, int x) {
    
    int low = 0;
    int high = n; // Not n - 1
    
    while (low < high) {
        
        int mid = low + (high - low) / 2;
        if (x >= aa[mid]) {
            low = mid + 1;
        }
        
        else{
            high = mid;
        }
    }
    return low;
}

int lower_bound(int *aa, int n, int x) {
   
    int low = 0;
    int high = n; // Not n - 1
    
    while (low < high){
        
        int mid = low + (high - low) / 2;
        if (x <= aa[mid]){
            high = mid;
        }

        else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
	int a[10];
	int i, b;
	
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}

	//sort before doing this
	
	for(i = 0; i < 3; i++){
		scanf("%d", &b);
		printf("%d %d\n", lower_bound(a, 10, b), upper_bound(a, 10, b));
	}	

}