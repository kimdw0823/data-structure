#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Mentee
{
private:
    int id;
    char* name;
    int age;
    char * team;
    char interest[100];
public:
    Mentee(int MTid,const char*MTname,int MTage,const char*MTteam,const char*MTinterest)
        :id(MTid),age(MTage)
    {
        name=new char[strlen(MTname)+1];
        strcpy(name,MTname);
        team=new char[strlen(MTteam)+1];
        strcpy(team,MTteam);
        
        strcpy(interest,MTinterest);
    }
    
     void ShowMenteeData()
    {
       
        cout<<id<<"    "<<name<<"      "<<age<<"      "<<team<<"           "<<interest<<endl;
        cout<<"---------------------------------------------------"<<endl;
       
    }
    ~Mentee()
    {
        delete []name;
        delete []team;
        
    }
    
    
};
class MenteeMgr
{
private:
    friend Mentee;
    Mentee* Mlist[100];
    int index;
    
public:
    MenteeMgr()
        :index(0)
    {

    }
    void AddNewMentee()
    {
        int id;
        char name[10];
        int age;
        char team[10];
        char interest[100];
        id=index+1;
        cout<<"id:"<<id<<endl;
        cout<<"name:";
        cin>>name;
        cout<<"age:";
        cin>>age;
        cout<<"team:";
        cin>>team;
        cout<<"interest:";
        cin>>interest;
        Mentee *m=new Mentee(id,name,age,team,interest);
        if(AddMentee_2(m)==1)
        {
            Mlist[index++]=m;
        }
    

    }
    bool AddMentee_2(Mentee *s)
    {
		if (index >= 100){
			return false;
		}else{
			return true;
		}
	}
    void ShowAll()
    {   
        cout<<"---------------------------------------------------"<<endl;
        cout<<"id   name     age   team     interest   "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        for(int i=0;i<index;i++)
        {
            Mlist[i]->ShowMenteeData();
        }
        cout<<"---------------------------------------------------"<<endl;
    }

    ~MenteeMgr()
    {
        for(int i=0;i<index;i++)
        {
            delete Mlist[i];
        }
    }
    

};
class MainMenu {
private:
	int sel;
public:
	int IssueMenu() {
		cout << endl;
		cout << "MainMenu" << endl;
		cout << "===============" << endl;
		cout << "1. Add New Mentee" << endl;
		cout << "2. Show All Mentee" << endl << endl;
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
		MenteeMgr Mentee_mag;
		MainMenu Main_Menu;
		while (true)
		{
			switch (Main_Menu.IssueMenu())
			{
			case 1: Mentee_mag.AddNewMentee(); break;
			case 2: Mentee_mag.ShowAll(); break;
			case 0: return;
			default: return;
			}
		}
	}
};
MainCtrl mc;

int main(void)
{   
    
}