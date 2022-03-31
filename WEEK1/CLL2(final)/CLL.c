#include<stdio.h>
#include<stdlib.h>

/*structure of node with data and a pointer */
struct node {
    int data;
    struct node * next;
}*head;

void createList(int n);
void displayList();
void insert_beginning(int data);
void search_element(int data);
void updating_element(int data);
void insert_given_position(int data, int position);
void delete_beginning();
void delete_given_position();
void reverse_list();

int main()
{
    int n, data, choise=1;
    head = NULL;
    while(choise != 0)
    {
        printf("1. Create Lists\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at any position\n");
        printf("6. Search Element\n");
        printf("7. Update Element\n");
        printf("8. Reverse Lists\n");
        printf("0. Exit\n");
        printf("\n\n");
        printf("Enter your Choise : ");
        scanf("%d", &choise);
        switch(choise)
        {
            case 1:
            printf("Enter the total number of nodes in the list: ");
            scanf("%d", &n);
            createList(n);
            displayList();
            break;

            case 2:
            printf("Enter data to be inserted at beginning: ");
            scanf("%d", &data);
            insert_beginning(data);
            displayList();
            break;

            case 3:
            printf("Enter node Position: ");
            scanf("%d", &n);
            printf("Enter data you want to insert at %d position: ", n);
            scanf("%d", &data);
            insert_given_position(data, n);
            displayList();
            break;

            case 4:
            if(head == NULL)
            {
                printf("\n The list is empty\n");
            }
            else
            {
                delete_beginning();
                displayList();
            }
            break;

            case 5:
            if(head == NULL)
            {
                printf("The list is empty\n");
            }
            else
            {
                delete_given_position();
                displayList();
            }
            break;

            case 6:
            printf("\n Enter the element to be Searched : ");
            scanf("%d", &data);
            search_element(data);
            break;

            case 7:
            printf("enter the element to be updated : ");
            scanf("%d", &data);
            updating_element(data);
            printf("\n The updated List is : \n\n");
            displayList();
            break;

            case 8:
            reverse_list();
            break;

            case 0:
            break;
            default:
            printf("incorrect choise.");
        }
        printf("\n");
    }
    return 0;
}


void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;
    if(n >=1)
    {
        //Creates and links the head node
        head = (struct node *)malloc(sizeof(struct node));
        printf("Data of node 1 : ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        prevNode = head;

        //Creates and links rest of the n-1 nodes
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("data of node %d : ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;

            prevNode->next = newNode;//links the previous node with newly created node
            prevNode = newNode; // moves the previous node ahead
        }
        prevNode->next = head;//links the last node with the first node
    }
}


void displayList()
{
    struct node *current;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        current = head;
        printf("The singly circular linked list is: \n");
        do{
            printf("%d\t",current->data);
            current = current->next;
            n++;
        } while(current != head);     
    }
}


void insert_beginning(int data)
{
    struct node *newNode, *current;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        //creates new node, assign data and links it to head
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        printf("\n The element %d is inserted at the beginning", data);
        printf("\n");

        //Traverses to last node and links last node with first node which is new node
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        head = newNode;//makes new node as head node
    }
}


void insert_given_position(int data, int position)
{
    struct node *newNode, *current;
    int i;
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(position == 0)
    {
        insert_beginning(data);
    }
    else
    {
        //creates new node and assign data to it
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        printf("\n The element %d is inserted at index %d", data,position);
        printf("\n");

        //Traverse to n-1 node
        current = head;
        for(i=2; i<=position ; i++)
        {
            current = current->next;
        }
        //links the new node with node ahead of it and previous of it
        newNode->next = current->next;
        current->next  = newNode;
    }
}


void delete_beginning()
{
    struct node * temp, *s;
    //when start and end of the list are same
    if(head == head->next)
    {
        head = NULL;
        printf("\n The list is empty\n");
    }
    else
    {
        temp = head;
        s = head;
        while(temp->next != head)// traverse until start node is reached again
        {
            temp = temp -> next;
        }
        printf("\n The element %d is deleted at the beginning", s->data);
        printf("\n");
        head = s->next;// shift head node
        temp->next = head;
        printf("\n");
        free(s);
    }
}


void delete_given_position()
{
    struct node *temp, *s;
    if(head == NULL)
    printf("\n the list is empty");
    else
    {
        int count = 0, pos;
        printf("\n Enter the position to be deleted :");
        scanf("%d", &pos);
        temp = head;
        while(count < pos)
        {
            s = temp;
            temp = temp->next;
            count++;
        }
        printf("\n The element %d at index %d is deleted", temp -> data,pos);
        printf("\n");
        s -> next = temp -> next;
        printf("\n");
        free(temp);
    }
}


void search_element(int data)
{
    struct node * temp = head;
    int index = 0;
    while(temp)
    {
        if(temp -> data == data)
        {
            printf("\n element found at index %d in the list", index);
            break;
        }
        else{
            temp = temp -> next;
            index++;
        }
    }
}


void updating_element(int data)
{
    int new_data;
    printf("\n enter the new data to replace with : ");
    scanf("%d", &new_data);
    struct node * temp = head;
    while(temp)
    {
        if(temp -> data == data)
        {
            temp -> data = new_data;//update the element if found and exit the loop
            break;
        }
        else
        {
            temp = temp -> next;
        }
    }
}


void reverse_list()
{
    struct node *prev, *cur, *next, *last;
    printf("\n The reversed list is \n \n");
    //Cannot reverse the empty list

    if (head == NULL)
    {
        printf("Cannot reverse the empty list. \n");
        return;
    }

    //head is going to be our last node after reversing list
    last = head;
    prev = head;
    cur = (head)->next;
    head = (head)->next;

    // Iterate till you reach the initial node in circular list
    while(head != last)
    {
        head = head->next;
        cur->next = prev;
        prev = cur;
        cur = head;
    }
    cur->next = prev;
    head = prev;
    displayList();
}