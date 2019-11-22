//---------------------------------------------------------------------------

#ifndef UnitTestH
#define UnitTestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "UnitSnake.h"
#include <AppEvnts.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
    TPaintBox *PaintBoxSnake;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *MiExit;
    TMenuItem *MiNew;
    TLabel *Label1;
    TLabel *LabelStage;
    TLabel *Label2;
    TLabel *LabelScore;
    TApplicationEvents *ApplicationEvents1;
    TMenuItem *MiPause;
    TMenuItem *Help1;
    TMenuItem *Help2;
    TMenuItem *About1;
    TMenuItem *Options1;
    TMenuItem *MiBlocks;
    TLabel *Label3;
    TLabel *LabelHS;
    TMenuItem *HighScore1;
    TMenuItem *N1;
    TScrollBox *ScrollBoxSnake;
    TLabel *LabelHome;
    void __fastcall PaintBoxSnakePaint(TObject *Sender);
    void __fastcall MiNewClick(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall MiExitClick(TObject *Sender);
    void __fastcall ApplicationEvents1Deactivate(TObject *Sender);
    void __fastcall MiPauseClick(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall MiBlocksClick(TObject *Sender);
    void __fastcall HighScore1Click(TObject *Sender);
    void __fastcall LabelHomeClick(TObject *Sender);
private:	// User declarations
    #pragma pack(push,1)
    typedef union
    {
      struct
       {
         int BmpSet;
         int HighScore;
         char HsName[32];
       };
      char Buffer[512];
    } TSnakeParams;
    #pragma pack(pop)
    TSnakeParams SnakeParams;
    Graphics::TBitmap *RunBmp, *MaskBmp, *PausedBmp, *OverBmp;
    bool _bPaused;
    int DrMove, StageNo;
    TSnakeBuf SnakeBuf;
    TSnakeTimer *SnakeTimer;
    void __fastcall fSetPaused(bool b);
    void __fastcall SnakeTimerTimer(TObject *Sender);
    void LoadParams(void);
    void SaveParams(void);
    void SaveHighScore(void);
    void ShowHighScore(void);

    TWndMethod LabelHomeDefProc;
    void __fastcall LabelHomeWndProc(Messages::TMessage &Message);
public:		// User declarations
    __fastcall TFormMain(TComponent* Owner);
    __fastcall ~TFormMain();
    __property bool Paused = { read = _bPaused, write = fSetPaused };
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
