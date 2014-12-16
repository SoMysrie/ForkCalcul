#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define LECTURE 0
#define ECRITURE 1

int main ( )
{
    int fd [2];
    int fd1 [2];
    int a,b,c,d,e,f;
    int X3,X4,X5,X6,X7,X8;
    int X1=a+b;
    int X2=c-d;

    printf("Entrez la valeur de a");
    scanf("%d",&a);
    printf("Entrez la valeur de b");
    scanf("%d",&b);
    printf("Entrez la valeur de c");
    scanf("%d",&c);
    printf("Entrez la valeur de d");
    scanf("%d",&d);
    printf("Entrez la valeur de e");
    scanf("%d",&e);
    printf("Entrez la valeur de f");
    scanf("%d",&f);

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
                read (fd[LECTURE],&X5,sizeof(X5));

                X6=X3+X5;
                printf ("resultat: %d \n", X6 ) ;   //TEST X6
                close ( fd [LECTURE] ) ;

                X7=2*X6;
                printf ("resultat: %d \n", X7 ) ;   //TEST X7
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

                            X8=X4+X7;
                            printf ("resultat: %d \n", X8 ) ;   //RESUTLTAT FINAL
                            close ( fd1 [LECTURE] ) ;

                }

    }


}
