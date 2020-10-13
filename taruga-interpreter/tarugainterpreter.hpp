#ifndef __TARUGAINTERPRETER_HPP
#define __TARUGAINTERPRETER_HPP

#include "taruga.hpp"
#include <cstdio>

namespace taruga {

class Interpreter
{
    //!
    //! \brief save_script Saves a Taruga script that describes the action queue of the given turtle
    //! \param turtle      The turtle whose action queue will be described
    //! \param filename    The filename where the script will be saved
    //!
public:
    static void save_script(Turtle& turtle, const char * filename)
    {
        std::queue<Action> actions = turtle.get_queue(); //! Get a copy of the turtle's current action queue
        if(actions.empty()) { return; }
        FILE * outputf = std::fopen(filename, "w");  //! Using FILE* instead of ofstream because I prefer fprintf's formatting abilities.
        if(!outputf)
        {
            fprintf(stderr, "Error in Taruga::Interpreter::save_script: couldn't save to \"%s\".\n", filename);
            return;
        }

        while (!actions.empty())
        {
            Action &current = actions.front();
            switch (current.instr)
            {
            case Instruction::Walk:
                current.data.walking_distance < 0 ? fprintf(outputf, "b ") : fprintf(outputf, "f ");
                fprintf(outputf, "%.3f\n", std::fabs(current.data.walking_distance));
            break;
            case Instruction::Rotate:
                current.data.rotation_angle < 0 ? fprintf(outputf, "l ") : fprintf(outputf, "r ");
                fprintf(outputf, "%.3f\n", std::fabs(current.data.rotation_angle));
            break;
            case Instruction::PopState:
                fprintf(outputf, "pop\n");
            break;
            case Instruction::PushState:
                fprintf(outputf, "push\n");
            break;
            case Instruction::PenMovement:
                current.data.pen_down ? fprintf(outputf, "pd\n") : fprintf(outputf, "pu\n");
            break;
            case Instruction::NewWalkingSpeed:
                fprintf(outputf, "ws %.5f\n", current.data.new_walking_speed);
            break;
            case Instruction::NewRotationSpeed:
                fprintf(outputf, "rs %.5f\n", current.data.new_rotation_speed);
            break;
            case Instruction::LineChangeColor:
                fprintf(outputf, "cc");
                for(int i = 0; i < 3; i++)
                {
                    fprintf(outputf, " %hhu",current.data.next_color[i]);
                }
                fprintf(outputf, "\n");
            break;
            case Instruction::Screenshot:
                fprintf(outputf, "sc\n");
            break;
            }
            actions.pop();
        }
        fclose(outputf);
    }
};
}




#endif // __TARUGAINTERPRETER_HPP
