for _ in range(int(input())):
    n = int(input())
    s = input()
    c = s.count('0')
    if c%2==1:
        if c>4:
            print('ALICE')
            continue
        c-=1
        if (c//2)%2==1:
            print('ALICE')
        else:
            print('BOB')
    else:
        if c>=4:
            print('BOB')
            continue
        if (c//2)%2==1:
            print('BOB')
        else:
            print('DRAW')
