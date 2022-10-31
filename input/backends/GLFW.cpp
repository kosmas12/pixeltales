//
// Created by kosmas on 31/1/22.
//

#include <fstream>
#include <iostream>
#include "../Input.h"
#include "../../graphics/backends/OpenGL/OpenGL_common.h"

Input::Input(const std::string& fileName) {
    this->parseInputConfigFile(fileName);
}

Input::~Input() {

}

bool Input::buttonIsPressed(Action action) {
    updateButtonStates();
    return buttonStates[action].isPressed;
}

void Input::updateButtonStates() {
    for (int i = 0; i < ACTION_NUM_ACTIONS; ++i) {
        buttonStates[i].isPressed = glfwGetKey(window, buttonStates[i].keyboardScanCode);
    }

}
void Input::parseInputConfigFile(const std::string& fileName) {
    std::ifstream inputConfigFile(fileName);

    std::string currentLine;

    while (std::getline(inputConfigFile, currentLine)) {
        std::transform(currentLine.begin(), currentLine.end(), currentLine.begin(), ::toupper);
        Action buttonToAssignTo;
        std::string action = currentLine.substr(0,currentLine.find(' '));

        if (action == "MOVE_CHARACTER_FORWARD") {
            buttonToAssignTo = ACTION_MOVE_CHARACTER_FORWARD;
        }
        if (action == "MOVE_CHARACTER_BACKWARD") {
            buttonToAssignTo = ACTION_MOVE_CHARACTER_BACKWARD;
        }
        if (action == "MOVE_CHARACTER_LEFT") {
            buttonToAssignTo = ACTION_MOVE_CHARACTER_LEFT;
        }
        if (action == "MOVE_CHARACTER_RIGHT") {
            buttonToAssignTo = ACTION_MOVE_CHARACTER_RIGHT;
        }
        if (action == "MOVE_SELECTION_UP") {
            buttonToAssignTo = ACTION_MOVE_SELECTION_UP;
        }
        if (action == "MOVE_SELECTION_DOWN") {
            buttonToAssignTo = ACTION_MOVE_SELECTION_DOWN;
        }
        if (action == "MOVE_SELECTION_LEFT") {
            buttonToAssignTo = ACTION_MOVE_SELECTION_LEFT;
        }
        if (action == "MOVE_SELECTION_RIGHT") {
            buttonToAssignTo = ACTION_MOVE_SELECTION_RIGHT;
        }
        if (action == "CONFIRM_SELECTION") {
            buttonToAssignTo = ACTION_CONFIRM_SELECTION;
        }
        if (action == "MENU") {
            buttonToAssignTo = ACTION_MENU;
        }
        if (action == "INVENTORY") {
            buttonToAssignTo = ACTION_INVENTORY;
        }
        if (action == "STATS") {
            buttonToAssignTo = ACTION_STATS;
        }
        if (action == "INTERACT") {
            buttonToAssignTo = ACTION_INTERACT;
        }
        std::string binding = currentLine.substr(currentLine.find(' ') + 1);

        unsigned long i = 0;
        while (binding.at(i) == ' ') {
            binding.erase(i++);
        }
        i = binding.size() - 1;
        while (binding.at(i) == ' ') {
            binding.erase(i--);
        }

        int scanCode = '\0';
        if (binding.length() == 1) {
            // GLFW's defines seem to follow standard ASCII codes, so this will simply work
            scanCode = binding.at(0);
        }
        else {
            // Special non-alphanumeric characters
            if (binding == "SPACE") {
                scanCode = GLFW_KEY_SPACE;
            }
            else if (binding == "ESCAPE" || binding == "ESC") {
                scanCode = GLFW_KEY_ESCAPE;
            }
            else if (binding == "ENTER") {
                scanCode = GLFW_KEY_ENTER;
            }
            else if (binding == "INSERT") {
                scanCode = GLFW_KEY_INSERT;
            }
            else if (binding == "DELETE") {
                scanCode = GLFW_KEY_DELETE;
            }
            else if (binding == "RIGHT") {
                scanCode = GLFW_KEY_RIGHT;
            }
            else if (binding == "LEFT") {
                scanCode = GLFW_KEY_LEFT;
            }
            else if (binding == "DOWN") {
                scanCode = GLFW_KEY_DOWN;
            }
            else if (binding == "UP") {
                scanCode = GLFW_KEY_UP;
            }
            else if (binding == "PAGEUP" || binding == "PGUP") {
                scanCode = GLFW_KEY_PAGE_UP;
            }
            else if (binding == "PAGEDOWN" || binding == "PGDN") {
                scanCode = GLFW_KEY_PAGE_DOWN;
            }
            else if (binding == "HOME") {
                scanCode = GLFW_KEY_HOME;
            }
            else if (binding == "END") {
                scanCode = GLFW_KEY_END;
            }
            else if (binding == "CAPS_LOCK") {
                scanCode = GLFW_KEY_CAPS_LOCK;
            }
            else if (binding == "SCROLL_LOCK") {
                scanCode = GLFW_KEY_SCROLL_LOCK;
            }
            else if (binding == "NUM_LOCK") {
                scanCode = GLFW_KEY_NUM_LOCK;
            }
            else if (binding == "PRINT_SCREEN" || binding == "PRTSCR") {
                scanCode = GLFW_KEY_PRINT_SCREEN;
            }
            else if (binding == "PAUSE") {
                scanCode = GLFW_KEY_PAUSE;
            }
            else if (binding == "F1") {
                scanCode = GLFW_KEY_F1;
            }
            else if (binding == "F2") {
                scanCode = GLFW_KEY_F2;
            }
            else if (binding == "F3") {
                scanCode = GLFW_KEY_F3;
            }
            else if (binding == "F4") {
                scanCode = GLFW_KEY_F4;
            }
            else if (binding == "F5") {
                scanCode = GLFW_KEY_F5;
            }
            else if (binding == "F6") {
                scanCode = GLFW_KEY_F6;
            }
            else if (binding == "F7") {
                scanCode = GLFW_KEY_F7;
            }
            else if (binding == "F8") {
                scanCode = GLFW_KEY_F8;
            }
            else if (binding == "F9") {
                scanCode = GLFW_KEY_F9;
            }
            else if (binding == "F10") {
                scanCode = GLFW_KEY_F10;
            }
            else if (binding == "F11") {
                scanCode = GLFW_KEY_F11;
            }
            else if (binding == "F12") {
                scanCode = GLFW_KEY_F12;
            }
            else if (binding == "F13") {
                scanCode = GLFW_KEY_F13;
            }
            else if (binding == "F14") {
                scanCode = GLFW_KEY_F14;
            }
            else if (binding == "F15") {
                scanCode = GLFW_KEY_F15;
            }
            else if (binding == "F16") {
                scanCode = GLFW_KEY_F16;
            }
            else if (binding == "F17") {
                scanCode = GLFW_KEY_F17;
            }
            else if (binding == "F18") {
                scanCode = GLFW_KEY_F18;
            }
            else if (binding == "F19") {
                scanCode = GLFW_KEY_F19;
            }
            else if (binding == "F20") {
                scanCode = GLFW_KEY_F20;
            }
            else if (binding == "F21") {
                scanCode = GLFW_KEY_F21;
            }
            else if (binding == "F22") {
                scanCode = GLFW_KEY_F22;
            }
            else if (binding == "F23") {
                scanCode = GLFW_KEY_F23;
            }
            else if (binding == "F24") {
                scanCode = GLFW_KEY_F24;
            }
            else if (binding == "F25") {
                scanCode = GLFW_KEY_F25;
            }
            else if (binding == "KP_0") {
                scanCode = GLFW_KEY_KP_0;
            }
            else if (binding == "KP_1") {
                scanCode = GLFW_KEY_KP_1;
            }
            else if (binding == "KP_2") {
                scanCode = GLFW_KEY_KP_2;
            }
            else if (binding == "KP_3") {
                scanCode = GLFW_KEY_KP_3;
            }
            else if (binding == "KP_4") {
                scanCode = GLFW_KEY_KP_4;
            }
            else if (binding == "KP_5") {
                scanCode = GLFW_KEY_KP_5;
            }
            else if (binding == "KP_6") {
                scanCode = GLFW_KEY_KP_6;
            }
            else if (binding == "KP_7") {
                scanCode = GLFW_KEY_KP_7;
            }
            else if (binding == "KP_8") {
                scanCode = GLFW_KEY_KP_8;
            }
            else if (binding == "KP_9") {
                scanCode = GLFW_KEY_KP_9;
            }
            else if (binding == "KP_DECIMAL") {
                scanCode = GLFW_KEY_KP_DECIMAL;
            }
            else if (binding == "KP_DIVIDE") {
                scanCode = GLFW_KEY_KP_DIVIDE;
            }
            else if (binding == "KP_MULTIPLY") {
                scanCode = GLFW_KEY_KP_MULTIPLY;
            }
            else if (binding == "KP_SUBTRACT") {
                scanCode = GLFW_KEY_KP_SUBTRACT;
            }
            else if (binding == "KP_ADD") {
                scanCode = GLFW_KEY_KP_ADD;
            }
            else if (binding == "KP_ENTER") {
                scanCode = GLFW_KEY_KP_ENTER;
            }
            else if (binding == "KP_EQUAL") {
                scanCode = GLFW_KEY_KP_EQUAL;
            }
            else if (binding == "SHIFT" || binding == "LSHIFT") {
                scanCode = GLFW_KEY_LEFT_SHIFT;
            }
            else if (binding == "CTRL" || binding == "CONTROL" || binding == "LCTRL" || binding == "LCONTROL") {
                scanCode = GLFW_KEY_LEFT_CONTROL;
            }
            else if (binding == "ALT" || binding == "LALT") {
                scanCode = GLFW_KEY_LEFT_ALT;
            }
            else if (binding == "SUPER" || binding == "LSUPER") {
                scanCode = GLFW_KEY_LEFT_SUPER;
            }
            else if (binding == "RSHIFT") {
                scanCode = GLFW_KEY_RIGHT_SHIFT;
            }
            else if (binding == "RCTRL" || binding == "RCONTROL") {
                scanCode = GLFW_KEY_RIGHT_CONTROL;
            }
            else if (binding == "RALT") {
                scanCode = GLFW_KEY_RIGHT_ALT;
            }
            else if (binding == "RSUPER") {
                scanCode = GLFW_KEY_RIGHT_SUPER;
            }
            else if (binding == "MENU") {
                scanCode = GLFW_KEY_MENU;
            }
            else {
                std::cerr << "Invalid mapping '" << binding << "' for " << action << std::endl;
                scanCode = GLFW_KEY_UNKNOWN;
            }
        }

        this->buttonStates[buttonToAssignTo].keyboardScanCode = scanCode;

    }

}
 