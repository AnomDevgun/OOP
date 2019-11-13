#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
int appnumber=1;
struct anode{                       //ADMIN LINK LIST
    int id;
    string pass;
    struct anode *admnxt= NULL;
}*adminhead = NULL;

struct status{                      //STATUS NODE
string stat;
int appno;
struct status *stnxt = NULL;
}*stahead = NULL;


struct unode{                       //USERS LINK LIST
    int uid;
    string user_name;
    string upass;
    struct unode *usr= NULL;
    string payment_status;

}*userhead = NULL;


struct tnode{
    int tdata;                       //TEMP USER LINK LIST
    string temp_fname,temp_lname;
    struct tnode *tempnxt = NULL;
}*temphead = NULL;


void admin_create()             //CREATE AN ADMIN ACC->ANODE
{
    struct anode *atemp = NULL,*newad = NULL;
    newad = new anode;
    atemp = adminhead;
    if(atemp == NULL)
    {
        cout<<"\nEnter a admin ID:\n";
        cin>>newad -> id;
        cout<<"Enter admin password for the user\n";
        cin>>newad -> pass;
        adminhead = newad;
        newad -> admnxt = NULL;
    }
    else{
        while(atemp -> admnxt != NULL)
        {
            atemp = atemp -> admnxt;
        }
        cout<<"\nEnter a admin ID:\n";
        cin>>newad -> id;
        cout<<"Enter admin password for the user\n";
        cin>>newad -> pass;
        atemp -> admnxt = newad;
        newad -> admnxt = NULL;

    }
    return;
}

void list_admin()                           //TO LIST ALL AVAILABLE ADMIN ACCOUNTS
{
    struct anode *atemp = NULL;
    atemp = adminhead;
    if(atemp == NULL)
    {
        cout<<"List is empty.\n";
    }
    else{
        do{
            cout<<"Admin id :"<<atemp->id<<"  Password: "<<atemp->pass<<"\n";
            atemp = atemp->admnxt;
        }
        while(atemp != NULL);

    }
}

int search_admin(int pid, string pas)          //SEARCH ADMIN LINKLIST
{
    int ret;
    struct anode *atemp = NULL;
    atemp = adminhead;
    if (atemp == NULL)
    {
        ret = 0;
    }
    else{
        while(atemp -> admnxt != NULL){
        if(atemp ->id == pid)
        {
            if(atemp ->pass == pas)
            {
                ret = 1;
            }
        }
        atemp = atemp -> admnxt;
    }
    if(atemp->id == pid && atemp ->pass== pas)
    {
        ret =1;
    }
    }
    return ret;
}

void admin_viewapp()                //FOR ADMIN TO VIEW SUBMITTED APPLICATIONS
{
    struct tnode *tuse = NULL;
    tuse = temphead;
    if(tuse == NULL)
    {
        cout<<"There are no new applications pending approval currently.\n";
    }
    else{
        while(tuse != NULL)
        {
            cout<<"Name: "<<tuse->temp_fname<<" "<<tuse->temp_lname<<"\n";
            cout<<"Application number: "<<tuse->tdata<<"\n\n";
            tuse = tuse->tempnxt;
        }
    }
}

void temp_application()                     //TO SUBMIT APPLICATION
{
    struct tnode *tuse = NULL,*newtemp = NULL;
    newtemp = new tnode;
    tuse = temphead;
    if(tuse == NULL)
    {
        cout<<"Please enter your first name.\n";
        cin>>newtemp -> temp_fname;
        cout<<"Please enter your last name.\n";
        cin>>newtemp -> temp_lname;
        newtemp -> tdata = appnumber;
        appnumber++;
        temphead = newtemp;
        newtemp -> tempnxt = NULL;
        cout<<"Successfully Submitted application,thank you.\nPlease check back in a few days to see status of your application using the number below\n\n";
    }
    else{
        while(tuse -> tempnxt != NULL)
        {
            tuse = tuse -> tempnxt;
        }
        cout<<"Please enter your first name.\n";
        cin>>newtemp -> temp_fname;
        cout<<"Please enter your last name.\n";
        cin>>newtemp -> temp_lname;
        newtemp -> tdata = appnumber;
        appnumber++;
        tuse -> tempnxt = newtemp;
        newtemp -> tempnxt = NULL;
    cout<<"\nSuccessfully Submitted application,thank you.\nPlease check back in a few days to see status of your application using the number below\n\n";
    }
    cout<<"The following is your application number,please note it down for future reference.\n";
    cout<<": "<< newtemp-> tdata;
return;
}

