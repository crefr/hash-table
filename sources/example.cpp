#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

int main()
{
    table_t table = tableCtor(8);

    int a = 52;
    tableInsert(&table, "aboba",  &a, sizeof(a));

    int b = 36;
    tableInsert(&table, "bebra",  &b, sizeof(b));

    int c = 14;
    tableInsert(&table, "amogus", &c, sizeof(c));

    name_t * searched = tableLookup(&table, "aboba");

    if (searched != NULL){
        printf("found: %s\n", searched->name);
        printf("value: %d\n", *((int *)searched->data));
    }
    else {
        printf("did not found(\n");
    }

    tableDtor(&table);

    return 0;
}
