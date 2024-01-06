#include <iostream>
#include<chrono>
#include<thread>
#include<fstream>
#include<vector>
#include <windows.h>
#include <conio.h>
#define loop(i, x, y) for (int i = x; i < y; i++)
#define eline cout << endl;
#define build cout << '#'
#define road cout << '*'
#define space cout << ' '
const int width = 200;
const int height = 50;
int userDest;
using namespace std;
struct position
{
    int x;
    int y;
};
struct PlayerInfo{
    char name[50];
    int finalPos[2];
    int visitedArr[13];
    int totalStep;
    int chooseDestinatoin;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // used to set the position of the cursor
}

void updatePlayerChoice(const char* filename,char userName[],int userDest){
    fstream f(filename,ios::binary|ios::in|ios::out);
    if(!f.is_open()){cout<<"Sorry! Cannot Open The File."<<endl;return;}
    PlayerInfo pi;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        if(strcmp(pi.name,userName)==0){
            streampos position = f.tellp();
            position -= sizeof(pi);
            f.seekp(position, ios::beg);
            pi.chooseDestinatoin=userDest;
            f.write(reinterpret_cast<const char*>(&pi), sizeof(pi));        // converting pointers of one type to pointers of another type without changing the actual data.
            f.close();
            return;
        }
    }
    cout<<"Welcome! It seems this is your first SUST adventure."<<endl;
    f.close();
    return;
}
void create(const char* filename,char userName[], int choose){
    ofstream f(filename,ios::binary|ios::app);
    if(!f.is_open()){cout<<"Sorry! Cannot Open The File."<<endl;return;}
    PlayerInfo pi;
    strcpy(pi.name,userName);
    pi.finalPos[0]=62;pi.finalPos[1]=80;
    for(int i=0;i<13;i++)pi.visitedArr[i]=0;
    pi.chooseDestinatoin=choose;
    pi.totalStep=0;
    f.write(reinterpret_cast<const char*>(&pi),sizeof(pi));
    gotoxy(5,(height/2-8)+3);
    cout<<"Hey "<<userName<<", step into the world of Shahjalal University's insights. Welcome to our informative game!"<<endl;
    gotoxy(5,(height/2-8)+4);
    cout<<"Emerging from a relentless struggle, Shahjalal University of Science and Technology (SUST) was founded in 1986, a beacon of singular distinction."<<endl;
    gotoxy(5,(height/2-8)+5);
    cout<<"Commencing on the 1st Phalgun (15th February 1991), it debuted with three departments, 15 teachers, and 205 students.From this modest genesis, SUST"<<endl;
    gotoxy(5,(height/2-8)+6);
    cout<<"has flourished into a powerhouse, boasting 7 schools, 27 departments, and two institutes. The faculty burgeoned to 566, guiding 8,596 students."<<endl;
    gotoxy(5,(height/2-8)+7);
    cout<<"Notably, SUST oversees 12 medical colleges with 4,000 students.A pioneer in Bangladesh, SUST introduced the integrated honors course and ushered"<<endl;
    gotoxy(5,(height/2-8)+8);
    cout<<"in the semester system in 1996-97, revolutionizing national education. Every SUST student delves into two language and computer courses, defining"<<endl;
    gotoxy(5,(height/2-8)+9);
    cout<<"the institution's IT prowess.SUST, a trailblazer in graduate education, initiated master's programs, forging a path to world-class research. Despite"<<endl;
    gotoxy(5,(height/2-8)+10);
    cout<<"funding challenges, faculty endeavor to cultivate a research haven. Two journals, in Bangla and English, showcase SUST's research vigor. Departments"<<endl;
    gotoxy(5,(height/2-8)+11);
    cout<<"hosting International Conferences reflect a commitment to global academic prominence."<<endl;
    gotoxy(5,(height/2-8)+12);
    cout<<"SUST's journey is not just history; it's a symphony of educational evolution."<<endl;
    f.close();
}

