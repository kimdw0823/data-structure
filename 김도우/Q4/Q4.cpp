#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Team
{
private:
    int id;
    char *name;
public:
    Team(int myid,const char* myname):id(myid)
    {
        name=new char[strlen(myname)+1];
        strcpy(name,myname);
    }
    Team()
    {}
    Team(const Team& copy)
        :id(copy.id)
        {
            name=new char[strlen(copy.name)+10];
            strcpy(name,copy.name);
        }
    void ShowTeamData()
     {
        cout<<id<<"    "<<name<<endl;
     }    
    

};
class TeamMgr
{
private:
    Team Tlist[50];
    Team t1;
    Team t2;
    Team t3;
    Team t4;
    int index;
public:
    TeamMgr():index(0),t1(1,"T-1"),t2(2,"T-2"),t3(3,"T-3"),t4(4,"T-4")
    {   
        
        Tlist[index++]=t1;
        Tlist[index++]=t2;
        Tlist[index++]=t3;
        Tlist[index++]=t4;

    }
     void AddNewTeam()
    {
        int id=index+1;
        char name[100];
        cout<<"id:"<<index+1<<endl;
        cout<<"name:";
        cin>>name;
        Team t(id,name);
       
        if(index<50)
        {
            Tlist[index++]=t;
        }
        else
        {
            cout<<"팀 저장 공간이 꽉참"<<endl;
        }
        
    }
    void ShowAllTeam()
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"id             이름"<<endl;
        cout<<"---------------------------------------------------"<<endl;
         for(int i=0;i<index;i++)
        {
            Tlist[i].ShowTeamData();
        }
        cout<<"---------------------------------------------------"<<endl;
    }

};
class Member
{
protected:
    friend Team;
    int id;
    char *name;
    Team *team;
public:
    Member(int myid,const char*myname,int myteamid,const char*myteamname):id(myid)
    {
        team =new Team(myteamid,myteamname);
        name=new char[strlen(myname)+1];
        strcpy(name,myname);
    }
    void ShowMemberData()
    {

    }
    ~Member()
    {
        delete []name;
        delete []team;
    }
};
class Mentee:public Member
{
private:
    int age;
    char interest[100];
public:
    Mentee(int myage,char *myinterest,int myid,const char*myname,int myteamid,const char*myteamname)
        :age(myage),Member(myid,myname,myteamid,myteamname)
    {
        strcpy(interest,myinterest);
    }
  

};
class Mentor:public Member
{
private:
    char *company;
public:
    Mentor(int myid,const char*myname,const char*mycompany,int myteamid,const char*myteamname)
        :Member(myid,myname,myteamid,myteamname)
    {
        company=new char[strlen(myname)+1];
        strcpy(company,mycompany);
    }
};
class MemberMgr
{
private:
    friend Member;
    friend Mentee;
    friend Mentor;
    friend Team;
    friend TeamMgr;
    Member *Mlist[100];
    int index;
public:
    MemberMgr():index(0)
    {   
        Mentee *mentee1=new Mentee(21,"Blockchain",1,"Kim",1,"T-1");
        Mlist[index++]=mentee1;
        Mentor *Mentor1=new Mentor(2,"김멘토","보안컴",2,"T-2");
        Mlist[index++]=Mentor1;
        Mentee *mentee2=new Mentee(22,"web",3,"이멘티",1,"T-1");
        Mlist[index++]=mentee2;
        Mentee *mentee3=new Mentee(23,"C++",4,"James",2,"T-2");
        Mlist[index++]=mentee3;
        Mentor *Mentor2=new Mentor(5,"Chris","Alcom",1,"T-1");
    }
    void AddNewMentee()
    {
        int id=index+1;
        char* name;
        cout<<"<<Add a new Mentee>>"<<endl;
        cout<<"-id:"<<id<<endl;
        cout<<"name";
        cin>>name;
        TeamMgr tm;
        tm.ShowAllTeam();
        

    }
};
class MainMenu{
private:
	int sel;
public:
	int IssueMenu(){
		cout << endl;
		cout << "MainMenu" << endl;
		cout << "===============" << endl;
		cout << "1. Add new Mentee" << endl;
		cout << "2. Add new Mentor" << endl;
		cout << "3. Add new Team" << endl<<endl;
		cout << "4. Display all mentees" << endl;
		cout << "5. Display all mentors" << endl;
		cout << "6. Display all members" << endl << endl;
        cout << "7. Display members by team"<<endl;
		cout << "9. clear the screen" << endl;
		cout << "0. Quit" << endl;
		cout << "===============" << endl;
		cout << "Your choice? >> ";
		cin >> sel;
		return sel;
	}
};
class MainCtrl{
public:
	MainCtrl(){
		TeamMgr tMgr;
		MemberMgr mMgr;
		MainMenu mm;
		while (1){
			switch (mm.IssueMenu()){
			case 1:
                mMgr.AddNewMentee();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 9:
				system("clear");
				break;
			case 0:
				return;
			default:
				
				break;
			}
		}
	}
};

