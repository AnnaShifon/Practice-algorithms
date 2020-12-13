import subprocess
from subprocess import PIPE
import random
file = input()
subprocess.run('gcc -o ../'+file+'/main.exe ../'+file+'/main.c')
s = ""
for i in range(10):
 if i < 10:
  filename = "../input00" + str(i) + ".txt"
  out_file = "../output00"+str(i)+".txt"
 elif i < 100:
  filename = "../input0" + str(i) + ".txt"
  out_file = "../output0"+str(i)+".txt"
 else:
  filename = "../input" + str(i) + ".txt"
  out_file = "../output"+str(i)+".txt"
 f = open(filename, "w")
 out = open(out_file, "w")
 k = random.randint(1, 10)
 f.write(str(k) + "\n")
 for i in range(k):
  k = random.randint(1, 100)
  s += str(k) + " "
  f.write(s)
 s = ""
 cmd = subprocess.Popen('../'+file+'/main.exe '+filename, stdout=PIPE)
 print(i)
 cmd_out, cmd_err = cmd.communicate()
 to_file = cmd_out.decode("utf-8")
 out.write(str(i) + '\n' + to_file + '\n')
 out.close()
