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
    ~Mentee()
    {
        delete []name;
        delete []team;
       
    }
    void ShowClassData()
    {
        cout<<"---------------------------------------------------"<<endl;
        cout<<"id           name    age       team     interest   "<<endl;
        cout<<"---------------------------------------------------"<<endl;
        cout<<id<<"            "<<name<<"     "<<age<<"        "<<team<<"      "<<interest<<endl;
       
       
    }
    
};
int main(void)
{
  Mentee mentee(1,"Kim",21,"TTT","Blockchain");
  mentee.ShowClassData();
  

  return 0;
}