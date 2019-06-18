import bisect

# 以空格作为分隔打印S中所有元素再换行.
def print_all(S):
    for x in S:
        print(x, end = " ")
    print("")

# 有序向量SV.
SV = [1, 3, 6, 6, 8, 9]

#查找元素.
key = int(input())
print(bisect.bisect_left(SV, key))
print(bisect.bisect_right(SV, key))

# 插入新元素.
key = 0
bisect.insort_right(SV, key)

# 删除重复元素的最后一个. 思考: 如何删除第一个?
key = 6
i = bisect.bisect_right(SV, key)
i -= 1
# 注意此时i < len(SV)必然成立. 如果确实有key这个元素则删除.
if (i > 0 and SV[i] == key): del(SV[i])
print_all(SV)

# 删除重复key所在区间: [bisect.bisect_left(SV, key):bisect.bisect_right(SV, key)).
del SV[bisect.bisect_left(SV, key):bisect.bisect_right(SV, key)]
print_all(SV)

# 无序向量USV.
USV = [9, 6, 1, 3, 8, 6]

# 插入新元素
key = 0
USV.append(key)

# 删除重复元素的最后一个. 思考: 如何删除第一个?
key = 6
# 逆向遍历, 如果存在则删除.
i = len(USV) - 1
while i > 0:
    if USV[i] == key:
        USV[i] = USV[-1]
        USV.pop()
        break
    i -= 1
print_all(USV)
