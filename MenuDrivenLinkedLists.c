#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

/*

LinkedList: Singly Linear Linked list...

Functions:

1]	void InsertFirst(PPNODE Head,int value);
2]	void Dispaly(PNODE Head)
3]	int Count(PNODE Head)
4]	void InsertLast(PPNODE Head,int value);
5]	void DeleteFirst(PPNODE Head);
6]	void DeleteLast(PPNODE Head)
7]	void InsertAtPos(PPNODE Head,int value,int Pos);
8]	void DeleteAtPos(PPNODE Head,int Pos);
*/

/*
Common Steps for Insert functions:=

1] Allocate Memory for Node;
2] Initilized that Node;
3] Checked whether linkedlist is empty or not!!;
4]Insert the Node Accordingly;
*/

void InsertFirst(PPNODE Head, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;

	if (*Head == NULL)	//if Linkedlist is Empty
	{
		*Head = newn;
	}
	else				//if LinkedList Contain atleast One node
	{
		newn->next = *Head;
		*Head = newn;
	}
}

void Display(PNODE Head)
{
	printf("Data in the Linkedlist:");

	if (Head == NULL)
	{
		printf("	SORRY!! Your LinkedList is Empty!!\n\n");
	}
	else {
		while (Head != NULL)
		{
			printf("|%d|->", Head->data);
			Head = Head->next;
		}
		printf("__NULL__\n");
	}

}

int Count(PNODE Head)
{
	int iCnt = 0;
	while (Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}
	return iCnt;
}

void InsertLast(PPNODE Head, int value)
{
	PNODE newn = NULL;
	PNODE temp = NULL;		//create temp variable to Iterate th Node or Loop

	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;

	if (*Head == NULL)		//Empty LinkedList
	{
		*Head = newn;
	}
	else
	{
		//Travel till the last node

		temp = *Head;		//Store the Address of 1st Node in temp variable//do not touch *Head Pointer

		while (temp->next != NULL)		//temp chy next madhe Null yet nahi toparyant...
		{
			temp = temp->next;
		}

		temp->next = newn;
	}
}

void DeleteFirst(PPNODE Head)
{
	PNODE temp = NULL;

	if (*Head == NULL)		//if LinkedList is Empty
	{
		return;
	}
	else
	{
		temp = *Head;
		*Head = temp->next;
		free(temp);
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp = NULL;

	if (*Head == NULL)		//if LinkedList is Empty
	{
		return;
	}
	else if ((*Head)->next == NULL)	//if LinkedList Contain Single Node
	{
		free(*Head);
		*Head = NULL;
		temp = *Head;
	}
	else
	{
		temp = *Head;

		while (temp->next->next != NULL)		// joparyant temp mhanje *Head chya next chya next madhe NULL yet nahi toparyant... 
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;

	}

}

void InsertAtPos(PPNODE Head, int value, int Pos)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->next = NULL;
	newn->data = value;

	PNODE temp = *Head;
	int i = 0;
	int size = 0;

	size = Count(*Head);

	if ((Pos < 1) || (Pos > size + 1))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		InsertFirst(Head, value);
		printf("First Node is Updated...\n\n");

	}
	else if (Pos == size + 1)
	{
		InsertLast(Head, value);
		printf("Last Node is Updated...\n\n");

	}
	else
	{
		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		printf("Position %d Node is Updated...!!\n\n", Pos);

	}
}

void DeleteAtPos(PPNODE Head, int Pos)
{
	int size = 0;
	size = Count(*Head);

	PNODE temp1, temp2 = NULL;
	int i = 0;
	temp1 = *Head;
	if ((Pos < 1) || (Pos > size))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		DeleteFirst(Head);
		printf("First Node is Deleted!!\n\n");
	}
	else if (Pos == size)
	{
		DeleteLast(Head);
		printf("Last Node is Deleted!!\n\n");
	}
	else
	{
		for (i = 1; i < Pos - 1; i++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
		printf("Position %d Node is Deleted...!!\n\n", Pos);

	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

LinkedList: Singly Circular Linked list...

Functions:

1]	void InsertFirst(PPNODE Head,int value);
2]	void Dispaly(PNODE Head);
3]	int Count(PNODE Head);
4]	void InsertLast(PPNODE Head,int value);
5]	void DeleteFirst(PPNODE Head);
6]	void DeleteLast(PPNODE Head);
7]	void InsertAtPos(PPNODE Head,int value,int Pos);
8]	void DeleteAtPos(PPNODE Head,int Pos);
*/


