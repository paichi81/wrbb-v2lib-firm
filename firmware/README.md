## paichi81注記：
takjnさんのAdafruit SSD, GFX, NeoPixel関連を ./ext/内にマージし、eep loaderを自分好みに改良、i2cdetectを実装しかけて途中でやめてるという自己責任でどうぞ版です。
mruby-grcitrus-rubishというmrbgemを組み込んだlibmruby.aにしています。
pinをオブジェクトとして定義できるので、ちょっとは見とおしがよくなるかもしれません。
またAdafruit LEDBackpackぽい? LEDmatrix Classも内包しているので、8x8のLED matrixが扱えます。

```ruby:sample.rb
button = Button.new(:pin_8) #=> pin8番,GNDにタクトスイッチを接続
matrix = LEDmatrix::BiColor_8x8.new({:wire=>4, :addr=0x70})

egao = [
  "01111110",
  "10000001",
  "10300301",
  "10000001",
  "10200201",
  "10022001",
  "10000001",
  "01111110"
]
magao = [
  "01111110",
  "10000001",
  "10200201",
  "10200201",
  "10000001",
  "10333301",
  "10000001",
  "01111110"
]


50.times do
  [egao, magao].each do |kao|
    matrix.buffer = kao
    matrix.write_display

    System.exit  if button.on?
    delay 500
  end
end

```





## 概要
Wakayama.rb Ruby Board V2 library Firmware
------
firmware_release フォルダ内にあるものがリリース版です。
firmware_develop フォルダ内にあるものは開発版です。主にWindows環境で動作確認されています。
sample フォルダ内にあるサンプルに関しては、develop版で動作するサンプルも含まれています。行頭にファームウェアのバージョンが入っているのでバージョンを確認してください。

実装しているrubyメソッドなどの使い方は、各フォルダ内のdescriptionフォルダ内にあるRuby Firmware on GR-CITRUS.pdfを参照してください。
また、mrubyフォルダ内にあるファイルは、mrubyのソース( https://github.com/mruby/mruby )に対して修正した差分です。
mrbconf.h
build_config.rb
rx630.rake
などがありますので、mrubyをmakeするときの参考にしてください。

 
(注意)
MacOSの場合は、firmware_release フォルダにある citrus_sketch.binを使用してください。firmware_develop を使用した場合、うまく動作しない恐れがあります。

(Caution)
For MacOS, please use citrus_sketch.bin in the firmware_release folder. Using firmware_develop may not work properly.

　V2ライブラリを使ったWakayama.rb のRubyボードGR-CITRUS用のソースと実行バイナリです。
　V2ライブラリとは、ルネサスさんが提供しているRX631のV2ライブラリを示します。

  バージョンのARIDAやUmeJamの後の数字は動作する基板種類を表します。
  バージョン最後のf2やf3はバイトコードフォーマットの番号です。mruby1.0.0ベースの場合はf2となります。

  mruby ver1.0.0 -> ByteCode Format Ver.0002  
  mruby ver1.1.0 -> ByteCode Format Ver.0003  
  mruby ver1.2.0 -> ByteCode Format Ver.0003  

    WAKAYAMA.RB Board Ver.ARIDA5-1.52(2016/3/19)f3(256KB), mruby 1.2.0
                            |      |      |      |   |
                            |      |      |      |   |
                            |      |      |      |  RAM Size
                            |      |      |      |
                            |      |      |   ByteCode Format Number
                            |      |      |
                            |      |    作成日
                            |      |
                            | Firmware Version
                            |
                       回路基板種類


How to use Wakayama.rb board
------
https://github.com/wakayamarb/wrbb-v2lib-firm/tree/master/firmware_release/description/Ruby%20Firmware%20on%20GR-CITRUS.pdf
http://www.slideshare.net/MinaoYamamoto/grcitrusruby

Link
------


License
------
 Wakayama.rb-Ruby-Board-V2-library-Firmware is released under the [MIT License](MITL).
