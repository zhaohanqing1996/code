//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitEnterName.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormEnterName *FormEnterName;
//---------------------------------------------------------------------------
__fastcall TFormEnterName::TFormEnterName(TComponent* Owner)
    : TForm(Owner)
{
  EditName->Clear();
}
//---------------------------------------------------------------------------
