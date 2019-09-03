#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <windows.h>
#include <winuser.h>
#include <ctime>
#include <ShlObj.h>

#include <string>

#include "utilities.h"
#include "denoiser.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MainForm form;
	Application::Run(%form);
	//Application::Run(gcnew MyForm());
	return 0;
}

