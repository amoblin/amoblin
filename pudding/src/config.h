/* 原始句子最大长度*/
#define SEN_LEN 50

/* 一个汉字占3个utf8字节 SEN_LEN*3 */
#define UTF8_LEN 150

/* 每个汉字的Unicode码占2字节 SEN_LEN*2 */
#define UNI_LEN 100

/* 每个汉字2字节,用16个char保存每一位。SEN_LEN*16 */
#define BIN_LEN 800

/* 子句长度，等于输出层节点数 */
#define OUT_NODES 5

/* 输入层节点数,一个汉字16位 OUT_NODES*16  */
#define IN_NODES 80

/* 隐含层节点数 */
#define HIDDEN_NODES 30

#define DEBUG 1

/* 最大循环次数 */
#define LOOP_MAX 2000

#define LOG_DEN 10
#define LEARN_RATE  1.9
#define PRECISION 0.1
#define PLOT_DEN 10

