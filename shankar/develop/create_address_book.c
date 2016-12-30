#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Defines */
#define FNAME_SIZE 16
#define LNAME_SIZE 16
#define PHONE_NUMBER_SIZE 16
#define TITLE_SIZE 4 
#define EMAIL_SIZE 30
#define ADDRESS_SIZE 150
#define GROUP_SIZE 16
#define NNAME_SIZE 10
/* Metadata */
#define MAGIC_STRING_SIZE 5
#define ADD_BOOK_STATUS_SIZE 4
#define NO_OF_CONTACTS_SIZE 4
#define MAX_NO_CONTACTS_SIZE 4
#define CONTACT_SIZE 4

/* Typedef of return value */
typedef enum
{
    e_success,
    e_failure,
} status_t;

/* Typedef of address book status */
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

/***********  Function prototypes ********** */

/* Create a link list of contact */
void create_contact_list(contact_t **head);

/* create a node */
contact_t *create_node(void);

/* Function to set all bytes of field to zero */
status_t reset_field(char *field, int size);

/* Function to set all elements of contact to zero */
status_t read_field(char *field, int sizse);

/* Function to set all elements of contact to '\0' */
status_t reset_contact(contact_t *contact);

/* Function to read a entire contact from user */
status_t read_contact(contact_t *contact);

/* Function to print entire contact */
status_t print_contact(contact_t contact);

/* Function to write entire contact to file destination */
status_t write_contact_to_file(FILE *fd, contact_t contact);

/* Function to  create a dummy metadata */
status_t create_metadata(metadata_t *metadata);

/* Function to print metadata */
status_t print_metadata(metadata_t metadata);

/* Function to write dummy metadata to file destination */
status_t write_metadata_to_file(FILE *fd, metadata_t metadata);

/* Function to copy metadata from file */
status_t copy_metadata_from_file(metadata_t *metadata, FILE *fs);

/* Function to reset metadata structure */
status_t reset_metadata(metadata_t *metadata);

/* Function to copy contact from file */
status_t copy_contact_from_file(contact_t *ptr, FILE *fs);

int main(void)
{
    contact_t *head = NULL;      /* Creating a local contact     */
    contact_t *ptr;      /* Creating a local contact     */
    metadata_t metadata;    /* Creating a local metadata    */
    FILE *fd, *fs;               /* File destination             */
    int idx, count;         /* Loop variables               */

#if 0
    /* Get input from user */
    printf("Enter no of contacts to input : ");
    scanf("%d", &count);

    /* Open file for writing */
    fd = fopen("ad.txt", "w");

    /* create a dummy meta data */
    create_metadata(&metadata);
    metadata.no_of_contacts = count;
    print_metadata(metadata);

    /* write metadata to file */
    write_metadata_to_file(fd, metadata);

    /* create a link list of contacts */
    for (idx = 0; idx < count; idx++)
    {
        create_contact_list(&head);
    }


    /* Read contacts and write to file */
    ptr = head;
    for (idx = 0; idx < count; idx++)
    {
        reset_contact(ptr);
        read_contact(ptr);
        write_contact_to_file(fd, *ptr);
        ptr = ptr->link;
    }

    /* print contacts */
    ptr = head;
    for (idx = 0; idx < count; idx++)
    {
        print_contact(*ptr);
        ptr = ptr->link;
    }

    /* Close destination file */
    fclose(fd);

    return e_success;
}

#endif

fs = fopen("ad1.txt", "r");

reset_metadata(&metadata);

copy_metadata_from_file(&metadata, fs);

for (idx = 0; idx < metadata.no_of_contacts; idx++)
{
    create_contact_list(&head);
}

ptr = head;

for (idx = 0; idx < metadata.no_of_contacts; idx++)
{
    reset_contact(ptr);
    copy_contact_from_file(ptr, fs);
    ptr = ptr->link;
}

 /* print contacts */
    ptr = head;
    for (idx = 0; idx < metadata.no_of_contacts; idx++)
    {
        print_contact(*ptr);
        ptr = ptr->link;
    }

    /* Close source file */
    fclose(fs);

    return e_success;
}


/* Create a link list of contact */
void create_contact_list(contact_t **head)
{
    contact_t *ptr = *head;

    if (*head == NULL)
    {
        *head = create_node();
        return;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = create_node();
        return;
    }
}

/* create a node */
contact_t *create_node(void)
{
    contact_t *new = (contact_t *)malloc(sizeof(contact_t));
    new->link = NULL;
    return new;
}

/* Function to set all bytes of field to zero */
status_t reset_field(char *field, int size)
{
    int idx;

    for (idx =0 ; idx < size; idx++)
    {
        field[idx] = 0;
    }

    return e_success;
}    

/* Function to read field from user */
status_t read_field(char *field, int size)
{
    int idx;
    char ch;

    /* Ignore new lines due to previous input */
    while ((ch = getchar()) == '\n');
    ungetc(ch, stdin);

    /* Fetch (fieldsize - 1) bytes of data*/
    for (idx = 0 ; idx < size - 1; idx++)
    {
        scanf("%c", (field + idx));
        if (field[idx] == '\n')
        {
            field[idx] = '\0';
            break;
        }
    }
    
    /* Clear stdin for extra input if any */
    if (idx == size - 1)
    while (getchar() != '\n');

    return e_success;
}    

/* Function to set all elements of contact to zero */
status_t reset_contact(contact_t *contact)
{
    contact->view_index = 0;
    reset_field(contact->first_name, FNAME_SIZE);
    reset_field(contact->last_name, LNAME_SIZE);
    reset_field(contact->phone_number, PHONE_NUMBER_SIZE);
    reset_field(contact->title, TITLE_SIZE);
    reset_field(contact->e_mail, EMAIL_SIZE);
    reset_field(contact->address,ADDRESS_SIZE);
    reset_field(contact->group, GROUP_SIZE);
    reset_field(contact->nick_name, NNAME_SIZE);
    
    return e_success;
}

