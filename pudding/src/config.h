/* 分词语句最大长度*/
#define SEN_LEN 30

/* 一个汉字占3个utf8字节 SEN_LEN*3 */
#define UTF8_LEN 90

/* 每个汉字的Unicode码占2字节 SEN_LEN*2 */
#define UNI_LEN 60

/* 每个汉字2字节,用16个char保存每一位。SEN_LEN*16 */
#define BIN_LEN 480

/* 输出层节点数,汉字的个数 */
#define OUT_NODES 4

/* 输入层节点数,一个汉字16位 OUT_NODES*16 */
#define IN_NODES 64

/* 隐含层节点数 */
#define HIDDEN_NODES 32

#define DEBUG 1

#define LOOP_MAX 100000000   //最大循环次数
#define LOG_DEN 10000
#define LEARN_RATE  1.9 //学习率
#define PRECISION 0.05  //精度
#define PLOT_DEN 100

