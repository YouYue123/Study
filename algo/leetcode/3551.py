class UF:
    parent: list[int]
    size: list[int]
    def __init__(self, n: int):
        self.parent = [x for x in range(n)]
        self.size = [1 for _ in range(n)]

    def unite(self, x: int, y: int):
        parent_x = self.find_parent(x)
        parent_y = self.find_parent(y)
        if parent_x == parent_y:
            return False
        if self.size[parent_x] > self.size[parent_y]:
            self.size[parent_x] += self.size[parent_y]
            self.parent[parent_y] = parent_x
        else:
            self.size[parent_y] += self.size[parent_x]
            self.parent[parent_x] = parent_y
        return True
        
    def find_parent(self, x: int) -> int:
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find_parent(self.parent[x])
        return self.parent[x]

    def get_size(self, x: int):
        return self.size[x]

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def get_digit_sum (x: int):
            tmp = 0
            while x > 0:
                tmp += x % 10
                x //= 10
            return tmp
        sorted_nums = sorted(nums, key=lambda num : (get_digit_sum(num), num))
        # print(sorted_nums)
        ans = 0
        sorted_num_to_pos = defaultdict(int)
        for i in range(len(nums)):
            sorted_num_to_pos[sorted_nums[i]] = i
        uf = UF(len(nums))
        for i in range(len(nums)):
            num = nums[i]
            pos = sorted_num_to_pos[num]
            uf.unite(i, pos)
        
        visit = set()
        for num, idx in enumerate(nums):
            p = uf.find_parent(num)
            if p in visit:
                continue
            visit.add(p)
            ans += (uf.get_size(p) - 1)
        return ans