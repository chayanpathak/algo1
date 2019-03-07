#include <iostream>
#include <math.h>
using namespace std;
void swapper (int first, int second){
    int temp;
    temp = second;
    second = first;
    first = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if (arr[j] < pivot) {
            i++;
            swap(arr[j],arr[i]);
        }
        i++;
        swap(pivot,arr[i]);
        return i;
    }
}
void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int part;
        part = partition(arr,low,high);
        quicksort(arr,low,part-1);
        quicksort(arr,part+1,high);
    }
}
int main() {
	// your code goes here
	int a[] = {10,1,2,11,4,57,12,13,44,14,6,7,9,8,15,16,17,98};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	quicksort(a,0,arrsize);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
		//cout<<"\n"<<arrsize;
	}
	return 0;
}
