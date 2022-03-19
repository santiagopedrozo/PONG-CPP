#include "FilesFuntions.h"
#include "ScoreFuntions.h"


int CountRegisters(){
    FILE *p;
    int res=0;
    long size;
    p=fopen("Scores.dat", "rb");
    fseek(p, 0, SEEK_END);
    size=ftell(p);
    fclose(p);
    res = size/sizeof(User);
    return res;
}

int SearchIdName(const char* name){
    int pos=0;
    User reg;
    while(reg.ReadFromDisk(pos)){
        if(strcmp(name, reg.GetUserName()) == 0){
            std::cout << "retorno encontrado: " << pos << std::endl;
            return reg.GetIdPlayer();
        }
        pos++;
    }

    return -1;
}

void AddUserFile(User& user, int Score[], int UsrN){
    user.setId(CountRegisters());
    user.SetUserScore( FinalScore( Score, Score[UsrN]) );
    std::cout << "user score asignado usr nuevo: " << user.GetUserScore() << std::endl;
    user.LoadToDisk();
    user.setIsLoaded("true");

    std::cout << "!!!cargado!!!" << std::endl;
}

void EditeUserFile(User& user, int pos, int Score[], int UsrN){
    user.ReadFromDisk(pos);
    std::cout << "final score asignado usr modificado: " << FinalScore(Score, Score[UsrN]) << std::endl;
    user.SetUserScore( user.GetUserScore() + FinalScore(Score, Score[UsrN]) );
    user.ModifyToDisk(pos);
    user.setIsLoaded("true");

    std::cout << "!!!modificado!!!" << std::endl;

}

void FileLoad(User& user1, User& user2, int Score[]){
    int pos1, pos2;

    if(!user1.GetIsLoaded())
    {
        pos1=SearchIdName(user1.GetUserName());
        if(pos1 == -1){    ///-1 == NO EXISTE EN EL ARCHIVO
            AddUserFile(user1, Score, 0);
        }
        else{
            EditeUserFile(user1, pos1, Score, 0);
        }

        std::cout << "primer usuario: " << std::endl;
        user1.show();
    }

    if(!user2.GetIsLoaded())
    {
        pos2=SearchIdName(user2.GetUserName());
        if( pos2 == -1){
            AddUserFile(user2, Score, 1);
        }
        else{
            EditeUserFile(user2, pos2, Score, 1);
        }

        std::cout << "segundo usuario: " << std::endl;
        user2.show();
    }


}


void deleteRegisters(){
    FILE *p;
    p=fopen("Scores.dat", "wb");
    fclose(p);
}
