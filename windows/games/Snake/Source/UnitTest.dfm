object FormMain: TFormMain
  Left = 365
  Top = 260
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = '̰����'
  ClientHeight = 359
  ClientWidth = 460
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = '����'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 84
    Top = 344
    Width = 30
    Height = 12
    Caption = '����:'
    Transparent = True
  end
  object LabelStage: TLabel
    Left = 116
    Top = 344
    Width = 6
    Height = 12
    Caption = '0'
    Transparent = True
  end
  object Label2: TLabel
    Left = 4
    Top = 344
    Width = 30
    Height = 12
    Caption = '����:'
    Transparent = True
  end
  object LabelScore: TLabel
    Left = 36
    Top = 344
    Width = 6
    Height = 12
    Caption = '0'
    Transparent = True
  end
  object Label3: TLabel
    Left = 164
    Top = 344
    Width = 30
    Height = 12
    Caption = '��¼:'
    Transparent = True
  end
  object LabelHS: TLabel
    Left = 195
    Top = 344
    Width = 6
    Height = 12
    Caption = '0'
    Transparent = True
  end
  object LabelHome: TLabel
    Left = 363
    Top = 344
    Width = 90
    Height = 12
    Cursor = crHandPoint
    Alignment = taRightJustify
    Caption = 'www.cppfans.com'
    OnClick = LabelHomeClick
  end
  object ScrollBoxSnake: TScrollBox
    Left = 4
    Top = 0
    Width = 452
    Height = 340
    TabOrder = 0
    object PaintBoxSnake: TPaintBox
      Left = 0
      Top = 0
      Width = 448
      Height = 336
      Align = alClient
      OnPaint = PaintBoxSnakePaint
    end
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object File1: TMenuItem
      Caption = '��Ϸ(&G)'
      object MiNew: TMenuItem
        Caption = '����Ϸ(&N)'
        ShortCut = 121
        OnClick = MiNewClick
      end
      object MiPause: TMenuItem
        Caption = '��ͣ(&P)'
        ShortCut = 27
        OnClick = MiPauseClick
      end
      object HighScore1: TMenuItem
        Caption = '��Ϸ��¼(&H)'
        OnClick = HighScore1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object MiExit: TMenuItem
        Caption = '�뿪��Ϸ(&X)'
        ShortCut = 32856
        OnClick = MiExitClick
      end
    end
    object Options1: TMenuItem
      Caption = 'ѡ��(&O)'
      object MiBlocks: TMenuItem
        Caption = '��������ʾ(&B)'
        OnClick = MiBlocksClick
      end
    end
    object Help1: TMenuItem
      Caption = '����(&H)'
      object Help2: TMenuItem
        Caption = '����(&H)'
        ShortCut = 112
      end
      object About1: TMenuItem
        Caption = '����(&A)����'
        OnClick = About1Click
      end
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnDeactivate = ApplicationEvents1Deactivate
    Left = 48
    Top = 16
  end
end
