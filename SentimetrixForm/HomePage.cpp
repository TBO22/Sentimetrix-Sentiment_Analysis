#include "HomePage.h"
#include <Windows.h>
using namespace SentimetrixForm;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew HomePage());
    return 0;
} 
