#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct node {
    int data;
    struct node *next;
}
int link_list_size(struct node *head){
    int counter = 0;
    struct node *current = head;
    while(next != NULL){
        counter++;
        current = current->next;
    }
    return count;
}
void link_list_insert(struct node *head,int data, int position){
    int k = 1;
    struct node *new_node, *p, *q;
    new_node = (node *)malloc(sizeof(struct node));
    
    if(!new_node){
        cout << "No space error in creating new entry";
        return;
    }
    new_node->data = data;
    *p = head;
    if (position == 1){
        new_node->next = p;
        *head = new_node;
    }
    else{
        if(p->next != NULL && k < position){
            q = p;
            p = p->next;
            k++;
        }
        q->next = new_node;
        new_node->next = p;
    }
    
}
int main() {
	// your code goes here
	
}