#include "../includes/cardinal.h"

static void    display_game(t_cardinal *carnival)
{
    size_t  index;
    t_node *temp;
    
    index = 0;
    temp =  carnival->list_head;
    while (temp) 
    {
        printf("%s", (char *)temp->color);
        if (!temp->value)
            printf("  "RESET"");
        else if (temp->value == X_START)
            printf("x "RESET"");
        else
            printf("%zu "RESET"", temp->value);
        index++;
        if(index % carnival->number_of_x_value == 0)
            printf("\n");
        temp = temp->next;
    }
}

static bool check_level_complete(t_cardinal *cardinal)
{
    t_node  *temp; 
    bool    all_white;

    temp = cardinal->list_head;
    all_white = true;
    while (temp)
    {
        if (strcmp((char *)temp->color, (char *)WHT) == 0)
        {
            all_white = false;
            break;
        }
        temp = temp->next;
    }
    return (all_white);
}

// static char *get_string_color(int color)
// {
//     char    *string_color;

//     switch (color)
//     {
//     case 91:
//         string_color = strdup(""RED"red"RESET"");
//         break;
//     case 92:
//         string_color = strdup(""GRN"green"RESET"");
//         break ;
//     case 93:
//         string_color = strdup(""YEL"yellow"RESET"");
//         break ;
//     case 94:
//         string_color = strdup(""BLU"blue"RESET"");
//         break ;
//     case 95:
//         string_color = strdup(""MAG"magenta"RESET"");
//         break ;
//     case 96:
//         string_color = strdup(""CYN"cyan"RESET"");
//         break ;
//     }
//     return (string_color);
// }

void    game_controller(t_cardinal *cardinal)
{
    char controller;

    selector_init_on_x(cardinal, 1);
    while (!cardinal->level_complete)
    {
        display_game(cardinal);
       // printf("\n--- line: %zu, column: %zu, chain: %s ---\n", cardinal->selector->line, cardinal->selector->column, get_string_color(cardinal->selector->color_id));
        printf("Select a direction (N, S, E, W).\nCancel the previous move (B).\nErase the chain (R).\nRestart the level (X).\nSelect another chain (C).\n>");
        scanf(" %c", &controller);
        printf("\n");
        controller = tolower(controller);
        switch (controller)
        {
            case 'n':
            case 's':
            case 'e':
            case 'w':
               handle_direction(cardinal, controller);
                break;
            case 'b':
                handle_cancel(cardinal);
                break;
            case 'r':
                handle_erase(cardinal);
                break;
            case 'x':
                handle_restart(cardinal);
                break;
            case 'c':
                handle_chain(cardinal, true);
                break;
            default:
                printf(""RED"Invalid input. Please try again.\n"RED"");
                break;
        }
        cardinal->level_complete = check_level_complete(cardinal);
    }
}

void    parsing_and_control(char *file_contents, size_t file_index)
{
    t_cardinal  *cardinal;

    cardinal = calloc(sizeof(t_cardinal), 1);
    parse_file_contents_to_linked_list(cardinal, file_contents);
    game_controller(cardinal);
    printf("level "BLU"%zu"RESET" complete !\n\n", file_index);
}
