#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure using an array
typedef struct stack{
	int* arr;
	int top;
}stack;

// Initialise a stack of given size
stack* stack_initialize(int size)

{
 stack * Stack = (stack *)malloc(sizeof(stack));
	
   
Stack->arr=(int *)malloc(size*sizeof(int));
 Stack->top=-1;	
   return Stack;

}

// Push an element onto the stack
void stack_push(stack *ptr_stack, int key) 

{
 ptr_stack->arr[++ptr_stack->top]=key;

}

// Pop an element from the stack. Do not return the element
void stack_pop(stack *ptr_stack)

{ if(stack_is_empty(ptr_stack)==0)
	
   { ptr_stack->arr[ptr_stack->top--];
	
   }

}

// Check if the stack is empty
int stack_is_empty(stack *ptr_stack)

{ return ptr_stack->top==-1;

}




// Return the top element of the stack
int stack_peek(stack *ptr_stack) 

{ if(stack_is_empty(ptr_stack)==0)
	
   { return ptr_stack->arr[ptr_stack->top];
	
    }

}

// Free the resources held by the stack
void stack_destroy(stack *ptr_stack) 

{
 free(ptr_stack->arr);

}


// Convert an infix expression to postfix expression
void convert_infix_to_postfix(const char *source_infix,char *target_postfix)

{    stack * Stack = stack_initialize(strlen(source_infix));
	int i=0,j=0;

   while(source_infix[i]!='\0')
	
    { int input_prec(char symb)

        { if(symb=='+' || symb=='-')
			
            { return 1; }

           else if(symb=='*' || symb=='/')
            
{ return 3; }

           else if(isalpha(symb))

            {
 return 7;
 }

           else if(symb==')'||symb==']'||symb=='}')

	{
 return 0;
 }

           else if(symb=='('||symb=='['||symb=='{')

            {
  return 9;
 }

         }

       int check_prec(char symb)
		
        { if(symb=='+' || symb=='-')
			
             { return 2;
 }

	else if(symb=='*' || symb=='/')
			
             { return 4; }

	else if(isalpha(symb))

	{ return 8;
 }

	else if(symb=='('||symb=='['||symb=='{')

	{ return 0;}

        }

       while(check_prec(stack_peek(Stack))>input_prec(source_infix[i]))
		
       {	target_postfix[j]=stack_peek(Stack);

              stack_pop(Stack); j++;
		
        }
       if(input_prec(source_infix[i])!=check_prec(stack_peek(Stack)))
		
       {	stack_push(Stack,source_infix[i]);
	
       }

      else

       {	stack_pop(Stack);
		
       }
		
      i++;

   }
  if(stack_is_empty(Stack)==0)
	
   {
 while(stack_is_empty(Stack)==0)
		
      { target_postfix[j]=stack_peek(Stack);

         stack_pop(Stack); j++;

      }

   }

 target_postfix[j]='\0';
	
 stack_destroy(Stack);

}



int main() 
{
	char source_infix[2000];
	char target_postfix[2000];
	int number_of_inputs = 0;
	printf("enter the inputs\n");
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) 
	{
		printf("\n Enter the source infix\n");
		scanf("%s", source_infix);
		convert_infix_to_postfix(source_infix, target_postfix);
		printf("%s\n", target_postfix);
	}
	return 0;
}

