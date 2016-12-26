/*####################################################################################*/
DETAILS OF METADATA
/*####################################################################################*/

typedef enum 
{ 
    NORMAL = 0,
    EMPTY = 1,
    FULL = 2
} A_B_status_t;

/* Typedef metadata structure */
typedef struct 
{
    char magic_string[5];                   /* Magic string "*A*B" to identify address book file format */
    A_B_status_t address_book_status;       /* To set address book status as NORMAL, EMPTY, FULL        */
    unsigned int no_of_contacts;            /* No of contacts available at present                      */
    unsigned int max_contacts;              /* Maximum number of contacts can be stored                 */
    unsigned int contact_size;              /* Size of each contact in file, by default is 259 bytes    */
} metadata_t;

/*

 * All the fields in the above typedef metadata_t are integers except for magic
   string which is a null terminated string.

 * Size of meta data in file is 21 bytes; 

 * Each field of a metadata is stored  continuously  one  after the other in file 
   without  any delimiter since each field and whole metadata is of fixed size in 
   the file.

* There can be two ways to have a metadata. 
   1 - if metadata exists in address book file, can  be  copied  to the dynamically
   created metadata structure.
   2 - if it is a new address book file, a dummy metadata structure is
   created and hard coded by the programmer as
   magic string = "*A*b*";
   address_book_status = EMPTY;
   no_of_contacts = 0;
   max_contacts = 300;
   contact_size = 259;
*/

/*####################################################################################*/
DETAILS OF CONTACT
/*####################################################################################*/

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
    char view_index;                        /* To store index of contact if search criteria matches    */
    char first_name[FNAME_SIZE];            /* To store first name                                     */
    char last_name[LNAME_SIZE];             /* To store last name                                      */
    char phone_number[PHONE_NUMBER_SIZE];   /* To store phone number                                   */
    char title[TITLE_SIZE];                 /* To store title                                          */
    char e_mail[EMAIL_SIZE];                /* To store e_mail address                                 */
    char address[ADDRESS_SIZE];             /* To store address                                        */
    char group[GROUP_SIZE];                 /* To store group to which contact belongs                 */
    char nick_name[NNAME_SIZE];             /* To store nick name                                      */
    struct node *link;                      /* Link to next contact                                    */
} contact_t;

/*

 * All the fields in the above typedef contact_t are null terminated strings
   except for view_index which is a integer value of one byte.

 * Each  field  has the  last  byte as '\0', so the  user  should be restricted
   to enter characters  one  byte  less  than  the maximum allowable characters
   for that field. The last byte will be made '\0' explicitly by the programmer
   while reading the field from user. 

 * Suppose the field contains data less than maximum allowable characters in
   that field, then rest of the elements should be made '\0'. For example : 
   nickname has maximum of 10 alloable characters. If the nickname entered by
   the user is "chotu", the field would look like
   ['c', 'h', 'o', 't', 'u', \0', '\0', '\0', '\0', \0']

 * Each field of a contact is stored continuously one after the other in file 
   without any delimiter since each field and also whole contact is of fixed size
   in the entire file.

* There can be two ways to have a contact. 
   1 - if contact exists in address book file, can  be  copied  to the dynamically
   created node in linklist.
   2 - if user adds a contact, the fields can be read from user to the dynamically
   created node in linklist.

*/
/*####################################################################################*/
DETAILS OF RETURN TYPE OF FUNCTIONS
/*####################################################################################*/

typedef enum
{
    e_success,
    e_failure,
} status_t;

Note : All function should only return either of above two values.

/*####################################################################################*/






