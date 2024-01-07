#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct login{
    char user[21];
    char parola[21];
    char type[21];
    /*
    1. savings
    2. checking
    3. credit
    */
    char balance[21];
    }repo_login[100];

int marime(float suma)
{
    int nr=0;
    while(suma)
    {
        nr=nr+1;
        suma = suma/10;
    }
    return nr;
}

void make_good(char* a[])
{
    for(int i =20;i>1;i--)
    {
        if (a[i]=='\n')
            a[i]='\0';
    }
}

void actiuni_cont(u,n)
{
    printf("\n","%d",u,"\n");

    int command;
    printf("1.Vizualizare cont\n");
    printf("2.Editare cont\n");
    printf("3.Stergere cont\n");
    scanf("%d",&command);
    switch(command)
    {
    case 1:
        {
            printf("Nume:\n");
            printf("%s",repo_login[u].user);
            printf("\nTipul contului:\n");
            //printf("%s",repo_login[u].type);
            //printf("%d",strlen(repo_login[u].type));
            if(repo_login[u].type[0] == '1')
            {
                //printf("%s",repo_login[u].type);
                printf("Savings\n");
            }
            if( repo_login[u].type[0] == '2' )
                {
                   // printf("%s",repo_login[u].type);
                    printf("Checking\n");
                }
            if(repo_login[u].type[0] == '3')
                {
                    //printf("%s",repo_login[u].type);
                    printf("Credit\n");
                }
            printf("Balance:\n");
            printf("%s",repo_login[u].balance);
            break;
        }
    case 2:
        {
            char user[21],password[21];
            printf("1.Editare Username\n");
            printf("2.Schimbare Parola\n");
            printf("3.Anulare\n");
            scanf("%d",&command);
            if (command ==1)
            {

                int ok =0;
                while(ok == 0)
                {
                    ok=1;
                    printf("Introduceti usernameul nou:\n");
                    scanf("%s",&user);
                    for(int i=1;i<n;i++)
                    {
                        if(strcmp(repo_login[i].user,user) ==0)
                            {
                                printf("Username luat\n");
                                ok=0;
                            }
                    }
                }
                strcpy(repo_login[u].user,user);
               // int l=strlen(repo_login[u].user);
                //repo_login[u].user[l-1]='/0';


            }
            if(command ==2)
            {
                printf("Introduceti parola noua:\n");
                scanf("s",password);
                strcpy(repo_login[u].parola,password);
                //int l=strlen(repo_login[u].parola);
                //repo_login[u].parola[l-1]='/0';
            }
             FILE *f2 = fopen("fisier1.txt","w");
            for(int i=1;i<=n;i++)
                        {
                        fprintf(f2,"%s",repo_login[i].user);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].parola);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].type);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].balance);
                        }
                        fclose(f2);
            break;
        }
    case 3:
        {
            strcpy(repo_login[u].balance,"");
            strcpy(repo_login[u].parola,"");
            strcpy(repo_login[u].type,"");
            strcpy(repo_login[u].user,"");
            FILE *f2 = fopen("fisier1.txt","w");
            for(int i=1;i<=n;i++)
                        {
                        fprintf(f2,"%s",repo_login[i].user);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].parola);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].type);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].balance);
                        }
                        fclose(f2);
                        break;
        }
    /*case 4:
        {
            double suma;
            printf("Introduceti suma pe care doriti sa o depozitati:\n");
            scanf("%f",&suma);
            double suma_repo;
            suma_repo = atof(repo_login[u].balance);
            printf("%f",suma_repo);
            suma +=suma_repo;
            int l = marime(suma);
            gcvt(suma, l,repo_login[u].balance);
            printf("%f",repo_login[u].balance);
            break;
        }*/
    }
}

void accesare_cont(n)
{
    char user[21], parola[21];
    int ok =0;


    printf("Introduceti numele de utilizator:\n");
    scanf("%s",&user);
    int l = strlen(user);

    for (int i=1; i<n ;i++)
    {

        //repo_login[i].user[l+1]='\n';
        if(strcmp(repo_login[i].user,user) ==0)
        {
            ok =1;
            printf("Introduceti parola\n");
            scanf("%s",&parola);
            if(strcmp (repo_login[i].parola , parola) == 0)
            {
                actiuni_cont(i,n);
            }
            else
                printf("Parola incorecta");
            break;
        }

    }
    if (ok ==0)
        printf("\nNu exista cont cu acest nume de utilizator \n");

}

