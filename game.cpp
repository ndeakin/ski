#include "game.hpp"

sf::RenderWindow  Game::g_main_window;
Game_object_manager Game::g_game_object_manager;

void Game::Start() {

}

sf::RenderWindow & Game::Get_window() {
  return g_main_window;
}

const sf::Keyboard::Key & Game::Get_input() {
  
}

const Game_object_manager & Game::Get_game_object_manager() {
  return g_game_object_manager;
}

bool Game::Is_exiting() {
  return true;
}

void Game::Game_loop() {
  
}

void Game::Show_splash_screen() {

}

bool Game::Show_menu() {
  return true;
}

void Game::Create_players() {

}
