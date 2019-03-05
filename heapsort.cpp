#include <iostream>
#include <math.h>
using namespace std;
void swapper (int first, int second){
    int temp;
    temp = second;
    second = first;
    first = temp;
}
void heapify (int a[], int size) {
    for(int i = 0; i < (size/2) ; i++) {
        int left = 2*i;
        int right = 2*i + 1;
        if (a[i] < a[left]) {
            swap(a[i], a[left]);
        }
        else if (a[i] < a[right]) { 
            swap(a[i],a[right]);
        }
    }
}
void heapsort(int a[], int size){
    int treesize = size;
    int i = size;
    heapify(a,size);
    while (treesize > 0) {
        cout << " \t " << a[i];
        swap(a[i],a[0]);
        i --;
        treesize--;
        heapify(a, treesize);
    }
    cout <<"\n";
    for(int i = 0; i < size; i++) {
        cout <<"\t"<<a[i];
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
