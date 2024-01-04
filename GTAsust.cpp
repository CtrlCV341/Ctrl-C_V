#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define loop(i, x, y) for (int i = x; i < y; i++)
#define eline cout << endl;
#define build cout << '#'
#define road cout << '*'
#define space cout << ' '
const int width = 150;  // Random
const int height = 50; // Random
int userDest;
using namespace std;
struct position
{
    int x;
    int y;
};
struct PlayerInfo{
    char name[50];
    // int destArr[2];
    int finalPos[2];
    int visitedArr[13];
    int totalStep;
};

void create(const char* filename,char userName[], int vis){
    ofstream f(filename,ios::binary|ios::app);
    if(!f.is_open()){cout<<"Sorry! Cannot open the file."<<endl;return;}
    PlayerInfo pi;
    // strcpy(pi.name,s);
    int traverse=0;
    // while(piMain.name!='\0'){
    //     pi.name[traverse]=s[traverse];
    //     traverse++;
    // }
    // pi.name=piMain.name;
    strcpy(pi.name,userName);
    // cout<<pi.name<<endl;
    // pi.destArr[0]=destPos.x;pi.destArr[1]=destPos.y;
    pi.finalPos[0]=62;pi.finalPos[1]=80;
    for(int i=0;i<13;i++)pi.visitedArr[i]=0;
    pi.visitedArr[vis]=1;
    pi.totalStep=0;
    f.write(reinterpret_cast<const char*>(&pi),sizeof(pi));
    // cout<<pi.name<<endl;
    cout<<"Hey! Welcome."<<endl;
    f.close();
}

bool playerFind(const char* filename,char username[],position &playerPos,position &destPos){
    //cout<<"H"<<endl;
    ifstream f(filename,ios::binary);
    vector<int> visVec;
    if(!f.is_open()){cout<<"Sorry! Cannot open the file."<<endl;return false;}
    PlayerInfo pi;
    string userNamePi="";
    // int traverse=0;

        // cout<<piMain.name<<endl;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        // cout<<pi.name<<endl;
        if(strcmp(pi.name,username)==0){
            cout<<userNamePi<<"you've been found"<<endl;
            // cout<<"name: "<<s<<" x: "<<pi.destArr[0]<<" y: "<<pi.destArr[1]<<" currX: "<<pi.finalPos[0]<<" currY: "<<pi.finalPos[1]<<endl;
            // cout<<endl;
            for (int i = 0; i < 13; i++) {
                if(pi.visitedArr[i]!=0)visVec.push_back(i);
            }
            cout<<"you're last destination was: "<<visVec.back()<<endl;
            cout<<"so far you've visited: "<<endl;
            for(int i=0;i<visVec.size();i++)cout<<visVec[i]<<endl;
            cout<<"you've travelled "<<pi.totalStep<<" steps"<<endl;
            cout<<"In you're last game you were at position: "<<pi.finalPos[0]<<" "<<pi.finalPos[1]<<endl;
            cout<<"Do you want to Continue your last game?"<<endl;
            cout<<"1.Yes"<<endl;
            cout<<"2.No"<<endl;
            int userChoice;
            cout<<"Your choice: ";
            cin>>userChoice;
            if(userChoice==1){
                userDest=visVec.back();
                playerPos={pi.finalPos[0],pi.finalPos[1]};
                // playerPos.x=pi.finalPos[0];
                // playerPos.y=pi.finalPos[1];
            }
            else {
                cout << "Where do you want to go?" << endl;
                cout << "1.IICT" << endl;
                cout << "2.Ladies Hall" << endl;
                cout << "3.Central Library" << endl;
                cout << "4.A-building" << endl;
                cout << "5.D-building" << endl;
                cout << "6.Cafeteria" << endl;
                cout << "7.E-building" << endl;
                cout << "8.C-building" << endl;
                cout << "9.B-building" << endl;
                cout << "10.Shahid Minar" << endl;
                cout << "11.Auditorium" << endl;
                cout << "12.Shahporan Hall" << endl;
                cout << "You're Option: ";
                cin>>userDest;
                cout<<"Do you want to start from the position You left Or you want to start at the gate?"<<endl;
                cout<<"1.start position where i left"<<endl;
                cout<<"2.from gate"<<endl;
                cout<<"Your choice: ";
                cin>>userChoice;
                if(userChoice==1){
                    playerPos={pi.finalPos[0],pi.finalPos[1]};
                }
                else{
                    playerPos={62,80};
                }
            }
            switch (userDest)
            {
                case 1:
                    destPos = {51,68}; // i
                    break;
                case 2:
                    destPos = {16,59}; // h
                    break;
                case 3:
                    destPos = {51,49}; // L
                    break;
                case 4:
                    destPos = {90,43}; // a
                    break;
                case 5:
                    destPos = {36,40}; // d
                    break;
                case 6:
                    destPos = {77,30}; // cafe
                    break;
                case 7:
                    destPos = {94,30}; // e
                    break;
                case 8:
                    destPos = {97,21}; // c
                    break;
                case 9:
                    destPos = {62,25}; // b
                    break;
                case 10:
                    destPos = {22,21}; // m
                    break;
                case 11:
                    destPos = {34,12}; // o
                    break;
                case 12:
                    destPos = {80,4}; // s
                    break;
                default:
                    cout<<"Does Not Exist"<<endl;
                    break;
            }
            f.close();
            return true;
        }
    }
    cout<<"Hey, Welcome!"<<endl;
    f.close();
    return false;
}


