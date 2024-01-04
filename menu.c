#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int size_of_file()
{
	FILE* fptr;

	fptr = fopen("menu.txt", "r");
	int line = 0;
	char str[100];
	while (fgets(str, 100, fptr))
	{
		line++;
	}
	fclose(fptr);
	
	return line;

}

int check(int iddddd)
{
	int size = size_of_file();

	struct menu* m = (struct menu*)malloc(size * (sizeof(struct menu)));

	FILE* ptr;
	ptr = fopen("menu.txt", "r");
	if (ptr == NULL)
	{
		printf("FILE \"menu.txt\" NOT FOUND!");
		return -1;
	}
	for (int i = 0; i < size; i++)
	{
		fscanf(ptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity);

	}
	fclose(ptr);

	for (int i = 0; i < size; i++)
	{
		if (m[i].id == iddddd)
		{
			return 1;	
		}


	}

	return 0;

}

void add_item(int id, char* name, int price, int quantity)
{

	if (check(id) == 0)
	{

		FILE* ptr = fopen("menu.txt", "a");

		if (ptr == NULL)
		{
			printf("FILE \"menu.txt\" NOT FOUND!");
			return;
		}

		fprintf(ptr, "\n%d %s %d %d", id, name, price, quantity);

		printf("SUCCESFULLY ADDED");
		printf("\n");
		fclose(ptr);
	}
	else
	{
		printf("ITEM ID ALREADY EXISTS");
		printf("\n");
	}

}

void showmenu()
{

	int size = size_of_file();

	FILE* ptr;
	ptr = fopen("menu.txt", "r");

	if (ptr == NULL)
	{
		printf("FILE \"menu.txt\" NOT FOUND!");
		return;
	}


	struct menu* m = (struct menu*)malloc(size * (sizeof(struct menu)));

	int i = 0;
	printf("%-6s %-15s %-9s %-6s\n", "id", "name", "price", "quantity");
	printf("-------------------------------------------\n");
	while (fscanf(ptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity) != EOF)
	{
		printf("%-6d %-15s %-9d %-6d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
		i++;
	}
	
	printf("\n");

	fclose(ptr);

}

void menu_rec(int id, int qty)
{

	int size = size_of_file();

	FILE* ptr;
	ptr = fopen("menu.txt", "r");

	if (ptr == NULL)
	{
		printf("FILE \"menu.txt\" NOT FOUND!");
		return;
	}

	
	struct menu* m = (struct menu*)malloc(size * (sizeof(struct menu)));
	int i=0;
	while (fscanf(ptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity) != EOF)
	{
		if (id == m[i].id)
			break;
		i++;
	}

	fclose(ptr);

	int total = qty * m[i].price;

	printf("YOUR TOTAL BILL IS: %d", total);
	printf("\n");

}