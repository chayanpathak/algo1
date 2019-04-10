#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
}
int link_list_size(struct Node *head){
    int counter = 0;
    struct Node *current = head;
    while(next != NULL){
        counter++;
        current = current->next;
    }
    return count;
}
void link_list_insert(struct Node *head, struct Node *New_node, int position){
    
}
int main() {
	// your code goes here
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int low =0;
	int high = sizeof(a)/(sizeof(a[0]));
	cout<<high;
	int pos;
	int ele = 7;
	pos = binsrch(a,low,high,ele);
	if(pos == -1){
		cout<<"\n not found";
	}
	else {
		cout <<"\n position of "<<ele<<"  is :"<<pos;
	}
	return 0;
}
