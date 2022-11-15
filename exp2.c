#include<stdio.h>
#define SIZE 100

int Front = -1, Rear = -1, array[SIZE];

void enqueue();
void dequeue();
void display();

main()
{
    int choice;
    
    while(1)
    {
        printf("\n\n1.Enqueue \n2.Dequeue \n3.Display \n4.Exit \nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: return 0;
            
            default: printf("Invalid choice.");
        }
    }
    
}

void enqueue()
{
    int x;
    
    if (Rear == SIZE-1)
    {
        printf("Queue if full.");
    }
    else
    {
        if (Front == -1)
        Front = 0;
        printf("Enter the element: ");
        scanf("%d",&x);
        Rear = Rear + 1;
        array[Rear]=x;
    }
}

void dequeue()
{
    int x;
    
    if (Front == -1 || Front > Rear)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("\nDeleted element: %d",array[Front]);
        Front = Front + 1;
    }
}

void display()
{
    if (Front == -1)
    {
        printf("Stack is empty.");
    }
    else
    {
        printf("\nElements in Queue: \n");
        for(int i = Front ; i <= Rear ; i++)
        {
            printf("%d\n",array[i]);
        }
    }
}
