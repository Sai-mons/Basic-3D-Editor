#pragma once

class Loop_Updates {
    private:
        void Events_Check(const SDL_Event& event) {
                if (event.type == SDL_EVENT_QUIT) {
                    sdl_data.app_running = false;
                } else if (event.type == SDL_EVENT_MOUSE_MOTION) {
                    button_mouse.Check_Action(event.motion.x, event.motion.y, false);
                } else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && event.button.button == SDL_BUTTON_LEFT) {
                    button_mouse.Check_Action(event.motion.x, event.motion.y, true);
                };
        };

    public:
        void Run_Update_Loop() {
            while (sdl_data.app_running) {
                Update_Fps();

                SDL_Event event;
                while (SDL_PollEvent(&event)) {Events_Check(event);};

                Check_KeyBinds();
                Update_Screen();
                SDL_Delay(8);
            };
        };
};

Loop_Updates update_loop;