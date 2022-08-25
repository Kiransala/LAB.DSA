#include<stdio.h>
#define Size 100
 
int Top=-1, array[Size];

void Push();
void Pop();
void Trav();
 
int main()
{
	int choice;
	
	while(1)	
	{
		printf("\nOperations performed by Stack");
		printf("\n1.Push the element\n2.Pop the element\n3.Traverse\n4.Exit");
		printf("\n\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: Push();
				break;
			case 2: Pop();
				break;
			case 3: Trav();
				break;
			case 4: return 0;
			
			default: printf("\nInvalid choice!!");
		}
	}
}
 
void Push()
{
	int x;
	if(Top==Size-1)
	{
		printf("\nOverflow!!");
	}
	else
	{
		printf("\nEnter element to be inserted to the stack: ");
		scanf("%d",&x);
		Top=Top+1;
		array[Top]=x;
	}
}
 
void Pop()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nPopped element:  %d",array[Top]);
		Top=Top-1;
	}
}
 
void Trav()
{
	if(Top==-1)
	{
		printf("\nUnderflow!!");
	}
	else
	{
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",array[i]);
	}
}