bool playerFind(const char* filename,char username[],position &playerPos,position &destPos,string deststr[]){
    ifstream f(filename,ios::binary);
    vector<int> visVec;
    if(!f.is_open()){return false;}
    PlayerInfo pi;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        if(strcmp(pi.name,username)==0){
            system("cls");
            gotoxy(width/2-35,height/2-5);
            cout<< "Welcome back, "<< username<< "! Your previous journey has been located."<< endl;

            for (int i = 0; i < 13; i++) {
                if(pi.visitedArr[i]!=0)visVec.push_back(i);
            }
            gotoxy(width/2-35,height/2-4);
            if(visVec.empty())cout<<"Unexplored Any Territory!"<<endl;
            else {
                gotoxy(width/2-35,height/2-4);
                cout<<"Recalling your last adventure, your car's wheels last rolled through: "<<deststr[pi.chooseDestinatoin]<<endl;
                gotoxy(width/2-35,height/2-3);
                cout<<"Explore your visited spots: "<<endl;
                gotoxy(width/2-35,height/2-2);
                int sum=0;
                for(int i=0;i<visVec.size();i++){gotoxy(width/2-35+sum,height/2-2);cout<<deststr[visVec[i]];if(i<visVec.size()-1){sum+=deststr[visVec[i]].size()+2;cout<<", ";}}
            }
            gotoxy(width/2-35,height/2-1);
            cout<<"You've rolled "<<pi.totalStep<<" times"<<endl;
            gotoxy(width/2-35,height/2);
            cout<<"In your last roll you were at position: "<<pi.finalPos[0]<<" "<<pi.finalPos[1]<<endl;
            gotoxy(width/2-35,height/2+1);
            cout<<"Do you want to resume your previous game?"<<endl;
            gotoxy(width/2-35,height/2+2);
            cout<<"1.Yes"<<endl;
            gotoxy(width/2-35,height/2+3);
            cout<<"2.No"<<endl;
            int userChoice;
            gotoxy(width/2-35,height/2+4);
            cout<<"Your choice: ";
            cin>>userChoice;
            if(userChoice==1){
                userDest=pi.chooseDestinatoin;
                playerPos={pi.finalPos[0],pi.finalPos[1]};
            }
            else {
                system("cls");
                gotoxy(width/2-15,height/2);
                cout<<"Your virtual car is ready to roll."<<endl;
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
                gotoxy(width/2-15,height/2-4);
                cout << "1.IICT" << endl;
                gotoxy(width/2+5,height/2-4);
                cout << "2.Ladies Hall" << endl;
                gotoxy(width/2-15,height/2-3);
                cout << "3.Central Library" << endl;
                gotoxy(width/2+5,height/2-3);
                cout << "4.A-building" << endl;
                gotoxy(width/2-15,height/2-2);
                cout << "5.D-building" << endl;
                gotoxy(width/2+5,height/2-2);
                cout << "6.Cafeteria" << endl;
                gotoxy(width/2-15,height/2-1);
                cout << "7.E-building" << endl;
                gotoxy(width/2+5,height/2-1);
                cout << "8.C-building" << endl;
                gotoxy(width/2-15,height/2);
                cout << "9.B-building" << endl;
                gotoxy(width/2+5,height/2);
                cout << "10.Shaheed Minar" << endl;
                gotoxy(width/2-15,height/2+1);
                cout << "11.Auditorium" << endl;
                gotoxy(width/2+5,height/2+1);
                cout << "12.Shahporan Hall" << endl;
                gotoxy(width/2-60,height/2+4);
                cout << "Now, it's your turn to decide. Type the corresponding number of your desired destination and let the journey begin!_";
                cin>>userDest;
                updatePlayerChoice("PlayerData.bin",username,userDest);
                system("cls");
                gotoxy(width/2-27,height/2-2);
                cout<<"Resume from your last game position or Restrat from gate?"<<endl;
                gotoxy(width/2-27,height/2-1);
                cout<<"1.Resume"<<endl;
                gotoxy(width/2-27,height/2);
                cout<<"2.Restart"<<endl;
                gotoxy(width/2-27,height/2+1);
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
            if(playerPos.x==destPos.x&&playerPos.y==destPos.y){
                if(playerPos.x<61)playerPos.x+=2;
                else playerPos.x-=2;
            }
            f.close();
            return true;
        }
    }
    f.close();
    return false;
}



void updatePlayerPos(const char* filename,char userName[],const position &PlayerPos){
    fstream f(filename,ios::binary|ios::in|ios::out);
    if(!f.is_open()){cout<<"Sorry! Cannot open the file."<<endl;return;}
    PlayerInfo pi;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        if(strcmp(pi.name,userName)==0){
            streampos position = f.tellp();
            position -= sizeof(pi);
            f.seekp(position, ios::beg);
            pi.finalPos[0]=PlayerPos.x;pi.finalPos[1]=PlayerPos.y;
            pi.totalStep++;
            f.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
            f.close();
            return;
        }
    }
    cout<<"Welcome! It seems this is your first SUST adventure. "<<endl;
    f.close();
    return;
}

void updatePlayerFinalDest(const char* filename,char userName[]){
    fstream f(filename,ios::binary|ios::in|ios::out);
    if(!f.is_open()){cout<<"Sorry! Cannot open the file."<<endl;return;}
    PlayerInfo pi;
    while(f.read(reinterpret_cast<char*>(&pi), sizeof(pi))){
        if(strcmp(pi.name,userName)==0){
            streampos position = f.tellp();
            position -= sizeof(pi);
            f.seekp(position, ios::beg);
            pi.visitedArr[pi.chooseDestinatoin]=1;
            f.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
            f.close();
            return;
        }
    }
    cout<<"Welcome! It seems this is your first SUST adventure. "<<endl;
    f.close();
    return;
}




