#include "UnitSnake.h"
//---------------------------------------------------------------------------
TSnakeBuf::TWall TSnakeBuf::Wall0[]={{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall1[]={{5,10,23,10},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall2[]={{10,5,10,16},{18,5,18,16},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall3[]={{10,5,10,16},{18,5,18,16},{ 5,10,23,10},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall4[]={{ 5,6,23, 6},{5,14,23,14},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall5[]={{ 5,6,23, 6},{5,14,23,14},{14, 7,14,13},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall6[]={{10,0,10,16},{18,5,18,20},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall7[]={{ 0,6,23, 6},{5,14,27,14},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall8[]={{ 6,5, 6,20},{20,5,20,20},{13, 0,13,16},{-1}};
TSnakeBuf::TWall TSnakeBuf::Wall9[]={{ 0,6,15, 6},{21,0,21, 9},{12,14,27,14},{6,12,6,20},{-1}};
TSnakeBuf::TWall *TSnakeBuf::Walls[]={TSnakeBuf::Wall0,TSnakeBuf::Wall1,TSnakeBuf::Wall2,TSnakeBuf::Wall3,TSnakeBuf::Wall4,TSnakeBuf::Wall5,TSnakeBuf::Wall6,TSnakeBuf::Wall7,TSnakeBuf::Wall8,TSnakeBuf::Wall9};
//---------------------------------------------------------------------------
TSnakeBuf::TBmpPos TSnakeBuf::BmpPos[] =
{
  // Wall  Bean Super Head  Horz  Vert  CrnUL CrnUR CrnDL CrnDR TailU TailD TailL TailR Stage
  {{{4,1},{4,2},{5,2},{5,1},{4,0},{5,0},{0,1},{1,1},{0,2},{1,2},{3,1},{2,2},{2,1},{3,2},{5,2}}},
  {{{0,0},{1,0},{3,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{2,0},{3,0}}},
};
//---------------------------------------------------------------------------
TSnakeBuf::TSnakeBuf()
{
  _Snake = 0;
  _iBeanNo = 0;
  _iStageBeans = 200;
  _iScore = 0;
  _bGameOver = false;
  _bEndStage = false;
  memset(_Units,0,sizeof(_Units));
  memset(_DispBuf,0,sizeof(_DispBuf));
}
//---------------------------------------------------------------------------
TSnakeBuf::~TSnakeBuf()
{
  ClearSnake();
}
//---------------------------------------------------------------------------
void TSnakeBuf::ClearSnake(void)
{
  if(_Snake)
   {
     TSnakeNode *toDel;
     _Snake->Prev->Next=0;
     while(_Snake)
      {
        toDel=_Snake;
        _Snake=_Snake->Next;
        delete toDel;
      }
     _Snake=0;
   }
}
//---------------------------------------------------------------------------
void TSnakeBuf::InitSnake(void)
{
  ClearSnake();
  _Snake = new TSnakeNode;
  TSnakeNode *nd = new TSnakeNode;

  _Snake->x = UnitX/2;
  _Snake->y = UnitY-2;
  _Snake->Next = nd;
  _Snake->Prev = nd;

  nd->x = UnitX/2;
  nd->y = UnitY-1;
  nd->Next = _Snake;
  nd->Prev = _Snake;
}
//---------------------------------------------------------------------------
void TSnakeBuf::StepMove(int d)
{
  if((_Snake)&&(d)&&(!_bGameOver)&&(!_bEndStage))
   {
     TSnakeNode NewPos = *_Snake;
     switch(d)
      {
        case sdUp   : NewPos.y--; break; //up
        case sdDown : NewPos.y++; break; //down
        case sdLeft : NewPos.x--; break; //left
        case sdRight: NewPos.x++; break; //right
        default     : return; //do nothing
      }
     if((NewPos.x<0)||(NewPos.y<0)||(NewPos.x>=UnitX)||(NewPos.y>=UnitY))
      {
        _bGameOver = true;
        return;
      }
     if(GetDispBuf(NewPos.x,NewPos.y)==sbnWall)
      {
        _bGameOver = true;
        return;
      }
     if((GetDispBuf(NewPos.x,NewPos.y)>=sbnHead)&&(GetDispBuf(NewPos.x,NewPos.y)<sbnStage))
      {
        _bGameOver = true;
        return;
      }

     bool bEat = GetUnit(NewPos.x,NewPos.y)==sbnBean || GetUnit(NewPos.x,NewPos.y)==sbnStage;
     SetUnit(NewPos.x,NewPos.y,sbnNone);
     if(bEat)
      {
        TSnakeNode *NewNode = new TSnakeNode;
        NewNode->x = NewPos.x;
        NewNode->y = NewPos.y;
        NewNode->Next = _Snake;
        NewNode->Prev = _Snake->Prev;
        _Snake->Prev->Next = NewNode;
        _Snake->Prev=NewNode;
        _Snake = NewNode;
        _iScore += ssEat;
      }
     else
      {
        _Snake = _Snake->Prev;
        _Snake->x = NewPos.x;
        _Snake->y = NewPos.y;
      }
     DrawSnake();

     if(bEat)
      if(!GenBean())
      {
        _bEndStage = true;
        _iScore += ssStage;
      }
   }
}
//---------------------------------------------------------------------------
int TSnakeBuf::GetDispBuf(int x, int y)
{
  if((x>=0) && (x<UnitX) && (y>=0) && (y<UnitY))
    return _DispBuf[y][x];
  return 0;
}
//---------------------------------------------------------------------------
int TSnakeBuf::GetUnit(int x, int y)
{
  if((x>=0) && (x<UnitX) && (y>=0) && (y<UnitY))
    return _Units[y][x];
  return 0;
}
//---------------------------------------------------------------------------
void TSnakeBuf::SetUnit(int x, int y, int n)
{
  if((x>=0) && (x<UnitX) && (y>=0) && (y<UnitY))
    _Units[y][x] = n;
}
//---------------------------------------------------------------------------
void TSnakeBuf::DrawSnake(void)
{
  memcpy(_DispBuf,_Units,sizeof(_Units));
  if(_Snake)
   {
     TSnakeNode *lpNode = _Snake->Next;
     _DispBuf[_Snake->y][_Snake->x]=sbnHead;

     while((lpNode)&&(lpNode!=_Snake))
      {
        if(lpNode->Next==_Snake)
         {
           if(lpNode->y==lpNode->Prev->y)
             _DispBuf[lpNode->y][lpNode->x] = (lpNode->x<lpNode->Prev->x?sbnTailL:sbnTailR);
           else
             _DispBuf[lpNode->y][lpNode->x] = (lpNode->y<lpNode->Prev->y?sbnTailU:sbnTailD);
         }
        else if(lpNode->y==lpNode->Prev->y)
         {
           if(lpNode->y>lpNode->Next->y)
             _DispBuf[lpNode->y][lpNode->x]=(lpNode->x<lpNode->Prev->x)?sbnCornDL:sbnCornDR;
           else if(lpNode->y<lpNode->Next->y)
             _DispBuf[lpNode->y][lpNode->x]=(lpNode->x<lpNode->Prev->x)?sbnCornUL:sbnCornUR;
           else
             _DispBuf[lpNode->y][lpNode->x]=sbnHorz;
         }
        else
         {
           if(lpNode->x<lpNode->Next->x)
             _DispBuf[lpNode->y][lpNode->x]=(lpNode->y<lpNode->Prev->y)?sbnCornUL:sbnCornDL;
           else if(lpNode->x>lpNode->Next->x)
             _DispBuf[lpNode->y][lpNode->x]=(lpNode->y<lpNode->Prev->y)?sbnCornUR:sbnCornDR;
           else
             _DispBuf[lpNode->y][lpNode->x]=sbnVert;
         }
        lpNode = lpNode->Next;
      }
   }
}
//---------------------------------------------------------------------------
void TSnakeBuf::InitStage(int StgNum)
{
  _iBeanNo = 0;
  _bGameOver = false;
  _bEndStage = false;
  memset(_Units,0,sizeof(_Units));
  memset(_DispBuf,0,sizeof(_DispBuf));
  GenWalls(StgNum);
  InitSnake();
  DrawSnake();
  GenBean();
}
//---------------------------------------------------------------------------
void TSnakeBuf::ClearScore(void)
{
  _iScore = 0;
}
//---------------------------------------------------------------------------
bool TSnakeBuf::GenBean(void)
{
  if(++_iBeanNo<=_iStageBeans)
   {
     int x = random(UnitX);
     int y = random(UnitY);

     while(GetDispBuf(x,y))
      {
        x = random(UnitX);
        y = random(UnitY);
      }

     SetUnit(x,y,_iBeanNo==_iStageBeans?sbnStage:sbnBean);
     return true;
   }
  return false;
}
//---------------------------------------------------------------------------
void TSnakeBuf::GenWalls(int StgNum)
{
  int StNo=StgNum%StageCount;
  TWall *lpWall = Walls[StNo];
  for(int i=0; lpWall[i].x1>=0; i++)
   {
     if(lpWall[i].x1==lpWall[i].x2)
      {
        for(int y=lpWall[i].y1; y<=lpWall[i].y2; y++)
         {
           SetUnit(lpWall[i].x1,y,sbnWall);
         }
      }
     else
      {
        for(int x=lpWall[i].x1; x<=lpWall[i].x2; x++)
         {
           SetUnit(x,lpWall[i].y1,sbnWall);
         }
      }
   }
}
//---------------------------------------------------------------------------
bool TSnakeBuf::fGetRunning(void)
{
  return ((_Snake)&&(!_bGameOver)&&(!_bEndStage));
}
//---------------------------------------------------------------------------
__fastcall TSnakeTimer::TSnakeTimer():TThread(false)
{
  dwTimeToWait = 300;
  hTimer = NULL;
  OnTimer = NULL;
  iSkipUserEvent = 0;
  FreeOnTerminate = true;
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::DestroyTimer(void)
{
  OnTimer = NULL;
  Terminate();
  SetEvent(hTimer);
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::SyOnStart(void)
{
  dwWaitTime = dwTimeToWait;
  iSkipUserEvent = 0;
  hTimer = CreateEvent(NULL, true, false, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::SyOnExit(void)
{
  CloseHandle(hTimer);
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::SyOnTimer(void)
{
  if((OnTimer)&&(!iSkipUserEvent))
   {
     try
      {
        OnTimer(this);
      }
     catch(Exception &e)
      {
        //ignore user's error
      }
   }
  if(iSkipUserEvent>0)
    iSkipUserEvent--;
  ResetEvent(hTimer);
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::Execute(void)
{
  Synchronize(SyOnStart);
  while(!Terminated)
   {
     WaitForSingleObject(hTimer,dwWaitTime);
     if(!Terminated)
      {
        Synchronize(SyOnTimer);
      }
   }
  Synchronize(SyOnExit);
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::fSetInterval(DWORD dwIntv)
{
  dwWaitTime = dwTimeToWait = dwIntv;
  iSkipUserEvent = 1;
  TriggerTimer();
}
//---------------------------------------------------------------------------
void __fastcall TSnakeTimer::TriggerTimer(int iWait)
{
  if(hTimer)
   {
     if(iWait>0)
       iSkipUserEvent = iWait+1;
     SetEvent(hTimer);
   }
}
//---------------------------------------------------------------------------
