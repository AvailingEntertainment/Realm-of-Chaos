#ifndef INPUT_H
#define INPUT_H

enum {
    KEY_ESC     = 27,
    ARROW_UP    = 256 + 72,
    ARROW_DOWN  = 256 + 80,
    ARROW_LEFT  = 256 + 75,
    ARROW_RIGHT = 256 + 77,
    KEY_F1      = 256 + 59,
    KEY_F2      = 256 + 60,
    KEY_F3      = 256 + 61,
    KEY_F4      = 256 + 62,
    KEY_F5      = 256 + 63,
    KEY_F6      = 256 + 64,
    KEY_F7      = 256 + 65,
    KEY_F8      = 256 + 66,
    KEY_F9      = 256 + 67,
    KEY_F10     = 256 + 68,
    KEY_F11     = 256 + 69,
    KEY_F12     = 256 + 70,
    TRASH	      = 7,
    COMMON      = 15,
    UNCOMMON    = 10,
    RARE	      = 9,
    EPIC	      = 13,
    LEGENDARY   = 6
};

class Input
{
    public:
        Input();
        virtual ~Input();
        void getInput(bool);
    private:
};

#endif // INPUT_H

