#include "../../includes/cardinal.h"

static t_node  *create_node(size_t line, size_t column, size_t color, size_t value, int color_id)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->line = line;
    new_node->column = column;
    new_node->color = color;
    new_node->value = value;
    new_node->color_id = color_id;
    new_node->next = NULL;
    return new_node;
}

void    add_node_back(t_node **head, size_t line, size_t column, size_t color, size_t value, int color_id)
{
    t_node *new_node = create_node(line, column, color, value, color_id);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    t_node *current_node = *head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}