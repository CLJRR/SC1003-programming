def sumOfNodes(t):
    if len(t) == 1:
        return 1
    else:
        left = sumOfNodes(t[0])
        right = sumOfNodes(t[2])

    return (left+right+1)


def main():
    tree = [[[7], 2, [9]], 3, [[8], 2, [4]]]
    # print(tree)
    count = sumOfNodes(tree)
    print(count)


main()
