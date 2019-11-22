//---------------------------------------------------------------------------

#ifndef UnitAboutH
#define UnitAboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormAbout : public TForm
{
__published:	// IDE-managed Components
    TBitBtn *BnOK;
    TLabel *LabelProg;
    TLabel *Label2;
    TLabel *LabelHome;
    TBevel *Bevel1;
    void __fastcall LabelHomeClick(TObject *Sender);
private:	// User declarations
    TWndMethod BnOKDefProc, LabelHomeDefProc;
    void __fastcall BnOkWndProc(Messages::TMessage &Message);
    void __fastcall LabelHomeWndProc(Messages::TMessage &Message);
public:		// User declarations
    __fastcall TFormAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAbout *FormAbout;
//---------------------------------------------------------------------------
#endif
