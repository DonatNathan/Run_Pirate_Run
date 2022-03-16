/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** It's a function that compare two string
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int cmpt;

    for (cmpt = 0; cmpt < my_strlen(s1); cmpt += 1) {
        if (s1[cmpt] != s2[cmpt])
            return (1);
    }
    return (0);
}
