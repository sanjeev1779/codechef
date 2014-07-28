#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

struct phonebook {
    int id;
    char name[20];
    char surname[20];
    char phone[20];
} phonelist[20];

int cnt=0; // record counter
int cnt_del=0; // deleted record counter

int generate_my_id() {

    //srand((unsigned)time(0));
    return rand() % 20000 + 1500; // random user id

}

void func_add() {

    char yes_no;

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t ADD A PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    if(cnt!=20) { // if struct is full give error
        cout<<"Index...........................: "<<cnt<<endl; // pk
        cout<<"Id..............................: ";
        phonelist[cnt].id=generate_my_id(); // random id
        cout<<phonelist[cnt].id<<endl;
        cout<<"Name............................: ";
        cin>>phonelist[cnt].name;
        cout<<"Surname.........................: ";
        cin>>phonelist[cnt].surname;
        cout<<"Phone...........................: ";
        cin>>phonelist[cnt].phone;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        cout<<"Do you want to save this person ? (Y)es-(N)o : ";
        cin>>yes_no;
            if(yes_no=='Y' || yes_no=='y') {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout<<"Person is saved !!!"<<endl;
                cnt++; // increase record counter
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout<<"Person is not saved !!!"<<endl; // delete the record
                    for(int j=cnt; j<10; j++) { // scroll the array
                                phonelist[j].id=phonelist[j+1].id;
                                strcpy(phonelist[j].name,phonelist[j+1].name);
                                strcpy(phonelist[j].surname,phonelist[j+1].surname);
                                strcpy(phonelist[j].phone,phonelist[j+1].phone);
                    }
            }
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<"Phonebook is full you can't add any person anymore !!! "<<endl;
    }
} // add person

void func_del() {

    char sch_name[20];
    char yes_no=' ';

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t DELETE A PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Please enter a name : ";
    cin>>sch_name;
        for(int i=0; i<20; i++) {
                if(strcmp(phonelist[i].name,sch_name)==0) { // compare two char array
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is found !!!"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout<<"Index...........................: "<<i<<endl;
                    cout<<"Id..............................: "<<phonelist[i].id<<endl;
                    cout<<"Name............................: "<<phonelist[i].name<<endl;
                    cout<<"Surname.........................: "<<phonelist[i].surname<<endl;
                    cout<<"Phone...........................: "<<phonelist[i].phone<<endl;
                    int dlt_index=i;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    cout<<"Do you want to delete this person (Y)es-(N)o : ";
                    cin>>yes_no;
                        if(yes_no=='Y' || yes_no=='y') {
                            for(int j=dlt_index; j<10; j++) { // scroll the array
                                i=dlt_index-1;
                                phonelist[j].id=phonelist[j+1].id;
                                strcpy(phonelist[j].name,phonelist[j+1].name);
                                strcpy(phonelist[j].surname,phonelist[j+1].surname);
                                strcpy(phonelist[j].phone,phonelist[j+1].phone);
                            }
                            cnt--; // decrease the counter
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout<<"Person is deleted !!!"<<endl;
                            break;
                        }
                }
                else if(i==19 && yes_no==' ') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is not found !!!"<<endl;
                }
        }

} // delete person

void func_lst() {

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t LIST ALL PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        for(int i=0; i<cnt; i++) {
                cout<<"Index..: "<<i<<" Id..: "<<phonelist[i].id<<"\t"<<phonelist[i].name<<"\t\t"<<phonelist[i].surname<<"\t\t"<<phonelist[i].phone<<endl;
            }
        if(cnt==0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout<<"There is no any record !!!"<<endl;
            }
} // list person

void func_sch() {

    char sch_name[20];

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t SEARCH A PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Please enter a name : ";
    cin>>sch_name;
        for(int i=0; i<20; i++) {
                if(strcmp(phonelist[i].name,sch_name)==0) { // compare two char array
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is found !!!"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout<<"Index...........................: "<<i<<endl;;
                    cout<<"Id..............................: "<<phonelist[i].id<<endl;;
                    cout<<"Name............................: "<<phonelist[i].name<<endl;
                    cout<<"Surname.........................: "<<phonelist[i].surname<<endl;
                    cout<<"Phone...........................: "<<phonelist[i].phone<<endl;
                    break;
                }
                else if(i==19) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is not found !!!"<<endl;
                }
        }
} // search person

