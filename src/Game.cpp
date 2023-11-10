
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  in_menu = true;

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  title_text.setString("PONG");
  title_text.setFont(font);
  title_text.setCharacterSize(70);
  title_text.setFillColor(sf::Color(255, 255, 255, 255));
  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 10 - title_text.getGlobalBounds().height / 2);

  // init menu text in game
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  title_text2.setString("P O N G");
  title_text2.setFont(font);
  title_text2.setCharacterSize(100);
  title_text2.setFillColor(sf::Color(255, 255, 255, 200));
  title_text2.setPosition(
    window.getSize().x / 2 - title_text2.getGlobalBounds().width / 2,
    window.getSize().y / 2 - title_text2.getGlobalBounds().height / 2);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  play_option.setString("Play");
  play_option.setFont(font);
  play_option.setCharacterSize(20);
  play_option.setFillColor(sf::Color(255, 255, 255, 255));
  play_option.setPosition(
    window.getSize().x / 4 - play_option.getGlobalBounds().width / 2,
    window.getSize().y / 2 - play_option.getGlobalBounds().height / 2);

  // init menu text
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(20);
  quit_option.setFillColor(sf::Color(255, 255, 255, 255));
  quit_option.setPosition(
    (window.getSize().x / 4 - quit_option.getGlobalBounds().width / 2) * 3,
    window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2);

  if (!ball_texture.loadFromFile("Data/Images/ball.png"))
  {
    std::cout << "ball texture did not load \n";
  }
  ball.setTexture(ball_texture);
  ball.setPosition(
    window.getSize().x / 2 - ball.getGlobalBounds().width / 2,
    window.getSize().y / 2 - ball.getGlobalBounds().height / 2);
  ball.setScale(0.5, 0.5);

  if (!paddleBlue_texture.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "paddleBlue texture did not load \n";
  }
  paddleBlue.setTexture(paddleBlue_texture);
  paddleBlue.setRotation(90);
  paddleBlue.setPosition(
    0 + paddleBlue.getGlobalBounds().width,
    window.getSize().y / 2 - paddleBlue.getGlobalBounds().height / 2);

  if (!paddleRed_texture.loadFromFile("Data/Images/paddleRed.png"))
  {
    std::cout << "paddleRed texture did not load \n";
  }
  paddleRed.setTexture(paddleRed_texture);
  paddleRed.setRotation(90);
  paddleRed.setPosition(
    window.getSize().x,
    window.getSize().y / 2 - paddleRed.getGlobalBounds().height / 2);

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  score2_text.setString(std::to_string(score2));
  score2_text.setFont(font);
  score2_text.setCharacterSize(20);
  score2_text.setFillColor(sf::Color(255, 255, 255, 255));
  score2_text.setPosition(
    (window.getSize().x / 4 - score2_text.getGlobalBounds().width / 2) * 3,
    window.getSize().y / 8 - score2_text.getGlobalBounds().height / 2);

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  score1_text.setString(std::to_string(score1));
  score1_text.setFont(font);
  score1_text.setCharacterSize(20);
  score1_text.setFillColor(sf::Color(255, 255, 255, 255));
  score1_text.setPosition(
    (window.getSize().x / 9 - score1_text.getGlobalBounds().width / 2) * 3,
    window.getSize().y / 8 - score1_text.getGlobalBounds().height / 2);

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  player1_win.setString("PLAYER 1 WINS");
  player1_win.setFont(font);
  player1_win.setCharacterSize(70);
  player1_win.setFillColor(sf::Color(255, 255, 255, 255));
  player1_win.setPosition(
    window.getSize().x / 2 - player1_win.getGlobalBounds().width / 2,
    window.getSize().y / 10 - player1_win.getGlobalBounds().height / 2);
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "font did not load \n";
  }
  player2_win.setString("PLAYER 2 WINS");
  player2_win.setFont(font);
  player2_win.setCharacterSize(70);
  player2_win.setFillColor(sf::Color(255, 255, 255, 255));
  player2_win.setPosition(
    window.getSize().x / 2 - player2_win.getGlobalBounds().width / 2,
    window.getSize().y / 10 - player2_win.getGlobalBounds().height / 2);

  return true;
}

