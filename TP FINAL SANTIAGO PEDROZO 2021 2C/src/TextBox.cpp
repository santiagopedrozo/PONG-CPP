#include "TextBox.h"

#define DeleteKey 8
#define EnterKey 13
#define SpaceKey 27

TextBox::TextBox()
{
    _IsSelected=false;
    _Limit=10;
    if(_IsSelected) _TextBox.setString("_");
    else _TextBox.setString("");
}


void TextBox::inputLogic(int charTyped){
    if(charTyped != DeleteKey && charTyped != EnterKey && charTyped != SpaceKey){
        _Text << static_cast<char>(charTyped);
    }
    else if(charTyped == DeleteKey){
        if(_Text.str().length() > 0){
           Delete();
        }
    }

    _TextBox.setString(_Text.str() + "_");
}

void TextBox::Delete(){
    std::string t = _Text.str();
    std::string newT = "";
    for(int i=0; i < t.length()-1; i++){        ///Copy all the string minus the last character
        newT += t[i];
    }
    _Text.str("");  ///clear out the string
    _Text << newT;  ///Asing new String

    _TextBox.setString(_Text.str());
}

void TextBox::SetFont(sf::Font& font){
    _TextBox.setFont(font);
}

void TextBox::SetPosition(sf::Vector2f pos){
    _TextBox.setPosition(pos);
}


void TextBox::SetLimit(int lim){
    _Limit=lim;
}

void TextBox::SetSelected(bool sel){
    _IsSelected=sel;
}

bool TextBox::GetSelected(){
    return _IsSelected;
}

void TextBox::TypedOn(sf::Event& Input){
    if(_IsSelected)
    {
        int CharTyped = Input.text.unicode;

        if(CharTyped < 256)
        {
            if(_Text.str().length() <= _Limit)
            {
                inputLogic(CharTyped);
            }
            else if(_Text.str().length() > _Limit && CharTyped == DeleteKey)
            {
                Delete();
            }
        }
    }
}

const char* TextBox::GetText(){
    return _Text.str().c_str();
}


sf::Text& TextBox::GetTextBox(){
    return _TextBox;
}

void TextBox::drawTo(sf::RenderWindow& window){
    window.draw(_TextBox);
}
