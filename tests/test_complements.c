#include "tests.h"

START_TEST(test_calc_complements_0) {
  matrix_t A, B, RES;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &RES);
  double arr1[] = {
      1, 2, 3, 0, 4, 2, 5, 2, 1,
  };
  double arr3[] = {
      0, 10, -20, 4, -14, 8, -8, -2, 4,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_1) {
  matrix_t A, B, RES;
  s21_create_matrix(8, 8, &A);
  s21_create_matrix(8, 8, &RES);
  double arr1[] = {
      7.042713553067156,   9.635052080873164,   8.43874487621824,
      0.33376205037375295, 9.7959291473138,     5.8981978155566965,
      2.947025460786721,   6.683030035295748,   0.39689757913598156,
      6.44123882285278,    5.7163737981504,     3.3427348167697364,
      9.732413559052675,   8.8902444424792,     3.209940129736846,
      9.705236823188544,   7.970464078019967,   1.0051893603021804,
      4.5122716576747735,  6.456864707786073,   0.05132416852476932,
      8.463978168930304,   2.0252495843880802,  9.783330109510457,
      7.277576475079858,   3.7494935170701003,  5.126415590192077,
      4.609426337751689,   8.417271851169499,   3.4117225466439627,
      9.701552715031212,   8.483521577207046,   9.8048924666119,
      6.8925010899301755,  7.792389867128735,   5.269689082307245,
      3.7133554636268014,  1.9269308978121946,  9.359746480608251,
      7.927985981827705,   4.987628473640678,   6.865622806915042,
      9.346847142415537,   7.6428614449084025,  2.579297273799817,
      0.2776252739959027,  8.226732221742862,   5.753424491068108,
      9.036841162825874,   0.16657908139432032, 2.581236271801216,
      7.126844567934832,   2.3444939233134816,  2.777532192626472,
      3.6547619740880353,  4.325316238024846,   3.895110200093602,
      0.6402462125516462,  7.375364643044347,   7.080655208850232,
      7.083122013353,      6.282870460042792,   6.983358607766517,
      0.705381493184302,
  };
  double arr3[] = {
      258988.4069439254,   -654207.2232557435,  1029420.628327178,
      -418561.2656538743,  419871.8806100286,   -555792.1620398057,
      -701557.3102054157,  281540.5445992495,   -284974.07277381653,
      1396313.3936544124,  -1498035.1235014026, 674182.2158049264,
      -211778.46801549685, 823829.2885469345,   450592.4423184246,
      -470219.39841070253, 14715.637632763168,  -1059957.9667936321,
      1115576.6957698185,  -491200.2061776717,  -120900.9053233419,
      -213753.08168996096, -341389.00411554315, 644941.8574777971,
      -42626.423864065924, -1851928.666517953,  1415589.3460013708,
      -672483.5691624891,  723657.6724383715,   -1199119.3003889034,
      -388940.1432753592,  1130063.3120926186,  191402.73367870826,
      2425719.3737440924,  -2383116.149550756,  232143.5941285582,
      -1127531.9433623808, 1821784.3303760418,  1594272.3449626768,
      -1359455.3855155874, -272849.6167646499,  -994964.1061389095,
      1440508.92161906,    141016.862674894,    368120.42811537243,
      -1186060.747471969,  -803762.1122394787,  757624.3077326422,
      304616.576322404,    780457.99306921,     -1081488.6772417233,
      956528.1689353217,   276717.53583247465,  -4208.1199682711895,
      -306073.4319054574,  -395300.53135094617, -17882.150100620223,
      26912.933621729648,  27122.17583090347,   -34429.2741417867,
      -117375.79153958787, 541438.2943776094,   373990.30163391243,
      -523208.59603769577,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_2) {
  matrix_t A, B, RES;
  s21_create_matrix(8, 8, &A);
  s21_create_matrix(8, 8, &RES);
  double arr1[] = {
      3.101739071461751,  6.581078285950506,  2.00291500324442,
      7.753306703728923,  3.0143755902643203, 7.375298435337702,
      2.2513953362831955, 2.1512355046765816, 6.256405317806929,
      1.3532861517130572, 1.6802894532246766, 1.703977875631235,
      2.7694560058075224, 4.653026963271886,  0.025546477611485756,
      8.811840403090374,  8.721567821724236,  3.1678740463057453,
      3.9645729254115865, 3.201212666633481,  8.206729055189255,
      4.275101287168267,  0.5051688683477469, 2.548182594387924,
      3.481912111873473,  2.274606747620235,  5.629204645717617,
      9.436883338674486,  7.784898868370724,  3.150391035752252,
      0.879810834431109,  2.8146423261277946, 4.671523404588328,
      1.1505825636366247, 0.9779102517819868, 8.100777247669958,
      4.536996708725206,  3.2808091717607737, 8.623123621463542,
      0.2387375843759333, 2.7274306108095185, 0.03346379665953285,
      7.5589578269518976, 8.9918642951794,    0.3917963327364706,
      6.3324078468859835, 6.003471755139859,  8.956344006831273,
      4.132770777817242,  5.502347365602682,  7.959941446539345,
      7.845836569928889,  9.89125174279674,   7.395372970357044,
      0.7920785761683026, 4.738369282785765,  1.5786516246366133,
      1.226964057861325,  7.911662208385577,  7.969260330526677,
      2.237752366268679,  9.758238372069325,  7.1686671630661305,
      0.855441118412473,
  };
  double arr3[] = {
      -211245.25934869575, -483495.6522745011,  59702.62745974447,
      -247064.29457554998, 423706.6066341958,   13716.746570295478,
      172817.76823122703,  119718.71930995144,  223970.8460129894,
      867613.7111994466,   812008.5260173208,   -91144.22969463222,
      -432534.73638008005, -833515.4849509486,  308438.76578199543,
      -263763.6679212181,  -799528.1061910656,  -457796.75974859804,
      -674921.5012690352,  131863.71472977905,  505149.675211425,
      493937.95966503734,  -15725.526565320508, 321632.9046180922,
      -87031.96082080902,  904390.9494141351,   375136.1327451719,
      -743451.3846661709,  -75341.14310436322,  -346599.8841837299,
      748332.5718667944,   199659.79235659845,  193914.5061854146,
      -25506.22324866766,  317852.04151687963,  101693.54277187306,
      -359516.01325432485, 87591.81713299376,   -491784.3009854676,
      -145871.62254130418, -265321.7397747419,  -667329.5811202342,
      -690441.0101889519,  61584.34319627696,   522196.58635308256,
      752951.0183788382,   -303839.72814560647, -150217.11173220887,
      643695.6407322605,   -552438.6386534716,  -142592.09685884113,
      544232.2570381955,   -565726.5733450577,  192013.88016129832,
      -535195.9847352232,  -372271.32838489406, 50384.342488274866,
      720602.5050722255,   191507.30423610588,  -74164.36009391786,
      -100231.01791644584, -750752.3196391748,  255721.66117164848,
      258572.9830083001,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_3) {
  matrix_t A, B, RES;
  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &RES);
  double arr1[] = {
      8.561050867504111,  4.907504156813384,  1.3215563645946558,
      7.238982924259853,  2.208057053612642,  3.2026575248616203,
      4.8308245209723175, 7.851749435792652,  1.2396644843155828,
      6.107350876972358,  4.2011974728435835, 0.5866738981968744,
      2.2677134617610046, 4.375891161596863,  2.4910676856390577,
      2.913672881432816,  6.189003643877778,  0.4325605014812034,
      2.7945918947598325, 7.099156140859245,  9.354519862638842,
      5.88997543014123,   2.095080616236493,  1.5450137488760305,
      1.3221757305977742, 4.725370046541347,  2.1977335831433655,
      1.367819368291191,  3.221249816629079,  2.0529468412506575,
      8.46225303652863,   1.1909310154831518, 0.21311104884127202,
      2.365550002586036,  5.6677693622618595, 7.970966903071554,
  };
  double arr3[] = {
      -5791.128485099956,  -1678.339133156912,  -1706.3053397437693,
      6126.8286663682875,  828.828265142091,    4036.8360115780215,
      6347.443453018391,   1780.439287774774,   1994.2197036383707,
      -6864.567820834926,  -846.737242012135,   -4418.717811774348,
      -2768.9726110796037, -682.1294591582315,  -879.6592543647528,
      2927.707607806278,   172.78195036452857,  2073.3562614299935,
      1993.4802049299547,  622.5275606381152,   483.8999511955825,
      -2172.291373970168,  -244.56946084322485, -1403.721618362543,
      -5745.506483955378,  -1965.283343470939,  -1687.6728953622787,
      6440.736027187771,   868.6245386466111,   3909.320164634248,
      3103.27910917258,    965.8149560847008,   927.4071249649967,
      -3353.1127161895142, -456.3825137248728,  -2264.3219356020977,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_4) {
  matrix_t A, B, RES;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &RES);
  double arr1[] = {
      7.050408957924067,
  };
  double arr3[] = {
      0.9999999999999999,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_5) {
  matrix_t A, B, RES;
  s21_create_matrix(6, 6, &A);
  s21_create_matrix(6, 6, &RES);
  double arr1[] = {
      2.8469718126200974, 6.070301367295232,   5.352649272230504,
      9.144256963881338,  0.693299250695358,   0.07129845492117809,
      6.033626940168441,  8.970649661869494,   3.4528529188556534,
      8.241240108398607,  4.73876303662043,    1.804745974739526,
      7.063276138880718,  1.8289628715865416,  2.8454444705236903,
      9.517036837224788,  2.886718540532767,   4.59010833804908,
      4.153303619679038,  3.2921850868402185,  8.78074887865898,
      5.221638839154767,  5.710058207036212,   8.104661807805654,
      3.9502565021763076, 0.21705996295278626, 6.821341266318311,
      2.6629422067227138, 9.383945726495726,   4.564142915486803,
      3.0461451725727073, 7.303280710220333,   8.806367150681112,
      8.358504834761996,  7.300396212685562,   2.966132674156846,
  };
  double arr3[] = {
      11803.927034453885,  -1955.3651039597255, 11661.24437744485,
      -5096.274041519437,  -7379.22352566043,   -9406.392397176718,
      6977.608276829108,   4190.2444195320095,  191.86141644029328,
      -4978.749612060769,  -993.1812817445274,  -1578.291339971594,
      -5354.575706909691,  -2615.6386976317353, -6240.849890677296,
      6803.752740458184,   2909.3659884283343,  4134.6934827495415,
      2423.5655120395104,  1936.3882800690747,  3232.368946996953,
      -3644.811544085446,  -4166.732201619672,  3672.8038903913075,
      10117.828041869085,  -2886.544409738395,  6793.080485719349,
      -5108.1770679396095, -555.6186289832915,  -7689.652970010217,
      -18434.010760684876, 695.8494655641645,   -10024.28525589497,
      10442.279931091804,  8519.558299455432,   7294.434124544732,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_6) {
  matrix_t A, B, RES;
  s21_create_matrix(7, 7, &A);
  s21_create_matrix(7, 7, &RES);
  double arr1[] = {
      8.804583573451032,   7.530242267196333,    7.067780689667607,
      0.7326999839503385,  7.195566393441089,    7.5967421055940845,
      0.29580135534589747, 6.349274177127615,    6.262882306303842,
      6.93941237208719,    9.844630436423568,    0.4793087661882598,
      8.204754170653771,   0.059566628949833805, 5.103666155573085,
      0.42328738191864246, 4.7415073902649985,   9.530305015651681,
      5.637093062797751,   1.7401054173967003,   8.4305645871986,
      2.6753540344325133,  1.9230761543768744,   6.986912875048936,
      2.7150281113331176,  5.633250055317585,    4.874417308047084,
      5.276513019284446,   0.9868261076126813,   9.739289346358392,
      6.838854185550912,   5.357221924778151,    1.5121646494889223,
      4.7738529514570125,  2.405315903189054,    0.05932090047058217,
      9.774898232941451,   8.57876245432912,     5.899035486283312,
      9.714193660943279,   3.595975094250653,    7.536971119396397,
      0.8144207288749393,  1.8967746832114714,   5.758324618570232,
      1.357781049678758,   2.5016547544031433,   0.7614288102727624,
      1.7440027719851812,
  };
  double arr3[] = {
      64035.513851611,     29006.33582469473,   -11667.416733343458,
      -32746.64974100787,  5852.9452771772585,  -22907.76292260347,
      4173.045229503447,   -52932.811586193275, -44083.25906328153,
      3896.657825160719,   77819.02942149962,   59449.56092724142,
      41664.66697965051,   -104254.87440145234, 71399.10905388018,
      18939.510008694153,  -11727.43619832693,  -1761.7480560560289,
      -39250.76681038639,  -55869.0466647444,   66847.21273133835,
      -44300.604143111275, -50041.5069523177,   9075.982632304045,
      -49859.988627437975, -33478.398528365,    126026.19565287023,
      76963.58518702057,   61781.02696016641,   83716.3279114892,
      4567.83395004747,    -76629.4355673155,   -148993.46280192636,
      -15981.643057149304, 145375.48709015927,  -74917.15110018179,
      -7856.425725787253,  -25682.75201577721,  59530.52336444022,
      113858.80125567957,  8230.148487542143,   -84934.45602136472,
      18391.4094505392,    -25075.00764467763,  135769.03378382657,
      10681.554544529457,  1438.4496084717666,  -122285.59892167084,
      -74030.25790679883,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_7) {
  matrix_t A, B, RES;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &RES);
  double arr1[] = {
      4.538756592743531, 6.847420838561413,  6.9112232154020345,
      4.898439576322962, 4.969601218585955,  5.228777218964402,
      8.05732407136536,  2.5013482760097445, 1.383042717575597,
  };
  double arr3[] = {
      -6.205822107675516, 35.35520136665113,  -27.788984134225885,
      7.817100750016649,  -49.40867092359572, 43.818877770822745,
      1.457614776150551,  10.12206224456549,  -10.985866937184497,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_8) {
  matrix_t A, B, RES;
  s21_create_matrix(9, 9, &A);
  s21_create_matrix(9, 9, &RES);
  double arr1[] = {
      0.05283267517971968, 4.937249600988182,  0.4108429837684947,
      4.717829209408941,   6.6907680164546965, 7.919660850565264,
      6.693241982156781,   8.106658932431626,  1.5586850888410348,
      6.312241503737427,   7.872982832825678,  1.3377164557472563,
      7.290330580717115,   1.7822318223472036, 5.4346161142148,
      4.574556656458183,   1.7465400833353772, 1.9753339037882682,
      3.4911894679128026,  7.79222734952311,   2.9961126790635153,
      4.914994540356761,   6.080009065451014,  7.331127059652495,
      1.751795735324667,   4.365467196790435,  9.212165743717796,
      9.298970758995312,   0.6134734819508129, 5.060846247599834,
      1.7940957532308457,  6.621437348135455,  9.433871823674828,
      2.1379580920816643,  4.314960158057391,  0.7041765921547956,
      3.685799619714695,   3.6054787564139903, 6.983518214449196,
      8.460193520419848,   5.384065077962049,  0.4671476935372929,
      2.051999809852774,   1.1144467119683905, 2.997919935429723,
      2.7686348949807638,  7.033673313221616,  1.0558541850505312,
      7.6632491605818664,  4.778207148526199,  8.368211142049377,
      5.307922175071453,   7.076217093853694,  0.8678676445345461,
      2.002516372642226,   3.5806888540896216, 5.72293806643529,
      9.753895535637188,   8.948605944655347,  9.711297367589921,
      8.994085504538479,   4.7412901391919755, 2.181145785536932,
      2.142548259463313,   6.864930918423323,  5.3557410074945135,
      4.35662186837562,    2.0829354527388673, 2.8366510938458926,
      6.073255227148458,   3.3408185677485442, 6.988674525689106,
      5.845385955371614,   9.765524206594408,  5.885119675524084,
      9.786485706495935,   9.062367919928882,  9.56573332848196,
      7.696257906447886,   8.695224697628364,  8.296437573752947,
  };
  double arr3[] = {
      -420562.63949918747, 2781972.0735797887,  257288.3362347083,
      -2295207.691360788,  2785675.473394366,   -869265.957491649,
      525904.6019730546,   -1188004.7893632168, -1736697.0470505701,
      499184.8412631292,   989198.967292329,    -648958.0583457712,
      -541120.8011565371,  956111.651573288,    -370699.79159326234,
      651560.2598479902,   -1136824.3047114445, -447343.92342495243,
      -782601.5478323152,  1359511.1700670433,  522886.407811863,
      -749033.0202659594,  782070.7078769812,   655308.60142275,
      -745487.1665266416,  -1006878.9760579674, -399207.32704315876,
      121948.3317951508,   496530.1245054164,   638599.7148000944,
      -716138.901955517,   247441.4235731087,   221257.7112438443,
      -147252.4077853221,  -111797.47239200912, -550232.0031916737,
      -382539.70168931206, 1595137.4074887868,  886351.3592342519,
      -733687.6620485659,  1289744.0796680627,  -537976.5174783715,
      -458371.7266240698,  -518319.80387447495, -1191434.5125170154,
      -744393.7604139922,  -209500.8795300657,  1113092.8990802094,
      922181.403121831,    -1916757.7030936829, 1102964.4222054807,
      -1278180.5764805828, 1159472.48653694,    -313798.75084957876,
      -268738.61400780565, -879403.3246607935,  -99348.61952924739,
      623130.2251194298,   -404626.6629217948,  641994.5939735617,
      285833.32781268726,  -436856.7440701572,  454362.0031506279,
      -698523.9507768439,  1402472.6432778114,  1560556.7423499615,
      -1148920.986408699,  -240442.43100003726, 323067.80967037816,
      90098.53423467485,   -299793.4522376957,  -789610.6783941154,
      1693958.7806414107,  -3814588.691058487,  -2253796.6142111667,
      2425186.3650362925,  -1597019.4159750415, -856748.974233011,
      734630.2631029023,   2054763.10660927,    2646171.142841373,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_9) {
  matrix_t A, B, RES;
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &RES);
  double arr1[] = {
      6.020646555025339,  5.057233771153894,  2.715863334987774,
      1.645091694744557,  3.981662774721511,  0.819033990789244,
      7.477223091804173,  5.08529006637556,   2.937318887989092,
      1.3589516604315466, 7.567308422077421,  0.8292774283451287,
      4.136122913138772,  9.553224377543517,  5.020454301746665,
      4.821481161076969,  9.205678078084997,  3.712784882371591,
      4.026376201083681,  2.642430938108573,  9.37543464745792,
      3.302014516492319,  2.6975137293482345, 4.999449146679065,
      0.9615964885943292,
  };
  double arr3[] = {
      -348.37459061925165, 271.48921247354394,  -694.8603979101453,
      1019.6038949540945,  -887.441336184955,   116.41716864948407,
      345.59605742864676,  -1760.1480624774981, 424.2125721357789,
      410.32765004534326,  205.1205505353614,   180.9753027444958,
      79.20589676179266,   -470.01961297820236, -399.8529930988269,
      284.55604254651274,  -987.964891104196,   1976.5869720846604,
      -919.9824390510561,  -143.53967015909828, -574.8910409210076,
      157.4713838036311,   -480.43877593549496, 160.66905027183338,
      930.6003824490201,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_10) {
  matrix_t A, B, RES;
  s21_create_matrix(7, 7, &A);
  s21_create_matrix(7, 7, &RES);
  double arr1[] = {
      7.240178468456502,  5.122453630277606,  7.9752255064107995,
      5.573540104151562,  3.646763621375583,  5.168445966387437,
      0.8285339053715198, 2.373021271355798,  3.0896194732261186,
      5.541110749233029,  9.907775699839263,  8.645464078127118,
      3.638212985151996,  6.381908453162493,  8.26465173534975,
      7.3788571259787785, 5.608487751047384,  3.110224210953794,
      1.927342810778788,  5.886040968305826,  8.469391100233375,
      2.904299774894781,  1.8835619468377056, 6.034037494466534,
      6.922916939154091,  3.2113388346556926, 7.730978105526387,
      6.369353728262069,  1.4741157038945205, 5.645451865546817,
      2.037832099617531,  9.767245260285772,  4.458580111090079,
      4.05702799487999,   7.60043311631605,   8.146026982050783,
      1.2992363128538609, 5.348551333998669,  3.388364362629188,
      1.324597516541652,  7.033725569016575,  5.705366305490827,
      9.925580129027779,  7.170809531060112,  9.089558659626707,
      2.183150559105982,  1.4109848206093436, 0.6191256352386065,
      5.766075569010034,
  };
  double arr3[] = {
      -10263.554902443537, -32233.816135432426, 4686.368548462041,
      -13493.952827379915, -6185.344138416863,  -26600.89173795835,
      59845.438713356845,  -5430.262260755968,  17607.45465625266,
      4312.492081033379,   35777.827603825084,  -88166.53463354925,
      9099.584453625783,   -12296.123707649978, 22474.407832451852,
      -58466.86290197784,  22326.08748648324,   89004.07871363482,
      -70865.3000679983,   -52051.827523524196, -11939.472487109677,
      80599.46133260785,   3008.332337978041,   -84444.51221838676,
      10344.67954667885,   45939.16096055788,   -25665.420953215493,
      -21768.458094568236, -23890.076438595013, -8699.746931872112,
      38370.858131342655,  -82474.70609790542,  66607.08152060611,
      24215.71557450201,   3783.0721435902037,  -83200.85880364799,
      63805.31473903923,   50315.40293923973,   -44486.73285669225,
      16326.799622982739,  12763.825088752914,  -3968.3518665333863,
      -743.2411854605924,  16032.463005547663,  -45323.56281583268,
      -27088.320700874516, 47863.69024372897,   54008.00375960624,
      -21708.088153692213,
  };
  from_array_to_matrix(&A, arr1);
  from_array_to_matrix(&RES, arr3);
  ck_assert_int_eq(s21_calc_complements(&A, &B), OK);
  ck_assert_int_eq(s21_eq_matrix(&B, &RES), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(test_calc_complements_uninitialized) {
  matrix_t A, C;
  s21_create_matrix(4, 4, &A);
  ck_assert_int_eq(s21_calc_complements(NULL, &C), ERROR_MATR);
  ck_assert_int_eq(s21_calc_complements(NULL, NULL), ERROR_MATR);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), ERROR_MATR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_invalid) {
  matrix_t A, C;
  s21_create_matrix(4, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, &C), ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *s =
      suite_create("\033[41m-=S21_CALC_COMPLEMENTS=-\033[0m" RAINBOW_COLORS);
  TCase *tc = tcase_create("s21_calc_complements_tc");

  srand(time(NULL));

  tcase_add_test(tc, test_calc_complements_0);
  tcase_add_test(tc, test_calc_complements_1);
  tcase_add_test(tc, test_calc_complements_2);
  tcase_add_test(tc, test_calc_complements_3);
  tcase_add_test(tc, test_calc_complements_4);
  tcase_add_test(tc, test_calc_complements_5);
  tcase_add_test(tc, test_calc_complements_6);
  tcase_add_test(tc, test_calc_complements_7);
  tcase_add_test(tc, test_calc_complements_8);
  tcase_add_test(tc, test_calc_complements_9);
  tcase_add_test(tc, test_calc_complements_10);
  tcase_add_test(tc, test_calc_complements_uninitialized);
  tcase_add_test(tc, test_calc_complements_invalid);

  suite_add_tcase(s, tc);
  return s;
}
