#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
//#include <windows.h>
#include <math.h>

#define PARKING_FEE_PER_DAY 1
#define MAX_SERVICES 10
#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 50
#define MAX_FEEDBACK_LENGTH 200
#define MAX_COMPLAINT_LENGTH 200
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MENU_SIZE 8
#define GST_RATE 0.18
//----------------------------------------------------------------------------------------------------------//
//Structure to represent personal information 
typedef struct 
{
    int hotelid;
    int rno;
    char name[40];
    char resadd[80];
    char peradd[80];
    char phone[20];
    char telpho[20];
    char DOB[20];
    int PINCODE;
    char state[20];
    char country[20];
    char mail[30];
    char whatno[20];
    char bnkacntno[30];
    char IFSC[20];
    char Aadhar[20];
    char passport[20];
    char voterid[20];
    struct info* next;
}info;
//----------------------------------------------------------------------------------------------------------//
// Structure to represent a hotel room
typedef struct {
    int room_number;
    char guest_name[50];
    int is_booked;
} Room;
//----------------------------------------------------------------------------------------------------------//
// Define a structure for user credentials
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} UserCredentials;
//----------------------------------------------------------------------------------------------------------//
// Structure to represent menu items
typedef struct
{
    char name[50];
    float price;
} MenuItem;
//----------------------------------------------------------------------------------------------------------//
//Structure to represent check in and Check out of customer
typedef struct {
    char checkin_date[15];
    char checkout_date[15];
} Customer;
//----------------------------------------------------------------------------------------------------------//
//Structure to Store Feedback
struct Guest {
    char name[MAX_NAME_LENGTH];
    int roomNumber;
    char feedback[MAX_FEEDBACK_LENGTH];
    char complaint[MAX_COMPLAINT_LENGTH];
};
//----------------------------------------------------------------------------------------------------------//
// Structure to represent a service
typedef struct {
    char name[50];
    float price;
} Service;
//----------------------------------------------------------------------------------------------------------//
// Structure for payment gateway
typedef struct { 
    float bill;
    int payment_status;

}booking;
//----------------------------------------------------------------------------------------------------------//
//Structure to represent Parking systme
struct Car {
    int id;

    int checked_in; // 1 if checked in, 0 if checked out
    int days_parked;
};
//----------------------------------------------------------------------------------------------------------//
    // Define the number of rooms in the hotel
    const int room_count = 10;
    struct Guest guests[MAX_ROOMS];
    int numGuests = 0;
    // Global variables
    Service services[MAX_SERVICES];
    int numServices = 0;
    int days[15][31];
