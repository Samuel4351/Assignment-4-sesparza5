//Samuel Esparza
//Due October 7, 2026

//FILE FUCNTION - Contains the declarations for the grocery item functions.




#ifndef ITEM_FUNCTIONS_H
#define ITEM_FUNCTIONS_H

#include "item.h"



void add_item(Item *item_list, double price, char *sku, 
					char *categrory, char *name, int index);


void free_items(Item *item_list, int size);


double average_price(Item *item_list, int size);


void print_items(Item *item_list, int size);




#endif
