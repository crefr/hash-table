#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hashtable.h"
#include "hash.h"

static name_t * newName(const char * name, size_t name_len, name_type_t type, union value_t val);
static void delName(name_t * name);

table_t tableCtor(size_t table_size)
{
    table_t table = {};

    table.table_size = table_size;
    table.names = (name_t **)calloc(table_size, sizeof(*table.names));

    return table;
}

void tableDtor(table_t * table)
{
    assert(table);

    for (size_t index = 0; index < table->table_size; index++){
        if (table->names[index] != NULL){
            name_t * cur_name;
            while (cur_name->next != NULL){
                name_t * next_name = cur_name->next;
                cur_name->next = NULL;
                delName(cur_name);

                cur_name = next_name;
            }

            delName(table->names[index]);
            table->names[index] = NULL;
        }
    }

    free(table->names);
    table->names = NULL;
}

void tableInsert(table_t * table, const char * name, name_type_t type, union value_t val)
{
    assert(table);
    assert(name);

    size_t name_len = strlen(name) + 1;

    size_t index = MurMur32Hash(name, sizeof(*name) * name_len, 0) % table->table_size;

    if (table->names[index] == NULL){
        table->names[index] = newName(name, name_len, type, val);
        return;
    }

    name_t * cur_name = table->names[index];
    while (cur_name->next != NULL)
        cur_name = cur_name->next;

    cur_name->next = newName(name, name_len, type, val);
}

static name_t * newName(const char * name, size_t name_len, name_type_t type, union value_t val)
{
    assert(name);

    name_t * new_name = (name_t *)calloc(1, sizeof(*new_name));

    new_name->name    = (char *)  calloc(name_len, sizeof(*name));
    strcpy(new_name->name, name);

    new_name->next = NULL;

    new_name->type  = type;
    new_name->value = val;

    return new_name;
}

static void delName(name_t * name)
{
    free(name->name);
    free(name);
}