//----------------------------------------------------------------------------------------------------------//
// Function to clear the screen
void clearScreen()
{
    system("cls");
}
//----------------------------------------------------------------------------------------------------------//
void Rinit(info **head)
{
    *head=NULL;   //Initialising the structure
}
//----------------------------------------------------------------------------------------------------------//
//Function to create a list of customers
info *Rcreate_list()
{                                           //To create a linked list of customers
    info *head,*p;
    int n;
    printf("NUMBER OF CUSTOMERS:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            head=(info*)malloc(sizeof(info));
            p=head;
        }
        else
        {
            p->next=(info*)malloc(sizeof(info));
            p=p->next;
        }
        p->hotelid=i;
        //----------------------------------------------------------------------------------------------------------//
        //Asking user for Input 
        printf("-----------------------------------------------CUSTOMER %d--------------------------------------------------------------\n",i);
        printf("NAME:");
        scanf("\n%[^\n]",p->name);
        printf("\nRESIDENTIAL ADDRESS:");
        scanf("\n%[^\n]",p->resadd);
        printf("\nPERMANENT ADDRESS:");
        scanf("\n%[^\n]",p->peradd);
        printf("\nPHONE:");
        scanf("%s",p->phone);
        printf("\nWHATSAPP NO:");
        scanf("%s",p->whatno);
        printf("\nTELEPHONE NO:");
        scanf("%s",p->telpho);
        printf("\nMAIL:");
        scanf("%s",p->mail);
        printf("\nDATE OF BIRTH IN DD-MM-YYYY:");
        scanf("%s",p->DOB);
        printf("\nBANK ACCOUNT NO:");
        scanf("%s",p->bnkacntno);
        printf("\nIFSC:");
        scanf("%s",p->IFSC);
        printf("\nAADHAR CARD NO:");
        scanf("%s",p->Aadhar);
        printf("\nVOTER ID NO:");
        scanf("%s",p->voterid);
        printf("\nPASSPORT:");
        scanf("%s",p->passport);
        printf("\nPINCODE:");
        scanf("%d",&p->PINCODE);
        printf("\nSTATE:");
        scanf("\n%[^\n]",p->state);
        printf("\nCOUNTRY:");
        scanf("\n%[^\n]",p->country);
    }
    p->next=NULL;
    return head;
}
//----------------------------------------------------------------------------------------------------------//
//Function to insert information about the new customer
void Rinsert(info **head)
{
    info *new,*p,*q;
    new=(info*)malloc(sizeof(info));                                //Providing the details of new customer
    printf("------------------------------------------------------NEW CUSTOMER DETAILS---------------------------------------------------\n");
    printf("NAME:");
    scanf("\n%[^\n]",new->name);
    printf("\nRESIDENTIAL ADDRESS:");
    scanf("\n%[^\n]",new->resadd);
    printf("\nPERMANENT ADDRESS:");
    scanf("\n%[^\n]",new->peradd);
    printf("\nPHONE:");
    scanf("%s",new->phone);
    printf("\nWHATSAPP NO:");
    scanf("%s",new->whatno);
    printf("\nTELEPHONE NO:");
    scanf("%s",new->telpho);
    printf("\nMAIL:");
    scanf("%s",new->mail);
    printf("\nDATE OF BIRTH IN DD-MM-YYYY FORMAT:");
    scanf("%s",new->DOB);
    printf("\nBANK ACCOUNT NO:");
    scanf("%s",new->bnkacntno);
    printf("\nIFSC:");
    scanf("%s",new->IFSC);
    printf("\nAADHAR CARD NO:");
    scanf("%s",new->Aadhar);
    printf("\nVOTER ID NO:");
    scanf("%s",new->voterid);
    printf("\nPASSPORT:");
    scanf("%s",new->passport);
    printf("\nPINCODE:");
    scanf("%d",&new->PINCODE);
    printf("\nSTATE:");
    scanf("\n%[^\n]",new->state);
    printf("\nCOUNTRY:");
    scanf("\n%[^\n]",new->country);
    p=*head;
    while(p!=NULL)
    {                                   //Inserting element at the end
        q=p;
        p=p->next;                          //Traversing the list 
    }
    new->hotelid=q->hotelid+1;
    q->next=new;
    new->next=NULL;
}
//----------------------------------------------------------------------------------------------------------//
//Function to delete the customer record
void Rdelete(info **head)
{
    info *p,*q,*r;
    int hid;
    printf("\nDelete for hotel id:");
    scanf("%d",&hid);
    p=*head;
    if(p->hotelid==hid)
    {
        r=p->next;
        *head=p->next;
        free(p);
    }
    else
    {
        while((p!=NULL)&&(p->hotelid!=hid))
        {
            q=p;
            p=p->next;
        }
        if(p==NULL)
        {
            printf("\nNo match!!Deletion Failed,Please Try Again");
        }
        else if(p->hotelid==hid)
        {
            q->next=p->next;
            r=p->next;
            free(p);
        }
    }
    while(r!=NULL)
    {
        r->hotelid=r->hotelid-1;
        r=r->next;
    }
}
//----------------------------------------------------------------------------------------------------------//
//Function to edit the customer record
void Redit(info **head)
{
    info *p;
    int hid,k=0;
    p=*head;
    printf("HOTEL ID:\n");
    scanf("%d",&hid);
    while((p->hotelid)!=hid&&(p!=NULL))
    {
        p=p->next;
    }
    if((p->hotelid)==hid)
    {
        do
        {
            printf("Input your choice to edit:\n");
            printf("1)NAME 2)RESIDENTIAL ADDRESS 3)PERMANENT ADDRESS 4)PHONE NO 5)WHATSAPP NO\n");
            printf("6)TELEPHONE NO 7)MAIL 8)DATE OF BIRTH 9)BANK ACCOUNT NO 10)IFSC 11)AADHAR CARD NO\n");
            printf("12)VOTER ID NO 13)PASSPORT 14)PINCODE 15)STATE 16)COUNTRY 17)EXIT\n");
            int c;
            scanf("%d",&c);
            switch(c)
            {
                case 1:printf("NAME:\n");
                scanf("\n%[^\n]",p->name);
                break;
                case 2:printf("RESIDENTIAL ADDRESS:\n");
                scanf("\n%[^\n]",p->resadd);
                break;
                case 3:printf("PERMANENT ADDRESS:\n");
                scanf("\n%[^\n]",p->peradd);
                break;
                case 4:printf("PHONE NO:\n");
                scanf("%s",p->phone);
                break;
                case 5:printf("WHATSAPP NO:\n");
                scanf("%s",p->whatno);
                break;
                case 6:printf("TELEPHONE NO:\n");
                scanf("%s",p->telpho);
                break;
                case 7:printf("MAIL:\n");
                scanf("%s",p->mail);
                break;
                case 8:printf("DATE OF BIRTH:\n");
                scanf("%s",p->DOB);
                break;
                case 9:printf("BANK ACCOUNT NO:\n");
                scanf("%s",p->bnkacntno);
                break;
                case 10:printf("IFSC:\n");
                scanf("%s",p->IFSC);
                break;
                case 11:printf("AADHAR CARD NO:\n");
                scanf("%s",p->Aadhar);
                break;
                case 12:printf("VOTER ID NO:\n");
                scanf("%s",p->voterid);
                break;
                case 13:printf("PASSPORT:\n");
                scanf("%s",p->passport);
                break;
                case 14:printf("PINCODE:");
                scanf("%d",&p->PINCODE);
                break;
                case 15:printf("STATE:\n");
                scanf("\n%[^\n]",p->state);
                break;
                case 16:printf("COUNTRY:\n");
                scanf("\n%[^\n]",p->country);
                break;
                case 17:printf("EXITING......\n");
                k=1;
                break;
                default:printf("WRONG INPUT!!Please Input a Valid choice:\n");
                break;
            }
        }while(k!=1);
        printf("************************************************INFROMATION UPDATED****************************************************\n");
    }
    else if(p==NULL)
    printf("No Such Record exists!!");
}
//----------------------------------------------------------------------------------------------------------//
//Function to display the details of customer
void Rdisplay(info *head)
{
    int count=1;
    while(head!=NULL)
    {
        printf("-------------------------------------------------CUSTOMER %d--------------------------------------------------------------- \n",count++);
        printf("============================================================================================================================\n");
        printf("============================================================================================================================\n");
        printf("HOTEL ID:%d\t\t\t\t\t\t\t\t\t\t\t\tRoom no:%d\n",head->hotelid,head->rno);
        printf("NAME:%s\t\t\t\t\t\t\t\t\t\tDATE OF BIRTH:%s\n",head->name,head->DOB);
        printf("RESIDENTIAL ADDRESS:%s\n",head->resadd);
        printf("PERMANENT ADDRESS:%s\n",head->peradd);
        printf("PINCODE:%d\n",head->PINCODE);
        printf("PHONE:%s\t\t\t\t\t\t\t\t\t\tTELEPHONE NO:%s\n",head->phone,head->telpho);
        printf("WHATSAPP NO:%s\t\t\t\t\t\t\t\t\t\tMAIL:%s\n",head->whatno,head->mail);
        printf("STATE:%s\t\t\t\t\t\t\t\t\t\tCOUNTRY:%s\n",head->state,head->country);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("AADHAR NO:%s\t\t\t\t\t\t\t\t\t\tPASSPORT NO:%s\n",head->Aadhar,head->passport);
        printf("VOTER ID:%s\n",head->voterid);
        printf("----------------------------------------------------------------------------------------------------------------------\n");
        printf("BANK ACCOUNT NO:%s\t\t\t\t\t\t\t\t\t\tIFSC CODE:%s\n",head->bnkacntno,head->IFSC);
        head=head->next;
    }
}
//----------------------------------------------------------------------------------------------------------//
// Function to book a room
void DbookRoom(Room *rooms, int room_count, int room_number, const char *guest_name) {
    // Check if the room number is valid
    if (room_number < 1 || room_number > room_count) {
        printf("Invalid room number\n");
        return;
    }

    // Check if the room is already booked
    if (rooms[room_number - 1].is_booked) {
        printf("Room %d is already booked\n", room_number);
        return;
    }

    // Book the room
    rooms[room_number - 1].room_number = room_number;
    strcpy(rooms[room_number - 1].guest_name, guest_name);
    rooms[room_number - 1].is_booked = 1;

    printf("Room %d booked successfully for %s\n", room_number, guest_name);
}
//----------------------------------------------------------------------------------------------------------//
// Function to display the status of all rooms
void DdisplayRooms(Room *rooms, int room_count) {
    printf("\n");
    printf("-----------Room Availability-----------");
    printf("\n");
    printf("Room\tGuest Name\tBooked\n");
    for (int i = 0; i < room_count; i++) {
        printf("%d\t%s\t\t%s\n", rooms[i].room_number, 
               rooms[i].guest_name, rooms[i].is_booked ? "Yes" : "No");
    }
}
//------------------------------------------------------------------------------------------------------------//
// Function to authenticate user credentials
int DauthenticateUser(UserCredentials *users, int num_users, char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // Return -1 if authentication fails
}
//----------------------------------------------------------------------------------------------------------//
//Function to login in the system
void Dlogin()
{
	 UserCredentials users[] = {
        {"admin", "admin123"},
        {"user1", "password1"},
        {"user2", "password2"}
        // Add more users as needed
    };
    int num_users = sizeof(users) / sizeof(users[0]);

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("=== Hotel Management Login ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    int auth_result = DauthenticateUser(users, num_users, username, password);
    if (auth_result != -1) {
        printf("Welcome, %s!\n", username);
        // Proceed to hotel management system functionalities
    } else {
        printf("Invalid username or password. Please try again.\n");
        exit(0);
    }
}
//-----------------------------------------------------------------------------------------------------------//
//Function to initialize elements
void Dinit(){
    int i=0;
	
	time_t t;
	time(&t);
    printf("\033[0;33m");
    printf(" -------------------------------------------------------------------------\n");
    printf("|                                                                                  |\n");
    printf("|                                                                                  |\n");
    printf("|  OOOOOO   OOOOO   OOOOOO  OOOOOO  OOOOOO  OOOOOO   O      O   OOOOOO     OOOOO   |\n");
    printf("|  O        O    O  O       O         O       O      O O    O   O         O        |\n");
    printf("|  O  OOO   OOOOO   OOOOO   OOOOO     O       O      O  O   O   O  OOO     OOOO    |\n");
    printf("|  O    O   O  O    O       O         O       O      O   O  O   O    O         O   |\n");
    printf("|  OOOOOO   O   O   OOOOOO  OOOOOO    O     OOOOOO   O    O O   OOOOOO    OOOOO    |\n");
    printf("|                                                                                  |\n");
    printf(" -------------------------------------------------------------------------\n");

    // Reset color to default
    printf("\033[0m");
 	printf("\t\t*\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*        WELCOME TO HOTEL PROJECT TWELVE        *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*        Brought To You By C programming        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     CONTACT US:18-87454575552,035455852       *\n");
	printf("\t\t*\n\n\n");
		for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(int i=0;i<80;i++)
		printf("-");
	printf(" \n Press any key to continue:");
}

//------------------------------------------------------------------------------------------------------------//
//Function to display preface
void Dpreface(){
    int i=0;
	
	time_t t;
	time(&t);
for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(int i=0;i<80;i++)
		printf("-");
		printf("\n");
	
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf(" \n Enter 1 -> New Hotel Record");
		printf("\n------------------------");
		printf(" \n Enter 2 -> View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 -> Delete Customer Record");
		printf("\n-----------------------------------");
        printf(" \n Enter 4 -> Display Room availablity");
		printf("\n-----------------------------------");
        printf(" \n Enter 5 -> Book a Room");
		printf("\n---------------------------------------");
		printf(" \n Enter 6 -> Edit Record");
		printf("\n-----------------------");
		printf(" \n Enter 7 -> Restaurant");
		printf("\n-----------------------");
        printf(" \n Enter 8 -> Services");
		printf("\n---------------------");
        printf(" \n Enter 9 -> check out");
		printf("\n----------------------");
        printf(" \n Enter 10 -> Feedback and Complaints");
		printf("\n----------------------------------");
        printf(" \n Enter 11 -> Parking System");
		printf("\n-----------------------------");
        printf(" \n Enter 12 -> Attendance Register(workers)");
		printf("\n-------------------------------------------");
        printf(" \n Enter 13 -> Exit");
		printf("\n----------------------");
		printf("\n");
		for(int i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(int i=0;i<80;i++)
		printf("-");
}

//---------------------------------------------------------------------------------------------------------//
void Dexecute(Room *rooms,info **head)
{
    DdisplayRooms(rooms, room_count);
    info *p;
    p=*head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    int ROOM;
    char NAME[10];
    printf("Enter room no. to be booked:");
    scanf("%d",&ROOM);
    p->rno=ROOM;
    printf("Enter name:");
    scanf("%s",NAME);
    
    DbookRoom(rooms, room_count, ROOM ,NAME);
}
//---------------------------------------------------------------------------------------------------------//
//-----------------------------code for payment gateway--------------------------------------------//
//Function for payment gateway
int payment(booking *bill,info *p)
{
    static float prev_amount = 0;
    
    bill->bill = bill->bill + prev_amount;
     // to print bill of the customer 
    printf ("Bill for customer: %s\n", p->name);

     // to check payment is completed or not
     if (bill->payment_status == 1)
     {
        printf ("payment completed\n");
        
     }

     else 
     {
        
        // to clear  bill amount 
        float amount;
        printf ("AMOUNT TO BE PAID = $%.2f  \n",bill->bill );
        printf ("Enter the amount= ");
        scanf ("%f",&amount);

        if (amount < 0) {
            printf ("Invalid amount.\n");
        }

        // if customer wants to pay advance 
        else if (amount<bill->bill)
        {
            
            printf ("the payment was succesfull \n");
    
            bill->bill =  bill->bill - amount;
            printf ("Remaining amount = %.2f \n",bill->bill);
            bill->payment_status = 0;
            prev_amount = bill->bill;
        }

        // if custmer gets some refund 
        else if (bill->bill<0)
        {
            printf ("REFUND AMOUNT= %.2f \n",-bill->bill);
            bill->payment_status = 1;
            bill->bill = 0;
        }

        // if customer wnats to clear all his bill
        else if (amount == bill->bill) 
        {
            printf (" Payment Successful\n ");
            bill->payment_status = 1;
            bill->bill = 0;
        }
        else 
        {
            printf ("Payment Sucessful \n");
            bill->payment_status = 0;
            bill->bill = bill->bill - amount;
            printf ("REFUND AMOUNT: %.2f \n",-bill->bill);
        }
        
     }
}
//---------------------------------------------------------------------------------------------------------//
//Function to execute
int executeC(info *p,float bill)
{
    int n=1;
    booking array[n];
    printf("\nCUSTOMER NAME:%s\n",p->name);
    printf("PHONE NUMBER:%s\n",p->phone);
    printf("AADHAR NUMBER:%s\n",p->Aadhar );
    array[0].bill=bill;
    //(0 for unpaid, 1 for paid):
    printf("Enter the payment status = ");
    scanf("%d", &array[0].payment_status);

    int choice;
    printf("Enter 1 to print the bill: ");
    scanf("%d", &choice);

    if (choice == 1) {
            printf ("--------BILL-----------");
            printf("\n");
            payment(&array[0],p);
        }

    return 0;
}
//---------------------------------------------------------------------------------------------------------//
//-------------------------------------------------RESTAURANT---------------------------------------------//
// Function to display the restaurant header
void JdisplayHeader()
{
    clearScreen();
    printf("\n");
    printf("\033[0;32m");
    printf(" ----------------------------------------------------------------------------------------------------------------\n");   
    printf(" .S_sSSs      sSSs_sSSs     .S S.    .S_SSSs    S.              sSSs   .S_sSSs      sSSs    sSSs  sdSS_SSSSSSbs\n");  
    printf(".SS~YSSSb    dSSSP~YSSSb   .SS SS.  .SS~SSSSS   SS.            dSSSP  .SS~YSSSb    dSSSP   dSSSP  YSSS~SSSSSSSP\n");  
    printf("SSS   `SSb  dSS'     `SSb  SSS SSS  SSS   SSSS  SSS           dSS'    SSS   `SSb  dSS'    dSS'         SSS     \n");  
    printf("SSS    SSS  SSS       SSS  SSS SSS  SSS    SSS  SSS           SSS     SSS    SSS  SSS     SS|          SSS     \n");  
    printf("SSS    d*S  S&S       S&S  SSS SSS  SSS SSSSSS  S&S           S&S     SSS    d*S  S&S     S&S          S&S     \n");  
    printf("S&S   .S*S  S&S       S&S   SS SS   S&S  SSSSS  S&S           S&S     S&S   .S*S  S&S_Ss  Y&Ss         S&S     \n");  
    printf("S&S_sdSSS   S&S       S&S    S S    S&S    S&S  S&S           S&S     S&S_sdSSS   S&S~SP  `S&&S        S&S     \n");  
    printf("S&S~YSYSb   S&S       S&S    SSS    S&S    S&S  S&S           S&S     S&S~YSYSb   S&S       `S*S       S&S     \n");  
    printf("S*S   `SSb  S*b       d*S    S*S    S*S    S&S  S*b           S*b     S*S   `Ssb  S*b        l*S       S*S     \n");  
    printf("S*S    SSS  S*S.     .S*S    S*S    S*S    S*S  S*S.          S*S.    S*S    SsS  S*S.      .S*P       S*S     \n");  
    printf("S*S    S&S   SSSbs_sdSSS     S*S    S*S    S*S   SSSbs         SSSbs  S*S    S&S   SSSbs  sSS*S        S*S     \n");  
    printf("S*S    SSS    YSSP~YSSY      S*S    SSS    S*S    YSSP          YSSP  S*S    SSS    YSSP  YSS'         S*S     \n");  
    printf("SP                           SP            SP                         SP                               SP      \n");  
    printf("Y                            Y             Y                          Y                                Y       \n");                                                         
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n");
}
//---------------------------------------------------------------------------------------------------------//
// Function to display the restaurant menu
void JdisplayMenu(MenuItem menu[], int size)
{
    system("cls");
    printf("\n");
    printf("*\n");
    printf("*                          Menu                               *\n");
    printf("*\n");
    for (int i = 0; i < size; i++)
        printf("* %d. %-50s $%.2f *\n", i + 1, menu[i].name, menu[i].price);
    printf("*\n");
}
//---------------------------------------------------------------------------------------------------------//
// Function to take the customer's order
void JtakeOrder(MenuItem menu[], int size, int quantity[])
{

    int choice, qty;
    do
    {
        // Prompt for item number
        printf("\nEnter item number to order (0 to finish): ");
        scanf("%d", &choice);
        // Validate the choice
        if (choice < 0 || choice > size)
        {
            printf("Invalid choice! Please enter a number between 1 and %d.\n", size);
            continue;
        }
        // If choice is not 0 (finish), prompt for quantity and update quantity array
        if (choice != 0)
        {
            printf("Enter quantity for %s: ", menu[choice - 1].name);
            scanf("%d", &qty);
            quantity[choice - 1] += qty;
        }
    } while (choice != 0);
    printf("\nThank you for your order!\n");
}
//---------------------------------------------------------------------------------------------------------//
// Function to calculate total price with GST
float JcalculateTotalWithGST(float subtotal)
{
    return subtotal + (subtotal * GST_RATE);
}
//---------------------------------------------------------------------------------------------------------//
// Function to generate the bill based on the order
void JgenerateBill(MenuItem menu[], int quantity[], int size,info *p)
{
    system("cls");
    float subtotal = 0.0;
    printf("**************************************Bill*********************************************\n");
    for(int i=0;i<80;i++)
    printf("-");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (quantity[i] > 0)
        {
            printf("* %s - Quantity: %d - Price: $%.2f\n", menu[i].name, quantity[i], menu[i].price * quantity[i]);
            subtotal += menu[i].price * quantity[i];
        }
    }
    for(int i=0;i<80;i++)
    printf("-");
    printf("\n");
    float total = JcalculateTotalWithGST(subtotal);
    printf("* Subtotal: $%.2f\n", subtotal);
    printf("* GST (18%%): $%.2f\n", subtotal * GST_RATE);
    printf("* Total (including GST): $%.2f\n", total);
    for(int i=0;i<80;i++)
    printf("-");
    executeC(p,total);
}
//---------------------------------------------------------------------------------------------------------//
// Function to prompt the user for feedback
void JprovideFeedback()
{
    int rating;
    printf("\nPlease rate our restaurant (1 to 5 stars): ");
    scanf("%d", &rating);
    if (rating >= 1 && rating <= 5)
    {
        printf("\nThank you for your rating! We're glad you enjoyed your experience.\n");
        printf("Please provide any further feedback for improvement: ");
        // Clear input buffer
        while (getchar() != '\n')
            ;
        char feedback[100];
        fgets(feedback, sizeof(feedback), stdin);
        printf("\nThank you for your feedback! We appreciate your suggestions.\n");
        printf("sdSS_SSSSSSbs   .S    S.    .S_SSSs     .S_sSSs     .S    S.          .S S.     sSSs_sSSs     .S       S. \n");
    printf("YSSS~SSSSSSSP  .SS    SS.  .SS~SSSSS   .SS~YSSSb   .SS    SS.        .SS SS.   dSSSP~YSSSb   .SS       SS.\n");
    printf("     SSS       SSS    SSS  SSS   SSSS  SSS   `SSb  SSS    S&S        SSS SSS  dSS'     `SSb  SSS       SSS\n");
    printf("     SSS       SSS    SSS  SSS    SSS  SSS    SSS  SSS    d*S        SSS SSS  SSS       SSS  SSS       SSS\n");
    printf("     S&S       SSS SSSSSS  SSS SSSSSS  SSS    S&S  S&S   .S*S        SSS SSS  S&S       S&S  S&S       S&S\n");
    printf("     S&S       S&S  SSS&S  S&S  SSSSS  S&S    S&S  S&S_sdSSS          SS SS   S&S       S&S  S&S       S&S\n");
    printf("     S&S       S&S    S&S  S&S    S&S  S&S    S&S  S&S~YSSYSb          S S    S&S       S&S  S&S       S&S\n");
    printf("     S&S       S&S    S&S  S&S    S&S  S&S    S&S  S&S    `SS          SSS    S&S       S&S  S&S       S&S\n");
    printf("     S*S       S*S    S*S  S*S    S&S  S*S    S*S  S*S     SS          S*S    S*b       d*S  S*b       d*S\n");
    printf("     S*S       S*S    S*S  S*S    S*S  S*S    S*S  S*S     S&          S*S    S*S.     .S*S  S*S.     .S*S\n");
    printf("     S*S       S*S    S*S  S*S    S*S  S*S    S*S  S*S     S&          S*S     SSSbs_sdSSS    SSSbs_sdSSS \n");
    printf("     S*S       SSS    S*S  SSS    S*S  S*S    SSS  S*S     SS          S*S      YSSP~YSSY      YSSP~YSSY  \n");
    printf("     SP               SP          SP   SP          SP                  SP                                 \n");
    printf("     Y                Y           Y    Y           Y                   Y                                  \n");
    printf("                                                                                                          \n");
    }
    else
    {
        printf("Invalid rating!\n");
    }
}
//---------------------------------------------------------------------------------------------------------//
//Calling Function
int Jmain2(info *p)
{
    system("cls");
    // Greet the customer
    JdisplayHeader();
    printf("Welcome to our restaurant!\n");
    printf("We are delighted to have you with us.\n");

    char orderChoice;
    printf("\n\nWould you like to order something? (Y/N): ");
    scanf(" %c", &orderChoice);

    if (orderChoice == 'Y' || orderChoice == 'y')
    {
        // Define menu items
        MenuItem menu[MENU_SIZE] = {
            {"Burger", 8.99}, {"Pizza", 12.99}, {"Pasta", 10.49}, {"Steak", 20.99}, {"Fish and Chips", 15.49}, {"Salad", 6.99}, {"Soup", 4.99}, {"Dessert", 7.99}};

        int quantity[MENU_SIZE] = {0}; // Initialize quantity of each item to 0

        // Display the menu
        JdisplayMenu(menu, MENU_SIZE);

        // Take the customer's order
        JtakeOrder(menu, MENU_SIZE, quantity);

        // Generate the bill
        JgenerateBill(menu, quantity, MENU_SIZE,p);

        // Prompt for feedback
        JprovideFeedback();
    }

    // Thank the customer
    printf("Thank you for dining with us! We look forward to serving you again.\n");

    

    return 0;
}
//---------------------------------------------------------------------------------------------------------//
//Executing the Function
int Jexecute(info *p)
{
    printf("Input your hotel id:\n");
    int id;
    scanf("%d",&id);
    while(p->hotelid!=id&&p->next!=NULL)
    p=p->next;
    if(p->hotelid==id)
    Jmain2(p);
    else
    printf("Invalid hotel id!You cannot access the restaurant\n");
    return 0;
}
//---------------------------------------------------------------------------------------------------------//
//CHECK IN-CHECK OUT PROGRAM
//---------------------------------------------------------------------------------------------------------//
//Function to check leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
//---------------------------------------------------------------------------------------------------------//
//Function to check days in month
int daysInMonth(int month, int year) {
    int days[] = {31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[month - 1];
}
//---------------------------------------------------------------------------------------------------------//
//Function to display customer details and check out information
float displayK(Customer *customers, int n,info *p) {
    int i;
    printf("\nCustomer Records:\n");
    for (i = 0; i < n; i++) {
        printf("\nCustomer Name: %s", p->name);
        printf("\nRoom Number: %d", p->rno);

        // Calculate number of days stayed
        int checkin_day = atoi(strtok(customers[i].checkin_date, "-"));
        int checkin_month = atoi(strtok(NULL, "-"));
        int checkin_year = atoi(strtok(NULL, "-"));

        int checkout_day = atoi(strtok(customers[i].checkout_date, "-"));
        int checkout_month = atoi(strtok(NULL, "-"));
        int checkout_year = atoi(strtok(NULL, "-"));

        int days_stayed = 0;
        for (int year = checkin_year; year < checkout_year; year++) {
            days_stayed += 365 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        }

        for (int month = checkin_month; month < checkout_month; month++) {
            days_stayed += daysInMonth(month, checkout_year);
        }

        days_stayed += checkout_day - checkin_day;

        printf("\nCheck-in Date: %s", customers[i].checkin_date);
        printf("\nCheck-out Date: %s", customers[i].checkout_date);
        printf("\nNumber of days stayed: %d", days_stayed);

        // Calculate amount
        float amount = days_stayed * 100; // Assuming $100 per day
        printf("\nAmount: $%f", amount);
        return amount;
    }
}
//---------------------------------------------------------------------------------------------------------//
//Function to store customer records
void customerRecordsK(int n,info *p) {
    Customer *customers = (Customer *)malloc(n * sizeof(Customer));

    for (int i = 0; i < n; i++) {
        printf("Name:%s\n ",p->name);
        printf("Room Number:%d",p->rno);
        printf("\nCheck-in Date (format: dd-mm-yyyy): ");
        scanf("%s", customers[i].checkin_date);
        printf("Check-out Date (format: dd-mm-yyyy): ");
        scanf("%s", customers[i].checkout_date);
    }

    float k=displayK(customers, n,p);
    executeC(p,k);
    free(customers);
}
//---------------------------------------------------------------------------------------------------------//
//Function to exectute check-out check in function
void executeK(info *p)
{
    customerRecordsK(1,p);
}
//---------------------------------------------------------------------------------------------------------//
//Feedback Collection system
void addGuest() {
    if (numGuests < MAX_ROOMS) {
        struct Guest newGuest;
        printf("Enter guest name: ");
        scanf("%s", newGuest.name);
        printf("Enter room number: ");
        scanf("%d", &newGuest.roomNumber);
        newGuest.feedback[0] = '\0'; // Initialize feedback to empty string
        newGuest.complaint[0] = '\0'; // Initialize complaint to empty string
        guests[numGuests] = newGuest;
        numGuests++;
        printf("Guest added successfully!\n");
    } else {
        printf("Sorry, the hotel is full.\n");
    }
}
//---------------------------------------------------------------------------------------------------------//
//Function to list guests
void listGuests() {
    printf("Guest List:\n");
    for (int i = 0; i < numGuests; i++) {
        printf("Room %d: %s\n", guests[i].roomNumber, guests[i].name);
    }
}
//---------------------------------------------------------------------------------------------------------//
//Funtion to provide feedback
void giveFeedback(int roomNumber, char *feedback) {
    for (int i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            strcpy(guests[i].feedback, feedback);
            printf("Feedback recorded successfully!\n");
            return;
        }
    }
    printf("Room number not found.\n");
}
//---------------------------------------------------------------------------------------------------------//
//Function to register complaint
void registerComplaint(int roomNumber, char *complaint) {
    for (int i = 0; i < numGuests; i++) {
        if (guests[i].roomNumber == roomNumber) {
            strcpy(guests[i].complaint, complaint);
            printf("Complaint registered successfully!\n");
            return;
        }
    }
    printf("Room number not found.\n");
}
//---------------------------------------------------------------------------------------------------------//
//Funtion to executeA
void executeA() {
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. List Guests\n");
        printf("3. Give Feedback\n");
        printf("4. Register Complaint\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addGuest();
                break;
            case 2:
                listGuests();
                break;
            case 3: {
                int roomNumber;
                char feedback[MAX_FEEDBACK_LENGTH];
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter feedback: ");
                scanf("\n%[^\n]", feedback);
                giveFeedback(roomNumber, feedback);
                break;
            }
            case 4: {
                int roomNumber;
                char complaint[MAX_COMPLAINT_LENGTH];
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter complaint: ");
                scanf("\n%[^\n]", complaint);
                registerComplaint(roomNumber, complaint);
                break;
            }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}
//---------------------------------------------------------------------------------------------------------//
// Function to add a new service
void addService() {
    if(numServices < MAX_SERVICES) {
        printf("Enter the name of the service: ");
        scanf("%s", services[numServices].name);
        printf("Enter the price of the service: ");
        scanf("%f", &services[numServices].price);
        numServices++;
        printf("Service added successfully.\n");
    } else {
        printf("Maximum number of services reached.\n");
    }
}
//---------------------------------------------------------------------------------------------------------//
// Function to display available services
void displayServices() {
    printf("\n\nAvailable Services:\n");
    for(int i = 0; i < numServices; i++) {
        printf("%d. %s - $%.2f\n", i + 1, services[i].name, services[i].price);
    }
    printf("\n\n");
}
//---------------------------------------------------------------------------------------------------------//
// Function to book services
void bookServices(Service bookyourservices[], int size, int serviceslist[] ) {
    printf("Booking Services...\n");
    int choice, qty;
    do {
        // Prompt for service number
        printf("\nEnter service number to book (0 to finish): ");
        scanf("%d", &choice);
        // Validate the choice
        if (choice < 0 || choice > size) {
            printf("Invalid choice! Please enter a number between 1 and %d.\n", size);
            continue;
        }
        // If choice is not 0 (finish), prompt for quantity and update quantity array
        if (choice != 0) {
            serviceslist[choice - 1] +=1;
        }
    } while (choice != 0);
}
//---------------------------------------------------------------------------------------------------------//
//Function to display the Services chose
void displayG(int num,int list[],info *p)
{
    float Grandtotal=0.0;
    printf("************************************************SERVICES CHOSEN****************************************************\n");
    for(int i=0;i<num;i++)
    {
        if(list[i]!=0)
        {
            printf("S.NO\t\tSERVICE NAME\t\tPRICE($)\n");
            int p=(services[i].price)*list[i];
            printf("%d.\t\t%s\t\t%d\n",i+1,services[i].name,p);
            Grandtotal+=(services[i].price)*list[i];
        }
    }
    printf("TOTAL($):%f\n",Grandtotal);
    printf("Thank you for using our services\n");
    printf("*****************************************************************************************************************\n");
    executeC(p,Grandtotal);
}
//---------------------------------------------------------------------------------------------------------//
//Function to execute the Extra services
int executeG(info *p) {
    strcpy(services[0].name, "Room Cleaning");
    services[0].price = 20.0;
    strcpy(services[1].name, "Laundry");
    services[1].price = 15.0;
    strcpy(services[2].name, "Room Service");
    services[2].price = 30.0;
    strcpy(services[3].name, "Repair");
    services[3].price = 25.0;
    numServices = 4;
    int choice;
    printf("Input your hotel id:\n");
    int id;
    scanf("%d",&id);
    while(p->hotelid!=id&&p->next!=NULL)
    p=p->next;
    if(p->hotelid==id)
    {
        int serviceslist[10]={0}; //Initialize choice of each service to 0
        do {
            printf("1. Add Service\n");
            printf("2. Display Services\n");
            printf("3. Book Services\n");
            printf("4. Display Bill\n");
            printf("5)EXIT...\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    addService();
                    break;
                case 2:
                    displayServices();
                    break;
                case 3:
                    bookServices(services, numServices,  serviceslist);
                    break;
                case 4:displayG(numServices,serviceslist,p);
                break;
                case 5:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 4.\n");
            }
        } while(choice != 5);
        return 0;
    }
    else
    {
        printf("Invalid hotel id:You cannot access the services\n");
        return 0;
    }
}
//---------------------------------------------------------------------------------------------------------//
//Function to check in the cars
void checkIn(struct Car cars[], int id) {
    // Find a free slot for the car
    int i;
    for (i = 0; i < 50; i++) {
        if (!cars[i].checked_in) {
            cars[i].id = id;
            cars[i].checked_in = 1;
            cars[i].days_parked = 0;
            printf("Car with ID %d checked in successfully.\n", id);
            return;
        }
    }
    printf("No free slots available for parking.\n");
}
//---------------------------------------------------------------------------------------------------------//
//Function to checkout the cars
int checkOut(struct Car cars[], int id,double t) {
    // Find the car by its ID and calculate parking fees
    int i;
    for (i = 0; i < 50; i++) {
        if (cars[i].checked_in && cars[i].id == id) {
            int fees = t * PARKING_FEE_PER_DAY;
            printf("Car with ID %d checked out.\n", id);
            printf("Parking fees: Rs. %d\n", fees);
            cars[i].checked_in = 0; // Mark as checked out
            return fees; 
        }
    }
    printf("Car with ID %d not found in the parking lot.\n", id);
}
//---------------------------------------------------------------------------------------------------------//
//Function to execute the parking system
int executeGA() {
    struct Car cars[50]; // Max 50 car limit, can be edited if needed
    int choice, id,k;
    time_t start,end;
    double dif;

    for (;;) {
        printf("\nCar Parking System\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter car ID: ");
                scanf("%d", &id);
                checkIn(cars, id);
                time (&start);
                break;
            case 2:
                printf("Enter car ID: ");
                scanf("%d", &id);
                time (&end);
                dif = difftime (end,start);
                k=checkOut(cars, id,dif);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
//---------------------------------------------------------------------------------------------------------//
//Function for worker's attendance
void WorkersRecord(int date)
{
    printf("If worker came for hotel the enter 1 or else enter 0 \n");
    printf("\n \n");
    int total=0;
    printf("1.RECEPTIONIST :");
    printf(" K.Sandhya \n");
    printf("salary : 650/day \n");
    printf("Receptionist attendance :");
    scanf("%d",&days[0][date-1]);
                                          //information about receptionist//
    printf("2.HEAD CHEF :");
    printf(" Vikas khanna \n");
    printf("salary : 1250/day \n");
    printf("Main chef attendance :");
    scanf("%d",&days[1][date-1]);
                                          //information about head chef//
    printf("3.ASSISTANT CHEF :");
    printf(" S.Ramandeep \n");
    printf("salary : 1050/day \n");
    printf("Assistant chef attendance :");
    scanf("%d",&days[2][date-1]);
                                          //information about assistant chef//
    printf("4.HOUSE KEEPER :");
    printf("A.Akshay kumar\n");
    printf("salary : 450/day \n");
    printf("housekeeper attendance :");
    scanf("%d",&days[3][date-1]);
                                          //information about hosekeeper//
    printf("5.CLEANER :");
    printf(" A.Arjun \n");
    printf("salary : 400/day \n");
    printf("cleaner attendance :");
    scanf("%d",&days[4][date-1]);
                                          //information about cleaner//
    printf("6.PLUMBER :");
    printf(" P.Someshwar \n");
    printf("salary : 500/day \n");
    printf("Plumber attendance :");
    scanf("%d",&days[5][date-1]);
                                          //information about plumber//
    printf("7.ELECTRICIAN :");
    printf(" Mehaboob \n");
    printf("salary : 450/day \n");
    printf("electrician attendance :");
    scanf("%d",&days[6][date-1]);
                                          //information about electrician//
    printf("8.SWEEPER :");
    printf(" Tilak Varma \n");
    printf("salary : 400/day \n");
    printf("Sweeper attendance :");
    scanf("%d",&days[7][date-1]);
                                          //information about sweeper//
    printf("9.CASHIER :");
    printf(" R.Anwit Sharma \n");
    printf("salary : 1450/day \n");
    printf("Cashier attendance :");
    scanf("%d",&days[8][date-1]);
                                          //information about cashier//
    printf("10.MANAGER :");
    printf(" vikas \n");
    printf("salary : 1650/day \n");
    printf("Manager attendance :");
    scanf("%d",&days[9][date-1]);
                                          //information about manager//
    printf("11.DOORMAN :");
    printf(" S.RAMESH \n");
    printf("salary : 500/day \n");
    printf("doorman attendance :");
    scanf("%d",&days[10][date-1]);
                                          //information about doorman//
    printf("12.HEAD SECURITY :");
    printf(" G.Abhishek \n");
    printf("salary : 900/day \n");
    printf("head security attendance :");
    scanf("%d",&days[11][date-1]);
                                          //information about head security//
    printf("13.SECURITY :");
    printf(" Manish kumar \n");
    printf("salary : 650/day \n");
    printf("security attendance :");
    scanf("%d",&days[12][date-1]);
                                          //information about security//
    printf("14.DISHWASHER :");
    printf(" E.Karishma \n");
    printf("salary : 450/day \n");
    printf("Dishwasher attendance :");
    scanf("%d",&days[13][date-1]);
                                          //information about dishwasher//
    printf("15.WAITER :");
    printf(" S.Krishna \n");
    printf("salary : 650/day \n");
    printf("waiter attendance :");
    scanf("%d",&days[14][date-1]);
                                          //information about waiter//
    for(int i=0;i<15;i++)
    {
        if(days[i][date-1])
        {
            total++;
        }
    }
    printf("Total attended employes in today are :\n");
    printf("%d\n",total);
}
//---------------------------------------------------------------------------------------------------------//
//Function to execute worker's attendance
int executeKO()
{
    int date;
    printf("Enter today date :");
    scanf("%d",&date);
    WorkersRecord( date);
    return 0;
}
//---------------------------------------------------------------------------------------------------------//
//Main Function 
void main()
{
    int choice,id;
    Dinit();
    Dlogin();
    info *head,*p;
    Rinit(&head);
    Room rooms[room_count];
    // Initialize each room
    for (int i = 0; i < room_count; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].is_booked = 0;
        strcpy(rooms[i].guest_name, "N/A");
    }
    do
    {
        Dpreface();
        printf("\nInput your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:head=Rcreate_list();
            Dexecute(rooms,&head);
            break;
            case 2:Rdisplay(head);
            break;
            case 3:Rdelete(&head);
            break;
            case 4:DdisplayRooms(rooms,room_count);
            break;
            case 5:DdisplayRooms(rooms,room_count);
            Rinsert(&head);
            Dexecute(rooms,&head);
            break;
            case 6:Redit(&head);
            break;
            case 7:Jexecute(head);
            break;
            case 8:executeG(head);
            break;
            case 9:p=head;
                printf("Input your hotel id:\n");
                scanf("%d",&id);
                while(p->hotelid!=id&&p->next!=NULL)
                p=p->next;
                if(p->hotelid==id)
                {
                    executeK(p);
                    rooms[(p->rno)-1].is_booked=0;
                    strcpy(rooms[(p->rno)-1].guest_name, "N/A");
                }
                else
                printf("Invalid Hotel Id!You cannot access the checkout Portal\n");
            break;
            case 10:executeA();
            break;
            case 11:executeGA();
            break;
            case 12:executeKO();
            break;
            case 13:printf("EXITING.....\n");
            break;
            default:printf("Invalid Choice\n");
            break;
        }
    }while(choice!=13);
}