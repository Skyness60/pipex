/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:41:47 by sperron           #+#    #+#             */
/*   Updated: 2024/09/09 09:29:14 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <sys/fcntl.h>
# include <sys/ioctl.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <sys/time.h>
# include <sys/uio.h>
# include <sys/utsname.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <stdbool.h>
# include "../lib.h"

typedef unsigned char	t_byte;

int		is_quote(char c);
int		is_separator(char c, char sep);
char	**valid(char **result, char s, int count);
char	**ft_split(char const *s, char c);
char	**split_with_quotes(char *str, char sep);
char	*prompt_command(char *result);
size_t	get_word_len(char *str, char sep);
char	*ft_strcpy(char *dest, char *src);
void	count_word_spe(char *str, char sep, int *count);
void	tab_str(char **result, char *str, char sep, int *j);
void	remove_char_from_string(char *read, char *write, char char_to_remove,
			int i);
void	valid2(char **result, char s, int count, int i);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *str, int n);
int		ft_strlen(const char *s);
int		ft_putchar(char c, int fd);
int		ft_puthexa(char form, long double nbr, int fd);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
int		ft_putstr(char *str, int fd);
int		ft_putpointer(void *adress, int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *str, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif