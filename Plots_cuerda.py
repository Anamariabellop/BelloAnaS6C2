import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("cuerda.txt")

t=datos[:,0]
x=datos[:,2]
xp=datos[:,3]

plt.figure()
plt.subplot(2,1,1)
plt.plot(t,x)
plt.xlabel("Amplitud")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones iniciales")

plt.subplot(2,1,2)
plt.plot(t,xp)
plt.xlabel("Amplitud")
plt.ylabel(" ")
plt.grid()
plt.ylim(-0.001,0.011)
plt.title("Condiciones presente")
plt.subplots_adjust(hspace=.5)
plt.savefig("cuerda.png")