//
// Created by kosmas on 29/1/22.
//

#ifndef PIXELTALES_INPUT_H
#define PIXELTALES_INPUT_H

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
    Input();
    ~Input();
    bool buttonIsPressed(Action action);

private:
    Button buttons[ACTION_NUM_ACTIONS];
    void updateButtons();
};


#endif //PIXELTALES_INPUT_H
