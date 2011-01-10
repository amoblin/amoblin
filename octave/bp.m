#!/usr/bin/octave -qf

%BP neural network
clear all
clc

inputNums=3; %输入层节点
outputNums=3; %输出层节点
hideNums=10; %隐含层节点
maxcount=2000; %最大迭代次数
samplenum=3; %一个计数器，无意义
precision=0.001; %预设精度
yyy=1.3;    %yyy是帮助网络加速走出平坦区

alpha=0.5;%学习率设定值
a=0.5;%设定值
error=zeros(1,maxcount+1); %
errorp=zeros(1,samplenum);

v=rand(inputNums,hideNums); %输入层到隐含层的权值
deltv=zeros(inputNums,hideNums);
dv=zeros(inputNums,hideNums);
st1=zeros(1,hideNums);

w=rand(hideNums,outputNums);    %隐含层到输出层权值
deltw=zeros(hideNums,outputNums);
dw=zeros(hideNums,outputNums);
st2=zeros(1,outputNums);

samplelist=[1,0,0;0,1,0;0,0,1];
expectlist=[1,0,0;0,1,0;0,0,1];

%samplelist=[0.1323,0.323,-0.132;0.321,0.2434,0.456;-0.6546,-0.3242,0.3255]; %3*3;指定输入值3*3(实为3个向量)
%expectlist=[0.5435,0.422,-0.642;0.1,0.562,0.5675;-0.6464,-0.756,0.11]; %3*3;期望输出值3*3(实为3个向量)，有导师的监督学

count=1;
while(count<=maxcount) %迭代结束条件
    c=1;
    while (c<=samplenum)
        for k=1:outputNums
            d(k)=expectlist(c,k);%获得期望输出的向量
        end

        for i=1:inputNums
            x(i)=samplelist(c,i);%获得输入的向量（数据）
        end

        %Forward();
        for j=1:hideNums
            net=0.0;
            for i=1:inputNums
                net=net+x(i)*v(i,j); %输入层到隐含层的加权和
            end
            net=net-st1(j);
            y(j)=1/(1+exp(-net)); %输出层处理单极性sigmoid函数
        end
        for k=1:outputNums
            net=0.0;
            for j=1:hideNums
                net=net+y(j)*w(j,k);
            end
            net=net-st2(k);

            if count>=2 && error(count)-error(count+1)<=0.0001
                o(k)=1/(1+exp(-net)/yyy);   %平坦区加大学习率
            else
                o(k)=1/(1+exp(-net));
            end
        end
                
        %BpError(c); 反馈，修改
        errortmp=0.0;
        for k=1:outputNums
            errortmp=errortmp+(d(k)-o(k))^2;    %第一组训练后的误差计算
        end
        errorp(c)=0.5*errortmp;       
        %end

        %Backward();
        for k=1:outputNums
            yitao(k)=(d(k)-o(k))*o(k)*(1-o(k));%输入层误差偏导
        end
        for j=1:hideNums
            tem=0.0;
            for k=1:outputNums
                tem=tem+yitao(k)*w(j,k);
            end
            yitay(j)=tem*y(j)*(1-y(j));
        end

        %调整各层权值
        for j=1:hideNums
            for k=1:outputNums
                deltw(j,k)=alpha*yitao(k)*y(j); %权值w的调整量
                w(j,k)=w(j,k)+deltw(j,k)+a*dw(j,k);%权值调整
                dw(j,k)=deltw(j,k);
            end
        end
        for k=1:outputNums
            st2(k)=st2(k)+alpha*yitao(k);
        end
        for i=1:inputNums
            for j=1:hideNums
                deltv(i,j)=alpha*yitay(j)*x(i);
                v(i,j)=v(i,j)+deltv(i,j)+a*dv(i,j);
                dv(i,j)=deltv(i,j);
            end
        end
        for j=1:hideNums
            st1(j)=st1(j)+alpha*yitay(j);
        end
        %end
            
        c=c+1;
    end %一次BP训练结束

    double tmp;
    tmp=0.0;
    for i=1:samplenum
        tmp=tmp+errorp(i)*errorp(i);    %误差求和
    end
    tmp=tmp/c;
    error(count)=sqrt(tmp); %误差求均方根，即精度。

    if (error(count)<precision)
        break;
    end
    count=count+1;    %训练次数加1
end

p=1:count;
pp=p/50;
plot(pp,error(p),'-');
pause
