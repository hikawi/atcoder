# 中央問題一覧表

自分用にたやすく探索できるように、解けるか解けなかったかの問題を表にします。コンテストで探索もできて、種類でもできるようにしたいです。

種類のまとめ:

| JP             | EN                            |
| -------------- | ----------------------------- |
| 実装           | Implementation / Simulation   |
| 全探索         | Brute Force                   |
| ビット全探索   | Bitmask Brute Force           |
| ビット演算     | Bit Manipulation              |
| 半分全列挙     | Meet in the Middle            |
| 配列           | Array                         |
| 文字列         | Strings                       |
| 連想配列       | Associative Array / Hash Maps |
| 連結リスト     | Linked List                   |
| 行列           | Matrices                      |
| 動的計画法     | Dynamic Programming           |
| 最短経路       | Shortest Path                 |
| 尺取り法       | Two Pointer / Sliding Window  |
| アドホック     | AdHoc                         |
| オフライン処理 | Offline Processing            |
| セグメント木   | Segment Tree                  |
| 貪欲方         | Greedy                        |
| 組み合わせ     | Combinatorics                 |

## ABC

| ID        | 名前                                 | 種類                   | ステータス | 難易度 |                              リンク                               |
| --------- | ------------------------------------ | ---------------------- | :--------: | :----: | :---------------------------------------------------------------: |
| `abc023b` | 手芸王                               | 実装                   |     UP     |  570   |               [リンク](./renshu/abc023b_手芸王.cpp)               |
| `abc038c` | 単調増加                             | 尺取り法               |     UP     |  894   |              [リンク](./renshu/abc038c_単調増加.cpp)              |
| `abc040c` | 柱柱柱柱柱                           | 1DDP                   |     UP     |  896   |             [リンク](./renshu/abc040c_柱柱柱柱柱.cpp)             |
| `abc054b` | Template Matching                    | 行列・実装             |     UP     |  893   |         [リンク](./renshu/abc054b_template_matching.cpp)          |
| `abc055c` | Scc Puzzle                           | アドホック             |     UP     |  561   |             [リンク](./renshu/abc055c_scc_puzzle.cpp)             |
| `abc064c` | Colorful Leaderboard                 | アドホック             |     UP     |  559   |        [リンク](./renshu/abc064c_colorful_leaderboard.cpp)        |
| `abc072c` | Together                             | 連想配列               |     UP     |  407   |              [リンク](./renshu/abc072c_together.cpp)              |
| `abc094c` | Many Medians                         | 配列・連想配列         |     UP     |  566   |            [リンク](./renshu/abc094c_many_medians.cpp)            |
| `abc096c` | Grid Repainting 2                    | 行列                   |     UP     |  407   |         [リンク](./renshu/abc096c_grid_repainting_2.cpp)          |
| `abc150c` | Count Order                          | 全探索                 |     UP     |  422   |            [リンク](./renshu/abc150c_count_order.cpp)             |
| `abc160d` | Line++                               | 最短経路               |     UP     |  879   |                [リンク](./renshu/abc160d_line.cpp)                |
| `abc171c` | One Quadrillion and One Dalmatians   | 数学                   |     UP     |  560   | [リンク](./renshu/abc171c_one_quadrillion_and_one_dalmatians.cpp) |
| `abc189c` | Mandarin Orange                      | 全探索                 |     UP     |  565   |          [リンク](./renshu/abc189c_mandarin_orange.cpp)           |
| `abc198c` | Compass Walking                      |                        |            |  413   |          [リンク](./renshu/abc198c_compass_walking.cpp)           |
| `abc230c` | X drawing                            | 行列・数学             |     UP     |  566   |             [リンク](./renshu/abc230c_x_drawing.cpp)              |
| `abc234e` | Arithmetic Number                    | 二分探索               |     UP     |  899   |         [リンク](./renshu/abc234e_arithmetic_number.cpp)          |
| `abc240d` | Strange Balls                        | 実装                   |     UP     |  570   |           [リンク](./renshu/abc240d_strange_balls.cpp)            |
| `abc280d` | Factorial and Multiple               | 数学                   |            |  880   |       [リンク](./renshu/abc280d_factorial_and_multiple.cpp)       |
| `abc286c` | Rotate and Palindrome                | 文字列                 |     UP     |  565   |       [リンク](./renshu/abc286c_rotate_and_palindrome.cpp)        |
| `abc314d` | LOWER                                | オフライン処理         |     UP     |  585   |               [リンク](./renshu/abc314d_lower.cpp)                |
| `abc324d` | Square Permutation                   | 全探索                 |     UP     |  895   |         [リンク](./renshu/abc324d_square_permutation.cpp)         |
| `abc356c` | Keys                                 | ビット全探索           |     UP     |  568   |                [リンク](./renshu/abc356c_keys.cpp)                |
| `abc360a` | A Healthy Breakfast                  | 実装                   |     UP     |   19   |   [リンク](./adt/adt_all_20261026_1/b_a_healthy_breakfast.cpp)    |
| `abc366c` | Balls and Bag Query                  | 連想配列               |     UP     |  180   |   [リンク](./adt/adt_all_20261026_1/f_balls_and_bag_query.cpp)    |
| `abc366d` | Cuboid Sum Query                     | 累積和                 |     UP     |  586   |          [リンク](./renshu/abc366d_cuboid_sum_query.cpp)          |
| `abc376c` | Prepare Another Box                  | 二分探索               |     UP     |  366   |   [リンク](./adt/adt_all_20261026_1/e_prepare_another_box.cpp)    |
| `abc378d` | Count Simple Paths                   | 深さ優先探索・全探索   |     UP     |  587   |         [リンク](./renshu/abc378d_count_simple_paths.cpp)         |
| `abc381b` | 1122 String                          | 文字列・実装           |     UP     |   52   |       [リンク](./adt/adt_all_20261026_1/c_1122_string.cpp)        |
| `abc407a` | Approximation                        | 実装                   |     UP     |  587   |      [リンク](./adt/adt_all_20261026_1/a_approximation.cpp)       |
| `abc435d` | Reachability Query 2                 | 深さ優先探索           |     UP     |  568   |        [リンク](./renshu/abc435d_reachability_query_2.cpp)        |
| `abc452b` | Draw Frame                           | 実装                   |     UP     |   25   |        [リンク](./adt/adt_all_20261026_1/d_draw_frame.cpp)        |
| `abc471d` | Chargers                             | アドホック             |     UP     |  570   |              [リンク](./renshu/abc471d_chargers.cpp)              |
| `abc475d` | Alphametic Prime                     | アドホック             |     UP     |  741   |          [リンク](./renshu/abc475d_alphametic_prime.cpp)          |
| `abc477a` | Traffic Light                        | 実装                   |     AC     |   17   |            [リンク](./abc/abc477/a_traffic_light.cpp)             |
| `abc477b` | Standing Outliers                    | 全探索・配列           |     AC     |   79   |          [リンク](./abc/abc477/b_standing_outliers.cpp)           |
| `abc477c` | Range Search Query                   | 文字列・累積和         |     UP     |  456   |          [リンク](./abc/abc477/c_range_search_query.cpp)          |
| `abc477d` | Masking Type                         | オフライン処理         |     UP     |  946   |             [リンク](./abc/abc477/d_masking_tape.cpp)             |
| `abc477e` | Wheel Distance                       | 最短経路               |     UP     |  1235  |            [リンク](./abc/abc477/e_wheel_distance.cpp)            |
| `abc478a` | Grapes                               | 実装                   |     AC     |   18   |                [リンク](./abc/abc478/a_grapes.cpp)                |
| `abc478b` | Topping                              | 全探索                 |     AC     |   90   |               [リンク](./abc/abc478/b_topping.cpp)                |
| `abc478c` | Sort Subarray                        | 配列・アドホック       |     UP     |  426   |            [リンク](./abc/abc478/c_sort_subarray.cpp)             |
| `abc478d` | Range Set Insertion Query            | 累積和・オフライン処理 |            |  729   |      [リンク](./abc/abc478/d_range_set_insertion_query.cpp)       |
| `abc479a` | Odd Index Sum                        | 実装                   |     AC     |   12   |            [リンク](./abc/abc479/a_odd_index_sum.cpp)             |
| `abc479b` | Longest Rainy Streak                 | 実装                   |     AC     |   33   |         [リンク](./abc/abc479/b_longest_rainy_streak.cpp)         |
| `abc479c` | Bento Packing                        | ビット全探索           |     AC     |  276   |            [リンク](./abc/abc479/c_bento_packing.cpp)             |
| `abc479d` | Back and Forth Distance              | 連結リスト             |     AC     |  563   |       [リンク](./abc/abc479/d_back_and_forth_distance.cpp)        |
| `abc479e` | Cut and Add                          | 木構造                 |            |  1000  |             [リンク](./abc/abc479/e_cut_and_add.cpp)              |
| `abc480a` | ADjacent                             | 実装                   |     AC     |   35   |               [リンク](./abc/abc480/a_adjacent.cpp)               |
| `abc480b` | Invalid Vote                         | 文字列                 |     AC     |  201   |             [リンク](./abc/abc480/b_invalid_vote.cpp)             |
| `abc480c` | Self-Stopping Shower                 | 数学                   |     UP     |  625   |         [リンク](./abc/abc480/c_self_stopping_shower.cpp)         |
| `abc480d` | Concatenation of Prefixes            | 累積和                 |     AC     |  864   |      [リンク](./abc/abc480/d_concatenation_of_prefixes.cpp)       |
| `abc480d` | Product-Bounded Arithmetic Sequences | 全探索・二分探索       |     UP     |  1355  | [リンク](./abc/abc480/e_product_bounded_arithmetic_sequences.cpp) |
| `abc481a` | Digits of A + B                      | 実装                   |     AC     |   17   |            [リンク](./abc/abc481/a_digits_of_a_b.cpp)             |
| `abc481b` | Polyline                             | 実装                   |     AC     |   78   |               [リンク](./abc/abc481/b_polyline.cpp)               |
| `abc481c` | Bank Accounts                        | 連想配列               |     AC     |   78   |            [リンク](./abc/abc481/c_bank_accounts.cpp)             |
| `abc481d` | Autopilot                            | 最短経路               |     AC     |  581   |              [リンク](./abc/abc481/d_autopilot.cpp)               |
| `abc481e` | Most Brilliant Starry Sky            |                        |            |  1326  |      [リンク](./abc/abc481/e_most_brilliant_starry_sky.cpp)       |

