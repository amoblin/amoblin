#!/usr/bin/octave -qf

%octave script file demo made by amoblin at 2010年12月09日 星期四 17时01分39秒

a=[0:0.1:10];
plot(sin(a))
pause

%matrix
A=[1 2 3; 4 5 6; 7 8 0]

%转置 乘法 求逆
B = A' + A*A

%向量或矩阵大小
size(B)

%转置
inv(A)

%vector
b=[1; 0; 2]

c=[2; 4; 6]

%点积
dot(b,c)

%叉积
cross(b,c)

%返回向量长度
length(b)

%左除 Ax=b时计算x
x=A\b


%图形输出
plot(A)
pause

% 3x2的随机矩阵[0-1]
B = rand(3,3)

%单位矩阵
C = eye(3)

%显示所有变量
who

%自由输入
disp("Hello, World!")

%清除A变量
clear A

%清除所有变量
clear all

input('Press any key...');
