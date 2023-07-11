
#include <stdio.h>

int  str_to_num(int *num1,int *num2,char *sym,char *str);
void clear(int *num1,int *num2,char *sym,char *str,int *ans);
void print_ans(int*ans);
int find_length(int *num);
int neg_or_pos(int *num1,int *num2);
void add(int *ans,int *num1,int *num2);
void sub(int *ans,int *num1,int *num2);
void mult(int *ans,int *num1,int *num2);
void div(int r,int q,int *num1,int *num2);
int check_same(int *temp_num1,int *temp_num2);

int main(){
    char str[102],sym;
    int num1[50]={0},num2[50]={0},ans[100]={0};
    int i,valid,r=0,q=0;
    printf("\t\t\t\t 50 DIGIT CALCULATOR \n\n");
    printf("Type without spaces \n");
    printf("\n");
    printf("Examples:\n");
    printf("12345678967354748+9876546877687678678678678\n");
     printf("1234567899538783788374-8738478937937498237\n");
     printf("123478763783847239874*34837472384723894732\n");
     printf("1233489374983933498398095/3487384\n");
    printf("Type exit to quit ");
    printf("\n");
    printf("\n");
    while(1){
        printf("calc< ");
        scanf("%[^\n]%*c",str);
        if(str[0]=='e'&&str[1]=='x'&&str[2]=='i'&&str[3]=='t'){
            break;
        }
        printf("\n");
        valid=str_to_num(num1,num2,&sym,str);
        if(valid==1){

           if(sym=='+'){
                printf("=");
            add(ans,num1,num2);
            print_ans(ans);
           }
           if(sym=='-'){
               printf("=");
            int neg=0;
            neg=neg_or_pos(num1,num2);

            if(neg==1){
                sub(ans,num2,num1);
                printf("-");
            }
            else{
                sub(ans,num1,num2);
            }
           print_ans(ans);
           }
           if(sym=='*'){
                printf("=");
            mult(ans,num1,num2);
            print_ans(ans);
           }
           if(sym=='/'){
            div(r,q,num1,num2);
           }
        }
        clear(num1,num2,&sym,str,ans);
        printf("\n");
       
    }
}

//This function will print the result
void print_ans(int*ans){
    int fl=0;

    for(int i=0;i<50;i++){
            if(ans[i]!=0&&fl==0){
                fl=1;
            }
            if(fl==1){
        printf("%d",ans[i]);
            }
    }
    if(fl==0){
        printf("%d",0);
    }
}

//This function clears the data in input,output and resultant variables
void clear(int *num1,int *num2,char *sym,char *str,int *ans){
    int i;
        for(i=0;i<50;i++){
            num1[i]=0;
            num2[i]=0;
        }

         for(i=0;i<100;i++){

            ans[i]=0;
        }
        for(i=0;i<50;i++){
            str[i]='\0';
        }
        *sym='\0';
}

//This function converts the input string into integers and storing it in integers array
int str_to_num(int *num1,int *num2,char *sym,char *str){
    int i,j=49,l=0,fl=0;

    for(l=0;str[l];l++);
    l--;
    for(i=l;i>=0;i--){
            if(fl==0 && str[i]>='0' &&str[i]<='9'){
                num2[j]=str[i]-48;
                j--;
            }
            else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
                fl=1;
                *sym=(char)str[i];
                j=49;
                continue;
            }

            else if(fl==1 &&  str[i]>='0' &&str[i]<='9'){
                    num1[j]=str[i]-48;
                    j--;
            }
            else{

                printf("Invalid numbers");
                return 0;
            }
        }

    return 1;
}
//This function will find the digit count of an array 
int find_length(int *num){
    int fl=0,l=0;
    for(int i=0;i<50;i++){
            if(num[i]!=0&&fl==0){
                fl=1;
            }
            if(fl==1){
                l++;
            }
    }
    return l;
}

//This function will find the largest number
int find_largest(int *num1,int *num2){

    for(int i=0;i<50;i++){
        if(num1[i]>num2[i]){
            return 1;
        }
        if(num1[i]<num2[i]){
            return 0;
        }
    }
    return 1;
}
//This function will check whether both numbers are same or not
int check_same(int *temp_num1,int *temp_num2){
    for(int i=0;i<50;i++){
        if(temp_num1[i]!=temp_num2[i]){
            return 0;
        }
    }
    return 1;
}

//This function check whether a result is positive or negative in subtraction
int neg_or_pos(int *num1,int *num2){
    int l1,l2,neg=0,large;
    l1=find_length(num1);
    l2=find_length(num2);
    if(l1<l2){
        neg=1;
    }
    else if(l1==l2 &&num1[50-l1]<num2[50-l2]){
        neg=1;
    }
    else if(l1==l2 &&num1[50-l1]==num2[50-l2]) {
       large= find_largest(num1,num2);
       if(large==0){
        neg=1;
       }
       else{
        neg=0;
       }
    }
    else{
        neg=0;
    }
    return neg;
}

