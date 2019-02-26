#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

struct student{
    char name[30];
    int roll;
    int mark;
    int age;
    char data[30];
    char course[30];
    char adress[100];
    char number[30];
    char fees[30];

};

void modify(){


    struct student s;
    int f=0;
    char name1[30];
    fflush(stdin);
    printf("\tEnter the student name :\n");
    gets(name1);
    FILE *fp = fopen("data_base.txt","rb+");
    FILE *fp1 = fopen("temp.txt","wb+");
    rewind(fp);
    char ch;
    while(fread(&s,sizeof(s),1,fp)== 1){
        if(strcmp(s.name,name1)!=0){
            fwrite(&s,sizeof(s),1,fp1);
            }
        }
    fclose(fp);
    fclose(fp1);
    remove("data_base.txt");
    rename("temp.txt","data_base.txt");
    fflush(stdin);
    fp = fopen("data_base.txt","ab+");
    fseek(fp,0,SEEK_END);
    fflush(stdin);
    printf("\tEnter the student new name :\n");
    gets(s.name);
    fflush(stdin);
    printf("\tEnter the student roll number:\n");
    scanf("%d",&s.roll);
    printf("\tEnter the student age:\n");
    scanf("%d",&s.age);
    printf("\tEnter the student phone number:\n");
    scanf("%d",&s.number);
    fflush(stdin);
    printf("\tEnter the student adress:\n");
    gets(s.adress);
    printf("\tEnter the student sign up data:\n");
    gets(s.data);
    printf("\tEnter the cours name:\n");
    gets(s.course);
    printf("\tEnter the student final mark:\n");
    scanf("%d",&s.mark);
    fflush(stdin);
    printf("\tEnter if the fees are not paid or not\n");
    gets(s.fees);
    fwrite(&s,sizeof(s),1,fp);
    printf("\n");
    printf("\tStudent was modified\n");
    fclose(fp);
    }


void del_rec(){

    struct student s;
    int f=0;
    char name1[30];
    fflush(stdin);
    printf("\tEnter the student name :\n");
    gets(name1);
    FILE *fp = fopen("data_base.txt","rb");
    FILE *fp1 = fopen("temp.txt","wb");
    rewind(fp);
    char ch;
    while(fread(&s,sizeof(s),1,fp)== 1){
        if(strcmp(s.name,name1)!=0){
            fwrite(&s,sizeof(s),1,fp1);
            }
        }
    fclose(fp);
    fclose(fp1);
    remove("data_base.txt");
    rename("temp.txt","data_base.txt");
    fflush(stdin);
    printf("\tRecord deleted\n");

}

void search(){

    while(1){
    struct student s;
    int res, f =0;
    FILE *fp = fopen("data_base.txt","rb+");
    rewind(fp);
    char ch;
    char name2[30];
    fflush(stdin);
    printf("\tEnter the name you want to search:\n");
    gets(name2);
    while(fread(&s,sizeof(s),1,fp)== 1){
    res = strcmp(s.name,name2);
    if(res==0){
    printf("\n");
    printf("\tRecord found :\n");
    printf("\n");
    printf("\tName : %s\n",s.name);
    printf("\tRoll number :%d\n",s.roll);
    printf("\tAge : %d\n",s.age);
    printf("\tPhone number : %s\n",s.number);
    printf("\tAdress : %s\n",s.adress);
    printf("\tData : %s\n",s.data);
    printf("\tCourse : %s\n",s.course);
    printf("\tFinal mark %d\n",s.mark);
    printf("\tFees situation :%s\n",s.fees);
    printf("\n");
    f=1;

        }
    }
    if(f==0){
        fflush(stdin);
        printf("\trecord not found\n");
        }
        printf("\tTo make another search press Y and to exite press N :\n");
        scanf("%c",&ch);
       	 if(ch=='n'){
       	     break;
           }
        fflush(stdin);

    fclose(fp);
    }
}


void display(){
    struct student s;
    FILE *fp = fopen("data_base.txt","rb+");
    rewind(fp);
     while(fread(&s,sizeof(s),1,fp)== 1){
    printf("\t============================================\n");
    printf("\n");
    printf("\t Name : %s\n",s.name);
    printf("\t Roll number :%d\n",s.roll);
    printf("\t Age : %d\n",s.age);
    printf("\t Phone number : %s\n",s.number);
    printf("\t Adress : %s\n",s.adress);
    printf("\t Data : %s\n",s.data);
    printf("\t Course : %s\n",s.course);
    printf("\t Final mark %d\n",s.mark);
    printf("\t Fees situation :%s\n",s.fees);
    printf("\t============================================\n");
    printf("\n");
    }
    fclose(fp);
}

void add_rec(){
    struct student s;
    int i;
    char ch;
    FILE * fp;
    fp = fopen("data_base.txt","ab+");
    fseek(fp,0,SEEK_END);
    fflush(stdin);
    while(ch != 'n'){
    fflush(stdin);
    printf("\tEnter the student name:\n");
    gets(s.name);
    printf("\tEnter the student roll number:\n");
    scanf("%d",&s.roll);
    printf("\tEnter the student age:\n");
    scanf("%d",&s.age);
    fflush(stdin);
    printf("\tEnter the student phone number:\n");
    gets(s.number);
    fflush(stdin);
    printf("\tEnter the student adress:\n");
    gets(s.adress);
    fflush(stdin);
    printf("\tEnter the student sign up data:\n");
    gets(s.data);
    fflush(stdin);
    printf("\tEnter the course name:\n");
    gets(s.course);
    printf("\tEnter the student final mark:\n");
    scanf("%d",&s.mark);
    fflush(stdin);
    printf("\tEnter if the fees are not paid or not\n");
    gets(s.fees);
    fwrite(&s,sizeof(s),1,fp);
    printf("\n");
    printf("\tStudent was added\n");
    printf("\n");
    printf("\tIf you want to add another one press Y or press N to exit\n");
    fflush(stdin);
    scanf("%c",&ch);
       // if(ch=='n'){
        //    break;
         //   }

    fclose(fp);
        }

}

int main()
{
    while(1){
    printf("\t\t\tWelcome\n");
    printf("\t============================================\n");
    printf("\t1.Add a student\n");
    printf("\t2.Modify student record\n");
    printf("\t3.Delete student record\n");
    printf("\t4.List all students records\n");
    printf("\t5.search student record\n");
    printf("\t6.Exit\n");
    printf("\t============================================\n");
    printf("\tSelect your choice\n");
    int n;
    scanf("%d",&n);
    switch(n){
        case 1:
            add_rec();
            break;
        case 2:
            modify();
            break;
        case 3:
            del_rec();
            break;
        case 4:
            display();
            break;
        case 5:
             search();
             break;
        case 6:
            exit(1);
        default:
            printf("\tNah....\n");
            printf("\tChoice again\n");
            break;
        }
    }



       // search();
    return 0;
}
