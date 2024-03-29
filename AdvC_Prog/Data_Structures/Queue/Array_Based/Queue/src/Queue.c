/*
 ============================================================================
 Name        : Queue.c
 Author      : M USMAN
 Version     :
 Copyright   : Your copyright notice
 Description : Array Based Queue Implementation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MXSIZE   50

void enqueue();
void dequeue();
void peek();
bool isEmpty();

int front = -1;
int rear = -1;
int queue[MXSIZE];


void enqueue()
{
int num ;

	if(rear!=MXSIZE-1)
	{
		if(front==-1){
			front=0;
		}
	rear +=1;
	printf("Enter the element to enqueue : ");
	scanf("%u",&num);
	queue[rear]= num;
	}
	else
		printf("Queue is Full");

}


void dequeue()
{
	if(isEmpty()==false)
	{
	printf("Removed : %i",queue[front]);
	front+=1;
	}
	else
		printf("Queue is Empty");

}

void peek()
{
	if(isEmpty()==false)
	{
    printf("Top Of Queue : %i",queue[front]);
	}

}

bool isEmpty()
{
bool state ;

	if(front==-1)
	{
		state = true;
	}
	else
	state = false;


return state;
}



void display()
{

	if(isEmpty()==false)
	{
        printf("Stack Elements : \n");
		for(int index=front;index<=rear;index++)
		{

		printf("%u  ",queue[index]);
		}

	}

	else if(isEmpty()==true)
	{
	printf("\n Stack is empty");
	}

}


int main(void)
{
	unsigned int choice;

	while(choice!=8)
	{
			printf("\nPress 1 To Enqueue\n");
			printf("Press 2 To Dequeue \n");
			printf("Press 3 To Peek the Top \n");
			printf("Press 4 to Display Queue \n");
			printf("Press 8 Exit \n");
			printf("Enter your choice : \n");
			scanf("%u",&choice);

			switch(choice)
			{

			case 1 : enqueue();
			         break;

			case 2 : dequeue();
			         break;

			case 3 : peek();
			         break;

			case 4 : display();
			         break;

	}

  }

return 0;

}
