//Samuel Esparza
//Due October 7, 2026

//FILE FUCNTION - Defines the Item structure used to store grocery item information.




#ifndef ITEM_H
#define ITEM_H



struct _Item
{
	double price;

	char *sku;

	char *name;

	char *category;

};


typedef struct _Item Item;



#endif
