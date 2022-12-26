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

    void Castle::increase_balance(int amount) {
        balance += amount;
    }

    void Castle::decrease_balance(int amount) {
        if(amount > balance)
            throw std::logic_error("You haven't got enough money...");
        else
            balance -= amount;
    }

    bool Castle::update_available() const {
        if(balance < upgrade_price){
            return false;
        }
        else if(level == max_level){
            return false;
        }
        else
            return true;
    }

    void Castle::get_damage(float dmg) {
        current_health -= dmg;
        if(current_health <= 0)
            is_entire = false;
    }

    void Castle::upgrade() {
        max_health = max_health * 1.2f;
        current_health = max_health;
        yield = yield + (float)level;
        regeneration_speed = regeneration_speed * 1.2f + (regeneration_speed/max_health)/4;
        decrease_balance(upgrade_price);
        upgrade_price = (int)(upgrade_price*1.5);
    }

}