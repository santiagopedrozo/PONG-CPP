#include "Top3Styles.h"

void DrawMedalsBlack(sf::RenderWindow& window){
    float X=150;
    sf::Texture GoldTXT;
    sf::Texture SilverTXT;
    sf::Texture BronzeTXT;

    GoldTXT.loadFromFile("Resources/Golden.png");
    SilverTXT.loadFromFile("Resources/Silver.png");
    BronzeTXT.loadFromFile("Resources/Bronze.png");

    sf::Sprite Gold;
    sf::Sprite Silver;
    sf::Sprite Bronze;

    Gold.setTexture(GoldTXT);
    Silver.setTexture(SilverTXT);
    Bronze.setTexture(BronzeTXT);

    Gold.setPosition({X + 10, 125 + 10});
    Silver.setPosition({X + 10, 260 + 10});
    Bronze.setPosition({X + 10, 390 + 10});

    Gold.setColor(sf::Color(45, 45, 45));
    Silver.setColor(sf::Color(45, 45, 45));
    Bronze.setColor(sf::Color(45, 45, 45));

    window.draw(Gold);
    window.draw(Silver);
    window.draw(Bronze);
}

void DrawMedals(sf::RenderWindow& window){
    float X=150;
    sf::Texture GoldTXT;
    sf::Texture SilverTXT;
    sf::Texture BronzeTXT;

    GoldTXT.loadFromFile("Resources/Golden.png");
    SilverTXT.loadFromFile("Resources/Silver.png");
    BronzeTXT.loadFromFile("Resources/Bronze.png");

    sf::Sprite Gold;
    sf::Sprite Silver;
    sf::Sprite Bronze;

    Gold.setTexture(GoldTXT);
    Silver.setTexture(SilverTXT);
    Bronze.setTexture(BronzeTXT);

    Gold.setPosition({X, 125});
    Silver.setPosition({X, 260});
    Bronze.setPosition({X, 390});

    window.draw(Gold);
    window.draw(Silver);
    window.draw(Bronze);
}

void DrawScoresAndNamesTOP3(sf::RenderWindow& window, int Scores[], std::string Names[]){
    int i;
    float X=270, Y=130;

    sf::Font font;
    GetFont(font);

    sf::Color FirstB(0, 60, 64); //blue
    sf::Color SecondB(20, 173, 182);

    sf::Color SecondG(255, 253, 0); //gold
    sf::Color FirstG(253, 151, 11);

    sf::Color SecondS(208, 214, 223); //silver
    sf::Color FirstS(45, 45, 45);

    sf::Color SecondBr(255, 154, 79); //brown
    sf::Color FirstBr(122, 93, 0);

    sf::Color BlueSky(25, 211, 226); //blue Rectangle
    sf::Color Blue(0, 111, 120);

    DrawBackground(window);
    BordersLineColor(window);
    DrawMedalsBlack(window);
    DrawMedals(window);

    WordStyle(Names[0], {X, Y}, 40, FirstG, SecondG, window, font);
    WordStyle(Names[1], {X, Y + 130}, 40, FirstS, SecondS, window, font);
    WordStyle(Names[2], {X, Y + 260}, 40, FirstBr, SecondBr, window, font);

    WordStyle(std::to_string(Scores[0]), {X, Y + 65}, 35, FirstG, SecondG, window, font);
    WordStyle(std::to_string(Scores[1]), {X, Y + 195}, 35, FirstS, SecondS, window, font);
    WordStyle(std::to_string(Scores[2]), {X, Y + 325}, 35, FirstBr, SecondBr, window, font);

    DrawRectangle(window, Blue, BlueSky, {160, 35}, {480, 70});
    WordStyle("RANKING", {210, 47}, 40, FirstB, SecondB,  window, font);

}
