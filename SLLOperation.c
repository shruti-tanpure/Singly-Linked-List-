
#include<stdio.h>
#include<stdlib.h>

struct SLLNode
{
	int data;
	struct SLLNode *next;     //self refrencing structure
};

int main(void)
{
	int ch = 0 ;
	int num = 0 ;
	int cnt = 0 ;
	int d = 0 ;
	int j = 0;
	int find = 0;
	int flag=0;
	int arr[20] = {0};
	int max = 0 ;
	struct SLLNode *rev_arr[20] ;
	struct SLLNode *head = NULL ;
	struct SLLNode *last = NULL ;
	struct SLLNode *new = NULL;
	struct SLLNode *p = NULL;
	struct SLLNode *q = NULL;
	struct SLLNode *i = NULL;
	struct SLLNode *dnode = NULL;
	
	do
	{
		printf("Enter choice\n1.Create\n2.Insert in the beginning\n3.Insert at the end\n4.Insert in between first and second nodes\n5. Delete node - first\n6. Delete node - last\n7. Delete node - in between\n8. Display linked list data\n9. Display linked list in reverse\n10. Reverse linked list - data\n11. Reverse linked list - nodes\n12. Find maximum no in the linked list nodes\n0. Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:   //create nodes
				if(cnt==0)
				{
					printf("Enter number of nodes to be created");
					scanf("%d",&num);
					while(num>0 )
					{
						new = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
						
						if(new == NULL)
						{
							printf("Memory allocation failed");
						}
						else
						{
							printf("Enter data of the node to be created\n");
							scanf("%d",&d);
							new->data = d;
							if(head == NULL)
							{
								head = new ;
								last = new ;
							}
							else
							{
								last->next = new;
								last = new ;
							}
							printf("Node created\n");
							
						}
						num--;
					}
					cnt++;
				}
				else
				{
					printf("Linked List already created\n");
				}
				break;
			
		
			case 2:     //Insert in the beginning
				printf("Enter data for the node\n");
				scanf("%d",&d);
				new = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if(new == NULL)
				{
					printf("Memory allocation failed\n");
				}
				else
				{
					new->data = d;
					if(head == NULL)
					{
						head = new ;
						last = new ;
					}
					else
					{
						new->next = head;
						head = new ;
					}
					printf("Node prepended\n");
				}
				break;
				
			case 3:    //Insert at the end
				printf("Enter data for the node\n");
				scanf("%d",&d);
				new = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if(new == NULL)
				{
					printf("Memory allocation failed\n");
				}
				else
				{
					new->data = d;
					if(head == NULL)
					{
						head = new ;
						last = new ;
					}
					else
					{
						last->next=new;
						last = new;
					}
					printf("Node apended\n");
				}
				break;
			
			case 4:    //Insert in between 
				printf("Enter data for the node to be inserted\n");
				scanf("%d",&d);
				new = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if(new == NULL)
				{
					printf("Memory allocation failed\n");
				}
				else
				{
					new->data = d;
					if(head == NULL)
					{
						head = new ;
						last = new ;
					}
					else
					{
						new->data = d;
						printf("Enter data after which node is to be inserted"); 
						scanf("%d",&find);
						for(i=head;i!=NULL;i=i->next)
						{
							if(i->data = find)
							{
								p = i;
								q=p->next;
								p->next = new;
								new->next = q;
								i=last;
								
							}
						}
					}
					printf("Node added\n");
				}
				break;
				
			case 5:
				printf("Enter data of node to be deleted\n");
				scanf("%d",&d);
				dnode = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if (head == NULL) 
				{ 
					printf("Linked list does not exist\n");
				} 
				else 
				{ 
					dnode = head ; // Assign Head to Dnode 
					if (head == last) 
					{ 
						head = NULL ; // Set Head & Last to NULL  
						last = NULL ; // As the Linked list contains only one node 
					} 
					else 
					{ 
						head = head->next ; // Set Head to Next node 
						dnode->next = NULL ; // Separate Dnode from the linked list
					} 
				
					free(dnode) ; 
					dnode = NULL ; 
					printf("Node deleted\n");
				}

				break;
				
			case 6:
				printf("Enter data of node to be deleted\n");
				scanf("%d",&d);
				dnode = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if (head == NULL) 
				{ 
					printf("Linked list does not exist\n");
				} 
				else 
				{ 
					dnode = head ; // Assign Head to Dnode 
					if (head == last) 
					{ 
						head = NULL ; // Set Head & Last to NULL  
						last = NULL ; // As the Linked list contains only one node 
					} 
					else 
					{ 
						i=head;
						while(i->next!=last)
						{
							i=i->next;
						}
						dnode = i->next ;
						last = i ;
						last->next = NULL ;
						free(dnode) ;
						dnode = NULL ;
						i = NULL ; 
					}
					printf("Node deleted\n");
				}

				break;
				
			case 7:
				printf("Enter data of node to be deleted\n");
				scanf("%d",&d);
				dnode = (struct SLLNode *)calloc(1,sizeof(struct SLLNode));
				if (head == NULL) 
				{ 
					printf("Linked list does not exist\n");
				} 
				else 
				{ 
					i=head;
					while(i!=NULL)
					{
						if(i->next->data == d)
						{
							p=i;
							i=NULL;
						}
						else
						{
							i=i->next;
						}
					}
					if (p != NULL)
					{
						dnode = p->next ;
						q = dnode->next ;
						dnode->next = NULL ;
						p->next = q ;
						free(dnode) ;
						dnode = NULL ;
						p=NULL;
						q=NULL;
						i=NULL;
					}
					printf("node deleted\n");
				}
				
				break;
				
			case 8 :
				i=head;
				while(i!=NULL)
				{
					printf("Element = %d\n",i->data);
					i=i->next;
				}
				break;
			
			case 9:
				j=0;
				i=head;
				while(i!=NULL)
				{
					arr[j] = i->data;
					i=i->next;
					j++;
				}
				for(j=j-1;j>=0;j--)
				{
					printf("Element = %d\n",arr[j]);
				}
				break;
				
			case 10:
				j=0 ;
				i=head ;
				while(i!=NULL)
				{
					arr[j] = i->data;
					i=i->next;
					j++;
				}
				
				i=head ;
				for(j=j-1;j>=0;j--)
				{
					i->data = arr[j];
					i=i->next;
				}
				i=NULL;
				printf("Reversed the data\n");
				break;
			
			case 11 :
				j=0;
				i=head;
				while(i!=NULL)
				{
					rev_arr[j] = i;
					i=i->next;
					j++;
				}
				head = rev_arr[j-1];
				for(j=j-1;j>=0;j--)
				{
					if(j>=1)
					{
						rev_arr[j]->next=rev_arr[j-1];
					}
					else
					{
						rev_arr[j]->next = NULL;
					}
				}
				printf("Order of nodes is reversed\n");
				break;
				
			case 12 :
				i = head;
				max=i->data;
				while(i != NULL)
				{
					if(max<i->data)
					{
						max = i->data;
					}
					i=i->next;
				}
				printf("Maximum of the numbers is = %d\n",max);
				break;
		}
	
	}while(ch > 0 && ch <=12 );
	
	return 0;
}






