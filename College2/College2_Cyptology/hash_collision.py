import math
import matplotlib.pyplot as plt
bits_number = 10
card = 1 << bits_number


def uncollision_core(n, bits=bits_number):
    return (1-n/bits)


pltX = []
pltY = []
print(card)
for i in range(card):
    pr_collision = 1
    for j in range(i):
        pr_collision*uncollision_core(j)
    pltX.append(i)
    pltY.append(pr_collision)

plt.plot(pltX, pltY)
plt.xlabel('攻击的次数')
plt.ylabel('碰撞概率')
plt.savefig("test2.png", dpi=220)
plt.show()