void accept_app(){                  //TO ACCEPT/REJECT APPLICATIONS
int sapp=0, cnt =0,yno=0;
string syes = "Your Application has been approved.Please use id and first name as password to login.";
string sno = "Your Application has been rejected.";
struct tnode *t1,*t2;
t1 = temphead;
t2 = temphead;
struct unode *u1,*u2;
u1 = userhead;
u2 = new unode;
struct status *s1,*s2;
s1 = stahead;
s2 = new status;
cout<<"Please Enter Application Number: ";
cin>>sapp;
if(t1 == NULL){
    cout<<"The Application List is empty.\n";
    return;
}
else{
while(t1!=NULL){
        if(t1->tdata == sapp){
                cout<<"Application Found.\n";
            cnt = 1;
            break;
        }
        t2 = t1;
        t1 = t1->tempnxt;
    }
if(cnt == 1)
{
cout<<"Enter 1 to accept or any other number to reject application.\n";
cin>>yno;
if(yno == 1){
if(u1 == NULL){
u2->uid = t1->tdata;
u2->upass = t1->temp_fname;
u2->user_name =t1->temp_fname;
userhead = u2;
u2->usr= NULL;
}
else{
    while(u1->usr != NULL)
        u1=u1->usr;
    u2->uid= t1->tdata;
    u2->upass= t1->temp_fname;
    u1->usr = u2;
    u2->user_name =t1->temp_fname;
    u2->usr = NULL;
}
if(s1 == NULL){
    s2->appno = t1->tdata;
    s2->stat = syes;
    stahead = s2;
    s2->stnxt= NULL;
}
else{
    while(s1->stnxt!=NULL){
        s1 = s1->stnxt;
    }
    s2->appno = t1->tdata;
    s2->stat = syes;
    s1->stnxt = s2;
    s2->stnxt=NULL;
}
if(t1 == temphead && t1->tempnxt==NULL){
    temphead = NULL;
    delete (t1);
}
else if(t1->tempnxt == NULL){
t2->tempnxt = NULL;
delete(t1);
}
else{
    t2= t1->tempnxt;
    t1->tempnxt = NULL;
    delete(t1);
}
}
else if(yno != 1){
if(s1 == NULL){
    s2->appno = t1->tdata;
    s2->stat = sno;
    stahead = s2;
    s2->stnxt= NULL;
}
else{
    while(s1->stnxt!=NULL){
        s1 = s1->stnxt;
    }
    s2->appno = t1->tdata;
    s2->stat = sno;
    s1->stnxt = s2;
    s2->stnxt=NULL;
}
if(t1 == temphead && t1->tempnxt==NULL){
    temphead = NULL;
    delete (t1);
}
else if(t1->tempnxt == NULL){
t2->tempnxt = NULL;
delete(t1);
}
else{
    t2->tempnxt= t1->tempnxt;
    t1->tempnxt = NULL;
    delete(t1);
}
}
}
else if(cnt == 0)
{
    cout<<"Search term not found.\n";
    return;

}
}
}

void view_user(){               //view user list.
struct unode *u;
u = userhead;
if(u == NULL)
{
    cout<<"User list is empty.\n";
}
else{
while(u!=NULL){
    cout<<"Name : "<<u->user_name<<"\n";
    u = u->usr;
}
}
}

void view_status(){
struct status *s;
s = stahead;
if(s == NULL)
{
    cout<<"User list is empty.\n";
}
else{
while(s!=NULL){
    cout<<"Status : "<<s->stat<<"\n";
    s = s->stnxt;
}
}
}

int main()                                  //MAIN FUNCTION.
{

    int ch,ach;
    int tch;
    int aid;
    int aisetd = 12345;
    int adm;
    string apass = "pass123",eapass;
    while(1)
    {
        system("cls");
        cout<<"\t\t\t\t\t\tWELCOME\n\n\n";
        cout<<"1)Admin Menu\n";
        cout<<"2)User Menu\n";
        cout<<"3)Submit Application to join\n";
        cout<<"4)Exit Program\n";
        cin>>ch;
        switch(ch)
        {

            case 1:
                                        system("cls");

                                    cout<<"Enter Admin details to login\n";
                                    cout<<"ID: ";
                                    cin>>aid;
                                    cout<<"\nPassword: ";
                                    cin>>eapass;
                                    cout<<"\n";
                                    adm = search_admin(aid,eapass);
                                        if((eapass == apass && aid == aisetd) ||(adm == 1) ){
                                            system("cls");
                                            cout<<"Successfully logged in.\n";
                                        do{
                                            cout<<"\n1)To create new admin user.\n";
                                            cout<<"2)To list all admin users.\n";
                                            cout<<"3)To view submitted applications.\n";
                                            cout<<"4)To accept/reject submitted applications\n";
                                            cout<<"5)To view user accounts.\n";
                                            cout<<"6)To view status.\n";
                                            cout<<"7)To return to main menu.\n";
                                                cin>>ach;
                                                switch(ach)
                                                    {
                                                    case 1:
                                                            admin_create();
                                                            break;
                                                    case 2:
                                                            list_admin();
                                                            break;
                                                    case 3:
                                                            admin_viewapp();
                                                            break;
                                                    case 4:
                                                            accept_app();
                                                            break;
                                                    case 5:
                                                            view_user();
                                                            break;
                                                    case 6:
                                                            view_status();
                                                            break;
                                                    case 7:
                                                            cout<<"Returning to main menu.\n";
                                                                system("cls");
                                                                break;
                                                    default:
                                                            cout<<"Incorrect Choice.\n";
                                                    }
                                              }
                                            while(ach != 7);
                                        } else{system("cls");
                                        cout<<"Incorrect Password, Please try again.\n";
                                        }
                                                        break;


                case 3:
                                        system("cls");
                                            do{
                                            cout<<"\n\n\t\t\t\tWelcome To NOMSWORLD Gym.\n\n";
                                            cout<<"1)To Submit New Application\n";
                                            cout<<"2)To Check Status of application\n";
                                            cout<<"3)To exit to main menu.\n";
                                            cin>>tch;
                                                switch(tch){
                                                    case 1:
                                                            system("cls");
                                                            cout<<"HELLO!\nYou are submitting a new application.\n\n\n";
                                                            temp_application();
                                                            break;
                                                    case 2:

                                                            break;
                                                    case 3:
                                                            system("cls");
                                                            break;
                                                    default:
                                                            cout<<"Invalid choice.\n";
                                                            }
                                            }while(tch != 3 );
                                            break;


            case 4:                                             //outermost switch
                                            cout<<"Now Exiting, Goodbye.\n";
                                            exit(0);
                                            system("cls");
                                            break;
            default:
                                            cout<<"Invalid Choice\n";

        }

    }

    return 0;
}
