#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook, int sortChoice) 
{
    //outer loop for bubble sort.
    for (int i = 0; i < addressBook->contactCount - 1; i++)
    {
        //inner loop for pair comparison
        for (int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            // variable for comparison
            int cmp = 0;
            if (sortChoice == 1)//press 1 for name sort
                cmp = strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name);
            else if (sortChoice == 2)//press 2 for phone num sort
                cmp = strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone);
            else if (sortChoice == 3)//press 3 for email sort
                cmp = strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email);
                //if cmp value is greater than 0 assign i place i+1,i+1 place i using temp variable.
            if (cmp > 0)
            {
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
    //print header for contact list
    printf("s.no\tName\t\tphone_no\tEmail\n");
    printf("-------------------------------------------\n");
    for(int i=0;i<(addressBook->contactCount);i++)
    {
        printf("%d\t%s\t\t%s\t%s\t\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
        
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;//start with empty address book
    //populateAddressBook(addressBook);
    
    //Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    
    printf("contact saved succesfully");
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char names[10];
    char phone[10];
    char email_id[20];
	printf("Enter the name : ");
    getchar();
    scanf("%[^\n]",names);
    //for validation call validate_name function
    if(validate_name(names))
    {
        //store valid name
    strcpy(addressBook->contacts[addressBook->contactCount].name,names);
    }
    else
    {
        printf("Your name is invalid please try again!");
        return;
    }
    printf("enter the phone number : ");
    scanf("%s",phone);
    //for validation call this function
    if(validate_phone(phone,addressBook))
    {
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);// store valid phone number
    }
    else
    {
       printf("your phone_no is invalid,pleaes try again");
       return ;
    }
    printf("Enter the email_id : ");
    scanf("%s",email_id);
    //for validating email call this function
    if(validate_email(email_id,addressBook))
     {
    strcpy(addressBook->contacts[addressBook->contactCount].email,email_id);//store valid email
     }
     else
     {
        printf("your emailid is invalid please try again!");
        return;
     }
    (addressBook->contactCount)++;
    printf("contact created succesfully!");
    
    
}

int searchContact(AddressBook *addressBook) 
{
    char name[20];
    char phone_no[10];
    char email_id[20];
    printf("Enter the choice to search the contact\npress 1 for Name search;\npress 2 for phone_no search;\npress 3 for email_id search;\n");
        int searchchoice,found=0;
        scanf("%d",&searchchoice);
        switch(searchchoice)
        {
            case 1:
                printf("Enter the name to search contact: ");
                getchar();
                scanf("%[^\n]",name);
                //loop for all contacts if it is matched its print contact details
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasecmp(addressBook->contacts[i].name,name)==0)
                    {
                        printf("index value is: %d\n",i);
                        printf("Name: %s\n",addressBook->contacts[i].name);
                        printf("phone: %s\n",addressBook->contacts[i].phone);
                        printf("email: %s\n",addressBook->contacts[i].email);
                        found=1;
                    
                    }
                }
                break;
            case 2:
                 printf("Enter the phone to search phonenumber: ");
                 scanf("%s",phone_no);
                 //loop for all contacts if it is matched its print contact details
                 for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasecmp(addressBook->contacts[i].phone,phone_no)==0)
                    {
                        printf("index value is: %d\n",i);
                        printf("Name: %s\n",addressBook->contacts[i].name);
                        printf("phone: %s\n",addressBook->contacts[i].phone);
                        printf("email: %s\n",addressBook->contacts[i].email);
                        found=1;
                        
                    }
                }
                 break;
            case 3:
                  printf("enter the email_id to search: ");
                  scanf("%s",email_id);
                  //loop for all contacts if it is matched its print contact details
                  for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(strcasecmp(addressBook->contacts[i].email,email_id)==0)
                    {
                        printf("index value is: %d\n",i);
                        printf("Name: %s\n",addressBook->contacts[i].name);
                        printf("phone: %s\n",addressBook->contacts[i].phone);
                        printf("email: %s\n",addressBook->contacts[i].email);
                        found=1;
                    
                    }
                }
                  break;
        }
        if(!found)
        {
            printf("contact not found\n");
            return 0;
        }
        return 1;
        /* Define the logic for search */
}

void editContact(AddressBook *addressBook)
{
    // to get the index of contact so we are calling this function
    int res=searchContact(addressBook);
    if(res==0)
    {
        printf("contact not available in the list can't edit the contact");
    }
    if(res==1)
    {
        char edited_name[20];
        char edited_phone_no[10];
        char edited_email[20];
        int edit_choice;
        int index;
        printf("Enter the choice to edit the contact details\npress 1 to edit the Name:\npress 2 to edit the phone number:\npress 3 to edit the email_id:");
        scanf("%d",&edit_choice);
        printf("Enter contact list number: ");
        scanf("%d",&index);
        switch(edit_choice)
        {
            case 1:
                   printf("Enter the new_name: ");
                   getchar();
                   scanf("%[^\n]",edited_name);
                    if(validate_name(edited_name))
                    {
                   // enter new name then we can copy 
                        strcpy(addressBook->contacts[index].name,edited_name);
                        printf("New name is edited succesfully\n");
                    }
                    else
                    {
                     printf("!error");
                    }
                   break;
            case 2:
                   printf("Enter the new_phone_no: ");
                   scanf("%s",edited_phone_no);
                   if(validate_phone(edited_phone_no,addressBook))
                   {
                   // enter new number then we can copy
                      strcpy(addressBook->contacts[index].phone,edited_phone_no);
                       printf("New phone number is edited succesfully\n");
                   }
                   else
                   {
                    printf("!error");
                   }
                   break;
            case 3:
                   printf("Enter the new_email_id: ");
                   scanf("%s",edited_email);
                   if(validate_email(edited_email,addressBook))
                   {
                   // enter new email then we can copy
                     strcpy(addressBook->contacts[index].email,edited_email);
                     printf("New email_id is edited succesfully!\n");
                   }
                   else
                    {
                     printf("!error");
                    }
                   break;
            default:
                   printf("Invalid choice please try again!");
                   break;
                 
        }
    }


}
void deleteContact(AddressBook *addressBook)
{
   // to get the index of contact so we are calling this function
   int res=searchContact(addressBook);
    if(res==0)
    {
        printf("contact not available to delete");
    }
    if(res==1)
    {
         int index;
         printf("Enter index number to delete the contact: ");
         scanf("%d",&index);
        for(int i=index;i<addressBook->contactCount-1;i++)
        {
            // in the place of index value we need to store index+1 value
            addressBook->contacts[i]=addressBook->contacts[i+1];
        }
        //decrease the count value
        (addressBook->contactCount)--;

    }
   
}
