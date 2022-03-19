#include "GameplayStyle.h"

void MidLine(sf::RenderWindow& window){
    sf::RectangleShape _Line[10];
    sf::Color Main(158, 252, 255);

    int y = 0;

    for(auto Ln : _Line){
        Ln.setFillColor(Main);
        Ln.setSize({12, 40});
        Ln.setPosition(400, y);
        Ln.setOrigin({6, 0});
        for(int i = 0; i < 10; i++) y += 8;
        window.draw(Ln);
    }
}

void ScoresAndNamesGameplay(int Score[], std::string Name[], sf::RenderWindow& window){
    sf::Color First(0, 60, 64);
    sf::Color Second(20, 173, 182);
    sf::Font font;

    GetFont(font);

    WordStyle(std::to_string(Score[0]), {400 - 65, 23}, 20, First, Second, window, font);
    WordStyle(std::to_string(Score[1]), {400 + 35, 23}, 20, First, Second, window, font);

    WordStyle(Name[0], {380 - 200, 50}, 16, First, Second, window, font);
    WordStyle(Name[1], {340 + 95, 50}, 16, First, Second, window, font);

}

void gameplayPanel(sf::RenderWindow& window, int Scores[], std::string Names[]){
    DrawBackground(window);
    BordersLineColor(window);
    MidLine(window);
    ScoresAndNamesGameplay(Scores, Names, window);
}

void FinalMenu(sf::RenderWindow& window, int Score[], std::string Names[]){
    float x=80, y=80;

    sf::Font font;
    GetFont(font);

    sf::Color BlueSky(25, 211, 226); //rgba(25, 211, 226, 0.8)
    sf::Color Blue(0, 111, 120);

    sf::Color SecondG(255, 253, 0); //Gold
    sf::Color FirstG(122, 121, 0);

    if(Score[0] == 2){
        WordStyle("WINNER", {380 - 200, y}, 15, FirstG, SecondG, window, font);
        WordStyle("FINAL POINTS: " + std::to_string(int(FinalScore( Score, Score[0]))), {380 - 200, y + 25}, 11, FirstG, SecondG, window, font);

        WordStyle("LOSER", {340 + 95, y}, 16, FirstG, SecondG, window, font);
        WordStyle("FINAL POINTS: " + std::to_string(int(FinalScore( Score, Score[1]))), {340 + 95, y + 25}, 11, FirstG, SecondG, window, font);
    }
    else{
        WordStyle("WINNER", {340 + 95, y}, 15, FirstG, SecondG, window, font);
        WordStyle("FINAL POINTS: " + std::to_string(int(FinalScore( Score, Score[1]))), {340 + 95, y + 25}, 11, FirstG, SecondG, window, font);

        WordStyle("LOSER", {380 - 200, y}, 16, FirstG, SecondG, window, font);
        WordStyle("FINAL POINTS: " + std::to_string(int(FinalScore( Score, Score[0]))), {380 - 200, y + 25}, 11, FirstG, SecondG, window, font);
    }

}


