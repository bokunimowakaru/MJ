new
100 cls:?"OLED BMP":?"ÀÞ³ÝÛ°ÀÞ":?:?"by":?"W.Kunino":gsb800
110 ifi2cw(60,#8A8,1,#8AA,6)?"E
120 B=0:goto300
200 'LINE
210 cls:uart0:forI=0to15:chr$(#E0+I);:next:?:?"Step ";B+1;"/8"
220 ifi2cw(60,#8A9,1,#700,128)?"E
300 'MJ
310 B=B+1:uart1:?"MJ GET bokunimowakaru.github.io/MJ/pg05/bmp/ras/";B;".txt"
320 end
800 'INIT
810 let[84],#4000,33,#227F,#700,#D5AE,#8D80,#2014,#DA00,#8112,#D9CF,#DBF1,#A440,#AFA6
820 ifi2cw(60,#8A8,1,#8B0,18)?"E
900 'OUT
910 ifi2cw(60,#8A8,1,#8AA,6)?"E
920 for[98]=0to7:for[99]=0to15:copy#8A0,vpeek(7-[98],[99])*8,8:ifi2cw(60,#8A9,1,#8A0,8)?"E
930 next:next:rtn