void InsertFirst(PPNODE Head, PPNODE Tail, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;

	if ((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	(*Tail)->next = *Head;
}

void Display(PNODE Head, PNODE Tail)
{
	printf("Data in the Linkedlist: ->");

	if ((Head == NULL) && (Tail == NULL))
	{
		printf("SORRY!! Your LinkedList is Empty!!\n\n");

		return;
	}

	do
	{
		printf("| %d |->", Head->data);
		Head = Head->next;
	} while (Head != Tail->next);
	printf("\n");
}

int Count(PNODE Head, PNODE Tail)
{
	int iCnt = 0;
	if (Head == NULL || Tail == NULL)
	{
		return 0;
	}
	do
	{
		iCnt++;
		Head = Head->next;
	} while (Head != Tail->next);

	return iCnt;
}


void InsertLast(PPNODE Head, PPNODE Tail, int value)
{

	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;

	if ((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		*Tail = newn;
	}
	(*Tail)->next = *Head;
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
	if ((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else if (*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Tail)->next);
		(*Tail)->next = *Head;
	}
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
	if ((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else if (*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		PNODE temp = NULL;
		temp = *Head;

		while (temp->next != *Tail)
		{
			temp = temp->next;
		}
		free(temp->next);
		*Tail = temp;
		(*Tail)->next = *Head;

	}
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int value, int Pos)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;
	int size = 0;
	size = Count(*Head, *Tail);

	if ((Pos < 0) || (Pos > size + 1))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		InsertFirst(Head, Tail, value);
		printf("First Node is Updated...\n\n");

	}
	else if (Pos == size + 1)
	{
		InsertLast(Head, Tail, value);
		printf("Last Node is Updated...\n\n");

	}
	else
	{
		PNODE temp = *Head;
		temp = *Head;
		int i = 0;

		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		printf("Position %d Node is Updated...!!\n\n", Pos);

	}
}

void DeleteAtPos(PPNODE Head, PPNODE Tail, int Pos)
{
	int size = 0;
	size = Count(*Head, *Tail);

	PNODE temp1, temp2 = NULL;
	int i = 0;
	temp1 = *Head;

	if ((Pos < 1) || (Pos > size))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
	}
	else if (Pos == 1)
	{
		DeleteFirst(Head, Tail);
		printf("First Node is Deleted!!\n\n");

	}
	else if (Pos == size)
	{
		DeleteLast(Head, Tail);
		printf("Last Node is Deleted!!\n\n");

	}
	else
	{
		for (i = 1; i < Pos - 1; i++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
		printf("Position %d Node is Deleted...!!\n\n", Pos);

	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

LinkedList: Doubly Linear Linked list...

Functions:

1]	void InsertFirst(PPNODE Head,int value);
2]	void Dispaly(PNODE Head);
3]	int Count(PNODE Head);
4]	void InsertLast(PPNODE Head,int value);
5]	void DeleteFirst(PPNODE Head);
6]	void DeleteLast(PPNODE Head);
7]	void InsertAtPos(PPNODE Head,int value,int Pos);
8]	void DeleteAtPos(PPNODE Head,int Pos);

9]	void DisplayR(PNODE Head);
*/


void InsertFirstX(PPNODE Head, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->next = NULL;
	newn->prev = NULL;
	newn->data = value;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}

}

void DisplayX(PNODE Head)
{
	printf("Data in the Linkedlist:");
	if (Head == NULL)
	{
		printf("SORRY!! Your LinkedList is Empty!!\n\n");
	}
	else
	{
		printf("__NULL__");
		while (Head != NULL)
		{
			printf("| %d |<=>", Head->data);
			Head = Head->next;
		}
		printf("__NULL__\n");
	}
}

