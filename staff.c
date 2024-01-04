#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "staff.h"



void update_menu(int id,char *name,int price,int quantity)
{
	int size = size_of_file();
	
	struct menu* m=(struct menu*)malloc(size*(sizeof(struct menu)));

	FILE *fptr;
	fptr = fopen("menu.txt", "r");
	int i = 0;
	printf("\n");
	while(fscanf(fptr, "%d %s %d %d", &m[i].id, m[i].name, &m[i].price, &m[i].quantity) != EOF)
	{
		printf("%d %s %d %d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
		i++;
	}
	

	int f = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (m[i].id == id)
		{
			strcpy(m[i].name, name);
			m[i].price = price;
			m[i].quantity = quantity;
			f = 1;
		}
	}
	fclose(fptr);
	FILE *temp = fopen("menu.txt", "w");
	if (f == 0)
	{
		printf("\nTHIS DOSENT EXIST\n");
	}
	else
	{   
		for (int k = 0; k < i; k++)
		{
			fprintf(temp, "%d %s %d %d\n", m[k].id, m[k].name, m[k].price, m[k].quantity);
		}
		fclose(temp);
		printf("\nNew menu is :\n");
		printf("\n");
		for (int k = 0; k < i; k++)
		{
			printf("%d %s %d %d\n", m[k].id, m[k].name, m[k].price, m[k].quantity);
		}
	}
	fclose(temp);

}