void Game::update(float dt)
{
  if (
    ball.getPosition().y >=
      (window.getSize().y - ball.getGlobalBounds().height) ||
    (ball.getPosition().y <= 0))
  {
    ball_direction.yoffset = -ball_direction.yoffset;
  }

  ball.move(
    ball_direction.xoffset * speed * dt, ball_direction.yoffset * speed * dt);

  if (detectCollision(ball, paddleBlue, paddleRed))
  {
    ball_direction.xoffset = -ball_direction.xoffset;
  }

  if (ball.getPosition().x >= window.getSize().x)
  {
    score1++;
    score1_text.setString(std::to_string(score1));
    ball.setPosition(
      window.getSize().x / 2 - ball.getGlobalBounds().width / 2,
      window.getSize().y / 2 - ball.getGlobalBounds().height / 2);
    ball_direction.xoffset = -ball_direction.xoffset;
  }
  if (ball.getPosition().x < 0)
  {
    score2++;
    score2_text.setString(std::to_string(score2));
    ball.setPosition(
      window.getSize().x / 2 - ball.getGlobalBounds().width / 2,
      window.getSize().y / 2 - ball.getGlobalBounds().height / 2);
    ball_direction.xoffset = -ball_direction.xoffset;
  }
}

void Game::render()
{
  if (in_menu)
  {
    window.draw(title_text);
    window.draw(play_option);
    window.draw(quit_option);
  }
  else
  {
    window.draw(title_text2);
    window.draw(ball);
    window.draw(score1_text);
    window.draw(score2_text);
    window.draw(paddleBlue);
    window.draw(paddleRed);
  }
}

void Game::mouseClicked(sf::Event event) {}

void Game::keyPressed(sf::Event event)
{
  if (
    (event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play_option.setString("> Play <");
      quit_option.setString("Quit");
    }
    else
    {
      play_option.setString("Play");
      quit_option.setString("> Quit <");
    }
  }
  if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }

  if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }

  if (event.key.code == sf::Keyboard::W)
  {
    if (paddleBlue.getPosition().y >= 0)
    {
      paddleBlue.move(0, -5);
    }
  }
  if (event.key.code == sf::Keyboard::S)
  {
    if (
      paddleBlue.getPosition().y + paddleBlue.getGlobalBounds().height <=
      window.getSize().y)
    {
      paddleBlue.move(0, +5);
    }
  }

  if (event.key.code == sf::Keyboard::Up)
  {
    if (paddleRed.getPosition().y >= 0)
    {
      paddleRed.move(0, -5);
    }
  }
  if (event.key.code == sf::Keyboard::Down)
  {
    if (
      paddleRed.getPosition().y + paddleRed.getGlobalBounds().height <=
      window.getSize().y)
    {
      paddleRed.move(0, +5);
    }
  }
}

bool Game::detectCollision(
  sf::Sprite ball, sf::Sprite paddleBlue, sf::Sprite paddleRed)
{
  if (
    (ball.getPosition().x <= paddleBlue.getPosition().x &&
     ball.getPosition().y >= paddleBlue.getPosition().y &&
     ball.getPosition().y <=
       paddleBlue.getPosition().y + paddleBlue.getGlobalBounds().height) ||
    (ball.getPosition().x + ball.getGlobalBounds().width >=
       paddleRed.getPosition().x &&
     ball.getPosition().y >= paddleRed.getPosition().y &&
     ball.getPosition().y <=
       paddleRed.getPosition().y + paddleRed.getGlobalBounds().height))
  {
    return true;
  }
  else
  {
    return false;
  }
}
