#ifndef FILESFUNTIONS_H
#define FILESFUNTIONS_H
#include "User.h"

int CountRegisters();

int SearchIdName(const char* name);

void AddUserFile(User& user, int Score[], int UsrN);

void EditeUserFile(User& user, int pos, int Score[], int UsrN);

void FileLoad(User& user1, User& user2, int Score[]);

void deleteRegisters();

#endif // FILESFUNTIONS_H
