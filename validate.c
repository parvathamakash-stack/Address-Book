#include "contact.h"
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int i=0;
//validate name should contain only alphabets
int validate_name(char *str)
{
    for(i=0;str[i]!='\0';i++)
    {
      if(!(islower(str[i])||isupper(str[i])||isspace(str[i])))
      {
        //invalid name
        return 0;
      }
      //valid name
      return 1;
    }
    
}
int validate_phone(char*str,AddressBook*addressBook)
{
  for(i=0;str[i];i++)
        {
          //contains only digits
           if(!isdigit(str[i]))
           {
            //invalid
            printf("Number should contain only digits.\n");
            return 0;
           }
        }  
        
  //phone number contains only 10 numbers
  if((strlen(str)!=10))
  {
    printf("phone number should contains only 10 digits\n");
    return 0;
  }
    for(int j=0;j<addressBook->contactCount;j++)
    {
      //check nuber already available
     if((strcmp(addressBook->contacts[j].phone,str)==0))
     {
      printf("Entered number is already exist\n");
       return 0;
     }
    }
    return 1;
        
        
}
        
    

int validate_email(char*str,AddressBook*addressBook)
{
   for(int j=0;j<addressBook->contactCount;j++)
   {
    //compare with exitsted list 
     if(strcmp(addressBook->contacts[j].email,str)==0)
     {
      printf("you entered email is already exist\n");
      return 0;
     }
   }
     i=0;
      while(str[i]!='\0')
      {
        if(isupper(str[i]))//check email contain uppercase letters
        {
        printf("Email id should be only lower case\n");
        return 0;//invalid
        }
        i++;
      }
      if(isdigit(str[0]))//first character is numeric is invalide
      {
        return 0;
      }
      
     char*str1=strchr(str,'@');
     char*str2=strchr(str,'.');
     // @ and . is manditory then first @ then . will come 
     if(str1&&str2 &&(str2>str1))
      {
        if (str1 != str && (str2 - str1) > 1 && *(str2 + 1) != '\0')
        {
         return 1;//valid
        }
      }
      printf("emails must contains '@' and '.'and in proper oder\n");
      return 0;
     
}