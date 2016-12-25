/* Defines */
#define FNAME_SIZE 16
#define LNAME_SIZE 16
#define PHONE_NUMBER_SIZE 16
#define TITLE_SIZE 4 
#define EMAIL_SIZE 30
#define ADDRESS_SIZE 150
#define GROUP_SIZE 16
#define NNAME_SIZE 10

/* Typedef contact structure */
typedef struct node
{
    char view_index;                        /* Flag to be set if search criteria matches */
    char first_name[FNAME_SIZE];            /* To store first name                       */
    char last_name[LNAME_SIZE];             /* To store last name                        */
    char phone_number[PHONE_NUMBER_SIZE];   /* To store phone number                     */
    char title[TITLE_SIZE];                 /* To store title                            */
    char e_mail[EMAIL_SIZE];                /* To store e_mail address                   */
    char address[ADDRESS_SIZE];             /* To store address                          */
    char group[GROUP_SIZE];                 /* To store group to which contact belongs   */
    char nick_name[NNAME_SIZE];             /* To store nick name                        */
} contact_t;

