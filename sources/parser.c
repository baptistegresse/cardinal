#include "../includes/cardinal.h"

void    parse_file_contents_to_linked_list(t_cardinal *cardinal, char *file_contents)
{
    size_t  index_x;
    size_t  index_y;
    char    **array_of_line;
    char    **array_of_value;
    char    *color_code;
    static  int color_id = 91;

    array_of_line = split(file_contents, "\n");
    cardinal->number_of_x_value = count_words(array_of_line[0]);
    index_x = 0;
    while (array_of_line[index_x])
    {
        index_y = 0;
        array_of_value = split(array_of_line[index_x], " ");
        while(array_of_value[index_y])
        {
            if (strchr(array_of_value[index_y], 'x'))
            {
                cardinal->number_of_x_start++;
                (color_id > 96) ? color_id = 91 : color_id;
                color_code = strjoin("\e[0;", strjoin(itoa(color_id++), "m"));
                add_node_back(&cardinal->list_head, index_x, index_y, (size_t)color_code, X_START, color_id);
            }
            else if (strchr(array_of_value[index_y], '0'))
            {
                add_node_back(&cardinal->list_head, index_x, index_y, (size_t)BLU, 0, 95);
            }
            else
                add_node_back(&cardinal->list_head, index_x, index_y, (size_t)WHT, atoi(array_of_value[index_y]), color_id);
            index_y++;
        }
        index_x++;
    }
}