#include <conio.h>
#include <iostream>


typedef struct datanode {
    int number;
    struct datanode *next;
}data;

data *headA = NULL,*endA = NULL;
data *headB = NULL,*endB = NULL;
data *headC = NULL,*endC = NULL;
data *deposit = NULL,*endDeposit = NULL;

data* newNode(int n);
void insertNode(data* ptr, data* &head,data* &end);
void printNode(data *ptr);
void printList(data *ptr);
data* searchNode(int keyword, data* &head);
void deleteNode(data *ptr, data* &head,data *&end);
void unionNode(data* headA,data* headB);

int main(){
	data *tmp;
	int ch,number;
	do{
        system("cls");
        printf("\n\tPlease select an option \n");
		printf("\n 1 Add number set A\n");
		printf(" 2 Add number set B\n");
		printf(" 3 Menbers of set A\n");
		printf(" 4 Menbers of set B\n");
		printf(" 5 Search for menber set A\n");
		printf(" 6 Search for menber set B\n");
		printf(" 7 Delete for menber set A\n");
		printf(" 8 Delete for menber set B\n");
		printf(" 9 C = A - B\n");
		printf(" 0 Exit\n");
		printf("\n\tEnter choice :");
		scanf("%d",&ch);
        
        switch (ch) {
            case 1:
                     printf("Enter Number Set A : ");
                    scanf("%d",&number);
                    tmp = newNode(number);
                    insertNode(tmp, headA,endA);
                    insertNode(tmp,headC,endC);
                    break;

            case 2: 
                	printf("Enter Number Set B : ");
                    scanf("%d",&number);
                    tmp = newNode(number);
                    insertNode(tmp, headB,endB);
                    insertNode(tmp,headC,endC);
                    getch();
                    break;
			case 3 :
				    if(headA != NULL){
				    	printList(headA);
				    	printf("\n--------------Press again to clear--------------");
					    getch();
					}else{
					printf("\n { }\n");
					printf("\n--------------Press again to clear--------------");
					getch();
				    }
				    break;
			case 4 :
				    if(headB != NULL){
				    	printList(headB);
				    	printf("\n--------------Press again to clear--------------");
					    getch();
					}else{
					printf("\n { }\n");
					printf("\n--------------Press again to clear--------------");
					getch();}
				    break;
			case 5 :
					printf("Enter Keyword Set A : ");
                    scanf("%d",&number);
	        		tmp = searchNode(number, headA);
	        		if(tmp == NULL){
	        		     printf("Search %d not found\n",number);
					     printf("\n--------------Press again to clear--------------");
						getch();
					}
					else{
						printNode(tmp);
						printf("\n--------------Press again to clear--------------");
						getch();
					}
			    	break;
			case 6 :
					printf("Enter Keyword Set B : ");
                    scanf("%d",&number);
	        		tmp = searchNode(number, headB);
	        		if(tmp == NULL){
	        		     printf("Search %d not found\n",number);
	        		     printf("\n--------------Press again to clear--------------");
						getch();
					}
					else{
						printNode(tmp);
						printf("\n--------------Press again to clear--------------");
						getch();
					}
				    break;
			case 7 :
					 printf("Enter keyword a set A : ");
	        		 scanf("%d",&number);
	        		tmp = searchNode(number, headA);
	        		if(tmp == NULL){
	        			printf("Search %d not found\n",number);
	        			printf("\n--------------Press again to clear--------------");
						getch();
					}
					else{
						deleteNode(tmp, headA,endA);
						printf("\n  Delete complete\n");
						printf("\n--------------Press again to clear--------------");
						getch();
					}
				    break;
			case 8 :
					printf("Enter keyword a set B : ");
	        		scanf("%d",&number);
	        		tmp = searchNode(number, headB);
	        		if(tmp == NULL){
	        			 printf("Search %d not found\n",number);
	        			 printf("\n--------------Press again to clear--------------");
						getch();
					}
					else{
						deleteNode(tmp, headB,endB);
						printf("\n  Delete complete\n");
						printf("\n--------------Press again to clear--------------");
						getch();
					}
				    break;
			case 9 :

		    if(headC != NULL){
				    	printList(headC);
				    	printf("\n--------------Press again to clear--------------");
				    	getch();
					}else{
						printf("{ }");
						printf("\n--------------Press again to clear--------------");
						getch();
					}
					
					headC = NULL;
					endC = NULL; 
					
					deposit = NULL;
					endDeposit = NULL;
					
					getch();
				   break;
			case 0 : break;
			default:
				
				printf("\n------------------Please try again----------------------");
				getch();
        }
    }while(ch != 0);

    return 0;
}

data* newNode(int number){
	data *tmp;
	tmp = new data;
	if (tmp == NULL){
		return (NULL);
	}else {
		tmp->number = number;
		tmp->next = NULL;
		return (tmp);	
	}
} 

void insertNode(data* ptr, data* &head,data* &end){ 
	
	data *start, *prev;
    
	if(head == NULL){
		head = ptr;
		end = ptr;
		return ;
	} 
	
    start = head;
	
    do{
		if(start->number == ptr->number){
			delete(ptr);
			return;
		}
		start = start->next;
	}while(start != NULL);

	start = head;

	while(start->number < ptr->number){
		start = start->next;
		if(start == NULL) break;
	}

	if(start == head){
		ptr->next = head;
		head = ptr;
	}else{
		prev = head;
		while(prev->next != start){
			prev = prev->next;
		}
		prev->next = ptr;
		ptr->next = start;
		if(end == prev){
			end = ptr;
		}
	}
}

void printNode(data *ptr){
	printf(" %3d,\0.5t", ptr->number);
}

void printList(data *ptr){
	int i = 0;

	while (ptr != NULL){
		printNode(ptr);
		if(i == 10){
			printf("\n");
		}
		i++;
		if(i > 10){
			i = 0;
		}
		ptr = ptr->next;
	}
}

data* searchNode(int keyword, data* &head){
	data *ptr;
	ptr = head;
	if (ptr == NULL){
		return (NULL);
	}
	while(keyword != ptr->number){
		ptr = ptr->next;
		if(ptr == NULL){
			break;
		}	
	}
	return (ptr);
}

void deleteNode(data *ptr, data* &head,data *&end){
	data *start, *prev;
	start = ptr;
   	if(start == head){
		head = head->next;
		if(end == start){
			end = head->next;
		}
		delete(start);
	}else{
		prev = head;
		while(prev->next != start){
			prev = prev->next;
		}
		prev->next = start->next;
		if(end == start){
			end = prev;
		}
		delete(start);
	}
}
 
