/*NAME : Divyanshu Shama*/
/*SLL Program*/

#include<stdio.h>
#include<stdlib.h>

/* structure of node */
struct node{
	int data;
	struct node *next;
};
typedef struct node *NODE;

/* CREATING THE NODE */
NODE createNode(){
	NODE ptr;
	ptr=(NODE)malloc(sizeof(struct node));
	ptr->next=NULL;
	return ptr;
}
	

/* INSERTING AT THE END OF THE LIST */
NODE insertAtEnd(NODE head, int value){
	NODE newNode=createNode();
	NODE temp;
	newNode->data=value;
	if(head==NULL)
		head=newNode;
	else{
		temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newNode;
	}
	return head;
}

/* INSERTING AT THE SPECIFIC POSITION */
NODE insertAtPosition(NODE head, int value, int position){
	int count=0;
	NODE temp, previous=NULL, newNode=createNode();
	newNode->data=value;
	if(head==NULL){
		printf("\n list is empty.");
	}
	else
	{
		temp=head;
		count=1;
		
		if(position==1)
			head=insertAtEnd(head, value);
		else{
			while(temp!=NULL && count < position){
				previous=temp;
				temp=temp->next;
				count++;
			}
			if(temp==NULL){
				temp->next = newNode;
			}
			else{
				previous->next=newNode;
				newNode->next=temp;
			}
		}
	}
	return head;
}

/* DELETE FROM THE FRONT OF THE LIST */
NODE deleteAtFirst(NODE head){
	NODE temp;
	if(head==NULL)
		printf("\n List is empty\n");
	else{
		if(head->next==NULL){
			free(head);
			head=NULL;
		}
		else
		{
			temp=head;
			head=head->next;
			free(temp);
			temp=NULL;
		}
	}
	return head;
}


/* DISPLAYING THE LIST */
void display(NODE head){
	NODE temp;
	if(head==NULL){
		printf("\nList is empty");
	}
	else{
		printf("LIST: ");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			if(temp->next!=NULL)
				printf("->");
			temp=temp->next;
		}
	}
}

/* REVERSING THE LIST */
void reverseList(NODE head){
	NODE current, temp=NULL;
	if(head==NULL)
	{
		printf("\n List is empty\n");
	}
	else{
		while(temp!=head)
		{
			current=head;
			while(current->next != NULL && current->next != temp)
				current= current->next;
			if(current->next!=NULL){
				printf("<-");
			}
			printf("%d",current->data);
			temp=current;
		}
	}
}

int main()
{
	NODE head=NULL;
	int value, position, choise;
	while(choise!=6){
		printf("\n Enter your choise\n");
		printf("1.Insert at End of the List\t 2.Insert at the specific Position\t 3.Delete at first of the \t 4.Display the list\t 5.Reverse the list\t 6.Exit\n");
		scanf("%d",&choise);
		switch(choise)
		{
			case 1:
			printf("\n Enter the value:\t");
			scanf("%d",&value);
			head=insertAtEnd(head, value);
			display(head);
			break;
			
			case 2:
			printf("\n Enter the value\n");
			printf("value: ");
			scanf("%d",&value);
			printf("\n Position: ");
			scanf("%d", &position);
			head=insertAtPosition(head, value, position);
			display(head);
			break;
			
			case 3:
			head=deleteAtFirst(head);
			display(head);
			break;
			
			case 4:
			display(head);
			break;
			
			case 5:
			reverseList(head);
			break;
		}
	}
}

			

	
				
		

	
