#include <stdio.h> 
#include <stdlib.h> // Pour EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h> // Pour les forks
#include<sys/wait.h>

int main()
{
	int a, b, c, d, e , f, g;
	int T1, T2, T3, T4, T5, T6, T7, T8;
	int x1, x2, x3, x4, x5, x6, x7, x8;

	int tab_x1[2];
	int tab_x2[2];
	int tab_x3[2];
	int tab_x4[2];
	int tab_x5[2];
	int tab_x6[2];
	int tab_x7[2];
	
	system("clear");
	
	T1 = fork();
	pipe (tab_x1);
	
		if(T1 == 0)
		{
			printf("Premier processus:\n\n"); 
			
			x1 = a + b;
			printf("x1 = %d\n", x1);
			
			close(tab_x1[0]);
			write(tab_x1[1], &x1, sizeof(x1));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T2 = fork();
	pipe (tab_x2);
	
		if(T2 == 0)
		{
			printf("Deuxieme processus:\n\n"); 
			
			x2 = c - d;
			printf("x2 = %d\n", x2);
			
			close(tab_x2[0]);
			write(tab_x2[1], &x2, sizeof(x2));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T3 = fork();
	pipe (tab_x3);
	
		if(T3 == 0)
		{
			printf("Troisieme processus:\n\n"); 
			
			close(tab_x1[1]);
			read(tab_x1[0], &x1, sizeof(x1));
			close(tab_x2[1]);
			read(tab_x2[0], &x2, sizeof(x2));
			
			x3 = x1 / x2;
			printf("x3 = %d\n", x3);
			
			close(tab_x3[0]);
			write(tab_x3[1], &x3, sizeof(x3));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T4 = fork();
	pipe (tab_x4);
	
		if(T4 == 0)
		{
			printf("Quatrieme processus:\n\n"); 
			
			close(tab_x1[1]);
			read(tab_x1[0], &x1, sizeof(x1));
			close(tab_x2[1]);
			read(tab_x2[0], &x2, sizeof(x2));
			
			x4 = x1 * x2;
			printf("x4 = %d\n", x4);
			
			close(tab_x4[0]);
			write(tab_x4[1], &x4, sizeof(x4));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T5 = fork();
	pipe (tab_x5);
	
		if(T5 == 0)
		{
			printf("Cinquieme processus:\n\n"); 
			
			x5 = e * f;
			printf("x5 = %d\n", x5);
			
			close(tab_x5[0]);
			write(tab_x5[1], &x5, sizeof(x5));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T6 = fork();
	pipe (tab_x6);
	
		if(T6 == 0)
		{
			printf("Sixieme processus:\n\n"); 
			
			close(tab_x3[1]);
			read(tab_x3[0], &x3, sizeof(x3));
			close(tab_x5[1]);
			read(tab_x5[0], &x5, sizeof(x5));
			
			x6 = x3 + x5;
			printf("x6 = %d\n", x6);
			
			close(tab_x6[0]);
			write(tab_x6[1], &x6, sizeof(x6));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T7 = fork();
	pipe (tab_x7);
	
		if(T7 == 0)
		{
			printf("Septieme processus:\n\n"); 
			
			close(tab_x6[1]);
			read(tab_x6[0], &x6, sizeof(x6));
			
			x7 = 2 * x6;
			printf("x7 = %d\n", x7);
			
			close(tab_x7[0]);
			write(tab_x7[1], &x7, sizeof(x7));
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	T8 = fork();
	
		if(T8 == 0)
		{
			printf("Huitieme processus:\n\n"); 
			
			close(tab_x4[1]);
			read(tab_x4[0], &x4, sizeof(x4));
			close(tab_x7[1]);
			read(tab_x7[0], &x7, sizeof(x7));
			
			x8 = x7 + x4;
			printf("x8 = %d\n", x8);
			exit(EXIT_SUCCESS);
		}	
	
	printf("\n\n");
	sleep(3);
	
	return 0;
}
