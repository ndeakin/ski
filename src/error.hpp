#ifndef _ERROR_HPP
#define _ERROR_HPP

enum Error_code {
    // 0x?XXXX -> '?' is 0 for fatal error, otherwise 1
    //         -> The more significant 'XX' identifies the nature of the error
    //         -> The less significant 'XX' identifies that specific error

    // 0x?01XX - Graphics related errors
    FE_SPRITE_SHEET_LOAD_FAILURE                        = 0x00101,
    EC_VISIBLE_GAME_OBJECT_TEXTURE_LOAD_FAILURE         = 0x10101,
};

#endif // !_ERROR_HPP
