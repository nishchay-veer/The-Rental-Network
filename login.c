// Login System Ready For Making Video
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
// #define ENTER 13
// #define TAB 9
// #define BCKSPC 8
void verify();
int menu();
void createaccount();
void login();
// int createaccount();
void gotoxy(int, int);
FILE *fp;
struct user u, U;
int choice;
char fname[20], lname[20], uname[20], pss[20], C;
struct user
{
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
    int phnum;
    char emailid[40];
    int age;
    char locality[20];
    // int price_upperlimit;
    // int price_lowerlimit; 
};
int main()
{
    system("color 0b");
    while (1)
    {
        switch (menu())
        {
        case 1:
            createaccount();
            break;

        case 2:
            login();
            break;

            // case 3:
            //     login();
            //     break;

        case 3:
            exit(0);
        default:
            printf("Invalid Choice! ");
            break;
        }
    }

    return 0;
}
void takePassword(char pwd[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13 || ch == 9)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("*");
        }
    }
    // printf("%s", pwd);
}
int menu()
{
    int ch;
    printf("1. Signup:  \n");
    printf("2. Login:  \n");
    printf("3. Exit:  \n");
    // printf("4. :  \n");
    printf("Enter your choice :  ");
    scanf("%d", &ch);
    return ch;
}
// void verify()
// {
//     FILE *fp;
//     struct user u;
//     system("cls");
//     gotoxy(52,3);
//     printf("    Your Details Are..\n\n");
//     ///Reading from file
//     fp=fopen("C:\CHATBOT\login.txt" ,"rb+");
//     if(fp==NULL)
//     {
//         printf("\"File not found\"");
//         return ;
//     }
//     while(fread(&u, sizeof(struct user), 1, fp)){
//         printf("\n    Name: %s %s \n", u.fname,u.lname);
//         printf("\n    Username: %s\n\n    Password = %s \n\n", u.username,u.pass);
//     }
//     fclose(fp);
//     gotoxy(75,16);
//     printf("Press any key to continue...");
//     getch();
//     system("cls");
// }
void createaccount()
{
    struct user U;
    FILE *fp;
    system("cls");
    gotoxy(57, 3);
    puts("<--<<Create Account>>-->");
    printf("\n\n");
    printf("    Enter First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("    Enter Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("    Enter Age - ");
    scanf("%d", &U.age);
    printf("\n");
    printf("    Enter Username: (remember) ");
    scanf("%s", U.username);
    printf("\n");
    printf("    Enter Password: (remember) ");
    takePassword(U.pass);
    printf("\n\n");
    printf("    Enter emailID - ");
    scanf("%s", U.emailid);
    printf("\n");
    printf("    Enter Phone Num - ");
    scanf("%d", &U.phnum);
    printf("\n");
    printf("    Enter Locality in which you are (searching/lending) a home - ");
    scanf("%s", U.locality);
    printf("\n");
    // printf("    Enter price  lower limit - ");
    // scanf("%d", &U.price_lowerlimit);
    // printf("\n");
    // printf("    Enter price  upper limit - ");
    // scanf("%d", &U.price_upperlimit);
    // printf("\n");
    fp = fopen("login.txt", "ab+");
    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }
    fwrite(&U, sizeof(struct user), 1, fp);
    fclose(fp);
    system("cls");
    gotoxy(55, 20);
    printf(" Account Created Successfully.");
    gotoxy(75, 25);
    printf("Press any key to continue...");
    getch();
    system("cls");
}
void writePassword(char pss[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13 || ch == 9)
        {
            pss[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pss[i++] = ch;
            printf("*");
        }
    }
}
void login()
{
    char uname[20], pss[20];
    FILE *fp;
    struct user u;
    system("cls");
    gotoxy(53, 3);
    printf("<--<<LOGIN TO YOUR ACCOUNT>>->\n\n");
    printf(" Enter Username: ");
    scanf("%s", uname);
    printf("\n");
    printf(" Enter Password: ");
    writePassword(pss);
    /// Reading from file
    fp = fopen("login.txt", "r");
    if (fp == NULL)
    {
        printf("\"File not found\"");
        return;
    }
    int flag = 0;
    while (fread(&u, sizeof(struct user), 1, fp))
    {
        if (strcmp(uname, u.username) == 0 && strcmp(pss, u.pass) == 0)
        {
            flag++;
            printf(" \n Username And Password is Correct.\n");
            printf(" Press any key to continue...");
            getch();
            gotoxy(57, 12);
            printf(" Welcome %s %s ", u.fname, u.lname);
            getch();
        }
    }
    if (flag == 0)
    {
        printf("\n Username And Password is Incorrect.\n\n");
        printf(" Press any key to continue...");
        getch();
    }
    fclose(fp);
    system("cls");
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
