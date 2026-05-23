#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
 
    int i;
    //open the file in write mode to copy the file
   FILE *contacts=fopen("contacts.csv","w");
   if(contacts==NULL)//if file is not opening its return null address
   {
    printf("File opening error for writing\n");
    return;
   }
   //copied and store the contact count value
   fprintf(contacts,"%d\n",addressBook->contactCount);
   for(i=0;i<addressBook->contactCount;i++)
   {
    //copied and store name,phone number and email in the list or array
   fprintf(contacts,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
   }
   fclose(contacts); 
   printf("Contacts saved successfully.\n");
 
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    int i=0;
   FILE *contacts=fopen("contacts.csv","r");
   if(contacts==NULL)
   {
    printf("File opening error for reading\n");
    return;
   }
   //read contact count from file
   fscanf(contacts,"%d\n",&(addressBook->contactCount));
   for(i=0;i<addressBook->contactCount;i++)
   {
    //read name,number and enail from the file
   fscanf(contacts,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
   }
   //printf("contact count:%d",addressBook->contactCount);
   fclose(contacts);

}
