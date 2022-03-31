#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;
 

int  topelement();
void push(int data);
void pop();
void empty();
void display();
void stack_count();
void create();
int  count = 0;
 
void main()
{
    int number, choise, element;
 
    printf("\n 1. Push the element into the stack");
    printf("\n 2. Pop the element into the stack");
    printf("\n 3. Peek of the stack");
    printf("\n 4. Empty");
    printf("\n 5. Dipslay the stack");
    printf("\n 6. Count the no. of element in stack");
	printf("\n 7. Exit");
    
 
    create();
 
    while (1)
    {
        printf("\n Enter the choice : ");
        scanf("%d", &choise);
 
        switch (choise)
        {
        case 1:
            	  printf("Enter data : ");
				  scanf("%d", &number);
				  push(number);
          	      break;

        case 2:
				  pop();
          	      break;

        case 3:
          	      if (top == NULL)
              	   printf("No elements in stack");
         	    else
           	    {
             	   element = topelement();
              	   printf("\n Top element is : %d", element);
           	    }
                break;

        case 4:
				empty();
				break;

        case 5:
         	    display();
          	    break;

        case 6:
				stack_count();
           	    break;
				
        case 7:
           	    exit(0);


        default :
         	   printf("Please enter the correct choice :  ");
          	   break;
        }
    }
}
 

void create()
{
    top = NULL;
}
 

void stack_count()
{
    printf("\n Number of elements in stack is: %d", count);
}
 

void push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}
 

void display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 

void pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n stack is empty");
        return;
    }
    else
        top1 = top1->ptr;
		printf("\n The value which is deleted is : %d", top->info);
		free(top);
		top = top1;
    	 count--;
}
 
/* Return top element */
int topelement()
{
    return(top->info);
}
 
/* Check if the stack is empty or not */
void empty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n The Stack is not empty, it has %d elements", count);
}
 


