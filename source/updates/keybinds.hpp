#pragma once

void Check_KeyBinds() {
    int numkeys;
    const bool *keyboard_state = SDL_GetKeyboardState(&numkeys);

    if (keyboard_state[SDL_SCANCODE_I]) {camera_data.camZ = camera_data.camZ - (movement_configs.cam_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_O]) {camera_data.camZ = camera_data.camZ + (movement_configs.cam_speed * time_data.delta_time);};
    
    if (keyboard_state[SDL_SCANCODE_LEFT]) {camera_data.camX = camera_data.camX - (movement_configs.cam_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_RIGHT]) {camera_data.camX = camera_data.camX + (movement_configs.cam_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_UP]) {camera_data.camY = camera_data.camY - (movement_configs.cam_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_DOWN]) {camera_data.camY = camera_data.camY + (movement_configs.cam_speed * time_data.delta_time);};
 
    if (keyboard_state[SDL_SCANCODE_A]) {camera_data.angleY = camera_data.angleY - (movement_configs.rot_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_D]) {camera_data.angleY = camera_data.angleY + (movement_configs.rot_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_S]) {camera_data.angleX = camera_data.angleX - (movement_configs.rot_speed * time_data.delta_time);};
    if (keyboard_state[SDL_SCANCODE_W]) {camera_data.angleX = camera_data.angleX + (movement_configs.rot_speed * time_data.delta_time);};
    
    if (keyboard_state[SDL_SCANCODE_Q]) {move_vertex.Move(-movement_configs.frame_speed,0,0);};
    if (keyboard_state[SDL_SCANCODE_E]) {move_vertex.Move(movement_configs.frame_speed,0,0);};
    if (keyboard_state[SDL_SCANCODE_T]) {move_vertex.Move(0,-movement_configs.frame_speed,0);};
    if (keyboard_state[SDL_SCANCODE_G]) {move_vertex.Move(0,movement_configs.frame_speed,0);};
    if (keyboard_state[SDL_SCANCODE_R]) {move_vertex.Move(0,0,-movement_configs.frame_speed);};
    if (keyboard_state[SDL_SCANCODE_F]) {move_vertex.Move(0,0,movement_configs.frame_speed);};
};