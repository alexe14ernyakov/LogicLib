#ifndef EA_CONFIG_H
#define EA_CONFIG_H

namespace config{

    ///    GAME FIELD
    const int GLOBAL_CONST_HEIGHT = 6;
    const int GLOBAL_CONST_WIDTH = 9;

    const int GLOBAL_CONST_GAME_FIELD[6][9] =
            {
                    {0, 0, 0, 2, 2, 1, 1, 0, 0},
                    {0, 0, 0, 2, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 1, 2, 0, 0, 0},
                    {0, 1, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 2, 0, 0, 1, 0, 0}
            };


    ///    CASTLE
    const int   GLOBAL_CONST_CASTLE_MAX_LEVEL = 5;
    const float GLOBAL_CONST_CASTLE_MAX_HEALTH = 500.0f;
    const float GLOBAL_CONST_CASTLE_YIELD = 5.0f;
    const float GLOBAL_CONST_CASTLE_REGENERATION_SPEED = 2.0f;
    const int   GLOBAL_CONST_CASTLE_UPGRADE_PRICE = 300;


    ///   LIGHT INFANTRY
    const float GLOBAL_CONST_LIGHT_INFANTRY_MAX_HEALTH = 50.0f;
    const float GLOBAL_CONST_LIGHT_INFANTRY_REGENERATION_SPEED = 0.0f;
    const float GLOBAL_CONST_LIGHT_INFANTRY_MOVE_SPEED = 30.0f;
    const float GLOBAL_CONST_LIGHT_INFANTRY_CASTLE_DAMAGE = 0.2f;
    const float GLOBAL_CONST_LIGHT_INFANTRY_DODGE_CHANCE = 0.3f;


    ///   AVIATION
    const float GLOBAL_CONST_AVIATION_MAX_HEALTH = 300.0f;
    const float GLOBAL_CONST_AVIATION_REGENERATION_SPEED = 0.0f;
    const float GLOBAL_CONST_AVIATION_MOVE_SPEED = 30.0f;
    const float GLOBAL_CONST_AVIATION_CASTLE_DAMAGE = 0.4f;
    const int   GLOBAL_CONST_AVIATION_AMMUNITION = 3;
    const float GLOBAL_CONST_AVIATION_DAMAGE = 100.0f;
}
#endif
