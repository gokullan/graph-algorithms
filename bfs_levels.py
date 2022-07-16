from collections import deque

def bfs(adj_list, n, start=0):
	print(adj_list)
	print()
	visited = [0 for i in range(n)]

	level = 0  # vertices of this level will be appended to the queue
	n_children = 1 
	bfs_queue = deque([start])
	visited[start]=1

	# print("Level: {}".format(level))
	while bfs_queue!=deque([]):
		u = bfs_queue[0]
		if len(bfs_queue)==n_children:
			print("Level: {}".format(level))  # vertices of this level will be explored
			level += 1  # vertices of this level will be appended to the queue
			n_children = 0
		bfs_queue.popleft()
		print(u)
		for v in adj_list[u]:
			if visited[v]==0:
				visited[v] = 1
				bfs_queue.append(v)
				n_children += 1

def main():
	n = int(input())
	e = int(input())
	adj_list = [[] for i in range(n)]
	for i in range(e):
		u,v = map(int, input().split())
		adj_list[u-1].append(v-1)
	bfs(adj_list, n)

if __name__ == "__main__":
	main()
