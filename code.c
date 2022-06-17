#include <stdio.h>
#include <string.h>
 
struct user {
    char firstName[50];
    int id;
    int pin;
    int balance;
} s[5];
 
int main() {
    int i;
    printf("Enter information of Users:\n");
    // storing information
    for (i = 0; i < 5; ++i) {
        s[i].id = i + 1;
        printf("\nFor id %d,\n", s[i].id);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter pin: ");
        scanf("%d", &s[i].pin);
        printf("Enter balance: ");
        scanf("%d", &s[i].balance);
    }
    
    while(1){
        int input,newid,newpin;
        printf("Enter 1 for withdrawl ,2 for depositing or 0 to exit: ");
        scanf("%d",&input);
        if(input==0){
            printf("Exit succesful");
            break;
        }else if(input==2){
            //depositing
                printf("Enter id: ");
                scanf("%d",&newid);
                printf("Enter Pin: ");
                scanf("%d",&newpin);
                if(newid>0&&newid<=5){
                    if(s[newid-1].pin==newpin){
                    printf("Enter how much you want to deposit?\n");
                    int deposit;
                    scanf("%d",&deposit);
                        s[newid-1].balance+=deposit;
                        printf("Depositing succesfull and current balance left: %d \n",s[newid-1].balance);
                    }else{
                        printf("Pin incorrect\n");
                    }
                
                }else{
                    printf("User ID not found\n");
                }
        }else{
            //withrawal
            printf("Enter id: ");
            scanf("%d",&newid);
            printf("Enter Pin: ");
            scanf("%d",&newpin);
            if(newid>0&&newid<=5){
                if(s[newid-1].pin==newpin){
                printf("Enter how much you want to withdraw?\n");
                int temp=0;
                scanf("%d",&temp);
                if(temp<s[newid-1].balance){
                    s[newid-1].balance-=temp;
                    printf("Withdraw succesfully and current balance left: %d \n",s[newid-1].balance);
                    }else{
                        printf("Insufficient balance \n");
                    }
                }else{
                    printf("Pin incorrect\n");
                }
            
            }else{
                printf("User ID not found\n");
            }
        }
        
        
    }
 
    return 0;
}
