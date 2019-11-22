//---------------------------------------------------------------------------

#ifndef UnitSnakeH
#define UnitSnakeH
//---------------------------------------------------------------------------
#include <vcl.h>
//---------------------------------------------------------------------------

class TSnakeBuf
{
public:
  static const UnitX=28, UnitY=21, StageCount=10;

  enum TDirection
   {
     sdUp    = VK_UP,
     sdDown  = VK_DOWN,
     sdLeft  = VK_LEFT,
     sdRight = VK_RIGHT,
   };

  enum TBmpNo
   {
     sbnNone   =  0,
     sbnWall   =  1,
     sbnBean   =  2,
     sbnSuper  =  3,
     sbnHead   =  4,
     sbnHorz   =  5,
     sbnVert   =  6,
     sbnCornUL =  7,
     sbnCornUR =  8,
     sbnCornDL =  9,
     sbnCornDR = 10,
     sbnTailU  = 11,
     sbnTailD  = 12,
     sbnTailL  = 13,
     sbnTailR  = 14,
     sbnStage  = 15,
   };

  enum TScore
   {
     ssEat = 1, //吃豆给分
     ssStage = 0, //过关给分
   };

  typedef struct TSnakeNode
   {
     int x;
     int y;
     TSnakeNode *Next;
     TSnakeNode *Prev;
   } TSnakeNode;

  typedef struct
   {
     int x1;
     int y1;
     int x2;
     int y2;
   } TWall;

  typedef union
   {
     struct
      {
        POINT Wall;
        POINT Bean;
        POINT Super;
        POINT Head;
        POINT Horz;
        POINT Vert;
        POINT CornUL;
        POINT CornUR;
        POINT CornDL;
        POINT CornDR;
        POINT TailU;
        POINT TailD;
        POINT TailL;
        POINT TailR;
        POINT Stage;
      };
     POINT Pos[1];
   } TBmpPos;

  static TWall Wall0[], Wall1[], Wall2[], Wall3[], Wall4[];
  static TWall Wall5[], Wall6[], Wall7[], Wall8[], Wall9[];
  static TWall *Walls[];
  static TBmpPos BmpPos[];

  void ClearScore(void);
  void InitStage(int StgNum);
  void StepMove(int d);
  int GetDispBuf(int x, int y);

  __property int Score = { read = _iScore };
  __property bool GameOver = { read = _bGameOver };
  __property bool EndStage = { read = _bEndStage };
  __property bool Running = { read = fGetRunning };

  TSnakeBuf();
  ~TSnakeBuf();

private:
  TSnakeNode *_Snake;
  int _iBeanNo, _iStageBeans, _iScore;
  bool _bGameOver, _bEndStage;
  int _Units[UnitY][UnitX];
  int _DispBuf[UnitY][UnitX];

  void ClearSnake(void);
  void InitSnake(void);
  int GetUnit(int x, int y);
  void SetUnit(int x, int y, int n);
  void DrawSnake(void);
  bool GenBean(void);
  void GenWalls(int StgNum);
  bool fGetRunning(void);
};
//---------------------------------------------------------------------------

class TSnakeTimer:public TThread
{
public:
  __property DWORD Interval = { read = dwWaitTime, write = fSetInterval };
  __fastcall TSnakeTimer();
  void __fastcall DestroyTimer(void);
  void __fastcall TriggerTimer(int iWait=0);
  void __fastcall (__closure *OnTimer)(TObject *Sender);
protected:
  void __fastcall Execute(void);
private:
  void __fastcall SyOnStart(void);
  void __fastcall SyOnExit(void);
  void __fastcall SyOnTimer(void);
  HANDLE hTimer;
  DWORD dwWaitTime, dwTimeToWait;
  int iSkipUserEvent;
  void __fastcall fSetInterval(DWORD dwIntv);
};
//---------------------------------------------------------------------------
#endif
