#ifndef HASHTABLE_INCLUDED
#define HASHTABLE_INCLUDED

typedef enum {
    INT = 0,
    DBL,
    CHR,
    PTR
} name_type_t;

union value_t {
    int int_;
    double double_;
    char char_;
    void * ptr_;
};

typedef struct name {
    char * name;
    struct name * next;

    name_type_t type;
    union value_t value;
} name_t;

typedef struct {
    name_t ** names;
    size_t table_size;
} table_t;


table_t tableCtor(size_t table_size);

void tableDtor(table_t * table);

void tableInsert(table_t * table, const char * name, name_type_t type, union value_t val);

#endif
