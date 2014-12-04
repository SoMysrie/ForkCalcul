#include <stdio.h>
#include <stdlib.h> // Pour EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h> // Pour les forks
#include<sys/wait.h>

int main()
{
	int a = 4, b = 2, c = 4, d = 2, e = 2, f = 2;		//declaration des valeurs
	int x1, x2, x3, x4, x5, x6, x7, x8;
	int T1, T2, T3, T4, T5, T6, T7, T8;

	int tab_x1[2];						                //declaration des tableaux pour récupérer les pipe
	int tab_x2[2];
	int tab_x3[2];
	int tab_x4[2];
	int tab_x5[2];
	int tab_x6[2];
	int tab_x7[2];

	system("clear");					                //nettoie la console

	pipe (tab_x1);						                //creation du tube pour recuperer la valeur x1
	T1 = fork();						                //creation du premier fork

		if(T1 == 0)					                    //si 0, on rentre dans le premier fils
		{
			printf("Premier processus:\n\n");

			x1 = a + b;				                    //calcul de x1
			printf("x1 = %d\n", x1);

			close(tab_x1[0]);			                //fermeture de la lecture de tab_x1
			write(tab_x1[1], &x1, sizeof(x1));	        //ecriture de x1 dans tab_x1 pour x3
			write(tab_x1[1], &x1, sizeof(x1));	        //ecriture de x1 dans tab_x1 pour x4
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x2);						                //creation du tube pour recuperer la valeur x2
	T2 = fork();						                //creation du deuxieme fork

		if(T2 == 0)					                    //si 0, on rentre dans le deuxieme fils
		{
			printf("Deuxieme processus:\n\n");

			x2 = c - d;				                    //calcul de x2
			printf("x2 = %d\n", x2);

			close(tab_x2[0]);			                //fermeture de la lecture de tab_x2
			write(tab_x2[1], &x2, sizeof(x2));	        //ecriture de x2 dans tab_x2 pour x3
			write(tab_x2[1], &x2, sizeof(x2));	        //ecriture de x2 dans tab_x2 pour x4
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x3);						                //creation du tube pour recuperer la valeur x3
	T3 = fork();						                //creation du troisieme fork

		if(T3 == 0)					                    //si 0, on rentre dans le troisieme fils
		{
			printf("Troisieme processus:\n\n");

			close(tab_x1[1]);			                //fermeture de l'écriture de tab_x1
			read(tab_x1[0], &x1, sizeof(x1));	        //lecture de x1 dans tab_x1
			close(tab_x2[1]);			                //fermeture de l'écriture de tab_x2
			read(tab_x2[0], &x2, sizeof(x2));	        //lecture de x2 dans tab_x2

			x3 = x1 / x2;				                //calcul de x3
			printf("x3 = %d\n", x3);

			close(tab_x3[0]);			                //fermeture de la lecture de tab_x3
			write(tab_x3[1], &x3, sizeof(x3));	        //ecriture de x3 dans tab_x3 pour x6
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x4);						                //creation du tube pour recuperer la valeur x4
	T4 = fork();						                //creation du quatrieme fork

		if(T4 == 0)					                    //si 0, on rentre dans le quatrieme fils
		{
			printf("Quatrieme processus:\n\n");

			close(tab_x1[1]);			                //fermeture de l'écriture de tab_x1
			read(tab_x1[0], &x1, sizeof(x1));	        //lecture de x1 dans tab_x1
			close(tab_x2[1]);			                //fermeture de l'écriture de tab_x2
			read(tab_x2[0], &x2, sizeof(x2));	        //lecture de x2 dans tab_x2

			x4 = x1 * x2;				                //calcul de x4
			printf("x4 = %d\n", x4);

			close(tab_x4[0]);			                //fermeture de la lecture de tab_x4
			write(tab_x4[1], &x4, sizeof(x4));	        //ecriture de x4 dans tab_x4 pour x8
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x5);						                //creation du tube pour recuperer la valeur x5
	T5 = fork();						                //creation du cinquieme fork

		if(T5 == 0)					                    //si 0, on rentre dans le cinquieme fils
		{
			printf("Cinquieme processus:\n\n");

			x5 = e * f;				                    //calcul de x5
			printf("x5 = %d\n", x5);

			close(tab_x5[0]);			                //fermeture de la lecture de tab_x5
			write(tab_x5[1], &x5, sizeof(x5));	        //ecriture de x5 dans tab_x5 pour x6
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x6);						                //creation du tube pour recuperer la valeur x6
	T6 = fork();						                //creation du sixieme fork

		if(T6 == 0)					                    //si 0, on rentre dans le sixieme fils
		{
			printf("Sixieme processus:\n\n");

			close(tab_x3[1]);			                //fermeture de l'écriture de tab_x3
			read(tab_x3[0], &x3, sizeof(x3));	        //lecture de x3 dans tab_x3
			close(tab_x5[1]);			                //fermeture de l'écriture de tab_x5
			read(tab_x5[0], &x5, sizeof(x5));	        //lecture de x5 dans tab_x5

			x6 = x3 + x5;		                        //calcul de x6
			printf("x6 = %d\n", x6);

			close(tab_x6[0]);			                //fermeture de la lecture de tab_x6
			write(tab_x6[1], &x6, sizeof(x6));	        //ecriture de x6 dans tab_x6 pour x7
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x7);						                //creation du tube pour recuperer la valeur x7
	T7 = fork();						                //creation du septieme fork

		if(T7 == 0)					                    //si 0, on rentre dans le septieme fils
		{
			printf("Septieme processus:\n\n");

			close(tab_x6[1]);			                //fermeture de l'écriture de tab_x6
			read(tab_x6[0], &x6, sizeof(x6));	        //lecture de x6 dans tab_x6

			x7 = 2 * x6;				                //calcul de x7
			printf("x7 = %d\n", x7);

			close(tab_x7[0]);			                //fermeture de la lecture de tab_x7
			write(tab_x7[1], &x7, sizeof(x7));	        //ecriture de x7 dans tab_x7 pour x8
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	T8 = fork();						                //creation du huitieme fork

		if(T8 == 0)					                    //si 0, on rentre dans le huitieme fils
		{
			printf("Huitieme processus:\n\n");

			close(tab_x4[1]);			                //fermeture de l'écriture de tab_x4
			read(tab_x4[0], &x4, sizeof(x4));	        //lecture de x4 dans tab_x4
			close(tab_x7[1]);			                //fermeture de l'écriture de tab_x7
			read(tab_x7[0], &x7, sizeof(x7));	        //lecture de x7 dans tab_x7

			x8 = x7 + x4;				                //calcul de x8
			printf("x8 = %d\n", x8);
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	return 0;
}
