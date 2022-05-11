/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** globbing
*/

#include "glob.h"
#include "sh.h"

char **glob_func(char *flag, char *name)
{
    int retval;
    char **array = NULL;
    glob_t paths;

    paths.gl_pathc = 0;
    paths.gl_pathv = NULL;
    paths.gl_offs = 0;
    retval = glob(flag, 0, NULL, &paths);
    if (retval == 0) {
        array = my_charssdup(paths.gl_pathv);
        if (!array)
            exit(84);
        globfree(&paths);
    } else if (retval == 3)
        my_eprintf("%s: No match.\n", name);
    free(name);
    return array;
}

void cat_string(char **globs, char **new, int start, char *str)
{
    char *tmp;
    char *tmp2;
    int pos = start;

    for (int i = 0; globs[i] != NULL; i++, free(tmp), free(tmp2)) {
        tmp = insert_str(str, globs[i], pos);
        if (!tmp)
            exit(84);
        pos += my_strlen(globs[i]);
        tmp2 = insert_str(tmp, " ", pos);
        if (!tmp2)
            exit(84);
        pos++;
        free(str);
        str = my_strdup(tmp2);
        if (!str)
            exit(84);
    }
    (*new) = my_strdup(str);
}

void star_glob(char *str, int i, char **new)
{
    int start = i;
    int end = i;
    char *tmp;
    char **globs;

    for (; start > 0 && str[start] != ' '; start--);
    for (; str[end] != '\0' && str[end] != ' '; end++);
    start++;
    tmp = extract_str(str, start, end, '\0');
    if (!tmp)
        exit(84);
    globs = glob_func(tmp, extract_str(str, 0, -1, ' '));
    while (str[start] != ' ' && str[start] != '\0')
        remove_char_wmalloc(str, start);
    free(tmp);
    cat_string(globs, new, start, str);
    free_charss(globs);
}

char *globbing(char *str)
{
    char *new = NULL;
    char *new2 = NULL;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '*') {
            star_glob(str, i, &new);
            new2 = filter_str(new);
            !new2 ? exit(84) : new2;
            str = new2;
            free(new);
            new = NULL;
        }
    }
    new2 = filter_str(new == NULL ? str : new);
    if (!new2)
        exit(84);
    free(new == NULL ? str : new);
    return new2;
}