# def sumOfNodes(t):
#     if len(t) == 1:
#         return t[0]
#     else:
#         left = sumOfNodes(t[0])
#         right = sumOfNodes(t[2])
#         max = t[1]
#         if (right < max):
#             max = right
#         if (left < max):
#             max = left

#     return (max)
def sumOfNodes(t):
    if len(t) == 1:
        return [t[0]]
    else:
        left = sumOfNodes(t[0])
        right = sumOfNodes(t[2])

    return [right, t[1], left]


def main():
    tree = [[[7], 1, [9]], 3, [[8], 2, [4]]]
    # print(tree)
    count = sumOfNodes(tree)
    print(count)


main()
