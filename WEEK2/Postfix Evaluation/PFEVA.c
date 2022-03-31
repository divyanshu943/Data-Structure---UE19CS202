#include<stdio.h>
#include<stdlib.h>
#define debug printf("HERE")

typedef struct node 
{
 int data;
 struct node *link;
}Node;

typedef struct list 
{
 Node *head; int number_of_Nodes;

}List;

static Node* create_Node(int data, Node* link) 
{
 Node* temp =  (Node*)malloc(sizeof(Node));
	
    temp -> data = data; temp -> link = link;
	
    return temp;

}


/* initializes a linked List */

void List_initialize(List* ptr_List) 

{ ptr_List->head=NULL;
   ptr_List->number_of_Nodes=0;

}



void List_insert_front(List* ptr_List, int data) 
{
 struct Node *top; top=ptr_List->head; 
  struct Node *temp; temp=create_Node(data,top);
  
  ptr_List->head=temp; ptr_List->number_of_Nodes++;

}


void List_delete_front(List* ptr_List)

{
 Node *top=ptr_List->head; ptr_List->head=ptr_List->head->link;
   free(top); ptr_List->number_of_Nodes--;
   

}


/* Returns the element that (*Node_ptr) contains */

const int Node_get_data(Node *Node_ptr) 

{
 return Node_ptr->data;

}



/* deallocates resources held by the List */


void List_destroy(List* ptr_List) 

{
 Node *pf=ptr_List->head; Node *ptr=NULL;
   while(pf!=NULL)
   { ptr=pf; pf=pf->link; free(ptr);
   }

}




typedef struct Stack
{
 List *ptr_List; 
} 
Stack;





void stack_initialize(Stack *ptr_stack) 

{
 ptr_stack->ptr_List = malloc(sizeof(List));
    List_initialize(ptr_stack->ptr_List);

}



void stack_push(Stack *ptr_stack, int key)

{
 List_insert_front(ptr_stack->ptr_List,key);

}



void stack_pop(Stack *ptr_stack) 

{
 List_delete_front(ptr_stack->ptr_List);


}



int stack_is_empty(Stack *ptr_stack) 

{ if(ptr_stack->ptr_List->number_of_Nodes!=0)
  {
       return 0;
   }
   else
  {
       return 1;
   }

}



const int stack_peek(Stack *ptr_stack)

{
 return(ptr_stack->ptr_List->head->data);

}



void stack_destroy(Stack *ptr_stack) 

{
  List_destroy(ptr_stack->ptr_List);


}



/* The implementations for the above functions are provided below main() */


/* Returns the result of the postfix expression */


int postfix_eval(const char* expression) 

{
  int res,tmp; 
    struct Stack ptr_stack; stack_initialize(&ptr_stack);
   while((*expression)!='\0')
   { tmp=(*expression)-'0';
     
      if(tmp>=0 && tmp<=9)
      
      { stack_push(&ptr_stack,tmp);
      
       }
      if((*expression)=='+' || (*expression)=='-' || (*expression)=='*' || (*expression)=='/' )
      { int op1, op2; op2=stack_peek(&ptr_stack); 
         stack_pop(&ptr_stack);  op1=stack_peek(&ptr_stack); stack_pop(&ptr_stack);
         switch(*expression)
         { int op3; 
             case('+'):
             { op3=op1+op2; stack_push(&ptr_stack,op3); break;
             }
             case('-'):
             { op3=op1-op2; stack_push(&ptr_stack,op3);break;
             }
             case('*'):
             { op3=op1*op2; stack_push(&ptr_stack,op3);break;
             }
             case('/'): 
                              
             { if(op2==0)
                { printf("\nError! Division by zero is undefined. "); return 0;
                 }
                op3=op1/op2; stack_push(&ptr_stack,op3); break;
             }     
         }
      }
         expression++;
    }   
    res=stack_peek(&ptr_stack);
    stack_destroy(&ptr_stack);
    return res;

}

/* TODO:
 * Provide suitable implementation for the above function declaration, namely, postfix_eval()
 */
 


















int main() 
{
	char expression[350];
	int number_of_inputs = 0;
	printf("\n Enter the no. of inputs:\t");
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) 
             {
		printf("\n ENTER THE EXPRESSION:\t");
		scanf("%s", expression);
		printf("%d\n", postfix_eval(expression));
	}
	return 0;
}

