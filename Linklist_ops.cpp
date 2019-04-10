#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
};
int link_list_size(struct node *head){
    int counter = 0;
    struct node *current = head;
    while(current->next != NULL){
        counter++;
        cout << "\n"<<counter;
        current = current->next;
    }
    return counter;
}
void link_list_print(struct node *head){
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    int counter = 0;
    struct node *current = head;
    cout <<"\n The data of the node is "<<current->data;
    cout<<"\n"<<current->next;
    while(current->next != NULL){
        cout<<"\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        counter++;
        cout <<"\n The node number is: "<<counter;
        cout <<"\n The data of the node is "<<current->data;
        current = current->next;
        cout<<"\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    }
}
void link_list_insert(struct node *head,int data, int position){
    int k = 1;
    struct node *new_node, *p, *q;
    cout << "\n creating new node";
    new_node = (node *)malloc(sizeof(struct node));
    cout << "\n created new node";
    if(!new_node){
        cout << "No space error in creating new entry";
        return;
    }
    new_node->data = data;
    cout << "\n assigned the data to new node";
    p = head;
    if (position == 1){
        new_node->next = p;
        head = new_node;
    }
    else{
            // Traverse till we go to the position we want to insert
        if(p != NULL && k < position){
            k++;
            q = p;
            p = p->next;
        }
        q->next = new_node;
        new_node->next = p;
    }
}
void Initialize_link_list(){
    node *head = NULL;
    head = new node();
    int option = 0;
    int entry_position;
    int data;
    while(option != 1){
        cout << "\n Enter 1. to quit";
        cin >> option;
        if(option != 1){
            entry_position = link_list_size(head);
            entry_position++;
            cout << "\n entry_position"<<entry_position;
            cout <<"\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
            cout << "\n Enter the data";
            cin >> data;
            cout << "\n data entered"<<data;
            cout <<"\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
            link_list_insert(head,data,1);
        }
    }
    link_list_print(head);
}
int main() {
	// your code goes here
	Initialize_link_list();
	return 0;
}
