#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "customer.h"

int size_of_file_cust()
{
	FILE* fptr;

	fptr = fopen("customer.txt", "r");

	int line = 0;
	char str[100];
	while (fgets(str, 100, fptr))
	{
		line++;
	}
	fclose(fptr);
	return line;

}
int checkcst(int iddddd)
{

	int size = size_of_file_cust();

	FILE* ptr;
	ptr = fopen("customer.txt", "r");

	if (ptr == NULL)
	{
		printf("FILE \"customer.txt\" NOT FOUND!");
		return -1;
	}

	
	struct customer* m = (struct customer*)malloc(size * (sizeof(struct customer)));

	int i = 0;
	while (fscanf(ptr, "%d %s %s", &m[i].id, m[i].name, m[i].password) != EOF)
	{
		i++;
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

int checkcstLogin(int iddddd, char* password) {

	int size = size_of_file_cust();

	FILE* ptr;
	ptr = fopen("customer.txt", "r");

	if (ptr == NULL)
	{
		printf("FILE \"customer.txt\" NOT FOUND!");
		return -1;
	}
	
	struct customer* m = (struct customer*)malloc(size * (sizeof(struct customer)));
	
	int i = 0;

	while (fscanf(ptr, "%d %s %s", &m[i].id, m[i].name, m[i].password) != EOF)
	{
		i++;
		printf("i : %d\n", i);
	}
	
        fclose(ptr);
	
        for (int j = 0; j < i; j++)
	{
		if (m[j].id == iddddd && strcmp(m[j].password, password)==0)
		{
			return 1;
		}

	}
	return 0;

}

void register_cust(int id, char* name, char* password)
{

	if (checkcst(id) == 0)
	{
		FILE* ptr = fopen("customer.txt", "a");

		if (ptr == NULL)
		{
			printf("FILE \"customer.txt\" NOT FOUND!");
			return;
		}
		fprintf(ptr, "\n%d %s %s", id, name, password);

		
		printf("YOUR ACCOUNT HAS SUCCESSFULLY REGISTRED");
		printf("\n");
		fclose(ptr);
	}
	else
	{
		printf("CUSTOMER ID ALREADY EXISTS!");
		printf("\n");
	}
}

int showCustMenu() {
	int no;
	do {
		printf("ENTER 1 TO MODIFY YOUR DETAILS ");
		printf("\n");
		printf("ENTER 2 TO PLACE ORDER ");
		printf("\n");
		printf("ENTER 3 TO CANCEL ORDER ");
		printf("\n");
		printf("ENTER 4 FOR MAIN MENU ");
		printf("\n");
		scanf("%d", &no);

		if (no < 1 || no > 4)
			printf("WRONG CHOICE. PLEASE STAY IN RANGE [1..4]\n");
		
	} while (no < 1 || no > 4);
	return no;
}

void update_details(int id, char *name,char *password)
{
	int size = size_of_file_cust();

	FILE *fptr;
	fptr = fopen("customer.txt", "r");

	if (fptr == NULL)
	{
		printf("FILE \"customer.txt\" NOT FOUND!");
		return;
	}

	
	struct customer* m=(struct customer*)malloc(size*(sizeof(struct customer)));

	int i=0;
	while(fscanf(fptr, "%d %s %s", &m[i].id, m[i].name, m[i].password) != EOF)
	{
		i++;
	}
	fclose(fptr);

	int f = 0;
	for (i = 0; i < size; i++)
	{
		if (m[i].id == id)
		{
			strcpy(m[i].name, name);
			strcpy(m[i].password, password);
			f = 1;
			break;
		}
	}

	
	FILE *temp = fopen("customer.txt", "w");

	if (temp == NULL)
	{
		printf("FILE \"customer.txt\" NOT FOUND!");
		return;
	}

	if (f == 0)
	{
		printf("\nCUSTOMER ID DOSENT EXIST\n");
	}
	else
	{   
		printf("\nNew details :\n");

		printf("\nName: %s, Password: %s\n", m[i].name, m[i].password);
		
		for (i = 0; i < size; i++)
		{
			fprintf(temp, "%d %s %s\n", m[i].id, m[i].name, m[i].password);
		}
		
	}
	fclose(temp);

}