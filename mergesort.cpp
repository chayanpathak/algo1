#include <iostream>
#include <math.h>
using namespace std;
void print(int a[], int size) {
    cout <<"\n";
    for (int i = 0; i < size; i++) {
        cout << a[i];
    }
}
void merge(int a[], int left, int mid, int right) {
    int length1 = mid - left + 1;
    int length2 = right - mid;
    int k = left;
    int b[length1],c[length2];
    for (int i = 0; i < length1; i++ ) {
        b[i] = a[i + left];
    }
    for (int j = 0; j < length2; j++ ) {
        c[j] = a[j + mid + 1];
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
    if (left < right) {
        int mid = (left + right)/2;
        int size = (right - left)/2;
        mergesort(a,left,mid);
        mergesort(a,mid + 1,right);
        merge(a,left,mid,right);
    }
} 
int main() {
	// your code goes here
	int a[] = {10,1,2,11,4,57,12,13,44,14,6,7,9,8,15,16,17,98};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	mergesort(a,0,arrsize-1);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
		//cout<<"\n"<<arrsize;
	}
	return 0;
}
