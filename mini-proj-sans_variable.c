#include <stdio.h>
#include <stdlib.h>                                     // Pour EXIT_SUCCESS et EXIT_FAILURE
#include <unistd.h>                                     // Pour les forks
#include <sys/wait.h>

int main()
{
	int a, b, c, d, e, f;		                        //declaration des valeurs
	int x1, x2, x3, x4, x5, x6, x7, x8;                 //declaration des etapes
	int T1, T2, T3, T4, T5, T6, T7, T8;                 //declaration des peres
    int cpt1, cpt2, cpt3, cpt4, cpt5, cpt6, cpt7;       //declarations des comteurs
    int op1, op2, op3, op4, op5, op6, op7, op8;         //declaration des operateurs
    int i, var1, var2, operateur;

	int tab_x1[2];						                //declaration des tableaux pour récupérer les pipe
	int tab_x2[2];
	int tab_x3[2];
	int tab_x4[2];
	int tab_x5[2];
	int tab_x6[2];
	int tab_x7[2];

	system("clear");					                //nettoie la console

    printf("Declaration des variables:\n");             //demande des variables à l'utilisateur
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);
    printf("d = ");
    scanf("%d", &d);
    printf("e = ");
    scanf("%d", &e);
    printf("f = ");
    scanf("%d", &f);

    printf("\n\n");

    printf("Declaration des étapes: \n");               //demande des étapes à l'utilisateur

    for (i=1; i<9; i++)
    {
        operateur = 0;

        printf("Pour x%d: \n", i);

        printf("Choix de la premiere variable.\n");
        printf("a = %d || b = %d || c = %d || d = %d || e = %d || f = %d\n", a, b, c, d, e, f);
        switch (i)
        {
            case 2:
                printf(" x1 = %d\n\n", x1);
                break;
            case 3:
                printf(" x1 = %d || x2 = %d\n\n", x1, x2);
                break;
            case 4:
                printf(" x1 = %d || x2 = %d || x3 = %d \n\n", x1, x2, x3);
                break;
            case 5:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d\n\n", x1, x2, x3, x4);
                break;
            case 6:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d\n\n", x1, x2, x3, x4, x5);
                break;
            case 7:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d || x6 = %d\n\n", x1, x2, x3, x4, x5, x6);
                break;
            case 8:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d || x6 = %d || x7 = %d\n\n", x1, x2, x3, x4, x5, x6, x7);
                break;
            default:
                printf("\n");
                break;
        }
        scanf("%d", &var1);

        if      (var1 == x1) cpt1 ++;
        else if (var1 == x2) cpt2 ++;
        else if (var1 == x3) cpt3 ++;
        else if (var1 == x4) cpt4 ++;
        else if (var1 == x5) cpt5 ++;
        else if (var1 == x6) cpt6 ++;
        else if (var1 == x7) cpt7 ++;
        else                 printf("\n");

        printf("\n\n");

        printf("Choix de la deuxieme variable.\n");
        printf("a = %d || b = %d || c = %d || d = %d || e = %d || f = %d\n", a, b, c, d, e, f);
        switch (i)
        {
            case 2:
                printf(" x1 = %d\n\n", x1);
                break;
            case 3:
                printf(" x1 = %d || x2 = %d\n\n", x1, x2);
                break;
            case 4:
                printf(" x1 = %d || x2 = %d || x3 = %d \n\n", x1, x2, x3);
                break;
            case 5:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d\n\n", x1, x2, x3, x4);
                break;
            case 6:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d\n\n", x1, x2, x3, x4, x5);
                break;
            case 7:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d || x6 = %d\n\n", x1, x2, x3, x4, x5, x6);
                break;
            case 8:
                printf(" x1 = %d || x2 = %d || x3 = %d || x4 = %d || x5 = %d || x6 = %d || x7 = %d\n\n", x1, x2, x3, x4, x5, x6, x7);
                break;
            default:
                printf("\n");
                break;
        }
        scanf("%d", &var2);

        if      (var2 == x1) cpt1 ++;
        else if (var2 == x2) cpt2 ++;
        else if (var2 == x3) cpt3 ++;
        else if (var2 == x4) cpt4 ++;
        else if (var2 == x5) cpt5 ++;
        else if (var2 == x6) cpt6 ++;
        else if (var2 == x7) cpt7 ++;
        else                 printf("\n");

        printf("\n\n");

        printf("Choix de l'operateur.\n");
        while(operateur<1 || operateur>4)
        {
            printf("1. +\n");
            printf("2. -\n");
            printf("3. *\n");
            printf("4. /\n");
            scanf("%d", &operateur);
        }
        switch(operateur)
        {
            case 1:
                switch (i)
                {
                    case 1:
                        x1 = var1 + var2;
                        break;
                    case 2:
                        x2 = var1 + var2;
                        break;
                    case 3:
                        x3 = var1 + var2;
                        break;
                    case 4:
                        x4 = var1 + var2;
                        break;
                    case 5:
                        x5 = var1 + var2;
                        break;
                    case 6:
                        x6 = var1 + var2;
                        break;
                    case 7:
                        x7 = var1 + var2;
                        break;
                    case 8:
                        x8 = var1 + var2;
                        break;
                    default:
                        printf("Erreur\n");
                        break;
                }
                break;
            case 2:
                switch (i)
                {
                    case 1:
                        x1 = var1 - var2;
                        break;
                    case 2:
                        x2 = var1 - var2;
                        break;
                    case 3:
                        x3 = var1 - var2;
                        break;
                    case 4:
                        x4 = var1 - var2;
                        break;
                    case 5:
                        x5 = var1 - var2;
                        break;
                    case 6:
                        x6 = var1 - var2;
                        break;
                    case 7:
                        x7 = var1 - var2;
                        break;
                    case 8:
                        x8 = var1 - var2;
                        break;
                    default:
                        printf("Erreur\n");
                        break;
                }
                break;
            case 3:
                switch (i)
                {
                    case 1:
                        x1 = var1 * var2;
                        break;
                    case 2:
                        x2 = var1 * var2;
                        break;
                    case 3:
                        x3 = var1 * var2;
                        break;
                    case 4:
                        x4 = var1 * var2;
                        break;
                    case 5:
                        x5 = var1 * var2;
                        break;
                    case 6:
                        x6 = var1 * var2;
                        break;
                    case 7:
                        x7 = var1 * var2;
                        break;
                    case 8:
                        x8 = var1 * var2;
                        break;
                    default:
                        printf("Erreur\n");
                        break;
                }
                break;
            case 4:
                switch (i)
                {
                    case 1:
                        x1 = var1 / var2;
                        break;
                    case 2:
                        x2 = var1 / var2;
                        break;
                    case 3:
                        x3 = var1 / var2;
                        break;
                    case 4:
                        x4 = var1 / var2;
                        break;
                    case 5:
                        x5 = var1 / var2;
                        break;
                    case 6:
                        x6 = var1 / var2;
                        break;
                    case 7:
                        x7 = var1 / var2;
                        break;
                    case 8:
                        x8 = var1 / var2;
                        break;
                    default:
                        printf("Erreur\n");
                        break;
                }
                break;
            default:
                printf("Erreur!\n");
                break;
        }

        printf("\n\n");
    }



	pipe (tab_x1);						                //creation du tube pour recuperer la valeur x1
	T1 = fork();						                //creation du premier fork

		if(T1 == 0)					                    //si 0, on rentre dans le premier fils
		{
			printf("Premier processus:\n\n");

			printf("x1 = %d\n", x1);

			close(tab_x1[0]);			                //fermeture de la lecture de tab_x1

			for(i=0; i<cpt1; i++)
            {
                write(tab_x1[1], &x1, sizeof(x1));	    //ecriture de x1 dans tab_x1
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x2);						                //creation du tube pour recuperer la valeur x2
	T2 = fork();						                //creation du deuxieme fork

		if(T2 == 0)					                    //si 0, on rentre dans le deuxieme fils
		{
			printf("Deuxieme processus:\n\n");

            close(tab_x1[1]);			                //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));	        //lecture de xi dans tab_xi

			printf("x2 = %d\n", x2);

			close(tab_x2[0]);			                //fermeture de la lecture de tab_x2

			for(i=0; i<cpt2; i++)
            {
                write(tab_x2[1], &x2, sizeof(x2));	    //ecriture de x2 dans tab_x2
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x3);						                //creation du tube pour recuperer la valeur x3
	T3 = fork();						                //creation du troisieme fork

		if(T3 == 0)					                    //si 0, on rentre dans le troisieme fils
		{
			printf("Troisieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi

			printf("x3 = %d\n", x3);

			close(tab_x3[0]);			                //fermeture de la lecture de tab_x3

			for(i=0; i<cpt3; i++)
            {
                write(tab_x3[1], &x3, sizeof(x3));	    //ecriture de x3 dans tab_x3
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x4);						                //creation du tube pour recuperer la valeur x4
	T4 = fork();						                //creation du quatrieme fork

		if(T4 == 0)					                    //si 0, on rentre dans le quatrieme fils
		{
			printf("Quatrieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi
            close(tab_x3[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x3[0], &x3, sizeof(x3));           //lecture de xi dans tab_xi


			printf("x4 = %d\n", x4);

			close(tab_x4[0]);			                //fermeture de la lecture de tab_x4

			for(i=0; i<cpt4; i++)
            {
                write(tab_x4[1], &x4, sizeof(x4));	    //ecriture de x4 dans tab_x4
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x5);						                //creation du tube pour recuperer la valeur x5
	T5 = fork();						                //creation du cinquieme fork

		if(T5 == 0)					                    //si 0, on rentre dans le cinquieme fils
		{
			printf("Cinquieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi
            close(tab_x3[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x3[0], &x3, sizeof(x3));           //lecture de xi dans tab_xi
            close(tab_x4[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x4[0], &x4, sizeof(x4));           //lecture de xi dans tab_xi


			printf("x5 = %d\n", x5);

			close(tab_x5[0]);			                //fermeture de la lecture de tab_x5

			for(i=0; i<cpt5; i++)
            {
                write(tab_x5[1], &x5, sizeof(x5));	    //ecriture de x5 dans tab_x5
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x6);						                //creation du tube pour recuperer la valeur x6
	T6 = fork();						                //creation du sixieme fork

		if(T6 == 0)					                    //si 0, on rentre dans le sixieme fils
		{
			printf("Sixieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi
            close(tab_x3[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x3[0], &x3, sizeof(x3));           //lecture de xi dans tab_xi
            close(tab_x4[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x4[0], &x4, sizeof(x4));           //lecture de xi dans tab_xi
            close(tab_x5[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x5[0], &x5, sizeof(x5));           //lecture de xi dans tab_xi


			printf("x6 = %d\n", x6);

			close(tab_x6[0]);			                //fermeture de la lecture de tab_x6

			for(i=0; i<cpt6; i++)
            {
                write(tab_x6[1], &x6, sizeof(x6));	    //ecriture de x6 dans tab_x6
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	pipe (tab_x7);						                //creation du tube pour recuperer la valeur x7
	T7 = fork();						                //creation du septieme fork

		if(T7 == 0)					                    //si 0, on rentre dans le septieme fils
		{
			printf("Septieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi
            close(tab_x3[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x3[0], &x3, sizeof(x3));           //lecture de xi dans tab_xi
            close(tab_x4[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x4[0], &x4, sizeof(x4));           //lecture de xi dans tab_xi
            close(tab_x5[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x5[0], &x5, sizeof(x5));           //lecture de xi dans tab_xi
            close(tab_x6[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x6[0], &x6, sizeof(x6));           //lecture de xi dans tab_xi


			printf("x7 = %d\n", x7);

			close(tab_x7[0]);			                //fermeture de la lecture de tab_x7

			for(i=0; i<cpt7; i++)
            {
                write(tab_x7[1], &x7, sizeof(x7));	    //ecriture de x7 dans tab_x7
			}

			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	T8 = fork();						                //creation du huitieme fork

		if(T8 == 0)					                    //si 0, on rentre dans le huitieme fils
		{
			printf("Huitieme processus:\n\n");

            close(tab_x1[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x1[0], &x1, sizeof(x1));           //lecture de xi dans tab_xi
            close(tab_x2[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x2[0], &x2, sizeof(x2));           //lecture de xi dans tab_xi
            close(tab_x3[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x3[0], &x3, sizeof(x3));           //lecture de xi dans tab_xi
            close(tab_x4[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x4[0], &x4, sizeof(x4));           //lecture de xi dans tab_xi
            close(tab_x5[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x5[0], &x5, sizeof(x5));           //lecture de xi dans tab_xi
            close(tab_x6[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x6[0], &x6, sizeof(x6));           //lecture de xi dans tab_xi
            close(tab_x7[1]);                           //fermeture de l'écriture de tab_xi
            read(tab_x7[0], &x7, sizeof(x7));           //lecture de xi dans tab_xi


			printf("x8 = %d\n", x8);
			exit(EXIT_SUCCESS);			                //quitte avec succes
		}

	printf("\n\n");
	sleep(3);						                    //attend 3 secondes

	return 0;
}
