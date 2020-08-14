/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres- <rtorres-@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:32:09 by rtorres-          #+#    #+#             */
/*   Updated: 2020/08/13 22:04:53 by rtorres-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Header files dependencies.
*/

# include <errno.h>
# include <wchar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>

/*
** Attributes for printed text.
*/

# define RESET				(0)
# define BOLD				(1)
# define DIM				(2)
# define ITALICS			(3)
# define UNDERLINE			(4)
# define REVERSE			(7)
# define HIDDEN				(8)
# define STROKE				(9)

/*
** Colors for printed text.
*/

# define BLACK				(0)
# define RED				(1)
# define GREEN				(2)
# define YELLOW				(3)
# define BLUE				(4)
# define MAGENTA			(5)
# define CYAN				(6)
# define WHITE				(7)

/*
** Macros for the limits of the variables.
*/

# define CHAR_BIT			(8)
# define MB_LEN_MAX			(1)
# define SCHAR_MIN			(-128)
# define SCHAR_MAX			(127)
# define UCHAR_MAX			(255)
# define CHAR_MIN			(-128)
# define CHAR_MAX			(127)
# define SHRT_MIN			(-32768)
# define SHRT_MAX			(32767)
# define USHRT_MAX			(65535)
# define INT_MIN			(-2147483648)
# define INT_MAX			(2147483647)
# define LONG_MIN			(-9223372036854775808)
# define LONG_MAX			(9223372036854775807)
# define ULONG_MAX			(18446744073709551615)

/*
** Macro math constants.
*/

# define M_E				(2.71828182845904523540)
# define M_LOG2E			(1.44269504088896340740)
# define M_LOG10E			(0.43429448190325182765)
# define M_LN2				(0.69314718055994530942)
# define M_LN10				(2.30258509299404568402)
# define M_PI				(3.14159265358979323846)
# define M_PI_2				(1.57079632679489661923)
# define M_PI_4				(0.78539816339744830962)
# define M_1_PI				(0.31830988618379067154)
# define M_2_PI				(0.63661977236758134308)
# define M_2_SQRTPI			(1.12837916709551257390)
# define M_SQRT2			(1.41421356237309504880)
# define M_SQRT1_2			(0.70710678118654752440)

/*
** Macro functions.
*/

# define FT_LO(num)			((num) & 0x00FF)
# define FT_HI(num)			(((num) & 0xFF00) >> 8)
# define FT_MIN(x, y)		(x) < (y) ? (x) : (y)
# define FT_MAX(x, y)		(x) > (y) ? (x) : (y)
# define FT_ABS(x)			(((x) < 0) ? -(x) : (x))
# define FT_SIZE(a)			(sizeof(a) / sizeof(a[0]))
# define FT_SWAP(a, b)		({a ^= b; b ^= a; a ^= b;})
# define FT_SQUARE(x)		(x * x)
# define FT_CUBE(x)			(x * x * x)
# define FT_BIT(x)			(1 << (x))
# define FT_STRCMP(A, o, B)	(ft_strcmp((A), (B)) o 0)
# define FT_MEMCMP(A, o, B)	(ft_memcmp((A), (B)) o 0)

/*
** Define the bool typedef to use for older compilers.
*/

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

/*
** Define the structure called t_list, for ft_lst* function.
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Define the structure called t_stack, for ft_stck* function.
*/

typedef struct		s_stack
{
	double			value;
	struct s_stack	*next;
}					t_stack;

/*
** Functions by type stdlib.h
*/

int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_calloc(size_t count, size_t size);
void				ft_qsort(void *base, size_t nmemb, \
								size_t size, int (*fcmp)(void *, void *));

/*
** Functions by type string.h
*/

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t ln);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strrev(char *str);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strtok(char *str, const char delim);
char				**ft_strsplit(const char *s, char c);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/*
** Functions by type strings.h
*/

void				ft_bzero(void *s, size_t n);

/*
** Functions by type ctype.h
*/

