このプログラムはクリエイティブコモンズライセンス・表示(CC BY)にしたがって、
複製・改変・再配布することが可能です。

　　　　　　　　　CC BY Copyright 2018 Wataru KUNINO
　　　　　　　　　https://bokunimo.net/ichigojam/

　・「IchigoJam」は株式会社 jig.jp の登録商標です。
　　(本資料は株式会社 jig.jp が作成したものではありません。)
　・ライセンス内容については下記を参照してください。
　　http://creativecommons.org/licenses/by/4.0/deed.ja

ダウンロード方法

・PC 等でダウンロード： http://bokunimowakaru.github.io/MJ/pg08/●●.txt
・MixJuice メニュー形式： ?"MJ GET bokunimowakaru.github.io/MJ/808.txt"

動作確認バージョンについて

　・本ソフトウェアはIchigoJam BASIC Version 1.2.3で動作確認しています。

参考資料に関して

　　本ソフトウェアの作成にあたり、株式会社jig.jpのIchigoJam関連情報及び
　　IchigoJam-FAN(facebook)の情報を参照させていただきました。

-----------------------------------------------------------------------
下記のMixJuice用コンテンツに、「カタカナのみ全角に」と補足説明を追加
    https://github.com/bokunimowakaru/MJ/blob/gh-pages/808.txt
-----------------------------------------------------------------------

' IchigoSoda + sakura.io

' [10]YaoYa Talk        リスト     LTE 対応IoT 音声アナウンス端末用
' [11]BTN/PIR           リスト 1-1 LTE 対応IoT 押しボタンSAKURA IoT TX BTN/PIR
' [12]BTN/PIR PS        リスト 1-4 LTE 対応IoT 押しボタンSAKURA IoT TX BTN/PIR PS
' [13]ANA               リスト     LTE 対応IoT アナログセンサ用
' [14]ILM               リスト 1-5 LTE 対応IoT 照度センサSAKURA IoT TX ILM
' [15]RX                リスト 1-2 LTE 対応IoT ディスプレイSAKURA IoT RX
' [16]OLED              リスト     LTE 対応IoT ディスプレイSAKURA IoT RX 有機EL版
' [17]LCD               リスト     LTE 対応IoT ディスプレイSAKURA IoT RX LCD版
' [18]Firm              リスト 1-3 SAKURA Firmware Updater 更新専用プログラム
' [19]Firmコマンド      リスト 1-3 SAKURA Firmware Updater BASICコマンド
'
' [110]IoT YaoYa Talk   LTE 対応IoT 音声アナウンス端末用
' [111]IoT TX BTN/PIR   リスト 1-6 IchigoJam BASIC 1.2.4 IoT 版・LTE 対応IoT 押しボタン
' [112]BTN/PIR PS       リスト 1-4 LTE 対応IoT 押しボタンSAKURA IoT TX BTN/PIR PS
' [113]ANA              リスト     LTE 対応IoT アナログセンサ用
' [114]ILM              リスト 1-5 LTE 対応IoT 照度センサSAKURA IoT TX ILM
' [115]RX               リスト 1-2 LTE 対応IoT ディスプレイSAKURA IoT RX
' [116]OLED             リスト     LTE 対応IoT ディスプレイSAKURA IoT RX 有機EL版
' [117]LCD              リスト     LTE 対応IoT ディスプレイSAKURA IoT RX LCD版
' [118]Firm             リスト     SAKURA Firmware Updater 更新専用プログラム
' [119]Firmコマンド     リスト 1-3 SAKURA Firmware Updater BASICコマンド
'
' MixJuice -> Ambient
' [20]TX                リスト 2-1 Wi-Fi 対応MixJuice 送信テスト用プログラム・トグル送信
' [21]BTN/PIR           リスト 2-2 Wi-Fi 対応IoT 押しボタン/IoT 人感センサMixJuice IoT BTN/PIR
' [22]B/P PS            リスト 2-3 Wi-Fi 対応IoT 押しボタン・省電力版 MixJuice IoT BTN/PIR PS
' [23]ANA2/ILM PS       リスト 2-4 Wi-Fi 対応IoT 照度センサ・省電力版 MixJuice IoT ANA2 PS
' [24]ANA2/I PS2'       リスト 2-4 Wi-Fi 対応IoT 照度センサ・MixJuice側タイマ仕様
' [25]Envセンサ         リスト 2-5 Wi-Fi 対応IoT 温湿度センサ MixJuice IoT Env センサ
' [29]TX LOOP           リスト 2-5 Wi-Fi 対応MixJuice 送信テスト用プログラム・繰り返し送信
'
' MixJuice -> IFTTT
' [26]BTN/PIR           リスト     Wi-Fi 対応IoT 押しボタン/IoT 人感センサMixJuice IoT BTN/PIR
' [27]BTN/PIR PS        リスト     Wi-Fi 対応IoT 押しボタン・省電力版 MixJuice IoT BTN/PIR PS
'
' LoRaWAN AL-050
' [30]Barcode           リスト     LoRaWAN 対応IoT バーコード・リーダ
' [31]TX                リスト 3-1 LoRaWAN 対応IoT 押しボタン/IoT 人感センサ LoraWAN AL-050 TX
' [32]ANA               リスト     LoRaWAN 対応IoT アナログセンサ用 LoraWAN AL-050 RX
' [33]RX                リスト 3-2 LoRaWAN 対応IoT 制御用・受信プログラム LoraWAN AL-050 RX
' [34]TXT               リスト     LoRaWAN 対応IoT 制御・テキスト文字受信用
' [37]LCD               リスト     LoRaWAN 対応IoT ディスプレイ
' [38]AT Modem          リスト     STM LoRa Discovery Kit 用IoT 押しボタン・送信用
' [39]Tester Barcode    リスト     バーコード読み取りテスト用
'
' [99]リターン
'
inputA:?"MJ GET bokunimowakaru.github.io/MJ/pg08/";A;".txt"
