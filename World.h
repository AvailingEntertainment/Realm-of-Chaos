#ifndef WORLD_H
#define WORLD_H

enum ShutdownExitCode
{
    SHUTDOWN_EXIT_CODE = 0,
    ERROR_EXIT_CODE = 1,
    RESTART_EXIT_CODE = 2
};

class World
{
    public:
        World();
        virtual ~World();
        void worldInit();
    private:
};

#endif // WORLD_H


