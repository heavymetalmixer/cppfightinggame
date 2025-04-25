#ifndef INPUT_HPP
#define INPUT_HPP

namespace Input {
    struct InputCommand {
        bool Up { false };
        bool Down { false };
        bool Left { false };
        bool Right { false };
        bool Attack { false };

        // Resets inputs back to their default values
        void Reset() {
            //*this = InputCommand {};
            Up = false;
            Down = false;
            Left = false;
            Right = false;
            Attack = false;
        }
    };
}

#endif // INPUT_HPP
