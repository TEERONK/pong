
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "vector.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  bool
  detectCollision(sf::Sprite ball, sf::Sprite paddleBlue, sf::Sprite paddleRed);

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Sprite paddleBlue;
  sf::Sprite paddleRed;
  sf::Texture ball_texture;
  sf::Texture paddleBlue_texture;
  sf::Texture paddleRed_texture;
  sf::Font font;
  sf::Text title_text;
  sf::Text title_text2;
  sf::Text player1_win;
  sf::Text player2_win;
  sf::Text score1_text;
  sf::Text score2_text;

  bool in_menu;
  sf::Text menu_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;
  bool player1Win = false;
  bool player2Win = false;

  float speed = 150;

  int score1 = 0;
  int score2 = 0;

  vector ball_direction;
};

#endif // PONG_GAME_H
