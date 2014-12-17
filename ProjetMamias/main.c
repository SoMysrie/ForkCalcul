#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
#define LECTURE 0
#define ECRITURE 1

int main ( )
{
    clock_t temps;
    int fd [2];
    int fd1 [2];
    int a,b,c,d,e,f;
    int X3,X4,X5,X6,X7,X8;


    srand(time(NULL));

    printf("Entrez la valeur de a ");
    scanf("%d",&a);
    printf("Entrez la valeur de b ");
    scanf("%d",&b);
    printf("Entrez la valeur de c ");
    scanf("%d",&c);
    printf("Entrez la valeur de d ");
    scanf("%d",&d);
    printf("Entrez la valeur de e ");
    scanf("%d",&e);
    printf("Entrez la valeur de f ");
    scanf("%d",&f);

    int X1=a+b;
    printf ("resultat X1: %d \n", X1 ) ;   //TEST X1
    int X2=c-d;
    printf ("resultat X2: %d \n", X2 ) ;   //TEST X2

    if(pipe(fd)==-1)
    {
        perror("Erreur a la creation du tube");
        exit(1);
    }
    if(pipe(fd1)==-1)
    {
        perror("Erreur a la creation du tube");
        exit(1);
    }

    switch (fork())
    {
        case -1 :
            perror("Erreur a la creation du fils" );
            exit(2);
        break ;
        case 0 :
            X5=e*f;
            if(write(fd[ECRITURE],&X5 , sizeof (X5 ) )==-1)
            {
                perror (" Erreur lors de l’ecriture du message ") ;
                exit(3);
            }
            close ( fd [ECRITURE] ) ;
            break;

        default :
                X3=X1/X2;
                printf ("resultat X3: %d \n", X3 ) ;   //TEST X3
             read (fd[LECTURE],&X5,sizeof(X5));
                printf ("resultat X5: %d \n", X5 ) ;   //TEST X5
                X6=X3+X5;
                printf ("resultat X6: %d \n", X6 ) ;   //TEST X6
                close ( fd [LECTURE] ) ;
                X7=2*X6;
                printf ("resultat X7: %d \n", X7 ) ;   //TEST X7
                switch (fork())
                {
                    case -1 :
                        perror("Erreur a la creation du fils" );
                        exit(2);
                    break ;
                    case 0 :
                        X4=X1*X2;
                        if(write(fd1[ECRITURE],&X4 , sizeof (X4 ) )==-1)
                        {
                            perror (" Erreur lors de l’ecriture du message ") ;
                            exit(3);
                        }
                        close (fd1 [ECRITURE] ) ;
                        break;

                    default :
                         read (fd1[LECTURE],&X4,sizeof(X4));

                            printf ("resultat X4: %d \n", X4 ) ;   //TEST X4
                            X8=X4+X7;
                            printf ("resultat X8: %d \n", X8 ) ;    //TEST X8
                            printf ("Resultat final: %d \n", X8 ) ;   //RESULTAT FINAL
                            close ( fd1 [LECTURE] ) ;

                }
                printf("Temps d'execution %f\n",(double)temps/CLOCKS_PER_SEC); //CALCULE LE TEMPS D EXECUTION ET LE CAST EN DOUBLE FORMULE: (double)temps/CLOCKS_PER_SEC

    }

    return 0;

}
