

int montbit(char *bits)
{
	int a = 9;
	int zero;
	zero = 0;
	int i = 0;
	while(--a >= 0)
	{
		if(bits[i] == '1')
	 		zero = (zero<<1) | 1 ;
		else if(bits[i] == '0')
			zero= zero<<1;
		i++;
	}
	return(zero);

}


int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}


void concat(char *str,char c)
{
	int len = ft_strlen(str);
	str[len] = c;
	str[len+1] = '\0';
}



int main()
{

	char ok[10] ;
	concat(ok,montbit("11110000"));
	concat(ok,montbit("10011111"));
	concat(ok,montbit("10010010"));
	concat(ok,montbit("10100101"));
	printf("%s",ok);

}