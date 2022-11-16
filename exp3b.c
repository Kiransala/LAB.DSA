#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int calcSize(struct Node* node){
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

void delete(struct Node** head, int pos)
{
    struct Node* temp = *head;
    struct Node* previous;

    //if the head node itself needs to be deleted
    int size = calcSize(*head);

    if(pos<1 || pos>size){
        printf("Enter valid position\n");

        return;
    }

    if(pos==1){
        //Case 1 head becomes 30
        *head = temp->next; //changing head to next in the list
        printf("Value %d, deleted \n",temp->data);

        //case 1: 22 deleted and freed
        free(temp);
        return;
    }

    //run until we find the value to be deleted in the list
    while (--pos) 
    {
        //store previous link node as we need to change its next val
        previous = temp; 
        temp = temp->next; 
    }


    // Case 2: (24)->next = 16 (as 20->next = 16) 
    // Case 3: (16)->next = NULL (as 12->next = NULL)
    previous->next = temp->next;
    printf("Value %d, deleted \n",temp->data);

    free(temp);
    //case 2: 20 deleted and freed
    //case 3: 12 deleted and freed
}

void display(struct Node* node){

    //as linked list will end when Node is Null
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n\n");
}

int main()
{
    //creating 4 pointers of type struct Node
    //So these can point to address of struct type variable
    struct Node* head = NULL; 
    struct Node* node2 = NULL; 
    struct Node* node3 = NULL; 
    struct Node* node4 = NULL;
    struct Node* node5 = NULL;
    struct Node* node6 = NULL;

    // allocate 3 nodes in the heap 
    head =  (struct Node*)malloc(sizeof(struct Node)); 
    node2 = (struct Node*)malloc(sizeof(struct Node)); 
    node3 = (struct Node*)malloc(sizeof(struct Node)); 
    node4 = (struct Node*)malloc(sizeof(struct Node)); 
    node5 = (struct Node*)malloc(sizeof(struct Node));
    node6 = (struct Node*)malloc(sizeof(struct Node));

   
    head->data  = 22; // data set for head node 
    head->next  = node2; // next pointer assigned to address of node2 

    node2->data = 30; 
    node2->next = node3; 

    node3->data = 24;
    node3->next = node4; 

    node4->data = 20;
    node4->next = node5; 
   
    node5->data = 16;
    node5->next = node6;

    node6->data = 12;
    node6->next = NULL;

    /*No need for & i.e. address as we do not
    need to change head address
    */
    printf("Linked List Before Operations : "); 
    display(head);

    //deleting first occurance of a value in linked list
    delete(&head,1);
    delete(&head,3);
    delete(&head,4);
    
    printf("Linked List After Operations : ");
    display(head);

    return 0; 
}
