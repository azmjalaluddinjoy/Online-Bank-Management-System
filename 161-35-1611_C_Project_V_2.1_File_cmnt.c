#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define account_capacity 15//globally variable declaration
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
}sign_up[account_capacity];//sign up array

int main ()
{/*Here's f,i,j,k,l,m,n,p all are used as counter variable*/
    int option=1, choice, sign_in_option=1, sign_in_choice,f=0, i, j=0, k=0, l=0, m=0,n=0,p=0, sign_in_account_number,sign_in_password, signin_money_transfer_account, signin_change_pass_request_previous_password, signin_new_password_step1, signin_new_password_step2, asking_for_password_recover;
    float cash_out_balance, signin_money_transfer_taka;
    char fullname_forgotten_password[30], mobile_forgotten_password[12], occupation_forgotten_password[20];
    FILE*inputfile;//Loading information from File
    inputfile = fopen("accounts_information.txt", "r");
        if (inputfile!=NULL)
            {
                fprintf(stderr, "\nData Loaded Successfully from file \"accounts_information.txt\"\nPlease continue...\n");
            }//Saved data willbe loaded from file
            fscanf(inputfile, "%d\n", &f);
            for (p=0; p<account_capacity; p++)
                {
                    fread(&sign_up[p], sizeof(struct sign_up_info), 1, inputfile);
                }//loading data by index
                i=f;//value of f transfers to i; for sign up purpose
    while (option)
    {
        printf("\t\t\t _____________________________________\n\t\t\t|   Welcome to the Daffodil Bank Ltd  |\n\t\t\t|_____________________________________|\n\n\t\t\t     ______________________________\n\t\t\t    |         Home Screen          |\n\t\t\t    |______________________________|\n\n");
        printf(" ___________________\t\t ______________________\t\t ___________________\n|   1 >  Cash Out   |\t\t|  2 >    Sign In      |\t|  3 >  Sign Up     |\n|___________________|\t\t|______________________|\t|___________________|\n");
        printf(" ___________________\t\t ______________________\t\t ___________________\n|   4 >  About Us   |\t\t|  5 >    Help         |\t|  6 >  IT Support  |\n|___________________|\t\t|______________________|\t|___________________|\n");
        printf("\t\t\t\t ______________________\n\t\t\t\t|  0 >    Exit Option  |\n\t\t\t\t|______________________|\n");
        printf ("Enter your choice : ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1://input 1 for cash out request
            system("cls");//system-cls using for cleaning the screen
        printf("\n\n\t\t\t****************************************\n\t\t\t<\t       Cash Out     \t\t>\n\t\t\t****************************************\n");
        printf("Enter Your 9 Digit Account Number : ");
         return main();
        scanf("%d", &sign_in_account_number);
        printf("Enter Your 4 Digit Password  \t  : ");
        scanf("%d", &sign_in_password);
            for (k=0; k<account_capacity; k++)
            {
                if (sign_in_account_number==sign_up[k].account_number && sign_in_password==sign_up[k].password)
                {
                    system("cls");
                    printf("\t  ==================================================\n\t <\t    Account Number : %d\t\t   >\n\t  ==================================================\n", sign_up[k].account_number);
                    printf(" ____________________________________________________________________\n| >>>  Account Holder \t|   %s\n|_______________________|____________________________________________|\n", sign_up[k].name);
                    printf("\t\t  ________________________________\n\t\t | Enter amount to be cashed out  |\n\t\t |________________________________|\n");
                    scanf("%f", & cash_out_balance);

//cash out balance should be smaller than account total balance
                    if (cash_out_balance <= sign_up[k].first_installment)
                    {
                        system("cls");
                        printf("\t  ______________________________________________\n\t | Successfully Cashed Out: %.2f Taka only  \n\t |______________________________________________|\n", cash_out_balance);
                        sign_up[k].first_installment=sign_up[k].first_installment-cash_out_balance;//cash out balance is deducting from main account
                        printf("\t  ______________________________________________\n\t | Current Balance: %.2f Taka only  \n\t |______________________________________________|\n", sign_up[k].first_installment);
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("\n\t\t\a  ________________________________\n\t\t |\t     Low Balance\t  |\n\t\t |________________________________|\n");
                        printf("\t  ______________________________________________\n\t | Your Current Balance is: %.2f Taka only  \n\t |______________________________________________|\n", sign_up[k].first_installment);
                        break;
                    }
                    break;
                }
                else if (k==account_capacity-1)
//checking all the accounts and if the account and password is absent in the database, error will be shown
                    {
                        system("cls");
                        printf("\n\n\t\t  \a==================================================\n\t\t <\tWrong Account or Password combination !     >\n\t\t  ==================================================\n");
                    }
            }
            break;
        case 2://case 2 is using for the sign in menu
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
                                sign_in_option=1;
                            while (sign_in_option)
                            {
                                system("cls");//sign in menu has 3 option for handling
                                printf("\n\t\t\t     _________________________________\n\t\t\t    |\t\t  Sign In\t      |\n\t\t\t    |_________________________________|\n\n");
                                printf(" ________________________\t ___________________________\t ________________________\n| 1 >  Money Transfer    |\t| 2 >  Personal Information |\t| 3 >  Change Password   |\n|________________________|\t|___________________________|\t|________________________|\n");
                                printf("\t\t\t\t    ______________________\n\t\t\t\t   |  0 >    Exit Option  |\n\t\t\t\t   |______________________|\n");
                                printf ("\nEnter your choice : ");
                                scanf    ("%d", &sign_in_choice);
                                switch (sign_in_choice)
                                    {
                                    case 1 ://case 1 is using for for money transferring
                                        system("cls");
                                        printf("\n\t\t\t     _________________________________\n\t\t\t    |\t\tMoney Transfer\t      |\n\t\t\t    |_________________________________|\n\n");
                                        printf("Please Input an Account Number: ");
                                        scanf("%d", & signin_money_transfer_account);
                                        printf("\t\t  Balance Taka: ");
                                        scanf("%f", & signin_money_transfer_taka);
                                        for (l=0; l<account_capacity; l++)
                                        {
                                            if (signin_money_transfer_account==sign_up[l].account_number)
                                            {//money transfer will be allowed only for registered account
                                                if (signin_money_transfer_taka <= sign_up[l].first_installment)
                                                {
                                                    sign_up[j].first_installment=sign_up[j].first_installment-signin_money_transfer_taka;
                                                    sign_up[l].first_installment=sign_up[l].first_installment+signin_money_transfer_taka;
                                                    system("cls");
                                                    printf("\nSuccussfully money transferred to the\n");
                                                    printf("\t\t  ==================================================\n\t\t <\t      Account : %d \t\t    >\n\t\t  ==================================================\n", signin_money_transfer_account);
                                                    printf("\t\t    ______________________________________________\n\t\t   | Transferred Ammount: %.2f Taka only  \n\t\t   |______________________________________________|\n", signin_money_transfer_taka);
                                                    printf("\t\t    ______________________________________________\n\t\t   | Current Balance: %.2f Taka only  \n\t\t   |______________________________________________|\n", sign_up[j].first_installment);
                                                    break;
                                                }
                                                else
                                                {
                                                    system("cls");//low balance will be shown when the necessity of Taka is lower than the account balance
                                                    printf("\n\t\t\a  ________________________________\n\t\t |\t     Low Balance\t  |\n\t\t |________________________________|\n");
                                                    break;
                                                }
                                            }
                                            else if(l==account_capacity-1)
                                            {
                                                system("cls");
                                                printf("\a\n\t\t\t     _________________________________\n\t\t\t    | Money Transfer can't be possible|\n\t\t\t    |_________________________________|\n\n");
                                            }
                                        }
                                        break;
                                    case 2 ://case 2 is working for showing account holder details
                                        system("cls");
                                        printf("\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\t\t\t<\t  Personal Information\t\t>\n\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                                        printf("\t\t  ==================================================\n\t\t <\t    Account Number : %d \t\t    >\n\t\t  ==================================================\n", sign_up[j].account_number);
                                        printf("\t _______________________________________________________________________\n\t|1 > Name of Account Holder | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].name);
                                        printf("\t _______________________________________________________________________\n\t|2 > Mobile Number          | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].mobile);
                                        printf("\t _______________________________________________________________________\n\t|3 > Current Occupation     | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].occupation);
                                        printf("\t _______________________________________________________________________\n\t|4 > Monthly Income         | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].monthly_income);
                                        printf("\t _______________________________________________________________________\n\t|5 > Gender                 | %s\n\t|___________________________|___________________________________________|\n", sign_up[j].gender);
                                        printf("\t _______________________________________________________________________\n\t|6 > Current Balance        | %.2f Taka Only\n\t|___________________________|___________________________________________|\n", sign_up[j].first_installment);
                                        break;
                                    case 3 ://it's using for changing password
                                        system("cls");
                                        printf("\nPlease Input\n");
                                        printf("\n\t\t    ______________________________________________\n\t\t   |\t    Previous Password: ");
                                        scanf("%d", & signin_change_pass_request_previous_password);//previous password verification request
                                        printf("\n\t\t    ______________________________________________\n\t\t   | \t\tNew Password : ");
                                        scanf("%d", & signin_new_password_step1);
                                        printf("\n\t\t    ______________________________________________\n\t\t   |\t   New Password Again: ");
                                        scanf("%d", & signin_new_password_step2);
                                        if (signin_change_pass_request_previous_password==sign_up[j].password && signin_new_password_step1==signin_new_password_step2 & signin_new_password_step1<=9999 && signin_new_password_step2>=1000)
                                        {
                                            system("cls");
                                            printf("\n\t\t\t     _________________________________\n\t\t\t    | Password Changed Successfully ! |\n\t\t\t    |_________________________________|\n\n");
                                            sign_up[j].password=signin_new_password_step2;
                                        }
                                        else
                                        {//mismatched password or activity will be shown as error
                                            system("cls");
                                            printf("\n\t\t\t\a     _________________________________\n\t\t\t    |    Error in Change request  !   |\n\t\t\t    |_________________________________|\n\n");
                                        }
                                        break;
                                        }
                                fflush (stdin);
                                printf ("\n\nDo you want to go in the SIGN-IN-MENU again ?\n\n");//asking for going to sign in menu even or not !
                                printf("   ___________________\t\t\t\t\t\t   ___________________\n  |  1 > SignIn Menu  |___________________________________________|  0 >  Exit\t      |\n  |___________________|\t\t\t\t\t\t  |___________________|\nPress: ");
                                scanf ("%d", &sign_in_option);
                                if (sign_in_option != 1)//input 1 for return in the sign in menu
                                    break;
                            }
                            break;
                        }
                        else if (j==account_capacity-1)
                            {//if wrong password or account number is submitted, forgotten password request will be shown
                                system("cls");
                                printf("\n\n\t\t  \a==================================================\n\t\t <\tWrong Account or Password combination !     >\n\t\t  ==================================================\n");
                                printf("Forgot password ?\nDo You want to recover ?");
                                printf("\n   ___________________\t\t\t\t\t\t   ____________________\n  |1 > Ignore         |___________________________________________|0 > Recover Password|\n  |___________________|\t\t\t\t\t\t  |____________________|\n");
                                printf("\nEnter Your Choice: ");
                                scanf("%d", & asking_for_password_recover);
                                if (asking_for_password_recover==0)
                                {
                                    system("cls");
                                    printf("\n\t\t\t   _________________________________\n\t\t\t  |\t   Forgotten Password ?\t    |\n\t\t\t  |_________________________________|\n\n");
                                    printf("Please Answer correct to the question below:\n\n");
                                    printf("Full Name\t\t   : ");//upper case letter and lower case letter is mandatory for checking
                                    scanf(" %[^\n]",fullname_forgotten_password);
                                    printf("11 Digit Mobile Number\t   : ");
                                    scanf(" %[^\n]", mobile_forgotten_password);
                                    for (m=0; m<account_capacity; m++)
                                        {
                                            if (strcmp(fullname_forgotten_password, sign_up[m].name)==0)
                                            {
                                                system("cls");
                                                printf("\n\t\t\t   _________________________________\n\t\t\t  | Your Password |\t%d\t    |\n\t\t\t  |_______________|_________________|\n\n",sign_up[m].password);
                                                break;
                                            }
                                            else if (m==account_capacity-1)
                                            {
                                                printf("\n\t\t\t\a   _________________________________\n\t\t\t  |Your Given Information Is wrong !|\n\t\t\t  |_________________________________|\n\n");
                                                break;
                                            }
                                        }
                                        break;
                                }

                            }//forgot password recovery ending process
                    }
            break;
        case 3://case 3 is using for registering form
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
                    {//checking password for 4 digit only
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
                    sign_up[i].account_number=161351611+i;//account registering will be started from this ID
                    printf("\n\nData saved Successfully ! \n");
                    printf("\t\t ______________________________________________\n\t\t|\t\t Congratulations !      \t|\n\t\t|______________________________________________|\n");
                    printf("\tWe reviewed your information & created an account for you !\n\n");
                    printf("\t\t================================================\n\t\t<\t    Account Number : %d \t\t>\n\t\t================================================\n", sign_up[i].account_number);
                }
            i++;//counter variable will be increased after using sign up function once and
            }
            break;
        case 4://case 4 is using for About Us function. it's showing details about this bank
            system("cls");
            printf("\n\n\t __________________________________________________________________\n\t|\t\t\tDaffodil Bank Ltd\t\t\t   |");
            printf("\n\t|__________________________________________________________________|\n\t| It is a private bank located in Dhanmondi, Dhaka, Bangladesh.    |\n");
            printf("\t| It was established on 24 January 2002.\t\t\t   |\n\t|\t\t\t\t\t\t\t\t   |\n\t| Chairperson: Md. Sabur Khan\t\t\t\t\t   |\n");
            printf("\t| Main Office >\t\t\t\t\t\t\t   |\n\t| Address: 102 Mirpur Rd, Dhaka 1207\t\t\t\t   |\n\t| Phone:9138234-5, 9136694, 9116774\t\t\t\t   |\n\t| Cell: 01713493050, 01713493051\t\t\t\t   |\n");
            printf("\t| Fax:88-02-9131947\t\t\t\t\t\t   |\n\t|__________________________________________________________________|\n");
            break;
        case 5://case 5 is for help line
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
        case 6://showing IT Support of this program
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
            default :
            printf("Invalid Input\n");
        }
        fflush (stdin);
        printf ("\n\nDo you want to continue again ?\n\n");//Ask user what they'd like to do
        printf(" ___________________\t\t\t\t\t\t ___________________\n|   1 >  Main Menu  |\t\t\t\t\t\t|  0 >  Exit\t    |\n|___________________|___________________________________________|___________________|\nPress: ");
        scanf    ("%d", &option);
        system("cls");
        if (option != 1)
        {
            f=i;
            FILE*outputfile;
//creating file for saving this data for further use
            outputfile = fopen("accounts_information.txt", "w");
                if (outputfile==NULL)
                    {
//stderr is using for showing standard error
                        fprintf(stderr, "\nerror creating file accounts_information.txt\n\n");
                        exit(1);//(usually) indicates unsuccessful termination.
                    }
//sending data to the created file
                    fprintf(outputfile, "%d\n", f);
                    for (n=0; n<account_capacity; n++)
                    {
                    fwrite(&sign_up[n], sizeof(struct sign_up_info), 1, outputfile);
                    }
                    break;
        }
    }
    return 0;
}

