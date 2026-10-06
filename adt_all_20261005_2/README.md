# AtCoder Daily Training ALL 2026/10/05 18:00

またやってまいりました。

平日にはいつもABCのためにトレーニングするコンテストがあるので、できる限り参加したいと思います。どんなコンテストのフォルダにも、自分の考えの流れなども書きます。自分より上手な方でも御覧になってください。自分どこが間違いかは見えませんが、そなたなら見えるかもしれません。

問題表：

| 名前                                                 |  配点   | 種類    |
| ---------------------------------------------------- | :-----: | ------- |
| [Hamming Distance](./Hamming_Distance.cpp)           | 100/100 | -       |
| [Many A+B Problems](./Many_A_B_Problems.cpp)         | 100/100 | -       |
| [Multi Test Cases](./Multi_Test_Cases.cpp)           | 200/200 | -       |
| [Line Sensor](./Line_Sensor.cpp)                     | 200/200 | -       |
| [Sum of Product](./Sum_of_Product.cpp)               | 300/300 | Cumprod |
| [Just K](./Just_K.cpp)                               |  0/300  | -       |
| [Election Quick Report](./Election_Quick_Report.cpp) | 350/350 | -       |
| Takahashi Quest                                      |  0/450  | -       |
| Grid Clipping                                        |  0/500  | -       |

##

### D - Line Sensor

ある行列$H\times W$が与えられて、`#`があったら、箱がその座標に置かれている。`.`があったら、空マスである。列ずつの箱数を求めよ。

これは問題になれないと思いますが、`cin`から入力を読み込んでいるところにも計算できます。それに、APLのような配列言語を使ったら、配列を転置してマスクしてから和関数で削減すればいいです。[Uiuaの提出](https://atcoder.jp/contests/adt_all_20261005_2/submissions/79814847)も載っていました。
