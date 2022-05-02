#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Team
{
private:
    int ID;
    char *NAME;
public:
    Team(int id,const char *name)
        :ID(id)
    {
        NAME=new char[strlen(name)+1];
        strcpy(NAME,name);
    }
    Team()
    {}
    Team(const Team& copy)
        :ID(copy.ID)
        {
            NAME=new char[strlen(copy.NAME)+10];
            strcpy(NAME,copy.NAME);
        }
    void ShowTeamData()
    {
        cout<<ID<<"    "<<NAME<<endl;
    }
    ~Team()
    {
        delete []NAME;
    }

};
class TeamMgr
{
private:
    friend Team;
    Team Tlist[50];
    Team t1;
    Team t2;
    Team t3;
    Team t4;
    int index;
public:
    TeamMgr()
        :index(0),t1(1,"우리"),t2(2,"ABC"),t3(3,"가나다"),t4(4,"연합")

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
    void SerchTeam()
    {
        int k;
        cout<<"id:";
        cin>>k;
        cout<<"---------------------------------------------------"<<endl;
        cout<<"id             이름"<<endl;
        Tlist[k-1].ShowTeamData();
        cout<<"---------------------------------------------------"<<endl;

    }
};
class MainMenu
{
private:
    int sel;
public:
    int IssuMenu()
    {
        cout << endl;
		cout << "MainMenu" << endl;
		cout << "===============" << endl;
		cout << "1. Add New Team" << endl;
		cout << "2. Show All Team" << endl;
        cout << "3.Serching Team"<<endl<<endl;
		cout << "0. Quit" << endl;
		cout << "===============" << endl;
		cout << "Your choice? >> ";
		cin >> sel;
		return sel;
    }
};
class MainCtrl
{
public:
    MainCtrl()
    {
        TeamMgr Team_Mag;
        MainMenu Main_Menu;
        while(true)
        {
            switch(Main_Menu.IssuMenu())
            {
                case 1:Team_Mag.AddNewTeam();break;
                case 2:Team_Mag.ShowAllTeam();break;
                case 3:Team_Mag.SerchTeam();break;
                default: return;
            }
        }
    }
};
MainCtrl mc;
int main(void)
{

}

