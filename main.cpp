#include <iostream>
#include "game_field.h"
#include "light_infantry.h"
#include "aviation.h"

int main() {

    td::Game_Field gf;
    gf.add_enemy(td::Aviation(140.0f, 410.0f));
    gf.add_enemy(td::Aviation(980.0f, 310.0f));
    gf.add_enemy(td::Aviation(330.0f, 210.0f));
    gf.add_enemy(td::Aviation(480.0f, 360.0f));
    gf.add_enemy(td::Aviation(270.0f, 110.0f));
    gf.add_enemy(td::Aviation(800.0f, 30.0f));
    gf.print_game_field();
    while (gf.get_game_status()){
        gf.next_step();
    }
    if(!gf.get_game_status())
        std::cout << "GAME OVER";
    return 0;
}
