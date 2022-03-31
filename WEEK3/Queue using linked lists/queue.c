#include <stdlib.h>
#include <stdio.h>
typedef struct node node;

struct node
{
	int id;
	int time;
	node *link;
};

typedef struct list
{
	node *head;
	node *tail;
	int number_of_nodes;
} List;

typedef struct queue
{
	List *ptr_list;
} Queue;

static node *create_node(int id, int time, node *link)
{ 
   node* temp=(node*)malloc(sizeof(node));
   temp->id=id; temp->time=time;
   temp->link=link;
   return(temp);
}

void list_initialize(List *ptr_list)
{ 
   ptr_list->head=NULL; 
   ptr_list->tail=NULL; 
   ptr_list->number_of_nodes=0;
}

void list_insert_rear(List *ptr_list, int id, int time)
{ 
   node *new=create_node(id,time,NULL);
   if(ptr_list->head==NULL)
   { 
	ptr_list->head=new; ptr_list->tail=new; 
	ptr_list->number_of_nodes++; 
	return; 
   }
   node *last=ptr_list->tail; 
   last->link=new; 
   ptr_list->tail=new;
   ptr_list->number_of_nodes++;
}

const int node_get_id(node *node_ptr)
{ 
	return(node_ptr->id); 	
}

const int node_get_time(node *node_ptr)
{
	 return(node_ptr->time);	
}

void list_delete_front(List *ptr_list)
{ 
	if(ptr_list->head==NULL)
  	 {
		 printf("\nThe queue is empty. ");
     		 return;
  	 }
  	 node *first=ptr_list->head;
	 ptr_list->head=first->link;
	 free(first);
  	 ptr_list->number_of_nodes--;
}


void list_destroy(List *ptr_list)
{ 
	node *ptr=ptr_list->head; node *pf=ptr->link;
  	 while(pf!=NULL)
  	 { 
		free(ptr); 
		ptr=pf; 
		pf=pf->link;
  	  }
   	 free(ptr);	
}

void queue_initialize(Queue *queue_list)
{ 
	queue_list->ptr_list=malloc(sizeof(List));
 	  list_initialize(queue_list->ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{ 
	list_insert_rear(ptr->ptr_list,id,time);	
}

void queue_dequeue(Queue *ptr)
{ 
	list_delete_front(ptr->ptr_list);	
}

int queue_is_empty(Queue *ptr)
{ 
	if(ptr->ptr_list->number_of_nodes!=0)
 	 {
      	 return 0;
  	 }
  	 else
  	{
    	   return 1;
  	 }		
}

void queue_peek(Queue *ptr)
{ 
	if(ptr->ptr_list->head==NULL)
  	 {
 		printf("Empty Queue"); return;
  	  }
  printf("%d %d\n",ptr->ptr_list->head->id,ptr->ptr_list->head->time);	
}


void queue_destroy(Queue *ptr)
{ 
	list_destroy(ptr->ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{ 
   int temp=0; int inc,empty,cid=0; node *first=ptr_queue->ptr_list->head; 
   while(temp<=t)
   {
  	 if(first==NULL)
  	 {
		printf("\n empty queue\n");
		return 0;
	}
   inc=node_get_time(first);
   temp+=inc;
   cid=node_get_id(first);
   first=first->link;
   }
    empty=queue_is_empty(&ptr_queue);
    printf("%d \n",cid); 
    return 0;		
}

int main()
{
	Queue queue;
	queue_initialize(&queue);
	int choice, id, time, t;
	int loop = 1;
	while (loop)
	{
		printf("\n 0.insert\n");
		printf("\n 1.delete\n");
		printf("\n 2.peek\n");
		printf("\n 3.find the element \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0: printf("inset the element from rear\n");
			scanf("%d%d", &id, &time);
			queue_enqueue(&queue, id, time);
			break;

		case 1:
			queue_dequeue(&queue);
			break;

		case 2:
			queue_peek(&queue);
			break;

		case 3: printf("\n find the element\n");
			scanf("%d", &t);
			queue_find_person(&queue, t);
			break;

		default:
			queue_destroy(&queue);
			loop = 0;
		}
	}
	return 0;
}




























