#include "light_infantry.h"
#include "config.h"

namespace td {

    Light_Infantry::Light_Infantry(float x_pos, float y_pos) {
        x = x_pos;
        y = y_pos;
        max_health         = config::GLOBAL_CONST_LIGHT_INFANTRY_MAX_HEALTH;
        current_health     = config::GLOBAL_CONST_LIGHT_INFANTRY_MAX_HEALTH;
        regeneration_speed = config::GLOBAL_CONST_LIGHT_INFANTRY_REGENERATION_SPEED;
        move_speed         = config::GLOBAL_CONST_LIGHT_INFANTRY_MOVE_SPEED;
        castle_damage      = config::GLOBAL_CONST_LIGHT_INFANTRY_CASTLE_DAMAGE;
        dodge_chance       = config::GLOBAL_CONST_LIGHT_INFANTRY_DODGE_CHANCE;
    }

    /*Light_Infantry::Light_Infantry(const Light_Infantry &source) {
        this->is_alive = source.is_alive;
        this->x = source.x;
        this->y = source.y;
        this->max_health = source.max_health;
        this->current_health = source.current_health;
        this->regeneration_speed = source.regeneration_speed;
        this->move_speed = source.move_speed;
        this->castle_damage = source.castle_damage;
        this->dodge_chance = source.dodge_chance;
    }*/

    int Light_Infantry::horizontal_index() const {
        return (int)( (x - 130.0f) / 100);
    }

    int Light_Infantry::vertical_index() const {
        return (int)( (y - 60.0f) / 100);
    }

    std::unique_ptr<Enemy> Light_Infantry::clone() const {
        return std::make_unique<Light_Infantry>(*this);
    }

    void Light_Infantry::make_move(std::vector<Line> field) {
        x -= move_speed;

        /// make_move function

        /*float left = move_speed;
        int h = horizontal_index();
        int v = vertical_index();

        if(x - 130.0f - 100.0f * (float)h - 50.0 > left){
            x -= left;
            return;
        }
        else{
            left -= (x - 130.0f - 100.0f * (float)h - 50);
            x = 130.0f + 100.0f * (float)h + 50.0f;
            if( field[v].line[h].get_type() == 0 && field[v].line[h].get_building() == nullptr){
                x -= left;
                return;
            }
            else{
                if( y > 360.0f && field[v - 1].line[h].get_building() == nullptr){
                    y -= left;
                    return;
                }
                else if( y < 360.0f && field[v + 1].line[h].get_building() == nullptr){
                    y += left;
                    return;
                }
            }
        } */

        std::cout << x << " " << y << std::endl;
    }

    bool Light_Infantry::get_is_alive() const {
        return is_alive;
    }

}