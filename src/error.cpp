#include <cstdio>
#include <cstdlib>

#include "error.hpp"

void Assert( bool condition, Error_code error_code ) {
    if( !condition ) {
        if( ( error_code & EC_FATAL ) != 0 ) {
            // is a fatal error.
            fprintf( stderr, "Fatal error: 0x%05X. Now exiting.\n",
                             error_code );
            exit( 1 );
        } else {
            fprintf( stderr, "Error: 0x%05X (this probably shouldn't happen.\n",
                             error_code );
        }
    }
}
