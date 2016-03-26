#include "UIForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LogicSimplifierUI::UIForm form;
	Application::Run(%form);

	return(0);
}

