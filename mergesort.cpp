#include <iostream>
#include <math.h>
using namespace std;
void merge(int a[], int left, int mid, int right) {
    int length1 = mid - left + 1;
    int length2 = right - mid;
    int k = left;
    int b[length1],c[length2];
    for (int i = 0; i < length1; i++ ) {
        b[i] = a[i + length1];
    }
    for (int j = 0; j < length2; j++ ) {
        c[j] = a[j + length2];
    }
    int i = 0, j = 0;
    while ((i < length1) && (j < length2)) {
        if (b[i] > c [j]) {
            a[k] = c[j];
            k++;
            j++;
        }
        else if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
            k++;
        }
    }
    while(i < length1) {
        a[k] = b[i];
        i++;
        k++;
    }
    while(j < length2) {
        a[k] = c[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int left, int right) {
    int mid = (left + right)/2;
    int size = (right - left)/2;
    mergesort(a,left,mid-1);
    mergesort(a,mid,right);
    merge(a,size,left,mid);
} 
void insertionsort(int a[], int n){
	int temp;
	for (int i = 0; i < n; i++){
		cout<<"\n";
		for(int k = 0; k < n; k++){
			cout << " "<<a[k];
		}
		for(int j= i; j > 0; j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
} 
int main() {
	// your code goes here
	int a[] = {10,1,2,11,4,57,12,13,44,14,6,7,9,8,15,16,17,98};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	mergesort(a,0,arrsize);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
		//cout<<"\n"<<arrsize;
	}
	return 0;
}