int CountX(PNODE Head)
{
	int iCnt = 0;

	while (Head != NULL)
	{
		iCnt++;
		Head = Head->next;
	}

	return iCnt;
}

void InsertLastX(PPNODE Head, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->next = NULL;
	newn->prev = NULL;
	newn->data = value;

	PNODE temp = *Head;

	if (*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
	}
}

void DeleteFirstX(PPNODE Head)
{
	if (*Head == NULL)
	{
		return;
	}
	else if ((*Head)->next == NULL)
	{
		free(*Head);
		*Head = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Head)->prev);
		(*Head)->prev = NULL;
	}
}

void DeleteLastX(PPNODE Head)
{
	PNODE temp = *Head;

	if (*Head == NULL)
	{
		return;
	}
	else if ((*Head)->next == NULL)
	{
		free(*Head);
		(*Head) = NULL;
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}
void InsertAtPosX(PPNODE Head, int value, int Pos)
{
	int size = 0;
	size = Count(*Head);
	int i = 0;


	if ((Pos < 1) || (Pos > size + 1))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		InsertFirst(Head, value);
		printf("First Node is Updated...\n\n");

	}
	else if (Pos == size + 1)
	{
		InsertLast(Head, value);
		printf("Last Node is Updated...\n\n");

	}
	else
	{
		PNODE newn = NULL;
		newn = (PNODE)malloc(sizeof(NODE));

		newn->next = NULL;
		newn->prev = NULL;
		newn->data = value;

		PNODE temp = *Head;

		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		printf("Position %d Node is Updated...!!\n\n", Pos);

	}
}

void DeleteAtPosX(PPNODE Head, int Pos)
{
	int size = 0;
	size = Count(*Head);
	int i = 0;


	if ((Pos < 1) || (Pos > size))
	{

		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		DeleteFirst(Head);
		printf("First Node is Deleted!!\n\n");

	}
	else if (Pos == size)
	{
		DeleteLast(Head);
		printf("Last Node is Deleted!!\n\n");

	}
	else
	{
		PNODE temp = *Head;

		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
		printf("Position %d Node is Deleted...!!\n\n", Pos);

	}
}

void DisplayR(PNODE Head)
{
	if (Head == NULL)
	{
		printf("SORRY!! Your LinkedList is Empty!!\n\n");
		return;
	}

	while (Head->next != NULL)
	{
		Head = Head->next;
	}
	printf("Reverse_Data in the Linkedlist:");
	printf("__NULL__<=>");

	while (Head != NULL)
	{
		printf("| %d |<=>", Head->data);
		Head = Head->prev;
	}
	printf("__NULL__\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*

LinkedList: Doubly Circular Linked list...

Functions:

1]	void InsertFirst(PPNODE Head,PPNODE Tail,int value);
2]	void Display(PNODE Head,PPNODE Tail);
3]	int Count(PNODE Head,PPNODE Tail);
4]	void InsertLast(PPNODE Head,PPNODE Tail,int value);
5]	void DeleteFirst(PPNODE Head,PPNODE Tail);
6]	void DeleteLast(PPNODE Head,PPNODE Tail);
7]	void InsertAtPos(PPNODE Head,PPNODE Tail,int value,int Pos);
8]	void DeleteAtPos(PPNODE Head,PPNODE Tail,int Pos);
*/


