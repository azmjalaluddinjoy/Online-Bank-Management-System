#include<stdio.h>
#include<string.h>
struct sign_up_info
{
    char name[30];
    char mobile[12];
    char occupation[20];
    float monthly_income;
    char gender[6];
    float first_installment;
    int account_number;
    int password;
}sign_up[10];

int main ()
{
    int option=1, choice, i=0, j=0,sign_in_account_number,sign_in_password;
    while (option)
    {

        printf("\t\t\t _____________________________________\n\t\t\t|   Welcome to the Daffodil Bank Ltd  |\n\t\t\t|_____________________________________|\n\n\t\t\t     ______________________________\n\t\t\t    |         Home Screen          |\n\t\t\t    |______________________________|\n\n");
        printf(" ___________________\t\t ______________________\t\t ___________________\n|   1 >  Cash Out   |\t\t|  2 >    Sign In      |\t|  3 >  Sign Up     |\n|___________________|\t\t|______________________|\t|___________________|\n");
        printf(" ___________________\t\t ______________________\t\t ___________________\n|   4 >  About Us   |\t\t|  5 >    Help         |\t|  6 >  IT Support  |\n|___________________|\t\t|______________________|\t|___________________|\n");
        printf ("Enter your choice : ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:

            break;
        case 2:

        printf("\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t\t\t<\t      SIGN IN   \t\t>\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("Enter Your 9 Digit Account Number : ");
        scanf("%d", &sign_in_account_number);
        printf("Enter Your 4 Digit Password  \t  : ");
        scanf("%d", &sign_in_password);
        for (j=0; j<15; j++)
        {
            if (sign_in_account_number==sign_up[j].account_number && sign_in_password==sign_up[j].password)
            {
                printf("\t\t  ==================================================\n\t\t <\t    Account Number : %d \t\t    >\n\t\t  ==================================================\n", sign_up[j].account_number);
                printf("\t _______________________________________________________________________\n\t|1 > Name of Account Holder | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].name);
                printf("\t _______________________________________________________________________\n\t|2 > Mobile Number          | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].mobile);
                printf("\t _______________________________________________________________________\n\t|3 > Current Occupation     | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].occupation);
                printf("\t _______________________________________________________________________\n\t|4 > Monthly Income         | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].monthly_income);
                printf("\t _______________________________________________________________________\n\t|5 > Gender                 | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].gender);
                printf("\t _______________________________________________________________________\n\t|6 > Current Balance        | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].first_installment);

            }
        }









            break;
        case 3:
            {

                printf("\nWelcome to our online portal !\n");
                printf("Please input your valid information\n\n");
                printf("Note: After submitting all the valid information, we will give you a valid Bank Account Number. Keep this account number with your given password for further use ! You have to maintain all our term & condition.\n\n");
                printf("Full Name\t\t   : ");
                scanf(" %[^\n]",sign_up[i].name);
                printf("11 Digit Mobile Number\t   : ");
                scanf(" %[^\n]",sign_up[i].mobile);
                printf("Current Occupation\t   : ");
                scanf(" %[^\n]",sign_up[i].occupation);
                printf("Monthly Income (In Taka)   : ");
                scanf(" %f",&sign_up[i].monthly_income);
                printf("Gender (Male/Female/Others): ");
                scanf(" %[^\n]",sign_up[i].gender);
                printf("First installment (In Taka): ");
                scanf("%f",&sign_up[i].first_installment);
                printf("Create a 4 Digit Password  : ");
                scanf("%d", &sign_up[i].password);
                if (sign_up[i].password>=9999 || sign_up[i].password<=1000)
                    {
                        printf("\t\t _______________________________________\n\t\t|     password submission error !\t|\n\t\t| Please input at least 4 number only ! |\n\t\t|_______________________________________|\n");

                    }
                else
                {
                    sign_up[i].account_number=161351611+i;
                    printf("\n\nData saved Successfully ! \n");
                    printf("\t\t ______________________________________________\n\t\t|\t\t Congratulations !      \t|\n\t\t|______________________________________________|\n");
                    printf("\tWe reviewed your information & created an account for you !\n\n");
                    printf("\t\t================================================\n\t\t<\t    Account Number : %d \t\t>\n\t\t================================================\n", sign_up[i].account_number);
                }



            i++;
            }




            break;
        case 4:
            return;
        case 5:
            break;
        case 6:
            break;
        }
        fflush (stdin);
        printf ("\nDo you want to continue again ?\n");
        printf(" ___________________\t\t\t\t\t\t ___________________\n|   1 >  Main Menu  |\t\t\t\t\t\t|  2 >  Exit\t    |\n|___________________|___________________________________________|___________________|\nPress: ");
        scanf    ("%d", &option);
        if (option != 1)
            break;

    }

    return 0;
}

