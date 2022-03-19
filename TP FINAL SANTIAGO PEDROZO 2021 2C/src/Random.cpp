#include "Random.h"
#include<cstdlib>
#include<ctime>

int Random(int Numbers){
    std::srand((unsigned)std::time( 0 ));
    return std::rand() % Numbers;
}

int RandomDirection(){
    std::srand((unsigned)std::time(0));
    if(std::rand()%2 == 0){
        return 1;
    }
    else return -1;
}
