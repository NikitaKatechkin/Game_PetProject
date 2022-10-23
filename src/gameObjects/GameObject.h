#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "../window/Window.h"

struct TextureContext
{
    sf::IntRect m_area;
    std::string m_pathToTexture;
};

class GameObject
{
public:
    GameObject();
    ~GameObject() = default;

public:
    void setSize(const sf::Vector2u& size);
    sf::Vector2u getSize();

    void setTextureAsset(const std::string& pathToTexture);
    
    void setTextureContext(const TextureContext& textureContext); 
    TextureContext getTextureContext();

    sf::Sprite getSprite();

public:
    void update();
    void draw(Window* window);

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    TextureContext m_textureContext;
};

#endif