void updatePlayerInfo(const char* filename,char userName[],const position &PlayerPos,int userDest){
    fstream f(filename,ios::binary|ios::in|ios::out);
    if(!f.is_open()){cout<<"Sorry! Cannot open the file."<<endl;return;}
    PlayerInfo pi;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        if(strcmp(pi.name,userName)==0){
            streampos position = f.tellp();
            position -= sizeof(pi);
            f.seekp(position, ios::beg);
            pi.finalPos[0]=PlayerPos.x;pi.finalPos[1]=PlayerPos.y;
            pi.visitedArr[userDest]=1;
            f.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
            //cout<<"Player Updated!"<<endl;
            f.close();
            return;
        }
    }
    cout<<"playe not found!"<<endl;
    f.close();
    return;
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // copied, used to set the position of the cursor
}
void disAvator(const position &playerPos,string s)
{
    gotoxy(playerPos.x, playerPos.y);
    cout << s;

    //gotoxy(destPos.x, destPos.y);
    //cout << "()";
}

void mapSUST()
{
    loop(i, 0, 84) /// shahporan hall
    {
        if (i > 76)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 90) /// shahporan hall
    {
        if (i == 77 || i == 83)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 84) /// shahporan hall
    {
        if (i > 76)
            cout << 'S';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall road
    {
        if (i < 60)
            cout << ' ';
        else if (i == 129)
            cout << '*';
        else
            cout << '*';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else if (i == 129)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
    loop(i, 0, 130) /// shahporan hall
    {
        if (i == 60)
            cout << '*';
        else if (i == 129)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    cout << endl;
    loop(j, 0, 2) /// tennis court turning road
    {
        for (int i = 0; i < 65; i++)
        {
            if (i == 60)
                cout << '*';
            else if (i > 63)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
    loop(i, 0, 120) /// auditorium and central field
    {
        if (i > 32 && i < 37)
            cout << 'O';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else if(i>=80 && i<=100)
            cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 120) /// auditorium
    {
        if (i == 33 || i == 36)
            cout << 'O';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else if(i==80 || i==100)
        cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 120) /// auditorium
    {
        if (i > 32 && i < 37)
            cout << 'O';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
            else if(i==80 || i==100)
        cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 120) /// auditorium front road
    {
        if (i > 32 && i < 61)
            cout << '*';
        else if (i == 64)
            cout << '*';
            else if(i==80 || i==100)
        cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 125) /// auditorium front road
    {
        /*if (i == 64)
            cout << '*';*/
         if(i==80 || i==100)
        cout<<'Z';
        else if(i>=64 && i<80)
            cout<<'*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 125) /// auditorium front road
    {
        if (i > 32 && i < 61)
            cout << '*';
       /*else if(i==64)
        cout<<'9';*/
        else if (i < 33)
            cout << ' ';
            else if(i==80 || i==100)
        cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 125) /// audit to minar
        {
            if (i == 60 || i == 64)
                cout << '*';
                 else if(i==80 || i==100)
        cout<<'Z';
        else if (i > 64 && i < 80)
            cout << '*';
            else
                cout << ' ';

        }
        eline;
    loop(j, 0, 2)
    {
        loop(i, 0, 125) /// audit to minar
        {
            if (i == 60 || i == 64)
                cout << '*';
                 else if(i==80 || i==100)
        cout<<'Z';
            else
                cout << ' ';

        }
        eline;
    }
    loop(i, 0, 125) ///  s minar
    {
        if (i > 20 && i < 25)
            cout << 'M';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
             else if(i>=80 && i<=100)
        cout<<'Z';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 65) ///  s minar
    {
        if (i == 21 || i == 24)
            cout << 'M';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 120) ///  s minar
    {
        if (i > 20 && i < 25)
            cout << 'M';
        else if (i == 60)
            cout << '*';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
   loop(i, 0, 120)
    {
        if (i > 60 && i < 64)
            cout << ' ';
        else if (i < 21)
            cout << ' ';
        else if(i>84 && i<95)cout<<'*';
        else if(i>64 && i<85)cout<<' ';
        else
            cout << '*';
    }
    eline;
    loop(i, 0, 100) ///  s minar road
    {
        if (i == 64)
            cout << '*';

        else if(i==85)cout<<'*';
        else
            cout << ' ';
    }
    eline;
   loop(i, 0, 120)
    {
        if(i>=21 && i<=60)cout<<'*';
        else if(i==64 || i==85)cout<<'*';
        else if(i>=89)cout<<'*';
        else cout<<' ';
    }
    eline;
    loop(i, 0, 100) /// road + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i > 64 && i<70)
            cout << 'B';
        else if(i==85 || i==89)cout<<'*';
        else if(i>=95 && i<=99)
            cout<<'C';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// road + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 65 || i == 69)
            cout << 'B';
             else if(i==95 || i==99)cout<<'C';
        else if(i==85 || i==89)cout<<'*';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 100; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 65 || i == 69)
            cout << 'B';
        else if (i == 85 || i==89)
            cout << '*';
        else if(i==95 || i==99)
            cout<<'C';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 100; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 65 && i <= 69)
            cout << 'B';
        else if (i == 85)
            cout << '*';
        else if(i==89)
            cout<<'*';
        else if(i>94)
            cout<<'C';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 120; i++) /// road + c building roof + b building
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 85 || i == 89)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 130; i++) /// road + c building roof
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 85 || i == 89)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    for (int i = 0; i < 100; i++)
    {
        if (i == 60)
            cout << '*';
        else if (i > 63 && i<=85)
            cout << '*';
            else if (i >= 89)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 1) /// s minar to chetona
    {
        loop(i, 0, 65)
        {
            if (i == 60)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    for (int i = 0; i < 100; i++) /// chetona to E
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// E build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 92 && i <= 96)
            cout << 'E';
        else if (i >= 75 && i <= 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// e build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 92 || i == 96)
            cout << 'E';
        else if (i == 75 || i == 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// e build
    {
        if (i == 60 || i == 64)
            cout << '*';
        else if (i == 92 || i == 96)
            cout << 'E';
        else if (i >= 75 && i <= 78)
            cout << 'T';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// E build
    {
        if (i == 60 || i == 64)
            road;
        else if (i >= 92 && i <= 96)
            cout << 'E';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2)
    {
        loop(i, 0, 65) /// chetona to arjuntola
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 100) /// d building and a building
    {
        if (i >= 30 && i <= 34)
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 88 && i <= 92)
            cout << 'A';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i == 30 || i == 34)
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << 'A';
        else if (i > 34 && i < 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i == 30 || i == 34)
            cout << 'D';
        else if (i == 64)
            cout << '*';
        else if (i == 88 || i == 92)
            cout << 'A';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// d building and a building
    {
        if (i >= 30 && i <= 34)
            cout << 'D';
        else if (i == 60 || i == 64)
            cout << '*';
        else if (i >= 88 && i <= 92)
            cout << 'A';
        else if (i > 34 && i < 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 100) /// a building to library
    {
        if (i == 60)
            cout << '*';
        else if (i >= 64 && i < 96)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90)
    {
        if (i == 60)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 96) /// a building road
    {
        if (i == 60)
            cout << '*';
        else if (i > 63)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// a building to library
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// library
    {
        if (i >= 45 && i <= 49)
            cout << 'L';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i == 45 || i == 49)
            cout << 'L';
        else if (i > 49 && i < 61 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i == 45 || i == 49)
            cout << 'L';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// library
    {
        if (i >= 45 && i <= 49)
            cout << 'L';
        else if (i > 49 && i < 61 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 3) /// library to chottor
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// chottor
    {
        if (i >= 50 && i < 61)
            cout << '*';
        else if (i > 63 && i < 75)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// chottor
    {
        loop(i, 0, 90)
        {
            if (i == 50 || i == 74)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
        else if (i == 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << 'H';
        else if (i >= 14 && i <= 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << 'H';
        else if (i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
        else if (i >= 14 && i <= 50 || i == 74)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// chottor
    {
        loop(i, 0, 90)
        {
            if (i == 50 || i == 74)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// chottor
    {
        if (i >= 50 && i < 61)
            cout << '*';
        else if (i > 63 && i < 75)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// lICT to chottor
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 90) /// IICT
    {
        if (i >= 41 && i <= 49)
            cout << 'I';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << 'I';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << 'I';
        else if (i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i == 41 || i == 49)
            cout << 'I';
        else if (i > 49 && i <= 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 90) /// IICT
    {
        if (i >= 41 && i <= 49)
            cout << 'I';
        else if (i == 60 || i == 64)
            cout << '*';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 9) /// kilo road
    {
        loop(i, 0, 90)
        {
            if (i == 60 || i == 64)
                cout << '*';
            else
                cout << ' ';
        }
        eline;
    }
    loop(i, 0, 76)
    {
        if (i >= 50 && i <= 60)
            cout << 'G';
        else if (i >= 64 && i <= 74)
            cout << 'G';
        else
            cout << ' ';
    }


    // gotoxy(82,4);   //s
    // cout<<"*";
    gotoxy(33,12);      //o
    cout<<"*";
    gotoxy(21,21);      //m
    cout<<"*";
    // gotoxy(77,30);      //cafe
    // cout<<"*";
     gotoxy(119,21);  //c
     cout<<"*";
    gotoxy(99,30);  //e
    cout<<"*";
    // gotoxy(36,40);      //d
    // cout<<"*";
    gotoxy(95,43);      //a
    cout<<"*";
    // gotoxy(51,49);      //L
    // cout<<"*";
    // gotoxy(16,59);      //h
    // cout<<"*";
    // gotoxy(51,68);      //i
    // cout<<"*";
    gotoxy(62,80);      //maingate
    cout<<"*";
}
bool obstacle(const position &newPos)
{
    loop(i, 60, 130){ /// shahporan hall road
        if(newPos.x>=i&&newPos.y==3)return true;
    }
    if((newPos.x==60||newPos.x==129)&&newPos.y==4)return true;  /// shahporan hall
    loop(i, 64, 130){    /// shahporan hall
        if(newPos.x>=i&&newPos.y==5)return true;
    }
    loop(i,5,81){   /// two roads
        if((newPos.x==60||newPos.x==64)&&newPos.y==i&&(newPos.y!=12||newPos.x==64)&&(newPos.y!=21||newPos.x==64)&&(newPos.y!=30||newPos.x==60)&&(newPos.y!=40||newPos.x==64)&&(newPos.y!=43||newPos.x==60)&&(newPos.y!=49||newPos.x==64)&&(newPos.y!=68||newPos.x==64)&&(newPos.y>=63||newPos.y<=54))return true;
    }
    loop(i, 0, 61){     /// auditorium,minar,D-building,library,IICT,golchottor
        if(newPos.x==i&&(newPos.y==11||newPos.y==13||newPos.y==20||newPos.y==22||newPos.y==39||newPos.y==41||newPos.y==48||newPos.y==50||newPos.y==67||newPos.y==69||newPos.y==54||newPos.y==63))return true;
    }
    loop(i,64,100){     // C-building,A-building, gol chottor
        if(newPos.x==i&&(newPos.y==29||newPos.y==31||newPos.y==42||newPos.y==44||newPos.y==54||newPos.y==63)){return true;}
    }
    loop(i,54,64){      // golchottor
        //if(i==59)continue;
        if((newPos.x==50||newPos.x==74)&&(newPos.y==i)&&(newPos.y!=59||newPos.x==74))return true;
    }
    loop(i,0,51){   //hall
        if(newPos.x==i&&(newPos.y==58||newPos.y==60))return true;
    }
    if((newPos.x==33&&newPos.y==12)||(newPos.x==34&&newPos.y==21)||(newPos.x==99&&newPos.y==30)||(newPos.x==35&&newPos.y==40)||(newPos.x==95&&newPos.y==43)||(newPos.x==50&&newPos.y==49)||(newPos.x==15&&newPos.y==59)||(newPos.x==50&&newPos.y==68)||(newPos.x==62&&newPos.y==81))return true;
    return false;
}

bool finalDest(const position &playerPos, const position &destPos)
{
    if (playerPos.x == destPos.x && playerPos.y == destPos.y)
        return true;
    return false;
}

void showPath(const position &playerPos, const position &destPos){
    if(playerPos.x==61||playerPos.x==62||playerPos.x==63||destPos.y==playerPos.y){
        if(playerPos.y>destPos.y)cout<<"Go Upwards";
        else if(playerPos.y<destPos.y)cout<<"Go Downwards";
        else{
            if(destPos.x<playerPos.x)cout<<"Go Left";
            else cout<<"Go Right";
        }
    }
    else{
        if(playerPos.x<61)cout<<"Go Right";
        else cout<<"Go Left";
    }
}





int main()
{
    system("mode con: lines=200 cols=700");
    // string filename="PlayerData.bin";
    position playerPos = {62,80};
    position destPos;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    gotoxy(width / 2+22, height / 2);
    cout << "Hey! Welcome to GTAsust game app";
    gotoxy(width / 2, height / 2+1);
    cout << "**********************************************************************************" << endl;gotoxy(width / 2, height / 2+2);
    cout << "This game is about Shahjalal University of Science and Technology(SUST) where you" << endl;gotoxy(width / 2, height / 2+3);
    cout << "can travel at any point of the university and reach to your desired destination" << endl;
    cout << endl;
    gotoxy(width / 2, height / 2+5);
    system("pause");
    system("cls");
    char userName[50];
    cout<<"please enter your name: ";
    cin.getline(userName,sizeof(userName));
    bool found=false;
    found=playerFind("PlayerData.bin",userName,playerPos,destPos);

    system("pause");
    system("cls");






    if(!found){
        cout<<"Welcome first time to our game"<<endl;
        cout << "Where do you want to go?" << endl;
        cout << "1.IICT" << endl;
        cout << "2.Ladies Hall" << endl;
        cout << "3.Central Library" << endl;
        cout << "4.A-building" << endl;
        cout << "5.D-building" << endl;
        cout << "6.Cafeteria" << endl;
        cout << "7.E-building" << endl;
        cout << "8.C-building" << endl;
        cout << "9.B-building" << endl;
        cout << "10.Shahid Minar" << endl;
        cout << "11.Auditorium" << endl;
        cout << "12.Shahporan Hall" << endl;
        cout << "You're Option: ";

        cin >> userDest;

        switch (userDest)
        {
            case 1:
                destPos = {51,68}; // i
                break;
            case 2:
                destPos = {16,59}; // h
                break;
            case 3:
                destPos = {51,49}; // L
                break;
            case 4:
                destPos = {90,43}; // a
                break;
            case 5:
                destPos = {36,40}; // d
                break;
            case 6:
                destPos = {77,30}; // cafe
                break;
            case 7:
                destPos = {94,30}; // e
                break;
            case 8:
                destPos = {97,21}; // c
                break;
            case 9:
                destPos = {62,25}; // b
                break;
            case 10:
                destPos = {22,21}; // m
                break;
            case 11:
                destPos = {34,12}; // o
                break;
            case 12:
                destPos = {80,4}; // s
                break;
            default:
                cout<<"Does Not Exist"<<endl;
                break;
        }
        create("PlayerData.bin",userName,userDest);
    }



    system("pause");


    system("cls");
    mapSUST();
    disAvator(destPos,"()");
    disAvator(playerPos,"@");
    if(abs(playerPos.y-destPos.y)<=49)disAvator(destPos,"()");
    while (true)
    {

        position newPos = playerPos;

        if (_kbhit())
        {
            char key = _getch();

            if (key == 80)
            {
                newPos.y++;
            }
            else if (key == 72)
            {
                newPos.y--;
            }

            else if (key == 77)
            {
                newPos.x++;
            }

            else if (key == 75)
            {
                newPos.x--;
            }
            if (!obstacle(newPos))
            {
                gotoxy(playerPos.x, playerPos.y);
                cout << " ";
                //gotoxy(160,playerPos.y);
                 //cout << "           ";
                playerPos = newPos;

                if(playerPos.y<=40){
                        gotoxy(184,31);cout<<"                           ";gotoxy(184,0);cout<<"                           ";gotoxy(184,0);cout<<"Your Position x: "<<playerPos.x<<" "<<"y: "<<playerPos.y;
                        gotoxy(184,33);cout<<"                           ";gotoxy(184,2);cout<<"Destination x: "<<destPos.x<<" "<<"y: "<<destPos.y;
                        gotoxy(184,35);
                        cout<<"                           ";
                        gotoxy(184,4);
                        cout<<"                           ";
                        gotoxy(184,4);
                        showPath(playerPos,destPos);
                }
                if(playerPos.y>40){
                        gotoxy(0,80);cout<<"";gotoxy(184,31);cout<<"Your Position x: "<<playerPos.x<<" "<<"y: "<<playerPos.y;
                        gotoxy(184,33);cout<<"Destination x: "<<destPos.x<<" "<<"y: "<<destPos.y;
                        gotoxy(184,35);
                        cout<<"                           ";
                        gotoxy(184,35);
                        showPath(playerPos,destPos);
                }
                disAvator(playerPos,"@");
                updatePlayerInfo("PlayerData.bin",userName,playerPos,userDest);

            }
        }
        if (finalDest(playerPos, destPos))
            break;
    }
    system("cls");
    //playerFind("PlayerData.bin",userName);cout<<endl;
    cout<<"Congrats! you've reached your destination"<<endl;
    {
        eline;eline;
       cout<<"this is x bulding and it is a part of sust it is situated in sust etc etc etc ok ok";
       eline;
        eline;
        eline;
        eline;
    }
    system("pause");
}