void disAvator(const position &playerPos,string s)
{
    gotoxy(playerPos.x, playerPos.y);
    cout << s;
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
    loop(i, 0, 105) /// chottor
    {
        if (i >= 50 && i < 61)
            cout << '*';
        else if (i > 63 && i < 75)
            cout << '*';
        else if(i>90)cout<<'P';
        else
            cout << ' ';
    }
    eline;
    loop(j, 0, 2) /// chottor
    {
        loop(i, 0, 105)
        {
            if (i == 50 || i == 74)
                cout << '*';
                else if (i == 104 || i==91)
            cout<<'P';
            else
                cout << ' ';

        }
        eline;
    }
    loop(i, 0, 105) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
        else if (i == 50 || i == 74)
            cout << '*';
            else if (i == 104 || i==91)
            cout<<'P';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 120) /// ladies hall and chottor
    {
        if (i > 14 && i <= 50 )
            cout << '*';
        else if(i>=74 && i<=90)
            cout<<'*';
        else if(i==10 || i==14)cout<<'H';
            else if (i == 104 || i==91)
            cout<<'P';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 110) /// ladies hall and chottor
    {
        if (i == 10 || i == 14)
            cout << 'H';
        else if (i == 104)
            cout<<'P';
        else
            cout << ' ';
    }
    eline;
    loop(i, 0, 105) /// ladies hall and chottor
    {
        if (i >= 10 && i <= 14)
            cout << 'H';
        else if (i >= 14 && i <= 50 )
            cout << '*';
        else if(i>=74 && i<=90)
            cout<<'*';
        else if(i>90)cout<<'P';
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
    loop(i,64,100){     // A-building, gol chottor,E-building
        if(newPos.x==i&&(newPos.y==29||newPos.y==31||newPos.y==42||newPos.y==44||newPos.y==54||newPos.y==63)&&((newPos.x!=86&&newPos.x!=87&&newPos.x!=88)||newPos.y!=29)){return true;}
    }
    loop(i,54,64){      // golchottor
        //if(i==59)continue;
        if((newPos.x==50||newPos.x==74)&&(newPos.y==i)&&(newPos.y!=59||newPos.x==74))return true;
    }
    loop(i,0,51){   //hall
        if(newPos.x==i&&(newPos.y==58||newPos.y==60))return true;
    }
    loop(i,20,29){        //C-building
        if((newPos.x==85||newPos.x==89)&&newPos.y==i&&(newPos.y!=21||newPos.x!=89))return true;
    }
    loop(i,85,120){         //C-Building
        if((newPos.y==20||newPos.y==22)&&newPos.x==i&&((newPos.x!=86&&newPos.x!=87&&newPos.x!=88)||newPos.y!=22))return true;
    }
    if((newPos.x==33&&newPos.y==12)||(newPos.x==21&&newPos.y==21)||(newPos.x==99&&newPos.y==30)||(newPos.x==35&&newPos.y==40)||(newPos.x==95&&newPos.y==43)||(newPos.x==50&&newPos.y==49)||(newPos.x==15&&newPos.y==59)||(newPos.x==50&&newPos.y==68)||(newPos.x==62&&newPos.y==81)||(newPos.x==119&&newPos.y==21))return true;
    return false;
}

bool finalDest(const position &playerPos, const position &destPos)
{
    if (playerPos.x == destPos.x && playerPos.y == destPos.y)
        return true;
    return false;
}

