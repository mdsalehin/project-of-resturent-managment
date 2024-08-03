#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct user
{
    char name[30], pass[30];
}admin, chef;

struct customer
{
    char name[30], food[30];
    int amount;
}c[100];

int loginPortal(int a);
int adminPortal();
int chefPortal();
int foodOrder();
int foodBilling(int a);
int feedback();
void messages();
int choice;
int main()
{
    printf("\t3 Food\n\n\n");
    printf("1. Menu\n");
    printf("2. Chef Login\n");
    printf("3. Admin Login\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    loginPortal(choice);

}

int loginPortal(int a)
{
    FILE *fp;
    char name[30], pass[30], ch;

    if(a!=4){

    if(a==1)
        foodOrder();

    else if(a==3){
            printf("\nAdmin profile\n\n");
            fp=fopen("project of resturent managment admin pass.txt", "r");
            fflush(stdin);
            printf("Enter user name: ");
            gets(name);
            fflush(stdin);
            printf("Enter password: ");
            scanf("%d", pass);
            /*int i;
            for(i=0; i!=13; i++)
            {
                ch = getch();
                pass[i] = ch;
                ch = '*' ;
                printf("%c", ch);
            }*/

            fflush(stdin);
            fscanf(fp,"%s", admin.name);
            fflush(stdin);
            fscanf(fp,"%d", admin.pass);


            if(strcmp(admin.name, name)== NULL && strcmp(admin.pass, pass) ==NULL){
                printf("successfully logged in...\n\n");
                adminPortal();
    }
            else if(strcmp(admin.name, name) == NULL && strcmp(admin.pass, pass) !=NULL){
                printf("password is incorrect!!\n");
                printf("try again.\n\n");

                fclose(fp);
                loginPortal(a);
    }
            else if(strcmp(admin.name, name) != NULL && strcmp(admin.pass, pass) ==NULL){
                printf("user name is incorrect!!\n");
                printf("try again.\\nn");

                fclose(fp);
                loginPortal(a);
    }
            else if(strcmp(admin.name, name) != NULL && strcmp(admin.pass, pass) != NULL){
                printf("user name and password both are incorrect!!\n");
                printf("try again.\n\n");

                fclose(fp);
                loginPortal(a);
    }

    }
    else if(a==2){
            printf("Chef profile\n\n");
            fp=fopen("project of resturent managment chef pass.txt", "r");

            fflush(stdin);
            printf("Enter user name: ");
            gets(name);
            fflush(stdin);
            printf("Enter password: ");
            scanf("%d", &pass);

            fscanf(fp,"%s", chef.name);
            fscanf(fp,"%d", chef.pass);


            if(strcmp(chef.name, name) == NULL && strcmp(chef.pass, pass) ==NULL){
                printf("successfully logged in...\n\n");
                chefPortal();
    }
            else if(strcmp(chef.name, name) == NULL && strcmp(chef.pass, pass) !=NULL){
                printf("password is incorrect!!\n");
                printf("try again.\n");

                fclose(fp);
                loginPortal(a);
    }
            else if(strcmp(chef.name, name) != NULL && strcmp(chef.pass, pass) ==NULL){
                printf("user name is incorrect!!\n");
                printf("try again.\n");

                fclose(fp);
                loginPortal(a);
    }
            else if(strcmp(chef.name, name) != NULL && strcmp(chef.pass, pass) != NULL){
                printf("user name and password both are incorrect!!\n");
                printf("try again.\n");

                fclose(fp);
                loginPortal(a);
            }
    }
    else
    {
        printf("Wrong Choice!!\n\n\n");
        main();
    }
}
}


int foodOrder()
{
    printf("\nHere are the list of food item we have today...\n\n");
    printf("1. Regular Chicken Burger\n");
    printf("2. Pizza\n");
    printf("3. BBQ Sub Sandwich\n");
    printf("4. Regular Cold Coffee\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    foodBilling(choice);
}

int foodBilling(int a)
{
    char name[30], address[100], num[20], fb, message[300];
    int method, plate;
    FILE *fp;
    if(a==1)
    {
        printf("\nRegular Chicken Burger\n");
        printf("price: 100tk\n");
        printf("Cooking time: 30min (maximum)\n\n");
        printf("Quantity: ");
        fflush(stdin);
        scanf("%d", &plate);
        printf("1.confirm\n");
        printf("2.change item\n");
        printf("3.cancel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp=fopen("project of resturent managment odered food.txt", "a+");
            printf("Enter your name: ");
            fflush(stdin);
            gets(name);
            printf("\nYour total bill is: %dtk\n\n", 100*plate);
            printf("Would you like to pay in:\n");
            printf("1. bCash\n");
            printf("2. Rocket\n");
            fflush(stdin);
            scanf("%d", &method);
            while(method>=0||method<0)
            {
                if(method == 1 || method == 2)
                    break;
                else
                {
                    printf("Enter the Correct Value: \n");
                    printf("1. bCash\n");
                    printf("2. Rocket\n");
                    fflush(stdin);
                    scanf("%d", &method);
                }

            }

            printf("Your phone number: ");
            fflush(stdin);
            scanf("%s", &num);

            fprintf(fp, "%s ", name);
            fprintf(fp, "Regular Chicken Burger ");
            fprintf(fp, "%d ", plate);
            fprintf(fp,"%s ", num);
            fprintf(fp, "BDT: %d\n", 100*plate);
            fclose(fp);

            printf("\nThank you so much for your co-operation.\n");
            printf("Please wait a bit. Your desire food will be served very soon :)\n");

            printf("\nDo you want to give any feedback? ('y' or 'n'): ");
            fflush(stdin);
            scanf("%c", &fb);
            if(fb == 'y' || fb == 'Y')
                feedback();

            system("pause");
            system("cls");
            main();
        }
        else if(choice==2)
            foodOrder();

        else if(choice==3)
            main();

        else
        {
            printf("Invalid input!!\n");
            foodOrder();
        }
    }
    else if(a==2)
    {
        printf("\nPizza\n");
        printf("price: 180tk\n");
        printf("cooking time: 30min (maximum)\n\n");
        printf("Quantity: ");
        fflush(stdin);
        scanf("%d", &plate);
        printf("1.confirm\n");
        printf("2.change item\n");
        printf("3.cancel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp=fopen("project of resturent managment odered food.txt", "a+");
            printf("Enter your name: ");
            fflush(stdin);
            gets(name);
            printf("\nYour total bill is: %dtk\n\n", 180*plate);
            printf("Would you like to pay in:\n");
            printf("1. bCash\n");
            printf("2. Rocket\n");
            fflush(stdin);
            scanf("%d", &method);
            printf("Your phone number: ");
            fflush(stdin);
            scanf("%s", &num);

            fprintf(fp, "%s ", name);
            fprintf(fp, "Pizza " );
            fprintf(fp, "%d ", plate);
            fprintf(fp,"%s ", num);
            fprintf(fp, "BDT: %d\n", 180*plate);
            fclose(fp);

            printf("\nThank you so much for your co-operation.\n");
            printf("Please wait a bit. Your desire food will be served very soon :)\n");

            printf("\nDo you want to give any feedback? ('y' or 'n'): ");
            fflush(stdin);
            scanf("%c", &fb);
            if(fb == 'y' || fb == 'Y')
                feedback();

            system("pause");
            system("cls");
            main();
        }
        else if(choice==2)
            foodOrder();

        else if(choice==3)
            main();

        else
        {
            printf("Invalid input!!\n");
            foodOrder();
        }
    }
    if(a==3)
    {
        printf("\nBBQ Sub Sandwich\n");
        printf("price: 150tk\n");
        printf("cooking time: 30min (maximum)\n\n");
        printf("Quantity: ");
        fflush(stdin);
        scanf("%d", &plate);
        printf("1.confirm\n");
        printf("2.change item\n");
        printf("3.cancel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp=fopen("project of resturent managment odered food.txt", "a+");
            printf("Enter your name: ");
            fflush(stdin);
            gets(name);
            printf("\nYour total bill is: %dtk\n\n", 150*plate);
            printf("Would you like to pay in:\n");
            printf("1. bCash\n");
            printf("2. Rocket\n");
            fflush(stdin);
            scanf("%d", &method);
            printf("Your phone number: ");
            fflush(stdin);
            scanf("%s", &num);

            fprintf(fp, "%s ", name);
            fprintf(fp, "BBQ Sub Sandwich ");
            fprintf(fp, "%d ", plate);
            fprintf(fp,"%s ", num);
            fprintf(fp, "BDT: %d\n", 150*plate);
            fclose(fp);

            printf("\nThank you so much for your co-operation.\n");
            printf("Please wait a bit. Your desire food will be served very soon :)\n");

            printf("\nDo you want to give any feedback? ('y' or 'n'): ");
            fflush(stdin);
            scanf("%c", &fb);
            if(fb == 'y' || fb == 'Y')
                    feedback();

            system("pause");
            system("cls");
            main();
        }
        else if(choice==2)
            foodOrder();

        else if(choice==3)
            main();

        else
        {
            printf("Invalid input!!\n");
            foodOrder();
        }
    }
    if(a==4)
    {
        printf("\nRegular Cold Coffee\n");
        printf("price: 60tk\n");
        printf("cooking time: 30min (maximum)\n\n");
        printf("Quantity: ");
        fflush(stdin);
        scanf("%d", &plate);
        printf("1.confirm\n");
        printf("2.change item\n");
        printf("3.cancel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            fp=fopen("project of resturent managment odered food.txt", "a+");
            printf("Enter your name: ");
            fflush(stdin);
            gets(name);
            printf("\nYour total bill is: %dtk\n\n", 60*plate);
            printf("Would you like to pay in:\n");
            printf("1. bCash\n");
            printf("2. Rocket\n");
            fflush(stdin);
            scanf("%d", &method);
            printf("Your phone number: ");
            fflush(stdin);
            scanf("%s", &num);

            fprintf(fp, "%s ", name);
            fprintf(fp, "Regular Cold Coffee ");
            fprintf(fp, "%d ", plate);
            fprintf(fp,"%s ", num);
            fprintf(fp, "BDT: %d\n", 60*plate);
            fclose(fp);

            printf("\nThank you so much for your co-operation.\n");
            printf("Please wait a bit. Your desire food will be served very soon :)\n");

            printf("\nDo you want to give any feedback? ('y' or 'n'): ");
            fflush(stdin);
            scanf("%c", &fb);
            if(fb == 'y' || fb == 'Y')
                feedback();

            system("pause");
            system("cls");
            main();
        }
        else if(choice==2)
            foodOrder();

        else if(choice==3)
            main();

        else
        {
            printf("Invalid input!!\n");
            foodOrder();
        }
    }
    else
        {
            printf("Invalid input\n");
            printf("try again..\n");
            main();
        }
}

int feedback()
{
    FILE *fp;
    char message[100];
    printf("Enter your Feedback: ");
    fflush(stdin);
    fp=fopen("project feedback.txt", "w");
    gets(message);
    fprintf(fp, "%s\n", message);
    fclose(fp);
}

int adminPortal()
{
    printf("\n\tWelcome to admin portal.\n\n");
    printf("1. Total Order\n");
    printf("2. Message to chef\n");
    printf("3. See Feedback\n");
    printf("4. Logout\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        totalOrder();
//    else if(choice == 2)
 //       totalCustomer();
    else if(choice == 2)
        {
            message();
            adminPortal();
        }
    else if(choice == 3)
    {
        char feedback[200];
        FILE *fp;
        fp = fopen("project feedback.txt", "r");
        fscanf(fp, "%[^\n]", feedback);
        fclose(fp);
        puts(feedback);
        system("pause");
        system("cls");
        adminPortal();
    }
    else if(choice==4)
    {
        printf("successfully logged out...\n");
        system("pause");
        system("cls");
        main();
    }
    else
    {
        printf("wrong input\n");
        adminPortal();
    }
}

void message()
{
    char messages[100];
    FILE *fp;
    fp=fopen("message.txt", "w");
    printf("Enter your message: ");
    fflush(stdin);
    gets(messages);
    fprintf(fp, "%s", messages);
    fclose(fp);
    adminPortal();

}

int chefPortal()
{
    printf("\n\tWelcome to chef portal.\n\n");
    printf("1. Total Order\n");
    printf("2. Message from admin\n");
    printf("3. See Feedback\n");
    printf("4. Logout\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        {
            FILE *fp;
            fp=fopen("project of resturent managment odered food.txt", "rb");
            fseek(fp, 0, SEEK_END);
            long fsize = ftell(fp);
            fseek(fp, 0, SEEK_SET);

            char *string = malloc(fsize + 1);
            fread(string, fsize, 1, fp);
            fclose(fp);

            string[fsize] = 0;

            printf("%s\n\n", string);

            system("pause");
            system("cls");
            chefPortal();
        }
   // else if(choice == 2)
 //       totalCustomer();
    else if(choice == 2)
        {
            char messages[300];
            FILE *fp;
            fp=fopen("message.txt", "r");

            fscanf(fp, "%[^\n]", messages);
            fclose(fp);
            //puts(feedback);
            /*fseek(fp, 0, SEEK_END);
            long fsize = ftell(fp);
            fseek(fp, 0, SEEK_SET);

            char *string = malloc(fsize + 1);
            fread(string, fsize, 1, fp);
            fclose(fp);

            string[fsize] = 0;
*/
            puts(messages);
            system("pause");
            system("cls");
            chefPortal();
        }
    else if(choice == 3)
    {
        char feedback[200];
        FILE *fp;
        fp = fopen("project feedback.txt", "r");
        fscanf(fp, "%[^\n]", feedback);
        fclose(fp);
        puts(feedback);
        system("pause");
        system("cls");
        chefPortal();
    }
    else if(choice==4)
    {
        printf("successfully logged out...\n");
        system("pause");
        system("cls");
        main();
    }
    else
    {
        printf("wrong input\n");
        chefPortal();
    }
}

void totalOrder()
{
    FILE *fp;
    fp=fopen("project of resturent managment odered food.txt", "rb");
    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);  //same as rewind(f);

    char *string = malloc(fsize + 1);
    fread(string, fsize, 1, fp);
    fclose(fp);

    string[fsize] = 0;

    printf("%s\n\n", string);

    system("pause");
    system("cls");
    adminPortal();

}
