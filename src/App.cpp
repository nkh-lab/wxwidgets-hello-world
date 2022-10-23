/*
 * Copyright (C) 2022 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#include "App.h"

#include <iostream>

#include "MainWindow.h"

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
