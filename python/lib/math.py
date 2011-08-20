from matplotlib import *
def  f(x, c):
    m1 = sin(2*pi*x)
    m2 = exp(-c*x)
    return multiply(m1, m2)

x = linspace(0, 4, 100)
sigma = 0.5
plot(x, f(x, sigma), 'r', linewidth=2)
xlabel(r'$\rm{time}  \  t$', fontsize=16)
ylabel(r'$\rm{Amplitude} \ f(x)$', fontsize=16)
title(r'$f(x) \ \rm{is \ damping  \ with} \ x$', fontsize=16)
text(2.0, 0.5, r'$f(x) = \rm{sin}(2 \pi  x^2) e^{\sigma x}$', fontsize=20)
savefig('latex.png', dpi=75)
show()
