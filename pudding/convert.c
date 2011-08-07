#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "utils.h"

int main()
{
    FILE *fp = NULL;
    char *fname = "exercise.txt";
    fp = fopen(fname,"r");
    if(fp == NULL) {
        printf("file: %s does not exist, please check again.\n", fname);
        return 0;
    }
    char sentence[SEN_LEN];  //语句长度最大值：18
    int data_size = get_data_size();
    unsigned char **in = (unsigned char **) malloc(sizeof(unsigned char*) * data_size);
    //unsigned char in[DATA_SIZE][IN_NODES];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    float **out = (float **) malloc(sizeof(float *) * data_size);//输出向量，0.9代表连续，0.1代表分词点
    int i;
    for(i=0;i<data_size;i++)
    {
        in[i] = (unsigned char *) malloc(sizeof(unsigned char) * IN_NODES);
        out[i] = (float *) malloc(sizeof(float) * OUT_NODES);
    }
    //char out[DATA_SIZE][OUT_NODES];       //输出向量，1代表连续，0代表分词点。
    int t = 0;  //向量数组游标
    while(fgets(sentence, SEN_LEN, fp) != NULL)
    {
        /* 初始化输入输出矩阵(貌似不要也可以) */
        /*
        int i;
        for(i = 0; i<OUT_NODES; i++) {
            in[t][i] = in[t][i*2] = out[t][i] = 0;
        }
        in[DATA_SIZE][IN_NODES - 1] = 0;
        */
        utf8_to_unicode(sentence, in[t],out[t]);
        t++;        //向量数组游标增1
    }
    fclose(fp);

    FILE *vector_p = NULL;
    vector_p = fopen("sample.dat","wb");
    fwrite(in, IN_NODES, t, vector_p);
    fwrite(out, OUT_NODES, t, vector_p);
    fclose(vector_p);

    return 0;
}