void func_upd() {

    char sch_name[20];
    char upd_line;

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t UPDATE A PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Please enter a name : ";
    cin>>sch_name;
        for(int i=0; i<20; i++) {
                if(strcmp(phonelist[i].name,sch_name)==0) { // compare two char array
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is found !!!"<<endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout<<"    Index...........................: "<<i<<endl; // pk
                    cout<<"    Id..............................: "<<phonelist[i].id<<endl;; // id
                    cout<<"1-) Name............................: "<<phonelist[i].name<<endl;
                    cout<<"2-) Surname.........................: "<<phonelist[i].surname<<endl;
                    cout<<"3-) Phone...........................: "<<phonelist[i].phone<<endl;
                    tryagain:
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    cout<<"Which line you want to change 1-3 : ";
                    cin>>upd_line;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                        switch(upd_line) {
                            case '1' : {
                                    cout<<"Please enter new name : ";
                                    cin>>phonelist[i].name;
                                    break;
                                     }
                            case '2' : {
                                    cout<<"Please enter new surname : ";
                                    cin>>phonelist[i].surname;
                                    break;
                                     }
                            case '3' : {
                                    cout<<"Please enter new phone number : ";
                                    cin>>phonelist[i].phone;
                                    break;
                                     }
                            default : {
                                goto tryagain; // out of range
                                      }
                        }
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout<<"Person is updated !!!"<<endl;
                        break;
                }
                else if(i==19) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"Person is not found !!!"<<endl;
                }
        }
} // update person

void func_srt() {

    int temp_id;
    char temp_name[20];
    char temp_surname[20];
    char temp_phone[20];

             for (int i = (cnt-cnt_del - 1); i > 0; i--) {
                for (int j = 1; j <= i; j++) {
                     if (phonelist[j-1].id > phonelist[j].id) { // ascending...
                          temp_id = phonelist[j-1].id;
                          strcpy(temp_name,phonelist[j-1].name);
                          strcpy(temp_surname,phonelist[j-1].surname);
                          strcpy(temp_phone,phonelist[j-1].phone);

                          phonelist[j-1].id = phonelist[j].id;
                          strcpy(phonelist[j-1].name,phonelist[j].name);
                          strcpy(phonelist[j-1].surname,phonelist[j].surname);
                          strcpy(phonelist[j-1].phone,phonelist[j].phone);

                          phonelist[j].id = temp_id;
                          strcpy(phonelist[j].name,temp_name);
                          strcpy(phonelist[j].surname,temp_surname);
                          strcpy(phonelist[j].phone,temp_phone);
                    }
                 }
             }

    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t SORT ALL PERSON"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        for(int i=0; i<cnt-cnt_del; i++) {
                cout<<"Index..: "<<i<<" Id..: "<<phonelist[i].id<<"\t"<<phonelist[i].name<<"\t\t"<<phonelist[i].surname<<"\t\t"<<phonelist[i].phone<<endl;
            }
        if(cnt==0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout<<"There is no any record !!!"<<endl;
            }
}

int main() {

    start:
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"******************************************************************"<<endl;
    cout<<"\t\t\t PHONEBOOK MAIN MENU"<<endl;
    cout<<"******************************************************************"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Please Select Action 1 to 7"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<"1-) ADD a person to phonebook"<<endl;
    cout<<"2-) DELETE a person from phonebook"<<endl;
    cout<<"3-) LIST data in phonebook"<<endl;
    cout<<"4-) SEARCH person from phonebook"<<endl;
    cout<<"5-) UPDATE a person from phonebook"<<endl;
    cout<<"6-) SORT date in phonebook"<<endl;
    cout<<"7-) QUIT program"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"Choice >> ";
    char choice;
    cin>>choice;
        switch(choice) {
            case '1' : {
                func_add(); break;
                     }
            case '2': {
                func_del(); break;
                    }
            case '3' : {
                func_lst(); break;
                     }
            case '4' : {
                func_sch(); break;
                     }
            case '5' : {
                func_upd(); break;
                     }
            case '6' : {
                func_srt(); break;
                     }
            case '7' : {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout<<"All record will be lost !!! Are you sure want to exit ? (Y)es-(N)o : ";
                char yes_no;
                cin>>yes_no;
                    if(yes_no=='Y' || yes_no=='y') {
                        return 0;
                        }
                    else {
                        goto start;
                        }
                       }
            default : {
                goto start;
                      }
            }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    system("PAUSE");
    goto start;
}
