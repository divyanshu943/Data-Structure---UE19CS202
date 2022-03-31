#include <stdio.h>
#include <stdlib.h>

/*Node of the circular linked list*/
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

/*INITIALIZES A CIRUCULAR LINKED LIST*/
List* initialize_list()
{
    List* cll = (List*)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;
    return cll;
}


/* CREATING THE NODE*/
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* INSERTING AT THE FRONT OF THE LIST */




/* INSERTING AT A POSITION*/
void position_insert(List* cll, int data, int pos)
{
   Node* newnode = create_node(data);
   if(pos<0 || pos>cll->length){
		return;}
   else if(pos == 0){
	if(cll->length == 0){
		cll->head = newnode;
		cll->tail = newnode;
		((cll->tail)->next) = newnode;
		cll->length++;
		}
	else{
		((cll->tail)->next) = newnode->next;
		newnode->next = cll->head;
		cll->head = newnode;
		cll->length++;}
	}
	else if(pos == cll->length){
		((cll->tail)->next) = newnode;
		newnode->next = cll->head;
		cll->tail = newnode;
		cll->length++;
	}
	else{
	int i=0;
	struct Node* temp = cll->head;
	while(i<(pos-1))
	{temp = temp->next;
		i++;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	cll->length++;
	}
}


/* DELETING AT THE POSITION*/
void position_delete(List* cll, int pos)
{
  if(pos<0 || pos >= cll->length)
	{return;
	}
	else if(pos == 0){
		struct Node* temp = cll->head;
		cll->head = cll->head->next;
		((cll->tail)->next) = cll->head;
		free(temp);
		cll->length--;
	}
	else if(pos==((cll->length)-1))
	{
	Node *current,*prev;
	current=cll->head;
	while((current->next)!=((cll->tail)->next))
	{
	prev=current;
	current=current->next;
	}
	prev->next=cll->head;
	cll->tail=prev;
	cll->length--;
	free(current);
	return;
	}
else{
	struct Node* temp = cll->head;
	struct Node* nextnode;
	int i;
	for(i=0; i<pos-1; i++){
		temp = temp->next;
	}
	nextnode = temp->next;
	temp->next = nextnode->next;
	free(nextnode);
	cll->length--;
	}
}


/*PRINT THE DATA PRESENT IN THE SAFE NODE ACCORDING TO THE JOSEPHUS PROBLEM*/
int josephus(List* cll, int k)
{
int output;
struct Node* temp;
    
k=(k+1)%(cll->length);
    
while(cll->length != 1){
    	
    position_delete(cll, k);
	k = (k+1)%(cll->length);
	}
return cll->head->data;
}


/*DISPLAYING THE LIST*/
void display(List* cll)
{
	if(cll->length == 0)
        printf("EMPTY");
  	  else
   	 {
        Node* temp = cll->head;
        for(int i=0;i<cll->length;i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }    
    printf("\n");
}


/*DEALLOCATES RESOURCES HELD BY THE LIST*/
void destroy_list(List* cll)
{
	Node *p = cll->head;
	Node *q = NULL;
	for(int i=0;i<cll->length;i++)
    	{
		q = p;
		p = p->next;
		free(q);
	}
	
    free(cll);
}

int main()
{

    List* cll = initialize_list();
    int ele,choice,pos,k;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at position;
            case 1:
                scanf("%d %d",&ele,&pos);
                position_insert(cll,ele,pos);
                break;

            // Delete at position
            case 2:
                scanf("%d",&pos);
                position_delete(cll, pos);
                break;

            // Josephus problem
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Print entire list
            case 4:
                display(cll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}






