/* Function to read a entire contact from user */
status_t read_contact(contact_t *contact)
{
    contact->view_index = 0;
    printf("\nEnter first name    : ");
    read_field(contact->first_name, FNAME_SIZE);
    printf("Enter last name     : ");
    read_field(contact->last_name, LNAME_SIZE);
    printf("Enter phone number  : ");
    read_field(contact->phone_number, PHONE_NUMBER_SIZE);
    printf("Enter title         : ");
    read_field(contact->title, TITLE_SIZE);
    printf("Enter email address : ");
    read_field(contact->e_mail, EMAIL_SIZE);
    printf("Enter address       : ");
    read_field(contact->address, ADDRESS_SIZE);
    printf("Enter group         : ");
    read_field(contact->group, GROUP_SIZE);
    printf("Enter nick name     : ");
    read_field(contact->nick_name, NNAME_SIZE);
    
    return e_success;
}

/* Function to print entire contact */
status_t print_contact(contact_t contact)
{
    printf("\nFirst name    : %s\n", contact.first_name);
    printf("Last name     : %s\n", contact.last_name);
    printf("Phone number  : %s\n", contact.phone_number);
    printf("Title         : %s\n", contact.title);
    printf("Email address : %s\n", contact.e_mail);
    printf("Address       : %s\n", contact.address);
    printf("Group         : %s\n", contact.group);
    printf("Nick name     : %s\n", contact.nick_name);
    
    return e_success;
}

/* Function to write entire contact to file destination */
status_t write_contact_to_file(FILE *fd, contact_t contact)
{
    fwrite(contact.first_name,   sizeof(char), FNAME_SIZE, fd);
    fwrite(contact.last_name,    sizeof(char), LNAME_SIZE, fd);
    fwrite(contact.phone_number, sizeof(char), PHONE_NUMBER_SIZE, fd);
    fwrite(contact.title,        sizeof(char), TITLE_SIZE, fd);
    fwrite(contact.e_mail,       sizeof(char), EMAIL_SIZE, fd);
    fwrite(contact.address,      sizeof(char), ADDRESS_SIZE, fd);
    fwrite(contact.group,        sizeof(char), GROUP_SIZE, fd);
    fwrite(contact.nick_name,    sizeof(char), NNAME_SIZE, fd);

    return e_success;
}

/* Function to  create a dummy metadata */
status_t create_metadata(metadata_t *metadata)
{
    strcpy(metadata->magic_string, "*A*B");
    metadata->address_book_status = NORMAL;
    metadata->no_of_contacts = 0;
    metadata->max_contacts = 300;
    metadata->contact_size = 259;

    return e_success;
}

/* Function to print metadata */
status_t print_metadata(metadata_t metadata)
{
    printf("Magic string         = %s\n", metadata.magic_string);
    printf("Adress book status   = %d\n", metadata.address_book_status);
    printf("Number of contacts   = %d\n", metadata.no_of_contacts);
    printf("Max contacts         = %d\n", metadata.max_contacts);
    printf("Size of each contact = %d\n", metadata.contact_size);

    return e_success;
}

/* Function to write dummy metadata to file destination */
status_t write_metadata_to_file(FILE *fd, metadata_t metadata)
{
    fwrite(metadata.magic_string, sizeof(char), 5, fd);
    fwrite(&metadata.address_book_status, sizeof(int), 1, fd);
    fwrite(&metadata.no_of_contacts,sizeof(int), 1, fd);
    fwrite(&metadata.max_contacts, sizeof(int), 1, fd);
    fwrite(&metadata.contact_size, sizeof(int), 1, fd);

    return e_success;
}

/* Function to copy contact from file */
status_t copy_contact_from_file(contact_t *ptr, FILE *fs)
{
    fread(ptr->first_name, sizeof(char), FNAME_SIZE, fs);
    fread(ptr->last_name, sizeof(char), LNAME_SIZE, fs);
    fread(ptr->phone_number, sizeof(char), PHONE_NUMBER_SIZE, fs);
    fread(ptr->title, sizeof(char), TITLE_SIZE, fs);
    fread(ptr->e_mail, sizeof(char), EMAIL_SIZE, fs);
    fread(ptr->address, sizeof(char), ADDRESS_SIZE, fs);
    fread(ptr->group, sizeof(char), GROUP_SIZE, fs);
    fread(ptr->nick_name, sizeof(char), NNAME_SIZE, fs);

    return e_success;
}

/* Function to copy metadata from file */
status_t copy_metadata_from_file(metadata_t *metadata, FILE *fs)
{
    fread(metadata->magic_string, sizeof(char), MAGIC_STRING_SIZE, fs);
    fread(&metadata->address_book_status, ADD_BOOK_STATUS_SIZE, 1, fs);
    fread(&metadata->no_of_contacts, NO_OF_CONTACTS_SIZE, 1, fs);
    fread(&metadata->max_contacts, MAX_NO_CONTACTS_SIZE, 1, fs);
    fread(&metadata->contact_size, CONTACT_SIZE, 1, fs);

    return e_success;
}

/* Function to reset metadata structure */
status_t reset_metadata(metadata_t *metadata)
{
    int i;

    for (i = 0; i < MAGIC_STRING_SIZE; i++)
    {
        metadata->magic_string[i] = '\0';
    }

    metadata->address_book_status = 0;
    metadata->no_of_contacts = 0;
    metadata->max_contacts = 0;
    metadata->contact_size = 0;

    return e_success;

}
