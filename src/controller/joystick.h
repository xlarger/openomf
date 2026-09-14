#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "controller/controller.h"
#include <SDL.h>

typedef struct {
    int x_axis;
    int y_axis;
    int dpad[4];
    int punch;
    int kick;
    int escape;
} joystick_keys;

typedef struct {
    SDL_GameController *joy;
    SDL_Haptic *haptic;
    joystick_keys *keys;
    int rumble;
} joystick;

int joystick_create(controller *ctrl, int joystick_id);
void joystick_free(controller *ctrl);

int joystick_count(void);
int joystick_nth_id(int n);
int joystick_guid_to_id(const char *guid_str, int offset);
int joystick_guid_offset(int device_index);

void joystick_init(void);
void joystick_close(void);
void joystick_menu_poll_all(controller *menu_ctrl, ctrl_event **ev);
void joystick_deviceadded(int sdl_joystick_index);
void joystick_deviceremoved(int sdl_joystick_instance_id);

#endif // JOYSTICK_H
