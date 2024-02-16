object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object UsernameLabel: TLabel
    Left = 200
    Top = 120
    Width = 59
    Height = 15
    Caption = 'Username: '
  end
  object PasswordLabel: TLabel
    Left = 203
    Top = 152
    Width = 56
    Height = 15
    Caption = 'Password: '
  end
  object UsernameEdit: TEdit
    Left = 272
    Top = 117
    Width = 121
    Height = 23
    TabOrder = 0
  end
  object PasswordEdit: TEdit
    Left = 272
    Top = 149
    Width = 121
    Height = 23
    TabOrder = 1
  end
  object LoginButton: TButton
    Left = 280
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Login'
    TabOrder = 2
  end
end
