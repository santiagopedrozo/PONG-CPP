#ifndef USER_H
#define USER_H

#include <string.h>
#include<stdio.h>
#include<iostream>
#include <SFML/Graphics.hpp>
class User
{
    private:
        int _IDplayer;
        char _UserName[30];
        float _UserScore;
        bool _IsLoaded;

    public:
        User();

        bool LoadToDisk();
        bool ReadFromDisk(int pos);
        bool ModifyToDisk(int pos);

        void show();

        void SetUserScore(float n);
        void setUserName(const char* n);
        void setId(int id);
        void setIsLoaded(bool l);

        bool GetIsLoaded();
        const char *GetUserName();
        int GetUserScore();
        int GetIdPlayer();

};

#endif // USER_H
