#!/usr/bin/octave -qf

R = 5;          # radius of the strip
W = 2;          # width of the strip
phiSteps = 20;  # resolution in phi
ySteps = 6;     # resolution in y

phi = -pi:2*pi/phiSteps:pi;
y = -W/2:W/ySteps:W/2;

X = Y = Z = zeros(max(size(y)), max(size(phi)));
for row = 1:max(size(y))
    for column = 1:max(size(phi))
        r = R - y(row) * cos(phi(column)/2);
        X(row, column) = r * cos(phi(column));
        Y(row, column) = -y(row) * sin(phi(column)/2);
        Z(row, column) = r * sin(phi(column));
    endfor
endfor

mesh(X, Y, Z);
axis([-R, R+W/2, -2*W, 2*W, -R-W/2, R+W/2]);
print -dpng moebius.png
input("Press any key...");
