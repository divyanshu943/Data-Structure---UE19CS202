#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize() {
	List* list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->number_of_nodes = 0;
	return list;
}


/*Inserts data at the end of the List*/
void insert_at_end(List *list, int data) 
{
 	Node *temp=(Node *)malloc(sizeof(Node));
   temp->data=data;
   temp->link=NULL;
   
   if(list->head==NULL)
    {
      list->head=temp;
      list->number_of_nodes++;
    }
    
   
   else
   
    {  Node *p=list->head;
      while(p->link!=NULL)
	  { p=p->link;}
	  
	  
	  p->link=temp;
	  
	  list->number_of_nodes++;
    }
}

/* Evaluates the polynomial for a given x */
long long int evaluate(List *list, int x)
{
     Node *temp=(Node*)malloc(sizeof(Node));
    temp=list->head;
    int n=list->number_of_nodes;
    long long int sol=0;
    for(int i=0;i<n;i++)
    {
        sol+=temp->data*pow(x,i);
        temp=temp->link;
    }
    return sol;

}


/* deallocates resources held by the list */

void list_destroy (List *list)
{
	Node *t, *u=NULL;
	t=list->head;
	while (t != NULL){
		u=t;
		t=t->link;
		free(u);
	}
	free(list);
}


int main() {
	int n,x,coeff;
    long long int value;
	List* list = list_initialize();

	printf(" single polynomial expression, which will denote the degree of the polynomial: ");
    scanf("%d", &n);
    for(int i=0;i<n+1;i++)
    {
		printf("enter the different integers: ");
	    scanf("%d",&coeff);
        insert_at_end(list,coeff);
    }
	printf("enter the single integer, which will denote the value of x: ");
    scanf("%d",&x);

    value = evaluate(list,x);
    printf("%lld \n",value);
    
    list_destroy(list);
	return 0;
}



