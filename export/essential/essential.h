#ifndef ESSENTIAL_H
# define ESSENTIAL_H
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>


size_t	ft_strlen(char const *str);
char	**split_with_quotes(char *str, char sep);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		is_quote(char c);
int		is_separator(char c, char sep);
void	count_word_spe(char *str, char sep, int *count);
void	tab_str(char **result, char *str, char sep, int *j);
char	*ft_strndup(const char *str, int n);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void remove_char_from_string(char *read, char *write, char char_to_remove, int i);
void remove_char_from_array(char **array, int num_strings, char char_to_remove);
#endif
