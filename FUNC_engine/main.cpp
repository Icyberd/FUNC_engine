#include "EngineCore/FUNC_program.hpp"

int main(int argc, char* args[])
{
    FUNC_engine::FUNC_program Game = FUNC_engine::FUNC_program("TestProg", 600, 400, true);

    while (Game.ShouldClose() != true)
    {



    }

    return 0;
}