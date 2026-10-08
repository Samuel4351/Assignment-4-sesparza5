//Samuel Esparza
//Due October 7, 2026

//Description - This assignment uses structures, pointers, dynamic memory, 
//and libraries in C to create a grocery item database. The program stores 
//items, calculates the average price, prints the items, and allows the 
//user to search for an item by its SKU.

//FILE FUCNTION - Creates the grocery item list and allows the user to print or search for items

//HOW TO USE PROGRAM

//NORMAL/EDITED ONLY MAIN.C

// gcc -o main main.c -L. -litem
//To Print all Items
// ./main
//To Search for a specific item
// ./main 14512

//EDITED LIBRARY FUNCTIONS TOO

// gcc -c item_functions.c
// ar rcs libitem.a item_functions.o
// gcc -o main main.c -L. -litem
// //To Print all Items
// ./main
//To Search for a specific item
// ./main 14512


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "item_functions.h"


int main(int argc, char *argv[])
{
    int size = 5;
    int ct = 0;
    double avg;
    char *sku;

	Item *item_list;

// Allocate enough memory for 5 Items
    item_list = malloc(size * sizeof(Item));

    // Check if memory allocation worked
    if (item_list == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }


    // Add 5 grocery items
    add_item(item_list, 5.00, "19282",
             "breakfast", "reese's cereal", 0);

    add_item(item_list, 3.95, "79862",
             "dairy", "milk", 1);

    add_item(item_list, 2.50, "14512",
             "bakery", "bread", 2);

    add_item(item_list, 6.25, "47321",
             "dairy", "eggs", 3);

    add_item(item_list, 8.75, "65891",
             "meat", "chicken", 4);

//IF NO SKU WAS ENTERED, PRINT ALL ITEMS
   if (argc == 1)
	{
    // No SKU was entered so print everything
    print_items(item_list, size);

    avg = average_price(item_list, size);
    printf("average price of items = %f\n", avg);
	}

//IF AN AKU WAS ENTERED, SEARCH FOR THAT ITEM
	else if (argc == 2)
	{
    // SKU was entered, so search for one item entered by user
    sku = argv[1];

    //search through item list
    while (ct < size && strcmp(item_list[ct].sku, sku) != 0)
    {
        ct++;
    }

    if (ct < size)
    	{
        printf("###############\n");

        printf("item name = %s\n", item_list[ct].name);

        printf("item sku = %s\n", item_list[ct].sku);

        printf("item category = %s\n", item_list[ct].category);

        printf("item price = %f\n", item_list[ct].price);

        printf("###############\n");
    	}
    	//if ct reached size, the SKU wa not found
    	else
    	{
    	    printf("Item not found.\n");
    	}
	}
	//More than one argument was entered
	else
	{
    printf("Usage: ./main [SKU]\n");
	}



    // Free all dynamically allocated memory to be safe
    free_items(item_list, size);



    return 0;
}
