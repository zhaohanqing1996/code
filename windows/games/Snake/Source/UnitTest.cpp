//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTest.h"
#include "UnitAbout.h"
#include "UnitEnterName.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
  randomize();
  LoadParams();

  StageNo = 0;
  Paused = false;
  DrMove = TSnakeBuf::sdUp;

  int dx = ScrollBoxSnake->Width - PaintBoxSnake->Width;
  int dy = ScrollBoxSnake->Height - PaintBoxSnake->Height;
  ScrollBoxSnake->Width = dx + TSnakeBuf::UnitX*16;
  ScrollBoxSnake->Height = dy + TSnakeBuf::UnitY*16;
  ScrollBoxSnake->DoubleBuffered = true;

  MiBlocks->Checked=SnakeParams.BmpSet;
  LabelHS->Caption=SnakeParams.HighScore;
  LabelStage->Caption=StageNo+1;
  LabelScore->Caption=SnakeBuf.Score;
  LabelHome->Font->Color = clBlue;

  LabelHomeDefProc = LabelHome->WindowProc;
  LabelHome->WindowProc = LabelHomeWndProc;

  RunBmp = new Graphics::TBitmap;
  RunBmp->LoadFromResourceName(0,"BMP_SNAKE");
  RunBmp->PixelFormat = pfDevice;

  PausedBmp = new Graphics::TBitmap;
  PausedBmp->LoadFromResourceName(0,"BMP_PAUSED");
  PausedBmp->PixelFormat = pfDevice;
  PausedBmp->Transparent = true;

  OverBmp = new Graphics::TBitmap;
  OverBmp->LoadFromResourceName(0,"BMP_GMOVER");
  OverBmp->PixelFormat = pfDevice;
  OverBmp->Transparent = true;

  MaskBmp = new Graphics::TBitmap;
  MaskBmp->Assign(RunBmp);
  MaskBmp->Mask(MaskBmp->Canvas->Pixels[MaskBmp->Width-1][MaskBmp->Height-1]);

  SnakeTimer = new TSnakeTimer;
  SnakeTimer->Interval = 300;
  SnakeTimer->OnTimer = SnakeTimerTimer;
}
//---------------------------------------------------------------------------
__fastcall TFormMain::~TFormMain()
{
  SnakeTimer->DestroyTimer();
  delete MaskBmp;
  delete OverBmp;
  delete PausedBmp;
  delete RunBmp;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::LabelHomeWndProc(Messages::TMessage &Message)
{
  if(Message.Msg==CM_MOUSEENTER)
   {
     LabelHome->Font->Color = clRed;
     LabelHome->Font->Style = LabelHome->Font->Style<<fsUnderline;
   }
  else if(Message.Msg==CM_MOUSELEAVE)
   {
     LabelHome->Font->Color = clBlue;
     LabelHome->Font->Style = LabelHome->Font->Style>>fsUnderline;
   }
  LabelHomeDefProc(Message);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::LabelHomeClick(TObject *Sender)
{
  ShellExecute(Handle,"open","http://www.cppfans.com/",0,"",SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::PaintBoxSnakePaint(TObject *Sender)
{
  TPaintBox *pb = (TPaintBox*)Sender;
  TCanvas *lpCanvas = pb->Canvas;
  TRect rc(pb->Left,pb->Top,pb->Left+pb->Width,pb->Top+pb->Height);
  lpCanvas->Brush->Style = bsSolid;
  lpCanvas->Brush->Color = clWhite;
  lpCanvas->FillRect(rc);

  int u, x0,y0,x1,y1;
  TSnakeBuf::TSnakeNode *lpPoint;
  for(int y=0; y<TSnakeBuf::UnitY; y++)
   {
     x1=0;
     y1=y*16;
     for(int x=0; x<TSnakeBuf::UnitX; x++)
      {
        u=SnakeBuf.GetDispBuf(x,y);
        if(u>0)
         {
           u--;
           x0=TSnakeBuf::BmpPos[SnakeParams.BmpSet].Pos[u].x*16;
           y0=TSnakeBuf::BmpPos[SnakeParams.BmpSet].Pos[u].y*16;
           ::BitBlt(lpCanvas->Handle,x1,y1,16,16, RunBmp->Canvas->Handle,x0,y0, SRCINVERT);
           ::BitBlt(lpCanvas->Handle,x1,y1,16,16, MaskBmp->Canvas->Handle,x0,y0, SRCAND  );
           ::BitBlt(lpCanvas->Handle,x1,y1,16,16, RunBmp->Canvas->Handle,x0,y0, SRCINVERT);
         }
        x1+=16;
      }
   }
  if(Paused)
   {
     int w=PausedBmp->Width,h=PausedBmp->Height;
     int x=(pb->Width-w)/2,y=(pb->Height-h)/2;
     lpCanvas->Draw(x,y,PausedBmp);
   }
  else if(SnakeBuf.GameOver)
   {
     int w=OverBmp->Width,h=OverBmp->Height;
     int x=(pb->Width-w)/2,y=(pb->Height-h)/2;
     lpCanvas->Draw(x,y,OverBmp);
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SnakeTimerTimer(TObject *Sender)
{
  if((!SnakeBuf.GameOver)&&(StageNo<TSnakeBuf::StageCount)&&(!Paused))
   {
     bool bCheckScore = false;
     SnakeBuf.StepMove(DrMove);
     if(SnakeBuf.GameOver)
      {
        LabelScore->Caption=SnakeBuf.Score;
        PaintBoxSnake->Invalidate();
        bCheckScore = true;
        //Application->MessageBox("Game Over!","Game Over",MB_OK|MB_ICONSTOP);
      }
     if(SnakeBuf.EndStage)
      {
        StageNo++;
        StageNo%=TSnakeBuf::StageCount;
        LabelScore->Caption=SnakeBuf.Score;
        //Application->MessageBox("Next stage.","Next stage",MB_OK|MB_ICONINFORMATION);
        LabelStage->Caption=StageNo+1;
        DrMove = TSnakeBuf::sdUp;
        SnakeBuf.InitStage(StageNo);
      }
     LabelScore->Caption=SnakeBuf.Score;
     PaintBoxSnake->Invalidate();

     if(bCheckScore)
      {
        LoadParams();
        if(SnakeBuf.Score>SnakeParams.HighScore)
         {
           SaveHighScore();
           ShowHighScore();
         }
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
  if((!SnakeBuf.GameOver)&&(!Paused))
   {
     int d = 0;
     switch(Key)
      {
        case VK_UP   : if(DrMove!=TSnakeBuf::sdDown )d=TSnakeBuf::sdUp   ; break;
        case VK_DOWN : if(DrMove!=TSnakeBuf::sdUp   )d=TSnakeBuf::sdDown ; break;
        case VK_LEFT : if(DrMove!=TSnakeBuf::sdRight)d=TSnakeBuf::sdLeft ; break;
        case VK_RIGHT: if(DrMove!=TSnakeBuf::sdLeft )d=TSnakeBuf::sdRight; break;
      }
     if(d)
      {
        DrMove = d;
        SnakeTimer->TriggerTimer();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MiNewClick(TObject *Sender)
{
  StageNo = 0;
  Paused = false;
  LabelStage->Caption=StageNo+1;
  DrMove = TSnakeBuf::sdUp;
  SnakeBuf.ClearScore();
  SnakeBuf.InitStage(StageNo);
  LabelScore->Caption=SnakeBuf.Score;
  PaintBoxSnake->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MiExitClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ApplicationEvents1Deactivate(TObject *Sender)
{
  if(SnakeBuf.Running)
    Paused = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::fSetPaused(bool b)
{
  _bPaused = b;
  MiPause->Checked=_bPaused;
  PaintBoxSnake->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MiPauseClick(TObject *Sender)
{
  if(SnakeBuf.Running)
    Paused=!Paused;
  else
    Paused=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MiBlocksClick(TObject *Sender)
{
  LoadParams();
  SnakeParams.BmpSet=!MiBlocks->Checked;
  MiBlocks->Checked=!MiBlocks->Checked;
  PaintBoxSnake->Invalidate();
  SaveParams();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::About1Click(TObject *Sender)
{
  FormAbout = new TFormAbout(this);
  FormAbout->ShowModal();
  delete FormAbout;
}
//---------------------------------------------------------------------------
void TFormMain::LoadParams(void)
{
  memset(&SnakeParams,0,sizeof(TSnakeParams));
  AnsiString fname = ChangeFileExt(ParamStr(0),".cfg");
  FILE *f = fopen(fname.c_str(),"rb");
  if(f)
   {
     fread(&SnakeParams,sizeof(TSnakeParams),1,f);
     fclose(f);
   }
}
//---------------------------------------------------------------------------
void TFormMain::SaveParams(void)
{
  AnsiString fname = ChangeFileExt(ParamStr(0),".cfg");
  FILE *f = fopen(fname.c_str(),"wb");
  if(f)
   {
     fwrite(&SnakeParams,sizeof(TSnakeParams),1,f);
     fclose(f);
   }
}
//---------------------------------------------------------------------------
void TFormMain::SaveHighScore(void)
{
  SnakeParams.HighScore = SnakeBuf.Score;
  LabelHS->Caption=SnakeParams.HighScore;
  AnsiString HsName;

  FormEnterName = new TFormEnterName(this);
  FormEnterName->EditName->MaxLength=30;
  while(HsName.IsEmpty())
   {
     FormEnterName->ShowModal();
     HsName = FormEnterName->EditName->Text.Trim();
   }
  delete FormEnterName;

  strcpy(SnakeParams.HsName,HsName.c_str());
  SaveParams();
}
//---------------------------------------------------------------------------
void TFormMain::ShowHighScore(void)
{
  AnsiString s;
  s.sprintf("游戏纪录: %s: %d", SnakeParams.HsName, SnakeParams.HighScore);
  Application->MessageBox(s.c_str(),"游戏纪录",MB_OK|MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::HighScore1Click(TObject *Sender)
{
  ShowHighScore();
}
//---------------------------------------------------------------------------

