
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
void verify();
int menu();
void createaccount();
void login();
void searchDetails();

void gotoxy(int, int);
FILE *fp;
struct user u, U;
void addTenantsInfo(struct user, struct user);
int choice;
char fname[20], lname[20], uname[20], pss[20], C;
struct house
{
    char name[50];
    char ldaApp[2];
    char parkingLot[2];
    char locality[50];
    int bhk;
    int price;
    char pss[20];
};
struct user
{
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
    double phnum;
    char emailid[100];
    int age;
    char position[1];
};
struct tenantInfo
{
    char opass[50];
    char ousername[50];
    char tenantname[50];
    char tenantpass[50];
    char occ[20];
    int members;
    int duration;
    char isMarried[20];
};
int main()
{
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

        case 3:
            exit(0);
        default:
            printf("Invalid Choice ! ");
            exit(0);
            // break;
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
void createaccount()
{
    struct user U;
    FILE *fp, *fp2;
    int z, j;
    system("cls");
    gotoxy(45, 3);
    // gotoxy(53, 3);
    char name[50] = "CREATE ACCOUNT";
    z = strlen(name);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        printf(" %c", name[j]);
    }
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
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
    if (!(U.age > 0 && U.age < 200))
    {
        printf("\n");
        printf("Enter a valid age");
        printf("\n");
        Sleep(1000);
        createaccount();
    }
    printf("\n");
    printf("    Enter Username : (remember/ without spaces) ");
    // char temp;
    // scanf("%c", &temp);
    scanf("%s", U.username);
    printf("\n");

    printf("    Enter Password: (remember) ");
    takePassword(U.pass);
    printf("\n\n");
    printf("    Enter emailID - ");
    scanf("%s", U.emailid);
    int flag = 0;
    int k = strlen(U.emailid);
    for (int i = 0; i < k; i++)
    {
        if (U.emailid[i] == '@' || U.emailid[i] == '.')
        {
            flag++;
        }
    }
    if (flag < 2)
    {
        printf("\nPlease enter a valid email id. \n");
        Sleep(1000);
        createaccount();
    }

    printf("\n");
    printf("    Enter Phone Num - ");
    scanf("%lf", &U.phnum);
    if (!(U.phnum > 1000000000 && U.phnum < 9999999999))
    {
        printf("\n");
        printf("Please enter a valid phone number.");
        printf("\n");
        Sleep(1000);
        createaccount();
    }
    printf("\n");
    printf("    Are you an Owner(o) or a Tenant(t) - ");
    scanf("%s", U.position);
    printf("\n");
    if (U.position[0] == 'o')
    {
        fp2 = fopen("owner.txt", "ab+");
        if (fp2 == NULL)
        {
            printf("\nError opened file\n");
            exit(1);
        }
        fwrite(&U, sizeof(struct user), 1, fp2);
        fclose(fp2);
    }
    else if (U.position[0] == 't')
    {
        fp2 = fopen("tenant.txt", "ab+");
        if (fp2 == NULL)
        {
            printf("\nError opened file\n");
            exit(1);
        }
        fwrite(&U, sizeof(struct user), 1, fp2);
        fclose(fp2);
    }
    fp = fopen("login.txt", "ab+");
    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(0);
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
    main();
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
// void input(char *x , char *y){
//     *x = *y;
// }
void addDetails(char *ptr)
{
    system("cls");
    gotoxy(31, 4);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB NEW SECTION \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    FILE *fptr;
    char nameofapp[100];
    char locality[100];
    int price;
    int bhk;
    char ldaApp[100];
    char parking[100];
    fptr = fopen("houses.txt", "ab+"); // ab+ gives us the ability of writing the function and add the second data in the existing one...
    if (fptr == NULL)
    {
        printf("Failed to create the required file.");
    }
    else
    {
        struct house H;
        char temp;
        gotoxy(31, 6);
        printf("Name of the Apartment:\t");
        // gotoxy(52,6);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.name);
        // fgets(nameofapp, 200, stdin);
        gotoxy(31, 7);
        printf("Locality:\t");
        // gotoxy(52,7);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.locality);
        // fgets(locality, 200, stdin);
        // scanf("%[^\n]", locality);
        gotoxy(31, 8);
        printf("BHK:\t");
        // gotoxy(52,9);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%d", &H.bhk);
        // fgets(locality, 200, stdin);
        gotoxy(31, 9);
        printf("Is it LDA Approved(y/n):\t");
        // gotoxy(57,10);
        // scanf("%c", &temp); //temp statement to clear buffer
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.ldaApp);
        gotoxy(31, 10);
        printf("Does it have any parking area (y/n):\t");
        // gotoxy(70,11);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%[^\n]", H.parkingLot);
        gotoxy(31, 11);
        printf("Price:\t");
        // gotoxy(52,8);
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%d", &H.price);
        // char *ptr = pss;
        strcpy(H.pss, ptr);
        // Sleep(3000);
        // strcpy(H.pss, *ptr);
        // printf("%s", H.pss);
        // Sleep(5000);

        fwrite(&H, sizeof(struct house), 1, fptr);
        fclose(fptr);
    }
    fclose(fptr);
    system("cls");
    char string[200] = "House details added successfully. Tenants will reach to you shortly.";
    int z = strlen(string);
    for (int i = 0; i <= z; i++)
    {
        Sleep(60);
        printf(" %c", string[i]);
    }
    Sleep(1000);
    login();
}
void tenantRequests(struct user u)
{
    // printf("%d", u.age);
    // Sleep(5000);
    system("cls");
    struct tenantInfo ti;
    struct user f;
    FILE *fp1, *fp2;
    fp1 = fopen("tenants-info.txt", "r");

    int flag = 0;
    if (fp1 == NULL)
    {
        printf("\"File not found\"");
        return;
    }
    while (fread(&ti, sizeof(struct tenantInfo), 1, fp1))
    {
        if (strcmp(u.pass, ti.opass) == 0 && strcmp(u.username, ti.ousername) == 0)
        {
            fp2 = fopen("tenant.txt", "r");
            while (fread(&f, sizeof(struct user), 1, fp2))
            {
                if (strcmp(f.pass, ti.tenantpass) == 0 && strcmp(f.username, ti.tenantname) == 0)
                {
                    printf("\n");
                    // gotoxy(28, 5);
                    printf("----------------------------------------");
                    printf("\n");
                    // gotoxy(31, 6.5);
                    printf("\xB3\xB2\xB2\xB2 Name of the Tenant:\t%s %s", f.fname, f.lname);
                    printf("\n");
                    // gotoxy(31, 7);
                    printf("\xB3\xB2\xB2\xB2 Age:\t%d", f.age);
                    printf("\n");
                    // gotoxy(31, 8);
                    printf("\xB3\xB2\xB2\xB2 Occupation:\t%s", ti.occ);
                    printf("\n");
                    // gotoxy(31, 9);
                    printf("\xB3\xB2\xB2\xB2 Married ? (y/n) :\t%s", ti.isMarried);
                    printf("\n");
                    printf("\xB3\xB2\xB2\xB2 Members in the family:\t%d", ti.members);
                    printf("\n");
                    // gotoxy(31, 10);
                    // gotoxy(31, 11);
                    printf("\xB3\xB2\xB2\xB2 Duration for which he/she wants your house ? \t%d", ti.duration);
                    printf("\n\n");
                    printf("CONTACT DETAILS\n");
                    printf("\xB3\xB2\xB2\xB2 Phone Number:\t%0.lf", f.phnum);
                    printf("\n");
                    printf("\xB3\xB2\xB2\xB2 Email-ID:\t%s", f.emailid);
                    printf("\n");

                    // gotoxy(28, 5);
                    printf("----------------------------------------");
                    printf("\n");
                    flag++;
                }
            }
            fclose(fp2);
        }
    }
    fclose(fp1);
    if (flag == 0)
    {
        system("cls");
        gotoxy(39, 4);

        char string[200] = "No requests found :(";
        int z = strlen(string);
        for (int i = 0; i <= z; i++)
        {
            Sleep(60);
            printf(" %c", string[i]);
        }
        Sleep(2000);
        login();
    }
    getch();
    login();
}
void searchDetails(struct user U)
{
    struct house h;
    struct user u;
    FILE *fptr, *fp;
    int flag = 0;
    int res;
    char pss[20];
    char nameofapp[100];
    char locality[100];
    int price;
    char ldaApp[100];
    char parking[100];
    int bhk;
    int bhk1;
    int ul;
    int ll;
    char name1[100];
    system("cls");
    fflush(stdin);
    // gotoxy(18, 2);
    printf("\xDB\xDB\xDB Search city, locality, project/ society, landmarks:: ");
    scanf("%[^\n]", name1);
    // printf("%s", name1);
    printf("\n");
    printf("\xDB\xDB\xDB Price lower limit:: ");
    scanf("%d", &ll);
    printf("\n");
    // printf("%d", ll);
    printf("\xDB\xDB\xDB Price upper limit:: ");
    scanf("%d", &ul);
    printf("\n");
    // printf("%d", ul);
    printf("\xDB\xDB\xDB How many number of bedrooms you want(BHK):: ");
    scanf("%d", &bhk1);
    printf("\n");
    // printf("%d", bhk1);
    fptr = fopen("houses.txt", "r");
    // fflush(stdin);
    int i = 0;
    while (fread(&h, sizeof(struct house),1,fptr)){
        // printf("%s", locality);
        // Sleep(5000);
        res = strcmp(h.locality, name1);

        if (res == 0 && h.price <= ul && h.price >= ll && bhk1 == h.bhk)
        {
            // gotoxy(39, 4);
            if (i == 0)
            {
                printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Record(s) Found \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
                i++;
            }

            printf("\n");
            // gotoxy(28, 5);
            printf("----------------------------------------");
            printf("\n");
            // gotoxy(31, 6.5);
            printf("\xB3\xB2\xB2\xB2 Name of the Apartment:\t%s", h.name);
            printf("\n");
            // gotoxy(31, 7);
            printf("\xB3\xB2\xB2\xB2 Locality:\t%s", h.locality);
            printf("\n");
            // gotoxy(31, 8);
            printf("\xB3\xB2\xB2\xB2 Price:\t%d", h.price);
            printf("\n");
            // gotoxy(31, 9);
            printf("\xB3\xB2\xB2\xB2 BHK:\t%d", h.bhk);
            printf("\n");
            // gotoxy(31, 10);
            printf("\xB3\xB2\xB2\xB2 LDA Approved (y/n) :\t%s", h.ldaApp);
            printf("\n");
            // gotoxy(31, 11);
            printf("\xB3\xB2\xB2\xB2 Parking Lot ? \t%s", h.parkingLot);
            printf("\n\n");

            // gotoxy(31,14);
            printf("OWNER  DETAILS");
            printf("\n");
            // gotoxy(31,15);
            fp = fopen("owner.txt", "r");
            while (fread(&u, sizeof(struct user), 1, fp))
            {
                if (strcmp(h.pss, u.pass) == 0)
                {
                    // gotoxy(31,17);
                    printf("\xB3\xB2\xB2\xB2 Name of the Owner:\t%s %s", u.fname, u.lname);
                    printf("\n");
                    // gotoxy(31,18);
                    printf("\xB3\xB2\xB2\xB2 Phone Number:\t%0.lf", u.phnum);
                    printf("\n");
                    // gotoxy(31,19);
                    printf("\xB3\xB2\xB2\xB2 Email-id:\t%s", u.emailid);
                    printf("\n\n");
                    printf("----------------------------------------");
                }
            }
            flag = 1;

            // gotoxy(31,21);

            // flag = 1;
            // Sleep(1000);
            fclose(fp);
            printf("\n");
            // // gotoxy(18, 12);
            // printf("Enter any key for menu option.");
            // while (getch())
            // {
            // 	menu();
            // }
        }
    }
    if (flag == 0)
    {
        system("cls");
        gotoxy(39, 4);

        char string[200] = "No record found :(";
        int z = strlen(string);
        for (int i = 0; i <= z; i++)
        {
            Sleep(60);
            printf(" %c", string[i]);
        }
        Sleep(1000);
        login();
    }

    fclose(fptr);
    char firstname[50], lastname[50];
    printf("\n Enter the name of the owner whom you want to connect with or press y to go to main menu : ");
    if (getch() == 'y')
    {
        printf("\n");
        main();
    }
    scanf("%s %s", firstname, lastname);

    fp = fopen("owner.txt", "r");
    while (fread(&u, sizeof(struct user), 1, fp))
    {
        if ((strcmp(firstname, u.fname) == 0) && (strcmp(lastname, u.lname) == 0))
        {
            addTenantsInfo(U, u);
        }
    }
}

