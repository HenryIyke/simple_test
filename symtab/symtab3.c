#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#include "../node.h"
#include "../parser.h"
#include "symtab.h"

struct symtab_entry_s *add_to_symtab(char *symbol)
{
    if(!symbol || symbol[0] == '\0')
    {
        return (NULL);
    }

    struct symtab_s *st = symtab_stack.local_symtab;
    struct symtab_entry_s *entry = NULL;

    if((entry = do_lookup(symbol, st)))
    {
        return (entry);
    }

    entry = malloc(sizeof(struct symtab_entry_s));

    if(!entry)
    {
        fprintf(stderr, "fatal error: no memory for new symbol table entry\n");
        exit(EXIT_FAILURE);
    }
    memset(entry, 0, sizeof(struct symtab_entry_s));
    entry->name = malloc(strlen(symbol)+1);
    
    if(!entry->name)
    {
        fprintf(stderr, "fatal error: no memory for new symbol table entry\n");
        exit(EXIT_FAILURE);
    }
    strcpy(entry->name, symbol);
    if(!st->first)
    {
        st->first      = entry;
        st->last       = entry;
    }
    else
    {
        st->last->next = entry;
        st->last       = entry;
    }
    return (entry);
}

void dump_local_symtab(void)
{
    struct symtab_s *symtab = symtab_stack.local_symtab;
    int i = 0;
    int indent = symtab->level * 4;

    fprintf(stderr, "%*sSymbol table [Level %d]:\r\n", indent, " ", symtab->level);
    fprintf(stderr, "%*s===========================\r\n", indent, " ");
    fprintf(stderr, "%*s  No               Symbol                    Val\r\n", indent, " ");
    fprintf(stderr, "%*s------ -------------------------------- ------------\r\n", indent, " ");
    struct symtab_entry_s *entry = symtab->first;

    while(entry)
    {
        fprintf(stderr, "%*s[%04d] %-32s '%s'\r\n", indent, " ",
                i++, entry->name, entry->val);
        entry = entry->next;
    }
    fprintf(stderr, "%*s------ -------------------------------- ------------\r\n", indent, " ");
}


struct symtab_s *get_local_symtab(void)
{
    return (symtab_stack.local_symtab);
}

struct symtab_s *get_global_symtab(void)
{
    return (symtab_stack.global_symtab);
}

struct symtab_stack_s *get_symtab_stack(void)
{
    return (&symtab_stack);
}