#include "../../includes/cardinal.h"

static  t_node  *get_selector(t_cardinal *cardinal, int x, int y)
{
    t_node  *temp;

    temp = cardinal->list_head;
    while (temp)
    {
        if ((int)temp->line == x && (int)temp->column == y)
            return (temp);
        temp = temp->next;
    }
    return (cardinal->selector);
}

void    handle_cancel(t_cardinal *cardinal)
{
    if (cardinal->selector->value == X_START)
        return ;
    cardinal->selector->color = (size_t)WHT;
    switch(cardinal->previous_direction)
    {
        case 'n':
            cardinal->selector = get_selector(cardinal, cardinal->selector->line + 1, cardinal->selector->column);
            break ;
        case 's':
            cardinal->selector = get_selector(cardinal, cardinal->selector->line - 1, cardinal->selector->column);
            break ;
        case 'e':
            cardinal->selector = get_selector(cardinal, cardinal->selector->line, cardinal->selector->column - 1);
            break ;
        case 'w' :
            cardinal->selector = get_selector(cardinal, cardinal->selector->line, cardinal->selector->column + 1);
            break ;
    }
    return ;
}
