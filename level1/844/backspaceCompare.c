#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int update_string(char *s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '#') {
            if (count > 0)
                count--;
        }
        else {
            s[count] = s[i];
            count++; 
        }
    }
    return (count);
}

bool backspaceCompare(char *s, char *t){
    if (!s && !t)
        return (true);
    int s_len = update_string(s);
    int t_len = update_string(t);
   
    if (s_len != t_len)
        return (false);
    for (int i = 0; i < s_len; i++) { 
        if (s[i] != t[i])
            return (false);
    }
    return (true);
}
