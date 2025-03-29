#include<stdio.h>
#include<string.h>
#include<math.h>
/*
int main()
{
	int a = 0;
	int b;
	int arr[10];
	printf("%d\n",a);
	printf("%d",sizeof (arr)/sizeof arr[0]);
	return 0;
	
}

void sed()
{
	printf("hello\n");
}
int main()
{
	int a=0;
	int b=0;
	while(a<10)
	{
		sed();
		a++;
	}
	return 0;
}
*/
int main()
{
	
	int i = 0;
	for(i=100;i<=200;i++)
	{
		int flag=1;
		int j = 0;
		for(j=2; j<=sqrt(i); j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
			
		}
	
		if(flag==1)
		printf("%d ",i);
		
	}
	
	return 0;
}




