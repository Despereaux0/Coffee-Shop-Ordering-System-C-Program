#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "order.h"


int place_order(int order_number, int cust_no,int foodid, int qtyOrder)
{
	
	int size = size_of_file();

	FILE* ptr;
	ptr = fopen("menu.txt", "r");
	if (ptr == NULL)
	{
		printf("FILE \"menu.txt\" NOT FOUND!");
		return -1;
	}

	struct menu* m = (struct menu*)malloc(size * (sizeof(struct menu)));

	int rank = 0;
	for (int i = 0; i < size; i++)
	{
		fscanf(ptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity);
		if (m[i].id == foodid) {
			rank = i;
		}
	}
	fclose(ptr);

	if (qtyOrder > m[rank].quantity) {
		printf("FAILED! ORDER QUANTITY GREATHER THAN ITEM QUANTITY.\n\n");
		return 0;
	}
	

	ptr = fopen("order.txt", "a");
	if (ptr == NULL)
	{
		printf("FILE \"order.txt\" NOT FOUND!");
		return -1;
	}

	m[rank].quantity = m[rank].quantity - qtyOrder;
	
	fprintf(ptr, "\n%d %d %d %d", order_number, cust_no, foodid, qtyOrder);
	fclose(ptr);

	ptr = fopen("menu.txt", "w");
	for (int i = 0; i < size; i++)
	{
		fprintf(ptr, "%d %s %d %d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
	}
	fclose(ptr);

	printf("YOUR ORDER HAS SUCCESSFULLY PLACED");
	printf("\n");
    
     	return 1;
}

int sizeofileorder()
{
	FILE *fptr;

	fptr = fopen("order.txt", "r");

	int line = 0;
	char str[100];
	while (fgets(str, 100, fptr))
	{
		line++;
	}
	fclose(fptr);
	return line;
}

int search_order(int id, int custId)
{

	int size = sizeofileorder();

	FILE *ptr = fopen("order.txt", "r");
	if (ptr == NULL) {
		printf("FILE \"order.txt\" NOT FOUND!");
		return-1;
	}
	

	int n1;
	int n2;
	int n3;
	int n4;
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		fscanf(ptr, "%d %d %d %d", &n1, &n2, &n3, &n4);

		if (n1 == id && custId == n2)
		{
			f = 1;
			break;
		}
	}
	fclose(ptr);
	return f; 
}

int cancel_order(int id, int custId)
{

	int size = sizeofileorder();

	FILE *ptr = fopen("order.txt", "r");
	if (ptr == NULL) {
		printf("FILE \"order.txt\" NOT FOUND!");
		return-1;
	}

	struct order* o = (struct order*)malloc(size*(sizeof(struct order)));
	
	int idItem = 0;
	int qtyOrdered = 0;
	
	for (int i = 0; i < size; i++)
	{
		fscanf(ptr, "%d %d %d %d", &o[i].order_no, &o[i].cust_no, &o[i].foodid, &o[i].qtyOrder);
		if (id == o[i].order_no && custId == o[i].cust_no) 
		{
			qtyOrdered = o[i].qtyOrder;
			idItem = o[i].foodid;
		}
	}
	fclose(ptr);

	int sizeMenu = size_of_file();

	ptr = fopen("menu.txt", "r");
	if (ptr == NULL)
	{
		printf("FILE \"menu.txt\" NOT FOUND!");
		return -1;
	}

	

	struct menu* m = (struct menu*)malloc(sizeMenu * (sizeof(struct menu)));

	int rankItem = 0;
	for (int i = 0; i < sizeMenu; i++)
	{
		fscanf(ptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity);
		if (m[i].id == idItem) {
			rankItem = i;
		}
	}
	fclose(ptr);

	ptr = fopen("order.txt", "w");
	if (ptr == NULL) {
		printf("FILE \"order.txt\" NOT FOUND!");
		return-1;
	}
	int f = 0;
	for (int i = 0; i < size; i++)
	{
		if (id == o[i].order_no && custId == o[i].cust_no)
		{
			f = 1;
		} else {
			fprintf(ptr, "%d %d %d %d", o[i].order_no, o[i].cust_no, o[i].foodid, o[i].qtyOrder);
			fprintf(ptr, "\n");
		}
	}
	fclose(ptr);

	ptr = fopen("menu.txt", "w");
	if (ptr == NULL) {
		printf("FILE \"menu.txt\" NOT FOUND!");
		return-1;
	}
	for (int i = 0; i < sizeMenu; i++)
	{
		if (i == rankItem)
		{
			m[i].quantity = m[i].quantity + qtyOrdered;
		} 
			
		fprintf(ptr, "%d %s %d %d", m[i].id, m[i].name, m[i].price, m[i].quantity);
		fprintf(ptr, "\n");
		
	}
	fclose(ptr);	

	return f;

}

void showOrders(int custId) {

	int size = sizeofileorder();

	FILE *ptr = fopen("order.txt", "r");
	if (ptr == NULL) {
		printf("FILE \"order.txt\" NOT FOUND!");
		return;
	}
	
	
	struct order* o = (struct order*)malloc(size*(sizeof(struct order)));
	int f = 0;
        for (int i = 0; i < size; i++)
	{
		fscanf(ptr, "%d %d %d %d", &o[i].order_no, &o[i].cust_no, &o[i].foodid, &o[i].qtyOrder);
		if (o[i].cust_no == custId) {
			f = 1;
			printf("No order: %d, Item Id: %d, Quantity: %d", o[i].order_no, o[i].foodid, o[i].qtyOrder);
			printf("\n");
		}
	}
	fclose(ptr);
	if (f == 0) {
		printf("NO ORDER FOR THIS CUSTOMER.\n");
	}
	
}