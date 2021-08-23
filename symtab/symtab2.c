#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#include "../node.h"
#include "../parser.h"
#include "symtab.h"

int rem_from_symtab(struct symtab_entry_s *entry, struct symtab_s *symtab)
{
    int res = 0;

    if(entry->val)
    {
        free(entry->val);
    }
    if(entry->func_body)
    {
        free_node_tree(entry->func_body);
    }
    free(entry->name);

    if(symtab->first == entry)
    {
        symtab->first = symtab->first->next;

        if(symtab->last == entry)
        {
            symtab->last = NULL;
        }
        res = 1;
    }
    else
    {
        struct symtab_entry_s *e = symtab->first;
        struct symtab_entry_s *p = NULL;
        while(e && e != entry)
        {
            p = e;
            e = e->next;
        }
        if(e == entry)
        {
            p->next = entry->next;
            res = 1;
        }
    }
    free(entry);
    return (res);
}

struct symtab_entry_s *do_lookup(char *str, struct symtab_s *symtable)
{
    if(!str || !symtable)
    {
        return (NULL);
    }

    struct symtab_entry_s *entry = symtable->first;

    while(entry)
    {
        if(strcmp(entry->name, str) == 0)
        {
            return entry;
        }
        entry = entry->next;
    }
    return (NULL);
}

struct symtab_entry_s *get_symtab_entry(char *str)
{
    int i = symtab_stack.symtab_count - 1;

    do
    {
        struct symtab_s *symtab = symtab_stack.symtab_list[i];
        struct symtab_entry_s *entry = do_lookup(str, symtab);

        if(entry)
        {
            return (entry);
        }
    } while(--i >= 0);

    return (NULL);
}

void symtab_entry_setval(struct symtab_entry_s *entry, char *val)
{
    if(entry->val)
    {
        free(entry->val);
    }
    if(!val)
    {
        entry->val = NULL;
    }
    else
    {
        char *val2 = malloc(strlen(val)+1);

        if(val2)
        {
            strcpy(val2, val);
        }
        else
        {
            fprintf(stderr, "error: no memory for symbol table entry's value\n");
        }

        entry->val = val2;
    }
}

void symtab_stack_add(struct symtab_s *symtab)
{
    symtab_stack.symtab_list[symtab_stack.symtab_count++] = symtab;
    symtab_stack.local_symtab = symtab;
}