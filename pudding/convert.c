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
    char sentence[UTF8_LEN];  //语句长度最大值：18
    int data_size = get_data_size();
    unsigned char **in = (unsigned char **) malloc(sizeof(unsigned char*) * data_size);
    //unsigned char in[DATA_SIZE][IN_NODES];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    float **out = (float **) malloc(sizeof(float *) * data_size);//输出向量，0.9代表连续，0.1代表分词点
    int i;
    for(i=0;i<data_size;i++)
    {
        in[i] = (unsigned char *) malloc(sizeof(unsigned char) * IN_NODES);
        memset(in[i],0,sizeof(unsigned char) * IN_NODES);
        out[i] = (float *) malloc(sizeof(float) * OUT_NODES);
        memset(out[i],0,sizeof(float) * OUT_NODES);
    }
    //char out[DATA_SIZE][OUT_NODES];       //输出向量，1代表连续，0代表分词点。
    //unsigned char **in = (unsigned char **) malloc(sizeof(unsigned char) * data_size * IN_NODES);
    //float **out = (float **)malloc(sizeof(float) * data_size * OUT_NODES);
    int t = 0;  //向量数组游标
    while(fgets(sentence, UTF8_LEN, fp) != NULL)
    {
        /* 初始化输入输出矩阵(貌似不要也可以,静态数组可以不要，但malloc分配的必须清零先) */
        /*

        int i;
        for(i = 0; i<OUT_NODES; i++) {
            in[t][i] = in[t][i*2] = out[t][i] = 0;
        }
        in[DATA_SIZE][IN_NODES - 1] = 0;
        */

        unsigned char tmp_in[UNI_LEN]={0};//输入最大长度18汉字，每个汉字2字节。要先清空
        float tmp_out[18];//默认为0，不需清零先。
        utf8_to_unicode(sentence, tmp_in,tmp_out);
        /*
        int i;
        for(i=0;i<36;i++) {
            printf("%d\n",tmp_in[i]);
        }
        */
        return 0;

        t++;        //向量数组游标增1
    }
    fclose(fp);

    FILE *vector_p = NULL;
    vector_p = fopen("sample.dat","wb");
    fwrite(in, IN_NODES, t, vector_p);
    fwrite(out, OUT_NODES, t, vector_p);
    fclose(vector_p);
    for(i=0;i<data_size;i++)
    {
        free(in[i]);
        free(out[i]);
    }
    free(in);
    free(out);

    return 0;
}
