//---------------------------------------------------------------------------

#ifndef UnitEnterNameH
#define UnitEnterNameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormEnterName : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *EditName;
    TBitBtn *BitBtn1;
    TBevel *Bevel1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormEnterName(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEnterName *FormEnterName;
//---------------------------------------------------------------------------
#endif