//This function performs addition
void add(int *ans,int *num1,int *num2){
    int i=49,carry=0,sum;
    while(i>=0){
        sum=num1[i]+num2[i]+carry;
        ans[i]=sum%10;
        carry=sum/10;
        i--;
    }
}

//This function performs subtraction
void sub(int *ans,int *num1,int *num2){
    int i=49,j=1,borrow,sub;
    while(i>=0){
         int   fl=0;
        j=1;borrow=0;
        if(num1[i]>=num2[i]){
        ans[i]=num1[i]-num2[i];
        }
        else if(num1[i]<num2[i]){
        ans[i]=num1[i]-num2[i]+10;
        borrow=1;
        }
        if(borrow==1&& num1[i-1]!=0){
            num1[i-1]--;
            fl=1;
        }

  this: if(borrow==1&& num1[i-1]==0 && num2[i-1]!=0 &&fl!=1){
            num1[i-j]=9;
            j++;
            goto this;

        }
    i--;
    }
}

//This function performs multiplation
void mult(int *ans,int *num1,int *num2){
    int carry=0,carry2=0,sum,i,j,k=49,z;
    for(i=49;i>=0;i--){
            z=k;
            carry=0;carry2=0;
        for(j=49;j>=0;j--){
            sum=(num1[j]*num2[i])+carry;
            carry=0;
            ans[z]=ans[z]+(((sum%10)+carry2));
            carry2=0;
            if(ans[z]>9){
                carry2=ans[z]/10;
                ans[z]%=10;
            }
            carry=sum/10;
            z--;
         if(z<0){
            break;
         }

        }
        k--;
        if(k<0){
            break;
        }
    }
}

//This function performs division
void div(int r,int q,int *num1,int *num2){
    int i,l1,l2,temp_num1[50]={0},temp_num2[50]={0},largest;
    int rem[50]={0},prev[50]={0},ansmult[50]={0},anssub[50]={0};
    int ptr,c=0,rp=0;
    l1=find_length(num1);
    l2=find_length(num2);
    ptr=50-l1+l2;

    for(i=0;i<l2;i++){
        temp_num1[50-l2+i]=num1[50-l1+i];
    }
    for(int j=0;j<50;j++){
        temp_num2[j]=num2[j];
    }
    while(ptr<=50){
        largest=find_largest(temp_num1,num2);
        if(largest==1){
            int mut[50]={0};
            mut[49]=1;
            int lal;
            while(1){
                for(int j=0;j<50;j++){

                    prev[j]=temp_num2[j];

                }
                for(int j=0;j<50;j++){
                    ansmult[j]=0;
                }
                mult(ansmult,num2,mut);
                for(int j=0;j<50;j++){
                    temp_num2[j]=ansmult[j];

                }
                lal=find_largest(temp_num1,temp_num2);
                if(lal==0){
                    int dup_temp1[50]={0};
                    for(int t=0;t<50;t++){
                      dup_temp1[t]=temp_num1[t];
                    }
                    sub(anssub,dup_temp1,prev);
                    mut[49]--;
                    rem[c]=mut[49];
                    c++;
                    break;
               }
                mut[49]++;

            }
            int subl=find_length(anssub);
             for(i=0;i<50;i++){
                    temp_num1[i]=0;

                }
            for(i=0;i<subl;i++){
                temp_num1[50-subl-1+i]=anssub[50-subl+i];


            }
            if(subl==0){
                for(i=0;i<50;i++){
                    temp_num1[i]=0;

                }
            }
            temp_num1[49]=num1[ptr];
            ptr++;
            rp=1;
        }
        else{
            int tl=find_length(temp_num1);
            for(int j=0;j<50;j++){
                temp_num2[j]=num2[j];
            }
            for(i=0;i<tl;i++){
                temp_num1[50-tl-1+i]=temp_num1[50-tl+i];
            }
            temp_num1[49]=num1[ptr];
            ptr++;
            if(rp>0){
            rem[c]=0;
            c++;
            }
            rp=1;;
        }

    }
    char sys='@';
    printf("Q=");
    for(i=0;i<c;i++){
        printf("%d",rem[i]);
    }
    printf("\n");
    printf("R=");
    int lf=0;
    for(i=0;i<50;i++){
         if(anssub[i]!=0||lf==1){
            printf("%d",anssub[i]);
            lf=1;
        }
    }
    if(lf==0){
        printf("%d",0); 
    }

}
