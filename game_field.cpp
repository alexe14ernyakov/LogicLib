#include "game_field.h"
#include "config.h"
#include "light_infantry.h"

namespace td{

    Game_Field::Game_Field(){
        height = config::GLOBAL_CONST_HEIGHT;
        width  = config::GLOBAL_CONST_WIDTH;
        for(const auto & i : config::GLOBAL_CONST_GAME_FIELD){
            Line l;
            for(int j : i){
                l.line.emplace_back(j);
            }
            game_field.push_back(l);
        }
        enemies = std::list<std::unique_ptr<Enemy>>();
        castle  = std::make_unique<Castle>();
    }

    bool Game_Field::get_game_status() const {
        return game_status;
    }

    void Game_Field::check_game() {
        game_status = castle->check_entire();
    }

    void Game_Field::print_game_field() const{
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                switch ( game_field[i].line[j].get_type() ) {
                    case(0): std::cout << "P "; break;
                    case(1): std::cout << "W "; break;
                    case(2): std::cout << "M "; break;
                    default: std::cout << "U "; break;
                }
            }
            std::cout << std::endl;
        }
    }

    void Game_Field::add_enemy(const Enemy& enemy) {
        enemies_count++;
        enemies.push_front(enemy.clone());
    }

    void Game_Field::next_step() {

        //std::cout << enemies.size() << std::endl;
        if(!enemies.empty()) {
            for (auto &enemy: enemies) {
                enemy->make_move(game_field);
            }
        }

        check_castle();
        check_deaths();
        check_game();
    }

    void Game_Field::check_castle() const {
        for(auto & enemy : enemies){
            if(enemy->get_x() < 130.0f){
                castle->get_damage(enemy->get_castle_damage());
                enemy->kill();
            }
        }
    }

    void Game_Field::check_deaths() {
        std::cout << enemies.size() << std::endl;

        if(enemies_count != 0){
            auto it(enemies.begin());
            while (it != enemies.end()) {
                if (!it->get()->get_is_alive()) {
                    enemies.erase(it);
                    enemies_count--;
                    std::cout << "Sucsessfull deletion" << std::endl;
                }
                it++;
            }
        }
    }

}