int main()
{



    FILE *f1 = fopen("fisier1.txt", "r");

    char user[21],dummy[21];
    char parola[21];
    int n=1;
    char aux[20];
    int a;
    while(fgets(repo_login[n].user, 20,f1) )
    {
        int ls = strlen(repo_login[n].user);
        repo_login[n].user[ls-1]='\0';
        make_good(&repo_login[n].user);


        fgets(repo_login[n].parola,20,f1);
        ls = strlen(repo_login[n].parola);
        repo_login[n].parola[ls-1]='\0';

        fgets(repo_login[n].type,20,f1);
        ls = strlen(repo_login[n].type);
        repo_login[n].type[ls-1]='\0';
        //repo_login[n].type = atoi(aux[1]);
        fgets(repo_login[n].balance,20,f1);
        ls = strlen(repo_login[n].user);
        repo_login[n].balance[ls-1]='\0';
        //repo_login[n].balance = atof(aux[1]);

        //fscanf(f1, "%f",&repo_login[n].balance);
        /*fscanf (f1, "%d", repo_login[n].type);
        fscanf(f1,"%f",repo_login[n].balance);
*/
        n++;
    }
    fclose(f1);
    /*for(int i=1;i<n;i++)
    {
        printf("user:");
        printf("%s",repo_login[i].user);
        printf("Parola:");
        printf("%s",repo_login[i].parola);
        printf("Type:");
        printf("%s",repo_login[i].type);
        printf("\n Balanta");
        printf("%s",repo_login[i].balance);
        printf("\n");
    }*/

    while(1)
    {
        printf("\n1.Accesare cont\n");
        printf("2.Creare cont\n");
        int command;
        scanf("%d", &command);
        switch (command)
        {
            case 1:
                {
                    accesare_cont(n);
                    break;
                }
            case 2:
                {
                    char username[21];
                    printf("Introduceti un username:\n");
                    scanf("%s",&username);
                    while(1)
                    {
                        int ok =0;
                        for(int i =1;i<=n;i++)
                        {
                            if(repo_login[i].user == username)
                                ok=1;
                        }
                        if (ok)
                        {
                            printf("Username existent.\nIntroduceti un username:\n");
                            scanf("%s",&username);
                        }
                        else
                            break;
                    }

                    char parola[21],tip[21];
                    char balanta[20] ="0";
                    printf("Introduceti parola\n");
                    scanf("%s",&parola);
                    printf("Selectati tipul contului:\n");
                    printf("1.savings\n2.checking\n3.credit\n");
                    scanf("%s",tip);
                    while(tip[0] !='1'&& tip[0] !='2' && tip[0] !='3')
                    {
                    printf("Tip invalid\nSelectati tipul contului:\n");
                    printf("1.savings\n2.checking\n3.credit");
                    scanf("%s",tip);
                    }
                    strcpy(repo_login[n].balance,balanta);
                    strcpy(repo_login[n].parola,parola);
                    strcpy(repo_login[n].type,tip);
                    strcpy(repo_login[n].user,username);

                    /*printf("%s",username);
                    printf("\n");
                    printf("%s",parola);
                    printf("\n");

                    /*int ls = strlen(repo_login[n].user);
                    repo_login[n].user[ls-1]='\0';
                    ls = strlen(repo_login[n].parola);
                    repo_login[n].parola[ls-1]='\0';
                    ls = strlen(repo_login[n].type);
                    repo_login[n].type[ls-1]='\0';
                    ls = strlen(repo_login[n].balance);
                    repo_login[n].balance[ls-1]='\0';*/

                        FILE *f2 = fopen("fisier1.txt","w");

                        printf("%s",repo_login[n].user);
                        printf("\n");
                        printf("%s",repo_login[n].parola);
                        printf("\n");
                        printf("%s",repo_login[n].type);
                        printf("\n");
                        printf("%s",repo_login[n].balance);
                        for(int i=1;i<=n;i++)
                        {
                        fprintf(f2,"%s",repo_login[i].user);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].parola);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].type);
                        fprintf(f2,"\n");
                        fprintf(f2,"%s",repo_login[i].balance);
                        }
                        fclose(f2);





                    n++;
                    break;
                }
            case 3:
                {
                    for(int i=1;i<n;i++)
                    {
                        printf("%s",repo_login[i].user);
                        printf("\n");
                        printf("%s",repo_login[i].parola);
                        printf("\n");
                        printf("%s",repo_login[i].type);
                        printf("\n");
                        printf("%s",repo_login[i].balance);
                        printf("\n=============\n");

                    }
                    break;
                }
            default:
                {
                    printf("default");
                    break;
                }
        }
        printf("\n\n\n");
    }


    return 0;
}

