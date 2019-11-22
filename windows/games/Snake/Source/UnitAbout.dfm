object FormAbout: TFormAbout
  Left = 367
  Top = 583
  BorderStyle = bsDialog
  Caption = '关于……'
  ClientHeight = 107
  ClientWidth = 233
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = '宋体'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 12
  object LabelProg: TLabel
    Left = 32
    Top = 16
    Width = 66
    Height = 12
    Caption = '贪吃蛇 v1.0'
  end
  object Label2: TLabel
    Left = 64
    Top = 40
    Width = 150
    Height = 12
    Caption = 'Copyright (C) Victor Chen'
  end
  object LabelHome: TLabel
    Left = 80
    Top = 56
    Width = 138
    Height = 12
    Cursor = crHandPoint
    Caption = 'http://www.cppfans.com/'
    OnClick = LabelHomeClick
  end
  object Bevel1: TBevel
    Left = 0
    Top = 72
    Width = 233
    Height = 2
  end
  object BnOK: TBitBtn
    Left = 80
    Top = 80
    Width = 75
    Height = 25
    Cursor = crHandPoint
    Caption = '关闭'
    TabOrder = 0
    Kind = bkOK
  end
end
