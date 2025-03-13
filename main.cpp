#include "cli_gui.cpp"

int main() {
    int mode;
    cout << "Choose Mode: 1 for CLI, 2 for GUI: ";
    cin >> mode;

    if (mode == 1)
        runCLI();
    else
        guiDisplay();

    return 0;
}
