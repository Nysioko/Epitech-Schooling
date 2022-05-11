/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** nothing for now
*/

#include <stdarg.h>
#include <stdbool.h>

#define CDEF  "\x1B[0m"
#define CBLD  "\x1B[1m"
#define CFNT  "\x1B[2m"
#define CITA  "\x1B[3m"
#define CUND  "\x1B[4m"
#define CINV  "\x1B[7m"
#define CTGH  "\x1B[9m"
#define CBLK  "\x1B[30m"
#define CRED  "\x1B[31m"
#define CGRN  "\x1B[32m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[37m"

int my_getnbr(char const *str, int n);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_str_in_str(char *str, char const *to_find);
int my_compute_power_rec(int nb, int p);
int my_isneg(int n);
void my_putstr(char const *str);
char *my_strcat(char *str1, char const *str2);
char *my_strncat(char *dest, char const *src, int n);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
char *my_revstr(char *str);
void my_swap(int *a, int *b);
int my_find_prime_sup(int nb);
void my_putchar(char c);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src);
void my_otherswap(char *a, char *b);
char *my_strdup(char const *src);
char *othan_nb(char *str1);
void my_strswap(char **s1, char **s2);
void my_charswap(char *a, char *b);
int do_op(int i, char c, int x);
int do_op1(int i, char c, int x);
int do_op2(int i, char c, int x, int nb);
int do_op3(int i, char c, int x, int nb);
char *my_strgetnbr(char const *str, int n);
char *ifnumber2(char const *str, int n, int minus);
int ifneg2(char const *str, int n);
char *int_to_str(int x, char *s1);
int oifneg2(char const *str, int n);
char *oifnumber2(char const *str, int n, int minus);
char *my_ostrgetnbr(char *str, int n);
char *int_to_str(int x, char *str);
char *uint_to_str(unsigned int x, char *str);
int my_printf(char *format, ...);
int compare(char *s1, char *s2);
char *freeing(char *s1, char *s2);
char *freeing_mult(char *s1, char *s2);
char *freeing_div(char *s1, char *s2, char *added);
int p_str(va_list *ap, int *c);
int p_nb(va_list *ap, int *c);
int p_c(va_list *ap, int *c);
int p_dec(va_list *ap, int *c);
int check_per(char *str, int *i, va_list *ap, int *c);
int p_n(va_list *ap, int *c);
void my_putcharss(char **tab);
void tempo(long long seconds);
int free_cmp(char *s1, char *s2, int i);
char *insert_str(char *str, char *c, int n);
bool my_alpcmp(char *s1, char *s2);
char **split(char *str, char *to, int nb);
char *extract_str(char *str, int side1, int side2, char end);
bool isletter(char letter);
char *clean_str(char *str, char to_remove);
void free_charss(char **to_free);
int my_charsslen(char **tab);
bool contains(char *str, char *c);
char *my_strcat_clean(char *str1, char const *str2);
int my_eprintf(char *format, ...);
bool is_alphanum(char c);
char *remove_char(char *str, int pos);
void remove_char_wmalloc(char *str, int pos);
char **my_charssdup(char **tab);