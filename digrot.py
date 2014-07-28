test_cases=int(input())
for k in range(0,test_cases):
    a=[]
    num=int(input())
    x=str(num)
    org=x
    l=len(x)
    print(l)
    
    else:
            while(True):
                #left rotation
                    first_digit=x[0]
                    second_digit=x[1]
                    if(second_digit=='0' and l>2):
                        new_num=x[2:]+x[0]
                        org=new_num
                    else if(second_digit=='0' and l==2):
                        new_num=x[1]
                        org=new_num
                    else:
                            new_num=x[1:]+x[0]
                            #if(new_num[0]=='0'):
                            #break                
                            if(new_num==org):
                                print(new_num)
                                a.append(new_num)
                                break
                    x=new_num
                    print(new_num)
                    a.append(new_num)

            x=str(num)
            org=x
            l=len(x)
            print("2nd caess")
            while(True):
                last_digit=x[l-1]
                if(last_digit=='0'):
                    new_num=x[:l-1]
                    org=new_num
                    l=len(org)
                else:    
                    new_num=x[l-1]+x[:l-1]
                    if(new_num==org):
                        print(new_num)
                        a.append(new_num)
                        break    
                x=new_num
                print(new_num)
                a.append(new_num)
            len_of_a=len(a)
            for i in range(0,len_of_a):
                a[i]= int(a[i])
            ans=max(a)
            print(a)
            print("ans= ",ans)
                
                
                
