#include "../includes/cardinal.h"

static char    *read_file(char *file_name)
{
    FILE    *file;
    int     length;
    char    *file_string;
    size_t  index;
    char    c;

    file = fopen(file_name, "r");
    if (!file)
        return (NULL);
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    file_string = malloc(sizeof(char) * length + 1);
    if (!file_string)
        return (NULL);
    index = 0;
    while ((c = fgetc(file)) != EOF)
        file_string[index++] = c;
    file_string[index] = 0;
    fclose(file);
    return (file_string);
}

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    char        *file_name;
    char        *file_contents;
    size_t      file_index;

    file_index = 0;
    while (true)
    {
        file_name = strjoin("./maps/map", itoa(file_index));
        file_contents = read_file(file_name);
        if (!file_contents)
            break ;
        parsing_and_control(file_contents, file_index);
        file_index++;
    }
    printf(""BLU"you done all %zu levels congrat !\n"RESET"", file_index);
    return (0);
}