## ARC

| ID        | 名前               | 種類     | ステータス | 難易度 |                      リンク                       |
| --------- | ------------------ | -------- | :--------: | :----: | :-----------------------------------------------: |
| `arc044a` | 素数判定           | 数学     |     UP     |  560   |      [リンク](./renshu/arc044a_素数判定.cpp)      |
| `arc161b` | Exactly Three Bits | 二分探索 |     UP     |  563   | [リンク](./renshu/arc161b_exactly_three_bits.cpp) |

## AGC

一生このコンテストに参加できないかもしれません。

## AWC

| ID         | 名前             | 種類                 | ステータス |                     リンク                     |
| ---------- | ---------------- | -------------------- | :--------: | :--------------------------------------------: |
| `awc0178a` | 円高と円安       | 実装                 |     UP     |    [リンク](./awc/awc0178/a_円高と円安.cpp)    |
| `awc0178b` | 田舎町の駅       | 実装                 |     UP     |    [リンク](./awc/awc0178/b_田舎町の駅.cpp)    |
| `awc0178c` | 荷物の回収       | 貪欲方               |     UP     |    [リンク](./awc/awc0178/c_荷物の回収.cpp)    |
| `awc0178d` | 道路網の整備     |                      |            |    [リンク](./awc/awc0178/d_荷物の回収.cpp)    |
| `awc0178e` | 照明スイッチ     | ビット演算・最短経路 |     UP     |   [リンク](./awc/awc0178/e_照明スイッチ.cpp)   |
| `awc0179a` | 売り主の値札     | 実装                 |     AC     |   [リンク](./awc/awc0179/a_売り主の値札.cpp)   |
| `awc0179b` | 焼き肉の順番     | 配列                 |     AC     |   [リンク](./awc/awc0179/b_焼き肉の順番.cpp)   |
| `awc0179c` | 学園祭の出店計画 | 実装                 |     AC     | [リンク](./awc/awc0179/c_学園祭の出店計画.cpp) |

