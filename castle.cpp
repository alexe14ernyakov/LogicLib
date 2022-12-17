#include "castle.h"
#include "config.h"

namespace td{

    Castle::Castle() {
        max_level          = config::GLOBAL_CONST_CASTLE_MAX_LEVEL;
        max_health         = config::GLOBAL_CONST_CASTLE_MAX_HEALTH;
        current_health     = config::GLOBAL_CONST_CASTLE_MAX_HEALTH;
        yield              = config::GLOBAL_CONST_CASTLE_YIELD;
        regeneration_speed = config::GLOBAL_CONST_CASTLE_REGENERATION_SPEED;
        upgrade_price      = config::GLOBAL_CONST_CASTLE_UPGRADE_PRICE;
    }

    bool Castle::check_entire() const {
        return is_entire;
    }

    void Castle::get_damage(float dmg) {
        current_health -= dmg;
        if(current_health <= 0)
            is_entire = false;
    }

}