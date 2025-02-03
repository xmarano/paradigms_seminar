import os
color1 = "\033[1m\033[32m"
color2 = "\033[1m\033[31m"
reset = "\033[0m"

# Exercice 1:
os.system("mv ex/ex01.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex01.c ex/ex01.c")
    exit(1)
else:
    os.system("./a.out > results/got1.txt")
    os.system("rm a.out")
    if (os.system("diff results/got1.txt results/expected1.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got1.txt])")
    else:
        print(f"{color1}Test ex01 success{reset}")
        os.system("mv ex01.c ex/ex01.c")

# Exercice 2:
os.system("mv ex/ex02.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex02.c ex/ex02.c")
    exit(1)
else:
    os.system("./a.out > results/got2.txt")
    os.system("rm a.out")
    if (os.system("diff results/got2.txt results/expected2.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got2.txt])")
    else:
        print(f"{color1}Test ex02 success{reset}")
        os.system("mv ex02.c ex/ex02.c")

# Exercice 3:
os.system("mv ex/ex03.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex03.c ex/ex03.c")
    exit(1)
else:
    os.system("./a.out > results/got3.txt")
    os.system("rm a.out")
    if (os.system("diff results/got3.txt results/expected3.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got3.txt])")
    else:
        print(f"{color1}Test ex03 success{reset}")
        os.system("mv ex03.c ex/ex03.c")

# Exercice 4:
os.system("mv ex/ex04.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex04.c ex/ex04.c")
    exit(1)
else:
    os.system("./a.out > results/got4.txt")
    os.system("rm a.out")
    if (os.system("diff results/got4.txt results/expected4.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got4.txt])")
        os.system("mv ex04.c ex/ex04.c")
    else:
        print(f"{color1}Test ex04 success{reset}")
        os.system("mv ex04.c ex/ex04.c")

# Exercice 5:
os.system("mv ex/ex05.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex05.c ex/ex05.c")
    exit(1)
else:
    os.system("./a.out > results/got5.txt")
    os.system("rm a.out")
    if (os.system("diff results/got5.txt results/expected5.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got5.txt])")
    else:
        print(f"{color1}Test ex05 success{reset}")
        os.system("mv ex05.c ex/ex05.c")

# Exercice 6:
os.system("mv ex/ex06.c .")
if os.system("gcc *.c -std=gnu17 -Wall -Wextra"):
    print(f"{color2}Compilation failed{reset}")
    os.system("mv ex06.c ex/ex06.c")
    exit(1)
else:
    os.system("./a.out > results/got6.txt")
    os.system("rm a.out")
    if (os.system("diff results/got6.txt results/expected6.txt")):
        print(f"{color2}Test failed{reset} (difference in [results/got6.txt])")
    else:
        print(f"{color1}Test ex06 success{reset}")
        os.system("mv ex06.c ex/ex06.c")

os.system("rm results/got*")
