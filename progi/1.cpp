
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>


class DrawManager{
    public:
    sf::RenderWindow window(sf::VideoMode(800, 600), "My okno");
    
    void window_clear(){
        window.clear();
        }
    void draw_text(sf::Text txt, int x0, int y0){
        txt.setPosition(x0, y0);
        window.draw(txt);
    }    
    void draw_sprite(sf::Sprite spt, int x0, int y0){
        spt.setPosition(x0, y0);
        window.draw(spt);
    }
    void draw_display(){
        window.display();
    }


};

class DataStorage{
    public:
    std::vector<std::string> strings;
    std::vector<sf::Sprite> sprites;
    std::vector<sf::Font> fonts;
    std::vector<sf::Text> texts;
    int i=5;
    void read_file(std::string name){
        std::ifstream file(name);
        std::string s((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
        strings.push_back(s);
    }
    void read_font(std::string name){
        sf::Font font;
        font.loadFromFile(name);
        fonts.push_back(font);
    }
    void read_sprite(std::string name){
        sf::Texture texture;
        texture.loadFromFile(name);
        sf::Sprite sprite(texture);
        sprites.push_back(sprite);
    }
    void converter(std::string s, sf::Font font, int size){
        std::string str;
        for(char a:s){
            str+=a;
            if( a=='\n'){
                sf::Text new_text(str, font, size);
                texts.push_back(new_text);
                str="";
            }
        
    }
    
    }



};
int main(){
        
    
    
    DataStorage dat;

    dat.read_file("text");
    dat.strings.push_back("sad");
    dat.read_font("arial.ttf");
    dat.read_sprite("logo.png");
    dat.converter(dat.strings[0], dat.fonts[0],20);
    DrawManager draw;
    draw.window(sf::VideoMode(800, 600), "My okno");
    
    
    while(draw.window.isOpen())
    {   
        sf::Event event;
        while(draw.window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                draw.window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                
                fflush(0);
                if(event.type == sf::Event::KeyPressed){
                    dat.i +=dat.i;
                }
            }
            
        }
        draw.window_clear();
        /*for( sf::Text tmp; hend.texts.begin(); hend.texts.end()){
            draw.draw_text(converter(dat.strings[0], dat.fonts[0],20),0,dat.i);
        }*/
        draw.draw_display();
    }
    return 0;
}
