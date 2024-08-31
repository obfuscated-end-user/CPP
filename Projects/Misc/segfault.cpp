// https://stackoverflow.com/questions/2045314/why-cant-i-cause-a-seg-fault

#include <signal.h>

int main() {
    raise(SIGSEGV);
}