## Educational DP Contest

| ID     | 名前         | 種類  | ステータス |              リンク               |
| ------ | ------------ | ----- | :--------: | :-------------------------------: |
| `dp_a` | Frog 1       | 1DDP  |     AC     |    [リンク](./dp/a_frog_1.cpp)    |
| `dp_b` | Frog 2       | 1DDP  |     AC     |    [リンク](./dp/b_frog_2.cpp)    |
| `dp_c` | Vacation     | 2DDP  |     AC     |   [リンク](./dp/c_vacation.cpp)   |
| `dp_d` | Knapsack 1   | 2DDP  |     AC     |  [リンク](./dp/d_knapsack_1.cpp)  |
| `dp_e` | Knapsack 2   | 2DDP  |     AC     |  [リンク](./dp/e_knapsack_2.cpp)  |
| `dp_f` | LCS          | 2DDPR |     AC     |     [リンク](./dp/f_lcs.cpp)      |
| `dp_g` | Longest Path | 1DDP  |     AC     | [リンク](./dp/g_longest_path.cpp) |

## Tessoku

| ID  | 名前                        | 種類                     | ステータス | 難易度 |                         リンク                          |
| --- | --------------------------- | ------------------------ | :--------: | :----: | :-----------------------------------------------------: |
| A01 | The First Problem           | 実装                     |     AC     |  1/9   |      [リンク](./tessoku/a01_the_first_problem.cpp)      |
| A02 | Linear Search               | 全探索                   |     AC     |  1/9   |        [リンク](./tessoku/a02_linear_search.cpp)        |
| A03 | Two Cards                   | 全探索                   |     AC     |  1/9   |          [リンク](./tessoku/a03_two_cards.cpp)          |
| A04 | Binary Representation       | ビット演算               |     AC     |  2/9   |    [リンク](./tessoku/a04_binary_representation.cpp)    |
| A05 | Three Cards                 | 全探索                   |     AC     |  2/9   |         [リンク](./tessoku/a05_three_cards.cpp)         |
| A06 | How Many Guests?            | 累積和                   |     AC     |  2/9   |       [リンク](./tessoku/a06_how_many_guests.cpp)       |
| A07 | Event Attendance            | 累積和                   |     AC     |  3/9   |      [リンク](./tessoku/a07_event_attendance.cpp)       |
| A08 | Two Dimensional Sum         | 累積和                   |     AC     |  4/9   |     [リンク](./tessoku/a08_two_dimensional_sum.cpp)     |
| A09 | Winter in ALGO Kingdom      | 累積和                   |     AC     |  4/9   |   [リンク](./tessoku/a09_winter_in_algo_kingdom.cpp)    |
| A10 | Resort Hotel                | 累積和                   |     AC     |  4/9   |        [リンク](./tessoku/a10_resort_hotel.cpp)         |
| A11 | Binary Search 1             | 二分探索                 |     AC     |  2/9   |       [リンク](./tessoku/a11_binary_search_1.cpp)       |
| A12 | Printer                     | 二分探索                 |     AC     |  3/9   |           [リンク](./tessoku/a12_printer.cpp)           |
| A13 | Close Pairs                 | 尺取り法                 |     AC     |  4/9   |         [リンク](./tessoku/a13_close_pairs.cpp)         |
| A14 | Four Boxes                  | 半分全列挙               |     AC     |  5/9   |         [リンク](./tessoku/a14_four_boxes.cpp)          |
| A15 | Compression                 | アドホック・二分探索     |     AC     |  3/9   |         [リンク](./tessoku/a15_compression.cpp)         |
| A16 | Dungeon 1                   | 1DDP                     |     AC     |  2/9   |          [リンク](./tessoku/a16_dungeon_1.cpp)          |
| A17 | Dungeon 2                   | 1DDPR                    |     AC     |  3/9   |          [リンク](./tessoku/a17_dungeon_2.cpp)          |
| A18 | Subset Sum                  | 2DDP                     |     AC     |  3/9   |         [リンク](./tessoku/a18_subset_sum.cpp)          |
| A19 | Knapsack 1                  | 2DDP                     |     AC     |  3/9   |         [リンク](./tessoku/a19_knapsack_1.cpp)          |
| A20 | LCS                         | 2DDP・文字列             |     AC     |  4/9   |             [リンク](./tessoku/a20_lcs.cpp)             |
| A21 | Block Game                  | 区間DP                   |     AC     |  4/9   |         [リンク](./tessoku/a21_block_game.cpp)          |
| A22 | Sugoroku                    | 1DDP                     |     AC     |  4/9   |          [リンク](./tessoku/a22_sugoroku.cpp)           |
| A23 | All Free                    | ビットDP                 |     AC     |  5/9   |          [リンク](./tessoku/a23_all_free.cpp)           |
| A24 | LIS                         | 1DDP                     |     AC     |  5/9   |             [リンク](./tessoku/a24_lis.cpp)             |
| A25 | Number of Routes            | 1DDP                     |     AC     |  3/9   |      [リンク](./tessoku/a25_number_of_routes.cpp)       |
| A26 | Prime Check                 | 数学                     |     AC     |  2/9   |         [リンク](./tessoku/a26_prime_check.cpp)         |
| A27 | Calculate GCD               | 数学                     |     AC     |  2/9   |        [リンク](./tessoku/a27_calculate_gcd.cpp)        |
| A28 | Blackboard                  | 数学                     |     AC     |  2/9   |         [リンク](./tessoku/a28_blackboard.cpp)          |
| A29 | Power                       | 数学                     |     AC     |  3/9   |            [リンク](./tessoku/a29_power.cpp)            |
| A30 | Combination                 | 数学                     |     AC     |  4/9   |         [リンク](./tessoku/a30_combination.cpp)         |
| B01 | A+B Problem                 | 実装                     |     AC     |   -    |         [リンク](./tessoku/b01_a_b_problem.cpp)         |
| B02 | Divisor Check               | 数学・全探索             |     AC     |   -    |        [リンク](./tessoku/b02_divisor_check.cpp)        |
| B03 | Supermarket                 | 全探索                   |     AC     |   -    |         [リンク](./tessoku/b03_supermarket.cpp)         |
| B04 | Supermarket                 | ビット演算               |     AC     |   -    |   [リンク](./tessoku/b04_binary_representation_2.cpp)   |
| B06 | Lottery                     | 累積和                   |     AC     |   -    |           [リンク](./tessoku/b06_lottery.cpp)           |
| B07 | Convenience Store 2         | 累積和                   |     AC     |   -    |     [リンク](./tessoku/b07_convenience_store_2.cpp)     |
| B08 | Counting Points             | 累積和                   |     AC     |   -    |       [リンク](./tessoku/b08_counting_points.cpp)       |
| B09 | Papers                      | 累積和                   |     AC     |   -    |           [リンク](./tessoku/b09_papers.cpp)            |
| B11 | Binary Search 2             | 二分探索                 |     AC     |   -    |       [リンク](./tessoku/b11_binary_search_2.cpp)       |
| B12 | Equation                    | 二分探索                 |     AC     |   -    |          [リンク](./tessoku/b12_equation.cpp)           |
| B13 | Supermarket 2               | 尺取り法                 |     AC     |   -    |        [リンク](./tessoku/b13_supermarket_2.cpp)        |
| B14 | Another Subset Sum          | ビット全探索・半分全列挙 |     AC     |   -    |     [リンク](./tessoku/b14_another_subset_sum.cpp)      |
| B16 | Frog 1                      | 1DDP                     |     AC     |   -    |           [リンク](./tessoku/b16_frog_1.cpp)            |
| B17 | Frog 1 with Restoration     | 1DDPR                    |     AC     |   -    |   [リンク](./tessoku/b17_frog_1_with_restoration.cpp)   |
| B18 | Subset Sum with Restoration | 2DDPR                    |     AC     |   -    | [リンク](./tessoku/b18_subset_sum_with_restoration.cpp) |
| B19 | Knapsack 2                  | 2DDP                     |     AC     |   -    |         [リンク](./tessoku/b19_knapsack_2.cpp)          |
| B20 | Edit Distance               | 2DDP・文字列             |     AC     |   -    |        [リンク](./tessoku/b20_edit_distance.cpp)        |
| B21 | Longest Palindrome          | 2DDP・文字列             |     AC     |   -    |     [リンク](./tessoku/b21_longest_palindrome.cpp)      |
| B22 | Dungeon 1                   | 1DDP                     |     AC     |   -    |          [リンク](./tessoku/b22_dungeon_1.cpp)          |
| B23 | Traveling Salesman Problem  | ビットDP                 |     AC     |   -    | [リンク](./tessoku/b23_traveling_salesman_problem.cpp)  |
| B24 | Many Boxes                  | 1DDP                     |     AC     |   -    |         [リンク](./tessoku/b24_many_boxes.cpp)          |
| B26 | Output Prime Numbers        | 数学                     |     AC     |   -    |    [リンク](./tessoku/b26_output_prime_numbers.cpp)     |
| B27 | Calculate LCM               | 数学                     |     AC     |   -    |        [リンク](./tessoku/b27_calculate_lcm.cpp)        |
| B28 | Fibonacci Easy              | 数学                     |     AC     |   -    |       [リンク](./tessoku/b28_fibonacci_easy.cpp)        |
| B29 | Power Hard                  | 数学                     |     AC     |   -    |         [リンク](./tessoku/b29_power_hard.cpp)          |
| B30 | Combination 2               | 組み合わせ               |     AC     |   -    |        [リンク](./tessoku/b30_combination_2.cpp)        |

## Others

| ID                           | 名前        | 種類     | ステータス | 難易度 |                            リンク                             |
| ---------------------------- | ----------- | -------- | :--------: | :----: | :-----------------------------------------------------------: |
| `code_festival_2017_qualb_b` | Problem Set | 連想配列 |     UP     |  568   | [リンク](./renshu/code_festival_2017_qualb_b_problem_set.cpp) |
