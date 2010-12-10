#!/usr/bin/octave

function[x,k]=getd(A,b,x0,ep,Nmax)
%用共轭梯度法求解正定系数矩阵线性方程组Ax=b
%A为线性方程组的系数矩阵，正定对称，b为方程组的右端向量
%x为解向量，k为迭代次数，x0为迭代初值（默认值原点）
%ep为精度（默认值为1e-5），Nmax为迭代次数上限以防发散（默认值为500）
n=length(A);
k=0;
if nargin<5 Nmax=500;
end
if nargin<4 ep=1e-10;
end
if nargin<3 x0=zeros(n,1);
end
x=x0;x0=x+2*ep;
r=b-A*x;
d=r;
k=0;
while norm(x0-x,inf)>ep & k<Nmax k=k+1;x0=x;
	alpha=(r'*r)/(d'*A*d);
	r1=r;
	s=alpha*d;
	x=x+s;
	r=r-A*s;
	beta=(r'*r)/(r1'*r1);
	d=r+beta*d;
end
if k==Nmax warning('已迭代上限次数');
end
