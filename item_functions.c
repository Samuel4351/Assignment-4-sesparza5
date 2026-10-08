//Samuel Esparza
//Due October 7, 2026

//FILE FUCNTION -Contains the functions used to add, print, 
//				calculate, and free grocery items.




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "item_functions.h"


//ADD ITEM FUNCTION
void add_item(Item *item_list, double price, char *sku, 
					char *category, char *name, int index)
{
	//Store the price first
	item_list[index].price = price;

	//Allocate memory for SKU
	item_list[index].sku = malloc((strlen(sku) + 1) * sizeof(char));

	//Copy SKU into allocated memory
	strcpy(item_list[index].sku, sku);

	//Do the same for category and name

	item_list[index].category = malloc((strlen(category) + 1) * sizeof(char));

	strcpy(item_list[index].category, category);


	item_list[index].name = malloc((strlen(name)+1) *sizeof(char));

	strcpy(item_list[index].name, name);


}



//FREE ITEM FUNCTION
void free_items(Item *item_list, int size)
{
	int row;

	for (row = 0; row < size; row++)
	{
		free(item_list[row].sku);

		free(item_list[row].category);

		free(item_list[row].name);
	}

	free(item_list);
}



//AVERAGE PRICE FUNCTION
double average_price(Item *item_list, int size)
{
	double sum = 0;
	double average;
	int row;

	for(row = 0; row < size; row++)
	{
		sum = sum + item_list[row].price;

	}

	average = sum / size;


	return average;
}



//PRINTING ITEMS AND DISPLAY FUNCTION
void print_items(Item *item_list, int size)
{
	int row;

	for(row = 0; row < size; row++)
	{
		printf("###############\n");

		printf("ITEM Name = %s\n", item_list[row].name);

		printf("ITEM SKU = %s\n", item_list[row].sku);

		printf("ITEM Category = %s\n", item_list[row].category);

		printf("ITEM Price = %f\n", item_list[row].price);
	}

	printf("###############\n");
}









