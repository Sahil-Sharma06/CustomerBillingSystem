#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char name[100];
char date[10];
char phonum[10];
char n_iphone[10];
char Price_iphone[40];
char Price_samsung[40];
char Price_oneplus[40];
char Price_pixel[40];
char Price_xiaomi[40];
 char n_samsung[10],n_oneplus[10],n_pixel[10],n_xiaomi[10];
 char AmtIphone[10],AmtSamsung[10],AmtOneplus[10],AmtPixel[10],AmtXiaomi[10];
char *replaceWord(const char * str , const char * oldWord,const char * newWord){
    char * resultString;
    int i,count = 0;
    int newWordLength = strlen(newWord);
    int oldWordLength = strlen(oldWord);

    // Lets count the number of times old word occurs in the string
    for(i = 0 ; str[i] != '\0' ; i++){
        if(strstr(&str[i],oldWord) == &str[i]){
            count++;

            // Jump over this word 

            i += oldWordLength -1;
        }
    }

    // Making a new string to fit in the replaced word 
       resultString = (char *)malloc(i + count * (newWordLength - oldWordLength) + 1);
        
        i = 0;
        while(*str){
            // Compare the substring with result 
            if(strstr(str,oldWord) == str){
                strcpy(&resultString[i], newWord);
                i += newWordLength;
                str += oldWordLength;
            }
            else{
                resultString[i] = *str;
                i += 1;
                str += 1;
            }
        }

        resultString[i] = '\0';
        return resultString;
}

int main(){
    
    itemsNprice();

     FILE * ptr = NULL;
     FILE * ptr2 = NULL;
     ptr = fopen("bill.txt","r");
     ptr2 = fopen("genBill.txt","w");
     char str[5000];
     fgets(str,5000,ptr);
     printf("The given bill template was: %s\n",str);

    //  Call the replaceWord function and generate newStr
    char * newStr =  str;
    newStr = replaceWord(str,"{{header}}","-------HEENA CORPORATION-------\n\t No Exchange No Return\n\n");
    newStr = replaceWord(newStr,"{{item}}","Smart Phone");
    newStr = replaceWord(newStr,"{{outlet}}","Heena Corporation");
    newStr = replaceWord(newStr,"{{name}}",name);
    newStr = replaceWord(newStr,"{{phonum}}",phonum);    
    newStr = replaceWord(newStr,"{{iphoneqt}}",n_iphone);    
    newStr = replaceWord(newStr,"{{samsungqt}}",n_samsung);    
    newStr = replaceWord(newStr,"{{oneplusqt}}",n_oneplus);    
    newStr = replaceWord(newStr,"{{pixelqt}}",n_pixel);    
    newStr = replaceWord(newStr,"{{xiaomiqt}}",n_xiaomi);       
    newStr = replaceWord(newStr,"{{iphoneamt}}",Price_iphone);       
    newStr = replaceWord(newStr,"{{samsungamt}}",Price_samsung);       
    newStr = replaceWord(newStr,"{{oneplusamt}}",Price_oneplus);       
    newStr = replaceWord(newStr,"{{pixelamt}}",Price_pixel);       
    newStr = replaceWord(newStr,"{{xiaomiamt}}",Price_xiaomi);       

    newStr = replaceWord(newStr,"{{nl}}","\n\n");
    newStr = replaceWord(newStr,"{{n}}","\n");
    newStr = replaceWord(newStr,"{{tt}}","\t");
     printf("The actual bill generated is: %s\n",newStr);
     fprintf(ptr2,"%s",newStr);
     fclose(ptr);     
     fclose(ptr2);     


}
void template(){
    printf("----HEENA CORPORATION----\n");
    printf("No Exchange No Return");

}
static float TAX=0.18;

int PriceIphone = 1000,PriceSamsung = 800,PriceOneplus = 600,PricePixel = 750,PriceXiaomi = 500;
void itemsNprice(){
   
    printf("Enter your name:");
    scanf("%s",name);
    printf("Enter your Phone Number:");
    scanf("%s",phonum);
    printf("Enter number of quantities:\n");
    printf("Enter number of iphone you want:\n");
    scanf("%s",n_iphone);
    printf("Enter number of samsung you want:\n");
    scanf("%s",n_samsung);
    printf("Enter number of oneplus you want:\n");
    scanf("%s",n_oneplus);
    printf("Enter number of pixel you want:\n");
    scanf("%s",n_pixel);
    printf("Enter number of xiaomi you want:\n");
    scanf("%s",n_xiaomi);


    // Iphone Amount 
    int amtIphone=0;
    amtIphone=atoi(n_iphone);
    int amt1=0;
    amt1=amtIphone*1000;
    sprintf(Price_iphone,"%d",amt1);


    //  Samsung Amount
    int amtSamsung=0;
    amtSamsung= atoi(n_samsung);
    int amt2=0;
    amt2=amtSamsung*800;
    sprintf(Price_samsung,"%d",amt2);


    //  OnePlus Amount
    int amtOneplus=0;
    amtOneplus= atoi(n_oneplus);
    int amt3=0;
    amt3=amtOneplus*600;
    sprintf(Price_oneplus,"%d",amt3);


    // Pixel Amount
    int amtPixel=0;
    amtPixel= atoi(n_pixel);
    int amt4=0;
    amt4=amtPixel*750;
    sprintf(Price_pixel,"%d",amt4);


    // Xiaomi Amount
    int amtXiaomi=0;
    amtXiaomi= atoi(n_xiaomi);
    int amt5=0;
    amt5=amtXiaomi*1000;
    sprintf(Price_xiaomi,"%d",amt5);


}




