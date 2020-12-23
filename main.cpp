#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<windows.h>
#include<iomanip>
using namespace std;
struct node{
char hesaru[10];
char vilasa[10];
float total;
struct node* next;
struct node* prev;
};
struct node* head = NULL;
void frontpage()
{
    cout << "\n\n\t\t\t\t\t JSS SCIENCE AND TECHNOLOGY UNIVERSITY " << endl;
    cout<<"\t\t\t\t\t\t\t MYSURU"<<endl;
    cout<<"\n\t\t\t\t\t\t\b\b\b\t\b\b\b\b\b DATA STRUCTURES AND ALGORITHMS "<<endl;
    cout<<"\n\n\t\t\t\t\t\t ";
    char u[20] = "J R G R QUIZ SYSTEM";
    for(int i =0 ; i<19;i++)
    {
        cout<<u[i];
        if(i<8) Sleep(1000);
        if(i==11) Sleep(1000);
    }
    cout<<"\n\n\t\t\t\t\t\t\t\b\b\b submited by\n";
    cout<<"\n\t\t\t\t\t SL.NO         NAME              USN";
    Sleep(1000);
    cout<<"\n\n\t\t\t\t\t\t\b\b\b\b\b\b 1      GAGAN V PATIL     01JST18EC031";
    Sleep(1000);
    cout<<"\n\t\t\t\t\t\t\b\b\b\b\b\b 2      JAGADEESH M B     01JST18EC043";
    Sleep(1000);
    cout<<"\n\t\t\t\t\t\t\b\b\b\b\b\b 3      RAKSHIT           01JST18EC074";
    Sleep(1000);
    cout<<"\n\t\t\t\t\t\t\b\b\b\b\b\b 4      RAMESH            01JST19EC412";
    cout<<"\n\n\n";
    cout<<"\n\t\t\t\t\t\t Under the guidance of";
    cout<<"\n\t\t\t\t\t\t D R PAVITHRA";
    cout<<"\n\t\t\t\t\t\t Associate Professor";
    cout<<"\n\t\t\t\t\t\t JSSSTU MYSURU";
}
void screen()
{
    Sleep(1000);
    system("CLS");
    Sleep(300);
}
void tab()
{
    cout<<"\t\t\t\t\t";
}
void middle()
{
    cout<<"\n\n\n\n";
}

