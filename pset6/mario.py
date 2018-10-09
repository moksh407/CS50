import sys

if len(sys.argv)!=1:
    print("Usage: python mario.py")
    exit(1)

print("Height:",end="")
x=input()

while (int(x)>23 or int(x)<=0):
    print("Height:",end="")
    x=input()

for i in range(1,int(x)+1):
    for j in range(i,int(x)):
        print(" ",end="")
    for k in range(i+1):
        print("#",end="")
    print()