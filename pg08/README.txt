���̃v���O�����̓N���G�C�e�B�u�R�����Y���C�Z���X�E�\��(CC BY)�ɂ��������āA
�����E���ρE�Ĕz�z���邱�Ƃ��\�ł��B

�@�@�@�@�@�@�@�@�@CC BY Copyright 2018 Wataru KUNINO
�@�@�@�@�@�@�@�@�@https://bokunimo.net/ichigojam/

�@�E�uIchigoJam�v�͊������ jig.jp �̓o�^���W�ł��B
�@�@(�{�����͊������ jig.jp ���쐬�������̂ł͂���܂���B)
�@�E���C�Z���X���e�ɂ��Ă͉��L���Q�Ƃ��Ă��������B
�@�@http://creativecommons.org/licenses/by/4.0/deed.ja

�_�E�����[�h���@

�EPC ���Ń_�E�����[�h�F http://bokunimowakaru.github.io/MJ/pg08/����.txt
�EMixJuice ���j���[�`���F ?"MJ GET bokunimowakaru.github.io/MJ/808.txt"

����m�F�o�[�W�����ɂ���

�@�E�{�\�t�g�E�F�A��IchigoJam BASIC Version 1.2.3�œ���m�F���Ă��܂��B

�Q�l�����Ɋւ���

�@�@�{�\�t�g�E�F�A�̍쐬�ɂ�����A�������jig.jp��IchigoJam�֘A���y��
�@�@IchigoJam-FAN(facebook)�̏����Q�Ƃ����Ă��������܂����B

-----------------------------------------------------------------------
���L��MixJuice�p�R���e���c�ɁA�u�J�^�J�i�̂ݑS�p�Ɂv�ƕ⑫������ǉ�
    https://github.com/bokunimowakaru/MJ/blob/gh-pages/808.txt
-----------------------------------------------------------------------

' IchigoSoda + sakura.io

' [10]YaoYa Talk        ���X�g     LTE �Ή�IoT �����A�i�E���X�[���p
' [11]BTN/PIR           ���X�g 1-1 LTE �Ή�IoT �����{�^��SAKURA IoT TX BTN/PIR
' [12]BTN/PIR PS        ���X�g 1-4 LTE �Ή�IoT �����{�^��SAKURA IoT TX BTN/PIR PS
' [13]ANA               ���X�g     LTE �Ή�IoT �A�i���O�Z���T�p
' [14]ILM               ���X�g 1-5 LTE �Ή�IoT �Ɠx�Z���TSAKURA IoT TX ILM
' [15]RX                ���X�g 1-2 LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX
' [16]OLED              ���X�g     LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX �L�@EL��
' [17]LCD               ���X�g     LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX LCD��
' [18]Firm              ���X�g 1-3 SAKURA Firmware Updater �X�V��p�v���O����
' [19]Firm�R�}���h      ���X�g 1-3 SAKURA Firmware Updater BASIC�R�}���h
'
' [110]IoT YaoYa Talk   LTE �Ή�IoT �����A�i�E���X�[���p
' [111]IoT TX BTN/PIR   ���X�g 1-6 IchigoJam BASIC 1.2.4 IoT �ŁELTE �Ή�IoT �����{�^��
' [112]BTN/PIR PS       ���X�g 1-4 LTE �Ή�IoT �����{�^��SAKURA IoT TX BTN/PIR PS
' [113]ANA              ���X�g     LTE �Ή�IoT �A�i���O�Z���T�p
' [114]ILM              ���X�g 1-5 LTE �Ή�IoT �Ɠx�Z���TSAKURA IoT TX ILM
' [115]RX               ���X�g 1-2 LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX
' [116]OLED             ���X�g     LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX �L�@EL��
' [117]LCD              ���X�g     LTE �Ή�IoT �f�B�X�v���CSAKURA IoT RX LCD��
' [118]Firm             ���X�g     SAKURA Firmware Updater �X�V��p�v���O����
' [119]Firm�R�}���h     ���X�g 1-3 SAKURA Firmware Updater BASIC�R�}���h
'
' MixJuice -> Ambient
' [20]TX                ���X�g 2-1 Wi-Fi �Ή�MixJuice ���M�e�X�g�p�v���O�����E�g�O�����M
' [21]BTN/PIR           ���X�g 2-2 Wi-Fi �Ή�IoT �����{�^��/IoT �l���Z���TMixJuice IoT BTN/PIR
' [22]B/P PS            ���X�g 2-3 Wi-Fi �Ή�IoT �����{�^���E�ȓd�͔� MixJuice IoT BTN/PIR PS
' [23]ANA2/ILM PS       ���X�g 2-4 Wi-Fi �Ή�IoT �Ɠx�Z���T�E�ȓd�͔� MixJuice IoT ANA2 PS
' [24]ANA2/I PS2'       ���X�g 2-4 Wi-Fi �Ή�IoT �Ɠx�Z���T�EMixJuice���^�C�}�d�l
' [25]Env�Z���T         ���X�g 2-5 Wi-Fi �Ή�IoT �����x�Z���T MixJuice IoT Env �Z���T
' [29]TX LOOP           ���X�g 2-5 Wi-Fi �Ή�MixJuice ���M�e�X�g�p�v���O�����E�J��Ԃ����M
'
' MixJuice -> IFTTT
' [26]BTN/PIR           ���X�g     Wi-Fi �Ή�IoT �����{�^��/IoT �l���Z���TMixJuice IoT BTN/PIR
' [27]BTN/PIR PS        ���X�g     Wi-Fi �Ή�IoT �����{�^���E�ȓd�͔� MixJuice IoT BTN/PIR PS
'
' LoRaWAN AL-050
' [30]Barcode           ���X�g     LoRaWAN �Ή�IoT �o�[�R�[�h�E���[�_
' [31]TX                ���X�g 3-1 LoRaWAN �Ή�IoT �����{�^��/IoT �l���Z���T LoraWAN AL-050 TX
' [32]ANA               ���X�g     LoRaWAN �Ή�IoT �A�i���O�Z���T�p LoraWAN AL-050 RX
' [33]RX                ���X�g 3-2 LoRaWAN �Ή�IoT ����p�E��M�v���O���� LoraWAN AL-050 RX
' [34]TXT               ���X�g     LoRaWAN �Ή�IoT ����E�e�L�X�g������M�p
' [37]LCD               ���X�g     LoRaWAN �Ή�IoT �f�B�X�v���C
' [38]AT Modem          ���X�g     STM LoRa Discovery Kit �pIoT �����{�^���E���M�p
' [39]Tester Barcode    ���X�g     �o�[�R�[�h�ǂݎ��e�X�g�p
'
' [99]���^�[��
'
inputA:?"MJ GET bokunimowakaru.github.io/MJ/pg08/";A;".txt"
