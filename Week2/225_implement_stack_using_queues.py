class MyStack:

	def __init__(self):
		self.q1 = deque()
		self.q2 = deque()

	def push(self, x: int) -> None:
		self.q1.append(x)

	def pop(self) -> int:
		while len(self.q1) != 1:
			self.q2.append(self.q1.popleft())

		val = self.q1.popleft()
		self.q1, self.q2 = self.q2, self.q1
		return val

	def top(self) -> int:
		while len(self.q1) != 1:
			self.q2.append(self.q1.pople-ft())

        # tried to re-use while part, but seems not achievable, since val is retrieved in-between 
		val = self.q1[0]
		self.q2.append(self.q1.popleft())  # note: add back to q2, so q1 will always be empty

		self.q1, self.q2 = self.q2, self.q1
		return val


	def empty(self) -> bool:
		return not self.q1

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()