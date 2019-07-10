import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("cuerda.txt")

t=datos[:,0]
x=datos[:,2]

plt.figure()
plt.plot(t,x)
plt.grid()
#plt.ylim(-0.010,0.010)
plt.savefig("cuerda.png")