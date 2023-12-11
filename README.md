# Senjo_no_kizuna2_USBIO

## これは何？
バンダイナムコの戦場の絆２の筐体のＵＳＢボードを置き換えてXinputの入力に置き換えます。

## 概要
以下の３つになります
１．senjo_no_kizuna2_con.ino(nano用の設定)
２．promicro_subcontrol.ino(promicro用の設定)
３．VolumeControlButton.ino(promicroボリュームコントローラー)


# 調整
バランス調整等はsenjo_no_kizuna2_con.ino
LVOLUME
RVOLUME
AXLVOLUME
AYLVOLUME
AXRVOLUME
AYRVOLUME
の比較部分を修正することで値の調整が可能です。

# その他
ソース類は、さーくるりんご汁のUSBIO用に設計されています。
