'''
DSL A1
'''

Group_A=[]
Group_B=[]
Group_C=[]
t=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
l=len(t)
print("Total no. of students:",t)


def play_cricket():

    n=int(input('Enter no. of students playing cricket:'))
    for i in range(n):

        c=int(input('Enter roll no. of students playing cricket:'))
        Group_A.append(c)

play_cricket()
print('Students playing only cricket:',Group_A)

def play_badmint():

    m=int(input('Enter no. of students playing badminton:'))
    for j in range(m):
        b=int(input('Enter roll no. of students playing badminton:'))
        Group_B.append(b)

play_badmint()
print('Students playing only basketball:',Group_B)

def play_football():

    o=int(input('Enter no. of studens playing football:'))
    for k in range(o):
        f=int(input('Enter roll no. of students playing football:'))
        Group_C.append(f)

play_football()
print('Students playing only football:',Group_C)

# Case 1 : Students who play both cricket and badminton
while(True):
    ch=int(input('Enter your choice:'))
    print(
        '1.Students who play both cricket and badminton\n2.Students who play either cricket or badminton but not both\n3.No. of students who play neither cricket nor badminton\n4.No. of students who play cricket and football but not badminton')

    if ch==1:
        def union_A_B(a,b):
            cricbad=a+b
            cricbad.sort()
            for i in a:
                if i in b:
                    cricbad.remove(i)
            print('Students who play both cricket and badminton:',cricbad)

        union_A_B(Group_A,Group_B)

# Case 2 : Students playing either cricket or badminton but not both

    if ch==2:
        def intersec(a,b):
            either_not=[]
            for i in a:
                if i in b:
                   either_not.append(i)
            print('Students playing either cricket or badminton but not both:',either_not)

        intersec(Group_A,Group_B)

# Case 3 : No. of students who play neither cricket nor badminton

    if ch==3:
        def comp(a,b):
            cricbad = a + b
            cricbad.sort()
            neither_not=[]
            for i in a:
                if i in b:
                    cricbad.remove(i)
                    s=len(cricbad)

                    neither_not=l-s
            print('Students who play neither cricket nor badminton:',neither_not)

        comp(Group_A,Group_B)

# Case 4 : No. of students who play cricket and football but not badminton

    if ch==4:
        def union_A_C(a,b,c,t):
            cricfoot= a+c
            cricfoot.sort()
            y=0
            z=0
            for i in a:
                if i in c:
                    cricfoot.remove(i)
                    y=len(cricfoot)
            interb=[]
            for j in t:
                if j in b:
                    interb.append(j)
                    z=len(interb)
            list= y-z
            print("Students who play cricket and football but not badminton:",list)


        union_A_C(Group_A,Group_B,Group_C,t)

    if ch>=5:
        print("Sorry! Wrong choice entered")
        break


