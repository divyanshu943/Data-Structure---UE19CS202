#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;

void createList(int n);
void displayList();
void insert_beginning(int data);
void search_element(int data);
void updating_element(int data);
void insert_given_position(int data);
void delete_beginning();
void delete_given_position();
void reverse_list();

int main()
{
    int n, data, choise=1;
    head = NULL;
    while(choise != 0)
    {
        printf("\n\n\n\t CIRCULAR LINKED LIST BASIC OPERATION\n\n");
        printf("1. Create Lists\n");
        printf("1. Insert at Beginning\n");
        printf("1. Insert at any position\n");
        printf("1. Delete at Beginning\n");
        printf("1. Delete at any position\n");
        printf("1. Search Element\n");
        printf("1. Update Element\n");
        printf("1. Reverse Lists\n");
        printf("1. Exit\n");
        printf("\n\n");
        printf("Enter your CHoise : ");
        scanf("%d, &choise");
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
            scanf("%d", data);
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
            printf("\n Enter the element to be Searrched : ");
            scanf("%d", &data);
            search_element(data);
            break;

            case 7:
            printf("enter the element to be updated : ");
            scanf("%d", data);
            updating_element(data);
            printf("\n The updated List is\n\n");
            displayList();
            break;

            case 8:
            reverse_list();
            break;

            case 0:
            break;
            default:
            printf("Error! invalid choise.");
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
        head = (struct node *)malloc(sizeof(struct node));
        printf("Data of node 1 : ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        prevNode = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("data of node %d : ", i);
            scanf("%d", data);
            newNode->data = data;
            newNode->next = NULL;

            prevNode->next = newNode;
            prevNode = newNode;
        }
        prevNode->next = head;
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
        }while(current != head);
        
    }
}

void insert_beginning(int data)
{
    
}
        }
    }
}