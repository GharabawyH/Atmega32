

#include "LSTD_TYPES.h"

#include "LASCII_CONVERT.h"
u8* FloatToAscii(f64 x)
{
	volatile u8 i = 0;
	volatile u8 j = 0;
	volatile u8 arr[] = {'0','1','2','3','4','5','6','7','8','9'};
	volatile u8 tmp[10];
	volatile s16 z;
	volatile static u8 string[10];
	volatile s16 y = (s16)x;
	if( x < 0)
	{
		z = ((x - y) * 100)*(-1);
	}
	else
	{
		z = (x - y)*100;
	}
	if( y > 0 && y < 10 )
	{
		string[j] = arr[y];
		string[j+1] = '.';
		j += 2 ;
	}
	else if( y > 10 )
	{
	
		while( y > 0 )
		{
			tmp[i] = arr[y%10];
			y = y/10;
			i++;
		}
		while(i > 0)
		{
			i -- ;
			string[j] = tmp[i];
			j ++ ;
		}
		string[j] = '.';
		j++;
	}
	else if( y > -10 && y < 0)
	{
		string[j] = '-';
		string[j+1] = arr[y];
		string[j+2] = '.';
		j += 3 ;
	}
	else if( y < -10 )
	{
		y -= 2*y;
		while( y > 0 )
		{
			tmp[i] = arr[y%10];
			y = y/10;
			i++;
		}
		string[j] = '-';
		j++;
		while(i > 0)
		{
			i -- ;
			string[j] = tmp[i];
			j ++ ;
		}
		string[j] = '.';
		j++;
	}
	if(z < 10)
	{
		string[j] = arr[z];
		string[j+1] = '\0';
	}
	else
	{
		while( z > 0 )
		{
			tmp[i] = arr[z%10];
			z = z/10;
			i++;
		}
		while( i > 0)
		{
			i -- ;
			string[j] = tmp[i];
			j++;
		}
		string[j] = '\0';
	}
	return string;
}

u8* IntegerToAscii(u32 x)
{
	volatile static u8 string[10];
	volatile u8 tmp[10];
	volatile u8 arr[]={'0','1','2','3','4','5','6','7','8','9'};
	volatile u8 i=0;
	volatile u8 j=0;
	if( x < 10)
	{
		string[i] = arr[x];
		string[i+1] = '\0';
	}
	else
	{
		while(x > 0)
		{
			tmp[i] = arr[x%10];
			x = x/10;
			i++;
		}
		while(i > 0)
		{
			i--;
			string[j] = tmp[i];
			j++;
		}
		string[j]='\0';
	}
	return string;
}
