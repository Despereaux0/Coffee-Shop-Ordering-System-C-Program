#include <stdio.h>
#include <stdlib.h>

#include "staff.h"
#include "order.h"

int main()
{
	printf("DOSTA COFFEE SHOP ORDERING SYTEM: ");
	printf("\n");

	while (1)
	{
		int no;
		printf("ENTER 1 FOR STAFF ");
		printf("\n");
		printf("ENTER 2 FOR REGISTERED CUSTOMERS ");
		printf("\n");
		printf("ENTER 3 FOR FIRST TIME CUSTOMER ");
		printf("\n");
		printf("ENTER 4 FOR MENU ");
		printf("\n");
		printf("ENTER 5 FOR EXIT ");
		printf("\n");
		scanf("%d", &no);

		if (no == 1)
		{
			system("cls");
			printf("HELLO WELCOME STAFF MEMBER");
			printf("\n");

			while (1)
			{
				int no;
				printf("ENTER 1 FOR ADDING NEW ITEM ");
				printf("\n");
				printf("ENTER 2 TO UPDATE THE MENU ");
				printf("\n");
				printf("ENTER 3 TO SEARCH ORDER");
				printf("\n");
				printf("ENTER 4 TO GO BACK TO THE MAIN MENU ");
				printf("\n");
				printf("ENTER 5 TO EXIT ");
				printf("\n");
				scanf("%d", &no);

				if (no == 1)
				{
					int id;
					printf("ENTER FOOD ID: ");
					scanf("%d", &id);

					char name[20];
					printf("ENTER FOOD NAME: ");
					scanf("%s", name);


					int p;
					printf("ENTER PRICE: ");
					scanf("%d", &p);

					int q;
					printf("ENTER QUANTITY: ");
					scanf("%d", &q);

					add_item(id, name, p, q);
				}
				else if (no == 2)
				{

					int id;
					printf("ENTER FOOD ID YOU WANT TO UPDATE: ");
					scanf("%d", &id);

					char name[20];
					printf("ENTER NEW FOOD NAME: ");
					scanf("%s", name);


					int p;
					printf("ENTER NEW PRICE: ");
					scanf("%d", &p);

					int q;
					printf("ENTER NEW QUANTITY: ");
					scanf("%d", &q);

					update_menu(id, name, p, q);

				}
				else if (no == 3)
				{
					int id;
					printf("ENTER CUSTOMERS ID: ");
					scanf("%d", &id);
					showOrders(id);
				}
				else if (no == 4)
				{
					break;
				}else if (no == 5)
				{
					exit(1);
				}


			}

		}
		else if (no == 2)
		{
			
			system("cls");
			printf("PLEASE LOGIN TO YOUR ACCOUNT: ");
			printf("\n");
			
			int id;
			printf("ENTER YOUR ID: ");
			scanf("%d", &id);

			char pass[40];
			printf("ENTER YOUR PASSWORD: ");
			scanf("%s", pass);

			int login = checkcstLogin(id, pass);
			
			if (checkcstLogin(id, pass) == 1)
			{
				system("cls");
				do {
					int choice = showCustMenu();
					if (choice == 1) {
						char name[20];
						printf("ENTER NEW NAME: ");
						scanf("%s", name);

						//char password[40];
						printf("ENTER NEW PASSWORD: ");
						scanf("%s", pass);

						update_details(id, name, pass);
	
					} else if (choice == 2) {

						showmenu();
	
						int idd;
						printf("TELL THE FOOD ID: ");
						scanf("%d", &idd);
	
						int orderid;
						printf("TELL THE ORDER No: ");
						scanf("%d", &orderid);

						int orderqty;
						printf("TELL THE QUANTITY ORDERED: ");
						scanf("%d", &orderqty);

						if (check(idd) == 0) {
							printf("FOOD ID NOT FOUND!\n");
							continue;
						}	
						
						if (search_order(orderid, id)==1) {
							printf("ORDER N° ALREADY EXISTS FOR YOU!\n");
							continue;	
						}
						
						if (place_order(orderid, id, idd, orderqty)==1) {
						
							system("cls");
							printf("HERE IS YOUR RECEPIT: ");
							printf("\n");
							menu_rec(idd, orderqty);
						} else 
							continue;

					} else if (choice == 3) {

						showOrders(id);

						int orderid;
						printf("TELL THE ORDER ID TO CANCEL: ");
						scanf("%d", &orderid);

						if (cancel_order(orderid, id)==1) {
					
							printf("ORDER SUCCESSFULLY CANCELED.");
							printf("\n");
						} else {
							printf("ORDER ID DOES NOT EXIST!");
							printf("\n");
						}	
				
				
					} else {
						break;
					}
				} while (1);
								

			}
			else
			{
				printf("WRONG ID or PASSWORD");
				printf("\n");
			}


		}
		else if (no == 3)
		{
			system("cls");
			printf("WELCOME TO THE COFFEE HOUSE, PLS REGISTERED YOUR ACCOUNT: ");
			printf("\n");
			
			int id;
			printf("ENTER YOUR ID: ");
			scanf("%d", &id);

			char name[20];
			printf("ENTER YOUR NAME: ");
			scanf("%s", name);


			char password[20];
			printf("ENTER YOUR PASSWORD: ");
			scanf("%s", password);

			register_cust(id, name, password);

			
			


		}
		else if (no == 4)
		{
			system("cls");
			showmenu();
		}
		else if(no==5)
		{
			break;
		}

	}




}