void showPath(const position &playerPos, const position &destPos,int userDest){
    if(userDest==8){
        position tempPos={87,30};
        if(((playerPos.x==86||playerPos.x==87||playerPos.x==88))||(playerPos.x>=63&&playerPos.y==21)){
            if(playerPos.y>destPos.y)cout<<"Go Up";
            else if(playerPos.y<destPos.y)cout<<"Go Down";
            else{
                if(destPos.x<playerPos.x)cout<<"Turn Left";
                else cout<<"Turn Right";
            }
        }
        else showPath(playerPos, tempPos,1);


        return;
    }
    if(playerPos.x==61||playerPos.x==62||playerPos.x==63||destPos.y==playerPos.y){
        if(playerPos.y>destPos.y)cout<<"Go Up";
        else if(playerPos.y<destPos.y)cout<<"Go Down";
        else{
            if(destPos.x<playerPos.x)cout<<"Turn Left";
            else cout<<"Turn Right";
        }
    }
    else{
        if(playerPos.x<61)cout<<"Turn Right";
        else cout<<"Turn Left";
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
    gotoxy((width / 2)-11, (height / 2)-2);
    string deststr[13]={"","IICT","Ladies Hall","Central Library","A-building","D-building","E-building","C-building","Cafeteria","B-building","Shaheed Minar","Auditorium","Shahporan Hall"};
    cout << "Hey! Welcome to GTA_SUST";
    gotoxy(width / 2-41, height / 2-1);
    cout << "**********************************************************************************" << endl;gotoxy(width / 2-41, height / 2);
    cout << "Embark on a virtual journey: " << endl;gotoxy(width / 2-41, height / 2+1);
    cout << "Explore Shahjalal University of Science and Technology in a Unique car Adventure!" << endl;gotoxy(width / 2-41, height / 2+2);
    system("pause");
    system("cls");
    gotoxy((width / 2)-50, (height / 2)-12);
    cout<<"Instructions : Move in different direction.The four arrow keys are used to move in four directions with "<<endl;
    gotoxy((width / 2)-50, (height / 2)-11);
    cout<<"up arrow to move upwards,down arrow to move down,left and right with left and right arrow respectively."<<endl;
    gotoxy((width / 2)-50, (height / 2)-9);
    cout<<"The right side of the terminal shows the coordinate of your destination, coordinate of you present location"<<endl;
    gotoxy((width / 2)-50, (height / 2)-8);
    cout<<"and directions you must follow to reach your destination"<<endl;
    gotoxy((width / 2)-50, (height / 2)-6);
    cout<<"You will be shown the map of SUST with roads and different buildings and establishments"<<endl;
    gotoxy((width / 2)-50, (height / 2)-5);
    cout<<"The '*' represents roads and different letters represents differents establisments"<<endl;
    gotoxy((width / 2)-50, (height / 2)-4);
    cout<<"The establishment with 'I'  represents IICT"<<endl;
    gotoxy((width / 2)-50, (height / 2)-3);
    cout<<"The establishment with 'H'  represents Ladies Hall"<<endl;
    gotoxy((width / 2)-50, (height / 2)-2);
    cout<<"The establishment with 'P'  represents Bus parking"<<endl;
    gotoxy((width / 2)-50, (height / 2)-1);
    cout<<"The establishment with 'L'  represents central library"<<endl;
    gotoxy((width / 2)-50, (height / 2));
    cout<<"The establishment with 'A'  represents Academic building A"<<endl;
    gotoxy((width / 2)-50, (height / 2)+1);
    cout<<"The establishment with 'D'  represents Academic building D"<<endl;
    gotoxy((width / 2)-50, (height / 2)+2);
    cout<<"The establishment with 'E'  represents Academic building E"<<endl;
    gotoxy((width / 2)-50, (height / 2)+3);
    cout<<"The establishment with 'C'  represents Academic building C"<<endl;
    gotoxy((width / 2)-50, (height / 2)+4);
    cout<<"The establishment with 'B'  represents Academic building B"<<endl;
    gotoxy((width / 2)-50, (height / 2)+5);
    cout<<"The establishment with 'T'  represents cafeteria"<<endl;
    gotoxy((width / 2)-50, (height / 2)+6);
    cout<<"The establishment with 'M'  represents Shahid Minar"<<endl;
    gotoxy((width / 2)-50, (height / 2)+7);
    cout<<"The establishment with 'Z'  represents central field"<<endl;
    gotoxy((width / 2)-50, (height / 2)+8);
    cout<<"The establishment with 'O'  represents Auditorium"<<endl;
    gotoxy((width / 2)-50, (height / 2)+9);
    cout<<"The establishment with 'S'  represents Shahporan Hall"<<endl;
    gotoxy((width / 2)-50, (height / 2)+11);

    system("pause");
    system("cls");

    char userName[50];
    gotoxy((width / 2)-76, (height / 2)-1);
    cout<<"Let's save your journey history! Please enter your name. (Note: This is case-sensitive, so if you've played before, enter exactly as you did last time))"<<endl;
    gotoxy((width / 2)-76, (height / 2));
    cout<<"You're Name: ";
    cin.getline(userName,sizeof(userName));
    bool found=false;
    found=playerFind("PlayerData.bin",userName,playerPos,destPos,deststr);
    cout<<endl;


    if(!found){
        system("cls");
        gotoxy(width/2-15,height/2);
        cout<<"Your virtual car is ready to roll."<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        system("cls");
        gotoxy(width/2-15,height/2-4);
        cout << "1.IICT" << endl;
        gotoxy(width/2+5,height/2-4);
        cout << "2.Ladies Hall" << endl;
        gotoxy(width/2-15,height/2-3);
        cout << "3.Central Library" << endl;
        gotoxy(width/2+5,height/2-3);
        cout << "4.A-building" << endl;
        gotoxy(width/2-15,height/2-2);
        cout << "5.D-building" << endl;
        gotoxy(width/2+5,height/2-2);
        cout << "6.Cafeteria" << endl;
        gotoxy(width/2-15,height/2-1);
        cout << "7.E-building" << endl;
        gotoxy(width/2+5,height/2-1);
        cout << "8.C-building" << endl;
        gotoxy(width/2-15,height/2);
        cout << "9.B-building" << endl;
        gotoxy(width/2+5,height/2);
        cout << "10.Shaheed Minar" << endl;
        gotoxy(width/2-15,height/2+1);
        cout << "11.Auditorium" << endl;
        gotoxy(width/2+5,height/2+1);
        cout << "12.Shahporan Hall" << endl;
        gotoxy(width/2-52,height/2+4);
        cout << "Now, it's your turn to decide. Type the corresponding number of your desired destination and let the journey begin!_";

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
        system("cls");
        create("PlayerData.bin",userName,userDest);
        gotoxy(5,(height/2-8)+15);
        system("pause");
    }



    system("cls");
    mapSUST();
    disAvator(destPos,"()");
    disAvator(playerPos,"^");

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
                playerPos = newPos;

                if(playerPos.y<=40){
                        gotoxy(180,31);cout<<"                                     ";gotoxy(180,0);cout<<"                                      ";gotoxy(180,0);cout<<"Your Position x: "<<playerPos.x<<" "<<"y: "<<playerPos.y;
                        gotoxy(180,33);cout<<"                                    ";gotoxy(180,2);cout<<"Destination x: "<<deststr[userDest];
                        gotoxy(180,35);
                        cout<<"                                     ";
                        gotoxy(180,4);
                        cout<<"                                    ";
                        gotoxy(180,4);
                        showPath(playerPos,destPos,userDest);
                }
                if(playerPos.y>40){
                        gotoxy(0,80);cout<<"";gotoxy(180,31);cout<<"Your Position x: "<<playerPos.x<<" "<<"y: "<<playerPos.y;
                        gotoxy(180,33);cout<<"Destination x: "<<deststr[userDest];
                        gotoxy(180,35);
                        cout<<"                                      ";
                        gotoxy(180,35);
                        showPath(playerPos,destPos,userDest);
                }
                if (key == 80)
                {
                    disAvator(playerPos,"v");
                }
                else if (key == 72)
                {
                    disAvator(playerPos,"^");
                }

                else if (key == 77)
                {
                    disAvator(playerPos,">");
                }

                else if (key == 75)
                {
                    disAvator(playerPos,"<");
                }
                else disAvator(playerPos,"#");
                updatePlayerPos("PlayerData.bin",userName,playerPos);

            }
            else{
                if(newPos.x==64&&newPos.y==13){
                    gotoxy(103,13);cout<<"No access! This route is not available at the moment.";
                    this_thread::sleep_for(chrono::milliseconds(500));gotoxy(103,13);cout<<"                                                                 ";
                }
                if(newPos.x==74&&newPos.y==59){gotoxy(108,59);cout<<"No access! This route is not available at the moment.";this_thread::sleep_for(chrono::milliseconds(500));gotoxy(108,59);cout<<"                                                               ";}
                if (key == 80)
                {
                    disAvator(playerPos,"v");
                }
                else if (key == 72)
                {
                    disAvator(playerPos,"^");
                }

                else if (key == 77)
                {
                    disAvator(playerPos,">");
                }

                else if (key == 75)
                {
                    disAvator(playerPos,"<");
                }
                else disAvator(playerPos,"#");
            }
        }
        if (finalDest(playerPos, destPos))
            break;
    }
    updatePlayerFinalDest("PlayerData.bin",userName);
    system("cls");
    gotoxy(width/2-22,height/2);
    cout<<"Congrats! you've reached your destination"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
    eline;
    {
        if(userDest==1)
        {
            cout<<"This is IICT building"<<endl;
            cout<<"It is the institute of information and communication technology"<<endl;
            cout<<"Departments -> CSE,SWE,EEE"<<endl;
            cout<<"Details ->"<<endl;
            cout<<"IICT, the first institute of Shahjalal University of Science and Technology was established in 2007. The aim and objective of the institute is to promote and provide facilities for"<<endl;
            cout<<"diploma, undergraduate and post graduate study in the field of ICT.The  institute's building is named 'Dr. M.A. Wazed Miah IICT Building' which was a gift to SUST from Prime Minister"<<endl;
            cout<<"for starting online admission in our country for the first time. To develop knowledge-based products and services, the IICT will pursue active research in the field of ICT. The institute"<<endl;
            cout<<"will also develop ICT facilities in order to create an on-campus environment conductive to enthusiasm, innovation, and enterprise and to nurture innovative ideas and incubate promising"<<endl;
            cout<<"initiatives. At the same time the institute will try to produce manpower and expertise in ICT by carrying out training in diverse areas for those interestedin taking ICT as a profession as"<<endl;
            cout<<"well asthose who are already engaged in the profession. The institute will also provide consulting and advisory services to public and private organizations,also providing a lot of resarch"<<endl;
            cout<<"facilities.Through its multifaceted approach, IICT aspires to be the cornerstone in cultivating a dynamic, skilled workforce and fostering a culture of innovation and excellencein the"<<endl;
            cout<<"ever-evolving landscape of ICT."<<endl;
            eline;eline;
        }
        else if(userDest==2)
        {
            cout<<"This is 1st ladies hall"<<endl;
            cout<<"SUST Ladies Hall holds significant importance within the university's residential infrastructure. There are three dedicated ladies halls at SUST, each equipped with ample facilities to accommodate"<<endl;
            cout<<"the university's female students. These halls are Sahid Janani Jahanara Imam Hall, Begum Sirajunnesa Chowdhury Ladies Hall, and Begum Fazilatunnesa Mujib Hall, commonly referred to as the First Ladies"<<endl;
            cout<<"Hall, Second Ladies Hall, and Third Ladies Hall, respectively.These three halls collectively provide housing for a substantial portion of the female student population. However, due to high demand, there remains"<<endl;
            cout<<"a considerable number of students who are unable to secure accommodation within these halls. The recently added Begum Fazilatunnesa Mujib Hall, designed to accommodate up to 450 girl students, serves as a"<<endl;
            cout<<"testament to the university's ongoing efforts to address this housing demand. Despite this addition, the current capacity still falls short of meeting the growing needs of the female student�body�at�SUST."<<endl;
            eline;eline;
        }
        else if(userDest==3)
        {
            cout<<"This is central library"<<endl;
            cout<<"The Central Library of Shahjalal University of Science and Technology (Central Library, SUST) started with a very small number of books and only four rooms in 1990 at the Academic Building �A�. It is now housed"<<endl;
            cout<<"in its own 4-storied Central Library Building."<<endl;
            cout<<"Library Hours:  The library provides 12-hour non-stop services from 8:00 a.m. to 8:00 p.m. on all working days."<<endl;
            cout<<"Library Resources (Hard Copy):  Starting with a very meager collection, the library has now been enriched with more than 75 thousand books, 6 thousand hard copy journals/ periodicals and 23 Dailies for its users."<<endl;
            cout<<"Library e-Resources:  The library has been subscribing to more than 25 thousand eJournals-eBooks/Resources through LiCoB Consortium. In addition, it has been subscribing the e-Journals/Resources of Emerald,"<<endl;
            cout<<"JSTOR, IEEE, and ACM and purchased 37,500 + e-Books through UGC Digital Library (UDL). "<<endl;
            cout<<"Computerized Service:  The library has been computerized (using the ILS KOHA by developing a database in MARC 21 format) and providing computerized library services since September 2013. The resources can be"<<endl;
            cout<<"searched through online from everywhere using the link: http://library.sust.edu.The circulation of books is done through computerized system within the seconds. As a part of computerization, an RFID tag has been"<<endl;
            cout<<"attached to each book for maintaining its security. Moreover, a CCTV system with 32 CC cameras is being run for the security of the whole library."<<endl;
            cout<<"Muktijuddho Corner:  The Central Library has established a unique Muktijuddho Corner which is enriched with the Books, Posters, Maps, Videos, Documents, etc. on the Great Liberation War of Bangladesh held in 1971."<<endl;
            cout<<"The present collection of books in the Muktijuddho Corner is more than 2,000 titles."<<endl;
            cout<<"The Central Library contributed to an overall improvement of the educational environment/level because of better library facilities. The users/researchers have connectivity with the rest of the world and access to the information"<<endl;
            cout<<"and knowledge through the Central Library."<<endl;
        }
        else if(userDest==4)
        {
            cout<<"This is academic building 'A' "<<endl;
            cout<<"Departments -> PHY,MEE,BMB,OCG,GEE"<<endl;
            cout<<"Details ->"<<endl;
            cout<<"Academic Building 'A', a venerable testament to the inception of this esteemed university, stands as the oldest bastion of academic pursuit. It laid the foundation institution's journey,with 3"<<endl;
            cout<<"departments; CSE,PHY, and CHE.Department of Physics reigns as a cornerstone of scientific exploration. With theoretical and experimental physics, this department pioneers research spanning"<<endl;
            cout<<"over different topics. Its state-of-the-art laboratories and scholarly faculty provides students with a comprehensive Department of Mechanical Engineering stands as an embodiment of innovation"<<endl;
            cout<<"and technological advancement.This department nurtures aspiring engineers to conceive, design, and fabricate cutting-edge solutions. Students are engaged in hands-on experimentation and"<<endl;
            cout<<"theoretical exploration, preparing them for modern engineering challenges.The Department of Oceanology,serves as a bastion of marine sciences. Drawing upon interdisciplinary approaches, it delves"<<endl;
            cout<<"into the realms of marine biology, oceanography. This department helps students and scholars collaborate to understand marine ecosystems,climate dynamics, and oceanic resources.The Department"<<endl;
            cout<<"of Geography stands as a vanguard of spatial sciences. It encompasses cartography, geographic information systems and environmental studies. Furthermore, the Department of Biochemistry and Molecular"<<endl;
            cout<<"Biology, a beacon of life sciences, thrives within these venerable walls. It delves deep into the molecular intricacies of biological systems, exploring DNA structures, cellular mechanisms, and biochemical"<<endl;
            cout<<"pathways. .Academic Building 'A' stands not merely as a physical structure but as a cradle of intellectual prowess,nurturing minds and facilitating discoveries across these diverse and dynamic departments."<<endl;
            eline;eline;
        }
         else if(userDest==5)
        {
            cout<<"This is academic building 'A' "<<endl;
            cout<<"Departments ->ECO,SCW,SOC,PSS,ANP,PAD,"<<endl;
            cout<<"Details ->"<<endl;
            cout<<"Academic Building D stands as the vibrant epicenter of arts and commerce subjects within the campus, exuding an effervescent atmosphere characterized by festivity and vivid colors. Its rectangular structure is"<<endl;
            cout<<"designed with an interspersed open space, serving as a versatile arena for sporting activities, events, concerts, and various other gatherings, fostering a vibrant community spirit.Delving into the intricate mechanisms"<<endl;
            cout<<"of economies, Economics department explores the allocation of resources, market dynamics, and economic policies, fostering a deep understanding of global financial systems and their impact on societies.The Department of"<<endl;
            cout<<"Social Work champions advocacy, community empowerment, and social justice, equipping students with the tools to address societal challenges and uplift marginalized communities.Department of Sociology,exploring the"<<endl;
            cout<<"fabric of societies, studies human behavior, social structures, and cultural dynamics, unraveling the complexities of relationships, institutions, and societal norms.Engaging in the analysis of political systems and governance,"<<endl;
            cout<<"the Department of Political Studies delves into the mechanisms of power, policy-making, and international relations, fostering critical thinking about political structures and ideologies.Nestled within this vibrant building,"<<endl;
            cout<<"Anthropology investigates human societies, cultures, and evolution, exploring diversity, rituals, and the complexities of human existence across time and space.The deparment of Public Administration equips future administrators"<<endl;
            cout<<"with the skills necessary to manage public policies, organizational structures, and public service delivery, ensuring efficient and ethical governance for the betterment of society.Each department within Academic Building D serves"<<endl;
            cout<<"as a crucible of knowledge and societal understanding, nurturing individuals equipped with the insights and skills to navigate the multifaceted realms of arts, commerce, and social sciences."<<endl;
            eline;eline;
        }
        else if(userDest==6)
        {
            cout<<"This is SUST Cafeteria"<<endl;
            cout<<"This space serves as the primary cafeteria for our institution, accommodating both teachers and students in a two seperate dinning space. Situated adjacent to academic building 'E' and approximately 100 meters away from"<<endl;
            cout<<"Chetona Ekattor',it serves as the hub for student meals, offering breakfast and lunch options. Operating hours span from 8 AM to 5 PM, with a noticeable surge in patrons around 1 PM during lunch hours. Notably, the cafeteria"<<endl;
            cout<<"ensures the provision of nutritious meals for students at reasonable prices, catering to their dietary needs within a suitable budgetary framework."<<endl;
            eline;eline;
        }
       else if(userDest==7)
       {
           cout<<"This is academic building 'E'"<<endl;
           cout<<"Departments -> ARC, ENG, BBA, FET, GEB, PME, FES"<<endl;
           cout<<"Details ->"<<endl;
           cout<<"E Building stands as a multifaceted educational hub, hosting an impressive array of four diverse departments. The architectural marvel of Architecture unfolds within its walls, inspiring creative"<<endl;
           cout<<"minds to envision and shape the future of design and construction. The Department of Food Engineering and Tea Technology engages in cutting-edge research, exploring the intricate"<<endl;
           cout<<"science behind food production and the nuances of tea technology. The English Department cultivates linguistic and literary excellence, honing communication skills essential for a globalized society."<<endl;
           cout<<"Business Administration thrives, instilling strategic acumen and managerial prowess in aspiring leaders. Beyond these, E Building expands its horizons to embrace Genetic Engineering and Biotechnology"<<endl;
           cout<<"delving into the revolutionary realms of life sciences. Petroleum and Mining Engineering carve a niche in energy exploration and resource extraction, while Forestry contributes to environmental stewardship"<<endl;
           cout<<"and sustainable resource management. E Building thus emerges as a comprehensive center of knowledge, where innovation, creativity, language, business, genetics, and natural resource management"<<endl;
           cout<<"converge, fostering a rich academic environment."<<endl;
           eline;eline;
       }
        else if(userDest==8)
        {
            cout<<"This is academic building 'C' "<<endl;
            cout<<"Departments -> IPE, CEE, MAT, STAT"<<endl;
            cout<<"Details ->"<<endl;
            cout<<"C Building stands as a hub of diverse academic pursuits, housing four distinct departments that contribute to the intellectual tapestry of the institution. Industrial and Production Engineering thrives within"<<endl;
            cout<<"its walls, fostering innovation and technological advancements. Civil and Environmental Engineering, on the other hand, emphasizes sustainable infrastructure and environmental stewardship. The Department of"<<endl;
            cout<<"Mathematics is a haven for analytical minds, exploring the beauty and intricacies of abstract concepts. Meanwhile, the Department of Statistics delves into the world"<<endl;
            eline;eline;
        }
        else if(userDest==9)
        {
            cout<<"This is academic building 'B' "<<endl;
            cout<<"Departments -> Chemistry, Bangla, CEP"<<endl;
            cout<<"Details ->"<<endl;
            cout<<"B Building stands as a bastion of knowledge, accommodating three pivotal departments that contribute distinct facets to the academic landscape. The Department of Bangla within its walls serves as a guardian"<<endl;
            cout<<"of linguistic and literary heritage, fostering an appreciation for the cultural richness embedded in the Bangla language. Meanwhile, the Department of Chemical Engineering and Polymer Science engages in"<<endl;
            cout<<"cutting-edge research, delving into the transformative realms of chemical processes and advanced materials. Complementing this, the Department of Chemistry conducts explorations into the fundamental principles"<<endl;
            cout<<"governing matter and reactions. Together, these departments in B Building create a synergistic environment where language, engineering, and scientific inquiry converge, shaping well-rounded scholars prepared for"<<endl;
            cout<<"the complexities of the modern world."<<endl;
            eline;eline;
        }
        else if(userDest==10)
        {
            cout<<"This is Shaheed Minar"<<endl;
            cout<<"SUST's central Shaheed Minar stands out as a remarkable structure, celebrated for its natural beauty and distinctive architectural style. Positioned atop the highest point in the country, it serves as a captivating landmark"<<endl;
            cout<<"within the university campus. Greeting visitors upon entry, the Shaheed Minar becomes a focal point, drawing attention with its unique charm. The premises surrounding the monument come alive with the vibrant sounds of"<<endl;
            cout<<"students and visitors engaging in lively conversations, songs, and poetry. This architectural gem in Sylhet occupies a 56 feet high platform, encompassing 6,006 square feet around the central auditorium and university center."<<endl;
            cout<<"Accessing the Shaheed Minar involves ascending 101 stairs, divided into three flights, leading to a visually stunning space marked by round walls and an additional seven steps before reaching the main altar."<<endl; eline;eline;
        }
        else if(userDest==11)
        {
            cout<<"This is SUST Auditorium"<<endl;
            cout<<"The central auditorium at SUST stands as a majestic centerpiece, both in size and aesthetic appeal, enhancing the university's architectural charm. With its impressive dimensions and modern design, the auditorium is not merely"<<endl;
            cout<<"a functional space for events but also an integral part of SUST's visual identity. Its grandeur contributes to the overall beauty of the campus, serving as a focal point for academic and cultural gatherings. The well-equipped facility"<<endl;
            cout<<"accommodates a large audience, hosting a myriad of events ranging from academic conferences to cultural performances. As a hub for collective experiences and shared moments, the central auditorium embodies the spirit of"<<endl;
            cout<<"community and intellectual exchange at SUST, making it a cherished and indispensable asset for the university."<<endl;
            eline;eline;
        }
        else if(userDest==12)
        {
            cout<<"This is Shahporan Hall"<<endl;
            cout<<"SUST's Shahporan Hall, the inaugural male residence, stands as a spacious abode for students. Beyond providing comfortable accommodations, the hall encompasses essential amenities, including a dining facility and a notable"<<endl;
            cout<<"canteen known for its quality offerings. The canteen, in particular, stands out for its diverse menu and excellent culinary offerings, creating a popular spot for residents. Moreover, Shahporan Hall is equipped with high-speed Wi-Fi,"<<endl;
            cout<<"freely accessible to all occupants. This technological inclusion enhances the overall living experience, allowing students to stay connected, engage in academic pursuits, and unwind in their downtime. With its comprehensive offerings"<<endl;
            cout<<"and modern conveniences, Shahporan Hall becomes more than just a residence; it becomes a vibrant and conducive living environment that fosters a sense of community among its residents."<<endl;
            eline;eline;
        }
    }
    system("pause");
}