void InsertFirstX(PPNODE Head, PPNODE Tail, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;
	newn->prev = NULL;

	if ((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		*Head = newn;
	}
	(*Tail)->next = newn;
}

void DisplayX(PNODE Head, PNODE Tail)
{
	printf("Data in the Linkedlist: <=>");

	if ((Head == NULL) && (Tail == NULL))
	{
		printf("SORRY!! Your LinkedList is Empty!!\n\n");
		return;
	}
	do
	{
		printf("| %d |<=>", Head->data);
		Head = Head->next;
	} while (Head != Tail->next);
	printf("\n");

}

int CountX(PNODE Head, PNODE Tail)
{
	int iCnt = 0;

	if ((Head == NULL) && (Tail == NULL))
	{
		return 0;
	}
	do
	{
		iCnt++;
		Head = Head->next;
	} while (Head != Tail->next);

	return iCnt;
}

void InsertLastX(PPNODE Head, PPNODE Tail, int value)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;
	newn->prev = NULL;

	if ((*Head == NULL) && (*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		(*Head)->prev = newn;
		(*Tail)->next = newn;
		newn->prev = *Tail;
	}
	*Tail = newn;
}

void DeleteFirstX(PPNODE Head, PPNODE Tail)
{

	if ((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else if (*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Tail)->next);
	}
	(*Tail)->next = *Head;
	(*Head)->prev = *Tail;

}

void DeleteLastX(PPNODE Head, PPNODE Tail)
{
	if ((*Head == NULL) && (*Tail == NULL))
	{
		return;
	}
	else if (*Head == *Tail)
	{
		free(*Head);
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Tail = (*Tail)->prev;
		free((*Head)->prev);		//free((*Tail)->next);
	}
	(*Tail)->next = *Head;
	(*Head)->prev = *Tail;
}

void InsertAtPosX(PPNODE Head, PPNODE Tail, int value, int Pos)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));

	newn->data = value;
	newn->next = NULL;
	newn->prev = NULL;

	int size = 0;
	size = Count(*Head, *Tail);
	int i = 0;
	PNODE temp = *Head;
	if ((Pos < 1) || (Pos > size + 1))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		InsertFirst(Head, Tail, value);
		printf("First Node is Updated...\n\n");

	}
	else if (Pos == size + 1)
	{
		InsertLast(Head, Tail, value);
		printf("Last Node is Updated...\n\n");

	}
	else
	{
		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		printf("Position %d Node is Updated...!!\n\n", Pos);

	}
}

