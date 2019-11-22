object FormEnterName: TFormEnterName
  Left = 531
  Top = 485
  BorderStyle = bsDialog
  Caption = '恭喜您破了游戏纪录'
  ClientHeight = 118
  ClientWidth = 244
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
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 84
    Height = 12
    Caption = '请输入您的名字:'
  end
  object Bevel1: TBevel
    Left = 0
    Top = 80
    Width = 244
    Height = 2
  end
  object EditName: TEdit
    Left = 72
    Top = 48
    Width = 129
    Height = 20
    TabOrder = 0
    Text = 'anonymous'
  end
  object BitBtn1: TBitBtn
    Left = 85
    Top = 88
    Width = 75
    Height = 25
    Caption = '确定'
    TabOrder = 1
    Kind = bkOK
  end
end
