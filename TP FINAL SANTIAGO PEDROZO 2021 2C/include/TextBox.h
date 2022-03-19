#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <string.h>



class TextBox
{
    private:
        sf::Text _TextBox;
        std::ostringstream _Text;
        bool _IsSelected;
        int _Limit;

        void inputLogic(int charTyped);
        void Delete();
    public:
        TextBox();

        void SetFont(sf::Font& font);
        void SetPosition(sf::Vector2f pos);
        void SetLimit(int lim);
        void SetSelected(bool sel);

        bool GetSelected();
        const char* GetText();

        void TypedOn(sf::Event& Input);

        void drawTo(sf::RenderWindow& window);

        sf::Text& GetTextBox();

};

#endif // TEXTBOX_H
