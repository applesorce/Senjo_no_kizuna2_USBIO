# Senjo_no_kizuna2_USBIO

## これは何？
バンダイナムコの戦場の絆２の筐体のＵＳＢボードを置き換えてXinputの入力に置き換えます。

## 概要
以下の３つになります
１．senjo_no_kizuna2_con.ino
２．promicro_subcontrol.ino
３．VolumeControlButton.ino

最終的にriviveUSB Advanceとコントローラー、ボリュームコントローラーの3つになります。

# 調整
バランス調整等はsenjo_no_kizuna2_con.ino
LVOLUME
RVOLUME
AXLVOLUME
AYLVOLUME
AXRVOLUME
AYRVOLUME
の比較部分を修正することで値の調整が可能です。