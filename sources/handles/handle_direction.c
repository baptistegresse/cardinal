#include "../../includes/cardinal.h"

static bool    check_position_value_color(t_cardinal *cardinal, int x, int y)
{
    t_node  *temp;

    temp = cardinal->list_head;
    while (temp)
    {
        if ((int)temp->line == x && (int)temp->column == y)
        {
            if (strcmp((char *)temp->color, (char *)WHT) != 0)
                return (false);
            if (!temp->value)
                return false;
            if (cardinal->selector->value == X_START)
                return (true);
            if (temp->value < cardinal->selector->value)
                return (false);
            return (true);
        }
        temp = temp->next;
    }
    return (false);
}

static bool    check_the_next_step(t_cardinal *cardinal, char controller)
{
    switch(controller)
    {
        case 'n':
            return (check_position_value_color(cardinal, cardinal->selector->line - 1, cardinal->selector->column)) ? true : false;
            break ;
        case 's':
            return (check_position_value_color(cardinal, cardinal->selector->line + 1, cardinal->selector->column)) ? true : false;
            break ;
        case 'e':
            return (check_position_value_color(cardinal, cardinal->selector->line, cardinal->selector->column + 1)) ? true : false;
            break ;
        case 'w' :
            return (check_position_value_color(cardinal, cardinal->selector->line, cardinal->selector->column - 1)) ? true : false;
            break ;
    }
    return (false);
}

static void    refresh_color_by_x(t_cardinal *cardinal, int x, int y)
{
    t_node  *temp;

    temp = cardinal->list_head;
    while (temp)
    {
        if ((int)temp->line == x && (int)temp->column == y)
        {
            temp->color = cardinal->selector->color;
            cardinal->selector = temp;
        }
        temp = temp->next;
    }
}

static void    change_color(t_cardinal *cardinal, char controller)
{
    switch(controller)
    {
        case 'n':
            return (refresh_color_by_x(cardinal, cardinal->selector->line - 1, cardinal->selector->column));
            break ;
        case 's':
            return (refresh_color_by_x(cardinal, cardinal->selector->line + 1, cardinal->selector->column));
            break ;
        case 'e':
            return (refresh_color_by_x(cardinal, cardinal->selector->line, cardinal->selector->column + 1));
            break ;
        case 'w' :
            return (refresh_color_by_x(cardinal, cardinal->selector->line, cardinal->selector->column - 1));
            break ;
    }
    return ;
}

void    handle_direction(t_cardinal *cardinal, char controller)
{
    bool    next_step;

    next_step = false;
    next_step = check_the_next_step(cardinal, controller);
    if (!next_step)
        return (printf(""RED"error you can't go there\n"RESET""), (void)0);
    cardinal->previous_direction = controller;
    change_color(cardinal, controller);
}
