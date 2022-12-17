#ifndef EA_GAME_FIELD_H
#define EA_GAME_FIELD_H
#include <vector>
#include <list>
#include <memory>
#include <iostream>
#include "tile.h"
#include "enemy.h"
#include "castle.h"
#include "config.h"

namespace td{



    class Game_Field{
    private:
        bool                              game_status = true;
        int                               height;
        int                               width;
        std::vector<Line>                 game_field;
        int                               enemies_count = 0;
        std::list<std::unique_ptr<Enemy>> enemies;
        std::unique_ptr<Castle>           castle;

    public:
        Game_Field();
        bool get_game_status() const;
        void check_game();
        void print_game_field() const;
        void add_enemy(const Enemy& enemy);
        void next_step();
        void check_castle() const;
        void check_deaths();
    };
}

#endif
