#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
    return(1);
}
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

unsigned int binaryStringToUInt(const char *binaryString) {
    unsigned int result = 0;

    // Percorrer a string de caracteres '0' e '1'
    for (size_t i = 0; i < strlen(binaryString); ++i) {
        result <<= 1; // Desloca os bits de resultado para a esquerda
        if (binaryString[i] == '1') {
            result |= 1; // Define o bit mais à direita se o caractere for '1'
        }
        // Se o caractere for '0', o bit mais à direita já é 0, então não precisa fazer nada
    }

    return result;
}





int main ()
{
	char s[5];
	s[0] = 112;
	s[1] = 31;
	s[2] = 18;
	s[3] = 37;
	s[4] = '\0';




	char *ok = "💥";
	
	


	//ft_putstr_fd((char*)value,1);
	write(1,s,4);

	
}