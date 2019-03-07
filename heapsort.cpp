#include <iostream>
#include <math.h>
using namespace std;
void swapper (int first, int second){
    int temp;
    temp = second;
    second = first;
    first = temp;
}
void heapify (int a[], int size, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if ((a[largest] < a[left]) && (left < size)) {
            largest = left;
        }
        if ((a[largest] < a[right]) && (right < size)) { 
            largest = right;
        }
        if (largest != i){
            swap(a[i],a[largest]);
            heapify(a,size,largest);
        }
    for(int j = 0; j < size; j++) {
        cout <<"\t"<<a[j];
    }
}
void heapsort(int a[], int size){
    for(int i = (size/2)-1; i >= 0; i-- ) {
        heapify(a,size,i);  
    }
    for(int i = size - 1; i >= 0; i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }

}
int main() {
	// your code goes here
	int a[] = {10,1,2,11,4,57,12,13,44,14,6,7,9,8,15,16,17,98};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	heapsort(a,arrsize);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
		//cout<<"\n"<<arrsize;
	}
	return 0;
}