int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isdigit(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isxdigit(int c);
int					ft_iswspace(int c);
int					ft_ismathop(int c);
int					ft_is_little_endian(void);
int					ft_str_is_lowercase(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_palindrome(char *str);

/*
** Functions by type stdio.h
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putnchar(char c, int n);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putunbr(uintmax_t n);
void				ft_putnstr(char const *s, size_t len);
void				ft_putnstr_fd(char const *str, size_t len, int fd);

/*
** Functions by type math.h
*/

int					ft_min(int x, int y);
int					ft_min(int x, int y);
int					ft_isprime(long unsigned int nbr);
double				ft_sqrt(double x);
double				ft_trunc(double x);
double				ft_ceil(double x);
double				ft_round(double x);
double				ft_floor(double x);
double				ft_pow(double x, int y);
double				ft_hypot(double x, double y);
long double			ft_sqrtl(long double x);
long double			ft_truncl(long double x);
long double			ft_ceill(long double x);
long double			ft_roundl(long double x);
long double			ft_floorl(long double x);
long double			ft_powl(long double x, long int y);
long double			ft_hypotl(long double x, long double y);
unsigned int		ft_collatz_conjecture(unsigned int base);
long unsigned int	ft_nextprime(long unsigned int nbr);
size_t				ft_nbrlen(int nbr, int base);
size_t				ft_factorial(unsigned int nb);
size_t				ft_fibonacci(unsigned int index);
size_t				ft_find_next_prime(unsigned int nb);

/*
** Functions by type wchar.h
*/

int					ft_wclen(wchar_t wchar);
int					ft_putwchar(wchar_t wc);
int					ft_putwchar_fd(wchar_t wc, int fd);
int					ft_putwstr(wchar_t *ws);
int					ft_putwstr_fd(wchar_t *ws, int fd);
size_t				ft_wcslen(wchar_t *ws);
wchar_t				*ft_wcsdup(wchar_t *src);
wchar_t				*ft_wcscpy(wchar_t *dst, const wchar_t *src);
wchar_t				*ft_wcsnew(size_t size);
wchar_t				*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);

/*
** Functions by type list.h
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Functions by type array.h
*/

int					ft_arr_max(int *arr, int length);
int					ft_arr_elem_get(int *arr, size_t size);
int					ft_arr_elem_rptd(int *arr, size_t size);
int					*ft_arr_new(size_t size);
int					*ft_arr_cpy(const int *arr, size_t size);
int					*ft_arr_rotl(int *arr, size_t size, unsigned int tms);
int					*ft_arr_rotr(int *arr, size_t size, unsigned int tms);
int					*ft_arr_do_op(const int *arr, size_t size, \
									char op, int val);
int					*ft_arr_elem_pop(int *arr, size_t size, unsigned int pos);
void				ft_arr_print(int *arr, size_t size, char *encl);
void				ft_arr_sort_bubbl(int *arr, size_t size);
void				ft_arr_sort_insrt(int *arr, size_t size);

/*
** Functions by type matrix.h
*/

int					**ft_mat_new(int row, int col);
void				ft_mat_del(int **matrix, int row);

/*
** Functions by type stack.h
*/

void				ft_stck_show(t_stack *top);
void				ft_stck_push(t_stack *top, double newdata);
double				ft_stck_pop(t_stack *top);

/*
** Miscellaneous functions
*/

int					ft_compact(char **tab, int length);
int					ft_do_op(int nbr1, int nbr2, char op);
int					ft_file_extension(char *file, char *ext);
char				*ft_str_capitalize(char *str);
char				*ft_str_to_upcase(char *str);
char				*ft_str_to_lowcase(char *str);
char				*ft_program_name(char const *argv0);
char				*ft_remove_extension(char *filename);
char				*ft_separated_values(char **values, char c);
void				ft_swap(int *a, int *b);
void				ft_textstyle(int attr, int fg, int bg);
void				ft_textstyle_reset(void);
void				ft_puterror(char *msg, int ret);
void				ft_puterror_fd(char *msg, int ret, int fd);
size_t				ft_active_bits(int value);
size_t				ft_nbrcount(const char *s, char c);
size_t				ft_wordcount(const char *s, char c);
size_t				ft_wordlen(const char *s, char c);
size_t				ft_char_count(char **values);
size_t				ft_values_count(char **values);

#endif
