//
// Created by kosmas on 29/1/22.
//

#ifndef PIXELTALES_INPUT_H
#define PIXELTALES_INPUT_H

#include <string>

/* More might be needed eventually */
typedef enum {
    ACTION_MOVE_CHARACTER_FORWARD = 0,
    ACTION_MOVE_CHARACTER_BACKWARD,
    ACTION_MOVE_CHARACTER_LEFT,
    ACTION_MOVE_CHARACTER_RIGHT,
    ACTION_MENU,
    ACTION_INVENTORY,
    ACTION_STATS,
    ACTION_INTERACT,
    ACTION_MOVE_SELECTION_UP,
    ACTION_MOVE_SELECTION_DOWN,
    ACTION_MOVE_SELECTION_LEFT,
    ACTION_MOVE_SELECTION_RIGHT,
    ACTION_CONFIRM_SELECTION,
    ACTION_NUM_ACTIONS // Must always be at the end to give us how many enum elements we have
}Action;

typedef struct {
    Action action;
    int keyboardScanCode;
    int controllerButton;
    bool isPressed;
}Button;

class Input {
public:
    Input(const std::string& fileName);
    ~Input();
    bool buttonIsPressed(Action action);

private:
    void parseInputConfigFile(const std::string& fileName);
    Button buttonStates[ACTION_NUM_ACTIONS]{};
    void updateButtonStates();
};


#endif //PIXELTALES_INPUT_H
