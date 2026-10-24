"""
    暴力对拍模板
    用法：把 sol.py、brute.py和本文件放在同一目录，运行 python stress.py
    两个解法都按正常提交的方式从 stdin 读入、向 stdout 输出，不需要改动。
"""
import random
import subprocess
import sys
 
FAST = "sol.py"
BRUTE = "brute.py"
TESTS = 1000
 
 
def gen():
    """生成一组随机输入，按题目格式返回字符串。每道题只需改这里。
    建议 t=1、n 很小，这样出错时反例最短，最好手算。"""
    t = 1
    lines = [str(t)]
    for _ in range(t):
        n = random.randint(3, 8)
        lines.append("".join(random.choice("01") for _ in range(n)))
    return "\n".join(lines) + "\n"
 
 
def run(file, inp):
    r = subprocess.run(
        [sys.executable, file],
        input=inp,
        capture_output=True,
        text=True,
        timeout=10,
    )
    if r.returncode != 0:
        print(f"{file} 运行出错，输入：\n{inp}")
        print(r.stderr)
        sys.exit(1)
    return r.stdout.split()  # 按空白切分比较，忽略换行和多余空格的差异
 
 
def main():
    for i in range(1, TESTS + 1):
        random.seed(i)  # 固定种子，出错时能复现
        inp = gen()
        out_fast = run(FAST, inp)
        out_brute = run(BRUTE, inp)
        if out_fast != out_brute:
            print(f"第 {i} 组不一致（seed={i}）")
            print("输入：")
            print(inp)
            print("你的输出：", " ".join(out_fast))
            print("暴力输出：", " ".join(out_brute))
            return
    print(f"全部 {TESTS} 组通过")
 
 
if __name__ == "__main__":
    main()