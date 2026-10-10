class UF:
    parent: [int]
    size: [int]
    cnt: int
    def __init__(self, n : int):
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]
        self.cnt = n
    def unite(self, x: int, y: int):
        parent_x = self._find_parent(x)
        parent_y = self._find_parent(y)
        if parent_x == parent_y:
            return
        if self.size[parent_x] > self.size[parent_y]:
            self.parent[parent_y] = parent_x
            self.size[parent_x] += self.size[parent_y]
        else:
            self.parent[parent_x] = parent_y
            self.size[parent_y] += self.size[parent_x]
        self.cnt -= 1

    def _find_parent(self, x: int):
        if x == self.parent[x]:
            return x
        self.parent[x] = self._find_parent(self.parent[x])
        return self.parent[x]

    def is_connect(self, x: int, y: int):
        return self._find_parent(x) == self._find_parent(y)