#include "fillit.h"

int     nb_piece(char **piece)
{
    int nb_blocks;
    int nb_empty;
    int i;

    nb_blocks = 0;
    nb_empty = 0;
    i = -1;
    while (piece[++i])
    {
        if (ft_strlen(piece[i]) != END)
            return (0);
        // nb_blocks += ft_strccnt(piece[i], BLOCK);
        // nb_empty += ft_strccnt(piece[i], EMPTY);
    }
    if (nb_blocks != END && nb_empty != END * END - BLOCK)
        return (0);
    return (1);
}

// int     piece_integrity(char **piece)
// {

// }

int     check_errors(char **tab)
{
    int i = -1;
    // if (!lst)
    //     return (0);
    while (tab[++i])
    {
        if (!nb_piece(tab))
            return (0);
        //lst = lst->next;
    }
    return (1);
}