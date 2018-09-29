#include "Background.h"

Background::Background()
{
	sprites = 0;

	texture.loadFromFile("texture/sonico.jpg");

	background.setPosition(0,0);
	background.setTexture(texture);
	//background.setScale((size.x/background.getTextureRect().width), 1);
}

Background::Background(sf::Vector2f Size){
	sprites = 0;
	setSize(Size);

	if(!texture.loadFromFile("texture/miku.jpg")){
		std::cout << "Error loading background texture.\n";
	}

	background.setPosition(0,0);
	background.setTexture(texture);
	background.setScale((size.x/background.getTextureRect().width), (size.y/background.getTextureRect().height));

	//background.setColor(sf::Color(0,0,0,100));
	texture.setSmooth(1);	//pixels are less noticeable
	//texture.loadFromFile("texture/sonico.jpg");	//test: the texture is binded with the sprite, whatever I load the sprite shows
}

Background::Background(sf::Vector2u Size){
	sprites = 0;
	setSize(sf::Vector2f(Size.x,Size.y));

	texture.loadFromFile("texture/sonico.jpg");

	background.setPosition(0,0);
	background.setTexture(texture);
	background.setScale((size.x/background.getTextureRect().width), (size.y/background.getTextureRect().height));
}

Background::~Background(){

}

void Background::setSize(sf::Vector2f Size){
	size = Size;
}

sf::Vector2f Background::getSize(){
	return size;
}

unsigned int Background::getSprites(){
	return sprites;
}

void Background::move(float x, float y){

}

void Background::move(sf::Vector2f speed){

}

void Background::draw(sf::RenderWindow* window){
	window->draw(background);
}
