//Binary search code
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int binsrch(int a[], int low, int high, int element) {
	int mid  = (low + high) / 2;
	if (a[mid] = element){
		return mid;
	}
	else if (a[mid] < element){
		return binsrch(a,mid+1,high,element);
	}
	else if (a[mid] > element){
		return binsrch(a,low,mid-1,element);
	}
	else{
		return -1;
	}
}
int main() {
	// your code goes here
	string a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int low =0;
	int high = a.size();
	int pos;
	int ele = 7;
	pos = binsrch(a,low,high,ele);
	if(pos == -1){
		cout<<"not found";
	}
	else {
		cout <<"position of "<<ele<<"is :"<<pos;
	}
	return 0;
}
