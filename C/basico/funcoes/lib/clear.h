

#ifdef _WIN32
#define CLEAR_CMD "cls"

#else
#define CLEAR_CMD "clear"

#endif
void clear()
{
    system(CLEAR_CMD);
};
