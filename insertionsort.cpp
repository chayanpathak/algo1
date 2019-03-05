#include <iostream>
#include <math.h>
using namespace std;
 
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
	insertionsort(a,arrsize);
	for (int i = 0; i < arrsize; i++){
		cout <<"\n "<<a[i];
		//cout<<"\n"<<arrsize;
	}
	return 0;
}
