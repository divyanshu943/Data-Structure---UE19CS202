#include <stdio.h>
#include <stdlib.h>

/* structure of node */
typedef struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
} Node;

/*Handle of the list. Its head points to the first node in the list.*/
typedef struct List
{
    Node *head;
    Node *tail;
    int number_of_nodes;
}List;

/*initializes a linked list*/
List* initialize_list()
{
    List* dll = (List*)malloc(sizeof(List));
    dll->head = NULL;
    dll->number_of_nodes = 0;
	
    return dll;
}


/* CREATING THE NODE */
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->previous = NULL;

    return node;
}


/* INSERTING AT THE FRONT OF THE LIST */
void insertAtFront(List* dll, int data)
{
    Node *rnode=create_node(data);
    Node *temp=NULL;
    if(dll->head==NULL)
    {
        dll->head=rnode;
        dll->tail=rnode;
        rnode->previous=NULL;
        rnode->next=NULL;
        dll->number_of_nodes++;
    }
    else
    {
        dll->head->previous=rnode;
        rnode->next=dll->head;
        dll->head=rnode;
        rnode->previous=NULL;
        dll->number_of_nodes++;
    }
}


/* DELETE FROM THE FRONT OF THE LIST */
void deleteAtFront(List* list)
{
    Node *temp=list->head;
    if(temp!=NULL)
    {
        list->head=list->head->next;
        free(temp);
        list->head->previous=NULL;
        list->number_of_nodes--;
    }
}

/* DELETING AT THE SPECIFIC POSITION */
void deleteAtPosition(List* dll, int pos)
{
     Node *temp=dll->head;
    Node *rnode=NULL;
    int n=0;
    if(dll->number_of_nodes==1)
    {
        temp=dll->tail;
        free(temp);
        dll->number_of_nodes--;
    }
    else if(pos>dll->number_of_nodes)
    {
        return;
    }
    else if(temp!=NULL)
    {
        while(n<pos)
        {
            rnode=temp;
            temp=temp->next;
            n++;
        }
        temp->previous=rnode->previous;
        free(rnode);
        dll->number_of_nodes--;
    }
}

/* SEARCHING FOR THE ELEMENT IN THE LIST */
int search_list(List* dll,int key)
{
    Node *temp=dll->head;
    Node *rnode=NULL;
    int n=0;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            rnode=temp;
            temp=temp->next;
            if(rnode->data==key)
            {
                return n;
            }
            n++;
        }
    }
    return -1;
}

/* COUNTING THE NO OF NODES IN THE LIST */
int count_nodes(List* dll)
{
	return dll->number_of_nodes;
	
}


/* DISPLAYING THE LIST */
void display(List* dll)
{
    if(dll->number_of_nodes == 0)
        printf("LIST IS EMPTY");
    else
    {
        Node* temp = dll->head;

        while(temp != NULL)
        {
            printf("%d",temp->data);
			if(temp->next!=NULL)
				printf("<->");
            temp = temp->next;
        }
    }
    
    printf("\n");
}


/* REVERSING THE LIST */
void reverse_list(List* dll)
{
    Node *cur=dll->head;
    Node *temp=NULL;
    while(cur!=NULL)
    {
        temp=cur->previous;
        cur->previous=cur->next;
        cur->next=temp;
        cur=cur->previous;
    }
    if(temp!=NULL)
    {
        dll->head=temp->previous;
    }
}

void destroy_list(List* dll)
{
    Node *p = dll->head;
	Node *q = NULL;

    while (p != NULL)
    {
		q = p;
		p = p->next;
		free(q);
	}
	
    free(dll);
}


int main()
{
    List* dll = initialize_list();
    int ele,choice,pos,x;
    do
    {
		printf("\n Enter your choise\n");
		printf("1.Insert at beginning\t 2.Delete element at the beginning of the list\t 3.Count the number of nodes\t 4.Delete at any position\t 5.Search for an element\t 6.reverse the List\t 7.Print the entire list\n");
		scanf("%d",&choice);

        switch(choice)
        {
           
            case 1:
				printf("\n Enter the value:\t");
                scanf("%d",&ele);
                insertAtFront(dll,ele);
				display(dll);
                break;

	    
			case 2:
                deleteAtFront(dll);
				display(dll);
				break;

	
			case 3:
				x = count_nodes(dll);
				printf("the number_of_nodes are: %d\n",x);
            	break;

           
            case 4:
				printf("\n Enter the value\n");
				printf("value: ");
				scanf("%d",&ele);
				printf("\n Position: ");
                scanf("%d",&pos);
                deleteAtPosition(dll, pos);
				display(dll);
                break;

           
            case 5:
				printf("\n Enter the value to be searched\n");
                scanf("%d",&ele);
                pos = search_list(dll,ele);
                printf("the value is preent at %d position\n",pos);
				
                break;
	
	  
            case 6:
                reverse_list(dll);
				display(dll);
                break;

          
            case 7:
                display(dll);
                break;        
        }
    }
	while (choice != 0);

    destroy_list(dll);
    return 0;
}










