#include<iostream>
#include<fstream>
using namespace std;


class temp {
    string rollNum,name,fName,address,search;
    fstream file;
    public:
        void addStu();
        void viewStu();
        void searchStu();
}obj;


int main(){
    char choice;
    cout<<"---------------------------"<<endl;
    cout<<"1-Add student record"<<endl;
    cout<<"2-view student record"<<endl;
    cout<<"3-Search student record"<<endl;
    cout<<"4-Exit";
    cout<<"---------------------------";
    cin>>choice;

    switch (choice)
    {
    case '1':
        obj.addStu();
        break;
    
    case '2':
        obj.viewStu();
        break;
    
    case '3':
        obj.searchStu();
        break;
    case '4':
        return 0;
        break;
    
    default:
        cout<<"Invalid choice......!";
        break;
    }




    
}

void temp :: addStu() {
    cout<<"Enter Student roll Number:: ";
    getline(cin,rollNum);
    cout<<"Enter Student Name:: ";
     getline(cin,name);
    cout<<"Enter Student Father Name:: ";
     getline(cin,fName);
    cout<<"Enter Student Address:: ";
     getline(cin,address);

    file.open("stuData.txt",ios :: out | ios :: app);
    file<<rollNum<<"*"<<endl;
    file<<name<<"*"<<endl;
    file<<fName<<endl;
    file.close();
}

void temp :: viewStu(){

    file.open("stuData.txt", ios::in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    while (!file.eof())
    {
        cout<<"\n";
        cout<<"Student roll number ::"<<rollNum<<endl;
        cout<<"Student name ::"<<name<<endl;
        cout<<"Student Father Name ::"<<fName<<endl;
        cout<<"Student address ::"<<address<<endl;

        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
    
}


void temp :: searchStu(){

    cout<<"Enter student roll Number"<<endl;
    getline(cin,search);

    file.open("stuData.txt", ios:: in);
    getline(file,rollNum,'*');
    getline(file,name,'*');
    getline(file,fName,'*');
    getline(file,address,'\n');
    while (!file.eof())
    {
        if(rollNum == search){
            cout<<endl;
            cout<<"student roll number :: "<<rollNum<<endl;
            cout<<"student name :: "<<name<<endl;
            cout<<"student Father Name :: "<<fName<<endl;
            cout<<"student address :: "<<address<<endl;

        }
        getline(file,rollNum,'*');
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');
    }
    file.close();
    
}