class contest
{
private:
    int id;
    float score;
    char name[20];
    char email[40];
    char pwd[30];
    char confirm_pwd[30];
    char recovery_key[30];
    char college[30];
    string uemail,password;
    char s[100],ans[4];
    int level;
    int q;
    int noj;
    int negative;


public:
    contest()
    { score=0; }
    void admin();
    void define();
    void display();
    void middle_display();
    void welcome();
    void sign_in();
    void sign_up();
    void validate(string,string);
    void recovery();
    void rules();
    void display_rank();
    void arrange_list(char*,char*,float z);
    void rewrite();
    void clear_list();
};
void contest ::admin()
{
    screen();middle();
    tab();cout<<"Enter 1.To see the standings  2.To edit the standings  3.To exit"<<endl;
    int choice;
    tab();cin>>choice;
    switch(choice)
    {
        case 1:
        {
           screen();middle();
           tab();cout<<"RANK"<<setw(20)<<"NAME"<<setw(20)<<"SCORE"<<setw(20)<<"EMAIL"<<endl;
           tab();cout<<"____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<endl;
           int stand = 1;
           fstream fr;
           fr.open("result.txt",ios::in|ios::app);
           fr.seekg(0);
           while(fr.eof()==0)
           {
            fr>>name;
            fr>>email;
            fr>>score;
            tab();cout<<stand<<setw(20)<<name<<setw(20-strlen(name))<<score<<setw(20-(sizeof(score)/4))<<email<<endl;
            stand=stand+1;
           }
           fr.close();
           middle();tab();cout<<"Enter 1 to continue"<<endl;
           tab();cin>>stand;
           admin();
        }
        case 2:
            {
               screen();middle();
               tab();cout<<"RANK"<<setw(20)<<"NAME"<<setw(20)<<"SCORE"<<setw(20)<<"EMAIL"<<endl;
               tab();cout<<"____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<endl;
               int stand = 1;
               fstream fs;
               fs.open("result.txt",ios::in|ios::app);
               fs.seekg(0);
               while(fs.eof()==0)
               {
                fs>>name;
                fs>>email;
                fs>>score;
                tab();cout<<stand<<setw(20)<<name<<setw(20-strlen(name))<<score<<setw(20-(sizeof(score)/4))<<email<<endl;
                stand=stand+1;
               }
               fs.close();
               tab();cout<<"Enter the standing position to be deleted"<<endl;
               int pos;
               tab();cin>>pos;
               screen();middle();
               fstream fr;
               fr.open("result.txt",ios::in|ios::app);
               fr.seekg(0);
               int enisu = 1;
               while(fr.eof()==0)
               {
                 fr>>name;
                 fr>>email;
                 fr>>score;
                 if(enisu != pos)
                 {
                    arrange_list(name,email,score);
                 }
                 enisu = enisu +1;

               }
               fr.close();
               fstream fclear;
               fclear.open("result.txt",ios::out|ios::trunc);
               fclear.close();
               node* temp = head;
               tab();cout<<"RANK"<<setw(20)<<"NAME"<<setw(20)<<"SCORE"<<setw(20)<<"EMAIL"<<endl;
               tab();cout<<"____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<endl;
               stand = 1;
               fstream fadd;
               fadd.open("result.txt",ios::out|ios::app);
               while(temp != NULL)
               {
                 int p = strlen(temp->hesaru);
                 int q = strlen(temp->vilasa);
                 fadd.seekg(0,ios::end);
                 fadd<<endl;
                 fadd<<temp->hesaru;
                 for(int i=0;i<26-p;i++)
                 fadd<<"\ ";
                 fadd <<temp->vilasa;
                 for(int i=0;i<40-q;i++)
                 fadd<<"\ ";
                 fadd<<temp->total;
                 tab();cout<<stand<<setw(20)<<temp->hesaru<<setw(20-strlen(temp->hesaru))<<temp->total<<setw(20-(sizeof(temp->total)/4))<<temp->vilasa<<endl;
                 temp = temp->next;
                 stand = stand+1;
               }
               fadd.close();
               clear_list();
            }
        case 3:
            {
                sign_in();
            }
    }
}
void contest :: welcome()
{
    screen();
    int choice;
    middle();
    tab();
    cout<<"J R G R QUIZ SYSTEM\n\n";
    tab();cout<<"Enter your choice"<<endl;
    tab();cout<<"1.SIGN IN              2.SIGN UP \n\n";
    tab();cout<<"Enter :  ";cin>>choice;
    switch(choice)
    {
    case 1:
        {
           sign_in();
           break;
        }
    case 2:
        {
            sign_up();
            break;
        }
    }
}
void contest :: rules()
{
    screen();middle();
    tab();cout<<"Welcome to  J R G R quiz system."<<endl<<endl;
    tab();cout<<"1.It has 2 Levels ."<<endl;
    tab();cout<<"2.Level 1 consists of a 5 question.s"<<endl;
    tab();cout<<"3.You will get +10 for correct answer and -5 for wrong answers."<<endl;
    tab();cout<<"4.Level 2 has 10 questions , which is divided into round 1 and round 2."<<endl;
    tab();cout<<"5.Each round have 5 questions you will get +10 for correct answer and -2 for wrong answers."<<endl;
    tab();cout<<"6.And in Level 2 participants has to score atleast 30 in round 1 to qualify for round 2."<<endl;
    tab();cout<<"7.In both the levels total marks will be 50"<<endl;
    tab();cout<<"8.At the end result will be displayed"<<endl<<endl;
    tab();cout<<"----SELECT THE LEVEL----"<<endl;
    tab();cout<<"ENTER    1.Level1     2.Level2"<<endl;
    tab();cin>>level;
    switch(level)
    {
    case 1:
        {
            negative = 5;
            q = 5;
            noj = 6;
            define();
            display();
        }
    case 2:
        {
            negative = 2;
            q = 10;
            noj=3;
            define();
            score = score/2;
            display();
        }
    }
}
void contest :: sign_in()
{
    int choice;
    screen();
    middle();tab();cout<<"SIGN IN"<<endl<<endl;
    tab();cout<<"Enter your email id : "<<endl;
    tab();cin>>uemail;
    cout<<endl;
    tab();cout<<"Enter your password : "<<endl;
    tab();cin>>password;
    cout<<endl<<endl;
    tab();cout<<"----Enter the choice----"<<endl<<endl;
    tab();cout<<"1.LOGIN           2.forgot password"<<endl;
    tab();cout<<"ENTER    :      ";cin>>choice;
    switch (choice)
        {
        case 1:
            {
                validate(uemail,password);
                break;
            }
        case 2:
            {
                recovery();
                break;
            }
        }
}
void contest :: validate(string umail , string password)
{
    if(umail == "admin" && password == "1234")
    {
        admin();
    }
    int cnt = 0;
    fstream f4;
    f4.open("details.txt",ios::in|ios::app);
    f4.seekg(0);
    while(f4.eof()==0)
    {
        f4>>name;
        f4>>email;
        f4>>pwd;
        f4>>college;
        if(email == umail && password == pwd)
        {
            rules();
            cnt = cnt+1;
            break;
        }
    }
    if(cnt == 0)
    {
      tab();cout<<"OOPS!! Your email or password is incorrect"<<endl;
      tab();cout<<"--Enter  1.TRY AGAIN        2.EXIT"<<endl;
      int choice;
      tab();cin>>choice;
      switch(choice)
      {
      case 1:
        {
            sign_in();
        }
      case 2:
        {
            screen();
        }
      }
    }
}
void contest :: recovery()
{
    char umail[30];
    char garbage[30];
    screen();middle();
    tab();cout<<"Enter your email"<<endl;
    tab();cin>>umail;
    tab();cout<<"Enter your recover key"<<endl;
    tab();cin>>garbage;
    int cnt = 0;
    fstream f4;
    f4.open("details.txt",ios::in|ios::app);
    f4.seekg(0);
    while(f4.eof()==0)
    {
        f4>>name;
        f4>>email;
        f4>>pwd;
        f4>>college;
        f4>>recovery_key;
        if(~strcmp(email,umail) && ~strcmp(garbage,recovery_key))
        {
            cnt = cnt+1;
            middle();tab();
            cout<<"Your password is :  "<<pwd<<endl<<endl;
            tab();cout<<"Enter 1 to continue "<<endl;
            tab();cin>>cnt;
            sign_in();
            break;
        }
    }
    if(cnt == 0)
    {
      tab();cout<<"OOPS!! NO ACCOUNT FOUND"<<endl;
      tab();cout<<"--Enter  1.TRY AGAIN        2.EXIT"<<endl;
      int choice;
      tab();cin>>choice;
      switch(choice)
      {
      case 1:
        {
            sign_in();
        }
      case 2:
        {
            screen();
        }
      }
    }
}
void contest :: sign_up()
{
    screen();middle();
    tab();cout<<"SIGN UP"<<endl<<endl;
    tab();cout<<"Enter your name."<<endl;
    tab();cin>>name;
    tab();cout<<"Enter your college name."<<endl;
    tab();cin>>college;
    tab();cout<<"Enter your email id :"<<endl;
    tab();cin>>email;
    cout<<endl;tab();cout<<"Enter your Password"<<endl;
    tab();cin>>pwd;tab();cout<<"Confirm your password"<<endl;
    tab();cin>>confirm_pwd;
    tab();cout<<"Enter account recover key "<<endl;
    tab();cin>>recovery_key;
    fstream f1;
    f1.open("details.txt",ios::out|ios::app);
    int p = strlen(name);
    int q = strlen(email);
    int r = strlen(pwd);
    int s = strlen(college);
    if(~strcmp(pwd,confirm_pwd))
    {
        fstream f1;
        f1.open("details.txt",ios::out|ios::app);
        f1.seekg(0,ios::end);
        f1<<endl;
        f1<<name;
        for(int i=0;i<26-p;i++)
        f1<<"\ ";
        f1 <<email;
        for(int i=0;i<40-q;i++)
        f1<<"\ ";
        f1 <<pwd;
        for(int i=0;i<25-r;i++)
        f1<<"\ ";
        f1 <<college;
        for (int i=0;i<30-s;i++)
        f1<<"\ ";
        f1<<recovery_key;
        f1.close();
        cout<<endl<<endl;
        tab();cout<<"Enter     1.CONFIRM      2.EXIT"<<endl;
        int choice;
        tab();cin>>choice;
        switch(choice)
        {
        case 1:
            {
                sign_in();
                break;
            }
        case 2:
            {
                break;
            }
        }


    }
    if(~strcmp(pwd,confirm_pwd))
    {
        cout<<pwd<<endl<<confirm_pwd<<endl;
        tab();cout<<"Password doesnot matched"<<endl;
    }

}
void  contest :: define()
{
   ifstream file;
   char a[4];
   file.open("QP.txt");
   srand(time(NULL));
   score = 0;
   while(q)
   {
    screen();
    q--;
    int n = rand()%noj;
    middle();
    for(int j =0 ; j< (n*6) ;j++)
   {
      file.getline(s,100);
   }

   int i =5;
   while(i)
   {
    i--;
    file.getline(s,100);
    tab();cout<<s<<endl;
   }

   file.getline(a,4);
   cout<<"\n\n";tab();cout<<"Select your answer : ";
   cin>>ans;

   if(~strcmp(a,ans))
   {
        score = score + 10;
        cout<<"\n\n";tab();cout<<" Your answer is correct";
   }
   else
    {
       cout<<"\n\n";tab(); cout<<" Wrong answer";
       score = score-negative;
    }
    screen();
    Sleep(500);
    if(level==2 && q==5)
    {
        middle_display();
    }
   }

   file.close();
}
void contest :: middle_display()
{
    screen();middle();
    tab();cout<<"----FIRST ROUND RESULT----"<<endl<<endl;
    tab();cout<<"You got "<<score<<"  in first half"<<endl<<endl;
    if(score>35)
    {
        tab();cout<<"CONGRATULATIONS!! YOU HAVE SELECTED FOR SECOND ROUND"<<endl;
        middle();tab();
        int garbage;
        cout<<"Enter 1 to continue"<<endl;
        tab();cin>>garbage;
    }
    else
    {
        tab();cout<<"SORYY!!! YOU HAVE NOT QUALIFIED FOR SECOND ROUND"<<endl;
        middle();tab();
        int garbage;
        cout<<"Enter 1 to continue"<<endl;
        tab();cin>>garbage;
        welcome();
    }
}
void contest :: display()
{
    screen();
    middle();
    tab();cout<<"--FINAL RESULT--"<<endl;
    tab();cout<<"Hello "<<name<<" you have got total "<<score<<" marks,out of 50\n";
    tab();cout<<"-------CONGRATULATIONS-----"<<endl;
    fstream fs;
    fs.open("result.txt",ios::out|ios::app);
    int p = strlen(name);
    int q = strlen(email);
    fs.seekg(0,ios::end);
    fs<<endl;
    fs<<name;
    for(int i=0;i<26-p;i++)
    fs<<"\ ";
    fs <<email;
    for(int i=0;i<40-q;i++)
    fs<<"\ ";
    fs<<score;
    fs.close();
    middle();
    tab();cout<<"Enter 1 to continue"<<endl;
    int garbage;
    tab();cin>>garbage;
    display_rank();
}
void contest :: display_rank()
{
    fstream fr;
    fr.open("result.txt",ios::in|ios::app);
    fr.seekg(0);
    while(fr.eof()==0)
    {
      fr>>name;
      fr>>email;
      fr>>score;
      arrange_list(name,email,score);
    }
    fr.close();
    fstream fclear;
    fclear.open("result.txt",ios::out|ios::trunc);
    fclear.close();
    node* temp = head;
    screen();middle();
    tab();cout<<"RANK"<<setw(20)<<"NAME"<<setw(20)<<"SCORE"<<setw(20)<<"EMAIL"<<endl;
    tab();cout<<"____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<setw(20)<<"_____"<<endl;
    int stand = 1;
    fstream fadd;
    fadd.open("result.txt",ios::out|ios::app);
    while(temp != NULL)
    {

        int p = strlen(temp->hesaru);
        int q = strlen(temp->vilasa);
        fadd.seekg(0,ios::end);
        fadd<<endl;
        fadd<<temp->hesaru;
        for(int i=0;i<26-p;i++)
        fadd<<"\ ";
        fadd <<temp->vilasa;
        for(int i=0;i<40-q;i++)
        fadd<<"\ ";
        fadd<<temp->total;
        tab();cout<<stand<<setw(20)<<temp->hesaru<<setw(20-strlen(temp->hesaru))<<temp->total<<setw(20-(sizeof(temp->total)/4))<<temp->vilasa<<endl;
        temp = temp->next;
        stand = stand+1;
    }
    fadd.close();
    clear_list();

}
void contest :: arrange_list(char* x,char* y,float z)
{
    if(head == NULL)
    {
        head = new node;
        strcpy(head->hesaru,x);
        strcpy(head->vilasa,y);
        head->total = z;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            struct node* temp2 = temp;
            temp = temp->next;
            if(temp2->next == NULL)
            {
                struct node*temp1 = new node;
                temp2->next = temp1;
                temp1->prev = temp2;
                strcpy(temp1->hesaru , x);
                strcpy(temp1->vilasa,y);
                temp1->total = z;
                temp1->next = NULL;
                break;
            }
            if(z>temp2->total)
            {
                struct node* temp1 = new node;
                if(temp2->prev == NULL)
                {
                    head = temp1;
                    strcpy(temp1->hesaru , x);
                    strcpy(temp1->vilasa,y);
                    temp1->total = z;
                    temp1->prev = NULL;
                    temp2->prev = temp1;
                    temp1->next = temp2;
                    break;
                }
                else
                {
                    strcpy(temp1->hesaru , x);
                    strcpy(temp1->vilasa,y);
                    temp1->total = z;
                    temp1->next = temp2;
                    temp1->prev = temp2->prev;
                    (temp2->prev)->next = temp1;
                    temp2->prev = temp1;
                    break;
                }
            }
        }
    }
}
void contest:: clear_list()
{
    node* temp = head;
    while(temp != NULL)
    {
        node* temp1 = temp->next;
        free(temp);
        temp = temp1;
    }
    head = NULL;
    cout<<endl<<endl;
    middle();tab();tab();cout<<"THANK YOU"<<endl;
    middle();tab();cout<<"Enter 1 to continue"<<endl;
    int garbage;tab();cin>>garbage;
    welcome();
}
int main()
{
    system("color f0");
    frontpage();
    contest r;
    r.welcome();
    getch();
}
