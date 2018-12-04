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
        nb_blocks += ft_strccnt(piece[i], BLOCK);
        nb_empty += ft_strccnt(piece[i], EMPTY);
    }
    if (nb_blocks != END && nb_empty != END * END - BLOCK)
        return (0);
    return (1);
}

int     piece_integrity(t_tetri *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        t_coord pt = lst->point;
        while (i < 3)
        {
            if (pt.x[i + 1] == pt.x[i] + 1 || pt.y[i + 1] == pt.y[i] + 1)
                i++;
            else
                return (0);
        }
        lst = lst->next;
    }
    return (1);
}

int     check_errors(t_tetri *lst)
{
    if (!lst || !piece_integrity(lst))
        return (0);
    while (lst)
    {
        if (!nb_piece(lst->tetri))
            return (0);
        lst = lst->next;
    }
    return (1);
}
