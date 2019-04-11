#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to get size of linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int ll_size(struct node *head){
    int counter = 0;
    struct node *current = head;
    while(current->next != NULL){
        counter++;
        cout << "\n The position "<<counter;
        current = current->next;
        cout<<"\n Data is "<<current->data;
        cout <<"\n |";
        cout <<"\n |";
        cout <<"\n V";
    }
    return counter;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to print linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void ll_print(struct node *head){
    int counter = 0;
    struct node *current = head;
    while(current->next != NULL){
        counter++;
        cout << "\n The position "<<counter;
        current = current->next;
        cout<<"\n Data is "<<current->data;
        //cout <<"\n |";
        //cout <<"\n |";
        //cout <<"\n V";
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to make a new node
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
node* get_node( int data){
    node*  new_node = (node*)malloc (sizeof(node));
    if (!new_node){
        cout <<"\n ERROR : new entry not created ";
    }
    new_node-> data = data;
    new_node->next = NULL;
    return new_node;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to insert new node at specific position
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void ll_insert(struct node **head, int data, int position){
    int k = 1;
    struct node *new_node, *p , *q;
    int size_of_ll = ll_size(*head);
    if ((position > size_of_ll + 1) || (position < 1)){
        cout <<"\n The entered position is invalid";
    }
    else {
    new_node = get_node(data);
    p = *head;
    if (position == 1){
            new_node->next = p;
            *head = new_node;
    }
    else {
        //start traversing to the position where we want to insert
        while(p != NULL && k < position){
            k++;
            q= p;
            p = p->next;
        }
        q->next = new_node;
        new_node->next = p;
    }
    int size_of_ll = ll_size(*head);
    }

    cout <<"\n =======================================================";
    cout <<"\n The size of the linked list is "<<size_of_ll;

}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to make new linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Init_ll(struct node  * head){
    int option = 0;
    int entry_position;
    int data;
}
int main() {
	// your code goes here
	struct node * ll_head;
	int value1 = 3;
	int option =0;
	int value,entry_pos;
	//a->data = 0;
	//a->next = NULL;
	cout <<"\n Enter the value that goes in the head";
	ll_head = get_node(value1);
	ll_head->next = get_node(value1);
	ll_head->next->next = get_node(value1+1);
    ll_head->next->next->next = get_node(value1+2);
    while (option !=1){
        cout <<"\n enter the value you want to enter";
    	cin >> value;
        entry_pos = ll_size(ll_head);
        entry_pos++;
    	ll_insert(&ll_head,value,entry_pos);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        cout<<"\n Enter 1 to quit";
        cin>> option;
    }
    ll_print(ll_head);
	return 0;
}
