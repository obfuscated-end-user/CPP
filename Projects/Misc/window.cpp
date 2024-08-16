// https://stackoverflow.com/questions/2348442/what-does-winapi-in-main-function-mean

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);
    return 0;
}