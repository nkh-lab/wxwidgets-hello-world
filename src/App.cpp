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

#include <wx/cmdline.h>

#include "MainWindow.h"
#include "Utils.h"

namespace {
constexpr int kTestModeAutoCloseTimeout_s = 3;
}

App::App()
    : test_mode_{false}
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool App::OnInit()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    bool ret = false;

    if (wxApp::OnInit())
    {
        // acording to wxWidjets spec window is suicide object, and we mast not use delete operator
        MainWindow* m = new MainWindow(nullptr, wxID_ANY, "Hello World Title");
        m->Show();

        if (test_mode_)
        {
            test_mode_timer_ = std::make_unique<wxTimer>();

            auto on_timeout = [m](wxTimerEvent& event) {
                UNUSED(event);

                std::cout << __PRETTY_FUNCTION__ << std::endl;
                m->Close();
            };

            Bind(wxEVT_TIMER, on_timeout, test_mode_timer_->GetId());
            test_mode_timer_->StartOnce(kTestModeAutoCloseTimeout_s * 1000);
        }

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

void App::OnInitCmdLine(wxCmdLineParser& parser)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    std::string test_desc =
        Sprintf("Test mode. Application will close after %ds", kTestModeAutoCloseTimeout_s);

    const wxCmdLineEntryDesc cmds[] = {
        {wxCMD_LINE_SWITCH, "h", "help", "Display this help text", wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP},
        {wxCMD_LINE_SWITCH, "t", "test", test_desc.c_str(), wxCMD_LINE_VAL_NONE, wxCMD_LINE_PARAM_OPTIONAL},

        wxCMD_LINE_DESC_END};

    parser.SetDesc(cmds);
}

bool App::OnCmdLineParsed(wxCmdLineParser& parser)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    test_mode_ = parser.Found("test");

    return true;
}