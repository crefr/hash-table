#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

int main()
{
    table_t table = tableCtor(128);

    union value_t temp = {};

    temp.int_ = 52;
    tableInsert(&table, "aboba",  INT, temp);

    temp.int_ = 36;
    tableInsert(&table, "bebra",  INT, temp);

    temp.int_ = 14;
    tableInsert(&table, "amogus", INT, temp);

    name_t * searched = tableLookup(&table, "bebra");

    if (searched != NULL){
        printf("found: %s\n", searched->name);
        printf("value: %d\n", searched->value.int_);
    }
    else {
        printf("did not found(\n");
    }

    tableDtor(&table);
    return 0;
}
