#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() 
{

   if(top == -1)
    return 1;
   else
    return 0;
}
   
int isfull() 
{

   if(top == MAXSIZE)
    return 1;
   else
    return 0;
}

int peek() 
{
   return stack[top];
}

int pop() 
{
   int data;
	
   if(!isempty()) 
   {
      data = stack[top];
      top = top - 1;   
      return data;
   } else 
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) 
{

   if(!isfull()) 
   {
      top = top + 1;   
      stack[top] = data;
   } else 
   {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() 
{
   int i;
   int n;
   int no;
   int maxop;
   printf("How many operation would you like to perform?\n");
   scanf("%d",&maxop);
   for(i = 1; i <= maxop ; i++)
   {
   printf("Choose one \n1.push 2.pop :");
   scanf("%d",&no);
   // using switch case
   switch (no)
       {
          case 1:
          printf("Enter a number,Push:");
          scanf("%d",&n);
          printf(" ");
          push(n);
          break;
          
          case 2:
          pop(n);
          break;
          
          default:
          printf("Invalid choice, Please enter valid number.\n");
          break;
       }
  
   }
   
   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data 
   while(!isempty()) 
   {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}