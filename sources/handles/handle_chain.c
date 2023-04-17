#include "../../includes/cardinal.h"

void    selector_init_on_x(t_cardinal *cardinal, size_t num)
{
    t_node  *temp;
    size_t  count;

    count = 0;
    temp = cardinal->list_head;
    while (temp)
    {
        if (temp->value == X_START)
        {
            count++;
            if (count == num)
            {
                cardinal->selector = temp;
                break;
            }
        }
        temp = temp->next;
    }
}

void    handle_chain(t_cardinal *cardinal, bool new_chain)
{
    static size_t  index = 2;
    (void)new_chain;
    selector_init_on_x(cardinal, index);
    if (index == cardinal->number_of_x_start)
        index = 0;
    index++;
}