void DeleteAtPosX(PPNODE Head, PPNODE Tail, int Pos)
{
	int size = 0;
	size = Count(*Head, *Tail);
	int i = 0;
	PNODE temp = *Head;


	if ((Pos < 1) || (Pos > size + 1))
	{
		printf("SORRY!! Invalid Position!!!\n\n");
		return;
	}
	else if (Pos == 1)
	{
		DeleteFirst(Head, Tail);
		printf("First Node is Deleted!!\n\n");

	}
	else if (Pos == size)
	{
		DeleteLast(Head, Tail);
		printf("Last Node is Deleted!!\n\n");

	}
	else
	{
		for (i = 1; i < Pos - 1; i++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
		printf("Position %d Node is Deleted...!!\n\n", Pos);

	}
}




int main()
{
	PNODE First = NULL;
	PNODE Last = NULL;

	int no = 0;
	int iRet = 0;
	int Pos = 0;
	int Choice = 1;
	
	printf("%ld", sizeof(NODE));


	while (Choice)	//Terminates when Choice variable contain 0;
	{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Welcome To LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

		printf("  >> Please Select The LinkedList:- \n\n");

		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		
		printf("	1: Singly Linear LinkedList \n	2: Singly Circular LinkedList \n	3: Doubly Linear LinkedList \n	4: Doubly Circular LinkedList \n	0:Exit \n");
		
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");

		printf("\nYour Selection Number is:  ");
		scanf("%d", &Choice);

		switch (Choice)
		{
		case 1:

			while (Choice)	//Terminates when Choice variable contain 0;
			{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Welcome To Singly Linear LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

				printf("---------------------------------------------------------------------------------\n");

				printf("  >> Please Enter Your Choice:- \n\n");

				printf("---------------------------------------------------------------------------------\n");
				printf("	1: InsertFirst \n	2: InsertLast \n	3: InsertAtPos \n	4: DeleteFirst \n	5: DeleteLast \n	6: DeleteAtPos \n");
				printf("	7: Display \n	8: Count \n	0: Exit \n");

				printf("---------------------------------------------------------------------------------\n");

				printf("\nYour Choice Number is:	");
				scanf("%d", &Choice);

				switch (Choice)
				{
				case 1:
				
					printf("Enter the First Number:	");
					scanf("%d", &no);
					InsertFirst(&First, no);
					printf("LinkedList is Updated...\n\n");
					break;
				
				case 2:

					printf("Enter the Last Number:	");
					scanf("%d", &no);
					InsertLast(&First, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 3:

					printf("Enter the Position of Node Which you add:  ");
					scanf(" %d", &Pos);
					printf("Enter the Data of Node:	");
					scanf(" %d", &no);

					InsertAtPos(&First, no, Pos);

					break;

				case 4:

					DeleteFirst(&First);
					printf("First Node is Deleted!!\n\n");
					break;

				case 5:

					DeleteLast(&First);
					printf("Last Node is Deleted!!\n\n");
					break;

				case 6:

					printf("Which Position Node do you want to Delete?  :");
					scanf("%d", &Pos);
					DeleteAtPos(&First, Pos);
					break;

				case 7:

					Display(First);
					printf("\n");
					break;

				case 8:

					iRet = Count(First);
					printf("\nThere is %d Node(s) avaliable in LinkedList...\n\n", iRet);
					if (iRet == 0)
					{
						printf("SORRY!! Your LinkedList is Empty!!\n\n");
					}
					break;
				case 0:
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Thank You for Using Singly Linear LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					break;
				default:
					printf(">>Wrong Choice!!\n\n");
					break;
				}
			}
			

		case 2:
					
			
				while (Choice)	//Terminates when Choice variable contain 0;
			{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Welcome To Singly Circular LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
				printf(">>>>>>>>>>------------------------------------------------------------------>>>>>>>>>>\n");

				printf("  >> Please Enter Your Choice:- \n\n");

				printf(">>>>>>>>>>------------------------------------------------------------------>>>>>>>>>>\n");
				printf("	1: InsertFirst \n	2: InsertLast \n	3: InsertAtPos \n	4: DeleteFirst \n	5: DeleteLast \n	6: DeleteAtPos \n");
				printf("	7: Display \n	8: Count \n	0: Exit \n");

				printf(">>>>>>>>>>------------------------------------------------------------------>>>>>>>>>>\n");

				printf("\nYour Choice Number is:	");
				scanf("%d", &Choice);

				switch (Choice)
				{
				case 1:

					printf("Enter the First Number:	");
					scanf("%d", &no);
					InsertFirst(&First, &Last, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 2:

					printf("Enter the Last Number:	");
					scanf("%d", &no);
					InsertLast(&First, &Last, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 3:

					printf("Enter the Position of Node Which you add:  ");
					scanf(" %d", &Pos);
					printf("Enter the Data of Node:	");
					scanf(" %d", &no);

					InsertAtPos(&First, &Last, no, Pos);

					break;


				case 4:

					DeleteFirst(&First, &Last);
					printf("First Node is Deleted!!\n\n");
					break;

				case 5:

					DeleteLast(&First, &Last);
					printf("Last Node is Deleted!!\n\n");
					break;

				case 6:

					printf("Which Position Node do you want to Delete?  :");
					scanf("%d", &Pos);
					printf("\n");
					DeleteAtPos(&First, &Last, Pos);
					break;

				case 7:

					Display(First, Last);
					printf("\n");
					break;

				case 8:

					iRet = Count(First, Last);
					printf("\nThere is %d Node(s) avaliable in LinkedList...\n\n", iRet);
					if (iRet == 0)
					{
						printf("SORRY!! Your LinkedList is Empty!!\n\n");
					}
					break;

				case 0:
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Thank You for Using Singly Cicular LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					break;


				default:
					printf(">>Wrong Choice!!\n\n");
					break;
				}
			}


		case 3:


			while (Choice)	//Terminates when Choice variable contain 0;
			{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Welcome To Doubly Linear LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
				printf("=================================================================================\n");
				printf("  >> Please Enter Your Choice:- \n\n");

				printf("=================================================================================\n");
				printf("	1: InsertFirst \n	2: InsertLast \n	3: InsertAtPos \n	4: DeleteFirst \n	5: DeleteLast \n	6: DeleteAtPos \n");
				printf("	7: Display \n	8: Count \n	9: DisplayReverse \n	0: Exit \n");

				printf("=================================================================================\n");

				printf("\nYour Choice Number is:	");
				scanf("%d", &Choice);

				switch (Choice)
				{
				case 1:
				{
					printf("Enter the First Number:	");
					scanf("%d", &no);
					InsertFirstX(&First, no);
					printf("LinkedList is Updated...\n\n");
					break;
				}
				case 2:

					printf("Enter the Last Number:	");
					scanf("%d", &no);
					InsertLastX(&First, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 3:

					printf("Enter the Position of Node Which you add:  ");
					scanf(" %d", &Pos);
					printf("Enter the Data of Node:	");
					scanf(" %d", &no);

					InsertAtPosX(&First, no, Pos);

					break;

				case 4:

					DeleteFirstX(&First);
					printf("First Node is Deleted!!\n\n");
					break;

				case 5:

					DeleteLastX(&First);
					printf("Last Node is Deleted!!\n\n");
					break;

				case 6:

					printf("Which Position Node do you want to Delete?  :");
					scanf("%d", &Pos);
					DeleteAtPosX(&First, Pos);
					break;

				case 7:

					DisplayX(First);
					printf("\n");
					break;

				case 8:

					iRet = CountX(First);

					printf("There is %d Node(s) avaliable in LinkedList...\n\n", iRet);

					if (iRet == 0)
					{
						printf("SORRY!! Your LinkedList is Empty!!\n\n");
					}
					break;
				case 9:
					DisplayR(First);
					break;

				case 0:

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Thank You for Using Doubly Linear LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					break;


				default:

					printf(">>Wrong Choice!!\n\n");
					break;
				}
			}
		case 4:


			while (Choice)	//Terminates when Choice variable contain 0;
			{
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Welcome To Doubly Circular LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
			printf("<<<<<<<<<<=============================================================>>>>>>>>>>\n");

				printf("  >> Please Enter Your Choice:- \n\n");

				printf("<<<<<<<<<<=============================================================>>>>>>>>>>\n");
				printf("	1: InsertFirst \n	2: InsertLast \n	3: InsertAtPos \n	4: DeleteFirst \n	5: DeleteLast \n	6: DeleteAtPos \n");
				printf("	7: Display \n	8: Count \n	0: Exit \n");

				printf("<<<<<<<<<<=============================================================>>>>>>>>>>\n");

				printf("\nYour Choice Number is:	");
				scanf("%d", &Choice);

				switch (Choice)
				{
				case 1:

					printf("Enter the First Number:	");
					scanf("%d", &no);
					InsertFirstX(&First, &Last, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 2:

					printf("Enter the Last Number:	");
					scanf("%d", &no);
					InsertLastX(&First, &Last, no);
					printf("LinkedList is Updated...\n\n");
					break;

				case 3:

					printf("Enter the Position of Node Which you add:  ");
					scanf(" %d", &Pos);
					printf("Enter the Data of Node:	");
					scanf(" %d", &no);

					InsertAtPosX(&First, &Last, no, Pos);

					break;

				case 4:

					DeleteFirstX(&First, &Last);
					printf("First Node is Deleted!!\n\n");
					break;

				case 5:

					DeleteLastX(&First, &Last);
					printf("Last Node is Deleted!!\n\n");
					break;

				case 6:

					printf("Which Position Node do you want to Delete?  :");
					scanf("%d", &Pos);

					DeleteAtPosX(&First, &Last, Pos);
					break;

				case 7:

					DisplayX(First, Last);
					printf("\n");
					break;

				case 8:

					iRet = CountX(First, Last);
					printf("\nThere is %d Node(s) avaliable in LinkedList...\n\n", iRet);
					if (iRet == 0)
					{
						printf("SORRY!! Your LinkedList is Empty!!\n\n");
					}
					break;

				case 0:
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Thank You for Using Doubly Circular LinkedList <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					break;


				default:
					printf(">>Wrong Choice!!\n\n");
					break;
				}

			}

		case 0:
			break;

		default:
			printf(">>Wrong Choice!!\n\n");
			break;
		}
	}

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>> Thank You For Using Application <<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

	return 0;
}
