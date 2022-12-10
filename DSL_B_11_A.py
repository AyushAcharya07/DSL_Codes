# DSL Assignment B11 A

'''
Write a Python program to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search.
'''

t=int(input("Enter the total no. of students attended the session:"))
student_list=[]
s=len(student_list)

for i in range(t):
    student_list.append(int(input("Enter the roll nos. of present students:")))

#student_list.sort()

check=int(input("Enter the roll no. you want to search:"))


def linear_search(student_list,check):
    for i in student_list:
        if i==check:
            return 1

    return -1


def sentinelSearch(arr, n, key):
    last=arr[n-1]
    arr[n-1]=key
    i=0
    while(arr[i]!=key):
        i+=1
    arr[n-1]=last

    if((i<n-1) or (arr[n-1]==key)):
        print("Student present for the session")
    else:
        print("Student absent for the session")


def main():
    while(True):
        print("--------------MENU-----------------")
        print("1.To check using linear search\n2.To search using binary search\n3.Exit")
        ch=int(input("Enter your choice :\n"))

        if ch==1:
            result=linear_search(student_list,check)
            if result==1:
                print("Student present for the session")
            else:
                print("Student absent for the session")

        if ch==2:
            o=sentinelSearch(student_list,s,check)

        if ch>=3:
            print("You have successfully exited")
            break


main()