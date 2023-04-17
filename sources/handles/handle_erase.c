#include "../../includes/cardinal.h"

void    handle_erase(t_cardinal *cardinal)
{
    t_node  *temp;
    char    *color;

    color = (char *)cardinal->selector->color;
    temp = cardinal->list_head;
    while (temp)
    {
        if (strcmp((char *)temp->color, color) == 0 && temp->value != X_START)
            temp->color = (size_t)WHT;
        temp = temp->next;
    }
    handle_chain(cardinal, 1);
}