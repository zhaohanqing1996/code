//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAbout *FormAbout;
//---------------------------------------------------------------------------
__fastcall TFormAbout::TFormAbout(TComponent* Owner)
    : TForm(Owner)
{
  LabelProg->Font->Size = 12;
  LabelHome->Font->Color = clBlue;
  LabelHome->Font->Style = LabelHome->Font->Style<<fsUnderline;
  BnOKDefProc = BnOK->WindowProc;
  BnOK->WindowProc = BnOkWndProc;
  LabelHomeDefProc = LabelHome->WindowProc;
  LabelHome->WindowProc = LabelHomeWndProc;
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::LabelHomeClick(TObject *Sender)
{
  ShellExecute(Handle,"open",LabelHome->Caption.c_str(),0,"",SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::LabelHomeWndProc(Messages::TMessage &Message)
{
  if(Message.Msg==CM_MOUSEENTER)
    LabelHome->Font->Color = clRed;
  else if(Message.Msg==CM_MOUSELEAVE)
    LabelHome->Font->Color = clBlue;
  LabelHomeDefProc(Message);
}
//---------------------------------------------------------------------------
void __fastcall TFormAbout::BnOkWndProc(Messages::TMessage &Message)
{
  if(Message.Msg==CM_MOUSEENTER)
    BnOK->Font->Color = clRed;
  else if(Message.Msg==CM_MOUSELEAVE)
    BnOK->Font->Color = clWindowText;
  BnOKDefProc(Message);
}
//---------------------------------------------------------------------------
