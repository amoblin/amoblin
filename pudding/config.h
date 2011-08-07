#define SEN_LEN 54  //分词语句最大长度,一个汉字占3个utf8字节
#define DATA_SIZE 1000  //学习数据的上限

#define IN_NODES 36     //输入层节点数,一个汉字占2个unicode字节
#define OUT_NODES 18     //输出层节点数,汉字的个数
#define HIDDEN_NODES 28   //隐含层节点数

#define REAL_DATA_SIZE 6 //实际学习数据量.    TODO: 动态分配


#define LOOP_MAX 100000   //最大循环次数
#define LEARN_RATE  0.09 //学习率
#define PRECISION 0.05  //精度

#define DEBUG 1

