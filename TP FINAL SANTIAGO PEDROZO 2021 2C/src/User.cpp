#include "User.h"
#include<string.h>

User::User()
{
    _IsLoaded = false;
    _UserScore = 0;
    _UserName;
}


bool User::LoadToDisk(){
    FILE *p;
    bool load;
    p=fopen("Scores.dat", "ab");
    if(p==NULL) return false;
    load=fwrite(this, sizeof (User), 1, p);
    fclose(p);
    return load;
}


bool User::ReadFromDisk(int pos){
    FILE *p;
    bool read;
    p=fopen("Scores.dat", "rb");
    if(p==NULL) return false;
    fseek(p, sizeof (User)*pos, 0);
    read=fread(this, sizeof(User), 1, p);
    fclose(p);
    return read;
}

bool User::ModifyToDisk(int pos){
    FILE *p;
    p=fopen("Scores.dat", "rb+");
    if(p==NULL) return false;
    fseek(p,sizeof(User)*pos,0);
    bool read=fwrite(this,sizeof(User),1, p);
    fclose(p);
    return read;

}

void User::SetUserScore(float n){
    _UserScore=n;
}

void User::setUserName(const char* n){
    strcpy(_UserName, n);
}


void User::setId(int id){
    _IDplayer=id;
}

void User::setIsLoaded(bool l){
    _IsLoaded=l;
}

bool User::GetIsLoaded(){
    return _IsLoaded;
}

int User::GetIdPlayer(){
    return _IDplayer;
}


const char* User::GetUserName(){
    return _UserName;
}

int User::GetUserScore(){
    return _UserScore;
}


void User::show(){
    std::cout << "\t" <<_UserName << std::endl;
    std::cout << "\tID:" << _IDplayer << std::endl;
    std::cout << "\tSCORE: " << _UserScore << std::endl;
}














