
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
struct dll_node
{
    int data;
    struct dll_node *next;
    struct dll_node *prev;
};
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to get size of linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int dll_size(struct dll_node *head)
{
    int counter = 0;
    struct dll_node *current = head;
    while (current->next != NULL)
    {
        counter++;
        cout << "\n The position is " << counter;
        current = current->next;
        cout << "\n Data is " << current->data;
        cout << "\n |";
        cout << "\n |";
        cout << "\n V";
    }
    return ++counter;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to print linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void dll_print(struct dll_node *head)
{
    int counter = 0;
    struct dll_node *current = head;
    while (current->next != NULL)
    {
        counter++;
        cout << "\n The position is " << counter;
        current = current->next;
        cout << "\n Data is " << current->data;
        //cout <<"\n |";
        //cout <<"\n |";
        //cout <<"\n V";
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to make a new node
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
dll_node *get_node(int data)
{
    dll_node *new_node = (dll_node *)malloc(sizeof(dll_node));
    if (!new_node)
    {
        cout << "\n ERROR : new entry not created ";
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to insert new node at specific position
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void dll_insert(struct dll_node **head, int data, int position)
{
    int k = 1;
    struct dll_node *new_node, *p, *q;
    int size_of_dll = dll_size(*head);
    if ((position > size_of_dll + 1) || (position < 1))
    {
        cout << "\n The entered position is invalid";
    }
    else
    {
        new_node = get_node(data);
        new_node->prev = NULL;
        p = *head;
        if (position == 1)
        {
            new_node->next = p;
            p->prev = new_node;
            *head = new_node;
            //head->prev = NULL;
            return;
        }
        else
        {
            //start traversing to the position where we want to insert
            while (p->next != NULL && k < position - 1)
            {
                k++;
                q = p;
                p = p->next;
            }
            q->next = new_node;
            new_node->prev = q;
            new_node->next = p;
            p->prev = new_node;
        }
        int size_of_dll = dll_size(*head);
    }

    cout << "\n =======================================================";
    cout << "\n The size of the linked list is " << size_of_dll;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to make new linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct dll_node *Init_ll()
{
    struct dll_node *dll_head;
    int value1 = 3;
    int option = 0;
    int value, entry_pos;
    cout << "\n The value that goes in the head is " << value1;
    dll_head = get_node(value1);

    while (option != 1)
    {
        cout << "\n enter the value you want to enter";
        cin >> value;
        entry_pos = dll_size(dll_head);
        entry_pos++;
        dll_insert(&dll_head, value, entry_pos);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        cout << "\n Enter  1 to quit";
        cin >> option;
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    }
    dll_print(dll_head);
    return dll_head;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to delete entry in the linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void dll_delete(struct dll_node **head, int position)
{
    int k = 1;
    struct dll_node *p, *q;
    if (*head == NULL)
    {
        cout << "\n  The List from which you are trying to delete is empty";
        return;
    }
    else
    {
        p = *head;
        //deletion from the first entry in the linked list
        if (position == 1)
        {
            *head = p->next;
            if (*head != NULL)
            {
                (*head)->prev = NULL;
                free(p);
                return;
            }
        }
        else
        {
            //Traverse to the position of the linked list where we want to delete element
            while (p != NULL && k < position)
            {
                k++;
                q = p;
                p = p->next;
            }
            if (p == NULL)
            {
                // We are at the end
                cout << "\n The position does not exist";
                return;
            }
            else
            {
                // We have reached the position
                struct dll_node *temp;
                temp = p;
                p = p->next;
                q->next = p;
                p->prev = q;
                free(temp);
                return;
            }
        }
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to drive deletion in the linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Delete_dll_init(struct dll_node *head)
{
    int option = 0;
    int delete_pos;
    while (option != 1)
    {
        cout << "\n enter the position you want to delete";
        cin >> delete_pos;
        dll_delete(&head, delete_pos + 1);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
        cout << "\n Enter  1 to quit";
        cin >> option;
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        cout << "\n ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    }
    dll_print(head);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to search entry within linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int dll_search(struct dll_node *head)
{
    int data, found = 0;
    int option = 0;
    while (option != 1)
    {
        cout << "\n Enter the data you want to searched";
        cin >> data;
        int counter = 0;
        struct dll_node *current = head;
        while (current != NULL)
        {
            if (current->data == data)
            {
                found = 1;
                cout << "\n The position is " << counter;
                cout << "\n||||||||||||||||||||||||||||||||||||||||||||||||| |";
                return ++counter;
            }
            current = current->next;
            counter++;
        }
        if (found == 0)
        {
            cout << "\n Sorry the entry does not exist";
            return -1;
        }
        cout << "\n Press 1 to quit";
        cin >> option;
    }
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//Module to clear linked list
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void full_dll_delete(struct dll_node **head)
{
    struct dll_node *iter, *aux_node;
    iter = *head;
    while (iter != NULL)
    {
        aux_node = iter;
        iter = iter->next;
        free(aux_node);
    }
    *head = NULL;
    dll_print(*head);
}
int main()
{
    // your code goes here
    struct dll_node *head;
    int srchd_postion;
    head = Init_ll();
    Delete_dll_init(head);
    srchd_postion = dll_search(head);
    full_dll_delete(&head);
    return 0;
}
