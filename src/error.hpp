#ifndef _ERROR_HPP
#define _ERROR_HPP

enum Error_code {
    // 0x?XXXX -> '?' is 1 for fatal error, otherwise 0
    //         -> The more significant 'XX' identifies the nature of the error
    //         -> The less significant 'XX' identifies that specific error

    EC_FATAL                                                = 0x10000,

    // 0x?00XX - General game errors
    FE_GAME_IN_UNKNOWN_GAME_STATE                           = 0x10001,
    EC_GAME_ATTEMPTED_GATE_KEEPING_WITHOUT_SKIER_OR_COURSE  = 0x00001,

    // 0x?01XX - Graphics related errors
    FE_SPRITE_SHEET_LOAD_FAILURE                            = 0x10101,
    EC_VISIBLE_GAME_OBJECT_TEXTURE_LOAD_FAILURE             = 0x00101,
};

// Throw error_code if condition is false
void Assert( bool condition, Error_code error_code );

#endif // !_ERROR_HPP
