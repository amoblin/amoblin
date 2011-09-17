/* 分词语句最大长度*/
#define SEN_LEN 50

/* 一个汉字占3个utf8字节 SEN_LEN*3 */
#define UTF8_LEN 150

/* 每个汉字的Unicode码占2字节 SEN_LEN*2 */
#define UNI_LEN 100

/* 每个汉字2字节,用16个char保存每一位。SEN_LEN*16 */
#define BIN_LEN 800

/* 输出层节点数,汉字的个数 */
#define OUT_NODES 4

/* 输入层节点数,一个汉字16位 OUT_NODES*16 */
#define IN_NODES 64

/* 隐含层节点数 */
#define HIDDEN_NODES 32

#define DEBUG 1

/* 最大循环次数 */
#define LOOP_MAX 5

#define LOG_DEN 1
#define LEARN_RATE  1.9
#define PRECISION 0.05
#define PLOT_DEN 100

