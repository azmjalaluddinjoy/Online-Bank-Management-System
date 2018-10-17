#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define account_capacity 15
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
}sign_up[account_capacity];

int main ()
{
    int option=1, choice, i=0, j=0, k=0,sign_in_account_number,sign_in_password;
    float cash_out_balance;
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
            system("cls");
        printf("\n\n\t\t\t****************************************\n\t\t\t<\t       Cash Out     \t\t>\n\t\t\t****************************************\n");
        printf("Enter Your 9 Digit Account Number : ");
        scanf("%d", &sign_in_account_number);
        printf("Enter Your 4 Digit Password  \t  : ");
        scanf("%d", &sign_in_password);
            for (k=0; k<account_capacity; k++)
            {
                if (sign_in_account_number==sign_up[k].account_number && sign_in_password==sign_up[k].password)
                {
                    system("cls");
                    printf("\t  ==================================================\n\t <\t    Account Number : %d   \t\t>\n\t  ==================================================\n", sign_up[k].account_number);
                    printf("\t\t  ________________________________\n\t\t | Enter amount to be cashed out  |\n\t\t |________________________________|\n");
                    scanf("%f", & cash_out_balance);
                    if (cash_out_balance <= sign_up[k].first_installment)
                    {
                        printf("\t  ______________________________________________\n\t | Successfully Cashed Out: %.2f Taka only  \n\t |______________________________________________|\n", cash_out_balance);
                        sign_up[k].first_installment=sign_up[k].first_installment-cash_out_balance;
                        printf("\t  ______________________________________________\n\t | Current Balance: %.2f Taka only  \n\t |______________________________________________|\n", sign_up[k].first_installment);
                        break;
                    }
                    else
                    {
                        printf("\n\t\t\a  ________________________________\n\t\t |\t     Low Balance    \t|\n\t\t |________________________________|\n");
                        break;
                    }
                    break;
                }
                else if (k==account_capacity-1)
                    {
                        system("cls");
                        printf("\n\n\t\t  \a==================================================\n\t\t <\tWrong Account or Password combination !     >\n\t\t  ==================================================\n");
                    }
            }


            break;
        case 2:
        system("cls");
        printf("\n\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t\t\t<\t      SIGN IN   \t\t>\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("Enter Your 9 Digit Account Number : ");
        scanf("%d", &sign_in_account_number);
        printf("Enter Your 4 Digit Password  \t  : ");
        scanf("%d", &sign_in_password);
            for (j=0; j<account_capacity; j++)
            {
                if (sign_in_account_number==sign_up[j].account_number && sign_in_password==sign_up[j].password)
                {
                    system("cls");
                    printf("\t\t  ==================================================\n\t\t <\t    Account Number : %d \t\t    >\n\t\t  ==================================================\n", sign_up[j].account_number);
                    printf("\t _______________________________________________________________________\n\t|1 > Name of Account Holder | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].name);
                    printf("\t _______________________________________________________________________\n\t|2 > Mobile Number          | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].mobile);
                    printf("\t _______________________________________________________________________\n\t|3 > Current Occupation     | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].occupation);
                    printf("\t _______________________________________________________________________\n\t|4 > Monthly Income         | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].monthly_income);
                    printf("\t _______________________________________________________________________\n\t|5 > Gender                 | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].gender);
                    printf("\t _______________________________________________________________________\n\t|6 > Current Balance        | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].first_installment);
                    break;
                }
                else if (j==account_capacity-1)
                {
                    system("cls");
                    printf("\n\n\t\t  \a==================================================\n\t\t <\tWrong Account or Password combination !     >\n\t\t  ==================================================\n");
                }

            }









            break;
        case 3:
            {
                system("cls");
                printf("\t\t  ==========================================================\n\t\t <\t\tAccount Registration Form\t\t    >\n\t\t  ==========================================================\n");
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
                        system("cls");
                        printf("\a\t\t _______________________________________________\n\t\t|        Error in terms & condition !\t\t|\n\t\t|\t\t\tor\t\t\t|");
                        printf("\n\t\t|        password submission error !\t\t|\n\t\t|   Please input at least 4 number only !\t|\n\t\t|_______________________________________________|\n");
                        printf("\t\t _______________________________________________");
                        printf("\n\t\t| For any help, go to Main Menu & Click Help\t|");
                        printf("\n\t\t|_______________________________________________|\n");
                    }
                else
                {
                    system("cls");
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
            system("cls");
            printf("\n\n\t __________________________________________________________________\n\t|\t\t\tDaffodil Bank Ltd\t\t\t   |");
            printf("\n\t|__________________________________________________________________|\n\t| It is a private bank located in Dhanmondi, Dhaka, Bangladesh.    |\n");
            printf("\t| It was established on 24 January 2002.\t\t\t   |\n\t|\t\t\t\t\t\t\t\t   |\n\t| Chairperson: Md. Sabur Khan\t\t\t\t\t   |\n");
            printf("\t| Main Office >\t\t\t\t\t\t\t   |\n\t| Address: 102 Mirpur Rd, Dhaka 1207\t\t\t\t   |\n\t| Phone:9138234-5, 9136694, 9116774\t\t\t\t   |\n\t| Cell: 01713493050, 01713493051\t\t\t\t   |\n");
            printf("\t| Fax:88-02-9131947\t\t\t\t\t\t   |\n\t|__________________________________________________________________|\n");
            break;
        case 5:
            system("cls");
            printf("\n\t** Help for Register Form:\n");
            printf("  ______________________________________________________________________________________________\n");
            printf(" | 1. Full name should be maximum 30 characters only.\t\t\t\t\t\t|\n");
            printf(" | 2. Mobile number digit should not be more than 11 characters.\t\t\t\t|\n");
            printf(" | 3. Submitting your current occupation is better than previous. Occupation’s name should be\t|\n |\tmaximum 20 characters only.\t\t\t\t\t\t\t\t|\n");
            printf(" | 4. Submit your monthly income in Taka (paisa is also be allowed).\t\t\t\t|\n");
            printf(" | 5. You must input your gender correctly from 3 options.\t\t\t\t\t|\n");
            printf(" | 6. First installment must be submitted.\t\t\t\t\t\t\t|\n");
            printf(" | 7. Your password should contain numbers only. Characters will not be allowed. Password\t|\n |\tshould be greater than 1000 & only 4 numbers will be allowed.\t\t\t\t|\n");
            printf(" |______________________________________________________________________________________________|\n");

            break;
        case 6:
            system("cls");
            printf("\t\t  ============================================\n\t\t <<<\t\t    IT Support \t\t    >>>\n\t\t  ============================================\n");
            printf("  ______________________________________________________________________________\n");
            printf(" |\t\t\t\t    Developer\t\t\t\t\t|\n");
            printf(" |______________________________________________________________________________|\n");
            printf(" |\t  Name : | Abu Zahid Md Jalal Uddin Joy\t\t\t\t\t|\n");
            printf(" | Designation : | Student\t\t\t\t\t\t\t|\n");
            printf(" |   Institute : | Daffodil International University\t\t\t\t|\n");
            printf(" |  Department : | B.sc. in Software Engineering\t\t\t\t|\n");
            printf(" |Level & Term : | Level 1 Term 3\t\t\t\t\t\t|\n");
            printf(" |\t Batch : | 19th\t\t\t\t\t\t\t\t|\n");
            printf(" |  Student ID : | 161-35-1611\t\t\t\t\t\t\t|\n");
            printf(" |\tE_mail : | joy.srijon@gmail.com\t\t\t\t\t\t|\n");
            printf(" |_______________|______________________________________________________________|\n");
            printf(" |\t\t\t\t    Teacher \t\t\t\t\t|\n");
            printf(" |______________________________________________________________________________|\n");
            printf(" |\t  Name : | K. M. Imtiaz-Ud-Din\t\t\t\t\t\t|\n");
            printf(" | Designation : | Assistant Professor\t\t\t\t\t\t|\n");
            printf(" |   Institute : | Daffodil International University\t\t\t\t|\n");
            printf(" |  Department : | Department of Software Engineering\t\t\t\t|\n");
            printf(" |\tE_mail : | imtu7986@gmail.com\t\t\t\t\t\t|\n");
            printf(" |_______________|______________________________________________________________|\n");

            break;
        }
        fflush (stdin);
        printf ("\n\nDo you want to continue again ?\n\n");
        printf(" ___________________\t\t\t\t\t\t ___________________\n|   1 >  Main Menu  |\t\t\t\t\t\t|  0 >  Exit\t    |\n|___________________|___________________________________________|___________________|\nPress: ");
        scanf    ("%d", &option);
        system("cls");
        if (option != 1)
            break;

    }

    return 0;
}

