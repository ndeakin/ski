#ifndef _ERROR_HPP
#define _ERROR_HPP

// TODO: Add error.cpp and make functions for throwing errors.
//       cstdio is included temporarily so fprintf will certainly work whereever
//       error codes are used (since these are always printed to stderr at the
//       moment; making message boxes or something would be nice in the future).
#include <cstdio>

enum Error_code {
    // 0x?XXXX -> '?' is 0 for fatal error, otherwise 1
    //         -> The more significant 'XX' identifies the nature of the error
    //         -> The less significant 'XX' identifies that specific error

    // 0x?00XX - General game errors
    FE_GAME_IN_UNKNOWN_GAME_STATE                       = 0x00001,

    // 0x?01XX - Graphics related errors
    FE_SPRITE_SHEET_LOAD_FAILURE                        = 0x00101,
    EC_VISIBLE_GAME_OBJECT_TEXTURE_LOAD_FAILURE         = 0x10101,
};

#endif // !_ERROR_HPP