void addTenantsInfo(struct user tenant, struct user owner)
{
    FILE *fptr;
    struct tenantInfo tp;
    printf("\nOWNER WANTS TO KNOW \n");
    printf("Your Occupation:: ");
    scanf("%s", tp.occ);
    printf("\n");
    printf("Are you married ? (y/n) ");
    scanf("%s", tp.isMarried);
    printf("\n");
    printf("How many members will be there ? ");
    scanf("%d", &tp.members);
    printf("\n");
    printf("For how many months you want this place to live ? ");
    scanf("%d", &tp.duration);
    printf("\n");
    strcpy(tp.opass, owner.pass);
    strcpy(tp.tenantpass, tenant.pass);
    strcpy(tp.tenantname, tenant.username);
    strcpy(tp.ousername, owner.username);

    fptr = fopen("tenants-info.txt", "ab+");
    if (fptr == NULL)
    {
        printf("Failed to create the required file.");
    }
    else
    {
        fwrite(&tp, sizeof(struct tenantInfo), 1, fptr);
        // fclose(fptr);
    }
    fclose(fptr);
    system("cls");
    char string[200] = "Your details added successfully. Owner will reach to you shortly.";
    int z = strlen(string);
    for (int i = 0; i <= z; i++)
    {
        Sleep(60);
        printf(" %c", string[i]);
    }
    Sleep(1000);
    printf("\n");
    system("cls");
    main();
}
void login()
{
    char uname[20], pss[20];
    int z, j;
    FILE *fp1;
    struct user u;
    system("cls");
    gotoxy(45, 3);
    char name[50] = "LOGIN TO YOUR ACCOUNT";
    z = strlen(name);
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    for (j = 0; j <= z; j++)
    {
        Sleep(60);
        printf(" %c", name[j]);
    }
    for (j = 0; j <= 16; j++)
    {
        Sleep(50);
        printf("\xDB");
    }
    gotoxy(45, 5);
    printf(" Enter Username: ");
    scanf("%s", uname);
    gotoxy(45, 7);
    printf(" Enter Password: ");
    writePassword(pss);
    /// Reading from file
    fp1 = fopen("login.txt", "r");
    if (fp1 == NULL)
    {
        printf("\"File not found\"");
        return;
    }
    int flag = 0;
    char str[10];
    char *ptr = str;
    while (fread(&u, sizeof(struct user), 1, fp1))
    {
        if (strcmp(uname, u.username) == 0 && strcmp(pss, u.pass) == 0)
        {
            flag++;
            printf(" \n Username And Password is Correct.\n");
            printf(" Press any key to continue...");
            getch();
            gotoxy(45, 12);

            if (u.position[0] == 'o')
            {
                ptr = "OWNER";
            }
            else if (u.position[0] == 't')
            {
                ptr = "TENANT";
            }
            else
            {
                printf("Invalid choice\n");
                exit(0);
            }
            printf("\xB3\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME %s %s. YOU ARE LOGGED IN AS %s \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB3", u.fname, u.lname, ptr);
            // printf(" Welcome %s %s. ", u.fname, u.lname);
            // printf("You are logged in as %s", ptr);
            getch();
            printf("\n");
            gotoxy(45, 15);
            if (ptr == "TENANT")
            {
                int k;
                printf("1. Search for home:  \n");
                gotoxy(45, 18);
                printf("2. Exit:  \n");
                printf("\n");
                // printf("4. :  \n");
                gotoxy(45, 21);
                printf("Enter your choice :  ");
                scanf("%d", &k);
                switch (k)
                {
                case 2:
                    exit(0);
                    break;
                case 1:
                    searchDetails(u);
                    break;
                default:
                    printf("Invalid choice !");
                    exit(0);
                    break;
                }
            }
            else
            {
                int k;
                printf("1. Add home details:  \n");
                gotoxy(45, 17);
                printf("2. Tenant Requests:  \n");
                gotoxy(45, 19);
                printf("3. Exit:  \n");
                printf("\n");
                // printf("4. :  \n");
                gotoxy(45, 21);
                printf("Enter your choice :  ");
                scanf("%d", &k);
                switch (k)
                {
                case 1:
                    addDetails(u.pass);
                    break;
                case 2:
                    tenantRequests(u);
                case 3:
                    exit(0);

                default:
                    printf("Invalid choice");
                    login();
                }
            }
            break;
        }
    }

    int choice;

    if (flag == 0)
    {
        printf("\n Username And Password is Incorrect.\n\n");
        printf(" Press any key to continue...");
        getch();
    }
    fclose(fp1);
    system("cls");
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
