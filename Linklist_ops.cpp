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
        cout << "\n The position is "<<counter;
        current = current->next;
        cout<<"\n Data is "<<current->data;
        cout <<"\n |";
        cout <<"\n |";
        cout <<"\n V";
    }
    return ++counter;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to print linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void ll_print(struct node *head){
    int counter = 0;
    struct node *current = head;
    while(current->next != NULL){
        counter++;
        cout << "\n The position is "<<counter;
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
struct node* Init_ll(){
    struct node * ll_head;
	int value1 = 3;
	int option =0;
	int value,entry_pos;
    cout <<"\n The value that goes in the head is "<<value1;
	ll_head = get_node(value1);

    while (option !=1){
        cout <<"\n enter the value you want to enter";
    	cin >> value;
        entry_pos = ll_size(ll_head);
        entry_pos++;
    	ll_insert(&ll_head,value,entry_pos);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        cout<<"\n Enter  1 to quit";
        cin>> option;
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    }
    ll_print(ll_head);
    return ll_head;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to delete entry in the linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void ll_delete(struct node **head, int position){
    int k = 1;
    struct node *p, *q;
    if (*head == NULL){
        cout <<"\n  The List from which you are trying to delete is empty";
        return;
    }
    else {
        p = *head;
        //deletion from the first entry in the linked list
        if (position == 1){
            *head  = p->next;
            free(p);
            return;
        }
        else {
            //Traverse to the position of the linked list where we want to delete element
            while (p != NULL && k < position){
            k++;
            q = p;
            p = p->next;
            }
            if (p == NULL) {
                // We are at the end
                cout << "\n The position does not exist";
                return;
            }
            else{
                // We have reached the position
                q->next = p->next;
                free(p);
                return;
            }

        }
    }

}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to drive deletion in the linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Delete_ll_init(struct node *head){
	int option =0;
	int delete_pos;
    while (option !=1){
        cout <<"\n enter the position you want to delete";
    	cin >> delete_pos;
    	ll_delete(&head,delete_pos+1);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        cout<<"\n Enter  1 to quit";
        cin>> option;
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout <<"\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    }
    ll_print(head);

}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to search entry within linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int ll_search(struct node *head){
    int data,found = 0;
    int option =0;
    while (option !=1){
        cout << "\n Enter the data you want to searched";
        cin>> data;
        int counter = 0;
        struct node *current = head;
        while(current!= NULL){
                if(current->data == data){
                    found = 1;
                    cout << "\n The position is "<<counter;
                    cout <<"\n||||||||||||||||||||||||||||||||||||||||||||||||| |";
                    return ++counter;
                }
            current = current->next;
            counter++;
        }
        if (found == 0){
            cout <<"\n Sorry the entry does not exist";
            return  -1;
        }
        cout <<"\n Press 1 to quit";
        cin >> option;
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to clear linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void full_ll_delete(struct node **head){
    struct node  *iter, *aux_node;
    iter = *head;
    while(iter != NULL){
    aux_node = iter;
    iter = iter->next;
    free(aux_node);
    }
    *head = NULL;
    ll_print(*head);
}
int main() {
	// your code goes here
	struct node* head;
	int srchd_postion;
    head = Init_ll();
    Delete_ll_init(head);
    srchd_postion = ll_search(head);
    full_ll_delete(&head);
	return 0;
}

