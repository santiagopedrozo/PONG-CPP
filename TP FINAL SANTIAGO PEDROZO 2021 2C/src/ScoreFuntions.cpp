#include "ScoreFuntions.h"
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <array>
#include "BackGround.h"
#include "Top3Styles.h"

void CharToString(const char * Char, std::string& Str, int Size){
    for(int i=0; i<Size - 1; i++)
    {
        if(Char[i] == '\0'){
            break;
        }
        else{
            Str+=Char[i];
        }

    }
}

float FinalScore(int score[], int ScoreMatch){ /// recibe vector con ambas puntuaciones y luego el puntuaje del jugador,
    float average;                             /// al perdedor se le divide el puntuaje y se lo multiplica por 7
    if(ScoreMatch < 10){
        return (ScoreMatch / 2) * 7;           ///Se saca promedio de los puntos,
    }                                          /// a este se le resta 10 para que al final no quede un numero muy grande
    average = ((float)score[0] + (float)score[1]) / 2;
    average = (10 - average) * 80;

    return average;
}

void SortVector(int *v, int Size){ ///from max to min
    int i, j, MaxPos, aux;

    for(i=0; i<Size - 1; i++)
    {
        MaxPos=i;
        for(j=i + 1; j<Size; j++)
        {
            if(v[j] > v [MaxPos] ) MaxPos = j;
        }

        aux = v[i];
        v[i] = v[MaxPos];
        v[MaxPos] = aux;
    }
}


void ListTop(int v[]){ ///LISTA POR CONSOLA
    int pos=0, showed=0;
    User reg;

    std::cout << std::endl;
    std::cout << "top 3" << std::endl;
    for(int i=0; i < 3; i++)
    {
        pos=0;

        while(reg.ReadFromDisk(pos++) && showed != 3)
        {
            if(reg.GetUserScore() == v[i]){
                reg.show();
                showed++;
            }
        }

    }

}

void ShowAll(){
    User reg;
    int pos=0;
    while(reg.ReadFromDisk(pos)){
        std::cout << "*******************" << std::endl;
        std::cout << "pos: " << pos << std::endl;
        reg.show();

        pos++;
    }
}


void LoadTop3(int v[], int Scores[], std::string strName[]){
    User reg;

    int pos=0, Load=0, i; ///ranking

    for(int i=0; i < 3; i++)
    {
        pos=0;

        while(reg.ReadFromDisk(pos++) && Load != 3)
        {
            if(reg.GetUserScore() == v[i]){
                CharToString(reg.GetUserName(), strName[Load], 30);
                Scores[Load] = reg.GetUserScore();
                Load++;
            }
        }

    }

}

void Top3Scores(sf::RenderWindow& window){
    User reg;
    int *VScores, pos=0, Size;
    int Scores[3];
    std::string Names[3];
    Size = CountRegisters();
    VScores = new int[Size];  ///VECTOR CON TODOS LOS PUNTAJES, DINAMICO SEGUN LA CANTIDAD DE REGISTROS.

    while(reg.ReadFromDisk(pos)){
        VScores[pos] = reg.GetUserScore();
        pos++;
    }

    SortVector(VScores, Size); ///SE ORDENA VECTOR
    LoadTop3(VScores, Scores, Names); ///CARGA 3 PRIMEROS PUNTAJES Y NOMBRES A INT Y STRING
    DrawScoresAndNamesTOP3(window, Scores, Names); ///DIBUJA EL PANEL CON ESTILO

    delete VScores;
}

