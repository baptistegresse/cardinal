#ifndef CARDINAL_H
#define CARDINAL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <ctype.h>


#define RESET "\e[m"
#define BLK "\e[0;90m"
#define RED "\e[0;91m"
#define GRN "\e[0;92m"
#define YEL "\e[0;93m"
#define BLU "\e[0;94m"
#define MAG "\e[0;95m"
#define CYN "\e[0;96m"
#define WHT "\e[0;97m"
#define X_START 65535

typedef struct s_node
{
    size_t  line;
    size_t  column;

    size_t  color;
    size_t  value;

    int     color_id;

    struct s_node   *next;

}   t_node;

typedef struct s_cardinal
{
    t_node      *list_head;

    size_t      number_of_x_start;
    size_t      number_of_x_value;

    bool        level_complete;

    char        previous_direction;

    t_node      *selector;
}   t_cardinal;

char	*itoa(int nb);
size_t  count_words(const char *string);
char    *strjoin(const char *s1, char *s2);
char    **split(const char *string, const char *delim);

void    add_node_back(t_node **head, size_t line, size_t column, size_t color, size_t value, int color_id);

void    handle_erase(t_cardinal *cardinal);
void    handle_cancel(t_cardinal *cardinal);
void    handle_restart(t_cardinal *cardinal);
void    handle_chain(t_cardinal *cardinal, bool new_chain);
void    handle_direction(t_cardinal *cardinal, char controller);

void    selector_init_on_x(t_cardinal *cardinal, size_t num);

void    parse_file_contents_to_linked_list(t_cardinal *cardinal, char *file_contents);
void    parsing_and_control(char *file_contents, size_t file_index);

#endif