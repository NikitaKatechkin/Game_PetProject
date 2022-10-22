#include "GameObject.h"

GameObject::GameObject()
{
    m_textureContext.m_area = sf::IntRect(0, 0, 0, 0);
}

void GameObject::setSize(const sf::Vector2u& size)
{
    m_textureContext.m_area = sf::IntRect(m_textureContext.m_area.left, 
                                          m_textureContext.m_area.top,
                                          size.x,
                                          size.y);
}

sf::Vector2u GameObject::getSize()
{
    return sf::Vector2u(m_textureContext.m_area.width, m_textureContext.m_area.height);
}

void GameObject::setTextureAsset(const std::string& pathToTexture)
{
    m_textureContext.m_pathToTexture = pathToTexture;
}

void GameObject::setTextureContext(const TextureContext& textureContext)
{
    m_textureContext = textureContext;
}

TextureContext GameObject::getTextureContext()
{
    return m_textureContext;
}

sf::Sprite GameObject::getSprite()
{
    return m_sprite;
}

void GameObject::update()
{
    m_texture = sf::Texture();
    m_texture.loadFromFile(m_textureContext.m_pathToTexture, m_textureContext.m_area);

    m_sprite = sf::Sprite(m_texture);
}

void GameObject::draw(Window* window)
{
    window->draw(m_sprite);
}
