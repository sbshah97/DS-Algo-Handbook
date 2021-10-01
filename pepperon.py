test = int(input())

while test:
    n = int(input())

    track = []

    tot_left = 0
    tot_right = 0
    for i in range(n):
        t = list(map(int, list(input())))
        cur_l = len(list(filter(lambda x: (x==1) ,t[:n//2])))
        cur_r = len(list(filter(lambda x: (x==1) ,t[n//2:])))
        track.append((cur_l, cur_r))
        tot_left += cur_l
        tot_right += cur_r


    without_exc = abs(tot_left - tot_right)
    # print(without_exc)
    if without_exc == 0:
        print(0)
    else:

        for i in range(n):
            lft, rgt = track[i]
            temp_left = tot_left - lft + rgt
            temp_right = tot_right - rgt + lft
            if abs(temp_left - temp_right) < without_exc:
                without_exc = abs(temp_left - temp_right)
                
        
        print(without_exc)
    
    test -= 1