#include "../../includes/cardinal.h"

void    handle_restart(t_cardinal *cardinal)
{
    t_node  *temp;

    temp = cardinal->list_head;
    while (temp)
    {
        if (!temp->value)
            ;
        else if (strcmp((char *)temp->color, (char *)WHT) != 0 && temp->value != X_START)
            temp->color = (size_t)WHT;
        temp = temp->next;
    }
    handle_chain(cardinal, 1);
}
