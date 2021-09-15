#include "App.h"

#include <iostream>

bool App::OnInit()
{
    bool ret = false;

    if (wxApp::OnInit())
    {
        // acording to wxWidjets spec window is suicide object, and we mast not use delete operator
        MainWindow* m = new MainWindow(nullptr, wxID_ANY, "Hello World Title");
        m->Show();
        ret = true;
    }

    return ret;
}

int App::OnExit()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    return wxApp::OnExit();
}

App::~App()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
