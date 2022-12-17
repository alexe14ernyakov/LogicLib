#include <iostream>
#include "aviation.h"
#include "config.h"

namespace td {

    Aviation::Aviation(float x_pos, float y_pos) {
        is_alive = true;
        x = x_pos;
        y = y_pos;
        max_health = config::GLOBAL_CONST_AVIATION_MAX_HEALTH;
        current_health = config::GLOBAL_CONST_AVIATION_MAX_HEALTH;
        regeneration_speed = config::GLOBAL_CONST_AVIATION_REGENERATION_SPEED;
        move_speed = config::GLOBAL_CONST_AVIATION_MOVE_SPEED;
        castle_damage = config::GLOBAL_CONST_AVIATION_CASTLE_DAMAGE;
        damage = config::GLOBAL_CONST_AVIATION_DAMAGE;
        ammunition = config::GLOBAL_CONST_AVIATION_AMMUNITION;
    }

    bool Aviation::get_is_alive() const {
        return is_alive;
    }

    int Aviation::horizontal_index() const {
        return (int)( (x - 130.0f) / 100);
    }

    int Aviation::vertical_index() const {
        return (int)( (y - 60.0f) / 100);
    }

    std::unique_ptr<Enemy> Aviation::clone() const {
        return std::make_unique<Aviation>(*this);
    }

    void Aviation::make_move(std::vector<Line> field) {
        int v = vertical_index();
        float left = move_speed;

        std::cout << x << " " << y << std::endl;
        if(x < 130.0f)
            return;

        if ( field[v].line[(int)((x - 130.0f - left - 50.0f) / 100)].get_type() != 2 ){
            x -= left;
            return;
        }
        else if(v < 3){
            y += left;
            return;
        }
        else{
            y -= left;
            return;
        }
    }




}