#include<stdio.h>

int g_y;
int g_z;

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	setup(int matrix[g_y][g_z])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_y)
	{
		j = 0;
		while (j < g_z)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	special(char *pattern, int matrix[g_y][g_z], int n)
{
	int j;

	matrix[0][0] = 1;
	j = 1;
	while (j <= n)
	{
		if (pattern[j - 1] == '*')
			matrix[0][j] = matrix[0][j - 1];
		j++;
	}
}

int		ismatch(char *pattern, char *text, int n, int m)
{
	int i;
	int j;
	int matrix[g_y][g_z];

	if (n == 0)
		return (m == 0);
	setup(matrix);
	special(pattern, matrix, n);
	i = 0;
	j = 0;
	while (++i <= m)
	{
		j = 0;
		while (++j <= n)
		{
			if (pattern[j - 1] == '*')
				matrix[i][j] = matrix[i][j - 1] || matrix[i - 1][j];
			else if (pattern[j - 1] == text[i - 1])
				matrix[i][j] = matrix[i - 1][j - 1];
			else
				matrix[i][j] = 0;
		}
	}
	return (matrix[m][n]);
}

int		match(char *s1, char *s2)
{
	int textlen;
	int patternlen;

	textlen = ft_strlen(s1);
	patternlen = ft_strlen(s2);
	g_y = textlen + 1;
	g_z = patternlen + 1;
	return (ismatch(s2, s1, patternlen, textlen));
}

int main()
{
		
	printf("%d",match("","**************"));
	return 1;
}


