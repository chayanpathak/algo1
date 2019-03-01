#include <iostream>
#include <math.h>
using namespace std;
 
void selectionsort(int a[], int n){
	int temp;
	for (int i = 0; i < n; i++){
		for(int j= i+1; j < n; j++){
			if(a[j] < a[i]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
} 
int main() {
	// your code goes here
	int a[] = {10,1,2,11,4,57,989,12,13,44,14,6,7,9,8,15,16,17};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	selectionsort(a,arrsize);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
	}
	return 0;
}
