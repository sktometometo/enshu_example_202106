# Arduino に繋がったサーボモータをPCのプログラムからシリアル通信で動かすサンプルプログラム

Arduino に付属のコードを書き込み、

`ls -l /dev/ttyUSB*` で見つかるArduino のシリアルポートに書き換えて

C言語バージョンの場合
```
gcc -o serial_test serial_test.c
```

C++言語バージョンの場合
```
g++ -o serial_test serial_test.cpp -I/usr/include/boost -lboost_system
```

としたあとに

```
./serial_test
```

とすると, 1秒ごとにサーボモータが動きます

インクルード部分と初期化部分, サーボモータを動かす関数をOpenCVなどのプログラムに組み込むと、画像処理と連携してサーボモータが動かせます。
