#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
int appnumber=1;
class gym{
private:
struct anode{                       //ADMIN LINK LIST
    int id;
    char pass[10];
    struct anode *admnxt= NULL;
}*adminhead = NULL;

struct status{                      //STATUS NODE
string stat;
int appno;
struct status *stnxt = NULL;
}*stahead = NULL;


struct unode{                       //USERS LINK LIST
    int uid;
    char user_name[10];
    char upass[10];
    struct unode *usr= NULL;
    string payment_status;

}*userhead = NULL;


struct tnode{
    int tdata;                       //TEMP USER LINK LIST
    char temp_fname[10],temp_lname[10];
    struct tnode *tempnxt = NULL;
}*temphead = NULL;
public:
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
	string syes = "Your Application has been approved.Please use application number as id and first name as password to login.";
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
	strcpy(u2->upass,t1->temp_fname);
	strcpy(u2->user_name,t1->temp_fname);
	userhead = u2;
	u2->usr= NULL;
	}
	else{
	    while(u1->usr != NULL)
	        u1=u1->usr;
	    u2->uid= t1->tdata;
	    strcpy(u2->upass,t1->temp_fname);
	    u1->usr = u2;
	    strcpy(u2->user_name,t1->temp_fname);
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

void view_status(int apno){				//View STATUS
struct status *s;
s = stahead;
if(s == NULL)
{
    cout<<"Application in Processing, Please Check again Later.\n";
}
else{
while(s!=NULL){
	if(s->appno == apno){
		cout<<s->stat<<"\n";
		return;
	}
    s = s->stnxt;
}
if(s->stnxt == NULL && s->appno !=apno)
cout<<"Application not found.\n";
}
}
int passcheck(int a)            //password cross check
{
    char ps[] = "pass123";
    struct anode *tem;
    tem = adminhead;
    char ch,passwo[10]={0};
    int i = 0,j;
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         passwo[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is presssed
       {
         cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
         i--;
       }
      else if(ch==13)
    {
         passwo[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }
        if(a == 12345){
        	if(strcmp(passwo,ps)==0){
        		cout<<passwo;
		        return 1;
    }
    else return 0;
	}
    while(tem != NULL){
        if(tem->id == a)
        {
            if(strcmp(passwo,tem->pass)==0)
                return 1;
        }
        tem = tem->admnxt;
    }
}

int userlog(int ide)              //user login
{
    int una,i=0,j;
    char up[10],ch,upas[10];
    struct unode *utem;
    utem = userhead;
    cout<<"Please Enter your password: ";
    for(i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         upas[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is presssed
       {
         cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
         i--;
       }
      else if(ch==13)
    {
         upas[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }
while(utem != NULL){
	if(utem->uid == ide)
	{
		if(strcmp(upas,utem->upass)==0)
		return 1;
	}
	utem = utem->usr;
}
return 0;
}
};
int main()                                  //MAIN FUNCTION.
{
	gym g;
    int ch,ach,tempappno;
    int tch;
    int aid;
    int aisetd = 12345;
    int adm;
    int id,pcheck = 0,swi;
    string apass = "pass123",eapass;
    while(1)
    {
        system("cls");
        cout<<"\t\t\t\t\t\tWelcome To FITNESSPLANET Gym\n\n\n";
        cout<<"\t\t\t\t\t1)Admin Menu\n";
        cout<<"\t\t\t\t\t2)User Menu\n";
        cout<<"\t\t\t\t\t3)Submit Application to join\n";
        cout<<"\t\t\t\t\t4)Exit Program\n";
        cin>>ch;
        switch(ch)
        {

            case 1:
                                        system("cls");

                                    cout<<"Enter Admin details to login\n";
                                    cout<<"ID: ";
                                    cin>>aid;
                                    cout<<"\nPassword: ";
                                    adm = g.passcheck(aid);
                                    cout<<"\n";
                                        if(adm == 1) {
                                            system("cls");
                                            cout<<"Successfully logged in.\n";
                                        do{
                                            cout<<"\n1)To create new admin user.\n";
                                            cout<<"2)To list all admin users.\n";
                                            cout<<"3)To view submitted applications.\n";
                                            cout<<"4)To accept/reject submitted applications\n";
                                            cout<<"5)To view user accounts.\n";
                                            cout<<"6)To return to main menu.\n";
                                                cin>>ach;
                                                switch(ach)
                                                    {
                                                    case 1:
                                                            g.admin_create();
                                                            break;
                                                    case 2:
                                                            g.list_admin();
                                                            break;
                                                    case 3:
                                                            g.admin_viewapp();
                                                            break;
                                                    case 4:
                                                            g.accept_app();
                                                            break;
                                                    case 5:
                                                            g.view_user();
                                                            break;
                                                    case 6:
                                                            cout<<"Returning to main menu.\n";
                                                                system("cls");
                                                                break;
                                                    default:
                                                            cout<<"Incorrect Choice.\n";
                                                    }
                                              }
                                            while(ach != 6);
                                        } else{
                                        cout<<"Incorrect Password, Please try again.\n";
                                        }
                                        break;
                case 2 :
										
										system("cls");
										cout<<"Welcome to the User Menu.\n";
										cout<<"Please Enter your details to login.\n\n";
										cout<<"ID: ";
										cin>>id;
										pcheck =  g.userlog(id);
										if(pcheck == 1){
											system("cls");
											cout<<"Login Successful.\n";
											do{
												cout<<"1)View Payment status.\n";
												cout<<"2)Send a message to the administrators.\n";
												cout<<"3)To View Membership Plan currently ongoing.\n";
												cout<<"4)To Update details.\n";
												cout<<"5)To exit to main menu.\n";
												cin>>swi;
												switch(swi){
													case 5:
														cout<<"Now Exiting, Goodbye!\n";
														break;
													default:
														cout<<"Incorrect Choice.\n";
												}
											}while(swi != 5);
										}
										else{
                                        cout<<"Incorrect Login Details, Please try again.\n";
									}
									break;
                case 3 :
                                        system("cls");
                                            do{
                                            cout<<"\n\n\t\t\t\tWelcome To FITNESSPLANET Gym.\n\n";
                                            cout<<"1)To Submit New Application\n";
                                            cout<<"2)To Check Status of application\n";
                                            cout<<"3)To exit to main menu.\n";
                                            cin>>tch;
                                                switch(tch){
                                                    case 1:
                                                            system("cls");
                                                            cout<<"HELLO!\nYou are submitting a new application.\n\n\n";
                                                            g.temp_application();
                                                            break;
                                                    case 2:
                                                    		cout<<"Please Enter Application Number: ";
                                                    		cin>>tempappno;
                                                    		g.view_status(tempappno);
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
