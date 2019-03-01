#include <iostream>
#include <math.h>
using namespace std;

int jumpsearch (int a[], int searched, int n){
	int m = n;
	while (m >=1){
		m = (m/sqrt(n));  
		for (int i = 0; a[i] <= searched ; i = i + m){
			if (a[i] == searched){
				return i;
			}
		}
	}
	return -1;
}
int main() {
	// your code goes here
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int arrsize= sizeof(a)/(sizeof(a[0]));
	int pos;
	int ele = 7;
	pos = jumpsearch(a,ele,arrsize);
	if(pos == -1){
		cout<<"\n not found";
	}
	else {
		cout <<"\n position of "<<ele<<"  is :"<<pos;
	}
	return 0;
}
