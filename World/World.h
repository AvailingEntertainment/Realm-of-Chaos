#ifndef WORLD_H
#define WORLD_H

struct map {
    char zonename[20];
    char mapline_y1[86];
    char mapline_y2[86];
    char mapline_y3[86];
    char mapline_y4[86];
    char mapline_y5[86];
    char mapline_y6[86];
    char mapline_y7[86];
    char mapline_y8[86];
    char mapline_y9[86];
    char mapline_y10[86];
    char mapline_y11[86];
    char mapline_y12[86];
    char mapline_y13[86];
    char mapline_y14[86];
    char mapline_y15[86];
    char mapline_y16[86];
    char mapline_y17[86];
    char mapline_y18[86];
    char mapline_y19[86];
    char mapline_y20[86];
    char mapline_y21[86];
    char mapline_y22[86];
    char mapline_y23[86];
    char mapline_y24[86];
    char mapline_y25[86];
}mapfile;




























enum ShutdownExitCode
{
    SHUTDOWN_EXIT_CODE = 0,
    ERROR_EXIT_CODE = 1,
    RESTART_EXIT_CODE = 2
};

const int zones = 3;
const int gWidth = 86;
const int gHeight = 25;

char map[3][25][86] = {
    "#####################################################################################",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#####################################################################################",
    "#####################################################################################",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#####################################################################################",
    "#####################################################################################",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#                                                                                   #",
    "#####################################################################################", };

class World
{
    public:
        World();
        virtual ~World();
        void worldInit();
    private:
};

#endif // WORLD_H


