#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node
{
  int data;
  struct Node *next;
};

// Insert at the beginning
void
insertAtBeginning (struct Node **head_ref, int new_data)
{
  // Allocate memory to a node
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert after node
void
insertAfter (struct Node *prev_node, int new_data)
{
  if (prev_node == NULL)
    {
      printf ("the given previous node cannot be NULL");
      return;
    }

  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert the the end
void
insertAtEnd (struct Node **head_ref, int new_data)
{
  struct Node *new_node = (struct Node *) malloc (sizeof (struct Node));
  struct Node *last = *head_ref;	/* used in step 5 */

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL)
    {
      *head_ref = new_node;
      return;
    }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

// Delete a node
void
deleteNode (struct Node **head_ref, int key)
{
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key)
    {
      *head_ref = temp->next;
      free (temp);
      return;
    }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key)
    {
      prev = temp;
      temp = temp->next;
    }

  // If the key is not present
  if (temp == NULL)
    return;

  // Remove the node
  prev->next = temp->next;

  free (temp);
}


// Print the linked list
void
printList (struct Node *node)
{
  while (node != NULL)
    {
      printf (" %d ", node->data);
      node = node->next;
    }
}

// Menu driven program
int
main ()
{
  struct Node *head = NULL;

  int choice, n;
  while (1)
    {
      printf ("\n\n1.InsertAtBeginning\n");
      printf ("2.InsertAtEnd\n");
      printf ("3.InsertAfter\n");
      printf ("4.Delete node\n");
      printf ("5.Exit\n");
      printf ("Enter your choice of operations : ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter the value: ");
	  scanf ("%d", &n);
	  insertAtBeginning (&head, n);
	  printf ("\nLinked list: ");
	  printList (head);
	  break;
	case 2:
	  printf ("Enter the value: ");
	  scanf ("%d", &n);
	  insertAtEnd (&head, n);
	  printf ("\nLinked list: ");
	  printList (head);
	  break;
	case 3:
	  printf ("Enter the value: ");
	  scanf ("%d", &n);
	  insertAfter (head->next, n);
	  printf ("\nLinked list: ");
	  printList (head);
	  break;
	case 4:
	  printf ("Enter the value: ");
	  scanf ("%d", &n);
	  printf ("\nAfter deleting an element: ");
	  deleteNode (&head, n);
	  printList (head);
	  break;
	case 5:
	  printf ("Have a good day.\n");
	  exit (0);
	default:
	  printf ("Incorrect choice \n");
	}
    }
}
