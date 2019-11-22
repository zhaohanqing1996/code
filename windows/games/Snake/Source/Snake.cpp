//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Snake.res");
USERC("Snake_Res.rc");
USEUNIT("UnitSnake.cpp");
USEFORM("UnitTest.cpp", FormMain);
USEFORM("UnitEnterName.cpp", FormEnterName);
USEFORM("UnitAbout.cpp", FormAbout);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TFormMain), &FormMain);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
