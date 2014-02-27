#include "moving_game_object.hpp"
#include "moving_game_object_manager.hpp"

Moving_game_object_manager::Moving_game_object_manager() {

}

Moving_game_object_manager::~Moving_game_object_manager() {

}

void Moving_game_object_manager::Set_focused_object(
                                    Moving_game_object * focus_object ) {
    m_focused_object = focus_object;
}

Moving_game_object const * Moving_game_object_manager::Get_focused_object() const {
    return const_cast< Moving_game_object const * >( m_focused_object );
}
